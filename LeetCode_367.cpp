class Solution
{
public:

    bool isPerfectSquare(int num)
    {
        int iStartNum = 1;
        int iEndNum   = num;
        
        while (iStartNum <= iEndNum)
        {
            int iMidNum    = iStartNum + (iEndNum - iStartNum) / 2;
            int iDivResult = num / iMidNum;
            int iModResult = num % iMidNum;
            
            if (iDivResult == iMidNum)
            {
                return iModResult == 0;
            }
            
            if (iDivResult > iMidNum)
            {
                iStartNum = iMidNum + 1;
            }
            else
            {
                iEndNum = iMidNum - 1;
            }
        }
        
        return false;
    }
};

/*

Bug free once !!!

Normal Binary search.

*/
