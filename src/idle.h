/*
** idle wrapper.
** wrap the idle handler. the subclass of handle class 
*/

#ifndef UV_IDLE_H
#define UV_IDLE_H

#include "define.h"
#include "handle_wrapper.h"



//CIdle class manage idle handle.   
class CIdle : public CHandle
{
public:
	CIdle();

	virtual ~CIdle();
	
	int Init();

	void Start(uv_idle_cb cb);

private:	
	uv_idle_t   m_IdleHandle;	
};

#endif

