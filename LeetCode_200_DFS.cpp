class Solution
{
public:

    int numIslands(vector<vector<char>> & grid)
    {
        unordered_set<int> hsetPoint;
        unordered_map<int, vector<int>> hmapGraph;
        
        for (int iIndex = 0; iIndex < grid.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < grid[iIndex].size(); jIndex ++)
            {
                if (grid[iIndex][jIndex] == '1')
                {
                    int iCurrPointId  = (iIndex - 0) * grid.size() + jIndex - 0;
                    int iToUpPrevId   = (iIndex - 1) * grid.size() + jIndex - 0;
                    int iToLeftPrevId = (iIndex - 0) * grid.size() + jIndex - 1;
                    
                    hsetPoint.insert(iCurrPointId);
                    
                    if (iIndex > 0 && grid[iIndex - 1][jIndex] == '1')
                    {
                        if (hmapGraph.find(iCurrPointId) != hmapGraph.end())
                        {
                            hmapGraph[iCurrPointId].push_back(iToUpPrevId);
                        }
                        else
                        {
                            hmapGraph[iCurrPointId] = vector<int>(1, iToUpPrevId);
                        }
                        
                        if (hmapGraph.find(iToUpPrevId) != hmapGraph.end())
                        {
                            hmapGraph[iToUpPrevId].push_back(iCurrPointId);
                        }
                        else
                        {
                            hmapGraph[iToUpPrevId] = vector<int>(1, iCurrPointId);
                        }
                    }
                    
                    if (jIndex > 0 && grid[iIndex][jIndex - 1] == '1')
                    {
                        if (hmapGraph.find(iCurrPointId) != hmapGraph.end())
                        {
                            hmapGraph[iCurrPointId].push_back(iToLeftPrevId);
                        }
                        else
                        {
                            hmapGraph[iCurrPointId] = vector<int>(1, iToLeftPrevId);
                        }
                        
                        if (hmapGraph.find(iToLeftPrevId) != hmapGraph.end())
                        {
                            hmapGraph[iToLeftPrevId].push_back(iCurrPointId);
                        }
                        else
                        {
                            hmapGraph[iToLeftPrevId] = vector<int>(1, iCurrPointId);
                        }
                    }
                }
            }
        }
        
        int iFinalResult = 0;
        
        unordered_set<int> hsetAccessed;
        
        while (hsetPoint.size() > 0)
        {
            int iCurrentPointId = *(hsetPoint.begin());
            
            graphTravesal(hmapGraph, iCurrentPointId, hsetAccessed, hsetPoint);
            
            iFinalResult ++;
        }
        
        return iFinalResult;
    }
    
private:

    void graphTravesal(unordered_map<int, vector<int>> & hmapGraph, int iCurrentPointId, unordered_set<int> & hsetAccessed, unordered_set<int> & hsetPoint)
    {
        unordered_map<int, vector<int>>::iterator hmapIterator = hmapGraph.find(iCurrentPointId);
        
        hsetPoint.erase(iCurrentPointId);
        
        hsetAccessed.insert(iCurrentPointId);
        
        if (hmapIterator != hmapGraph.end())
        {
            for (int iIndex = 0; iIndex < hmapIterator -> second.size(); iIndex ++)
            {
                if (hsetAccessed.find(hmapIterator -> second[iIndex]) == hsetAccessed.end())
                {
                    graphTravesal(hmapGraph, hmapIterator -> second[iIndex], hsetAccessed, hsetPoint);
                }
            }
        }
    }
};

/*

Build a graph and calculate the number of connection braches of the graph by DFS. Not bug free... An error of accessed set control...

The runtime of the algorithm only beat 1.47% submissions. Optiminized algorithm must exist, research it later.

*/
