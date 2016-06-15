class Solution
{
public:

    void reverseWords(string & s)
    {
        stack<char> stackWordRev;
        stack<char> stackTotalRev;
        
        for (int iIndex = 0; iIndex < s.length(); iIndex ++)
        {
            if (s[iIndex] == ' ')
            {
                if (!stackWordRev.empty())
                {
                    for (; !stackWordRev.empty(); stackWordRev.pop())
                    {
                        stackTotalRev.push(stackWordRev.top());
                    }
                    
                    stackTotalRev.push(' ');
                }
            }
            else
            {
                stackWordRev.push(s[iIndex]);
            }
        }
        
        for (; !stackWordRev.empty(); stackWordRev.pop())
        {
            stackTotalRev.push(stackWordRev.top());
        }
        
        if (!stackTotalRev.empty() && stackTotalRev.top() == ' ')
        {
            stackTotalRev.pop();
        }
        
        s.clear();
        
        for (; !stackTotalRev.empty(); stackTotalRev.pop())
        {
            s.push_back(stackTotalRev.top());
        }
    }
};
