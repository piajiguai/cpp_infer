cur_dir=/home/zjl/123/cpp_infer
export LD_LIBRARY_PATH=${cur_dir}/paddle_inference/third_party/install/onnxruntime/lib/:$LD_LIBRARY_PATH   
export LD_LIBRARY_PATH=${cur_dir}/paddle_inference/third_party/install/paddle2onnx/lib/:$LD_LIBRARY_PATH   
export LD_LIBRARY_PATH=${cur_dir}/paddle_inference/third_party/install/mkldnn/lib/:$LD_LIBRARY_PATH  

./build/ppocr \

