class Solution
{
public:

	int findKthLargest(vector<int> & nums, int k)
	{
		srand(time(NULL));
		return findKthLargest(nums, k, 0, nums.size() - 1);
	}
	
private:

	int findKthLargest(vector<int> & vecNumList, int iKthIndex, int iStartIndex, int iEndIndex)
	{
		if (iStartIndex == iEndIndex)
		{
			return vecNumList[iStartIndex];
		}
		
		int iSize       = iEndIndex - iStartIndex + 1;
		int iDivIndex   = iStartIndex + rand() % iSize;
		int iCurrentVal = vecNumList[iDivIndex];
		
		int iFromEndDesc = 1;
		int iIndex = iStartIndex, jIndex = iEndIndex;
		vecNumList[iDivIndex] = vecNumList[iStartIndex];
		
		while (iIndex != jIndex)
		{
			if (iFromEndDesc)
			{
				if (vecNumList[jIndex] < iCurrentVal)
				{
					vecNumList[iIndex] = vecNumList[jIndex];
					iFromEndDesc = !iFromEndDesc;
					iIndex ++;
				}
				else
				{
					jIndex --;
				}
			}
			else
			{
				if (vecNumList[iIndex] > iCurrentVal)
				{
					vecNumList[jIndex] = vecNumList[iIndex];
					iFromEndDesc = !iFromEndDesc;
					jIndex --;
				}
				else
				{
					iIndex ++;
				}
			}
		}
		
		vecNumList[iIndex] = iCurrentVal;
		
		if (iIndex == iEndIndex - iKthIndex + 1)
		{
			return vecNumList[iIndex];
		}
		else if (iIndex < iEndIndex - iKthIndex + 1)
		{
			return findKthLargest(vecNumList, iKthIndex, iIndex + 1, iEndIndex);
		}
		else
		{
			return findKthLargest(vecNumList, iKthIndex - iSize + iIndex - iStartIndex, iStartIndex, iIndex - 1);
		}
	}
};

/*

Thinking is right, but bugs everywhere!

Introduction of Algorithm. Chapter 4. This is a random algorithm. Average Time Complexity is O(n).

There is another algorithm which worst time complexity is O(n), implement it tomorrow.

*/
