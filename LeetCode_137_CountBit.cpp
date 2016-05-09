class Solution
{
public:

    int singleNumber(vector<int> & nums)
    {
        int aiBitCount[sizeof(int) * 8] = { 0 };
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            for (int iCurrent = nums[iIndex], iBitIndex = 0; iBitIndex < sizeof(int) * 8; iBitIndex ++)
            {
                if (iCurrent & (1 << iBitIndex))
                {
                    aiBitCount[iBitIndex] ++;
                }
            }
        }
        
        int iResultNumber = 0;
        
        for (int iIndex = 0; iIndex < sizeof(int) * 8; iIndex ++)
        {
            if (aiBitCount[iIndex] % 3)
            {
                iResultNumber |= (1 << iIndex);
            }
        }
        
        return iResultNumber;
    }
};

/*

刚开始用异或传统思路去想，败下阵来……

后来参考资料，发现这个方法很巧妙的，还是用位，只是用位来统计……

如果一个整数数组中，其他数出现 n 次，而只有一个数出现一次时，该方法均可用。

用一个数组 aiBitCount[sizeof(int) * 8] 记录所有原始数据中，每个二进制位出现 1 的次数总和，则必有如下关系：

当 aiBitCount[i] % n != 0 时，这位一定是那个只出现一次的数搞的鬼，它的这一位是 1，所以其他数出现 n 次，但总数不是 n 的倍数；

当 aiBitCount[i] % n == 0 时，那个只出现一次的数没有搞鬼，说明它的这一位是 0；

算法很清楚了，针对每个数，统计每一位 i 是不是 1，并且把结果累加到 aiBitCount[i] 中；如果 aiBitCount[i] 是 n 的倍数，则只出现一次的那个数该位就是 1，否则就是 0；

这样就可以把那个数算出来了，时间复杂度 O(sizeof(int) * n + sizeof(int)) = O(n)，空间复杂度 O(sizeof(int)) = O(1)



写的程序总调不对，有两个地方出了问题，

1. sizeof 的单位是字节，想统计位的时候必须乘以 8，糊涂，该打，该死！

2. C 语言中的位运算移位都是算术移位，左移时没有区别，但右移时会保留符号位，之前不清楚这个，导致下面自以为等价的代码出现死循环

for (int iCurrent = nums[iIndex], iBitIndex = 0; iCurrent != 0; iCurrent >>= 1, iBitIndex ++)
{
    if (iCurrent & 0x1)
    {
        aiBitCount[iBitIndex] ++;
    }
}

*/
