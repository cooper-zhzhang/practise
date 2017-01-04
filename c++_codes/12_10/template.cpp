#include <iostream>

template<unsigned n>
struct Factorical {
	enum {
		value = n * Factorical<n-1>::value
	};
};

template<>
struct Factorical<0> {
	enum {
		value = 1
	};
};


int main() {
	unsigned n = 1;
	std::cin >> n;

	std::cout << Factorical<5>::value << std::endl;
	std::cout << Factorical<10>::value << std::endl;

	return 0;
}
