class Solution
{
public:

	enum { LEFT, RIGHT, UP, DOWN };

	int longestIncreasingPath(vector<vector<int>> & matrix)
	{
		m_iRowNumber = matrix.size();
		
		if (m_iRowNumber > 0)
		{
			m_iRowElemNumber = matrix[0].size();
		}
		
		m_iElemNumber = m_iRowNumber * m_iRowElemNumber;
		
		for (int iRowIndex = 0; iRowIndex < m_iElemNumber; iRowIndex ++)
		{
			m_vecGraph.push_back(vector<bool>());
			
			for (int iColIndex = LEFT; iColIndex <= DOWN; iColIndex ++)
			{
				m_vecGraph[iRowIndex].push_back(false);
			}
		}
		
		m_piNodeInDegree = new int[m_iElemNumber];
		
		bzero(m_piNodeInDegree, sizeof(int) * m_iElemNumber);
		
		vector<int> avecZeroInDegreeList[2];
		
		int iCurrentUseIndex = 0;
		
		for (int iRowIndex = 0; iRowIndex < matrix.size(); iRowIndex ++)
		{
			for (int iColIndex = 0; iColIndex < matrix[iRowIndex].size(); iColIndex ++)
			{
				if (iColIndex < matrix[iRowIndex].size() - 1)
				{
					if (matrix[iRowIndex][iColIndex] < matrix[iRowIndex][iColIndex + 1])
					{
						addNodeToGraph(iRowIndex * m_iRowElemNumber + iColIndex, RIGHT);
					}
					
					if (matrix[iRowIndex][iColIndex] > matrix[iRowIndex][iColIndex + 1])
					{
						addNodeToGraph(iRowIndex * m_iRowElemNumber + iColIndex + 1, LEFT);
					}
				}
				
				if (iRowIndex < matrix.size() - 1)
				{
					if (matrix[iRowIndex][iColIndex] < matrix[iRowIndex + 1][iColIndex])
					{
						addNodeToGraph(iRowIndex * m_iRowElemNumber + iColIndex, DOWN);
					}
					
					if (matrix[iRowIndex][iColIndex] > matrix[iRowIndex + 1][iColIndex])
					{
						addNodeToGraph((iRowIndex + 1) * m_iRowElemNumber + iColIndex, UP);
					}
				}
				
				if (m_piNodeInDegree[iRowIndex * m_iRowElemNumber + iColIndex] <= 0)
				{
					avecZeroInDegreeList[iCurrentUseIndex].push_back(iRowIndex * m_iRowElemNumber + iColIndex);
				}
			}
		}
		
		int iMaxPathLength = 0, iElemExistNumber = m_iElemNumber;
		
		while (iElemExistNumber > 0)
		{
			avecZeroInDegreeList[!iCurrentUseIndex].clear();
		
			for (int iIndex = 0; iIndex < avecZeroInDegreeList[iCurrentUseIndex].size(); iIndex ++)
			{
				int iNodeIdSrc = avecZeroInDegreeList[iCurrentUseIndex][iIndex];
				
				iElemExistNumber --;
				
				for (int jIndex = LEFT; jIndex <= DOWN; jIndex ++)
				{
					int iNodeIdDst = 0;
					
					if (m_vecGraph[iNodeIdSrc][jIndex] && getNodeIdDstBySrc(iNodeIdSrc, jIndex, iNodeIdDst))
					{
						m_piNodeInDegree[iNodeIdDst] --;
						
						if (m_piNodeInDegree[iNodeIdDst] <= 0)
						{
							avecZeroInDegreeList[!iCurrentUseIndex].push_back(iNodeIdDst);
						}
					}
				}
			}
			
			iMaxPathLength ++; iCurrentUseIndex = !iCurrentUseIndex;
		}
		
		delete [] m_piNodeInDegree;
		
		m_piNodeInDegree = NULL;
		
		return iMaxPathLength;
    }
	
private:

	vector<vector<bool>> m_vecGraph;
	
	int * m_piNodeInDegree;
	
	int m_iElemNumber;
	
	int m_iRowNumber;
	
	int m_iRowElemNumber;
	
private:

	bool getNodeIdDstBySrc(int iNodeIdSrc, int iDireIndex, int & iNodeIdDst)
	{
		int iRowElemPosition = iNodeIdSrc % m_iRowElemNumber;
	
		if (iDireIndex == LEFT && iRowElemPosition > 0)
		{
			iNodeIdDst = iNodeIdSrc - 1;
			return true;
		}
		
		if (iDireIndex == RIGHT && iRowElemPosition < m_iRowElemNumber - 1)
		{
			iNodeIdDst = iNodeIdSrc + 1;
			return true;
		}
		
		if (iDireIndex == UP && iNodeIdSrc >= m_iRowElemNumber)
		{
			iNodeIdDst = iNodeIdSrc - m_iRowElemNumber;
			return true;
		}
		
		if (iDireIndex == DOWN && iNodeIdSrc < m_iElemNumber - m_iRowElemNumber)
		{
			iNodeIdDst = iNodeIdSrc + m_iRowElemNumber;
			return true;
		}
		
		return false;
	}
	
	void addNodeToGraph(int iNodeIdSrc, int iDireIndex)
	{
		m_vecGraph[iNodeIdSrc][iDireIndex] = true;
		
		int iNodeIdDst = 0;
		
		if (getNodeIdDstBySrc(iNodeIdSrc, iDireIndex, iNodeIdDst))
		{
			m_piNodeInDegree[iNodeIdDst] ++;
		}
	}
};
