/*
*main.cpp 
*/

#include "uv_wrapper.h"

int main(int argc, char const *argv[])
{
	/* code */
	google::InitGoogleLogging(argv[0]); 
	FLAGS_log_dir="../log/";
	LOG(INFO) << "Start the main function~"; 
	return 0;
}
