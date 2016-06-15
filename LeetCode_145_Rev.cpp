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

    vector<int> postorderTraversal(TreeNode * root)
    {
        vector<int> vecResult;
        
        if (root == NULL)
        {
            return vecResult;
        }
        
        stack<TreeNode *> stackTraversal;
        stackTraversal.push(root);
        
        while (!stackTraversal.empty())
        {
            TreeNode * pstCurrNode = stackTraversal.top();
            stackTraversal.pop();
            
            if (pstCurrNode -> left != NULL)
            {
                stackTraversal.push(pstCurrNode -> left);
            }
            
            if (pstCurrNode -> right != NULL)
            {
                stackTraversal.push(pstCurrNode -> right);
            }
            
            vecResult.push_back(pstCurrNode -> val);
        }
        
        reverse(vecResult.begin(), vecResult.end());
        return vecResult;
    }
};

/*

Bug free once !!!

Change sequence (Left,Right,Root) to (Root,Right,Left), then, reverse the result.

*/
