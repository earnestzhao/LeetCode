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
        
        stack<TreeNode *> stackTravesal[2];
        stackTravesal[0].push(root);
        
        for (int iStackCurrentIndex = 0; !stackTravesal[0].empty() || !stackTravesal[1].empty(); iStackCurrentIndex = !iStackCurrentIndex)
        {
            vector<int> vecLevelResult;
            
            while (!stackTravesal[iStackCurrentIndex].empty())
            {
                TreeNode * pstCurrent = stackTravesal[iStackCurrentIndex].top();
                stackTravesal[iStackCurrentIndex].pop();
                vecLevelResult.push_back(pstCurrent -> val);
                
                TreeNode * pstCurrentChildPushFirst  = !iStackCurrentIndex ? pstCurrent -> left  : pstCurrent -> right;
                TreeNode * pstCurrentChildPushSecond = !iStackCurrentIndex ? pstCurrent -> right : pstCurrent -> left;
                
                if (pstCurrentChildPushFirst != NULL)
                {
                    stackTravesal[!iStackCurrentIndex].push(pstCurrentChildPushFirst);
                }
                
                if (pstCurrentChildPushSecond != NULL)
                {
                    stackTravesal[!iStackCurrentIndex].push(pstCurrentChildPushSecond);
                }
            }
            
            vecResult.push_back(vecLevelResult);
        }
        
        return vecResult;
    }
};

/*

Using 2 stacks S0 and S1.

If pop from S0 and push its children to S1, then push from left to right.

If pop from S1 and push its children to S0, then push from right to left.

Because of no reverse, it can reduce runtime compared with reverse method.

*/
