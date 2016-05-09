class Solution
{
public:

    int findDuplicate(vector<int> & nums)
	{
		int iRangeStart = 1;
		int iRangeEnd   = nums.size() - 1;
	
		while (true)
		{
			FDSCheckResult enCheckResult;
			
			int iNumCheck = iRangeStart + (iRangeEnd - iRangeStart) / 2;
		
			if (findDuplicateSub(nums, iRangeStart, iRangeEnd, iNumCheck, enCheckResult))
			{
				return iNumCheck;
			}
			
			if (enCheckResult == NCR_REPEAT_LESS)
			{
				iRangeEnd = iNumCheck - 1;
			}
			
			if (enCheckResult == NCR_REPEAT_MORE)
			{
				iRangeStart = iNumCheck + 1;
			}
		}
    }
	
private:

	enum FDSCheckResult { NCR_REPEAT_THIS, NCR_REPEAT_LESS, NCR_REPEAT_MORE };

	bool findDuplicateSub(vector<int> & nums, unsigned numRangeStart, unsigned numRangeEnd, int numCheck, FDSCheckResult & checkResult)
	{
		int iExpectLess = numCheck - numRangeStart;
		int iExpectMore = numRangeEnd - numCheck;
		int iExpectThis = 1;
		
		int iRealLess = 0;
		int iRealMore = 0;
		int iRealThis = 0;
	
		for (unsigned uiIndex = 0; uiIndex < nums.size(); uiIndex ++)
		{
			if (nums[uiIndex] >= numRangeStart && nums[uiIndex] <= numRangeEnd)
			{
				if (numCheck == nums[uiIndex])
				{
					iRealThis ++;
				}
				else if (numCheck < nums[uiIndex])
				{
					iRealMore ++;
				}
				else
				{
					iRealLess ++;
				}
			}
		}
		
		if (iRealThis > iExpectThis)
		{
			checkResult = NCR_REPEAT_THIS;
			return true;
		}
		
		if (iRealLess > iExpectLess)
		{
			checkResult = NCR_REPEAT_LESS;
			return false;
		}
		
		if (iRealMore > iExpectMore)
		{
			checkResult = NCR_REPEAT_MORE;
			return false;
		}
	}
};
