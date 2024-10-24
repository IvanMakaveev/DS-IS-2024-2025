#include <iostream>
#include <vector>

// Version 1
template<class RandomIt>
void mergeV1(RandomIt first1, RandomIt last1,
              RandomIt first2, RandomIt last2,
              RandomIt buff)
{
    for (; first1 != last1; ++buff) {
        if (first2 == last2) {
            for (; first1 != last1; ++first1, ++buff) {
                *buff = *first1;
            }
            return;
        }

        if (*first2 < *first1) {
            *buff = *first2;
            ++first2;
        } else {
            *buff = *first1;
            ++first1;
        }
    }

    for (; first2 != last2; ++first2, ++buff) {
        *buff = *first2;
    }
}

// Version 2
template <class RandomIt>
void mergeV2(RandomIt first1, RandomIt last1,
           RandomIt first2, RandomIt last2,
           RandomIt buff) {
    while (first1 != last1 && first2 != last2) {
        if (*first1 <= *first2) {
            *buff = *first1;
            ++first1;
        } else {
            *buff = *first2;
            ++first2;
        }
        ++buff;
    }

    while (first1 != last1) {
        *buff = *first1;
        ++first1;
        ++buff;
    }

    while (first2 != last2) {
        *buff = *first2;
        ++first2;
        ++buff;
    }
}

int main() {
    // Example 1: Merging two subranges from the same vector
    {
        std::vector<int> v = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
        std::vector<int> buffer(v.size());  // Pre-allocated buffer

        // Merging the first half and second half of the vector into the buffer
        mergeV1(v.begin(), v.begin() + 5, v.begin() + 5, v.end(), buffer.begin());

        // Output the merged result
        std::cout << "Merged result from two subranges of the same vector: ";
        for (int i : buffer) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    // Example 2: Merging two separate vectors
    {
        std::vector<int> v1 = {3, 8, 15, 20};
        std::vector<int> v2 = {1, 5, 10, 30};
        std::vector<int> buffer(v1.size() + v2.size()); // Pre-allocated buffer to store the merged result

        // Merging the two vectors into the buffer
        mergeV2(v1.begin(), v1.end(), v2.begin(), v2.end(), buffer.begin());

        std::cout << "Merged result from two separate vectors: ";
        for (int i : buffer) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}