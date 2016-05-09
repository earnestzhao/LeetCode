class Solution
{
public:

	int maximalSquare(vector<vector<char>> & matrix)
	{
		if (matrix.size() <= 0)
		{
			return 0;
		}
		
		if (matrix[0].size() <= 0)
		{
			return 0;
		}
		
		int iFinalResult = 0;
		
		vector<vector<int>> vecElemEndMaxSquare;
		
		for (int iIndex = 0; iIndex < matrix.size(); iIndex ++)
		{
			vecElemEndMaxSquare.push_back(vector<int>(matrix[iIndex].size(), 0));
			
			for (int jIndex = 0; jIndex < matrix[iIndex].size(); jIndex ++)
			{
				if (iIndex == 0)
				{
					vecElemEndMaxSquare[iIndex][jIndex] = (int)(matrix[iIndex][jIndex] - '0');
				}
				
				if (jIndex == 0)
				{
					vecElemEndMaxSquare[iIndex][jIndex] = (int)(matrix[iIndex][jIndex] - '0');
				}
				
				if (iIndex > 0 && jIndex > 0)
				{
					if (matrix[iIndex][jIndex] == '1')
					{
						int iCurrMinResult = vecElemEndMaxSquare[iIndex - 1][jIndex];
						
						if (iCurrMinResult > vecElemEndMaxSquare[iIndex][jIndex - 1])
						{
							iCurrMinResult = vecElemEndMaxSquare[iIndex][jIndex - 1];
						}
						
						if (iCurrMinResult > vecElemEndMaxSquare[iIndex - 1][jIndex - 1])
						{
							iCurrMinResult = vecElemEndMaxSquare[iIndex - 1][jIndex - 1];
						}
						
						vecElemEndMaxSquare[iIndex][jIndex] = iCurrMinResult + 1;
					}
					else
					{
						vecElemEndMaxSquare[iIndex][jIndex] = 0;
					}
				}
				
				if (vecElemEndMaxSquare[iIndex][jIndex] > iFinalResult)
				{
					iFinalResult = vecElemEndMaxSquare[iIndex][jIndex];
				}
			}
		}
		
		return iFinalResult * iFinalResult;
    }
};

/*

The way of thinking is right, but still not bug free.

1. Dynamic Programming Record Matrix is not initialized.

2. Min or Max logic!!!

3. Result return.


Define matrix eems[i][j] is sqrt(max square area) which the element of the right down corner is matrix[i][j]. Then,

eems[i][j] = min(eems[i-1][j], eems[i-1][j-1], eems[i][j-1]).

FinalResult = max { eem[i][j] } * max { eem[i][j] }. Time Complexity is O(n^2)

There are better solutions exist. Research it later.

*/
