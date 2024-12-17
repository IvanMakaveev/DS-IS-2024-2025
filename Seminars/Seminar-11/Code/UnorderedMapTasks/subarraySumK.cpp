#include <vector>
#include <unordered_map>

int subarraySum(const std::vector<int>& nums, int k)
{
	std::unordered_map<int, int> prefixSumsMap;
	prefixSumsMap[0] = 1;

	int resultCount = 0;
	int sum = 0;

	for (int el : nums)
	{
		sum += el;
		if (prefixSumsMap.find(sum - k) != prefixSumsMap.end())
			resultCount += prefixSumsMap[sum - k];
		prefixSumsMap[sum] += 1;
	}
	return resultCount;
}
