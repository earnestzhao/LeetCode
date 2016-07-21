// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution
{
public:

    int guessNumber(int n)
    {
        int iMinNumber = 1;
        int iMaxNumber = n;
        
        while (iMinNumber <= iMaxNumber)
        {
            int iMidNumber   = iMinNumber + (iMaxNumber - iMinNumber) / 2;
            int iGuessResult = guess(iMidNumber);
            
            if (iGuessResult == 0)
            {
                return iMidNumber;
            }
            
            if (iGuessResult == 1)
            {
                iMinNumber = iMidNumber + 1;
            }
            else
            {
                iMaxNumber = iMidNumber - 1;
            }
        }
        
        return -1;
    }
};
