#include <iostream>
#include <vector>

// Time complexity: O(n*log(n))
// Space complexity: O(n)
int mergeAndCount(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    int invCount = 0;

    // Сливане на подмасивите
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            invCount += (mid + 1) - (left + i);  // Всички елементи в левия подмасив са инверсии
        }
    }

    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }

    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }

    return invCount;
}

// Time complexity: O(n*log(n))
// Space complexity: O(n)
int mergeSortAndCount(std::vector<int>& arr, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);

        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

int main() {
    std::vector<int> arr = {2, 4, 1, 3, 5};

    int invCount = mergeSortAndCount(arr, 0, arr.size() - 1);

    std::cout << "Inversions count: " << invCount << std::endl;

    return 0;
}