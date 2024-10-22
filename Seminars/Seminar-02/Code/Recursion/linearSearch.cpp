using namespace std;

template <class T>
bool linearSearch(const T* arr, unsigned len, const T& searched)
{
	if (len == 0)
		return false;

	return  *arr == searched || linearSearch(++arr, --len, searched);
}