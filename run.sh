cur_dir=/home/zjl/123/cpp_infer
export LD_LIBRARY_PATH=${cur_dir}/paddle_inference/third_party/install/onnxruntime/lib/:$LD_LIBRARY_PATH   
export LD_LIBRARY_PATH=${cur_dir}/paddle_inference/third_party/install/paddle2onnx/lib/:$LD_LIBRARY_PATH   
export LD_LIBRARY_PATH=${cur_dir}/paddle_inference/third_party/install/mkldnn/lib/:$LD_LIBRARY_PATH  

./build/ppocr \
    --det_model_dir=${cur_dir}/utils/inference/det_model \
    --rec_model_dir=${cur_dir}/utils/inference/rec_model \
    --rec_char_dict_path=${cur_dir}/utils/en_dict.txt \
    --image_dir=${cur_dir}/utils/img/output/spined_2.png \
    --use_angle_cls=false \
    --det=true \
    --rec=true \
    --cls=false \

