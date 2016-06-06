/**
 * Definition for a binary tree node.
 * struct TreeNode
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:

    TreeNode * sortedArrayToBST(vector<int> & nums)
    {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
private:

    TreeNode * sortedArrayToBST(const vector<int> & vecNumList, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex > iEndIndex)
        {
            return NULL;
        }
        
        int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
        
        TreeNode * pstRoot = new TreeNode(vecNumList[iMidIndex]);
        pstRoot -> left    = sortedArrayToBST(vecNumList, iStartIndex, iMidIndex - 1);
        pstRoot -> right   = sortedArrayToBST(vecNumList, iMidIndex + 1, iEndIndex);
        return pstRoot;
    }
};

/*

Bug free once !!! Normal recursion.

*/
