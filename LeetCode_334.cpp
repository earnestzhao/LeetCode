class Solution
{
public:

	enum { NUM_DELETED = ~(((unsigned)(-1) << 1) >> 1) };

	bool increasingTriplet(vector<int> & nums)
	{
		if (nums.size() < 3)
		{
			return false;
		}
		
		for (int iIndex = 0, iIncInterval = 1, iIncIntervalLen = 1; iIndex < nums.size(); iIndex ++)
		{
			if (iIndex > 0)
			{
				if (iIncInterval && nums[iIndex] <= nums[iIndex - 1])
				{
					iIncInterval    = 0;
					iIncIntervalLen = 0;
				}
				
				else if (!iIncInterval && nums[iIndex] > nums[iIndex - 1])
				{
					iIncInterval    = 1;
					iIncIntervalLen = 2;
				}
				
				else if (iIncInterval && nums[iIndex] > nums[iIndex - 1])
				{
					iIncIntervalLen ++;
					
					if (iIndex - 1 > 0)
					{
						nums[iIndex - 1] = NUM_DELETED;
					}
				}
				
				else
				{
					iIncIntervalLen = 0;
					nums[iIndex - 1] = NUM_DELETED;
				}
				
				if (iIncIntervalLen >= 3)
				{
					return true;
				}
			}
		}
		
		for (int iIndex = 1, iIntervalBigger = 0, iLastIntervalBiggerIndex = -1, iLastIntervalSmallerIndex = -1; iIndex < nums.size(); iIndex ++)
		{
			if (nums[iIndex] != NUM_DELETED)
			{
				if (iLastIntervalBiggerIndex < 0)
				{
					iIntervalBigger          = (nums[iIndex] > nums[0]);
					iLastIntervalBiggerIndex = 0;
				}
				
				if (iLastIntervalSmallerIndex < 0)
				{
					iLastIntervalSmallerIndex = iIntervalBigger ? 0 : -1;
				}
				
				if (iIndex == nums.size() - 1 && !iIntervalBigger)
				{
					break;
				}
			
				if (iIntervalBigger)
				{
					if (iLastIntervalBiggerIndex > 0 && nums[iIndex] > nums[iLastIntervalBiggerIndex])
					{
						return true;
					}
					else
					{
						iLastIntervalBiggerIndex = iIndex;
					}
				}
				else
				{
					if (iLastIntervalSmallerIndex >= 0 && nums[iIndex] > nums[iLastIntervalSmallerIndex])
					{
						return true;
					}
					else
					{
						iLastIntervalSmallerIndex = iIndex;
					}
				}
				
				iIntervalBigger = !iIntervalBigger;
			}
		}
		
		return false;
    }
};
