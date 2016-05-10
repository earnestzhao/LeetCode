class Solution
{
public:

    vector<int> findOrder(int numCourses, vector<pair<int, int>> & prerequisites)
    {
        unordered_set<int>              hsetZeroDegree;
        unordered_map<int, int>         hmapInDegree;
        unordered_map<int, vector<int>> hmapGraph;
        
        for (int iIndex = 0; iIndex < prerequisites.size(); iIndex ++)
        {
            unordered_map<int, vector<int>>::iterator hmapIterator = hmapGraph.find(prerequisites[iIndex].second);
            
            if (hmapIterator != hmapGraph.end())
            {
                hmapIterator -> second.push_back(prerequisites[iIndex].first);
            }
            else
            {
                hmapGraph[prerequisites[iIndex].second] = vector<int>(1, prerequisites[iIndex].first);
            }
            
            if (hmapInDegree.find(prerequisites[iIndex].second) == hmapInDegree.end())
            {
                hmapInDegree[prerequisites[iIndex].second] = 0;
                hsetZeroDegree.insert(prerequisites[iIndex].second);
            }
            
            if (hmapInDegree.find(prerequisites[iIndex].first) != hmapInDegree.end())
            {
                hmapInDegree[prerequisites[iIndex].first] ++;
            }
            else
            {
                hmapInDegree[prerequisites[iIndex].first] = 1;
            }
            
            hsetZeroDegree.erase(prerequisites[iIndex].first);
        }
        
        vector<int>        vecFinalResult;
        unordered_set<int> hsetPartResult;
        
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
                    hsetPartResult.insert(*hsetIterator);
                    vecFinalResult.push_back(*hsetIterator);
                }
            }
            
            hsetZeroDegree.swap(hsetNewZeroDegree);
        }
        
        if (hmapGraph.size() > 0)
        {
            return vector<int>();
        }
        
        for (int iIndex = 0; iIndex < numCourses; iIndex ++)
        {
            if (hsetPartResult.find(iIndex) == hsetPartResult.end())
            {
                vecFinalResult.push_back(iIndex);
            }
        }
        
        return vecFinalResult;
    }
};

/*

The same method as LeetCode.207.

But not bug free... A variety using error in initialize loop.

*/
