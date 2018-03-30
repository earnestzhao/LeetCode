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

    vector<int> findFrequentTreeSum(TreeNode * root)
    {
        if (root == NULL)
        {
            return vector<int>();
        }

        calculateSumFrequent(root);

        int iMaxFrequent = 0;

        for (unordered_map<int, vector<int>>::iterator hmapIterator = m_hmapSumFrequent.begin(); hmapIterator != m_hmapSumFrequent.end(); hmapIterator ++)
        {
            if (hmapIterator -> second.size() > iMaxFrequent)
            {
                iMaxFrequent = hmapIterator -> second.size();
            }
        }

        vector<int> vecResult;

        for (unordered_map<int, vector<int>>::iterator hmapIterator = m_hmapSumFrequent.begin(); hmapIterator != m_hmapSumFrequent.end(); hmapIterator ++)
        {
            if (hmapIterator -> second.size() == iMaxFrequent)
            {
                vecResult.push_back(hmapIterator -> first);
            }
        }

        return vecResult;
    }

private:

    int calculateSumFrequent(TreeNode * pstRoot)
    {
        if (pstRoot == NULL)
        {
            return 0;
        }

        int iLeftSubTreeSum  = calculateSumFrequent(pstRoot -> left);
        int iRightSubTreeSum = calculateSumFrequent(pstRoot -> right);
        int iTreeSum         = pstRoot -> val + iLeftSubTreeSum + iRightSubTreeSum;

        unordered_map<int, vector<int>>::iterator hmapIterator = m_hmapSumFrequent.find(iTreeSum);

        if (hmapIterator != m_hmapSumFrequent.end())
        {
            hmapIterator -> second.push_back(pstRoot -> val);
        }
        else
        {
            m_hmapSumFrequent[iTreeSum] = vector<int>(1, pstRoot -> val);
        }

        return iTreeSum;
    }

private:

    unordered_map<int, vector<int>> m_hmapSumFrequent;
};

