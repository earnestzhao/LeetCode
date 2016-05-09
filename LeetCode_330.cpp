class Solution
{
public:

	int minPatches(vector<int> & nums, int n)
	{
		int iMinPatchesResult = 0;
		
		for (int iIndex = 0, iCurrCoverNum = 1; iCurrCoverNum > 0 && iCurrCoverNum <= n; )
		{
			if (iIndex < nums.size() && nums[iIndex] <= iCurrCoverNum)
			{
				iCurrCoverNum += nums[iIndex]; iIndex ++;
			}
			else
			{
				iCurrCoverNum <<= 1; iMinPatchesResult ++;
			}
		}
		
		return iMinPatchesResult;
    }
};
