class Solution
{
public:

    vector<int> twoSum(vector<int> & numbers, int target)
    {
        vector<int> vecResult;
        
        for (int iHeadIndex = 0, iTailIndex = numbers.size() - 1; iHeadIndex < iTailIndex;)
        {
            if (numbers[iHeadIndex] + numbers[iTailIndex] == target)
            {
                vecResult.push_back(iHeadIndex + 1);
                vecResult.push_back(iTailIndex + 1);
                break;
            }
            
            if (numbers[iHeadIndex] + numbers[iTailIndex] > target)
            {
                iTailIndex --;
            }
            else
            {
                iHeadIndex ++;
            }
        }
        
        return vecResult;
    }
};
