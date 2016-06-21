class Solution
{
public:

    vector<int> topKFrequent(vector<int> & nums, int k)
    {
        unordered_map<int, int> hmapElemFreq;
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            unordered_map<int, int>::iterator hmapIterator = hmapElemFreq.find(nums[iIndex]);
            
            if (hmapIterator != hmapElemFreq.end())
            {
                hmapIterator -> second ++;
            }
            else
            {
                hmapElemFreq[nums[iIndex]] = 1;
            }
        }
        
        vector<vector<int>> vecFreqElem(nums.size(), vector<int>());
        
        for (unordered_map<int, int>::iterator hmapIterator = hmapElemFreq.begin(); hmapIterator != hmapElemFreq.end(); hmapIterator ++)
        {
            vecFreqElem[hmapIterator -> second - 1].push_back(hmapIterator -> first);
        }
        
        vector<int> vecFinalResult;
        
        for (int iIndex = vecFreqElem.size() - 1; iIndex >= 0; iIndex --)
        {
            for (int jIndex = 0; jIndex < vecFreqElem[iIndex].size(); jIndex ++)
            {
                vecFinalResult.push_back(vecFreqElem[iIndex][jIndex]);
                
                if (vecFinalResult.size() >= k)
                {
                    return vecFinalResult;
                }
            }
        }
        
        return vecFinalResult;
    }
};

/*

Bug free once !!!

Using hash table to count frequent, and sort by frequent.

Time complexity: O(n)

Space complexity: O(n)

*/
