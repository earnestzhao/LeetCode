class Solution
{
public:

    vector<string> generateParenthesis(int n)
    {
        vector<string> vecResult;
        unordered_set<string> hsetResult;
        generateParenthesis(n, hsetResult);
        
        for (unordered_set<string>::iterator hsetIterator = hsetResult.begin(); hsetIterator != hsetResult.end(); hsetIterator ++)
        {
            vecResult.push_back(*hsetIterator);
        }
        
        return vecResult;
    }
    
private:

    void generateParenthesis(int iNumber, unordered_set<string> & hsetResult)
    {
        if (iNumber <= 0)
        {
            return;
        }
        
        if (iNumber == 1)
        {
            hsetResult.insert("()");
            return;
        }
        
        unordered_set<string> hsetPrevResult;
        
        generateParenthesis(iNumber - 1, hsetPrevResult);
        
        for (unordered_set<string>::iterator hsetIterator = hsetPrevResult.begin(); hsetIterator != hsetPrevResult.end(); hsetIterator ++)
        {
            for (int iInsertIndex = 0; iInsertIndex < (*hsetIterator).length(); iInsertIndex ++)
            {
                if (iInsertIndex >= 2 && (*hsetIterator)[iInsertIndex - 1] == ')' && (*hsetIterator)[iInsertIndex - 2] == '(')
                {
                    continue;
                }
                
                hsetResult.insert((*hsetIterator).substr(0, iInsertIndex) + "()" + (*hsetIterator).substr(iInsertIndex));
            }
            
            hsetResult.insert((*hsetIterator) + string("()"));
        }
    }
};

/*

Two little optimizations.

1. Using hash table.

2. Do not insert "()" in current position where adjacent two characters on left are "()".

*/
