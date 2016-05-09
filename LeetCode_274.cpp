class Solution
{
public:

    int hIndex(vector<int> & citations)
	{
		sort(citations.begin(), citations.end());
		
		for (int iIndex = 0; iIndex < citations.size(); iIndex ++)
		{
			if (citations[iIndex] >= citations.size() - iIndex)
			{
				return citations.size() - iIndex;
			}
		}
		
		return 0;
    }
};

/*

想思路时总是被一些事打断，这样不好，以后要集中精神做题才有状态。

排个序，排序之后的列表为 c，如果 c[i] >= n - i，则满足条件，n - i 即为结果。

从最小的 i 开始遍历，得到的就是最大的 h 值。

基于二分查找，还可以优化，见第 275 题。

*/
