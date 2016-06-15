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
        stack<int>  stackResult;
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
            
            stackResult.push(pstCurrNode -> val);
        }
        
        for (; !stackResult.empty(); stackResult.pop())
        {
            vecResult.push_back(stackResult.top());
        }
        
        return vecResult;
    }
};

/*

The same thinking as LeetCode_145_Rev.cpp, but using a stack to store result and naturally reverse.

*/
