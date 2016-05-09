/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:

    int rob(TreeNode * root)
	{
		int iRootRobValue    = rob(root, true);
		int iRootNotRobValue = rob(root, false);
		return iRootRobValue > iRootNotRobValue ? iRootRobValue : iRootNotRobValue;
	}

private:

	int rob(TreeNode * pstRoot, bool bRootRob)
	{
		if (pstRoot == NULL)
		{
			return 0;
		}
		
		if (bRootRob && m_mapMaxValueRootRobTrue.find(pstRoot) != m_mapMaxValueRootRobTrue.end())
		{
			return m_mapMaxValueRootRobTrue[pstRoot];
		}
		
		if (!bRootRob && m_mapMaxValueRootRobFalse.find(pstRoot) != m_mapMaxValueRootRobFalse.end())
		{
			return m_mapMaxValueRootRobFalse[pstRoot];
		}
		
		int iMaxValue      = 0;
		int iRobLeftFalse  = rob(pstRoot -> left,  false);
		int iRobRightFalse = rob(pstRoot -> right, false);
		
		if (bRootRob)
		{
			iMaxValue = pstRoot -> val + iRobLeftFalse + iRobRightFalse;
			m_mapMaxValueRootRobTrue[pstRoot] = iMaxValue;
		}
		else
		{
			int iRobLeftTrue  = rob(pstRoot -> left,  true);
			int iRobRightTrue = rob(pstRoot -> right, true);
			
			iMaxValue = iRobLeftTrue + iRobRightTrue;
			
			if (iMaxValue < iRobLeftTrue + iRobRightFalse)
			{
				iMaxValue = iRobLeftTrue + iRobRightFalse;
			}
			
			if (iMaxValue < iRobLeftFalse + iRobRightTrue)
			{
				iMaxValue = iRobLeftFalse + iRobRightTrue;
			}
			
			if (iMaxValue < iRobLeftFalse + iRobRightFalse)
			{
				iMaxValue = iRobLeftFalse + iRobRightFalse;
			}
			
			m_mapMaxValueRootRobFalse[pstRoot] = iMaxValue;
		}
		
		return iMaxValue;
	}
	
private:

	map<TreeNode *, int> m_mapMaxValueRootRobTrue;
	map<TreeNode *, int> m_mapMaxValueRootRobFalse;
};

/*

递归和深度优先搜索思路是一样的，但是我忽略了一点导致运行时间过长。

深度优先搜索可以存储结点数据，直接递归则不存储。

后来把递归也加上了存储，问题就解决了。

保存结果数据以减少下一次递归时间。

本题从思路上没有走弯路，有点进步，但因头脑过于僵化，居然没想到递归和存储的区别何在。

*/
