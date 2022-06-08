#ifndef Strategy_HPP_
#define Strategy_HPP_
#include <string>
#include <memory>
#include <vector>
namespace igg {
class tmpPixel {
  public:
    int red_;
    int green_;
    int blue_;
    tmpPixel() {
      red_ = 0;
      green_ = 0;
      blue_ = 0;
    }
    tmpPixel(int& red, int& green, int& blue) {
      red_ = red;
      green_ = green;
      blue_ = blue;
    }
};
class tmpImage {
  public:
  int rows_;
  int cols_;
  std::vector<tmpPixel> data_;
  tmpImage(int& rows, int& cols, std::vector<tmpPixel> data) {
    rows_ = rows;
    cols_ = cols;
    data_.resize(rows*cols);
    data_ = std::move(data);
  };
};
class IoStrategy {
public:
  // IoStrategy();
  // IoStrategy(const IoStrategy& other){};
  // IoStrategy &operator=(const IoStrategy& other){};
  virtual ~IoStrategy() = default;
  virtual tmpImage ReadFromDisk(const std::string &file_name) = 0;
  virtual bool WriteToDisk(const std::string &file_name,tmpImage& image) =0;
};
} // namespace igg
#endif