#include "../include/image.hpp"
#include <fstream>
#include <cmath>
bool igg::Image::FillFromPgm(const std::string &file_name) {
  std::ifstream in(file_name, std::ios_base::in);
  if (!in) {
    return false;
  }

  // Read integers, if we read chars, we get 1 digit instead of the whole number
  std::string type;
  int rows = 0;
  int cols = 0;
  int max_val = 0;
  std::vector<uint8_t> data;
  in >> type >> rows >> cols >> max_val;

  data.resize(rows * cols);
  int byte = 0;
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      in >> byte;
      data[r * cols + c] = byte;
    }
  }
  rows_ = rows;
  cols_ = cols;
  data_ = data;
  return true;
}

bool igg::Image::WriteToPgm(const std::string &file_name) {
  int max_val=0;
  std::ofstream out(file_name);
  if (!out) {
    return false;
  }
  out << "P2" << std::endl
      << rows_ << " " << cols_ << std::endl
      << max_val << std::endl;
  for (int r = 0; r < rows_; ++r) {
    for (int c = 0; c < cols_; ++c) {
      out << data_[r * cols_ + c] << " ";
    }
    out << std::endl;
  }
  return true;
}
std::vector<float> const igg::Image::ComputeHistogram(int bins) const {
  const float max_int = 255;
  const auto total_size = float(rows_ * cols_);
  const float interval = max_int / float(bins);
  std::vector<float> histogram(bins);

  for (int data : data_) {
    int i = floor(data / interval);
    if (i == bins) {
      histogram[bins - 1] += 1;
    } else {
      histogram[i] += 1;
    }
  }
  for (float &i : histogram) {
    i /= total_size;
  }
  return histogram;
}
void igg::Image::DownScale(const int scale) {
  int down_rows = rows_ / scale;
  int down_cols = cols_ / scale;
  Image down_image=Image(down_rows, down_cols);
  for (int i = 0; i < down_rows; i++) {
    for (int j = 0; j < down_cols; j++) {
      down_image.at(i,j)=at(i*scale,j*scale);
    }
  }
  rows_ = down_rows;
  cols_ = down_cols;
  data_ = down_image.data_;
}
void igg::Image::UpScale(const int scale) {
  int up_rows = rows_ * scale;
  int up_cols = cols_ * scale;
  Image up_image = Image(up_rows, up_cols);
  for (int i = 0; i < up_rows; i++) {
    for (int j = 0; j < up_cols; j++) {
      up_image.at(i, j) = at(i/scale,j/scale);
    }
  }
  rows_ = up_rows;
  cols_ = up_cols;
  data_ = up_image.data_;
}