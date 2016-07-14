
class PairSmaller
{
public:

    bool operator()(const pair<int, int> & stOper1, const pair<int, int> & stOper2)
    {
        return stOper1.first + stOper1.second < stOper2.first + stOper2.second;
    }
};

typedef priority_queue<pair<int, int>, vector<pair<int, int>>, PairSmaller> PairPriorityQueue;

class Solution
{
public:

    vector<pair<int, int>> kSmallestPairs(vector<int> & nums1, vector<int> & nums2, int k)
    {
        int iListSize1 = nums1.size() < k ? nums1.size() : k;
        int iListSize2 = nums2.size() < k ? nums2.size() : k;
        
        PairSmaller       objPairSmaller;
        PairPriorityQueue priqResultContainer;
        
        for (int iIndex = 0; iIndex < iListSize1; iIndex ++)
        {
            for (int jIndex = 0; jIndex < iListSize2; jIndex ++)
            {
                pair<int, int> pairCurrent(nums1[iIndex], nums2[jIndex]);
                
                if (priqResultContainer.size() < k)
                {
                    priqResultContainer.push(pairCurrent);
                }
                else
                {
                    if (objPairSmaller(pairCurrent, priqResultContainer.top()))
                    {
                        priqResultContainer.pop();
                        priqResultContainer.push(pairCurrent);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        
        vector<pair<int, int>> vecFinalResult;
        
        for (; !priqResultContainer.empty(); priqResultContainer.pop())
        {
            vecFinalResult.push_back(priqResultContainer.top());
        }
        
        return vecFinalResult;
    }
};

/*

Using priority queue. Time complexity: O(p * q * log(k)), p = min(nums1.size(), k), q = min(nums2.size(), k)

1. Priority queue is used to keep the current result with comparing and deleting the maximum one.

2. In STL, the priority_queue is a maximum-top-heap which the comparing is a smaller one.

*/
