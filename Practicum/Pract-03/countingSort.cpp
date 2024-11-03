#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> countingSort(const std::vector<int>& arr)
{
    std::vector<int> countArr(*std::max_element(arr.begin(), arr.end()) + 1);

    for (int num : arr)
        countArr[num]++;

    for (int i = 1; i < countArr.size(); i++)
        countArr[i] += countArr[i - 1];

    std::vector<int> sortedArr(arr.size());
    
    for (int i = sortedArr.size() - 1; i >= 0; i--)
    {
        sortedArr[--countArr[arr[i]]] = arr[i];
    }

    return sortedArr;
}

int main()
{
    std::vector<int> arr = {1,4,2,1,3,4,5};

    arr = countingSort(arr);
    for (auto el : arr)
        std::cout << el << ' ';
}