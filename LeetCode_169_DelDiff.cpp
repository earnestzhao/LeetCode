class Solution
{
public:

    int majorityElement(vector<int> & nums)
	{
		int iCurrElem  = 0;
		int iCurrCount = 0;
		
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			if (iCurrCount <= 0)
			{
				iCurrElem  = nums[iIndex];
				iCurrCount = 1;
			}
			else
			{
				if (iCurrElem == nums[iIndex])
				{
					iCurrCount ++;
				}
				else
				{
					iCurrCount --;
				}
			}
		}
		
		return iCurrElem;
    }
};

/*

Morre voting algorithm. I have known that deleting different 2 elements until it doesn't have this kind of pair, the left element is the result.

But the implementation which I have thinked is foolish. Morre voting algorithm is funny, fantanstic, wonderful and excellent!

iCurrElem & iCurrCount. If iCurrCount <= 0, then, assign nums[i] to iCurrElem.

If iCurrCount >= 0, and the current nums[i] is equal to iCurrElem, then, iCurrCount ++.

If iCurrCount >= 0, and the current nums[i] is unequal to iCurrElem, then, iCurrCount --.

Loop to the end, the iCurrElem is the result.

*/
