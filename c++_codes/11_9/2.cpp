class App
{
public:
	virtual ~App();

	void startup() 
	{
		initialize();
		if(!validate())
		{
			altInit();
		}
	}

protected:
	virtual bool validate() const = 0;
	virtual void altInit();

private:
	void initialize();
};

class MyApp : public App
{
public:
	
private:
	bool validate() const;
	void altInit();
};


int main()
{

	return 0;
}
