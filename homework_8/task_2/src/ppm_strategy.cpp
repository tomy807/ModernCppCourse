#include "../include/io_strategies/ppm_strategy.hpp"
#include <bits/stdint-uintn.h>
#include <iostream>
igg::tmpImage igg::PpmIoStrategy::ReadFromDisk(const std::string &file_name) {
  std::ifstream infile(file_name, std::ios_base::in);
  if (!infile) {
    std::cout << "fail" << std::endl;
  }
  std::string type;
  int rows = 0;
  int cols = 0;
  int max_val = 0;
  std::vector<tmpPixel> data;
  infile >> type >> rows >> cols >> max_val;
  int red = 0;
  int green = 0;
  int blue = 0;
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      for (int i = 0; i < 3; i++) {
        infile >> red >> green >> blue;
        tmpPixel h = tmpPixel(red, green, blue);
        data.emplace_back(h);
      }
    }
  }
  tmpImage image(rows,cols,data);
  return image;
}
bool igg::PpmIoStrategy::WriteToDisk(const std::string &file_name,
                                     tmpImage &image) {
  std::ofstream out(file_name);
  if (!out) {
    return false;
  }
  out << "P3" << std::endl
      << image.rows_ << " " << image.cols_ << std::endl
      << "255" << std::endl;
  for (int r = 0; r < image.rows_; ++r) {
    for (int c = 0; c < image.cols_; ++c) {
      out << image.data_[r * image.cols_ + c].red_ << " ";
      out << image.data_[r * image.cols_ + c].green_ << " ";
      out << image.data_[r * image.cols_ + c].blue_ << " ";
    }
    out << std::endl;
  }
  return true;
}