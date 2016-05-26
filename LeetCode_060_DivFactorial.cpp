class Solution
{
public:

    string getPermutation(int n, int k)
    {
        if (n <= 0 || k <= 0)
        {
            return "";
        }
        
        int iPermutationNumber = 1;
        
        for (int iIndex = 2; iIndex < n; iIndex ++)
        {
            iPermutationNumber *= iIndex;
        }
        
        set<int> vecUnvisited;
        
        for (int iIndex = 1; iIndex <= n; iIndex ++)
        {
            vecUnvisited.insert(iIndex);
        }
        
        string strResult;
        
        for (int iFactor = n - 1; !vecUnvisited.empty();)
        {
            int iCurrentPosDivQuo = k / iPermutationNumber;
            int iCurrentPosDivRem = k % iPermutationNumber;
            int iCurrentPos       = 0;
            
            if (iCurrentPosDivRem == 0)
            {
                iCurrentPosDivQuo --;
            }
            
            set<int>::iterator setIterator = vecUnvisited.begin();
                
            for (int iSeq = 0; iSeq < iCurrentPosDivQuo; iSeq ++)
            {
                setIterator ++;
            }
            
            iCurrentPos = *setIterator;
            
            strResult.push_back((char)('0' + *setIterator));
            
            vecUnvisited.erase(*setIterator);
            
            if (iCurrentPosDivRem == 0)
            {
                k = iPermutationNumber;
            }
            else
            {
                k %= iPermutationNumber;
            }
            
            if (iFactor > 1)
            {
                iPermutationNumber /= (iFactor --);
            }
        }
        
        return strResult;
    }
};

/*

First using backtrack, but 'Time Limit Exceeded'.

Next thinking is right, but a lot of bugs.

1. A full permutation of 'n elements' has n! results.

2. The results must in order from min to max.

3. So, we can consider which one is the result by k.

4. The ceil(k / (iFactor - 1)!)-th biggest number which is not visited is the current position number.

5. Then, let k = k % (iFactor - 1)!, if k == 0, then, let k = (iFactor - 1)!

6. Then, iFactor --. Loop until all elements are visited.

Main point: divide each factorial number to calculate expect element.

*/
