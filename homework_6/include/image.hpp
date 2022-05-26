#ifndef Image_HPP_
#define Image_HPP_
#include <vector>
#include <string>
namespace igg {
class Image {

public:
  Image() {
    rows_ = 0;
    cols_ = 0;
    
  };
  Image(const int& rows, const int& cols) {
    rows_ = rows;
    cols_ = cols;
    data_.resize(rows*cols);
  };
  Image(const int& rows, const int& cols, std::vector<uint8_t> data) {
    rows_ = rows;
    cols_ = cols;
    data_.resize(rows * cols);
    data_ = data;
  }
  Image(const Image& other) {
    cols_ = other.cols_;
    rows_ = other.rows_;
    data_ = other.data_;
  }
  Image &operator=(const Image& other) {
    if (this != &other) {
      cols_ = other.cols_;
      rows_ = other.rows_;
      data_ = other.data_;
    }
    return *this;
  }
  Image(Image&& other) {
    cols_ = other.cols_;
    rows_ = other.rows_;
    data_ = other.data_;

    other.cols_ = 0;
    other.rows_ = 0;
    other.data_ = {};
  }

  Image &operator=(Image&& other) {
    if (this != &other) {
      cols_ = other.cols_;
      rows_ = other.rows_;
      data_ = other.data_;

      other.cols_ = 0;
      other.rows_ = 0;
      other.data_ = {};
    }
    return *this;
  }

  int& rows() { return rows_; };
  int& cols() { return cols_; }
  int rows() const { return rows_; };
  int cols() const { return cols_; };
  const uint8_t at(int& row, int &col) const {
    return data_[row * cols_ + col];
  };
  uint8_t& at(const int row, const int col) {
    return data_[row * cols_ + col];
  };
  bool FillFromPgm(const std::string &file_name);
  bool WriteToPgm(const std::string &file_name);
  std::vector<float> const ComputeHistogram(int bins) const;
  void DownScale(const int scale);
  void UpScale(const int scale);

private:
  int rows_;
  int cols_;
  std::vector<uint8_t> data_;
};

} // namespace igg
#endif