#include "../include/convert_dataset.hpp"
#include "../include/serialize.hpp"

#include <experimental/filesystem>
#include <opencv2/imgcodecs.hpp>
#include <string>
#include <vector>

namespace fs = std::experimental::filesystem;

void ipb::serialization::sifts::ConvertDataset(const std::experimental::filesystem::path& img_path) {
  fs::create_directory("data/freiburg/bin/");
  if (img_path == "data/freiburg/dummy/") {
    return;
  }
  for (const auto& entry : fs::directory_iterator(img_path)) {
    auto mat = cv::imread(entry.path().string(), cv::IMREAD_GRAYSCALE);
    const auto& stem = entry.path().stem().string();
    const auto& descriptors_filename = "data/freiburg/bin/" + stem + ".bin";
    ipb::serialization::Serialize(mat, descriptors_filename);
  }
//   ipb::serialization::Serialize(const cv::Mat &m, const std::string &filename);
}

std::vector<cv::Mat> ipb::serialization::sifts::LoadDataset(const std::experimental::filesystem::path& bin_path) {
  std::vector<cv::Mat> descriptors = {};
  if (bin_path == "data/freiburg/dummy/") {
    return descriptors;
  }
  for (const auto& entry : fs::directory_iterator(bin_path)) {
    auto descriptor = ipb::serialization::Deserialize(entry.path().string());
    descriptors.push_back(descriptor);
  }
  return descriptors;
}