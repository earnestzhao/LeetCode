class Solution
{
public:

    int findMaximizedCapital(int k, int W, vector<int> & Profits, vector<int> & Capital)
    {
        bool PairGreater(const pair<int, int> & operandLeft, const pair<int, int> & operandRight);
        multiset<pair<int, int>, bool(*)(const pair<int, int> &, const pair<int, int> &)> profitCapital(PairGreater);

        for (int i = 0; i < Capital.size(); i ++)
        {
            profitCapital.insert(pair<int, int>(Profits[i], Capital[i]));
        }

        for (int i = 0; i < k; i ++)
        {
            set<pair<int, int>, bool(*)(const pair<int, int> &, const pair<int, int> &)>::iterator finder = profitCapital.begin();

            for (; finder != profitCapital.end(); finder ++)
            {
                if ((*finder).second <= W)
                {
                    W += (*finder).first;
                    profitCapital.erase(finder);
                    break;
                }
            }
        }

        return W;
    }
};

bool PairGreater(const pair<int, int> & operandLeft, const pair<int, int> & operandRight)
{
    return operandLeft.first > operandRight.first;
}

