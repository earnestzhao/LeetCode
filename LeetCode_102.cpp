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

    vector<vector<int>> levelOrder(TreeNode * root)
    {
        vector<vector<int>> vecResult;
        
        if (root == NULL)
        {
            return vecResult;
        }
        
        queue<TreeNode *> queueTraversal;
        queueTraversal.push(NULL);
        queueTraversal.push(root);
        
        while (queueTraversal.size() > 1)
        {
            TreeNode * pstFront = queueTraversal.front();
            queueTraversal.pop();
            
            if (pstFront == NULL)
            {
                vecResult.push_back(vector<int>());
                queueTraversal.push(NULL);
            }
            else
            {
                vecResult[vecResult.size() - 1].push_back(pstFront -> val);
                
                if (pstFront -> left != NULL)
                {
                    queueTraversal.push(pstFront -> left);
                }
                
                if (pstFront -> right != NULL)
                {
                    queueTraversal.push(pstFront -> right);
                }
            }
        }
        
        return vecResult;
    }
};

/*

Aaaaaaaaaaaaa !!! Low level bugs occured !!!

*/
