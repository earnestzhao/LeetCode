class Solution
{
public:

    int lastRemaining(int n)
    {
        int iAPFirstItem  = 1;
        int iAPLastItem   = n;
        int iAPItemNumber = n;
        int iAPDistance   = 1;
        
        for (bool bOperFromLeft = true; iAPItemNumber > 1; bOperFromLeft = !bOperFromLeft, iAPItemNumber /= 2, iAPDistance *= 2)
        {
            if (iAPItemNumber % 2)
            {
                iAPFirstItem += iAPDistance;
                iAPLastItem  -= iAPDistance;
            }
            else
            {
                if (bOperFromLeft)
                {
                    iAPFirstItem += iAPDistance;
                }
                else
                {
                    iAPLastItem -= iAPDistance;
                }
            }
        }
        
        return iAPFirstItem;
    }
};

/*

Thinking is right, and bug free, fantastic !!! But cost long time ...

Using arithmetic progression as a way to calculate. It is an arithmetic progression after each operation.

You can calculate each AP[i] by each AP[i-1].

Optimization on line 12: iAPItemNumber >>= 1, iAPDistance <<= 1

*/
