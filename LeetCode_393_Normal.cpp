class Solution
{
public:

    bool validUtf8(vector<int> & data)
    {
        int iStatus   = 0;
        int iSegCount = 0;
        
        for (int iIndex = 0; iIndex < data.size(); iIndex ++)
        {
            if ((data[iIndex] & 0x80) == 0)
            {
                if (iStatus != 0)
                {
                    return false;
                }
                
                iStatus   = 0;
                iSegCount = 0;
            }
            else if ((data[iIndex] & 0xE0) == 0xC0)
            {
                if (iStatus != 0)
                {
                    return false;
                }
                
                iStatus   = 1;
                iSegCount = 1;
            }
            else if ((data[iIndex] & 0xF0) == 0xE0)
            {
                if (iStatus != 0)
                {
                    return false;
                }
                
                iStatus   = 1;
                iSegCount = 2;
            }
            else if ((data[iIndex] & 0xF8) == 0xF0)
            {
                if (iStatus != 0)
                {
                    return false;
                }
                
                iStatus   = 1;
                iSegCount = 3;
            }
            else if ((data[iIndex] & 0xC0) == 0x80)
            {
                if (iStatus != 1)
                {
                    return false;
                }
                
                -- iSegCount;
                
                if (iSegCount == 0)
                {
                    iStatus = 0;
                }
            }
            else
            {
                return false;
            }
        }
        
        return iStatus == 0 && iSegCount == 0;
    }
};
