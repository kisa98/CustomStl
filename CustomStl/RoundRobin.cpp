#include <iostream>
#include "LinkedList.h"

struct Job {
	int job_Id;
	int total_work;
	int progress;

	Job() = delete;
	Job(int id, int total) : job_Id(id), total_work(total) {
		progress = 0;
	}

	~Job() {
		std::cout << "Job Destoryed" << std::endl;
	}

	void doJob() {
		++progress;
		std::cout << "Job " << job_Id << " : " << progress << " / " << total_work << "%" << std::endl;
	}

	bool jobCompleted() {
		if (progress == total_work) {
			std::cout << "Job Completed" << std::endl;
			return true;
		}
		else {
			return false;
		}
	}
};

class Scheduler {
private:
	LinkedList<Job*> readyQueue;

	size_t size() {
		return readyQueue.size();
	}

public:

	void addJob(Job* job) {
		readyQueue.push_back(job);
	}

	bool empty() {
		return size() == 0;
	}

	void processJob() {
		if (size() == 0)
			return;

		readyQueue[0]->doJob();

		if (readyQueue[0]->jobCompleted()) {
			readyQueue.pop_front();
		}
		else {
			Job* job = readyQueue.front();
			readyQueue.pop_front();
			readyQueue.push_back(job);
		}
	}
};