class Solution
{
public:

	vector<int> majorityElement(vector<int> & nums)
	{
		int iResult1 = 0;
		int iResult2 = 0;
		
		int iResultCount1 = 0;
		int iResultCount2 = 0;
		
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			if (iResultCount1 <= 0 && iResult2 != nums[iIndex])
			{
				iResult1 = nums[iIndex];
				iResultCount1 = 1;
				continue;
			}
			
			if (iResultCount2 <= 0 && iResult1 != nums[iIndex])
			{
				iResult2 = nums[iIndex];
				iResultCount2 = 1;
				continue;
			}
			
			if (nums[iIndex] != iResult1 && nums[iIndex] != iResult2)
			{
				iResultCount1 --;
				iResultCount2 --;
				continue;
			}
			
			if (nums[iIndex] == iResult1)
			{
				iResultCount1 ++;
				continue;
			}
			
			if (nums[iIndex] == iResult2)
			{
				iResultCount2 ++;
				continue;
			}
		}
		
		iResultCount1 = 0;
		iResultCount2 = 0;
		
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			if (nums[iIndex] == iResult1)
			{
				iResultCount1 ++;
				continue;
			}
			
			if (nums[iIndex] == iResult2)
			{
				iResultCount2 ++;
				continue;
			}
		}
		
		vector<int> vecResult;
		
		if (iResultCount1 > nums.size() / 3)
		{
			vecResult.push_back(iResult1);
		}
		
		if (iResultCount2 > nums.size() / 3)
		{
			vecResult.push_back(iResult2);
		}
		
		return vecResult;
    }
};

/*

Bug free when submitted, but some errors when writing. Carefully Checking make me do it!

Moore Voting Algorithm. Deleting 3 different elements cannot change the property of the list.

The result array contains two elements most.

It may have better solultion, research it later.

*/
