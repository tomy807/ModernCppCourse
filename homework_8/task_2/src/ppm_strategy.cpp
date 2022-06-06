#include "../include/io_strategies/ppm_strategy.hpp"
bool igg::PpmIoStrategy::ReadFromDisk(const std::string &file_name) {
  std::ifstream in(file_name, std::ios_base::in);
  if (!in) {
    return false;
  }
  
}