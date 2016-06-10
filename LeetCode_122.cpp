class Solution
{
public:

    int maxProfit(vector<int> & prices)
    {
        int iMaxProfit = 0;
        
        for (int iIndex = 1; iIndex < prices.size(); iIndex ++)
        {
            if (prices[iIndex] > prices[iIndex - 1])
            {
                iMaxProfit += prices[iIndex] - prices[iIndex - 1];
            }
        }
        
        return iMaxProfit;
    }
};

/*

Bug free. Very easy.

Make a summary of the interval of each increasing range.

*/
