#ifndef BOWDICTIONARY_HPP_
#define BOWDICTIONARY_HPP_
#include <experimental/filesystem>
#include <string>
#include <vector>
#include <iostream>
#include "kmeans.hpp"
#include <opencv2/core/mat.hpp>

namespace ipb {
    class BowDictionary {
        private:
            int max_iterations_;
            int dictionary_size_;
            std::vector<cv::Mat> descriptors_;
            cv::Mat dictionary;
            BowDictionary(){};
            BowDictionary(const BowDictionary& other);
            ~BowDictionary(){};
        public:
            static BowDictionary& GetInstance() {
                static BowDictionary instance;
                return instance;
            }
            void set_params(const int max_iter, const int dict_size,
                            const std::vector<cv::Mat>& descriptors) {
                max_iterations_ = max_iter;
                dictionary_size_ = dict_size;
                descriptors_ = descriptors;
                // dictionary=kMeans(descriptors, dict_size, max_iter);
            }
            void set_max_iterations(const int kNewIterations) {
                max_iterations_ = kNewIterations;
            }
            void set_size(const int kNewSize) {
              dictionary_size_ = kNewSize;
            }
            void set_descriptors(std::vector<cv::Mat>& new_descriptors) {
                descriptors_ = new_descriptors;
            }
            int max_iterations() {
              return max_iterations_;
            }
            int size() {
              return dictionary_size_;
            }
            std::vector<cv::Mat> descriptors() {
              return descriptors_;
            }
            int total_features() {
                int total_features = 0;
                for (const auto& descriptor : descriptors_) {
                total_features += descriptor.rows;
                }
                return total_features;
            }
            bool empty() {
                if (dictionary_size_ == 0) {
                return true;
                }
                return false;
            }
    };
} // namespace ipb
#endif