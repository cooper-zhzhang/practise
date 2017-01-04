#include <iostream>
#include <string>

using namespace std;

enum FUCK
{
	TURR,
	FAA
};

class Button
{
public :
	Button(const string &lable) : label_(lable), action_(0) {}
	void setAction(void (*newAction)())
	{
		action_ = newAction;
	}

	void onClick() const
	{
		if(action_)
		{
			action_();
		}
	}

private:
	string label_;
	void (*action_)();
};


int main()
{
	Button button(string("click"));
	FUCK fuck = FAA;
	if(fuck == TURR)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	
	FUCK fuck1 = FAA;

	cout << fuck << endl;


	return 0;
}
