#ifndef Image_HPP_
#define Image_HPP_
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "io_strategies/strategy.hpp"
namespace igg {
  class Image {
    class Pixel {
      public:
        int red;
        int green;
        int blue;
    };
    private:
      int rows_;
      int cols_;
      std::vector<Pixel> data_;
      std::shared_ptr<IoStrategy> io_strategy=nullptr;
    public:
      Image() {
        rows_ = 0;
        cols_ = 0;
      }
      Image(const int &rows, const int &cols) {
        rows_ = rows;
        cols_ = cols;
        data_.resize(rows * cols);
      }
      Image(const int &rows, const int &cols, std::vector<Pixel> data) {
        rows_ = rows;
        cols_ = cols;
        data_.resize(rows * cols);
        data_ = std::move(data);
      }
      Image(const Image &other) {
        cols_ = other.cols_;
        rows_ = other.rows_;
        data_ = other.data_;
      }
      Image(Image &&other)  noexcept {
        cols_ = other.cols_;
        rows_ = other.rows_;
        data_ = other.data_;

        other.cols_ = 0;
        other.rows_ = 0;
        other.data_ = {};
      }
      Image &operator=(const Image &other) {
        if (this != &other) {
          cols_ = other.cols_;
          rows_ = other.rows_;
          data_ = other.data_;
        }
        return *this;
      }
      Image &operator=(Image &&other)  noexcept {
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
      ~Image();
      int &rows() { return rows_; };
      int &cols() { return cols_; }
      int rows() const { return rows_; };
      int cols() const { return cols_; };
      Pixel at(int &row, int &col) const { return data_[row * cols_ + col]; };
      Pixel &at(const int row, const int col) {
        return data_[row * cols_ + col];
      };
      void DownScale(int scale);
      void UpScale(int scale);
      bool ReadFromDisk(const std::string &file_name);
      bool WriteToDisk(const std::string &file_name);
      void SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr);
  };

} // namespace igg
#endif