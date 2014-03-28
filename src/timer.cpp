#include "timer.h"

CTimer::CTimer()
{
	LOG(INFO) <<"CTimer "<< this <<" Constructor!";	
}


CTimer::CTimer(uint64_t timeOut,uint64_t repeatInterval)
				 :m_timeout(timeOut),
				  m_repeat(repeatInterval)
{
	LOG(INFO) <<"CTimer "<< this <<" Constructor!";	
}

void CTimer::Init()
{
	int res = uv_timer_init(GetLoop(),&m_TimerHandle);
	ASSERT(0 == res);
	m_TimerHandle.data = this;
}

CTimer::~CTimer()
{
	//uv_close(&m_TimerHandle,uv_close_cb close_cb);
	LOG(INFO) <<"CTimer "<< this <<" Destructor!";	
}

int CTimer::Start(uv_timer_cb cb)
{
	if(0 == m_timeout && 0 == m_repeat)
	{
		LOG(WARNING) <<"CTimer::Start both timeout and repeat are zero~";
		return -1;
	}
	int res = uv_timer_start(&m_TimerHandle,cb,m_timeout,m_repeat);
	ASSERT(0 == res);
	return 0;
}

int CTimer::Stop()
{
	int res = uv_timer_stop(&m_TimerHandle);
	if(0 != res)
	{
		LOG(ERROR) << "CTimer::Stop Error~";
		return -1;
	}
	return 0;
}

void CTimer::SetTimeOut(uint64_t timeOut)
{
	m_timeout = timeOut;
}

void CTimer::SetRepeatInterval(uint64_t repeatInterval)
{
	m_repeat = repeatInterval;
}



