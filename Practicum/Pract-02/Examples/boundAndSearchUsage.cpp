#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};

    // upper_bound(iterator1, iterator2, value)
    // -> returns an iterator pointing to the first element in the range [iterator1, iterator2) which is greater than value
    // -> if no element is greater than value, it returns iterator2
    // -> the range [iterator1, iterator2) must be sorted
    // -> the complexity is logarithmic O(log(n))
    auto itUpper = std::upper_bound(nums.begin(), nums.end(), 3);
    if (itUpper != nums.end())
    {
        std::cout << "Upper bound: " << *itUpper << std::endl; // Upper bound: 4
    }

    // lower_bound(iterator1, iterator2, value)
    // -> returns an iterator pointing to the first element in the range [iterator1, iterator2) which is not less than value
    // -> if no element is not less than value, it returns iterator2
    // -> the range [iterator1, iterator2) must be sorted
    // -> the complexity is logarithmic O(log(n))
    auto itLower = std::lower_bound(nums.begin(), nums.end(), 3);
    if (itLower != nums.end())
    {
        std::cout << "Lower bound: " << *itLower << std::endl; // Lower bound: 3
    }

    // binary_search(iterator1, iterator2, value)
    // -> returns true if the value is in the range [iterator1, iterator2)
    // -> the range [iterator1, iterator2) must be sorted
    // -> the complexity is logarithmic O(log(n))
    int value = 3;
    if (std::binary_search(nums.begin(), nums.end(), value))
    {
        std::cout << "Value " << value << " is in the vector" << std::endl; // Value 3 is in the vector
    }
    else
    {
        std::cout << "Value " << value << " is not in the vector" << std::endl;
    }