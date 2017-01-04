class Condition
{
public:
	void wait()
	{
		pthread_cond_wait(&cond_, mutex.getPthreadMutex(), NULL);
	}

	void signal() 
	{
		pthread_cond_signal(&cond_);
	}

private:
	pthread_cond_t cond_;
	Mutex mutex;
};
