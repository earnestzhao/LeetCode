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
            return "NULL";
        }
        
        ostringstream ossResult;
        ossResult << root -> val              << "(";
        ossResult << serialize(root -> left)  << ",";
        ossResult << serialize(root -> right) << ")";
        return ossResult.str();
    }

    // Decodes your encoded data to tree.
    TreeNode * deserialize(string data)
    {
        if (data == "NULL")
        {
            return NULL;
        }
        
        int iBracket = 0;
        
        TreeNode * pstRoot = new TreeNode(0);
        
        for (string::iterator sitSearch = data.begin(), sitWord = data.begin(); sitSearch != data.end(); sitSearch ++)
        {
            if (*sitSearch == '(')
            {
                if (iBracket == 0)
                {
                    pstRoot -> val = atoi(string(sitWord, sitSearch).c_str());
                    sitWord = sitSearch;
                    sitWord ++;
                }
                
                iBracket ++;
            }
            else if (*sitSearch == ',')
            {
                if (iBracket == 1)
                {
                    pstRoot -> left = deserialize(string(sitWord, sitSearch));
                    sitWord = sitSearch;
                    sitWord ++;
                }
            }
            else if (*sitSearch == ')')
            {
                if (-- iBracket == 0)
                {
                    pstRoot -> right = deserialize(string(sitWord, sitSearch));
                    break;
                }
            }
            else
            {
                
            }
        }
        
        return pstRoot;
    }
};
