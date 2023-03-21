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

const int thresh = 210;

std::vector<std::pair<std::string, double>> ocr(std::vector<cv::String> &cv_all_img_names);
std::vector<int> lt666(const cv::Mat &title);