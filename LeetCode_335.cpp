class Solution
{
public:

    bool isSelfCrossing(vector<int> & x)
    {
        if (x.size() <= 3)
        {
            return false;
        }
        
        for (int iIndex = 3; iIndex < x.size(); iIndex ++)
        {
            if (x[iIndex] >= x[iIndex - 2] && x[iIndex - 3] >= x[iIndex - 1])
            {
                return true;
            }
            
            if (iIndex >= 4 && x[iIndex - 1] == x[iIndex - 3] && x[iIndex - 4] + x[iIndex] >= x[iIndex - 2])
            {
                return true;
            }
            
            if (iIndex >= 5 && x[iIndex - 2] > x[iIndex - 4] && x[iIndex - 1] <= x[iIndex - 3] && x[iIndex - 1] + x[iIndex - 5] >= x[iIndex - 3] && x[iIndex] >= x[iIndex - 2] - x[iIndex - 4])
            {
                return true;
            }
        }
        
        return false;
    }
};

/*

开始的时候考虑不相交的形状，共有四种（内外螺旋加单勾 或 上外下内双螺旋），但情况过于复杂，边界条件很多。

没有想到相交的情况规律性比不相交更强。

后面要开拓思路，正反两方面都想到才好。

相交一共有三种情况：第一条边和第四条边相交，第一条边和第五条边重合，第一条边和第六条边相交。

其他顺延即可。

不要害怕困难，多想一想就想出来了，正反都要想，尽量避免产生边界。

写代码时边界情况没有想透，要搞定所有边界判断情况。大小关系一旦出现边界情况没判断好，就会出错。

*/
