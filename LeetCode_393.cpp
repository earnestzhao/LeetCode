class Solution
{
public:

    bool validUtf8(vector<int> & data)
    {
        if (data.size() <= 0)
        {
            return true;
        }
        
        vector<bool> vecValidList;
        
        for (int iIndex = 0; iIndex < data.size(); iIndex ++)
        {
            vecValidList.push_back(false);
            
            if (iIndex <= 3 && validSingleUtf8(data, 0, iIndex))
            {
                vecValidList[iIndex] = true;
            }
            
            else if (iIndex >= 1 && vecValidList[iIndex - 1] && validSingleUtf8(data, iIndex, iIndex))
            {
                vecValidList[iIndex] = true;
            }
            
            else if (iIndex >= 2 && vecValidList[iIndex - 2] && validSingleUtf8(data, iIndex - 1, iIndex))
            {
                vecValidList[iIndex] = true;
            }
            
            else if (iIndex >= 3 && vecValidList[iIndex - 3] && validSingleUtf8(data, iIndex - 2, iIndex))
            {
                vecValidList[iIndex] = true;
            }
            
            else if (iIndex >= 4 && vecValidList[iIndex - 4] && validSingleUtf8(data, iIndex - 3, iIndex))
            {
                vecValidList[iIndex] = true;
            }
        }
        
        return vecValidList[vecValidList.size() - 1];
    }
    
private:

    bool validSingleUtf8(vector<int> & vecData, int iStartIndex, int iEndIndex)
    {
        if (iEndIndex == iStartIndex)
        {
            return (vecData[iStartIndex] & 0x80) == 0;
        }
        
        if (iEndIndex == iStartIndex + 1)
        {
            return (vecData[iStartIndex] & 0xE0) == 0xC0 && (vecData[iStartIndex + 1] & 0xC0) == 0x80;
        }
        
        if (iEndIndex == iStartIndex + 2)
        {
            return (vecData[iStartIndex] & 0xF0) == 0xE0 && (vecData[iStartIndex + 1] & 0xC0) == 0x80 && (vecData[iStartIndex + 2] & 0xC0) == 0x80;
        }
        
        if (iEndIndex == iStartIndex + 3)
        {
            return (vecData[iStartIndex] & 0xF8) == 0xF0 && (vecData[iStartIndex + 1] & 0xC0) == 0x80 && (vecData[iStartIndex + 2] & 0xC0) == 0x80 && (vecData[iStartIndex + 3] & 0xC0) == 0x80;
        }
        
        return false;
    }
};

/*

Normal Dynamic programming.

*/
