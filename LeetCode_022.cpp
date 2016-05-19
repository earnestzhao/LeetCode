class Solution
{
public:

    vector<string> generateParenthesis(int n)
    {
        set<string>    setResult;
        vector<string> vecResult;
        generateParenthesis(n, setResult);
        
        for (set<string>::iterator setIterator = setResult.begin(); setIterator != setResult.end(); setIterator ++)
        {
            vecResult.push_back(*setIterator);
        }
        
        return vecResult;
    }
    
private:

    void generateParenthesis(int iNumber, set<string> & setResult)
    {
        if (iNumber <= 0)
        {
            return;
        }
        
        if (iNumber == 1)
        {
            setResult.insert("()");
            return;
        }
        
        set<string> setPrevResult;
        
        generateParenthesis(iNumber - 1, setPrevResult);
        
        for (set<string>::iterator setIterator = setPrevResult.begin(); setIterator != setPrevResult.end(); setIterator ++)
        {
            for (int iIndex = 0; iIndex < (*setIterator).length(); iIndex ++)
            {
                setResult.insert((*setIterator).substr(0, iIndex) + "()" + (*setIterator).substr(iIndex));
            }
            
            setResult.insert((*setIterator) + "()");
        }
    }
};

/*

Thinking about recursive is right, but wrong on combination...

I thought add "()" or wider "()" on right side, left side, and whole... lost a lot of special conditions...

Normal Algorithm:

1. Exit condition.

2. Recursive on n - 1.

3. For each string on R(n-1) result, add "()" in middle space of each two neighbour charactors.

There must be better solutions. Research it later.

*/
