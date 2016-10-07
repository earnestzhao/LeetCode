/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger
 * {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution
{
public:

    NestedInteger deserialize(string s)
    {
        return deserialize(s, 0, s.length() - 1);
    }
    
private:

    NestedInteger deserialize(string & strSrc, int iStartIndex, int iEndIndex)
    {
        if (strSrc[iStartIndex] != '[' && strSrc[iStartIndex] != ',')
        {
            return NestedInteger(atoi(strSrc.substr(iStartIndex, iEndIndex - iStartIndex + 1).c_str()));
        }
        
        if (strSrc[iStartIndex + 1] == ']')
        {
            return NestedInteger();
        }
        
        vector<int> vecDivIndexes;
        
        for (int iCurrHeadIndex = iStartIndex + 1, iCurrTailIndex = iCurrHeadIndex, iCurrEmbeddedCheck = 0; iCurrTailIndex <= iEndIndex; iCurrTailIndex ++)
        {
            if (strSrc[iCurrHeadIndex] != '[')
            {
                if (strSrc[iCurrTailIndex] == ',' || iCurrTailIndex == iEndIndex)
                {
                    vecDivIndexes.push_back(iCurrTailIndex);
                    iCurrHeadIndex = iCurrTailIndex + 1;
                }
            }
            else
            {
                if (iCurrEmbeddedCheck == 0 && (strSrc[iCurrTailIndex] == ',' || iCurrTailIndex == iEndIndex))
                {
                    vecDivIndexes.push_back(iCurrTailIndex);
                    iCurrHeadIndex = iCurrTailIndex + 1;
                }
                else if (strSrc[iCurrTailIndex] == '[')
                {
                    iCurrEmbeddedCheck ++;
                }
                else if (strSrc[iCurrTailIndex] == ']')
                {
                    iCurrEmbeddedCheck --;
                }
                else
                {
                    
                }
            }
        }
        
        NestedInteger stResultLeft;
        NestedInteger stResultRight;
        
        if (vecDivIndexes.size() == 1)
        {
            stResultLeft.add(deserialize(strSrc, iStartIndex + 1, iEndIndex - 1));
        }
        else
        {
            stResultLeft  = deserialize(strSrc, iStartIndex, vecDivIndexes[vecDivIndexes.size() / 2 - 1]);
            stResultRight = deserialize(strSrc, vecDivIndexes[vecDivIndexes.size() / 2 - 1], iEndIndex);
            
            for (int iIndex = 0; iIndex < stResultRight.getList().size(); iIndex ++)
            {
                stResultLeft.add(stResultRight.getList()[iIndex]);
            }
        }
        
        return stResultLeft;
    }
};

/*

Divide and Conquer does not make any optimization (135ms) !!!

The result is different from my analyzation...

Why?

*/
