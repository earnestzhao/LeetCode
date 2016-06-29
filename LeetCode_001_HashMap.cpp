class Solution
{
public:

    vector<int> twoSum(vector<int> & nums, int target)
    {
        vector<int> vecResult;
        
        unordered_map<int, int> hmapValueIndex;
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            unordered_map<int, int>::iterator hmapIterator = hmapValueIndex.find(target - nums[iIndex]);
            
            if (hmapIterator != hmapValueIndex.end() && iIndex != hmapIterator -> second)
            {
                vecResult.push_back(hmapIterator -> second);
                vecResult.push_back(iIndex);
                break;
            }
            else
            {
                hmapValueIndex[nums[iIndex]] = iIndex;
            }
        }
        
        return vecResult;
    }
};

/*

Using hash map, and reduce a loop of hash map initialization.

Runtime: 16ms

*/
