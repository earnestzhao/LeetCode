class Solution
{
public:

	int maxArea(vector<int> & height)
	{
		vector<int> vecUpDownIndex;
		
		int iDescStartIndex = -1;
		
		for (int iIndex = 0; iIndex < height.size(); iIndex ++)
		{
			if (height[iIndex] > 0)
			{
				vecUpDownIndex.push_back(iIndex);
				
				if (iIndex > 0)
				{
					if (height[iIndex] >= height[iIndex - 1])
					{
						if (iDescStartIndex > 0)
						{
							while (vecUpDownIndex[vecUpDownIndex.size() - 1] > iDescStartIndex && height[vecUpDownIndex[vecUpDownIndex.size() - 1]] <= height[iIndex])
							{
								vecUpDownIndex.pop_back();
							}
							
							vecUpDownIndex.push_back(iIndex);
							
							if (height[iIndex] >= height[iDescStartIndex])
							{
								iDescStartIndex = -1;
							}
						}
					}
					else
					{
						if (iDescStartIndex < 0)
						{
							iDescStartIndex = iIndex - 1;
						}
					}
				}
			}
		}
		
		int iMaxHeightIndex = 0;
		
		for (int iIndex = 0; iIndex < vecUpDownIndex.size(); iIndex ++)
		{
			if (height[iMaxHeightIndex] < height[vecUpDownIndex[iIndex]])
			{
				iMaxHeightIndex = vecUpDownIndex[iIndex];
			}
		}
		
		int iMaxUpArea = 0, iMaxUpAreaIndex = 0, iMaxDownArea = 0, iMaxDownAreaIndex = 0, iCurrentArea = 0;
		
		for (int iIndex = 0; iIndex < vecUpDownIndex.size(); iIndex ++)
		{
			if (iMaxHeightIndex >= vecUpDownIndex[iIndex])
			{
				iCurrentArea = height[vecUpDownIndex[iIndex]] * (iMaxHeightIndex - vecUpDownIndex[iIndex]);
				
				if (iMaxUpArea < iCurrentArea)
				{
					iMaxUpArea = iCurrentArea;
					iMaxUpAreaIndex = vecUpDownIndex[iIndex];
				}
			}
			else
			{
				iCurrentArea = height[vecUpDownIndex[iIndex]] * (vecUpDownIndex[iIndex] - iMaxHeightIndex);
				
				if (iMaxDownArea < iCurrentArea)
				{
					iMaxDownArea = iCurrentArea;
					iMaxDownAreaIndex = vecUpDownIndex[iIndex];
				}
			}
		}
		
		int iMaxArea = iMaxUpArea > iMaxDownArea ? iMaxUpArea : iMaxDownArea;
		
		for (int iIndex = 0; iIndex < vecUpDownIndex.size(); iIndex ++)
		{
			if (vecUpDownIndex[iIndex] < iMaxHeightIndex)
			{
				iCurrentArea = (iMaxDownAreaIndex - vecUpDownIndex[iIndex]) * (height[iMaxDownAreaIndex] < height[vecUpDownIndex[iIndex]] ? height[iMaxDownAreaIndex] : height[vecUpDownIndex[iIndex]]);
				
				if (iMaxArea < iCurrentArea)
				{
					iMaxArea = iCurrentArea;
				}
			}
			
			if (vecUpDownIndex[iIndex] > iMaxHeightIndex)
			{
				iCurrentArea = (vecUpDownIndex[iIndex] - iMaxUpAreaIndex) * (height[iMaxUpAreaIndex] < height[vecUpDownIndex[iIndex]] ? height[iMaxUpAreaIndex] : height[vecUpDownIndex[iIndex]]);
				
				if (iMaxArea < iCurrentArea)
				{
					iMaxArea = iCurrentArea;
				}
			}
		}
		
		return iMaxArea;
	}
};
