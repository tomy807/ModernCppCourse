#ifndef HISTOGRAM_HPP_
#define HISTOGRAM_HPP_
#include "bowdictionary.hpp"
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <string>

namespace ipb {
  class Histogram {
    private:
      std::vector<int> data_;
    public:
      Histogram() = default;

      Histogram(std::vector<int>& data) {
        data_ = data;
      }

      Histogram(const cv::Mat& descriptor,
                const ipb::BowDictionary& dictionary);

      std::vector<int> data() const { return data_; }

      bool empty() const {
        if (size()==0) {
          return true;
        }
        return false;
      }

      int size() const { return data_.size(); }

      friend std::ostream& operator<<(std::ostream& os,
                                      const Histogram& histogram);

      Histogram& operator=(const Histogram& other) = default;

      int& operator[](int idx) { return data_[idx]; }

      int operator[](int idx) const { return data_[idx]; }

      auto begin() const { return data_.begin(); }

      auto end() const{ return data_.end(); }

      auto cbegin() const { return data_.cbegin(); }

      auto cend() const { return data_.cend(); }


      void WriteToCSV(std::string& filename);

      static Histogram ReadFromCSV(std::string& filename) {
        std::vector<int> read_data;
        std::string line;
        int val;
        std::ifstream file(filename);
        if (file.is_open()) {
          while (std::getline(file, line)) {
            std::stringstream ss(line);
            while (ss >> val) {
              read_data.emplace_back(val);
            }
          }
        }
        else {
          std::cout << "file is not opened" << std::endl;
        }
        file.close();
        return Histogram(read_data);
      }
  };
}
#endif