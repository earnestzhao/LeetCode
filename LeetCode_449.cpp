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

class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode * root)
    {
        if (root == NULL)
        {
            return "";
        }
        
        string strLeft  = serialize(root -> left);
        string strRight = serialize(root -> right);
        
        ostringstream ossResult;
        ossResult << root -> val;
        
        if (!strLeft.empty())
        {
            ossResult << "," << strLeft;
        }
        
        if (!strRight.empty())
        {
            ossResult << "," << strRight;
        }
        
        return ossResult.str();
    }
    
    // Decodes your encoded data to tree.
    TreeNode * deserialize(string data)
    {
        if (data.empty())
        {
            return NULL;
        }
        
        vector<int> vecPreOrder;
        vecPreOrder.push_back(0);
        
        for (int iIndex = 0; iIndex < data.length(); iIndex ++)
        {
            if (data[iIndex] == ',')
            {
                vecPreOrder.push_back(0);
            }
            else
            {
                int iVectorIndex = vecPreOrder.size() - 1;
                vecPreOrder[iVectorIndex] = vecPreOrder[iVectorIndex] * 10 + data[iIndex] - '0';
            }
        }
        
        return buildBST(vecPreOrder, 0, vecPreOrder.size() - 1);
    }
    
private:

    TreeNode * buildBST(vector<int> & vecPreOrder, int iStartIndex, int iEndIndex)
    {
        if (iEndIndex < iStartIndex)
        {
            return NULL;
        }
        
        int iRightStartIndex = iStartIndex + 1;
        
        for (; iRightStartIndex <= iEndIndex; iRightStartIndex ++)
        {
            if (vecPreOrder[iRightStartIndex] >= vecPreOrder[iStartIndex])
            {
                break;
            }
        }
        
        TreeNode * pstRoot = new TreeNode(vecPreOrder[iStartIndex]);
        pstRoot -> left    = buildBST(vecPreOrder, iStartIndex + 1,  iRightStartIndex - 1);
        pstRoot -> right   = buildBST(vecPreOrder, iRightStartIndex, iEndIndex);
        return pstRoot;
    }
};
