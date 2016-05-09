class Solution
{
public:

	bool searchMatrix(vector<vector<int>> & matrix, int target)
	{
		if (matrix.size() <= 0)
		{
			return false;
		}
		
		int iTotalRowNumber = matrix.size();
		int iTotalColNumber = matrix[0].size();
		int iTotalNumber    = iTotalRowNumber * iTotalColNumber;
		
		int iStartIndex = 0, iEndIndex = iTotalNumber - 1;
		
		while (iStartIndex <= iEndIndex)
		{
			int iMidIndex    = iStartIndex + (iEndIndex - iStartIndex) / 2;
			int iMidRowIndex = iMidIndex / iTotalColNumber;
			int iMidColIndex = iMidIndex % iTotalColNumber;
			
			if (target == matrix[iMidRowIndex][iMidColIndex])
			{
				return true;
			}
			else if (target < matrix[iMidRowIndex][iMidColIndex])
			{
				iEndIndex = iMidIndex - 1;
			}
			else
			{
				iStartIndex = iMidIndex + 1;
			}
		}
		
		return false;
    }
};

/*

The way of thinking is right. But... rowIndex = totalIndex / colNumber; colIndex = totalIndex % colNumber;

I made a mistake on which putting rolNumber instead of colNumber. It would be better if I thought it more clearly.

Binary Search. Image the matrix as an ascending list.

Twice Binary Search is the most popular way on Internet. First, do binary search on column, and then, on row.

It can save multi and divide cost. But Complexity is not reduced. logRow + logCol = log(Row Col) = O(log(Row Col))

*/
