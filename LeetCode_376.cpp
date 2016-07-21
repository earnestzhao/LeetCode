class Solution
{
public:

    int wiggleMaxLength(vector<int> & nums)
    {
        if (nums.size() <= 0)
        {
            return 0;
        }
        
        int iWiggleMaxLengthG1 = 1;
        int iWiggleMaxLengthS1 = 1;
        
        for (int iIndex = 1, iGreater = 1; iIndex < nums.size(); iIndex ++)
        {
            if (iGreater)
            {
                if (nums[iIndex] > nums[iIndex - 1])
                {
                    iWiggleMaxLengthG1 ++;
                    iGreater = !iGreater;
                }
            }
            else
            {
                if (nums[iIndex] < nums[iIndex - 1])
                {
                    iWiggleMaxLengthG1 ++;
                    iGreater = !iGreater;
                }
            }
        }
        
        for (int iIndex = 1, iGreater = 0; iIndex < nums.size(); iIndex ++)
        {
            if (iGreater)
            {
                if (nums[iIndex] > nums[iIndex - 1])
                {
                    iWiggleMaxLengthS1 ++;
                    iGreater = !iGreater;
                }
            }
            else
            {
                if (nums[iIndex] < nums[iIndex - 1])
                {
                    iWiggleMaxLengthS1 ++;
                    iGreater = !iGreater;
                }
            }
        }
        
        return iWiggleMaxLengthG1 > iWiggleMaxLengthS1 ? iWiggleMaxLengthG1 : iWiggleMaxLengthS1;
    }
};

/*

Thinking is right. After 3 times correction and optimization, it is accepted in O(n) time complexity.

Dynamic Programming. Define vecResult[i] as the result of which 'i' is the last index. Then, the recursive relation is as follow:

vecResult[i] = min (lastIndex[j] WIGGLE nums[i]) { vecResult[j] } + 1. If it is implemented as this, the time complex is O(n^2).

--------------------------------------------------

Optimization 1:

vecResult[i] is a non-decreasing function. So we need to compare nums[i] with the maximum element before if nums[i] would be smaller, and compare nums[i] with the minimum element before if nums[i] would be greater.

Keep a variable which is the minimum or maximum when wiggle maximum length changes. Keep a minimum element before a greater element appears, and a maximum element before a smaller one appears.

--------------------------------------------------

Optimization 2:

Do not keep the variable, if nums[i] is greater than nums[i-1] and we would find a greater one, then, the wiggle maxinum length changes. We can use the nums[i] as the maximum element till now on the condition of new wiggle maxinum length. Otherwise, we can use the nums[i] as the new minimum element on the condition of current wiggle maxinum length.

--------------------------------------------------

The last question:

There are 2 conditions that the nums[0] > nums[1] and nums[0] < nums[1]. So we run the procedure above twice. One for nums[0] > nums[1], and the other for nums[0] < nums[1]. Finally, we return the maximum one of them.

*/
