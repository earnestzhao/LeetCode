class Solution
{
public:

    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        
        int iReverse = 0;
        
        for (int iSource = x; iSource > 0; iSource /= 10)
        {
            iReverse = iReverse * 10 + iSource % 10;
        }
        
        return x == iReverse;
    }
};
