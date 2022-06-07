#ifndef Ppm_Strategy_HPP_
#define Ppm_Strategy_HPP_
#include "strategy.hpp"
#include <fstream>
namespace igg {
class PpmIoStrategy :public IoStrategy {
  tmpImage ReadFromDisk(const std::string &file_name) override;
};
} // namespace igg
#endif