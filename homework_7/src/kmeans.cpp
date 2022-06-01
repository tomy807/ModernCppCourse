#include "../include/kmeans.hpp"
#include <opencv2/opencv.hpp>
struct Point {
  int point_id_;
  cv::Mat_<float> mat_;
  Point(int point_id, cv::Mat_<float> mat) : point_id_(point_id), mat_(mat){};
};
// update centroids(means of descriptors that close to the centroid)
void update_centroids(std::vector<Point>& centroids,std::vector<Point>& descriptors,int dimensions,int k) {
  for (Point& centroid : centroids) {
    float point_count = 0;
    cv::Mat sum_mat = cv::Mat::zeros(1, dimensions, CV_32FC1);
    for (Point descriptor : descriptors) {
      if (descriptor.point_id_ == centroid.point_id_) {
        sum_mat += descriptor.mat_;
        point_count += 1;
      }
    }
    if (point_count != 0) {
      sum_mat /= point_count;
      centroid.mat_ = sum_mat;
    }
  }
}
/*
find closest centroid to the descriptor
count Euclidean distance from centroid to descriptor
  1.minus each points
  2.mul each points(squre)
  3.find minimum
*/
int close_centroid(std::vector<Point>& centroids, cv::Mat descriptor) {
  float min_distance = FLT_MAX;
  int centroid_id = 0;
  for (Point centroid : centroids) {
    cv::Mat centroid_mat = centroid.mat_;    
    cv::Mat minus_mat = descriptor - centroid_mat;
    minus_mat = minus_mat.mul(minus_mat);
    float min_tmp = (float)sum(minus_mat)[0];
    if (min_distance > min_tmp) {
      min_distance = min_tmp;
      centroid_id = centroid.point_id_;
    }
  }
  return centroid_id;
}
cv::Mat ipb::kMeans(const std::vector<cv::Mat>& descriptors, int k, int max_iter) {
  std::vector<Point> centroids;
  std::vector<Point> descriptors_point;
  int dimensions = descriptors[0].cols;
  cv::RNG rng(cv::getTickCount());

  //   centroids initialization(k random centroids)
  for (int i = 1; i < k + 1; i++) {
    cv::Mat_<float> random_mat(1, dimensions);
    rng.fill(random_mat, cv::RNG::UNIFORM, 0, 255);
    centroids.emplace_back(Point(i, random_mat));
  }
  //   descriptors_point initialization
  for (cv::Mat descriptor : descriptors) {
    int centroid_id = close_centroid(centroids, descriptor);
    descriptors_point.emplace_back(Point(centroid_id, descriptor));
  }
  //  repeat cycle max_iter times
  for (int iter = 0; iter < max_iter; iter++) {
    update_centroids(centroids, descriptors_point, dimensions, k);
    for (Point descriptor : descriptors_point) {
      int centroid_id = close_centroid(centroids, descriptor.mat_);
      descriptor.point_id_ = centroid_id;
    }
  }
  cv::Mat result;
  for (Point centroid : centroids) {
    result.push_back(centroid.mat_);
  }
  return result;
}