class Solution
{
public:

    bool canJump(vector<int> & nums)
    {
        if (nums.size() <= 0)
        {
            return false;
        }
        
        if (nums.size() == 1)
        {
            return true;
        }
        
        queue<int> queueTraversal;
        queueTraversal.push(0);
        
        while (!queueTraversal.empty())
        {
            int iCurrentIndex = queueTraversal.front(); queueTraversal.pop();
            
            for (int iNewIndex = queueTraversal.back() + 1; iNewIndex <= iCurrentIndex + nums[iCurrentIndex]; iNewIndex ++)
            {
                if (iNewIndex >= nums.size() - 1)
                {
                    return true;
                }
                
                queueTraversal.push(iNewIndex);
            }
        }
        
        return false;
    }
};

/*

Thinking is right, but "Time Limit Exceeded" so many times.

Normal bandwidth first search.

Because of index increasing order of elements which are pushed to BFS Queue, we can use the back element of the BFS Queue to reduce times of inner loop.

*/
