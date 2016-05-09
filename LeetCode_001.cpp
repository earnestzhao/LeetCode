class Solution
{
public:

	vector<int> twoSum(vector<int> & nums, int target)
	{
		map<int, int> mapValueIndex;
	
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			mapValueIndex[nums[iIndex]] = iIndex;
		}
	
		vector<int> vecResult;
	
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			map<int, int>::iterator mapIterator = mapValueIndex.find(target - nums[iIndex]);
		
			if (mapIterator != mapValueIndex.end() && iIndex < mapIterator -> second)
			{
				vecResult.push_back(iIndex + 1);
				vecResult.push_back(mapIterator -> second + 1);
				return vecResult;
			}
		}
    }
};

/*

Using map.

*/
