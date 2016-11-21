
char * aszNumberLT20[] =
{
    "Zero",   "One",    "Two",      "Three",    "Four",    "Five",    "Six",       "Seven",    "Eight",   "Nine",   "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

char * aszNumber2090[] =
{
    "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};


class Solution
{
public:

    string numberToWords(int num)
    {
        string strResult;
        
        if (num >= 1000000000)
        {
            strResult += numberToWordsLT1000(num / 1000000000) + " Billion";
            num %= 1000000000;
        }
        
        if (num >= 1000000)
        {
            if (!strResult.empty())
            {
                strResult.push_back(' ');
            }
            
            strResult += numberToWordsLT1000(num / 1000000) + " Million";
            num %= 1000000;
        }
        
        if (num >= 1000)
        {
            if (!strResult.empty())
            {
                strResult.push_back(' ');
            }
            
            strResult += numberToWordsLT1000(num / 1000) + " Thousand";
            num %= 1000;
        }
        
        if (num > 0 || strResult.empty())
        {
            if (!strResult.empty())
            {
                strResult.push_back(' ');
            }
            
            strResult += numberToWordsLT1000(num);
        }
        
        return strResult;
    }
    
private:

    string numberToWordsLT1000(int iNumber)
    {
        if (iNumber == 0)
        {
            return "Zero";
        }
        
        string strResult;
        
        if (iNumber >= 100)
        {
            strResult.append(aszNumberLT20[iNumber / 100]);
            strResult.append(" Hundred");
            iNumber %= 100;
        }
        
        if (iNumber > 20)
        {
            if (!strResult.empty())
            {
                strResult.push_back(' ');
            }
            
            strResult.append(aszNumber2090[iNumber / 10 - 2]);
            iNumber %= 10;
        }
        
        if (iNumber > 0)
        {
            if (!strResult.empty())
            {
                strResult.push_back(' ');
            }
            
            strResult.append(aszNumberLT20[iNumber]);
        }
        
        return strResult;
    }
};

/*

Notice !!! Zero Edge !!!

*/
