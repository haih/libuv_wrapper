/*
*main.cpp 
*/

#include "uv_wrapper.h"


void test()
{
	CHandle* pHandle = new CHandle();
	unsigned long threadId = pHandle->GetThreadId();
	cout<<"Get thread Id = "<<threadId<<endl;
	return;
}


int main(int argc, char const *argv[])
{
	/* code */
	google::InitGoogleLogging(argv[0]); 
	FLAGS_log_dir="../log/";
	LOG(INFO) << "Start the main function~"; 
	test();
	return 0;
}
