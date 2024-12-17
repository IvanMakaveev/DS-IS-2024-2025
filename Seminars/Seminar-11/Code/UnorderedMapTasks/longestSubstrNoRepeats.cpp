#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(const std::string& str)
{
    std::unordered_map<char, size_t> charsMap;

    size_t maxSize = 0;
    size_t currentStart = 0;

    for (size_t i = 0; i < str.size(); i++)
    {
        auto iter = charsMap.find(str[i]);
        if (iter != charsMap.end() && iter->second >= currentStart)
        {
            currentStart = iter->second + 1;
        }

        charsMap[str[i]] = i;
        size_t currentSize = i - currentStart + 1;
        maxSize = std::max(maxSize, currentSize);
    }
    return maxSize;
}
