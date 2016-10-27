class Solution
{
public:

    string decodeString(string s)
    {
        stack<string> stackDecoder;
        stackDecoder.push("");
        
        for (int iIndex = 0; iIndex < s.length(); iIndex ++)
        {
            if (s[iIndex] >= '0' && s[iIndex] <= '9')
            {
                if (stackDecoder.top().empty())
                {
                    stackDecoder.push("");
                }
                else
                {
                    char cStackTopLast = stackDecoder.top()[stackDecoder.top().length() - 1];
                    
                    if (cStackTopLast < '0' || cStackTopLast > '9')
                    {
                        stackDecoder.push("");
                    }
                }
                
                stackDecoder.top().push_back(s[iIndex]);
            }
            else if (s[iIndex] == '[')
            {
                stackDecoder.push("");
            }
            else if (s[iIndex] == ']')
            {
                string strChars = stackDecoder.top(); stackDecoder.pop();
                string strTimes = stackDecoder.top(); stackDecoder.pop();
                
                for (int iTimes = atoi(strTimes.c_str()); iTimes > 0; iTimes --)
                {
                    stackDecoder.top().append(strChars);
                }
            }
            else
            {
                stackDecoder.top().push_back(s[iIndex]);
            }
        }
        
        return stackDecoder.top();
    }
};
