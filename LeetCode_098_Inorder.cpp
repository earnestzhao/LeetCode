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

    bool isValidBST(TreeNode * root)
    {
        vector<int> vecInorderList;
        
        inOrder(root, vecInorderList);
        
        for (int iIndex = 1; iIndex < vecInorderList.size(); iIndex ++)
        {
            if (vecInorderList[iIndex] <= vecInorderList[iIndex - 1])
            {
                return false;
            }
        }
        
        return true;
    }
    
private:

    void inOrder(TreeNode * pstRoot, vector<int> & vecResult)
    {
        if (pstRoot == NULL)
        {
            return;
        }
        
        inOrder(pstRoot -> left, vecResult);
        
        vecResult.push_back(pstRoot -> val);
        
        inOrder(pstRoot -> right, vecResult);
    }
};

/*

A binary tree is a binary search tree whether its inorder list is sorted.

Generate its inorder list, and judge it is sorted or not.

Time complexity: n + n = 2n = O(n)

*/
