class Solution
{
public:

	vector<int> countBits(int num)
	{
		vector<int> vecResult;
		vecResult.push_back(0);
		
		for (int iSquareNum = 1; num > 0; iSquareNum <<= 1)
		{
			for (int iIndex = 0; iIndex < iSquareNum; iIndex ++)
			{
				vecResult.push_back(vecResult[iIndex] + 1);
				
				if (vecResult.size() >= num + 1)
				{
					break;
				}
			}
			
			if (vecResult.size() >= num + 1)
			{
				break;
			}
		}
		
		return vecResult;
    }
};

/*

我的方法比较好，循环取值，只要最高位为 1，低位都是循环的；

andy 和 peter 的思路都是纯动态规划的，可以借鉴一下。


f(n) = f(n/2)      n是偶数

f(n) = f(n/2) + 1  n是奇数


f(n+1) = f(n) + 1   n是偶数

f(n+1) = f(n/2 + 1) n是奇数 相当于模拟进位

*/
