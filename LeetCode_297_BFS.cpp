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
            return "[]";
        }
        
        ostringstream ossResult;
        ossResult.put('[');
        
        queue<TreeNode *> queueSerializer;
        queueSerializer.push(root);
        
        for (int iNotNullCountInQueue = 1; iNotNullCountInQueue > 0;)
        {
            TreeNode * pstFront = queueSerializer.front();
            queueSerializer.pop();
            
            if (pstFront != NULL)
            {
                ossResult << pstFront -> val << ",";
                queueSerializer.push(pstFront -> left);
                queueSerializer.push(pstFront -> right);
                
                if (pstFront -> left != NULL)
                {
                    iNotNullCountInQueue ++;
                }
                
                if (pstFront -> right != NULL)
                {
                    iNotNullCountInQueue ++;
                }
                
                iNotNullCountInQueue --;
            }
            else
            {
                ossResult << "N,";
            }
        }
        
        ossResult.seekp(ossResult.tellp() - 1);
        ossResult.put(']');
        return ossResult.str();
    }

    // Decodes your encoded data to tree.
    TreeNode * deserialize(string data)
    {
        if (data == "[]")
        {
            return NULL;
        }
        
        vector<TreeNode *> vecNodeList;
        
        for (string::iterator sitSearch = data.begin() + 1, sitWord = sitSearch; sitSearch != data.end(); sitSearch ++)
        {
            if (*sitSearch == ',' || *sitSearch == ']')
            {
                string strNodeValue(sitWord, sitSearch);
                
                if (strNodeValue == "N")
                {
                    vecNodeList.push_back(NULL);
                }
                else
                {
                    vecNodeList.push_back(new TreeNode(atoi(strNodeValue.c_str())));
                }
                
                sitWord = sitSearch + 1;
            }
        }
        
        TreeNode * pstRoot = vecNodeList[0];
        
        for (int iExtendIndex = 0, iExtendSubIndex = 1; iExtendSubIndex < vecNodeList.size(); iExtendIndex ++)
        {
            TreeNode * pstCurrent = vecNodeList[iExtendIndex];
            
            if (pstCurrent == NULL)
            {
                continue;
            }
            
            pstCurrent -> left = vecNodeList[iExtendSubIndex ++];
            
            if (iExtendSubIndex < vecNodeList.size())
            {
                pstCurrent -> right = vecNodeList[iExtendSubIndex ++];
            }
        }
        
        return pstRoot;
    }
};

/*

BFS is faster than DFS.

It seems that there is a faster way.

*/
