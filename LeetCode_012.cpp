class Solution
{
public:

    string intToRoman(int num)
    {
        string strResult;
        
        int iNumCurrentPart = num;
        
        for (int i = 0; i < iNumCurrentPart / 1000; i++)
        {
            strResult.append("M");
        }
        
        iNumCurrentPart %= 1000;
        
        if (iNumCurrentPart >= 900)
        {
            strResult.append("CM");
            iNumCurrentPart -= 900;
        }
        else if (iNumCurrentPart >= 500 && iNumCurrentPart < 900)
        {
            strResult.append("D");
            iNumCurrentPart -= 500;
        }
        else if (iNumCurrentPart >= 400 && iNumCurrentPart < 500)
        {
            strResult.append("CD");
            iNumCurrentPart -= 400;
        }
        
        for (int i = 0; i < iNumCurrentPart / 100; i++)
        {
            strResult.append("C");
        }
        
        iNumCurrentPart %= 100;
        
        if (iNumCurrentPart >= 90)
        {
            strResult.append("XC");
            iNumCurrentPart -= 90;
        }
        else if (iNumCurrentPart >= 50 && iNumCurrentPart < 90)
        {
            strResult.append("L");
            iNumCurrentPart -= 50;
        }
        else if (iNumCurrentPart >= 40 && iNumCurrentPart < 50)
        {
            strResult.append("XL");
            iNumCurrentPart -= 40;
        }
        
        for (int i = 0; i < iNumCurrentPart / 10; i++)
        {
            strResult.append("X");
        }
            
        iNumCurrentPart %= 10;
        
        if (iNumCurrentPart >= 9)
        {
            strResult.append("IX");
            iNumCurrentPart -= 9;
        }
        else if (iNumCurrentPart >= 5 && iNumCurrentPart < 9)
        {
            strResult.append("V");
            iNumCurrentPart -= 5;
        }
        else if (iNumCurrentPart >= 4 && iNumCurrentPart < 5)
        {
            strResult.append("IV");
            iNumCurrentPart -= 4;
        }
        
        for (int i = 0; i < iNumCurrentPart; i++)
        {
            strResult.append("I");
        }
        
        return strResult;
    }
};
