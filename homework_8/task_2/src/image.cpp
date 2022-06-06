#include "../include/image.hpp"

void igg::Image::SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr) {
  this->io_strategy=strategy_ptr;
}
bool igg::Image::ReadFromDisk(const std::string &file_name) {
  return io_strategy->ReadFromDisk(file_name);
}