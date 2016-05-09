class Solution
{
public:

	int calculate(string s)
	{
		stack<int> stackOperand;
		stack<int> stackOperator;
		bool bOperandAppending = false;
		
		for (int iIndex = 0; iIndex < s.length(); iIndex ++)
		{
			if (s[iIndex] >= '0' && s[iIndex] <= '9')
			{
				if (bOperandAppending)
				{
					stackOperand.top() = stackOperand.top() * 10 + (int)(s[iIndex] - '0');
				}
				else
				{
					stackOperand.push((int)(s[iIndex] - '0'));
				}
				
				bOperandAppending = true;
			}
			
			if (s[iIndex] == '+' || s[iIndex] == '-' || s[iIndex] == '*' || s[iIndex] == '/' || iIndex == s.length() - 1)
			{
				bOperandAppending = false;
				
				if (stackOperand.size() >= 2 && stackOperator.size() > 0 && (stackOperator.top() == '*' || stackOperator.top() == '/'))
				{
					int iCurrOper2 = stackOperand.top();  stackOperand.pop();
					int iCurrOper1 = stackOperand.top();  stackOperand.pop();
					int cOperator  = stackOperator.top(); stackOperator.pop();
					
					int iCurrResult = 0;
					
					if (cOperator == '/')
					{
						iCurrResult = iCurrOper1 / iCurrOper2;
					}
					else
					{
						iCurrResult = iCurrOper1 * iCurrOper2;
					}
					
					stackOperand.push(iCurrResult);
				}
				
				if (s[iIndex] == '+' || s[iIndex] == '-' || s[iIndex] == '*' || s[iIndex] == '/')
				{
					stackOperator.push(s[iIndex]);
				}
			}
		}
		
		while (stackOperand.size() >= 2 && stackOperator.size() > 0)
		{
			int iCurrOper2 = stackOperand.top();  stackOperand.pop();
			int iCurrOper1 = stackOperand.top();  stackOperand.pop();
			int cOperator  = stackOperator.top(); stackOperator.pop();
			
			if (stackOperator.size() > 0 && stackOperator.top() == '-')
			{
				if (cOperator == '+')
				{
					cOperator = '-';
				}
				else
				{
					cOperator = '+';
				}
			}
					
			int iCurrResult = 0;
					
			if (cOperator == '-')
			{
				iCurrResult = iCurrOper1 - iCurrOper2;
			}
			else
			{
				iCurrResult = iCurrOper1 + iCurrOper2;
			}
			
			stackOperand.push(iCurrResult);
		}
		
		return stackOperand.top();
    }
};

/*

The same thinking as Problem 224, the same bugs. Including:

1. Using " " makes compile error.

2. Not Judging stackOperand.size() > 0 in loop condition.

3. Put iIndex == s.length() - 1 with operator judgment together, and push it into operator stack.


The same thinking as Problem 224, the only different is calculating MULTI or DIVIDE when it appears immediately.

There maybe better solutions, research it and do it later.

*/
