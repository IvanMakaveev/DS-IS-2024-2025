#include <iostream>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)
void countingSort(std::vector<int>& arr) {
    int range = 201; // от -100 до 100
    std::vector<int> count(range, 0);

    for (int num : arr) {
        count[num + 100]++; // преместваме индекса с 100, за да покрием отрицателни числа, като ги превърнем в положителни
    }

    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i]--) {
            arr[index++] = i - 100; // възстановяваме реалната стойност на числото като върнем 100 от индекса
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
    std::vector<int> arr = {55, -19, 27, 0, -100, 100, -35, 11};
    countingSort(arr);
    printVector(arr);

    return 0;
}
