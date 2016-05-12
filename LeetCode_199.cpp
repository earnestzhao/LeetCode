/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:

    vector<int> rightSideView(TreeNode * root)
    {
        queue<TreeNode *> queueTranversal;
        queueTranversal.push(root);
        queueTranversal.push(NULL);
        
        vector<int> vecResult;
        
        for (TreeNode * pstCurrent = NULL, * pstPrevious = NULL; !queueTranversal.empty(); pstPrevious = pstCurrent)
        {
            pstCurrent = queueTranversal.front(); queueTranversal.pop();
            
            if (pstCurrent == NULL)
            {
                if (pstPrevious != NULL)
                {
                    vecResult.push_back(pstPrevious -> val);
                }
                else
                {
                    break;
                }
                
                queueTranversal.push(NULL);
            }
            else
            {
                if (pstCurrent -> left != NULL)
                {
                    queueTranversal.push(pstCurrent -> left);
                }
                
                if (pstCurrent -> right != NULL)
                {
                    queueTranversal.push(pstCurrent -> right);
                }
            }
        }
        
        return vecResult;
    }
};

/*

Thinking is right, but not bug free... Edge Condition!!!

Do breadth-first search (BFS) on the tree, collect the last node value of each layer.

*/
