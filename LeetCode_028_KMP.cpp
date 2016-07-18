class Solution
{
public:

    int strStr(string haystack, string needle)
    {
        return KMP(haystack, needle);
    }
    
private:

    void buildKMPNext(const string & strPattern, vector<int> & vecNext)
    {
        vecNext.clear();
        
        if (strPattern.empty())
        {
            return;
        }
        
        vecNext.push_back(0);
        
        for (int iBuildPosition = 1, iHeadMatchPosition = 0; iBuildPosition < strPattern.size(); iBuildPosition ++)
        {
            while (iHeadMatchPosition > 0 && strPattern[iBuildPosition] != strPattern[iHeadMatchPosition])
            {
                iHeadMatchPosition = vecNext[iHeadMatchPosition - 1];
            }
            
            if (strPattern[iBuildPosition] == strPattern[iHeadMatchPosition])
            {
                iHeadMatchPosition ++;
            }
            
            vecNext.push_back(iHeadMatchPosition);
        }
    }


    int KMP(const string & strSource, const string & strPattern)
    {
        if (strPattern.empty())
        {
            return 0;
        }
        
        if (strSource.empty())
        {
            return -1;
        }
        
        vector<int> vecNext;
        
        buildKMPNext(strPattern, vecNext);
        
        for (int iSourceIndex = 0, iPatternIndex = 0; iSourceIndex + strPattern.size() - iPatternIndex - 1 < strSource.size();)
        {
            if (strSource[iSourceIndex] != strPattern[iPatternIndex])
            {
                if (iPatternIndex > 0)
                {
                    iPatternIndex = vecNext[iPatternIndex - 1];
                }
                else
                {
                    iSourceIndex ++;
                }
            }
            else
            {
                if (iPatternIndex == strPattern.length() - 1)
                {
                    return iSourceIndex - strPattern.length() + 1;
                }
                
                iSourceIndex  ++;
                iPatternIndex ++;
            }
        }
        
        return -1;
    }
};
