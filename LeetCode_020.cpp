class Solution
{
public:

    bool isValid(string s)
    {
        stack<char> stackChecker;
        
        for (int iIndex = 0; iIndex < s.length(); iIndex ++)
        {
            if (s[iIndex] == '(' || s[iIndex] == '[' || s[iIndex] == '{')
            {
                stackChecker.push(s[iIndex]);
            }
            else if (s[iIndex] == ')')
            {
                if (!stackChecker.empty() && stackChecker.top() == '(')
                {
                    stackChecker.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[iIndex] == ']')
            {
                if (!stackChecker.empty() && stackChecker.top() == '[')
                {
                    stackChecker.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[iIndex] == '}')
            {
                if (!stackChecker.empty() && stackChecker.top() == '{')
                {
                    stackChecker.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                
            }
        }
        
        return stackChecker.empty();
    }
};
