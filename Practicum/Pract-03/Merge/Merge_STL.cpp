#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v1 = {-10, -5, 0, 5};
    std::vector<int> v2 = {-7, 1, 6, 20};
    std::vector<int> result(v1.size() + v2.size());

    // Merging the two sorted vectors into the result vector
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());

    std::cout << "Merged result: ";
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
