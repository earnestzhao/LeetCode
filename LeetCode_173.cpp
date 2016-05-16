/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator
{
public:

    BSTIterator(TreeNode * root) : m_iCurrentIndex(0)
    {
        midRootTravesal(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return m_iCurrentIndex < m_vecMidRootSeq.size();
    }

    /** @return the next smallest number */
    int next()
    {
        return m_vecMidRootSeq[m_iCurrentIndex ++];
    }
    
private:

    void midRootTravesal(TreeNode * root)
    {
        if (root == NULL)
        {
            return;
        }
        
        midRootTravesal(root -> left);
        
        m_vecMidRootSeq.push_back(root -> val);
        
        midRootTravesal(root -> right);
    }
    
private:

    int m_iCurrentIndex;
    
    vector<int> m_vecMidRootSeq;
};

/*

A simple thinking, but not bug free...

Middle root travesal, and give the next element out...

next/hasNext Time Complex: O(1)

next/hasNext Space Complex: O(1)

Total Space Complex: O(n)

Is there O(h) total space complex algorithm exists? Research it later.

*/
