class Solution
{
public:

    vector<vector<int>> permute(vector<int> & nums)
    {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> vecResult(1, nums);
        
        while (next_permutation(nums.begin(), nums.end()))
        {
            vecResult.push_back(nums);
        }
        
        return vecResult;
    }
};

/*

STL next_permutation method.

The list must be in ascending order when using "next_permutation" to generate all orders.

*/
