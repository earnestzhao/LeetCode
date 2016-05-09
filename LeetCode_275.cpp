class Solution
{
public:

    int hIndex(vector<int> & citations)
    {
        int iStartIndex = 0;
        int iEndIndex   = citations.size() - 1;
        
        while (iStartIndex < iEndIndex)
        {
            int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
            
            if (citations[iMidIndex] <= 0)
            {
                iStartIndex = iMidIndex + 1;
                continue;
            }
            
            if (citations[iMidIndex] >= citations.size() - iMidIndex)
            {
                iEndIndex = iMidIndex;
            }
            else
            {
                iStartIndex = iMidIndex + 1;
            }
        }
        
        if (iStartIndex == iEndIndex && citations[iStartIndex] > 0)
        {
            return citations.size() - iStartIndex;
        }
        
        return 0;
    }
};

/*

二分查找优化，思路没问题，但边界没考虑好，全 0 的时候会出错，该打啊！

后来加入了 0 值限制，就 OK 了。

没什么其他好说，就是边界条件，还是要注意啊！！！

*/
