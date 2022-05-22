#include "../include/serialize.hpp"
#include <experimental/filesystem>
#include <fstream>
#include <vector>
#include <iostream>

namespace fs=std::experimental::filesystem;

/*
cv::Mat -> binary file(.bin file)
*/
void ipb::serialization::Serialize(const cv::Mat& m,
                                   const std::string& filename) {
  int type = m.type();
  std::ofstream file(filename, std::ios_base ::out | std::ios_base ::binary);

  file.write((const char *)(&m.rows), sizeof(int));
  file.write((const char *)(&m.cols), sizeof(int));
  file.write((const char *)(&type), sizeof(int));
  file.write((const char *)(m.data), m.elemSize() * m.total());
  return;
}

/*
binary file ->cv::Mat
*/
cv::Mat ipb::serialization::Deserialize(const std::string& filename) {
  int rows=0;
  int cols=0;
  int type=0;
  std::ifstream file(filename, std::ios_base::in | std::ios_base::binary);

  file.read((char *)(&rows), sizeof(int));
  file.read((char *)(&cols), sizeof(int));
  file.read((char *)(&type), sizeof(int));
  cv::Mat returnMat(rows,cols,type);
  file.read((char *)(returnMat.data), returnMat.elemSize() * returnMat.total());
  
  return returnMat;
}
