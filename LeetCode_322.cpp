class Solution
{
public:

    int coinChange(vector<int> & coins, int amount)
    {
        vector<int> vecResult(amount + 1, INF);
        
        vecResult[0] = 0;
        
        for (int iSubAmount = 1; iSubAmount <= amount; iSubAmount ++)
        {
            for (int iIndex = 0; iIndex < coins.size(); iIndex ++)
            {
                if (iSubAmount >= coins[iIndex])
                {
                    if (vecResult[iSubAmount] > vecResult[iSubAmount - coins[iIndex]])
                    {
                        vecResult[iSubAmount] = vecResult[iSubAmount - coins[iIndex]] + 1;
                    }
                }
            }
        }
        
        return vecResult[amount] == INF ? -1 : vecResult[amount];
    }
    
private:

    enum { INF = ((unsigned)(-1) >> 1) };
};
