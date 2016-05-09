class Solution
{
public:

	int nthSuperUglyNumber(int n, vector<int> & primes)
	{
		m_vecResultList.clear();
		m_vecResultList.push_back(0);
		m_vecResultList.push_back(1);
		m_vecResultList.push_back(primes[0]);
		
		for (int iCurrent = 3; iCurrent <= n; iCurrent ++)
		{
			int iMinNext = (int)((unsigned)(-1) >> 1);
			
			for (int iIndex = 0; iIndex < primes.size(); iIndex ++)
			{
				int iNextExpect = getMinBiggerValue(0, iCurrent - 1, m_vecResultList[iCurrent - 1] / primes[iIndex]) * primes[iIndex];
				
				if (iNextExpect < iMinNext)
				{
					iMinNext = iNextExpect;
				}
			}
			
			m_vecResultList.push_back(iMinNext);
		}
		
		return m_vecResultList[n];
    }
	
private:

	int getMinBiggerValue(int iStartIndex, int iEndIndex, int iValue)
	{
		if (iValue == 0)
		{
			return 1;
		}
		
		while (iStartIndex >= 0 && iEndIndex >= 0 && iStartIndex <= iEndIndex)
		{
			int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
			
			if (iValue == m_vecResultList[iMidIndex])
			{
				return m_vecResultList[iMidIndex + 1];
			}
			
			if (iValue < m_vecResultList[iMidIndex])
			{
				iEndIndex = iMidIndex - 1;
			}
			else
			{
				iStartIndex = iMidIndex + 1;
			}
		}
		
		return m_vecResultList[iStartIndex];
	}
	
private:

	vector<int> m_vecResultList;
};

/*

还是一次成功，但是第一次提交过程中弄掉了一个边界，该打！

思路是（设 a 为结果数组）：任何一个 a[i]，都是由某个 a[j] (j<i) 再乘以一个 p[s] 得到；

因此对所有的 a[j] (j<i) 都分别乘以 p[0...k-1]，再取大于 a[i-1] 且最小的那个，就是 a[i]；

简化一下，变成使用 a[i-1] 分别除以 p[0...k-1]，得到 a[i-1]/p[s] 的值，再在已经生成的 a[1...i-1] 序列中找到刚好大于这个值的数，

再用这个数乘以 p[s]，就是含有 p[s] 因子的，大于 a[i-1] 的最小值；

循环处理，拿到所有的含 p[0...k-1] 因子的，大于 a[i-1] 的最小值集合 b[0...k-1]，取这些值中最小的，就是 a[i]；

由于 a[1...i-1] 有序，所以二分查找可用，最终时间复杂度是 O(knlogn)。

虽然 Accepted，但是运行时间仅仅打败了 2.82% 的人，后续还需要再想优化方法。

*/
