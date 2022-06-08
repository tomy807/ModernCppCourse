#include "../include/image.hpp"

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
void igg::Image::DownScale(int scale) {
  int down_rows = rows_ / scale;
  int down_cols = cols_ / scale;
  Image down_image = Image(down_rows, down_cols);
  for (int i = 0; i < down_rows; i++) {
    for (int j = 0; j < down_cols; j++) {
      down_image.at(i, j) = at(i * scale, j * scale);
    }
  }
  rows_ = down_rows;
  cols_ = down_cols;
  data_ = down_image.data_;
}
void igg::Image::UpScale(int scale) {
  int up_rows = rows_ * scale;
  int up_cols = cols_ * scale;
  Image up_image = Image(up_rows, up_cols);
  for (int i = 0; i < up_rows; i++) {
    for (int j = 0; j < up_cols; j++) {
      up_image.at(i, j) = at(i / scale, j / scale);
    }
  }
  rows_ = up_rows;
  cols_ = up_cols;
  data_ = up_image.data_;
}