#include <iostream>

namespace	org
{
	class		A
	{
		public:
		int		x;
	};

	void		f         (A a) {
		std::cout << a.x << std::endl;
std:: cout << "namespace::org" << std::endl;
	}
}

void 
f(org::A a)
{
std:: cout << a.x << std::endl;
std:: cout << "global" << a.x << std::endl;
}

int 
main()
{
	int		x = 11;
org::	A a;
	a.x = x;

::	f(a);
org::	f(a);

	return 0;
}
