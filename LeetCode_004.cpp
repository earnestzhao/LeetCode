class Solution
{
public:

	double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2)
	{
		return findMedianSortedArrays(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1);
	}
	
private:

	double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2, int startIndex1, int endIndex1, int startIndex2, int endIndex2)
	{
		int iSize1   = endIndex1 - startIndex1 + 1;
		int iSize2   = endIndex2 - startIndex2 + 1;
		int iMinSize = iSize1 <= iSize2 ? iSize1 : iSize2;
		
		int iMidIndex1 = (iSize1 > 0 ? startIndex1 + (endIndex1 - startIndex1) / 2 : -1);
		int iMidIndex2 = (iSize2 > 0 ? startIndex2 + (endIndex2 - startIndex2) / 2 : -1);
		
		int iMidValuePre1  = (iMidIndex1 >= 0 ? nums1[iMidIndex1] : -1);
		int iMidValuePost1 = (iMidIndex1 >= 0 ? (iSize1 % 2 != 0 ? iMidValuePre1 : nums1[iMidIndex1 + 1]) : -1);
		
		int iMidValuePre2  = (iMidIndex2 >= 0 ? nums2[iMidIndex2] : -1);
		int iMidValuePost2 = (iMidIndex2 >= 0 ? (iSize2 % 2 != 0 ? iMidValuePre2 : nums2[iMidIndex2 + 1]) : -1);
		
		double dMidValue1 = (iMidValuePre1 + iMidValuePost1) / 2.0;
		double dMidValue2 = (iMidValuePre2 + iMidValuePost2) / 2.0;
		
		if (iSize1 <= 0 && iSize2 <= 0)
		{
			return 0.0F;
		}
		
		if (iSize1 <= 0)
		{
			return dMidValue2;
		}
		
		if (iSize2 <= 0)
		{
			return dMidValue1;
		}
		
		if (iSize1 == 1)
		{
			if (iSize2 % 2 == 0)
			{
				if (iMidValuePre1 >= iMidValuePre2 && iMidValuePre1 <= iMidValuePost2)
				{
					return (double)(iMidValuePre1);
				}
				else if (iMidValuePre1 < iMidValuePre2)
				{
					return (double)(iMidValuePre2);
				}
				else
				{
					return (double)(iMidValuePost2);
				}
			}
			else
			{
				if (iMidValuePre1 == iMidValuePre2)
				{
					return (double)(iMidValuePre1);
				}
				else if (iMidValuePre1 < iMidValuePre2)
				{
					return iMidIndex2 - 1 >= 0 && iMidValuePre1 < nums2[iMidIndex2 - 1] ? (nums2[iMidIndex2 - 1] + iMidValuePre2) / 2.0 : (iMidValuePre1 + iMidValuePre2) / 2.0;
				}
				else
				{
					return iMidIndex2 + 1 < nums2.size() && iMidValuePre1 > nums2[iMidIndex2 + 1] ? (nums2[iMidIndex2 + 1] + iMidValuePre2) / 2.0 : (iMidValuePre1 + iMidValuePre2) / 2.0;
				}
			}
		}
		
		if (iSize2 == 1)
		{
			if (iSize1 % 2 == 0)
			{
				if (iMidValuePre2 >= iMidValuePre1 && iMidValuePre2 <= iMidValuePost1)
				{
					return (double)(iMidValuePre2);
				}
				else if (iMidValuePre2 < iMidValuePre1)
				{
					return (double)(iMidValuePre1);
				}
				else
				{
					return (double)(iMidValuePost1);
				}
			}
			else
			{
				if (iMidValuePre2 == iMidValuePre1)
				{
					return (double)(iMidValuePre2);
				}
				else if (iMidValuePre2 < iMidValuePre1)
				{
					return iMidIndex1 - 1 >= 0 && iMidValuePre2 < nums1[iMidIndex1 - 1] ? (nums1[iMidIndex1 - 1] + iMidValuePre1) / 2.0 : (iMidValuePre2 + iMidValuePre1) / 2.0;
				}
				else
				{
					return iMidIndex1 + 1 < nums1.size() && iMidValuePre2 > nums1[iMidIndex1 + 1] ? (nums1[iMidIndex1 + 1] + iMidValuePre1) / 2.0 : (iMidValuePre2 + iMidValuePre1) / 2.0;
				}
			}
		}
		
		if (iMidValuePre1 <= iMidValuePre2 && iMidValuePost1 >= iMidValuePost2)
		{
			return dMidValue2;
		}
		
		if (iMidValuePre2 <= iMidValuePre1 && iMidValuePost2 >= iMidValuePost1)
		{
			return dMidValue1;
		}
		
		// int iUsefulNumber1 = (iSize1 % 2 == 0 ? iSize1 / 2 : iSize1 / 2 + 1);
		// int iUsefulNumber2 = (iSize2 % 2 == 0 ? iSize2 / 2 : iSize2 / 2 + 1);
		
		// if (dMidValue1 > dMidValue2)
		// {	
			// if (iSize1 <= iSize2)
			// {
				// return findMedianSortedArrays(nums1, nums2, startIndex1, startIndex1 + iUsefulNumber1 - 1, startIndex2 + iUsefulNumber2 - 1, endIndex2);
			// }
			// else
			// {
				// return findMedianSortedArrays(nums1, nums2, startIndex1, endIndex1 - iUsefulNumber + 1, startIndex2 + iUsefulNumber, endIndex2);
			// }
		// }
		// else
		// {
			// if (iSize1 <= iSize2)
			// {
				// return findMedianSortedArrays(nums1, nums2, iSize1 / 2, endIndex1, startIndex2, startIndex2 + iSize1 / 2);
			// }
			// else
			// {
				// return findMedianSortedArrays(nums1, nums2, startIndex1 + iSize2 / 2, endIndex1, startIndex2, iSize2 / 2);
			// }
		// }
	}
};
