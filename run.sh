cur_dir=$(cd "$(dirname "$0")";pwd)/

export LD_LIBRARY_PATH=${cur_dir}/paddle_inference/third_party/install/onnxruntime/lib/:$LD_LIBRARY_PATH   
export LD_LIBRARY_PATH=${cur_dir}/paddle_inference/third_party/install/paddle2onnx/lib/:$LD_LIBRARY_PATH   
export LD_LIBRARY_PATH=${cur_dir}/paddle_inference/third_party/install/mkldnn/lib/:$LD_LIBRARY_PATH  
export LD_LIBRARY_PATH=${cur_dir}/paddle_inference/third_party/install/mklml/lib/:$LD_LIBRARY_PATH 
export LD_LIBRARY_PATH=${cur_dir}/paddle_inference/paddle/lib/:$LD_LIBRARY_PATH 
export LD_LIBRARY_PATH=/install/lib/:$LD_LIBRARY_PATH 


./build/run \
  --cur_dir=${cur_dir} \
  --img_path=/cpp_infer/utils/img/one_img.jpg 

