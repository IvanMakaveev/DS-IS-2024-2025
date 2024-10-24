#include <iostream>
#include <vector>
#include <algorithm>

template <typename RandomIt, typename Predicate>
RandomIt partitionIt(RandomIt first, RandomIt last, Predicate pred)
{
    RandomIt boundary = first;

    while (boundary != last && pred(*boundary)) {
        ++boundary;
    }

    if (boundary == last)
        return boundary;

    for (RandomIt it = boundary + 1; it != last; ++it) {
        if (pred(*it)) {
            std::swap(*it, *boundary);
            ++boundary;
        }
    }

    return boundary;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto isIven = [](int n) { return n % 2 == 0; };

    // Partition the numbers based on whether they are even
    auto boundary = partitionIt(numbers.begin(), numbers.end(), isIven);

    // Output the numbers after partitioning
    std::cout << "Partitioned numbers: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }

    // Output the boundary index
    std::cout << "\nBoundary: " << std::distance(numbers.begin(), boundary) << std::endl;
}