
// Path Info
struct PathInfo
{
    // Constructor
    PathInfo() : file(false), level(0), length(0), maxPathLength(0)
    {
        
    }
    
    // File
    bool file;
    
    // Level
    int level;
    
    // Length
    int length;
    
    // Result
    int maxPathLength;
};


class Solution
{
public:

    int lengthLongestPath(string input)
    {
        if (input.length() <= 0)
        {
            return 0;
        }
        
        vector<PathInfo> vecPathInfo;
        
        if (!getPathInfo(input, vecPathInfo))
        {
            return 0;
        }
        
        return maxPathLength(vecPathInfo);
    }
    
private:

    bool getPathInfo(string & strInput, vector<PathInfo> & vecPathInfo)
    {
        bool bFileExist = false;
        
        PathInfo stPathInfo;
        vecPathInfo.push_back(stPathInfo);
        
        stPathInfo.file   = false;
        stPathInfo.level  = 1;
        stPathInfo.length = 0;
        
        for (int iCharIndex = 0; iCharIndex < strInput.length(); iCharIndex ++)
        {
            if (strInput[iCharIndex] == '\n')
            {
                if (stPathInfo.length > 0)
                {
                    vecPathInfo.push_back(stPathInfo);
                }
                
                stPathInfo.file   = false;
                stPathInfo.level  = 1;
                stPathInfo.length = 0;
            }
            else if (strInput[iCharIndex] == '\t')
            {
                if (stPathInfo.length <= 0)
                {
                    stPathInfo.level ++;
                }
            }
            else
            {
                stPathInfo.length ++;
                
                if (strInput[iCharIndex] == '.')
                {
                    bFileExist      = true;
                    stPathInfo.file = true;
                }
                
                if (iCharIndex == strInput.length() - 1)
                {
                    vecPathInfo.push_back(stPathInfo);
                }
            }
        }
        
        vecPathInfo.push_back(vecPathInfo[0]);
        return bFileExist;
    }
    
    int maxPathLength(vector<PathInfo> & vecPathInfo)
    {
        stack<int> stackCalculator;
        stackCalculator.push(0);
        
        for (int iIndex = 1; iIndex < vecPathInfo.size();)
        {
            PathInfo & stPathInfoCurrent  = vecPathInfo[iIndex];
            PathInfo & stPathInfoStackTop = vecPathInfo[stackCalculator.top()];
            
            if (stPathInfoCurrent.level >= stPathInfoStackTop.level)
            {
                stackCalculator.push(iIndex ++);
                continue;
            }
            
            vector<int> vecIndexList;
            
            while (vecPathInfo[stackCalculator.top()].level == stPathInfoStackTop.level)
            {
                vecIndexList.push_back(stackCalculator.top());
                stackCalculator.pop();
            }
            
            for (int jIndex = 0; jIndex < vecIndexList.size(); jIndex ++)
            {
                PathInfo & stCurrent  = vecPathInfo[vecIndexList[jIndex]];
                PathInfo & stStackTop = vecPathInfo[stackCalculator.top()];
                
                if (stCurrent.file && stCurrent.maxPathLength == 0)
                {
                    stCurrent.maxPathLength = stCurrent.length;
                }
                
                if (stStackTop.maxPathLength < stCurrent.maxPathLength + stStackTop.length + 1)
                {
                    stStackTop.maxPathLength = stCurrent.maxPathLength + stStackTop.length + 1;
                }
            }
        }
        
        return vecPathInfo[0].maxPathLength - 1;
    }
};

/*

Perfect thinking, but not bug free ...

1. Traverse the input string, build a list of all path of file info of each row.

2. Using stack to build the path or file relation, and get the max path length finally.

*/
