class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        ostringstream result;
        if (nums.size() == 1)
        {
            result << nums[0];
            return result.str();
        }

        if (nums.size() == 2)
        {
            result << nums[0] << "/" << nums[1];
            return result.str();
        }

        result << nums[0] << "/(" << nums[1];
        for (size_t i = 2; i < nums.size(); i++)
        {
            result << "/" << nums[i];
        }

        result << ")";
        return result.str();
    }
};
