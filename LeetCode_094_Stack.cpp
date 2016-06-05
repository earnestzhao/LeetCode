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

    vector<int> inorderTraversal(TreeNode * root)
    {
        stack<TreeNode *> stackInorder;
        stackInorder.push(root);
        
        vector<int> vecResult;
        
        while (!stackInorder.empty())
        {
            TreeNode * pstCurrent = stackInorder.top();
            stackInorder.pop();
            
            if (pstCurrent == NULL)
            {
                continue;
            }
            
            if (pstCurrent -> left == NULL && pstCurrent -> right == NULL)
            {
                vecResult.push_back(pstCurrent -> val);
            }
            else
            {
                TreeNode * pstCurrentRoot = new TreeNode(pstCurrent -> val);
                stackInorder.push(pstCurrent -> right);
                stackInorder.push(pstCurrentRoot);
                stackInorder.push(pstCurrent -> left);
            }
        }
        
        return vecResult;
    }
};
