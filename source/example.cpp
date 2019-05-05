#include "window.hpp"
#include <GLFW/glfw3.h>
#include "circle.hpp"
#include "rectangle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include <utility>
#include <cmath>
#include "color.hpp"
#include <vector>

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  Color col_circ        {0.3f, 0.4f, 2.0f};
  float thickness_circ  {3.0f};
  Circle circ_1         {35.0f, {100.0f,150.0f}, col_circ};
  Circle circ_2         {50.0f, {500.0f,550.0f}, col_circ};

  Color col_rect        {0.3f, 0.4f, 2.0f};
  float thickness_rect  {3.5f};
  Rectangle rec_1       {{100.f,100.0f},{700.0f,700.0f},col_rect};
  Rectangle rec_2       {{210.0f,300.0f},{400.0f,430.0f},col_rect};

  Vec2 uhr_center         {400.0f, 400.0f};
  float uhr_radius        {300.0f};
  Color uhr_col_sec       {1.0f, 0.1f, 0.1f};
  Color uhr_col_min       {0.1f, 1.0f, 0.1f};
  Color uhr_col_std       {0.1f, 0.1f, 1.0f};
  float uhr_thickness_sec {3.0f};
  float uhr_thickness_min {5.0f};
  float uhr_thickness_std {7.0f};
  Circle uhr              {uhr_radius, uhr_center, col_circ};

  std::vector<Rectangle> rectangles;
  rectangles.push_back(rec_1);
  rectangles.push_back(rec_2);
  
  std::vector<Circle> circles;
  circles.push_back(circ_1);
  circles.push_back(circ_2);
  circles.push_back(uhr);



  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    Vec2 mouse_position_vec{std::get<0>(mouse_position), std::get<1>(mouse_position)};

    int vector_size_circ = circles.size();
    for (int i =0;i <= vector_size_circ ;++i){
      Circle circ = circles[i];
      if (circ.is_inside(mouse_position_vec) == true){
        bool highlight_color = true;
        circ.draw(win, col_circ, thickness_circ + 3.0f, highlight_color);
      }
      else {
        circ.draw(win);
      }
    }
    
    int vector_size_rect = rectangles.size();
    for (int i =0;i <= vector_size_rect ;++i){
      Rectangle rect = rectangles[i];
      if (rect.is_inside(mouse_position_vec) == true){
        bool highlight_color = true;
        rect.draw(win, col_rect, thickness_rect + 3.0f, highlight_color);
      }
      else {
        rect.draw(win);
      }
    }

    Vec2 uhr_point_start {uhr_center.x , (uhr_center.y - uhr_radius)};
    Vec2 uhr_vec {0.0f, -uhr_radius};
    Vec2 uhr_sec {uhr_point_start};
    Vec2 uhr_min {uhr_point_start};
    Vec2 uhr_std {uhr_point_start};

    uhr_sec = make_rotation_mat2((2*M_PI)/60*(int)(win.get_time())) * uhr_vec + uhr_center;
    uhr_min = make_rotation_mat2((2*M_PI)/60*(int)(win.get_time()/60.0f)) * uhr_vec + uhr_center;
    uhr_std = make_rotation_mat2((2*M_PI)/60*(int)(win.get_time()/3600.0f)) * uhr_vec + uhr_center;

    win.draw_line(uhr_center.x, uhr_center.y, uhr_sec.x, uhr_sec.y, uhr_col_sec.r_, uhr_col_sec.g_, uhr_col_sec.b_, uhr_thickness_sec);
    win.draw_line(uhr_center.x, uhr_center.y, uhr_min.x, uhr_min.y, uhr_col_min.r_, uhr_col_min.g_, uhr_col_min.b_, uhr_thickness_min);
    win.draw_line(uhr_center.x, uhr_center.y, uhr_std.x, uhr_std.y, uhr_col_std.r_, uhr_col_std.g_, uhr_col_std.b_, uhr_thickness_std);

    win.update();
  }

  return 0;
}
