#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>
#include<vector>


using std::string;
using std::vector;
using std::cos;
using std::sin;
using std::atan2;
using std::map;
using std::pair;
using std::endl;
using std::cout;

using cv::Mat;
using cv::Rect;
using cv::Point;


cv::Mat two_valuing(const cv::Mat &img, const int thresh);      //用于预处理时图像的二值化

int rotateImage(const cv::Mat &src, cv::Mat &dst, const double angle, const int mode);      //以任意角度旋转图像
double get_spin_angle(const cv::Mat &binary);     //矫正图像方向，得到相差180°的两个图像

bool comp_rect(const Rect &a, const Rect &b);       //cv::Rect的自定义比较函数
vector<Rect> make_contour(const Mat &mdimg, const Mat &mdimg_tem, int w, int h, double Match_threshold);        //模板匹配并去重
string combine_lines(vector<pair<Rect, string>> all_found_contours);        //整理各符号位置，最后输出一行
void draw_contour(Mat img, vector<pair<Rect, string>> all_found_coutours);      //在图像上画矩形框
string combine(const Mat &spined_img);

vector<int> str2array(string output);
