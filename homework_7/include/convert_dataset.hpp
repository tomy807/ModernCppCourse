#ifndef CONVERT_DATASET_HPP_
#define CONVERT_DATASET_HPP_

#include <experimental/filesystem>
#include <string>
#include <vector>
#include "serialize.hpp"
#include <opencv2/core/mat.hpp>

namespace ipb::serialization::sifts {
  void ConvertDataset(const std::experimental::filesystem::path& img_path);
  std::vector<cv::Mat> LoadDataset(const std::experimental::filesystem::path& bin_path);
} // namespace ipb::serialization::sifts
#endif // CONVERT_DATASET_HPP_