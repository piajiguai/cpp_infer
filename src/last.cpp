// Copyright (c) 2020 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <vector>
#include <map>

#include <include/args.h>
#include <include/paddleocr.h>
#include <include/utils.h>
#include <include/last.h>

using namespace PaddleOCR;


std::vector<std::pair<std::string, double>> ocr(std::vector<cv::String> &cv_all_img_names, PPOCR &ocr_model) {

  if (FLAGS_benchmark) {
    ocr_model.reset_timer();
  }
  
  std::vector<cv::Mat> img_list;
  std::vector<cv::String> img_names;
  for (int i = 0; i < cv_all_img_names.size(); ++i) {
    cv::Mat img = cv::imread(cv_all_img_names[i], cv::IMREAD_COLOR);
    if (!img.data) {
      std::cerr << "[ERROR] image read failed! image path: "
                << cv_all_img_names[i] << std::endl;
      continue;
    }
    img_list.push_back(img);
    img_names.push_back(cv_all_img_names[i]);
  }

  std::vector<std::vector<OCRPredictResult>> ocr_results =
      ocr_model.ocr(img_list, FLAGS_det, FLAGS_rec, FLAGS_cls);

  std::vector<std::pair<std::string, double>> outputs;
  for (int i = 0; i < img_names.size(); ++i) {
    // std::cout << "predict img: " << cv_all_img_names[i] << std::endl;
    std::pair<std::string, double> output = Utility::output_one_line(ocr_results[i]);
    outputs.push_back(output);
  }
  return outputs;
}

std::string cap2str(cv::Mat cap, PPOCR &ocr_model) {
  cv::String spined_1_path = FLAGS_cur_dir + std::string("utils/img/tmp/spined_1.png");  
  cv::String spined_2_path = FLAGS_cur_dir + std::string("utils/img/tmp/spined_2.png"); 
  cv::Mat binary = two_valuing(cap, thresh); 

  cv::Mat img1, img2;
  double rotate_angle = get_spin_angle(binary);
  rotateImage(cap, img1, rotate_angle, 0);
  rotateImage(cap, img2, rotate_angle + 180, 0);

//  cv::cvtColor(img1, img1, cv::COLOR_GRAY2BGR);
//  cv::cvtColor(img2, img2, cv::COLOR_GRAY2BGR); 

  cv::imwrite(spined_1_path, img1);
  cv::imwrite(spined_2_path, img2);

  std::vector<cv::String> cv_all_img_names;
  cv_all_img_names.push_back(spined_1_path);
  cv_all_img_names.push_back(spined_2_path);

  
  std::vector<std::pair<std::string, double>> outputs = ocr(cv_all_img_names, ocr_model);
  std::string ret = outputs[0].second > outputs[1].second ? outputs[0].first : outputs[1].first;
  if (ret.size() > 8) {
    cout << "Oops! The num of output string is over 8!" << endl;
    ret = string(ret.begin(), ret.begin() + 8);
	}
  std::transform(ret.begin(), ret.end(), ret.begin(), [](char const &c) {
                    return std::toupper(c);
                });

  return ret;
}

