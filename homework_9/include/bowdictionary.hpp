#ifndef BOWDICTIONARY_HPP_
#define BOWDICTIONARY_HPP_
#include "kmeans.hpp"
#include <experimental/filesystem>
#include <iostream>
#include <opencv2/core.hpp>
#include <string>
#include <vector>

namespace ipb {
  class BowDictionary {
    private:
      cv::Mat dictionary;
      BowDictionary() = default;
      BowDictionary(const BowDictionary &other);

    public:
      static BowDictionary& GetInstance() {
        static BowDictionary instance;
        return instance;
      }

      void build(const int max_iter, const int dict_size,
                 const std::vector<cv::Mat>& descriptors);

      cv::Mat vocabulary() { return dictionary; }

      int size() { return dictionary.rows; }

      void set_vocabulary(const cv::Mat descriptors) {
        dictionary = descriptors;
      }

      bool empty() {
        if (size() == 0) {
          return true;
        }
        return false;
      }
  };
} // namespace ipb
#endif