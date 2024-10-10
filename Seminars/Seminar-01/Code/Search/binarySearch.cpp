#include <utility>

template <class T>
int binarySearch(const T* arr, size_t size, const T& searched)
{
	size_t leftIndex = 0;
	size_t rightIndex = size - 1;
	while (leftIndex <= rightIndex)
	{
		size_t midIndex = leftIndex + (rightIndex - leftIndex) / 2;

		if (arr[midIndex] == searched)
		{
			return midIndex;
		}

		if (arr[midIndex] > searched)
		{
			rightIndex = midIndex - 1;
		}
		else
		{
			leftIndex = midIndex + 1;
		}
	}

	return -1;
}

// HW: да се напише с итератори
// Hint: std::distance