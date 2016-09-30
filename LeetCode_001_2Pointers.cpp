
struct NumIndex
{
    NumIndex(int iNumber, int iIndex) : number(iNumber), index(iIndex)
    {
        
    }
    
    int number, index;
};

bool NumIndexLess(NumIndex & stOper1, NumIndex & stOper2)
{
    return stOper1.number < stOper2.number;
}

class Solution
{
public:

    vector<int> twoSum(vector<int> & nums, int target)
    {
        vector<NumIndex> vecNumIndexList;
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            vecNumIndexList.push_back(NumIndex(nums[iIndex], iIndex));
        }
        
        sort(vecNumIndexList.begin(), vecNumIndexList.end(), NumIndexLess);
        
        vector<int> vecResult;
        
        for (int iLeftIndex = 0, iRightIndex = vecNumIndexList.size() - 1; ;)
        {
            if (vecNumIndexList[iLeftIndex].number + vecNumIndexList[iRightIndex].number == target)
            {
                vecResult.push_back(vecNumIndexList[iLeftIndex].index);
                vecResult.push_back(vecNumIndexList[iRightIndex].index);
                break;
            }
            
            if (vecNumIndexList[iLeftIndex].number + vecNumIndexList[iRightIndex].number < target)
            {
                iLeftIndex ++;
            }
            else
            {
                iRightIndex --;
            }
        }
        
        return vecResult;
    }
};

/*

Two Pointers.

Runtime: 9ms

*/
