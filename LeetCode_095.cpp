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

    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> vecResult;
        generateTrees(n, vecResult);
        return vecResult;
    }
    
private:

    void generateTrees(int iNodeNumber, vector<TreeNode *> & vecResult)
    {
        if (iNodeNumber <= 0)
        {
            return;
        }
        
        if (iNodeNumber == 1)
        {
            vecResult.push_back(new TreeNode(1));
            return;
        }
        
        generateTrees(iNodeNumber - 1, vecResult);
        
        int iPrevResultSize = vecResult.size();
        
        for (int iIndex = 0; iIndex < iPrevResultSize; iIndex ++)
        {
            for (TreeNode * pstNewNodeParent = vecResult[iIndex]; pstNewNodeParent != NULL; pstNewNodeParent = pstNewNodeParent -> right)
            {
                TreeNode * pstNewTreeAddNodeParent = NULL;
                TreeNode * pstNewTree              = copyTree(vecResult[iIndex], pstNewNodeParent, &pstNewTreeAddNodeParent);
                
                TreeNode * pstNewTreeAddNodeSubLeft      = pstNewTreeAddNodeParent -> right;
                pstNewTreeAddNodeParent -> right         = new TreeNode(iNodeNumber);
                pstNewTreeAddNodeParent -> right -> left = pstNewTreeAddNodeSubLeft;
                
                vecResult.push_back(pstNewTree);
            }
        }
        
        for (int iIndex = 0; iIndex < iPrevResultSize; iIndex ++)
        {
            TreeNode * pstNewTree = new TreeNode(iNodeNumber);
            pstNewTree -> left    = vecResult[iIndex];
            vecResult[iIndex]     = pstNewTree;
        }
    }

    TreeNode * copyTree(TreeNode * pstRoot, TreeNode * pstCurrent, TreeNode ** ppstCurrentNew)
    {
        if (pstRoot == NULL)
        {
            return NULL;
        }
        
        TreeNode * pstNewTreeRoot = new TreeNode(pstRoot -> val);
        pstNewTreeRoot -> left    = copyTree(pstRoot -> left,  pstCurrent, ppstCurrentNew);
        pstNewTreeRoot -> right   = copyTree(pstRoot -> right, pstCurrent, ppstCurrentNew);
        
        if (pstRoot == pstCurrent)
        {
            *ppstCurrentNew = pstNewTreeRoot;
        }
        
        return pstNewTreeRoot;
    }
};

/*

Thinking is right, but cost a long time. Almost no bugs, but a key bug...

Dynamic programming. Normal recursion. vecResult[i] = { vecResult[i-1] } ADD node(i).

Add node(i) into right sub-tree of each level because the node(i) is greater than node(i-1).

*/
