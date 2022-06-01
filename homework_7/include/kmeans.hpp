#ifndef KMEANS_HPP_
#define KMEANS_HPP_

#include <experimental/filesystem>
#include <string>
#include <vector>

#include <opencv2/core/mat.hpp>

namespace ipb {
    cv::Mat kMeans(const std::vector<cv::Mat>& descriptors, int k, int max_iter);
} // namespace ipb
#endif