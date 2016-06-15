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

    vector<int> preorderTraversal(TreeNode * root)
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
            
            if (pstCurrNode -> right != NULL)
            {
                stackTraversal.push(pstCurrNode -> right);
            }
            
            if (pstCurrNode -> left != NULL)
            {
                stackTraversal.push(pstCurrNode -> left);
            }
            
            vecResult.push_back(pstCurrNode -> val);
        }
        
        return vecResult;
    }
};
