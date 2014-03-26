#ifndef DEFINE_H
#define DEFINE_H

#include <iostream>
#include <assert.h>

#include "uv.h"
#include "glog/logging.h"

using namespace std;

#define ASSERT(expr)  {if (!(expr)){LOG(ERROR) <<"assert "<<  #expr <<" failed"; assert(expr);} }
#define ASSERT_ERR(expr, errinfo)   {if (!(expr)){LOG(ERROR) <<"assert "<<  #expr <<" failed"; return errinfo;} }



#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

#endif

