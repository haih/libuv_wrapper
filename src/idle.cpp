#include "idle.h"


CIdle::CIdle()
{
	
	LOG(INFO) <<"CIdler "<< this <<" Constructor!";
} 

CIdle::~CIdle()
{
	LOG(INFO) <<"CIdler "<< this <<" Destructor!";
}

int CIdle::Init()
{
	m_IdleHandle.data = (void*)this;
	if(0 == uv_idle_init(GetLoop(),&m_IdleHandle))
	{
		return 0;
	}
	else
	{
		LOG(ERROR) <<"CIdler initial failed!";	
		return -1;
	}

}

void CIdle::Start(uv_idle_cb cb)
{
	uv_idle_start(&m_IdleHandle,cb);
}

/*
//the call back function may be should implement by custon using start().
void CIdle::OnIdle(uv_idle_t* handle,int status) 
{
//TODO 
//May add some callback function pointer.
	LOG(INFO) <<"CIdle::OnIdle is been called~"<<"status = "<<status;
}
*/
