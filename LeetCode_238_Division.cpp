class Solution
{
public:

    vector<int> productExceptSelf(vector<int> & nums)
    {
        long long llTotalMulValue = 1;
        
        int iZeroCount = 0, iZeroIndex = -1;
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            if (nums[iIndex] == 0)
            {
                iZeroCount ++;
                iZeroIndex = iIndex;
            }
            else
            {
                llTotalMulValue *= nums[iIndex];
            }
        }
        
        vector<int> vecResultList(nums.size(), 0);
        
        if (iZeroCount > 1)
        {
            return vecResultList;
        }
        
        if (iZeroCount == 1)
        {
            vecResultList[iZeroIndex] = (int)(llTotalMulValue);
        }
        else
        {
            for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
            {
                vecResultList[iIndex] = (int)(llTotalMulValue / nums[iIndex]);
            }
        }
    }
};

/*

Excellent! I do it. Bug Free! Both logic and compling, bug free!

The way of thinking is easy. Multi all elements, and divide each element.

Zero Condition: 2 or more zero elements, return all zero list;

1 zero element, returns all zero elements except the zero element position which result is the multi value.

*/
