#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <vector>
#include <include/last.h>

using namespace std;

int main(int argc, char **argv) {
    string img_path(cur_dir + string("utils/img/unspined/new_origin1.jpg"));
    cv::Mat title = cv::imread(img_path);
    
    vector<int> a = lt666(title);
    for (int i=0;i<8;i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
