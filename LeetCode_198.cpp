class Solution
{
public:

    int rob(vector<int> & nums)
    {   
        if (nums.size() <= 0)
        {
            return 0;
        }
        
        if (nums.size() == 1)
        {
            return nums[0];
        }
        
        vector<int> vecIndexRobMax;
        vector<int> vecIndexNoRobMax;
        
        vecIndexRobMax.push_back(nums[0]);
        vecIndexNoRobMax.push_back(0);
        
        vecIndexRobMax.push_back(nums[1]);
        vecIndexNoRobMax.push_back(nums[0]);
        
        for (int iIndex = 2; iIndex < nums.size(); iIndex ++)
        {
            vecIndexRobMax.push_back(max(vecIndexNoRobMax[iIndex - 1] + nums[iIndex], vecIndexRobMax[iIndex - 2] + nums[iIndex]));
            vecIndexNoRobMax.push_back(max(vecIndexRobMax[iIndex - 1], vecIndexNoRobMax[iIndex - 1]));
        }
        
        return max(vecIndexRobMax[nums.size() - 1], vecIndexNoRobMax[nums.size() - 1]);
    }
    
private:

    int max(int x, int y)
    {
        return x > y ? x : y;
    }
};

/*

Dynamic Programming.

Define rm[i] as max value with index i robbed, nrm[i] as max value without index i robbed.

rm[i] = max { nrm[i-1] + nums[i], rm[i-2] + nums[i] }

nrm[i] = max { rm[i-1], nrm[i-1] }

The final result is max { rm[nums.size()-1], nrm[nums.size()-1] }

*/
