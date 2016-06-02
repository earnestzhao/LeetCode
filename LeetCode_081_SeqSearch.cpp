class Solution
{
public:

    bool search(vector<int> & nums, int target)
    {
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            if (nums[iIndex] == target)
            {
                return true;
            }
        }
        
        return false;
    }
};

/*

A stupid algorithm!!! After searching, I may draw this conclusion...

First, we cannot determin the minimum element in O(logn) time complexity. If each element is different, we can do it.

If the middle index is equal to the start index, and no smaller than the end index, the binary search is useless. We must do recusing on both sides.

T(n) = 2T(n/2) + c = O(n). Because the worst condition is O(n), we have no necessary to find an algorithm such as binary search, which increasing complex.

Complex algorithm can reduce average complexity, but a complex method may make runtime high. So, I think the sequence searching is the best choice.

The best time complexity is still O(logn), which occured on all elements are different.

*/
