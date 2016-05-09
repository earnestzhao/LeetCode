class Solution
{
public:

	enum { POSITIVE_HIGH_BIT = 0x40000000 };

	int divide(int dividend, int divisor)
	{
		if (divisor == 0)
		{
			return INT_MAX;
		}
		
		if (dividend == 0)
		{
			return 0;
		}
		
		if (dividend > 0 && divisor > 0 && dividend < divisor)
		{
		    return 0;
		}
		
		if (dividend < 0 && divisor < 0 && dividend > divisor)
		{
		    return 0;
		}
		
		long long iPositiveDivend = abs((long long)dividend);
		long long iPositiveDivsor = abs((long long)divisor);
		long long iLongResult     = 0;
		
		if (iPositiveDivend == iPositiveDivsor)
		{
			iLongResult = 1;
		}
		else
		{
			while (iPositiveDivend >= iPositiveDivsor)
			{
				int iLeftMoveBits = 0;
				
				while ((iPositiveDivsor << iLeftMoveBits) <= iPositiveDivend)
				{
					iLeftMoveBits ++;
					
					if ((iPositiveDivsor << (iLeftMoveBits - 1)) & POSITIVE_HIGH_BIT)
					{
						break;
					}
				}
				
				iLeftMoveBits --;
				
				iLongResult += (1 << iLeftMoveBits);
				
				iPositiveDivend -= (iPositiveDivsor << iLeftMoveBits);
			}
		}
		
		int iResult = (int)(iLongResult);
		
		if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
		{
		    if (iResult < 0)
		    {
		        return INT_MAX;
		    }
		    else
		    {
		        return iResult;
		    }
		}
		
		return 0 - iResult;
	}
};
