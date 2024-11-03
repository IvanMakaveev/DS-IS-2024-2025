#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto b = std::partition()

    auto isGreatThan5 = [](int n) { return n > 5; };

    // Partition the numbers based on whether they are even
    auto boundary = std::partition(numbers.begin(), numbers.end(), isGreatThan5);

    // Output the numbers after partitioning
    std::cout << "Partitioned numbers: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }

    // Output the boundary index
    std::cout << "\nBoundary: " << std::distance(numbers.begin(), boundary) << std::endl;
}