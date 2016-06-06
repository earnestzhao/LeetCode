/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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

    TreeNode * sortedListToBST(ListNode * head)
    {
        vector<int> vecSortedList;
        
        for (ListNode * pstCurrent = head; pstCurrent != NULL; pstCurrent = pstCurrent -> next)
        {
            vecSortedList.push_back(pstCurrent -> val);
        }
        
        return sortedArrayToBST(vecSortedList, 0, vecSortedList.size() - 1);
    }
    
private:

    TreeNode * sortedArrayToBST(const vector<int> & vecSortedList, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex > iEndIndex)
        {
            return NULL;
        }
        
        int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
        
        TreeNode * pstRoot = new TreeNode(vecSortedList[iMidIndex]);
        pstRoot -> left    = sortedArrayToBST(vecSortedList, iStartIndex, iMidIndex - 1);
        pstRoot -> right   = sortedArrayToBST(vecSortedList, iMidIndex + 1, iEndIndex);
        return pstRoot;
    }
};

/*

Convert to 'sortedArrayToBST'. Foolish algorithm.

*/
