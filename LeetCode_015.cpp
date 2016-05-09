class Solution
{
public:

	vector< vector<int> > threeSum(vector<int> & nums)
	{
		map<int, int> mapPositiveNumber;
		map<int, int> mapNegativeNumber;
		
		int iZeroNumber  = 0;
		int iPositiveMin = 0x7FFFFFFF, iPositiveMax = 0;
		int iNegativeMin = 0, iNegativeMax = 0x80000001;
		
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			map<int, int> * pmapNumber = NULL;
			
			if (nums[iIndex] > 0)
			{
				pmapNumber = &mapPositiveNumber;
				
				if (nums[iIndex] < iPositiveMin)
				{
					iPositiveMin = nums[iIndex];
				}
				
				if (nums[iIndex] > iPositiveMax)
				{
					iPositiveMax = nums[iIndex];
				}
			}
			else if (nums[iIndex] < 0)
			{
				pmapNumber = &mapNegativeNumber;
				
				if (nums[iIndex] < iNegativeMin)
				{
					iNegativeMin = nums[iIndex];
				}
				
				if (nums[iIndex] > iNegativeMax)
				{
					iNegativeMax = nums[iIndex];
				}
			}
			else
			{
				pmapNumber = NULL;
				iZeroNumber ++;
			}
			
			if (pmapNumber != NULL)
			{
				map<int, int>::iterator mapIterator = pmapNumber -> find(nums[iIndex]);
				
				if (mapIterator != pmapNumber -> end())
				{
					mapIterator -> second ++;
				}
				else
				{
					(*pmapNumber)[nums[iIndex]] = 1;
				}
			}
		}
		
		set<int> setNumChecked;
		set< vector<int> > setResultList;
		
		for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
		{
			if (setNumChecked.find(nums[iIndex]) == setNumChecked.end())
			{
				map<int, int> * pmapCheck1 = NULL;
				map<int, int> * pmapCheck2 = NULL;
				
				if (nums[iIndex] > 0)
				{
					pmapCheck1 = &mapNegativeNumber;
					pmapCheck2 = &mapNegativeNumber;
				}
				else if (nums[iIndex] < 0)
				{
					pmapCheck1 = &mapPositiveNumber;
					pmapCheck2 = &mapPositiveNumber;
				}
				else
				{
					pmapCheck1 = &mapNegativeNumber;
					pmapCheck2 = &mapPositiveNumber;
				}

				if ((nums[iIndex] < 0 && 0 - nums[iIndex] <= iPositiveMax + iPositiveMax && 0 - nums[iIndex] >= iPositiveMin + iPositiveMin)
				 || (nums[iIndex] > 0 && nums[iIndex] <= 0 - iNegativeMin - iNegativeMin && nums[iIndex] >= 0 - iNegativeMax - iNegativeMax)
				 || (nums[iIndex] == 0))
				{
					for (map<int, int>::iterator mapIterator1 = pmapCheck1 -> begin(); mapIterator1 != pmapCheck1 -> end(); mapIterator1 ++)
					{
						map<int, int>::iterator mapIterator2 = pmapCheck2 -> find(0 - nums[iIndex] - mapIterator1 -> first);
						
						if (mapIterator2 != pmapCheck2 -> end() && (mapIterator1 -> first != mapIterator2 -> first || mapIterator2 -> second > 1))
						{
							vector<int> vecResult;
							vecResult.push_back(nums[iIndex]);
							vecResult.push_back(mapIterator1 -> first);
							vecResult.push_back(mapIterator2 -> first);
							sort(vecResult.begin(), vecResult.end());
							setResultList.insert(vecResult);
						}
					}
				}
				
				setNumChecked.insert(nums[iIndex]);
			}
		}
		
		if (iZeroNumber >= 3)
		{
			vector<int> vecResult;
			vecResult.push_back(0);
			vecResult.push_back(0);
			vecResult.push_back(0);
			setResultList.insert(vecResult);
		}
		
		vector< vector<int> > vecResultList;
		
		for (set< vector<int> >::iterator setIterator = setResultList.begin(); setIterator != setResultList.end(); setIterator ++)
		{
			vecResultList.push_back(*setIterator);
		}
		
		return vecResultList;
	}
};
