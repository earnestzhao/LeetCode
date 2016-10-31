class Solution
{
public:

    string removeKdigits(string num, int k)
    {
        if (num.length() <= k)
        {
            return "0";
        }
        
        string strResult;
        
        for (int iIndex = 0; iIndex < num.length();)
        {
            if (!strResult.empty() && num[iIndex] < strResult[strResult.length() - 1] && k -- > 0)
            {
                strResult.pop_back();
            }
            else
            {
                if (!strResult.empty() || num[iIndex] != '0')
                {
                    strResult.push_back(num[iIndex]);
                }
                
                iIndex ++;
            }
        }
        
        while (k -- > 0)
        {
            strResult.pop_back();
        }
        
        if (strResult.empty())
        {
            strResult = "0";
        }
        
        return strResult;
    }
};

/*

Thinking is exactly right, but a lot of bugs occured.

If a digit is less than the previous one, then, delete the previous one.

Take care of edge conditions !!!

*/
