class Solution
{
public:

	int calculate(string s)
	{
		stack<int>  stackOper;
		stack<char> stackSign;
		bool bOperAppending = false;
		
		for (int iIndex = 0; iIndex < s.length(); iIndex ++)
		{
			if (s[iIndex] >= '0' && s[iIndex] <= '9')
			{
				if (bOperAppending)
				{
					stackOper.top() = stackOper.top() * 10 + (int)(s[iIndex] - '0');
				}
				else
				{
					stackOper.push((int)(s[iIndex] - '0'));
				}
				
				bOperAppending = true;
			}
			
			if (s[iIndex] == '+' || s[iIndex] == '-' || s[iIndex] == '(')
			{
				bOperAppending = false;
				stackSign.push(s[iIndex]);
			}
			
			if (s[iIndex] == ')')
			{
				bOperAppending = false;
				
				while (stackSign.top() != '(')
				{
					int iOper2 = stackOper.top(); stackOper.pop();
					int iOper1 = stackOper.top(); stackOper.pop();
					char cSign = stackSign.top(); stackSign.pop();
					
					if (stackSign.top() == '-')
					{
						if (cSign == '+')
						{
							cSign = '-';
						}
						else
						{
							cSign = '+';
						}
					}
					
					int iCurrResult = 0;
					
					if (cSign == '-')
					{
						iCurrResult = iOper1 - iOper2;
					}
					else
					{
						iCurrResult = iOper1 + iOper2;
					}
					
					stackOper.push(iCurrResult);
				}
				
				if (stackSign.top() == '(')
				{
					stackSign.pop();
				}
			}
		}
		
		while (stackSign.size() > 0)
		{
			int iOper2 = stackOper.top(); stackOper.pop();
			int iOper1 = stackOper.top(); stackOper.pop();
			char cSign = stackSign.top(); stackSign.pop();
			
			if (stackSign.size() > 0 && stackSign.top() == '-')
			{
				if (cSign == '+')
				{
					cSign = '-';
				}
				else
				{
					cSign = '+';
				}
			}
			
			int iCurrResult = 0;
			
			if (cSign == '-')
			{
				iCurrResult = iOper1 - iOper2;
			}
			else
			{
				iCurrResult = iOper1 + iOper2;
			}
			
			stackOper.push(iCurrResult);
		}
		
		return stackOper.top();
    }
};

/*

Method of thinking is right, but too many bugs. Including:

1. STL stack edge judgement. stack::top method can be called only when stack::size is positive.

2. When only one operand in brackets, pop 2 operands from stackOper.

3. Stack sequence is from end to beginning, so the result of any 2 operands part is affacted by pre-operator.

If the pre-operator is MINUS, we should change the current operator to an opposite one.


Use 2 stacks to calculate middle sequence expression. One stack is called operand stack (stackOper), the other is called operator stack (stackSign).

When the travesal meets number, then, collect it and put it in stackOper, otherwise, push it into stackSign.

If the travesal meets left bracket, push it into stackSign. If meets right bracket, calculate the expression until it reaches left bracket.

Final, calculate the expression without brackets, and the result is the top element of stackOper.

There maybe exist a better solution, research and do it later.

*/
