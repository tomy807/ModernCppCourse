#include "../include/io_strategies/png_strategy.hpp"
#include <png++/png.hpp>
igg::tmpImage igg::PngIoStrategy::ReadFromDisk(const std::string &file_name) {
  png::image<png::rgb_pixel> img(file_name);
  int cols = img.get_height();
  int rows = img.get_width();
  std::vector<tmpPixel> data;
  int red = 0;
  int green = 0;
  int blue = 0;
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      red = img[r][c].red;
      green = img[r][c].green;
      blue = img[r][c].blue;
      tmpPixel h = tmpPixel(red, green, blue);
    data.emplace_back(h);
    }
  }
  tmpImage image(rows, cols, data);
  return image;
}