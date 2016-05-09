class Solution
{
public:

	int singleNumber(vector<int> & nums)
	{
		int iOne = 0, iTwo = 0, iThree = 0;
		
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			iTwo   = (nums[iIndex] & iOne) | iTwo;
			iOne   = nums[iIndex] ^ iOne;
			iThree = iOne & iTwo;
			
			iOne &= ~iThree;
			iTwo &= ~iThree;
		}
		
		return iOne;
	}
};

/*

其实思维和 CountBit 版本是一样的，只是把这个搞成了位操作，节省了空间和时间，这次空间复杂度是真正的 O(1) 了，时间复杂度 O(n)，谱系一样，但是少了倍数。

CountBit 空间复杂度是 O(sizeof(T))，当然可以近似为 O(1)，因为和输入规模无关，和输入集元素的数据类型相关。

方法的本质也是计数，可参见 CountBit 的总结。

只不过计数的方法是使用三个变量，记录每一位 >= 3 的 1 的个数，由于超过三个的元素都被搞到了 two, three 中，最后剩下的 one 就是最终结果了。

*/
