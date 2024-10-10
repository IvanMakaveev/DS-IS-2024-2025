#include <utility>

template <class T>
int linearSearch(const T* arr, size_t size, const T& target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}

	return -1;
}

template <class Iter, class T>
Iter linearSearch(Iter begin, Iter end, const T& value)
{
	for (Iter it = begin; it != end; ++it)
	{
		if (*it == value)
		{
			return it;
		}
	}

	return end;
}