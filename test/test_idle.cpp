
#include "idle.h"

int g_count = 0;

void OnFunc(uv_idle_t* handle,int status)
{
	if(10 <= g_count)
	{
		cout<<"status = "<<status<<endl;
		uv_idle_stop(handle);
	}
	g_count++;
}

void idle_test()
{
	CIdle* pHandle = new CIdle;
	ASSERT(pHandle);
	pHandle->Init();
	pHandle->Start(OnFunc);
	return;
}


