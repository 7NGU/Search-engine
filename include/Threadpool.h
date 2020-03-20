 ///
 /// @file    Threadpool.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-02 16:45:08
 ///
 
#ifndef __WD_THREADPOOL_H__
#define __WD_THREADPOOL_H__

#include "TaskQueue.h"

#include <vector>
#include <memory>

using namespace std;

namespace wd
{

class Task {
public:
	virtual
	void process() = 0;
    virtual ~Task() {};
};

class Thread;
class WorkerThread;

class Threadpool
{
	friend WorkerThread;
public:
	Threadpool(size_t threadNum, size_t queSize)
	: _threadNum(threadNum)
	, _queSize(queSize)
	, _taskQue(_queSize)
	, _isExit(false)
	{
		_threads.reserve(_threadNum);
	}

	~Threadpool();

	void start();
	void stop();
	void addTask(Task *);

private:
	void threadFunc();
	Task * getTask();

private:
	size_t _threadNum;
	size_t _queSize;
	vector<shared_ptr<Thread> > _threads;
	TaskQueue _taskQue;
	bool _isExit;
};


}//end of namespace wd

#endif
