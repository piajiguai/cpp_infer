#include <iostream>
#include <opencv2/opencv.hpp>
#include "include/last.h"
#include <include/args.h>

using namespace std;
using namespace cv;

float scalingfactor = 138.28;

Mat newcam_mtx = (Mat_<double>(3, 3) << 2.63797676e+04, 0.00000000e+00, 1.04655382e+03,
    0.00000000e+00, 2.41409961e+04, 1.20918688e+03,
    0.00000000e+00, 0.00000000e+00, 1.00000000e+00);
Mat inverse_newcam_mtx = newcam_mtx.inv();

Mat tvec1 = (Mat_<double>(3, 1) << 6.96596514, 3.19605319, 143.59501265);

Mat R_mtx = (Mat_<double>(3, 3) << -0.12765192, -0.88343605, -0.45082783,
    -0.97731071, 0.03457677, 0.20896941,
    -0.16902294, 0.46727421, -0.86780531);
Mat inverse_R_mtx = R_mtx.inv();

vector<pair<int, Point2d>> result;

struct MyData {
    int num;
    Point2d myPoint;
    string myString;
};

Point2d calculate_XYZ(double u, double v) {
    Mat uv_1 = (Mat_<double>(3, 1) << u, v, 1);
    Mat suv_1 = scalingfactor * uv_1;
    Mat xyz_c = inverse_newcam_mtx * suv_1;
    xyz_c = xyz_c - tvec1;
    Mat XYZ = inverse_R_mtx * xyz_c;
    Point2d point_xyz = { Point2d(XYZ.at<double>(0, 0), XYZ.at<double>(1, 0)) };
    return point_xyz;
}



vector<Vec3f> circle_help(Mat img) {
    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);
    Scalar lower_white = Scalar(0, 0, 221);
    Scalar higher_white = Scalar(180, 150, 255);
    Mat mask;
    inRange(hsv, lower_white, higher_white, mask);
    Mat white;
    bitwise_and(img, img, white, mask = mask);
    Mat gray;
    cvtColor(white, gray, COLOR_BGR2GRAY);
    Mat gray_blurred;
    blur(gray, gray_blurred, Size(3, 3));
    vector<Vec3f> detected_circles;
    HoughCircles(gray_blurred, detected_circles, HOUGH_GRADIENT, 1, 100, 50, 30, 20, 100);
    return detected_circles;

}

//string zifu()

vector<MyData> circle_detector(string path_left, string path_right) {
    Mat img_left = imread(path_left, 1);
    Mat img_right = imread(path_right, 1);

    vector<Vec3f> circles_left;
    vector<Vec3f> circles_right;
    circles_left = circle_help(img_left);
    circles_right = circle_help(img_right);

    //vector<pair<int, Point2d>> record;
    vector<MyData> result;
    std::set<string> record;
    if (!circles_right.empty()) {
        for (size_t i = 0; i < circles_right.size(); i++) {
            int a = cvRound(circles_right[i][0]);
            int b = cvRound(circles_right[i][1]);
            int r = cvRound(circles_right[i][2]);
            Rect roi(int(a - r / 2) - 26, int(b - r / 2) - 26, r + 52, r + 52);
            Mat cropped = img_right(roi);
            // string cur_string = "kkkkkkkk";
            
            string cur_string = cap2str(cropped);
            record.insert(cur_string);
            Point2d real_xy = calculate_XYZ(b,a);
            MyData cur_circle;
            cur_circle.num = i;
            cur_circle.myPoint = real_xy;
            cur_circle.myString = cur_string;
            /*cur_char.copy(cur_circle.myString, sizeof(cur_circle.myString));*/

            result.push_back(cur_circle);
        }
    }
    if (!circles_left.empty()) {
        for (size_t i = 0; i < circles_left.size(); i++) {
            int a = cvRound(circles_left[i][0]);
            int b = cvRound(circles_left[i][1]);
            int r = cvRound(circles_left[i][2]);
            Rect roi(int(a - r / 2) - 30, int(b - r / 2) - 30, r + 60, r + 60);
            Mat cropped = img_left(roi);
            // string cur_string = "kkkkkk";
            string cur_string;
            try{
                cur_string = cap2str(cropped);
                       
            }
            catch(...){
                std::cerr << "Warning: occors in function cap2str()" << std::endl;           
                continue;
            }
            std::set<string>::iterator it;
            it = record.find(cur_string);

            if (it == record.end()) {
                Point2d real_xy = calculate_XYZ(b, a);
                real_xy.x = real_xy.x + 9;
                MyData cur_circle;
                cur_circle.num = record.size();
                cur_circle.myPoint = real_xy;
                cur_circle.myString = cur_string;
                record.insert(cur_string);
                result.push_back(cur_circle);       
            }
        }

    }
    
    
    return result;
}

int main(int argc, char **argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);

    string left_img = FLAGS_left_img_path;
    string right_img = FLAGS_right_img_path;
    vector<MyData> circles = circle_detector(left_img, right_img);
    
    for (MyData item : circles) {
        cout << "output: " <<item.num << " (" << round(item.myPoint.x) << ", " << round(item.myPoint.y) << ") " << item.myString<<endl;
    }

    return 0;
}

