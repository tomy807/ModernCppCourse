#ifndef Png_Strategy_HPP_
#define Png_Strategy_HPP_
#include "strategy.hpp"
namespace igg {
  class PngIoStrategy
      :public IoStrategy {
    tmpImage ReadFromDisk(const std::string& file_name) override;
    bool WriteToDisk(const std::string& file_name, tmpImage& image) override;
  };
} // namespace igg
#endif