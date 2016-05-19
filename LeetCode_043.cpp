class Solution
{
public:

    string multiply(string num1, string num2)
    {
        string & strShort  = num1.size() <  num2.size() ? num1 : num2;
        string & strLong   = num1.size() >= num2.size() ? num1 : num2;
        string   strResult = "0";
        
        reverse(strShort.begin(), strShort.end());
        reverse(strLong .begin(), strLong .end());
        
        for (int iIndex = 0, iFactor = 0; iIndex < strShort.size(); iIndex ++, iFactor ++)
        {
            if (strShort[iIndex] == '0')
            {
                continue;
            }
            
            string strSingleResult = multiBySingleNumber(strLong, strShort[iIndex]);
            
            for (int jIndex = 0; jIndex < iFactor; jIndex ++)
            {
                strSingleResult = string("0") + strSingleResult;
            }
            
            strResult = plus(strResult, strSingleResult);
        }
        
        reverse(strResult.begin(), strResult.end());
        return strResult;
    }
    
private:

    string plus(const string & strRevNum1, const string & strRevNum2)
    {
        if (strRevNum1 == "0")
        {
            return strRevNum2;
        }
        
        if (strRevNum2 == "0")
        {
            return strRevNum1;
        }
        
        const string & strShort = strRevNum1.size() <  strRevNum2.size() ? strRevNum1 : strRevNum2;
        const string & strLong  = strRevNum1.size() >= strRevNum2.size() ? strRevNum1 : strRevNum2;
        
        int  iShortIndex   = 0;
        char cResultNextUp = 0;
        string strResult   = "";
        
        for (; iShortIndex < strShort.size(); iShortIndex ++)
        {
            char cResult  = strShort[iShortIndex] - '0' + strLong[iShortIndex] - '0' + cResultNextUp;
            cResultNextUp = cResult / 10;
            strResult.push_back(cResult % 10 + '0');
        }
        
        for (int iIndex = iShortIndex; iIndex < strLong.size(); iIndex ++)
        {
            char cResult  = strLong[iIndex] - '0' + cResultNextUp;
            cResultNextUp = cResult / 10;
            strResult.push_back(cResult % 10 + '0');
        }
        
        if (cResultNextUp > 0)
        {
            strResult.push_back(cResultNextUp + '0');
        }
        
        if (strResult.empty())
        {
            strResult = "0";
        }
        
        return strResult;
    }
    
    string multiBySingleNumber(const string & strRevNum, char cSingleNum)
    {
        if (cSingleNum == '0')
        {
            return "0";
        }
        
        if (cSingleNum == '1')
        {
            return strRevNum;
        }
        
        if (strRevNum == "0")
        {
            return "0";
        }
        
        if (strRevNum == "1")
        {
            return string(1, cSingleNum);
        }
        
        char cResultNextUp = 0;
        string strResult   = "";
        
        for (int iIndex = 0; iIndex < strRevNum.size(); iIndex ++)
        {
            char cResult  = (strRevNum[iIndex] - '0') * (cSingleNum - '0') + cResultNextUp;
            cResultNextUp = cResult / 10;
            strResult.push_back(cResult % 10 + '0');
        }
        
        if (cResultNextUp > 0)
        {
            strResult.push_back(cResultNextUp + '0');
        }
        
        if (strResult.empty())
        {
            strResult = "0";
        }
        
        return strResult;
    }
};

/*

Thinking is right, not bug free, and too long code.

Normal big integer multiply.

*/
