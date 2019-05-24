class Solution
{
public:
    int jump(vector<int> &nums)
    {
        vector<int> vecResult(nums.size(), nums.size() + 1);
        vecResult[0] = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] >= i - j && vecResult[i] > vecResult[j] + 1)
                {
                    vecResult[i] = vecResult[j] + 1;
                } 
            }
        }

        return vecResult[nums.size() - 1];
    }
};

/*
 * 1. Dynamic Programming O(n^2)
 *
 * 2. Time Limit Exceeded.
 *
 * 3. minPath[0] = 0, minPath[i] = min (j < i, nums[j] >= i - j) { minPath[j] + 1 }
 */

