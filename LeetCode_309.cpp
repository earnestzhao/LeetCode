class Solution
{
public:

    int maxProfit(vector<int> & prices)
    {
        if (prices.size() <= 1)
        {
            return 0;
        }
        
        vector<int> vecNotHaveList;
        vecNotHaveList.push_back(0);
        vecNotHaveList.push_back(max(0, prices[1] - prices[0]));
        
        vector<int> vecHaveList;
        vecHaveList.push_back(- prices[0]);
        vecHaveList.push_back(max(- prices[0], - prices[1]));
        
        for (int iIndex = 2; iIndex < prices.size(); iIndex ++)
        {
            vecNotHaveList.push_back(max(vecHaveList[iIndex - 1] + prices[iIndex], vecNotHaveList[iIndex - 1]));
            vecHaveList.push_back(max(vecNotHaveList[iIndex - 2] - prices[iIndex], vecHaveList[iIndex - 1]));
        }
        
        return vecNotHaveList[vecNotHaveList.size() - 1];
    }
    
private:

    int max(int x, int y)
    {
        return x > y ? x : y;
    }
};

/*

受到之前增减区间的思路限制，这次没有想对，该打！

之前的思路是找到所有的单调递增区间，在增区间起始点买入，在最高点卖出。

因为有冷却期，所以想到，如果两个增区间相邻（当前区间起点 - 上一区间终点 = 1），则有两种情况，一是去掉上一区间终点，二是去掉本区间起点……

乍看思路正确，其实存在问题，情况比想像得要多……

1. 上个区间起点到本区间终点的差值可能比两个区间收益值加起来还大

2. 一旦选择或放弃了一个区间，则后续最优决策可能会影响之前的决策，例如 2,3,5,8,3,8,2,6…… 极端情况下需要遍历所有之前决策的结果才能得到正确结果

失败了，气馁……思路也被局限在了单调区间上，没办法只能查资料解决了。（差价倒是想到了）


两种动态规划方法，理解描述 + 语言表达 锻炼……

第一种  sell[i] -- 第 i 天有卖出行为之后的最大收益；buy[i] -- 第 i 天有买入行为之后的最大收益；（只看手里的钱，不看手里的股票）

则 sell[i] = max { buy[i-1] + p[i] , sell[i-1] + p[i] - p[i-1] };  buy[i] = max { sell[i-2] - p[i], buy[i-1] - (p[i] - p[i-1]) };  最终结果 max{ sell[i] }

第二种  notHave[i] -- 第 i 天无持股状态下的最大收益；have[i] -- 第 i 天有持股状态下的最大收益；（只看手里的钱，不看手里的股票）

则 notHave[i] = max { notHave[i-1], have[i-1] + p[i] };  have[i] = max { have[i-1], notHave[i-1] - p[i] };  最终结果 notHave[n-1]

第二种理解成本更低，且实现起来更方便

初始条件是 sell/notHave[0] = 0, buy/have[0] = - p[0];

比较巧妙的是 buy/have，允许负数，想一想也是，买的时候减去当前价格，卖的时候加上当前价格，自然赔赚立现！


得到的一个启发是：不要拘泥于动态规划单一的递推公式，有多个状态时，用多个递推公式，可能思路会更加明朗

*/
