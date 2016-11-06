class Solution
{
public:

    bool searchMatrix(vector<vector<int>> & matrix, int target)
    {
        if (matrix.size() <= 0 || matrix[0].size() <= 0)
        {
            return false;
        }
        
        int iStartRowIndex = 0;
        int iStartColIndex = 0;
        int iEndRowIndex   = matrix.size()    - 1;
        int iEndColIndex   = matrix[0].size() - 1;
        
        while (iStartRowIndex <= iEndRowIndex && iStartColIndex <= iEndColIndex)
        {
            int iColDstIndex = 0;
            
            if (binarySearch(matrix, target, iStartRowIndex, iStartColIndex, iEndColIndex, true, iColDstIndex))
            {
                return true;
            }
            
            if (iColDstIndex < 0)
            {
                return false;
            }
            
            int iRowDstIndex = 0;
            
            if (binarySearch(matrix, target, iColDstIndex, iStartRowIndex, iEndRowIndex, false, iRowDstIndex))
            {
                return true;
            }
            
            iStartRowIndex = iRowDstIndex + 1;
            iEndColIndex   = iColDstIndex;
        }
        
        return false;
    }
    
private:

    bool binarySearch(vector<vector<int>> & vecMatrix, int iTarget, int iBaseIndex, int iStartIndex, int iEndIndex, bool bOnRow, int & iDstIndex)
    {
        while (iStartIndex <= iEndIndex)
        {
            int iMidIndex = (iStartIndex + iEndIndex) / 2;
            int iMidValue = 0;
            
            if (bOnRow)
            {
                iMidValue = vecMatrix[iBaseIndex][iMidIndex];
            }
            else
            {
                iMidValue = vecMatrix[iMidIndex][iBaseIndex];
            }
            
            if (iMidValue == iTarget)
            {
                iDstIndex = iMidIndex;
                return true;
            }
            
            if (iMidValue < iTarget)
            {
                iStartIndex = iMidIndex + 1;
            }
            else
            {
                iEndIndex = iMidIndex - 1;
            }
        }
        
        iDstIndex = iEndIndex;
        return false;
    }
};
