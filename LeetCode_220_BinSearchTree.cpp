class BinSearchTree
{
public:

	BinSearchTree() : m_pstRoot(NULL)
	{
		
	}
	
	void Insert(int iValue)
	{
		if (m_pstRoot -> m_iValue == iValue)
		{
			return;
		}
		
		if (m_pstRoot == NULL)
		{
			m_pstRoot = new BinSearchTreeNode(iValue);
			return;
		}
		
		BinSearchTreeNode * pstParent  = NULL;
		BinSearchTreeNode * pstCurrent = m_pstRoot;
		
		while (pstCurrent != NULL)
		{
			if (pstCurrent -> m_iValue == iValue)
			{
				return;
			}
			
			pstParent = pstCurrent;
			
			if (iValue < pstCurrent -> m_iValue)
			{
				pstCurrent = pstCurrent -> m_pstLeft;
			}
			else
			{
				pstCurrent = pstCurrent -> m_pstRight;
			}
		}
		
		if (iValue < pstParent -> m_iValue)
		{
			pstParent -> m_pstLeft = new BinSearchTreeNode(iValue);
		}
		else
		{
			pstParent -> m_pstRight = new BinSearchTreeNode(iValue);
		}
	}
	
	void Delete(int iValue)
	{
		BinSearchTreeNode * pstParent  = NULL;
		BinSearchTreeNode * pstCurrent = m_pstRoot;
		
		while (pstCurrent != NULL)
		{
			if (pstCurrent -> m_iValue == iValue)
			{
				break;
			}
			
			pstParent = pstCurrent;
			
			if (pstCurrent -> m_iValue > iValue)
			{
				pstCurrent = pstCurrent -> m_pstLeft;
			}
			else
			{
				pstCurrent = pstCurrent -> m_pstRight;
			}
		}
		
		if (pstCurrent == NULL)
		{
			return;
		}
		
		if (pstCurrent == pstParent -> m_pstLeft)
		{
			
		}
		else
		{
		}
	}
	
private:

	struct BinSearchTreeNode
	{
		int m_iValue;
		
		BinSearchTreeNode * m_pstLeft;
		
		BinSearchTreeNode * m_pstRight;
		
		BinSearchTreeNode(int iValue) : m_iValue(iValue), m_pstLeft(NULL), m_pstRight(NULL)
		{
			
		}
	};
	
	BinSearchTreeNode * m_pstRoot;
};

class Solution
{
public:

    bool containsNearbyAlmostDuplicate(vector<int> & nums, int k, int t)
	{
		return true;
    }
};
