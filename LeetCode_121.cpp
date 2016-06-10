class Solution
{
public:

    int maxProfit(vector<int> & prices)
    {
        if (prices.size() <= 0)
        {
            return 0;
        }
        
        vector<int> vecMaxProfit;
        vecMaxProfit.push_back(0);
        
        int iMinPrice    = prices[0];
        int iFinalResult = 0;
        
        for (int iIndex = 1; iIndex < prices.size(); iIndex ++)
        {
            if (prices[iIndex] < iMinPrice)
            {
                iMinPrice = prices[iIndex];
                vecMaxProfit.push_back(0);
            }
            else
            {
                vecMaxProfit.push_back(prices[iIndex] - iMinPrice);
                
                if (vecMaxProfit[iIndex] > iFinalResult)
                {
                    iFinalResult = vecMaxProfit[iIndex];
                }
            }
        }
        
        return iFinalResult;
    }
};

/*

A easy problem, but an ugly answer.

First, did not understand the topic, then, thought a bit long time. At last, some small bugs occured.

Algorithm:

1. Travesal the list, record the current minimum element 'MIN'.

2. Define v[i] as the max profit if the stock is sold out at the 'ith' day.

3. If the current element 'prices[i]' is less than 'MIN', update the 'MIN' to 'prices[i]', and set v[i] = 0.

4. Else, set v[i] = prices[i] - MIN.

5. The final result is max { v[i] }. 

*/
