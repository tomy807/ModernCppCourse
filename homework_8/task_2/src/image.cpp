#include "../include/image.hpp"
#include <iostream>
#include <vector>

void igg::Image::SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr) {
  this->io_strategy = strategy_ptr;
}
bool igg::Image::ReadFromDisk(const std::string &file_name) {
  auto tmpImage = this->io_strategy->ReadFromDisk(file_name);
  rows_ = tmpImage.rows_;
  cols_ = tmpImage.cols_;
  data_.resize(rows_*cols_);
  for (int r = 0; r < rows_; r++) {
    for (int c = 0; c < cols_; c++) {
      this->data_[r * cols_ + c].blue = tmpImage.data_[r * cols_ + c].blue_;
      this->data_[r * cols_ + c].red = tmpImage.data_[r * cols_ + c].red_;
      this->data_[r * cols_ + c].green = tmpImage.data_[r * cols_ + c].green_;
    }
  }
  return true;
}
bool igg::Image::WriteToDisk(const std::string &file_name) {
  std::vector<tmpPixel> data;
  data.resize(rows_ * cols_);
  for (int r = 0; r < rows_; r++) {
    for (int c = 0; c < cols_; c++) {
      data[r * cols_ + c].blue_ = data_[r * cols_ + c].blue;
      data[r * cols_ + c].red_ = data_[r * cols_ + c].red;
      data[r * cols_ + c].green_ = data_[r * cols_ + c].green;
    }
  }
  tmpImage image(rows_,cols_,data);
  return this->io_strategy->WriteToDisk(file_name, image);
}