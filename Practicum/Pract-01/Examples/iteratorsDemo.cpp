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
    // Iterator
    std::vector<int> nums = {1, 2, 3, 4, 5};
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        std::cout << *it << " "; // 1 2 3 4 5
    }
 
    // find
    std::vector<int> nums = {1, 2, 3, 4, 5};
    auto it = std::find(nums.begin(), nums.end(), 3);
    if (it != nums.end())
    {
        std::cout << "Found: " << *it << std::endl; // Found: 3
    }
 
    // reverse
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::reverse(nums.begin(), nums.end());
    for (int n : nums) 
    {
        std::cout << n << " "; // 5 4 3 2 1
    }
        
    // max_element
    std::vector<int> nums = {4, 2, 9, 7, 5, 1};
    auto it = std::max_element(nums.begin(), nums.end());
    if (it != nums.end())
    {
        std::cout << "Max element: " << *it << std::endl; // Max element: 9
    }
 
    // min_element
    std::vector<int> nums = {4, 2, 9, 7, 5, 1};
    auto it = std::min_element(nums.begin(), nums.end());
    if (it != nums.end())
    {
        std::cout << "Min element: " << *it << std::endl; // Min element: 1
    }
 
    //  Ascending order
    std::vector<int> numbers = {4, 2, 9, 7, 5, 1};
    std::sort(numbers.begin(), numbers.end());
    for (int n : numbers)
    {
        std::cout << n << " "; // 1 2 4 5 7 9
    }
 
    // Descending order
    std::vector<int> numbers = {4, 2, 9, 7, 5, 1};
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    for (int n : numbers)
    {
        std::cout << n << " "; // 9 7 5 4 2 1
    }
 
    // Sort by age
    std::vector<Person> people = {{"Alice", 25}, {"Bob", 20}, {"Charlie", 30}};
    std::sort(people.begin(), people.end(), compareByAge);
 
    for (const Person &p : people)
    {
        std::cout << p.name << " " << p.age << ", "; // Bob 20, Alice 25, Charlie 30
    }
 
    return 0;
}