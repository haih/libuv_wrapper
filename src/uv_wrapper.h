/*
*uv_wrapper.h
*/

#ifndef UV_WRAPPER_H
#define UV_WRAPPER_H

#include <iostream>
using namespace std;

#include "uv.h"
#include "glog/logging.h"

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

//
// Handle Types
//
/*

typedef struct uv_loop_s	 uv_loop_t;
typedef struct uv_handle_s	 uv_handle_t;
typedef struct uv_stream_s	 uv_stream_t;
typedef struct uv_tcp_s		 uv_tcp_t;
typedef struct uv_udp_s	 uv_udp_t;
typedef struct uv_pipe_s	 uv_pipe_t;
typedef struct uv_tty_s		 uv_tty_t;
typedef struct uv_poll_s	 uv_poll_t;
typedef struct uv_timer_s	 uv_timer_t;
typedef struct uv_prepare_s	 uv_prepare_t;
typedef struct uv_check_s	 uv_check_t;
typedef struct uv_idle_s		 uv_idle_t;
typedef struct uv_async_s	 uv_async_t;
typedef struct uv_process_s	 uv_process_t;
typedef struct uv_fs_event_s uv_fs_event_t;
typedef struct uv_fs_poll_s	 uv_fs_poll_t;
typedef struct uv_signal_s	 uv_signal_t;

// Request types

typedef struct uv_req_s		 	uv_req_t;
typedef struct uv_getaddrinfo_s	uv_getaddrinfo_t;
typedef struct uv_shutdown_s	uv_shutdown_t;
typedef struct uv_write_s		uv_write_t;
typedef struct uv_connect_s		uv_connect_t;
typedef struct uv_udp_send_s	uv_udp_send_t;
typedef struct uv_fs_s			uv_fs_t;
typedef struct uv_work_s		uv_work_t;

// None of the above 
typedef struct uv_cpu_info_s			uv_cpu_info_t;
typedef struct uv_interface_address_s 	uv_interface_address_t;
*/

//Base class for manage the handle. the  
class CHandle
{
public:
	CHandle(uv_loop_t* loop,uv_handle_t* pHandle = NULL):
				m_pHandle(pHandle),m_tid(uv_thread_self())
	{
		if(NULL == loop)
		{
			m_loop = uv_default_loop();
		}
		else
		{
			m_loop = loop;
		}
	}
	static CHandle* GetInstance();

	virtual ~CHandle(){}
	
	virtual void SetLoop(uv_loop_t* loop)
	{
		m_loop = loop;
	}
	virtual uv_loop_s* GetLoop()
	{
		return m_loop;
	}
	virtual unsigned long GetThreadId()
	{
		return m_tid;
	}
	
protected:	
	DISALLOW_COPY_AND_ASSIGN(CHandle);
	
	uv_loop_t* m_loop;
	uv_handle_t* m_pHandle;
	unsigned long m_tid;	
};


#endif
