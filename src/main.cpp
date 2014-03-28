/*
*main.cpp 
*/
#include "idle.h"
#include "timer.h"


//uv_timer_t timer;


void OnTimer(uv_timer_t* handle,int status)
{
	uv_timer_t* pTimerHandle = handle;
	
	CTimer* pTimer = (CTimer*)pTimerHandle->data;
	pTimer->Stop();

	cout<<"status = "<<status<<endl;
}



void timer_test()
{
	//uv_timer_t timer;
	CTimer* pTimer = new CTimer(2000,3000);
	pTimer->Init();
	pTimer->Start(OnTimer);
	return;
}


int main(int argc, char const *argv[])
{
	/* code */
	google::InitGoogleLogging(argv[0]); 
	FLAGS_log_dir="../log/";
	LOG(INFO) << "Start the main function~"; 
	timer_test();
	
	uv_run(uv_default_loop(),UV_RUN_DEFAULT);
	return 0;
}


