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
        if (root == NULL)
        {
            return NULL;
        }
        
        if (p == NULL)
        {
            return q;
        }
        
        if (q == NULL)
        {
            return p;
        }
        
        midRootTraversal(root);
        
        for (TreeNode * pstCurrent = root; pstCurrent != NULL;)
        {
            if (m_mapTraversalNodeIndex[p] == m_mapTraversalNodeIndex[pstCurrent] || m_mapTraversalNodeIndex[q] == m_mapTraversalNodeIndex[pstCurrent])
            {
                return pstCurrent;
            }
            
            if ((m_mapTraversalNodeIndex[p] <= m_mapTraversalNodeIndex[pstCurrent] && m_mapTraversalNodeIndex[q] >= m_mapTraversalNodeIndex[pstCurrent])
             || (m_mapTraversalNodeIndex[q] <= m_mapTraversalNodeIndex[pstCurrent] && m_mapTraversalNodeIndex[p] >= m_mapTraversalNodeIndex[pstCurrent]))
            {
                return pstCurrent;
            }
            
            if (m_mapTraversalNodeIndex[p] < m_mapTraversalNodeIndex[pstCurrent] && m_mapTraversalNodeIndex[q] < m_mapTraversalNodeIndex[pstCurrent])
            {
                pstCurrent = pstCurrent -> left;
            }
            else
            {
                pstCurrent = pstCurrent -> right;
            }
        }
        
        return NULL;
    }
    
private:
    
    void midRootTraversal(TreeNode * pstRoot)
    {
        if (pstRoot == NULL)
        {
            return;
        }
        
        midRootTraversal(pstRoot -> left);
        
        m_vecTraversalList.push_back(pstRoot);
        
        m_mapTraversalNodeIndex[pstRoot] = m_vecTraversalList.size() - 1;
        
        midRootTraversal(pstRoot -> right);
    }

    vector<TreeNode *> m_vecTraversalList;
    
    map<TreeNode *, int> m_mapTraversalNodeIndex;
};

/*

Bug free once, but see a shot of thinking when query means of words...

If the 2 nodes are separated in 2 sides of the root node, then, the root node is the result.

Otherwise, choose root's left child or root's right child as a new root, then, go on judging like previous step.

This Program implements the logic by Middle Root Sequence, and an index recorder,

which changing judging left sub-tree or right sub-tree as compare index bigger or smaller.

It may have better solution. I will do it later.

*/
