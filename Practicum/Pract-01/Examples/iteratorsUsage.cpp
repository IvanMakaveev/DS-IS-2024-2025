#include <iostream>
#include <vector>
#include <algorithm>

struct Person
{
    std::string name;
    int age;
};

bool compareByAge(const Person &a, const Person &b)
{
    return a.age < b.age;
}

int main()
{
    // Iterator example
    // -> iterator is a pointer-like object that points to an element in a container
    // -> can be used to iterate over elements in a container
    // -> can be used to access elements in a container
    // -> can be used to modify elements in a container
    // -> begin() returns an iterator pointing to the first element
    // -> end() returns an iterator pointing to the element after the last element
    std::vector<int> nums = {4, 2, 9, 7, 5, 1};
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        std::cout << *it << " "; // 4 2 9 7 5 1
    }
    std::cout << std::endl;

    // std::distance(iterator1, iterator2)
    // -> returns the distance between two iterators, O(n)
    std::cout << "Distance between begin() and end(): " << std::distance(nums.begin(), nums.end()) << std::endl; // Distance between begin() and end(): 6

    // std::find(iterator1, iterator2, serachValue)
    // -> linear search, O(n)
    // -> [iterator1, iterator2) is the range to search in
    // -> returns iterator pointing to the first element found
    // -> if not found, returns end()
    auto it = std::find(nums.begin(), nums.end(), 9);
    if (it != nums.end())
    {
        std::cout << "Found number: " << *it << std::endl;                               // Found number: 9
        std::cout << "Found at index: " << std::distance(nums.begin(), it) << std::endl; // Found at index: 2
    }

    // std::reverse(iterator1, iterator2)
    // -> reverses the order of elements in a container, O(n)
    // -> [iterator1, iterator2) is the range to reverse
    std::reverse(nums.begin(), nums.end());
    for (int n : nums) // <=> for (int i = 0; i < nums.size(); i++)
    {
        std::cout << n << " "; // 1 5 7 9 2 4
    }
    std::cout << std::endl;

    // std::max_element(iterator1, iterator2)
    // -> returns iterator pointing to the max element in the range, O(n)
    // -> [iterator1, iterator2) is the range to search in
    // -> if multiple max elements, returns the first one
    // -> if empty range, returns end()
    it = std::max_element(nums.begin(), nums.end());
    if (it != nums.end())
    {
        std::cout << "Max element: " << *it << std::endl; // Max element: 9
    }

    // std::min_element(iterator1, iterator2)
    // -> returns iterator pointing to the min element in the range, O(n)
    // -> [iterator1, iterator2) is the range to search in
    // -> if multiple min elements, returns the first one
    // -> if empty range, returns end()
    it = std::min_element(nums.begin(), nums.end());
    if (it != nums.end())
    {
        std::cout << "Min element: " << *it << std::endl; // Min element: 1
    }

    // std::sort (ascending order)
    // std::sort(iterator1, iterator2)
    // -> sorts the elements in a container in ascending order, O(nlogn)
    // -> [iterator1, iterator2) is the range to sort
    // -> default comparison function is std::less<T>()
    std::vector<int> numsAsc = {7, 5, 20, 11, 35, 3};
    std::sort(numsAsc.begin(), numsAsc.end());
    for (int n : numsAsc)
    {
        std::cout << n << " "; // 3 5 7 11 20 35
    }
    std::cout << std::endl;

    // std::sort (descending order)
    // -> custom comparison function is std::greater<T>()
    // -> std::greater<T>() is a function object that returns true if a > b and false if a <= b
    std::vector<int> numsDesc = {8, 18, 6, 10, 2, 15};
    std::sort(numsDesc.begin(), numsDesc.end(), std::greater<int>());
    for (int n : numsDesc)
    {
        std::cout << n << " "; // 18 15 10 8 6 2
    }
    std::cout << std::endl;

    // std::sort (custom comparison function)
    // -> example with more complex data type
    // -> custom comparison function is compareByAge
    std::vector<Person> people = {{"Alice", 25}, {"Bob", 20}, {"Charlie", 30}};
    std::sort(people.begin(), people.end(), compareByAge);
    for (const Person &p : people)
    {
        std::cout << p.name << " " << p.age << ", "; // Bob 20, Alice 25, Charlie 30
    }

    return 0;
}
