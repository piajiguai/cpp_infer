# cpp_infer


### 使用方式：

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

