#ifndef SERIALIZE_HPP_
#define SERIALIZE_HPP_

#include <string>
#include <opencv2/core/mat.hpp>

namespace ipb::serialization {
    void Serialize(const cv::Mat& m, const std::string& filename);
    cv::Mat Deserialize(const std::string& filename);
} // namespace ipb::serialization
#endif // SERIALIZE_HPP_