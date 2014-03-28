/*
** idle wrapper.
** wrap the timer handler. the subclass of handle class 
*/

#ifndef UV_Timer_H
#define UV_Timer_H

#include "define.h"
#include "handle_wrapper.h"



//CIdle class manage idle handle.   
class CTimer : public CHandle
{
public:
	CTimer();
	
	CTimer(uint64_t timeOut,uint64_t repeatInterval);

	virtual ~CTimer();

	virtual void Init();
	
	virtual int Start(uv_timer_cb cb);

	virtual	int Stop();
	
	virtual void SetTimeOut(uint64_t timeOut);
	
	virtual void SetRepeatInterval(uint64_t repeatInterval);

private:	
	uv_timer_t   m_TimerHandle;	
	uint64_t m_timeout;
	uint64_t m_repeat;
};

#endif


