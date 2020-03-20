 ///
 /// @file    WorkerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-02 17:26:03
 ///
 

#include "WorkerThread.h"
#include "Threadpool.h"


using namespace wd;

void WorkerThread::run()
{
	_threadpool.threadFunc();
}
