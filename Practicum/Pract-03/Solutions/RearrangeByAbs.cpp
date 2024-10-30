#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Time complexity: O(n)
// Space complexity: O(1)
void rearrangeByAbsPartition(std::vector<int>& arr)
{
    auto it = arr.begin();
    for (int num = 0; num <= 100; ++num)
    {
        it = std::partition(it, arr.end(), [num](int a) { return num == abs(a); });
        if (it == arr.end()) break;
    }
}

// Time complexity: O(n*log(n)) - in order to keep the relative order of elements
// Space complexity: O(n) - additional space for stable_partition in order to keep the relative order of elements
void rearrangeByAbsStablePartition(std::vector<int>& arr)
{
    auto it = arr.begin();
    for (int num = 0; num <= 100; ++num)
    {
        it = std::stable_partition(it, arr.end(), [num](int a) { return num == abs(a); });
        if (it == arr.end()) break;
    }
}

// Time complexity: O(n)
// Space complexity: O(n)
void rearrangeByAbsCounting(std::vector<int>& arr)
{
    std::vector<int> positive[101];
    std::vector<int> negative[101];

    for (int num : arr) {
        if (num > 0) {
            positive[std::abs(num)].push_back(num);
        } else {
            negative[std::abs(num)].push_back(num);
        }
    }

    int index = 0;
    for (int abs_value = 1; abs_value <= 100; ++abs_value) {
        for (int num : positive[abs_value]) {
            arr[index++] = num;
        }
        for (int num : negative[abs_value]) {
            arr[index++] = num;
        }
    }
}

void printVector(const std::vector<int>& arr)
{
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    {
        std::vector<int> arr = {-1, 5, 3, 4, 1, -3, -4, -5, 1};
        rearrangeByAbsPartition(arr);
        printVector(arr); // -1 1 1 -3 3 4 -4 -5 5
    }
    {
        std::vector<int> arr = {-1, 5, 3, 4, 1, -3, -4, -5, 1};
        rearrangeByAbsStablePartition(arr);
        printVector(arr); // -1 1 1 3 -3 4 -4 5 -5
    }
    {
        std::vector<int> arr = {-1, 5, 3, 4, 1, -3, -4, -5, 1};
        rearrangeByAbsCounting(arr);
        printVector(arr); // 1 1 -1 3 -3 4 -4 5 -5
    }
}