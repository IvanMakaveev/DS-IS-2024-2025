#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start, end;

    Interval(int s, int e) : start(s), end(e) {}
};

bool compareIntervalsByStart(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

// Time complexity: O(n*log(n))
// Space complexity: O(n)
std::vector<Interval> mergeIntervals(std::vector<Interval>& intervals) {
    if (intervals.empty()) {
        return {};
    }

    // Sort the intervals by start time with lambda function
    // std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
    //     return a.start < b.start;
    // });

    // Sort the intervals by start time with custom compare function
    std::sort(intervals.begin(), intervals.end(), compareIntervalsByStart);

    std::vector<Interval> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
        if (merged.back().end >= intervals[i].start) {
            merged.back().end = std::max(merged.back().end, intervals[i].end);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

void printIntervals(std::vector<Interval>& intervals) {
    std::cout << "[";
    for (int i = 0; i < intervals.size(); ++i) {
        std::cout << "[" << intervals[i].start << "," << intervals[i].end << "]";
        if (i != intervals.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    {
        std::vector<Interval> intervals = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};

        std::vector<Interval> result = mergeIntervals(intervals);

        printIntervals(result); // Output: [[1,4],[5,8]]
    }
    {
        std::vector<Interval> intervals = {{1, 10}, {2, 5}, {6, 8}};

        std::vector<Interval> result = mergeIntervals(intervals);

        printIntervals(result); // Output: [[1,10]]
    }

    return 0;
}
