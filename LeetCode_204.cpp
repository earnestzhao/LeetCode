class Solution
{
public:

    int countPrimes(int n)
    {
        int iResultCount = 0;
        
        vector<bool> vecSieveNotPrime(n - 1, false);
        
        for (int iCurrent = 2; iCurrent < n; iCurrent ++)
        {
            if (!vecSieveNotPrime[iCurrent])
            {
                iResultCount ++;
                
                for (long long llGenerate = static_cast<long long>(iCurrent) * iCurrent; llGenerate < n; llGenerate += iCurrent)
                {
                    vecSieveNotPrime[llGenerate] = true;
                }
            }
        }
        
        return iResultCount;
    }
};

/*

Smart !!! Excellent !!! Wonderful !!!

Sieve of Eratosthenes.

https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

*/
