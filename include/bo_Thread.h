 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-02 10:13:04
 ///
 
#ifndef __WD_BO_THREAD_H__
#define __WD_BO_THREAD_H__

#include "Noncopyable.h"

#include <pthread.h>
#include <functional>
using std::function;

namespace wd
{


class boThread
: Noncopyable // 表达语义
{
	using boThreadCallback = function<void()>;
public:
	boThread(boThreadCallback && cb);
	~boThread();

	void start();
	void join();
	
	bool isRunning() const {	return _isRunning;	}

private:
	static void * threadFunc(void *);//采用静态成员函数，就是为了去掉this的影响
private:
	pthread_t _pthid;
	bool _isRunning;
	boThreadCallback _cb;
};
}//end of namespace wd
 

#endif
