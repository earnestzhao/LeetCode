class Solution
{
public:
    
    int minSubArrayLen(int s, vector<int> & nums)
    {
        if (nums.size() <= 0)
        {
            return 0;
        }
        
        int iStartIndex = 0;
        int iEndIndex   = 0;
        
        int iCurrentSum = 0;
        int iResultLen  = INT_MAX;
        
        while (iStartIndex < nums.size() && iEndIndex < nums.size())
        {
            while (iCurrentSum < s && iEndIndex < nums.size())
            {
                iCurrentSum += nums[iEndIndex ++];
            }
            
            while (iCurrentSum >= s && iStartIndex < iEndIndex)
            {
                if (iEndIndex - iStartIndex < iResultLen)
                {
                    iResultLen = iEndIndex - iStartIndex;
                }
                
                iCurrentSum -= nums[iStartIndex ++];
            }
        }
        
        return iResultLen == INT_MAX ? 0 : iResultLen;
    }
};

/*

The first thinking 'Divide and Conquer' is wrong...

Two pointers.

1. Initialize iStartIndex and iEndIndex to 0.

2. Loop on iStartIndex and iEndIndex from index 0 to n-1...

    2.1 Loop on iEndIndex to right, calculate the sum = sigma(iStartIndex <= i <= iEndIndex) { nums[i] } until sum is no smaller than s.

    2.2 Loop on iStartIndex to right, calculate the sum' = sum - nums[iStartIndex], until sum's is smaller than s. Update the minimum final result in this process.
    
3. Return the final minimum result.

The algorithm is so smart. I love it!!! Time complex: O(n)

*/
