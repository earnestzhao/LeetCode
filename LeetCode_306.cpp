class Solution
{
public:

    bool isAdditiveNumber(string num)
    {
        if (num.length() < 3)
        {
            return false;
        }
        
        for (int iFirstLength = 1; iFirstLength <= num.length() / 2; iFirstLength ++)
        {
            for (int iSecondLength = 1; max(iFirstLength, iSecondLength) <= num.length() - iFirstLength - iSecondLength; iSecondLength ++)
            {
                int iStartIndex = 0, iLeftLength = iFirstLength, iRightLength = iSecondLength;
                
                while (true)
                {
                    int iNextRightLength = ValidAdditiveNextLength(num, iStartIndex, iLeftLength, iRightLength);
                    
                    if (iNextRightLength < 0)
                    {
                        break;
                    }
                    else
                    {
                        if (iStartIndex + iLeftLength + iRightLength + iNextRightLength == num.length())
                        {
                            return true;
                        }
                        
                        iStartIndex  = iStartIndex + iLeftLength;
                        iLeftLength  = iRightLength;
                        iRightLength = iNextRightLength;
                    }
                }
            }
        }
        
        return false;
    }
    
private:

    int max(int x, int y)
    {
        return x > y ? x : y;
    }
    
    int ValidAdditiveNextLength(const string & num, int iStartIndex, int iLeftLength, int iRightLength)
    {
        int iLeftStartIndex  = iStartIndex;
        int iLeftEndIndex    = iLeftStartIndex + iLeftLength - 1;
        
        int iRightStartIndex = iLeftEndIndex + 1;
        int iRightEndIndex   = iRightStartIndex + iRightLength - 1;
        
        if ((num[iLeftStartIndex] == '0' && iLeftLength > 1) || (num[iRightStartIndex] == '0' && iRightLength > 1))
        {
            return -1;
        }
        
        int iLowPlus     = 0;
        string strResult = "";
        
        for (int iIndex = iLeftEndIndex, jIndex = iRightEndIndex; iIndex >= iLeftStartIndex && jIndex >= iRightStartIndex; iIndex --, jIndex --)
        {
            int iCurrent = num[iIndex] - '0' + num[jIndex] - '0' + iLowPlus;
            
            if (iCurrent >= 10)
            {
                iLowPlus = 1;
                strResult.push_back('0' + iCurrent - 10);
            }
            else
            {
                iLowPlus = 0;
                strResult.push_back('0' + iCurrent);
            }
        }

        int iDstStartIndex = iLeftLength > iRightLength ? iLeftStartIndex            : iRightStartIndex;
        int iDstLength     = iLeftLength > iRightLength ? iLeftLength - iRightLength : iRightLength - iLeftLength;
        
        for (int iIndex = iDstStartIndex + iDstLength - 1; iIndex >= iDstStartIndex; iIndex --)
        {
            int iCurrent = num[iIndex] - '0' + iLowPlus;
            
            if (iCurrent >= 10)
            {
                iLowPlus = 1;
                strResult.push_back('0' + iCurrent - 10);
            }
            else
            {
                iLowPlus = 0;
                strResult.push_back('0' + iCurrent);
            }
        }
        
        if (iLowPlus)
        {
            strResult.push_back('1');
        }
        
        if (iRightEndIndex + strResult.length() >= num.length())
        {
            return -2;
        }
        
        for (int iIndex = 0; iIndex < strResult.length(); iIndex ++)
        {
            if (num[iRightEndIndex + strResult.length() - iIndex] != strResult[iIndex])
            {
                return -3;
            }
        }
        
        return strResult.length();
    }
};

/*

坑死了，枚举暴力算法……

在一个题没有很好的通用解法的时候，或者想到这个题的平凡算法已经有一定难度的时候，枚举暴力算法也许是唯一的选择……

个人很讨厌这种题，不锻炼思维，不过倒是锻炼判断力，哪个题需要用什么方法，可以通过交叉练习来准确判断。

边界条件没把握好，确实该打！这里面有一个点需要记住 iStartIndex + iLength = iEndIndex + 1，而 iStartIndex + iLength - 1 = iEndIndex

把握清楚边界就不会出错了

*/
