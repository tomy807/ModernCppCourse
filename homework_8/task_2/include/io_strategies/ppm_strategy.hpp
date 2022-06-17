#ifndef Ppm_Strategy_HPP_
#define Ppm_Strategy_HPP_
#include "strategy.hpp"
#include <fstream>
namespace igg {
  class PpmIoStrategy
    :public IoStrategy {
    tmpImage ReadFromDisk(const std::string& file_name) override;
    bool WriteToDisk(const std::string& file_name, tmpImage& image) override;
  };
} // namespace igg
#endif