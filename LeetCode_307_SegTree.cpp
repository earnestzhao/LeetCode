class NumArray
{
public:
    
	NumArray(vector<int> & nums) 
	{
		m_pstRoot = buildSumSegTree(nums, 0, nums.size() - 1);
    }

    void update(int i, int val)
	{
		if (m_pstRoot != NULL)
		{
			updateSumValue(m_pstRoot, i, val);
		}
    }

    int sumRange(int i, int j)
	{
		if (m_pstRoot != NULL)
		{
			return getSumValueOfRange(m_pstRoot, i, j);
		}
		
		return 0;
    }
	
private:

	struct SumSegTreeNode
	{
		int iSumValue;
		
		int iSegLeft, iSegRight;
		
		SumSegTreeNode * pstNodeLeft, * pstNodeRight;
		
		SumSegTreeNode() : iSumValue(0), iSegLeft(0), iSegRight(0), pstNodeLeft(NULL), pstNodeRight(NULL) {  }
	};
	
	SumSegTreeNode * buildSumSegTree(const vector<int> & vecNumList, int iSegLeft, int iSegRight)
	{
		if (vecNumList.size() <= 0)
		{
			return NULL;
		}
		
		SumSegTreeNode * pstRoot = new SumSegTreeNode;
		pstRoot -> iSegLeft  = iSegLeft;
		pstRoot -> iSegRight = iSegRight;
		
		if (iSegLeft == iSegRight)
		{
			pstRoot -> iSumValue    = vecNumList[iSegLeft];
			pstRoot -> pstNodeLeft  = NULL;
			pstRoot -> pstNodeRight = NULL;
		}
		else
		{
			int iMidValue = (iSegLeft + iSegRight) / 2;
			pstRoot -> pstNodeLeft  = buildSumSegTree(vecNumList, iSegLeft,      iMidValue);
			pstRoot -> pstNodeRight = buildSumSegTree(vecNumList, iMidValue + 1, iSegRight);
			pstRoot -> iSumValue    = pstRoot -> pstNodeLeft -> iSumValue + pstRoot -> pstNodeRight -> iSumValue;
		}
		
		return pstRoot;
	}
	
	void updateSumValue(SumSegTreeNode * pstRoot, int iIndex, int iValue)
	{
		if (pstRoot -> iSegLeft == pstRoot -> iSegRight)
		{
			pstRoot -> iSumValue = iValue;
			return;
		}
		
		int iMidValue = (pstRoot -> iSegLeft + pstRoot -> iSegRight) / 2;
		
		if (iIndex <= iMidValue)
		{
			updateSumValue(pstRoot -> pstNodeLeft, iIndex, iValue);
		}
		else
		{
			updateSumValue(pstRoot -> pstNodeRight, iIndex, iValue);
		}
		
		pstRoot -> iSumValue = pstRoot -> pstNodeLeft -> iSumValue + pstRoot -> pstNodeRight -> iSumValue;
	}
	
	int getSumValueOfRange(SumSegTreeNode * pstRoot, int iRangeLeft, int iRangeRight)
	{
		if (iRangeLeft == pstRoot -> iSegLeft && iRangeRight == pstRoot -> iSegRight)
		{
			return pstRoot -> iSumValue;
		}
		
		int iMidValue = (pstRoot -> iSegLeft + pstRoot -> iSegRight) / 2;
		
		if (iRangeLeft <= iMidValue && iRangeRight <= iMidValue)
		{
			return getSumValueOfRange(pstRoot -> pstNodeLeft, iRangeLeft, iRangeRight);
		}
		
		if (iRangeLeft > iMidValue && iRangeRight > iMidValue)
		{
			return getSumValueOfRange(pstRoot -> pstNodeRight, iRangeLeft, iRangeRight);
		}
		
		return getSumValueOfRange(pstRoot -> pstNodeLeft, iRangeLeft, iMidValue) + getSumValueOfRange(pstRoot -> pstNodeRight, iMidValue + 1, iRangeRight);
	}
	
	SumSegTreeNode * m_pstRoot;
};

/*

娘的，还好看了 Tag，如果死研究下去，不知道什么时候是个头呢，呜呜……

看来一些东西在没有思路的情况下，看看 Tag 也许有帮助，这次碰到了之前没学过的数据结构，理所当然败下阵来……

本题属于区间统计，典型的应用就是可以设置单个元素，另外还需要对整个区间求和。如果使用传统数组，那么两个操作中必有一个是 O(n)，另外一个是 O(1)

适用的数据结构有两种：线段树（Segment Tree）和树状数组（Binary Indexed Tree）

这个方法是用线段树来实现的，树状数组的学完决定再写一个。现在代码质量是越来越高了，但是该死的脑子，能不能不要忘记边界条件？（空数组 空树 单节点树）

自己复习一下线段树，个人喜欢完全不交叉，叶节点左右边界相等的闭区间线段树。

1. 二叉树，节点的标识是一个区间（个人喜欢闭区间）

2. 同一层节点所标识的区间没有交集

3. 叶节点区间的左右值相等

4. 选用 m = (l + r) / 2 的形式分割当前区间，形成两个不相交子区间，[l, m] 和 [m + 1, r]，再对子区间分别递归建树，直到 l = r 为止

5. 节点可以像数组一样存储值，一般在回溯时设置，本题是求和，因此必须在回溯时设置

6. 单一节点查找时，需要指定该点索引值，查找时间复杂度 O(logn)

7. 区间合并计算时，需要找到待合并的目标子区间，根据区间中值和给定区间的大小，来确定区间位于左子树还是右子树，或分别位于左右子树。递归处理，时间复杂度 O(logn)

O(logn) 用求解递归式的方式无法描述，需要深入理解，树的每一层最多被选中两个节点，共有 logn 层，因此共有 2logn = O(logn)

树状数组的解法会再写一次程序，另外一个文件中，一定要深刻理解哦！

*/
