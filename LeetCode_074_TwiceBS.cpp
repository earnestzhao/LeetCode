class Solution
{
public:

	bool searchMatrix(vector<vector<int>> & matrix, int target)
	{
		if (matrix.size() <= 0)
		{
			return false;
		}
		
		if (matrix[0].size() <= 0)
		{
			return false;
		}
		
		int iStartIndex = 0;
		int iEndIndex   = matrix.size() - 1;
		
		while (iStartIndex <= iEndIndex)
		{
			int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
			
			if (target == matrix[iMidIndex][0])
			{
				return true;
			}
			
			if (target < matrix[iMidIndex][0])
			{
				iEndIndex = iMidIndex - 1;
			}
			
			if (target > matrix[iMidIndex][0])
			{
				iStartIndex = iMidIndex + 1;
			}
		}
		
		if (iStartIndex <= 0)
		{
			return false;
		}
		
		int iDstLineIndex = iStartIndex - 1;
		iStartIndex       = 0;
		iEndIndex         = matrix[iDstLineIndex].size() - 1;
		
		while (iStartIndex <= iEndIndex)
		{
			int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
			
			if (target == matrix[iDstLineIndex][iMidIndex])
			{
				return true;
			}
			
			if (target < matrix[iDstLineIndex][iMidIndex])
			{
				iEndIndex = iMidIndex - 1;
			}
			
			if (target > matrix[iDstLineIndex][iMidIndex])
			{
				iStartIndex = iMidIndex + 1;
			}
		}
		
		return false;
    }
};

/*

This program implements it by binary search twice to test the runtime.

Not bug free, the result of the first binary search need edge condition judging before starting the second binary search.

Test Result: The same runtime. It may have better solution.

*/
