class Solution
{
public:

    string simplifyPath(string path)
    {
        string strResult;
        
        vector<int> vecLayerIndex;
        
        path.push_back('/');
        
        for (int iIndex = 0; iIndex < path.length(); iIndex ++)
        {
            if (path[iIndex] == '/')
            {
                if (iIndex >= 3 && path[iIndex - 1] == '.' && path[iIndex - 2] == '.' && path[iIndex - 3] == '/')
                {
                    if (vecLayerIndex.size() <= 1)
                    {
                        strResult = "/";
                        vecLayerIndex.clear();
                        vecLayerIndex.push_back(0);
                    }
                    else
                    {
                        int iPrevLayerIndex = vecLayerIndex[vecLayerIndex.size() - 2];
                        strResult = strResult.substr(0, iPrevLayerIndex + 1);
                        vecLayerIndex.pop_back();
                    }
                }
                else if (iIndex >= 2 && path[iIndex - 1] == '.' && path[iIndex - 2] == '/')
                {
                    strResult.pop_back();
                }
                else if (iIndex >= 1 && path[iIndex - 1] == '/')
                {
                    
                }
                else
                {
                    strResult.push_back(path[iIndex]);
                    vecLayerIndex.push_back(strResult.length() - 1);
                }
            }
            else
            {
                strResult.push_back(path[iIndex]);
            }
        }
        
        if (strResult != "/")
        {
            strResult.pop_back();
        }
        
        return strResult;
    }
};

/*

Thinking is right, but do not think about invalid condition. Too many bugs...

Normal algorithm. Travesal from beginning to the end, if current charactor is '/', analyse all conditions.

Add a '/' as a last charactor to raw string, so that the processing logic is same.

*/
