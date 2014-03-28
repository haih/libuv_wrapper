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

	virtual ~CTimer();
	
	int Init();

	void Start(uv_idle_cb cb);

private:	
	uv_timer_t   m_TimerHandle;	
	uint64_t m_timeout;
	uint64_t m_repeat;
};

#endif


