class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int result = 0, current_sum = 0;
        unordered_map<int, int> sum_time;
        for (int i = 0; i < nums.size(); i++)
        {
            current_sum += nums[i];
            if (current_sum == k)
            {
                result ++;
            }

            auto iterator = sum_time.find(current_sum - k);
            if (iterator != sum_time.end())
            {
                result += iterator->second;
            }

            sum_time[current_sum] ++;
        }

        return result;
    }
};

/*
 * 1. Understand the meaning of the title wrongly!
 *
 * 2. Consider more about how to optimize space complexity.
 *
 * 3. Time complexity is more important !!!
 */
