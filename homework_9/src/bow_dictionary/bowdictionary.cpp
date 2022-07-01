#include "../../include/bowdictionary.hpp"
void ipb::BowDictionary::build(const int max_iter, const int dict_size,
                          const std::vector<cv::Mat>& descriptors) {
  dictionary = kMeans(descriptors, dict_size, max_iter);
}