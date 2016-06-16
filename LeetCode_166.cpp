class Solution
{
public:

    string fractionToDecimal(int numerator, int denominator)
    {
        long long llNumerator   = abs((long long)numerator);
        long long llDenominator = abs((long long)denominator);
        
        ostringstream ossResult;
        ossResult << (((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) ? "-" : "");
        ossResult << llNumerator / llDenominator;
        
        int iIntModValue = llNumerator % llDenominator;
        
        if (iIntModValue == 0)
        {
            return ossResult.str();
        }
        else
        {
            ossResult << ".";
        }
        
        unordered_map<int, int> hmapModValueIndex;
        hmapModValueIndex[iIntModValue] = 0;

        string strFractionalPart;
        int iRecurringBeginIndex = -1;
        int iCurrIndex = 1;
        
        for (long long llCurrDividend = iIntModValue * 10, llCurrModValue = 0; true; iCurrIndex ++)
        {
            strFractionalPart.push_back((char)(llCurrDividend / llDenominator + '0'));
            
            llCurrModValue = llCurrDividend % llDenominator;
            
            if (llCurrModValue == 0)
            {
                break;
            }
            
            unordered_map<int, int>::iterator hmapIterator = hmapModValueIndex.find(llCurrModValue);
            
            if (hmapIterator != hmapModValueIndex.end())
            {
                iRecurringBeginIndex = hmapIterator -> second;
                break;
            }
            
            llCurrDividend = llCurrModValue * 10;
            hmapModValueIndex[llCurrModValue] = iCurrIndex;
        }
        
        if (iRecurringBeginIndex < 0)
        {
            ossResult << strFractionalPart;
        }
        else
        {
            ossResult << strFractionalPart.substr(0, iRecurringBeginIndex) << "(" << strFractionalPart.substr(iRecurringBeginIndex) << ")";
        }
        
        return ossResult.str();
    }
};

/*

Thinking is right, but a lot of bugs which occured on INT_MIN, and signed number.

Using 'long long' type and first judgement on sign to solve them.

Recurring occurs on the same mod value appears. Using a hash map to record the mod values.

Earnest, you must consider INT_MAX or INT_MIN, and non-negative number first anytime !!!

*/
