class Solution
{
public:

    int countNumbersWithUniqueDigits(int n)
    {
        int aiResultList[] = { 1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 8877691 };
        
        if (n > 10)
        {
            n = 10;
        }
        
        return aiResultList[n];
    }
};

/*

A smart one !!!

*/
