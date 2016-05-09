#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
    public:
    
    bool wordPattern(string pattern, string str)
    {
        vector<string> vecSepStr;
        
        for (unsigned uiIndex = 0, ujIndex = 0; ujIndex < str.length(); ujIndex ++)
        {
            if (str[ujIndex] == ' ')
            {
                if (uiIndex < ujIndex)
                {
                    vecSepStr.push_back(str.substr(uiIndex, ujIndex - uiIndex));
                }
                
                uiIndex = ujIndex + 1;
            }
			
			if (ujIndex == str.length() - 1)
			{
				if (uiIndex <= ujIndex)
                {
					vecSepStr.push_back(str.substr(uiIndex, ujIndex - uiIndex + 1));
                }
			}
        }
        
        if (vecSepStr.size() != pattern.length())
        {
            return false;
        }
        
        map<char, string> mapPatternToStr;
        map<string, char> mapStrToPattern;
        
        for (unsigned uiIndex = 0; uiIndex < pattern.length(); uiIndex ++)
        {
            map<string, char>::iterator mitSTP = mapStrToPattern.find(vecSepStr[uiIndex]);
            
            if (mitSTP != mapStrToPattern.end())
            {
                if (mitSTP -> second != pattern[uiIndex])
                {
                    return false;
                }
            }
            else
            {
                mapStrToPattern[vecSepStr[uiIndex]] = pattern[uiIndex];
            }
            
            map<char, string>::iterator mitPTS = mapPatternToStr.find(pattern[uiIndex]);
            
            if (mitPTS != mapPatternToStr.end())
            {
                if (mitPTS -> second != vecSepStr[uiIndex])
                {
                    return false;
                }
            }
            else
            {
                mapPatternToStr[pattern[uiIndex]] = vecSepStr[uiIndex];
            }
        }
        
        return true;
    }
};
