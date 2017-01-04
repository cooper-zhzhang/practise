#include <iostream>

struct Counter
{
	static ::std::size_t count;
	bool valid;

	Counter() : valid(true)
	{
	}

	Counter(Counter &&o) noexcept :valid(false)
	{
		::std::swap(valid, o.valid);
	}

	Counter& operator=(Counter&&) = delete;
	Counter(Counter const&) = delete;
	Counter& operator=(const Counter&) = delete;

	~Counter()
	{
		if(valid)
			count++;
	}
};

::std::size_t Counter::count = 0;

char buf[sizeof(Counter)] = {0};

void write(Counter &&counter)
{
	new (buf) Counter(::std::move(counter));
}

Counter read()
{
	Counter *ptr = (Counter *)buf;
	Counter counter(::std::move(*ptr));
	ptr->~Counter();
	return counter;
}

int main()
{
	{
		write({});
		Counter c = read();
	}
	printf("%zu\n", Counter::count);
}


