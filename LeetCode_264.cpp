class Solution
{
public:

	int nthUglyNumber(int n)
	{
		vector<int> vecUglyNumberList;
		vecUglyNumberList.push_back(0);
		vecUglyNumberList.push_back(1);
		vecUglyNumberList.push_back(2);
		vecUglyNumberList.push_back(3);
		vecUglyNumberList.push_back(4);
		vecUglyNumberList.push_back(5);
		
		for (int iIndex = 6; iIndex <= n; iIndex ++)
		{
			int iExpect2 = BinarySearchBigger(vecUglyNumberList, vecUglyNumberList[iIndex - 1] / 2);
			int iExpect3 = BinarySearchBigger(vecUglyNumberList, vecUglyNumberList[iIndex - 1] / 3);
			int iExpect5 = BinarySearchBigger(vecUglyNumberList, vecUglyNumberList[iIndex - 1] / 5);
			
			int iExpectVal2 = iExpect2 * 2;
			int iExpectVal3 = iExpect3 * 3;
			int iExpectVal5 = iExpect5 * 5;
			int iUglyNumber = iExpectVal2;
			
			if (iUglyNumber > iExpectVal3)
			{
				iUglyNumber = iExpectVal3;
			}
			
			if (iUglyNumber > iExpectVal5)
			{
				iUglyNumber = iExpectVal5;
			}
			
			vecUglyNumberList.push_back(iUglyNumber);
		}
		
		return vecUglyNumberList[n];
	}
	
private:

	int BinarySearchBigger(const vector<int> & vecList, int iValue)
	{
		int iStartIndex = 0;
		int iEndIndex   = vecList.size() - 1;
		
		while (iStartIndex <= iEndIndex)
		{
			int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
			
			if (iValue == vecList[iMidIndex])
			{
				return vecList[iMidIndex + 1];
			}
			else if (iValue > vecList[iMidIndex])
			{
				iStartIndex = iMidIndex + 1;
			}
			else
			{
				iEndIndex = iMidIndex - 1;
			}
		}
		
		return vecList[iStartIndex];
	}
};

/*

思路没有错，实现的时候除法被除数搞错了，这个实在该打啊！

二分查找应该是 OK 了，以后只要有机会就多写。

思路还是比较简单清晰的，ugly 序列是一个递增序列，若需要求得当前的 ugly[i]，需要知道必有一个 j (j < i)，

满足 ugly[i] = min (j < i, ugly[j] * either(2,3,5) > ugly[i-1]) {ugly[j] * 2, ugly[j] * 3, ugly[j] * 5}

知道了这个关系就好办了，用 ugly[i-1] 分别除以 2,3,5，得到 ugly[i-1]/2, ugly[i-1]/3, ugly[i-1]/5 这三个值，

然后再在已经算出的 ugly 序列中分别找到大于它们的三个最小值，再用这三个最小值分别乘以 2,3,5，得到三个备选值，这三个备选值中最小的值即是 ugly[i]

由于 ugly 序列是递增序列，因此查找大于 ugly[i-1]/2, ugly[i-1]/3, ugly[i-1]/5 的最小值时适用二分查找。

*/
