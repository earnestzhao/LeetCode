class Solution
{
public:

    vector<int> singleNumber(vector<int> & nums)
	{
		if (nums.size() <= 2)
		{
			return nums;
		}
		
		int iXorResult = nums[0];
		
		for (int iIndex = 1; iIndex < nums.size(); iIndex ++)
		{
			iXorResult ^= nums[iIndex];
		}
		
		int iBitOneFirstPosition = 0;
		
		for (int iPos = 0; iPos < sizeof(int) * 8; iPos ++)
		{
			if (iXorResult & (1 << iPos))
			{
				iBitOneFirstPosition = iPos;
				break;
			}
		}
		
		vector<int> vecResult;
		vecResult.push_back(0);
		vecResult.push_back(0);
		
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			if (nums[iIndex] & (1 << iBitOneFirstPosition))
			{
				vecResult[1] ^= nums[iIndex];
			}
			else
			{
				vecResult[0] ^= nums[iIndex];
			}
		}
		
		return vecResult;
    }
};

/*

程序又没有一次写对，又是小细节出错，真是该打啊……

之前思路想到了分组，但对于如何分组，确实没想好，思路的拓展性太差了，其实往前进一小步就会想到了……

首先还是把所有的数字异或起来，得到一个结果 iXorResult = a[i] ^ a[j]，即为查找目标元素的异或值。

然后取这个 iXorResult 中比特位为 1 的任何一个位都可以，上述程序取的是右数第一位。

用这个比特位为 1 的位，将原有输入数组分为两组。两组分别异或，所得到的结果就是这两个目标数。

中间那个循环有些拙劣，应该是一步就可以计算出来了。iBitOneFirstPosition = iXorResult & ~(iXorResult - 1)

这样后面也就不用移位了……

但是貌似 LeetCode 反馈，这个的性能比我这个循环统计的还差，是不是和硬件或者缓存一类的有关系？有待研究

*/
