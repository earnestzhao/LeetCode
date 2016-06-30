class Solution
{
public:

    double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2)
    {
        int iListSize1 = nums1.size();
        int iListSize2 = nums2.size();
        
        if (iListSize1 > iListSize2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int iStartIndex = 0;
        int iEndIndex   = iListSize1;
        int iTotalHalf  = (iListSize1 + iListSize2 + 1) >> 1;
        
        while (iStartIndex <= iEndIndex)
        {
            int iMidIndex     = iStartIndex + ((iEndIndex - iStartIndex) >> 1);
            int iAnotherIndex = iTotalHalf - iMidIndex;
            
            if (iAnotherIndex > 0 && iMidIndex < iListSize1 && nums2[iAnotherIndex - 1] > nums1[iMidIndex])
            {
                iStartIndex = iMidIndex + 1;
            }
            else if (iMidIndex > 0 && iAnotherIndex < iListSize2 && nums1[iMidIndex - 1] > nums2[iAnotherIndex])
            {
                iEndIndex = iMidIndex - 1;
            }
            else
            {
                int iFinalResult1 = INT_MIN;
                
                if (iMidIndex > 0 && iFinalResult1 < nums1[iMidIndex - 1])
                {
                    iFinalResult1 = nums1[iMidIndex - 1];
                }
                
                if (iAnotherIndex > 0 && iFinalResult1 < nums2[iAnotherIndex - 1])
                {
                    iFinalResult1 = nums2[iAnotherIndex - 1];
                }
                
                if ((iListSize1 + iListSize2) & 1)
                {
                    return iFinalResult1;
                }
                
                int iFinalResult2 = INT_MAX;
                
                if (iMidIndex < iListSize1 && nums1[iMidIndex] < iFinalResult2)
                {
                    iFinalResult2 = nums1[iMidIndex];
                }
                
                if (iAnotherIndex < iListSize2 && nums2[iAnotherIndex] < iFinalResult2)
                {
                    iFinalResult2 = nums2[iAnotherIndex];
                }
                
                return (iFinalResult1 + iFinalResult2) / 2.0F;
            }
        }
        
        return -1.0F;
    }
};

/*

https://leetcode.com/discuss/15790/share-my-o-log-min-m-n-solution-with-explanation

*/
