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

    vector<vector<int>> zigzagLevelOrder(TreeNode * root)
    {
        vector<vector<int>> vecResult;
        
        if (root == NULL)
        {
            return vecResult;
        }
        
        queue<TreeNode *> queueTravesal;
        queueTravesal.push(root);
        queueTravesal.push(NULL);
        
        vector<int> vecSubResult;
        bool bFromLeftToRight = true;
        
        while (!queueTravesal.empty())
        {
            TreeNode * pstCurrent = queueTravesal.front();
            queueTravesal.pop();
            
            if (pstCurrent == NULL)
            {
                if (!bFromLeftToRight)
                {
                    reverse(vecSubResult.begin(), vecSubResult.end());
                }
                
                bFromLeftToRight = !bFromLeftToRight;
                vecResult.push_back(vecSubResult);
                vecSubResult.clear();
                
                if (!queueTravesal.empty())
                {
                    queueTravesal.push(NULL);
                }
            }
            else
            {
                TreeNode * pstSubNodeLeft  = pstCurrent -> left;
                TreeNode * pstSubNodeRight = pstCurrent -> right;
                vecSubResult.push_back(pstCurrent -> val);
                
                if (pstSubNodeLeft != NULL)
                {
                    queueTravesal.push(pstSubNodeLeft);
                }
                
                if (pstSubNodeRight != NULL)
                {
                    queueTravesal.push(pstSubNodeRight);
                }
            }
        }
        
        return vecResult;
    }
};

/*

Thinking is right, a small bug...

Normal algorithm.

Using a flag for recording reverse or not, and reverse it when it need to reverse.

*/
