#ifndef Png_Strategy_HPP_
#define Png_Strategy_HPP_
#include "strategy.hpp"
namespace igg {
class PngIoStrategy :public IoStrategy {
    bool ReadFromDisk(const std::string &file_name) override;
};
} // namespace igg
#endif