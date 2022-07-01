#include "../../include/histogram.hpp"

ipb::Histogram::Histogram(const cv::Mat& descriptor,
                          const ipb::BowDictionary& dictionary) {
  cv::Mat dict = dictionary.GetInstance().vocabulary();
  if (descriptor.empty()) {
    data_={};
    return;
  }
  data_.resize(dict.rows, 0);
  for (int i = 0; i < descriptor.rows; i++) {
    float min_distance = FLT_MAX;
    int centroid_id = 0;
    cv::Mat descriptor_line = descriptor.row(i);
    for (int j = 0; j < dict.rows; j++) {
      cv::Mat dict_line = dict.row(j);
      float min_tmp = calculate_distance(dict_line, descriptor_line);
      if (min_distance > min_tmp) {
        min_distance=min_tmp;
        centroid_id = j;
      }
    }
    data_[centroid_id] += 1;
  }
};

std::ostream& ipb::operator<<(std::ostream& os, const Histogram& histogram) {
  auto _data = histogram.data();
  for (auto i : _data) {
    os << i << ", ";
  }
  return os;
}

void ipb::Histogram::WriteToCSV(std::string& filename) {
  std::ofstream file;
  file.open(filename);
  if (file.is_open()) {
    for (int element : data_) {
      file << element << std::endl;
    }
  } else {
    std::cout << "file is not opened" << std::endl;
  }
  file.close();
}
