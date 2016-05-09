class Solution
{
public:

    int majorityElement(vector<int> & nums)
	{
		int aiBitCount[2][sizeof(int) * 8] = { { 0 } };
		
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			for (int jIndex = 0; jIndex < sizeof(int) * 8; jIndex ++)
			{
				aiBitCount[!!(nums[iIndex] & (1 << jIndex))][jIndex] ++;
			}
		}
		
		int iResultValue = 0;
		
		for (int iIndex = 0; iIndex < sizeof(int) * 8; iIndex ++)
		{
			iResultValue |= ((aiBitCount[1][iIndex] > aiBitCount[0][iIndex]) << iIndex);
		}
		
		return iResultValue;
    }
};

/*

Bit Manipulation. Another good algorithm. sizeof(int) * n + sizeof(int) = O(n)

sizeof(int) * 8 !!! Fuck!!! Why am I always forget it when Bit Manipulation ???!!!

Count ith bit 1's number and 0's number of all numbers. The count of each bit of the majority element has more 1 or 0 than other elements.

So, if a bit of 1's count is more than 0's count, the majority element on this bit is 1, vice versa.   

*/
