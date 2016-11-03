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

    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
    {
        unordered_map<TreeNode *, TreeNode *> hmapNodeParent;
        hmapNodeParent[root] = NULL;
        
        unordered_map<TreeNode *, int> hmapNodeLevel;
        hmapNodeLevel[root] = 0;
        
        queue<TreeNode *> queueTraversal;
        queueTraversal.push(root);
        
        while (!queueTraversal.empty())
        {
            TreeNode * pstCurrent = queueTraversal.front();
            queueTraversal.pop();
            
            if (pstCurrent != NULL)
            {
                if (pstCurrent -> left != NULL)
                {
                    hmapNodeParent[pstCurrent -> left] = pstCurrent;
                    hmapNodeLevel[pstCurrent -> left]  = hmapNodeLevel[pstCurrent] + 1;
                    queueTraversal.push(pstCurrent -> left);
                }
                
                if (pstCurrent -> right != NULL)
                {
                    hmapNodeParent[pstCurrent -> right] = pstCurrent;
                    hmapNodeLevel[pstCurrent -> right]  = hmapNodeLevel[pstCurrent] + 1;
                    queueTraversal.push(pstCurrent -> right);
                }
            }
        }
        
        if (hmapNodeParent.find(p) == hmapNodeParent.end() || hmapNodeParent.find(q) == hmapNodeParent.end())
        {
            return NULL;
        }
        
        TreeNode * pstHigherNode = hmapNodeLevel[p] < hmapNodeLevel[q] ? p : q;
        TreeNode * pstLowerNode  = pstHigherNode == p ? q : p;
        unordered_set<TreeNode *> hsetPathToRootFromHigher;
        
        for (TreeNode * pstCurrent = pstHigherNode; pstCurrent != NULL; pstCurrent = hmapNodeParent[pstCurrent])
        {
            hsetPathToRootFromHigher.insert(pstCurrent);
        }
        
        for (TreeNode * pstCurrent = pstLowerNode; pstCurrent != NULL; pstCurrent = hmapNodeParent[pstCurrent])
        {
            if (hsetPathToRootFromHigher.find(pstCurrent) != hsetPathToRootFromHigher.end())
            {
                return pstCurrent;
            }
        }
        
        return NULL;
    }
};

/*

Level-order tranversal, record node's level and parent.

Build the path to root from the higher level.

Begin from the node which has lower level, return the first node appears in the path above.

*/
