/*
*main.cpp 
*/
#include <idle.h>

uv_timer_t timer;


void OnTimer(uv_timer_t* handle,int status)
{
	cout<<"status = "<<status<<endl;
}


void timer_test()
{
	//uv_timer_t timer;
	int r = uv_timer_init(uv_default_loop(),&timer);
	cout<<"uv_timer_init return "<<r<<endl;
	int r1 =uv_timer_start(&timer,OnTimer,2000,1000);
	cout<<"uv_timer_init return "<<r1<<endl;
	return;
}


int main(int argc, char const *argv[])
{
	/* code */
	google::InitGoogleLogging(argv[0]); 
	FLAGS_log_dir="../log/";
	LOG(INFO) << "Start the main function~"; 
//	timer_test();
	uv_timer_t timer;
	int r = uv_timer_init(uv_default_loop(),&timer);
	cout<<"uv_timer_init return "<<r<<endl;
	int r1 =uv_timer_start(&timer,OnTimer,2000,1000);
	cout<<"uv_timer_init return "<<r1<<endl;
	uv_run(uv_default_loop(),UV_RUN_DEFAULT);
	return 0;
}


