#include "../include/io_strategies/ppm_strategy.hpp"
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