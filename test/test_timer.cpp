
#include "define.h"

int g_count = 0;

void OnTimer(uv_timer_t* handle,int status)
{
	uv_timer_t* pTimerHandle = handle;
	
	CTimer* pTimer = pTimerHandle->data;
	pTimer->Stop();

	cout<<"status = "<<status<<endl;
}

/*
 * Start the timer. `timeout` and `repeat` are in milliseconds.
 *
 * If timeout is zero, the callback fires on the next tick of the event loop.
 *
 * If repeat is non-zero, the callback fires first after timeout milliseconds
 * and then repeatedly after repeat milliseconds.
 */


void timer_test()
{
	CTimer* pTimer = new CTimer(2000,3000);
	pTimer->Init();
	pTimer->Start(uv_timer_cb cb)

	return;
}

