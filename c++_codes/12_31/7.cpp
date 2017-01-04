#include <iostream>

using namespace std;

class TestMove
{
	public:
		TestMove(int data_):data(data_)
		{}
		TestMove(TestMove &&b) noexcept
		{
			this->data = b.data;
		}
		~TestMove()
		{
			++count;
		}
		static int count;
	private:
		int data;
};

int TestMove::count = 0;

void read(TestMove &&obj)
{
	cout << "read" << endl;
}

int main()
{
	{
		TestMove test1(1);
		read(move(test1));
	}

	cout << TestMove::count << endl;

	return 0;
}

