class Solution
{
public:

    int trap(vector<int> & height)
    {
        int iMaxHeight = INT_MIN, iMaxHeightIndex = 0;
        
        for (int iIndex = 0; iIndex < height.size(); iIndex ++)
        {
            if (iMaxHeight < height[iIndex])
            {
                iMaxHeight      = height[iIndex];
                iMaxHeightIndex = iIndex;
            }
        }
        
        int iTrapResult = 0;
        
        for (int iIndex = 0, iWaterHeight = 0; iIndex < iMaxHeightIndex; iIndex ++)
        {
            if (height[iIndex] > iWaterHeight)
            {
                iWaterHeight = height[iIndex];
            }
            else
            {
                iTrapResult += iWaterHeight - height[iIndex];
            }
        }
        
        for (int iIndex = height.size() - 1, iWaterHeight = 0; iIndex > iMaxHeightIndex; iIndex --)
        {
            if (height[iIndex] > iWaterHeight)
            {
                iWaterHeight = height[iIndex];
            }
            else
            {
                iTrapResult += iWaterHeight - height[iIndex];
            }
        }
        
        return iTrapResult;
    }
};

/*

Two pointers. Smart !!!

Find the bigger height, then, traversal the height list from right and left to the bigger height index.

The water position is always growing when traversal.

*/
