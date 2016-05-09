class Solution
{
public:

	bool containsDuplicate(vector<int> & nums)
	{
		set<int> setNoDup;
		
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			if (setNoDup.find(nums[iIndex]) != setNoDup.end())
			{
				return true;
			}
			
			setNoDup.insert(nums[iIndex]);
		}
		
		return false;
    }
};

/*

Normal Set: O(nlogn).

*/
