class Solution
{
public:

	int numSquares(int n)
	{
		vector<int> vecSquareNumber;
		
		for (int iSquareIndex = 1; iSquareIndex * iSquareIndex <= n; iSquareIndex ++)
		{
			vecSquareNumber.push_back(iSquareIndex * iSquareIndex);
		}
		
		vector<int> vecSquarePlusLength;
		vecSquarePlusLength.push_back(0);
		
		for (int iCheckNumber = 1; iCheckNumber <= n; iCheckNumber ++)
		{
			int iCurrentMinSquarePlusLength = iCheckNumber;
		
			for (int jIndex = 0; jIndex < vecSquareNumber.size() && iCheckNumber >= vecSquareNumber[jIndex]; jIndex ++)
			{
				if (vecSquarePlusLength[iCheckNumber - vecSquareNumber[jIndex]] + 1 < iCurrentMinSquarePlusLength)
				{
					iCurrentMinSquarePlusLength = vecSquarePlusLength[iCheckNumber - vecSquareNumber[jIndex]] + 1;
				}
			}
			
			vecSquarePlusLength.push_back(iCurrentMinSquarePlusLength);
		}
		
		return vecSquarePlusLength[n];
    }
};
