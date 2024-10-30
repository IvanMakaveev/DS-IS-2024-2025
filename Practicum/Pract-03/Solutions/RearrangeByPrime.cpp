#include <iostream>
#include <vector>
#include <algorithm>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void printVector(const std::vector<int>& arr)
{
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {10, 3, 5, 9, 2, 8};
    std::partition(arr.begin(), arr.end(), isPrime); // Time complexity: O(n), Space complexity: O(1)
    printVector(arr);

    return 0;
}
