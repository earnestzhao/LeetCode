class Solution
{
public:

    int numIslands(vector<vector<char>> & grid)
    {
        if (grid.size() <= 0 || grid[0].size() <= 0)
        {
            return 0;
        }
        
        vector<int> vecUnionSet(grid.size() * grid[0].size(), -1);
        
        for (int iRowIndex = 0; iRowIndex < grid.size(); iRowIndex ++)
        {
            for (int iColIndex = 0; iColIndex < grid[iRowIndex].size(); iColIndex ++)
            {
                int iPointId = iRowIndex * grid[iRowIndex].size() + iColIndex;
                
                if (grid[iRowIndex][iColIndex] == '0')
                {
                    vecUnionSet[iPointId] = INT_MIN;
                }
                else
                {
                    if (iRowIndex > 0 && grid[iRowIndex - 1][iColIndex] == '1')
                    {
                        setParent(vecUnionSet, iPointId, iPointId - grid[iRowIndex].size());
                    }
                    
                    if (iColIndex > 0 && grid[iRowIndex][iColIndex - 1] == '1')
                    {
                        setParent(vecUnionSet, iPointId, iPointId - 1);
                    }
                }
            }
        }
        
        int iNumberIslands = 0;
        
        for (int iIndex = 0; iIndex < vecUnionSet.size(); iIndex ++)
        {
            if (vecUnionSet[iIndex] == -1)
            {
                iNumberIslands ++;
            }
        }
        
        return iNumberIslands;
    }
    
private:

    int getParent(vector<int> & vecParent, int iPointId)
    {
        if (vecParent[iPointId] == -1)
        {
            return iPointId;
        }
        
        vecParent[iPointId] = getParent(vecParent, vecParent[iPointId]);
        return vecParent[iPointId];
    }
    
    void setParent(vector<int> & vecParent, int iPointId, int iParentPointId)
    {
        int iSrcParent = getParent(vecParent, iPointId);
        int iDstParent = getParent(vecParent, iParentPointId);
        
        if (iSrcParent != iDstParent)
        {
            vecParent[iSrcParent] = iDstParent;
        }
    }
};

/*

Thinking is right, but bugs, bugs, bugs ...

Union Find Set. It is so good that I remember the union find set by myself ...

*/
