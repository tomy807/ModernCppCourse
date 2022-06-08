#include "../include/io_strategies/png_strategy.hpp"
#include <png++/png.hpp>
igg::tmpImage igg::PngIoStrategy::ReadFromDisk(const std::string& file_name) {
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
      tmpPixel tmp_pixel = tmpPixel(red, green, blue);
      data.emplace_back(tmp_pixel);
    }
  }
  tmpImage image(rows, cols, data);
  return image;
}
bool igg::PngIoStrategy::WriteToDisk(const std::string& file_name,
                                     tmpImage& image) {
  png::image<png::rgb_pixel> png_image(image.cols_, image.rows_);
  int red = 0;
  int green = 0;
  int blue = 0;
  int cols_ = image.cols_;
  for (size_t r = 0; r < png_image.get_height(); r++) {
    for (size_t c = 0; c < png_image.get_width(); c++) {
      red = image.data_[r * cols_ + c].red_;
      green = image.data_[r * cols_ + c].green_;
      blue = image.data_[r * cols_ + c].blue_;
      png_image[r][c] = png::rgb_pixel(red,green,blue);
    }
  }
  png_image.write(file_name);
  return true;
}