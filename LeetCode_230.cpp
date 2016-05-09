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

    int kthSmallest(TreeNode* root, int k)
    {   
        if (m_vecMidRootTraversal.size() >= k)
        {
            return m_vecMidRootTraversal[k - 1];
        }
        
        if (root == NULL)
        {
            return 0;
        }
        
        kthSmallest(root -> left, k);
        
        m_vecMidRootTraversal.push_back(root -> val);
        
        if (m_vecMidRootTraversal.size() >= k)
        {
            return m_vecMidRootTraversal[k - 1];
        }
        
        kthSmallest(root -> right, k);
    }
    
private:

    vector<int> m_vecMidRootTraversal;
};

/*

Bug Free! Both thinking and writing is right! But because of more thinking of O(logn), I failed writing it out for test.

Middle Root Tranversal, then output the kth element. I have thoughted immediately. The speed is fast in Leetcode's submission.

But maybe have more directly solution. Research it later.

*/
