#ifndef Strategy_HPP_
#define Strategy_HPP_
#include <string>
#include <memory>
namespace igg {
class IoStrategy {
public:
  IoStrategy();
  // IoStrategy(const IoStrategy& other){};
  // IoStrategy &operator=(const IoStrategy& other){};
  virtual ~IoStrategy()=default;
  virtual bool ReadFromDisk(const std::string &file_name) = 0;
};
} // namespace igg
#endif