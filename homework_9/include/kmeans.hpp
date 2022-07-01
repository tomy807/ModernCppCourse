#ifndef KMEANS_HPP_
#define KMEANS_HPP_
#include <experimental/filesystem>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

template <typename Tp> bool mat_are_equal(cv::Mat& m1, cv::Mat& m2) {
  return std::equal(m1.begin<Tp>(), m1.end<Tp>(), m2.begin<Tp>());
}

float calculate_distance(cv::Mat& cetroid, cv::Mat& descriptor);

namespace ipb {
  cv::Mat kMeans(const std::vector<cv::Mat>& descriptors, int k, int max_iter);
} // namespace ipb
#endif