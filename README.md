# cpp_infer


### 使用方式：

（下载预测库和模型可参考https://github.com/PaddlePaddle/PaddleOCR/blob/release/2.6/deploy/cpp_infer/readme_ch.md）
1. 在当前cpp_infer文件夹中下载Paddle预测库

    ```shell
    wget https://paddle-inference-lib.bj.bcebos.com/2.3.2/cxx_c/Linux/CPU/gcc8.2_avx_mkl/paddle_inference.tgz
    tar -xf paddle_inference.tgz
    rm paddle_inference.tgz
    ```

2. 在/utils/inference/中下载pp-ocr检测和识别模型

    ```shell
    wget https://paddleocr.bj.bcebos.com/PP-OCRv3/english/en_PP-OCRv3_det_infer.tar
    tar -xf en_PP-OCRv3_det_infer.tar
    mv en_PP-OCRv3_det_infer.tar det_model
    rm en_PP-OCRv3_det_infer.tar

    wget https://paddleocr.bj.bcebos.com/PP-OCRv3/english/en_PP-OCRv3_rec_infer.tar
    tar -xf en_PP-OCRv3_rec_infer.tar
    mv en_PP-OCRv3_rec_infer.tar rec_model
    rm en_PP-OCRv3_rec_infer.tar
    ```


3. 编译并运行

    ```shell
    sudo sh build.sh
    sh run.sh
    ```


### 注意事项：

1. 需要修改/include/args.h中的cur_dir为当前机器上的cpp_infer的绝对路径

   ```cpp
   #define cur_dir "/home/zjl/123/cpp_infer/"
   ```

   

2. build.sh中指定opencv和paddle_inference的绝对路径

   ```shell
   OPENCV_DIR=/home/zjl/opt/opencv/opencv-4.5.4/build
   LIB_DIR=/home/zjl/123/cpp_infer/paddle_inference
   ```

   

3. src/main.cpp中line 171需要指定输入标签图像的相对路径

   ```cpp
   std::string pic_dir = cur_dir + std::string("utils/img/unspined/new_origin4.jpg");   //输入标签图像地址
   ```

