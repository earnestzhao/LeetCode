
/*

186. Reverse Words in a String II

Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,

Given s = "the sky is blue",

return "blue is sky the".

Could you do it in-place without allocating extra space?

*/

class Solution
{
public:

    void reverseWords(string & s)
    {
        reverse(s.begin(), s.end());
        
        s.push_back(' ');
        
        for (string::iterator sitSearch = s.begin(), sitWord = s.begin(); sitSearch != s.end(); sitSearch ++)
        {
            if (*sitSearch == ' ')
            {
                reverse(sitWord, sitSearch);
                sitWord = sitSearch;
                sitWord ++;
            }
        }
        
        s.pop_back();
    }
};
