class Solution
{
public:

	int missingNumber(vector<int> & nums)
	{
		int iCurrentSum = 0;
		
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			iCurrentSum += nums[iIndex];
		}
		
		return (0 + nums.size()) * (nums.size() + 1) / 2 - iCurrentSum;
    }
};

/*

这个题目很简单，把数组中所有数加起来，再用等差数列求和公式求出预期和值，减一下就 OK 了。

因为首个数是 0，所以不会出现边界问题，多一项也无所谓，反正是 0，嘻嘻。

*/
