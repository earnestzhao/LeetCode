class Solution
{
public:

    int evalRPN(vector<string> & tokens)
    {
        stack<int> stackOperand;
        
        for (int iIndex = 0; iIndex < tokens.size(); iIndex ++)
        {
            if (tokens[iIndex].size() > 1 || (tokens[iIndex][0] >= '0' && tokens[iIndex][0] <= '9'))
            {
                stackOperand.push(atoi(tokens[iIndex].c_str()));
            }
            else
            {
                int iOper2 = stackOperand.top(); stackOperand.pop();
                int iOper1 = stackOperand.top(); stackOperand.pop();
                int iOperResult = 0;
                
                switch (tokens[iIndex][0])
                {
                    case '/':
                        iOperResult = iOper1 / iOper2;
                        break;
                    case '-':
                        iOperResult = iOper1 - iOper2;
                        break;
                    case '*':
                        iOperResult = iOper1 * iOper2;
                        break;
                    default:
                        iOperResult = iOper1 + iOper2;
                        break;
                }
                
                stackOperand.push(iOperResult);
            }
        }
        
        return stackOperand.empty() ? 0 : stackOperand.top();
    }
};

/*

Thinking is right, but not bug free, because of the weak thinking about signed number.

Normal stack calculation algorithm.

*/
