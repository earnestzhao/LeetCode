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
        if (strSrc[iStartIndex] != '[')
        {
            return NestedInteger(atoi(strSrc.substr(iStartIndex, iEndIndex - iStartIndex + 1).c_str()));
        }
        
        if (strSrc[iStartIndex + 1] == ']')
        {
            return NestedInteger();
        }
        
        NestedInteger stResult;
        
        for (int iCurrHeadIndex = iStartIndex + 1, iCurrTailIndex = iCurrHeadIndex, iCurrEmbeddedCheck = 0; iCurrTailIndex <= iEndIndex; iCurrTailIndex ++)
        {
            if (strSrc[iCurrHeadIndex] != '[')
            {
                if (strSrc[iCurrTailIndex] == ',' || iCurrTailIndex == iEndIndex)
                {
                    stResult.add(NestedInteger(atoi(strSrc.substr(iCurrHeadIndex, iCurrTailIndex - iCurrHeadIndex + 1).c_str())));
                    iCurrHeadIndex = iCurrTailIndex + 1;
                }
            }
            else
            {
                if (iCurrEmbeddedCheck == 0 && (strSrc[iCurrTailIndex] == ',' || iCurrTailIndex == iEndIndex))
                {
                    stResult.add(deserialize(strSrc, iCurrHeadIndex, iCurrTailIndex - 1));
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
        
        return stResult;
    }
};

/*

Normal Recurision.

Optimization: Reduce a level of recurision. Speed up: 9ms (35ms - 26ms).

*/
