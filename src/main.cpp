#include <iostream>
#include <opencv2/opencv.hpp>
#include "include/last.h"
#include <include/args.h>
#include <include/paddleocr.h>

using namespace std;
using namespace cv;
using namespace PaddleOCR;

float scalingfactor = -89.400604;

Mat newcam_mtx = (Mat_<double>(3,3) << 1.23274580e+04, 0.00000000e+00, 1.25236768e+03,
                  0.00000000e+00, 1.10874355e+04, 9.23223976e+02,
                  0.00000000e+00, 0.00000000e+00, 1.00000000e+00);
Mat inverse_newcam_mtx = newcam_mtx.inv();

Mat tvec1 = (Mat_<double>(3,1) << 10.16173016, 5.36255966, -91.67960961);

Mat R_mtx = (Mat_<double>(3,3) << -0.90037802, 0.00690048, -0.4350538,
             0.02249729, -0.99779849, -0.06238619,
             -0.43452653, -0.06595869, 0.89824059);
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
    Scalar lower_white = Scalar(0, 28, 230);
    Scalar higher_white = Scalar(150, 150, 260);
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

vector<MyData> circle_detector(string path_one_img, PPOCR &ocr_model) {
    Mat img_left = imread(path_one_img, 1);

    vector<Vec3f> circles_left;
    circles_left = circle_help(img_left);

    //vector<pair<int, Point2d>> record;
    vector<MyData> result;
    std::set<string> record;
    if (!circles_left.empty()) {
        for (size_t i = 0; i < circles_left.size(); i++) {
            int a = cvRound(circles_left[i][0]);
            int b = cvRound(circles_left[i][1]);
            int r = cvRound(circles_left[i][2]);
            Rect roi(int(a - r / 2) - 28, int(b - r / 2) - 28, r + 56, r + 56);
            Mat cropped = img_left(roi);
            string cur_string;

	    try{
                cur_string = cap2str(cropped, ocr_model);
            }
            catch(...){
                std::cerr << "Warning: occors in function cap2str()" << std::endl;           
                continue;
            }
           
            record.insert(cur_string);
            Point2d real_xy = calculate_XYZ(a, b);
	    MyData cur_circle;
            cur_circle.num = i;
            cur_circle.myPoint = real_xy;
            cur_circle.myString = cur_string;
            result.push_back(cur_circle);
        }
    }

    return result;
}

int main(int argc, char **argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);

    string one_img = FLAGS_img_path;
    PPOCR ocr_model = PPOCR();

    vector<MyData> circles = circle_detector(one_img, ocr_model);
    
    for (MyData item : circles) {
        cout << "output: " <<item.num << " (" << round(item.myPoint.x) << ", " << round(item.myPoint.y) << ") " << item.myString<<endl;
    }

    return 0;
}

