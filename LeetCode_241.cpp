class Solution
{
public:

    vector<int> diffWaysToCompute(string input)
    {
        if (input.length() <= 0)
        {
            return vector<int>(1, 0);
        }
        
        if (input.length() == 1)
        {
            return vector<int>(1, input[0] - '0');
        }
        
        return dfCompute(input, 0, input.length() - 1);
    }
    
private:

    vector<int> dfCompute(const string & strInput, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex > iEndIndex)
        {
            return vector<int>();
        }
        
        if (iStartIndex == iEndIndex)
        {
            return vector<int>(1, strInput[iStartIndex] - '0');
        }
        
        int iStoreIndex = iStartIndex * strInput.size() + iEndIndex;
        
        map<int, vector<int>>::iterator mapIterator = m_mapComputeResult.find(iStoreIndex);
        
        if (mapIterator != m_mapComputeResult.end())
        {
            return mapIterator -> second;
        }
        
        bool bSingleNumber = true;
        
        vector<int> vecCurrentResult;
        
        for (int iIndex = iStartIndex; iIndex <= iEndIndex; iIndex ++)
        {
            if (strInput[iIndex] == '+' || strInput[iIndex] == '-' || strInput[iIndex] == '*')
            {
                bSingleNumber = false;
                vector<int> vecLeftResult  = dfCompute(strInput, iStartIndex, iIndex - 1);
                vector<int> vecRightResult = dfCompute(strInput, iIndex + 1,  iEndIndex);
                
                for (int jIndex = 0; jIndex < vecLeftResult.size(); jIndex ++)
                {
                    for (int kIndex = 0; kIndex < vecRightResult.size(); kIndex ++)
                    {
                        switch (strInput[iIndex])
                        {
                            case '+': vecCurrentResult.push_back(vecLeftResult[jIndex] + vecRightResult[kIndex]); break;
                            case '-': vecCurrentResult.push_back(vecLeftResult[jIndex] - vecRightResult[kIndex]); break;
                            case '*': vecCurrentResult.push_back(vecLeftResult[jIndex] * vecRightResult[kIndex]); break;
                            default:  return vector<int>();
                        }
                    }
                }
            }
            
            if (iIndex == iEndIndex && bSingleNumber)
            {
                vecCurrentResult.clear();
                vecCurrentResult.push_back(atoi(strInput.substr(iStartIndex, iEndIndex - iStartIndex + 1).c_str()));
            }
        }
        
        m_mapComputeResult[iStoreIndex] = vecCurrentResult;
        return vecCurrentResult;
    }
    
    map<int, vector<int>> m_mapComputeResult;
};

/*

Accepted only once! A great progress! Side condition and compiling are both correct!

When I saw the problem the first time, it seemed to be no directly solution. If no valid thinking about the problem, we can scan all the common alogrithms.

The alogrithm is Divide and Conquer. Choose each operator as divide point, and then follow:

dfCompute(i, j) = append(k) { dfCompute(i, op[k] - 1) op dfCompute(op[k] + 1, j) }, i < k < j, k is the operator index changing by string sequence.

Use map to store all step results for reducing recursion.

*/
