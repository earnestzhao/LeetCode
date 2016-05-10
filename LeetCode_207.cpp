class Solution
{
public:

    bool canFinish(int numCourses, vector<pair<int, int>> & prerequisites)
    {
        unordered_set<int>              hsetZeroDegree;
        unordered_map<int, int>         hmapInDegree;
        unordered_map<int, vector<int>> hmapGraph;
        
        for (int iIndex = 0; iIndex < prerequisites.size(); iIndex ++)
        {
            unordered_map<int, vector<int>>::iterator hmapIterator = hmapGraph.find(prerequisites[iIndex].first);
            
            if (hmapIterator != hmapGraph.end())
            {
                hmapIterator -> second.push_back(prerequisites[iIndex].second);
            }
            else
            {
                hmapGraph[prerequisites[iIndex].first] = vector<int>(1, prerequisites[iIndex].second);
            }
            
            if (hmapInDegree.find(prerequisites[iIndex].first) == hmapInDegree.end())
            {
                hmapInDegree[prerequisites[iIndex].first] = 0;
                hsetZeroDegree.insert(prerequisites[iIndex].first);
            }
            
            if (hmapInDegree.find(prerequisites[iIndex].second) != hmapInDegree.end())
            {
                hmapInDegree[prerequisites[iIndex].second] ++;
                hsetZeroDegree.erase(prerequisites[iIndex].second);
            }
            else
            {
                hmapInDegree[prerequisites[iIndex].second] = 1;
                hsetZeroDegree.erase(prerequisites[iIndex].second);
            }
        }
        
        while (hsetZeroDegree.size() > 0)
        {
            unordered_set<int> hsetNewZeroDegree;
            
            for (unordered_set<int>::iterator hsetIterator = hsetZeroDegree.begin(); hsetIterator != hsetZeroDegree.end(); hsetIterator ++)
            {
                unordered_map<int, vector<int>>::iterator hmapIterator = hmapGraph.find(*hsetIterator);
                
                if (hmapIterator != hmapGraph.end())
                {
                    for (int iIndex = 0; iIndex < hmapIterator -> second.size(); iIndex ++)
                    {
                        hmapInDegree[hmapIterator -> second[iIndex]] --;
                        
                        if (hmapInDegree[hmapIterator -> second[iIndex]] <= 0)
                        {
                            hsetNewZeroDegree.insert(hmapIterator -> second[iIndex]);
                        }
                    }
                    
                    hmapGraph.erase(*hsetIterator);
                }
            }
            
            hsetZeroDegree.swap(hsetNewZeroDegree);
        }
        
        return hmapGraph.size() <= 0;
    }
};

/*

Perfect! Bug free! Runtime beat 100% Submitions.

The fact of the algorithm is finding loop in a graph.

Delete zero-in-degree point in the graph until there is no zero-in-degree point exist.

If the graph is still not empty, the loop exists, then return false.

*/
