#ifndef __LIB_IDL_H__
#define __LIB_IDL_H__

#ifdef static_lib
#define IDLIO
#else
#ifdef import_dll
#if defined(_MSC_VER)
#define IDLIO extern "C" __declspec(dllimport)
#endif
#else
#if defined(_MSC_VER)
#define IDLIO extern "C" __declspec(dllexport)
#else
#define IDLIO __attribute__((visibility("default")))
#endif
#endif
#endif
#ifdef USE_NAMESPACE
namespace IDL
{
#else
extern "C"
{
#endif
	//============================================================================
	//Device
	IDLIO int get_gpu_count();
	IDLIO size_t make_device(int device_type, int device_id);
	IDLIO bool release_device(size_t device_instance_id);
	//Handle
	IDLIO size_t make_handle(size_t device_instance_id);
	IDLIO bool release_handle(size_t handle_instance_id);
	//============================================================================
	//Video Instance
	IDLIO size_t make_video_instance(size_t device_instance_id, char* video_name);
	IDLIO bool release_video_instance(size_t video_instance_id);
	IDLIO void set_video_instance(size_t model_instance_id, size_t video_instance_id);
	IDLIO void set_video_instance_use_ptz_detection(size_t video_instance_id, bool value);
	IDLIO bool get_video_instance_use_ptz_detection(size_t video_instance_id);
	IDLIO void set_input_image(size_t video_instance_id, int batch_index, int height, int width, int channel, unsigned char* src, int flag = 0);
	IDLIO void video_instance_lock(size_t video_instance_id);
	IDLIO void video_instance_unlock(size_t video_instance_id);
	IDLIO bool video_instance_locked(size_t video_instance_id);
	IDLIO void set_video_instance_perspective_coeffs(size_t video_instance_id, double* perspective_coeffs, int slot_size);
	//============================================================================
	//Model
	IDLIO size_t make_model_instance(size_t handle_instance_id, int model_id);
	IDLIO void initialize(size_t model_instance_id);
	IDLIO void forward(size_t model_instance_id);
	IDLIO bool release_model_instance(size_t model_instance_id);
	//============================================================================
	//Model Save / Load
	//*.ai : only weight, encrypted
	//*.aix : model parameter + weight, encrypted
	IDLIO bool load_param_aix(size_t model_instance_id, char* path, bool encrypted);
	IDLIO void set_weight_tag(size_t model_instance_id, char* tag_name);
	IDLIO bool load_weight_ai(size_t model_instance_id, char* path, bool encrypted);
	IDLIO bool load_weight_aix(size_t model_instance_id, char* path, bool encrypted);
	IDLIO bool save_weight_ai(size_t model_instance_id, char* path, bool encrypted);
	IDLIO bool save_weight_aix(size_t model_instance_id, char* path, bool encrypted);
	IDLIO int* read_weight_tag_aix(char* path, bool encrypted);
	//Param
	//[0] version [1] input_width [2] input_height [3] input_channel [4] output_channel
	IDLIO void set_param(size_t model_instance_id, int index, float value);
	IDLIO int get_param_count(size_t model_instance_id);
	IDLIO float get_param(size_t model_instance_id, int index);
	//============================================================================
	//Tensor
	IDLIO int get_tensor_instance_count(size_t model_instance_id, char* query_name, int depth);
	IDLIO void get_tensor_instance(size_t model_instance_id, char* query_name, int depth, size_t* dst);
	IDLIO void get_tensor_shape(size_t tensor_instance_id, int* dst);
	IDLIO int get_tensor_layout_type(size_t tensor_instance_id);
	IDLIO int get_tensor_precision_type(size_t tensor_instance_id);
	IDLIO int* get_tensor_name(size_t tensor_instance_id);
	IDLIO void get_tensor_data(size_t tensor_instance_id, float* dst);
	//============================================================================
	//Decoder
	IDLIO int get_output_channel(size_t model_instance_id);
	IDLIO int* get_decoder_type(size_t model_instance_id);
	IDLIO int get_decoder_data_block_size(size_t model_instance_id);
	IDLIO int get_decoder_data_count(size_t model_instance_id);
	IDLIO void reset_decoder_iterator(size_t model_instance_id);
	IDLIO void next_decoder_data(size_t model_instance_id);
	IDLIO void get_decoder_data(size_t model_instance_id, float* dst);
	IDLIO float get_extension_value(size_t model_instance_id, int index);
	IDLIO void set_objectness_confidence_level(size_t model_instance_id, float value);
	IDLIO void set_class_confidence_level(size_t model_instance_id, int class_index, float value);
	IDLIO void set_class_confidence_level_array(size_t model_instance_id, float* value_array);
	//Thumbnail Encoder
	IDLIO void reset_thumbnail_iterator(size_t model_instance_id);
	IDLIO void next_thumbnail_data(size_t model_instance_id);
	IDLIO int get_thumbnail_data_block_size(size_t model_instance_id);
	IDLIO int get_thumbnail_data_count(size_t model_instance_id);
	IDLIO void get_thumbnail_data(size_t model_instance_id, float* dst);
	IDLIO void add_thumbnail_rect(size_t model_instance_id, int x, int y, int w, int h);
	//Color Extractor
	IDLIO void add_color_extractor_rect(size_t model_instance_id, int x, int y, int w, int h);
	IDLIO int get_color_extractor_K(size_t instance_id);
	IDLIO int get_color_extractor_num_images(size_t instance_id);
	IDLIO int get_color_extractor_output_count(size_t instance_id);
	IDLIO int get_color_extractor_output_block_size(size_t instance_id);
	IDLIO void reset_color_extractor_output_iterator(size_t instance_id);
	IDLIO void color_extractor_next_output(size_t instance_id);
	IDLIO void get_color_extractor_output(size_t instance_id, float* buffer);
	//============================================================================
	//Timer
	IDLIO void start_timer();
	IDLIO float end_timer();
	IDLIO float get_pre_time(size_t model_instance_id);
	IDLIO float get_net_time(size_t model_instance_id);
	IDLIO float get_post_time(size_t model_instance_id);
	//GPU Resource Usage
	IDLIO void update_gpu_status(size_t device_instance_id);
	IDLIO double get_gpu_usage(size_t device_instance_id);
	IDLIO double get_gpu_temperature(size_t device_instance_id);
	IDLIO double get_gpu_mem_total_kbytes(size_t device_instance_id);
	IDLIO double get_gpu_mem_used_kbytes(size_t device_instance_id);
	IDLIO double get_gpu_mem_usage(size_t device_instance_id);
	//===================================================================================
	//Debug
	IDLIO int* get_weight_tag(size_t model_instance_id);
	IDLIO int* get_model_type(size_t model_instance_id);
	IDLIO int get_model_count();
	IDLIO int* get_model_name(int index);
	IDLIO int get_model_id(char* model_string);
	IDLIO void open_console_log();
	IDLIO void close_console_log();
	IDLIO void load_model_darknet_weights(size_t model_instance_id, char* path);
	IDLIO int get_module_depth(size_t module_instance_id);
	IDLIO int* get_module_type(size_t module_instance_id);
#ifdef USE_NAMESPACE
};
#else
}
#endif
#endif