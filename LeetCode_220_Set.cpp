class Solution
{
public:

    bool containsNearbyAlmostDuplicate(vector<int> & nums, int k, int t)
    {
        set<int> setValueInRange;
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            if (iIndex > k)
            {
                setValueInRange.erase(nums[iIndex - k - 1]);
            }
            
            set<int>::iterator setIterator = setValueInRange.lower_bound(nums[iIndex] - t);
            
            if (setIterator != setValueInRange.end() && *setIterator - nums[iIndex] <= t)
            {
                return true;
            }
            
            setValueInRange.insert(nums[iIndex]);
        }
        
        return false;
    }
};

/*

This algorithm and method is out of my knowledge. Learn it!!!

Keep a set for each element range of [nums[i-k], num[i]].

Use lower_bound method to find an element in the set which is the smallest one bigger than nums[i] - t.

Check the element, return true if it is smaller than nums[i] + t.

The real data structure is binary search tree. I will implement it again without set, but binary search tree manually.

*/
