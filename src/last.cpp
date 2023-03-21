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
#include <include/paddlestructure.h>
#include <include/utils.h>
#include <include/last.h>

using namespace PaddleOCR;


std::vector<std::pair<std::string, double>> ocr(std::vector<cv::String> &cv_all_img_names) {
  PPOCR ocr = PPOCR();

  if (FLAGS_benchmark) {
    ocr.reset_timer();
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
      ocr.ocr(img_list, FLAGS_det, FLAGS_rec, FLAGS_cls);

  std::vector<std::pair<std::string, double>> outputs;
  for (int i = 0; i < img_names.size(); ++i) {
    // std::cout << "predict img: " << cv_all_img_names[i] << std::endl;
    std::pair<std::string, double> output = Utility::output_one_line(ocr_results[i]);
    outputs.push_back(output);
  }
  return outputs;
}


std::vector<int> lt666(const cv::Mat &title) {

  cv::String spined_1_path = cur_dir + std::string("utils/img/tmp/spined_1.png");  //旋转后保存路径1
  cv::String spined_2_path = cur_dir + std::string("utils/img/tmp/spined_2.png");  //旋转后保存路径2

  cv::Mat binary = two_valuing(title, thresh);
  cv::Mat img1, img2;
  spin(binary, img1, img2);

  cv::imwrite(spined_1_path, img1);
  cv::imwrite(spined_2_path, img2);

  std::vector<cv::String> cv_all_img_names;
  cv_all_img_names.push_back(spined_1_path);
  cv_all_img_names.push_back(spined_2_path);
  // cv::glob(FLAGS_image_dir, cv_all_img_names);

  std::vector<std::pair<std::string, double>> outputs = ocr(cv_all_img_names);
  std::string ret = outputs[0].second > outputs[1].second ? outputs[0].first : outputs[1].first;
  

  if (ret.size() > 8) {
  cout << "Oops! The num of output string is over 8!" << endl;
  ret = string(ret.begin(), ret.begin() + 8);
	}

  vector<int> ans = str2array(ret);
  return ans;
}
