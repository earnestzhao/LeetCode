struct StrInfo
{
	int iAbstract;

	int iLength;

	int iLetterNum;
	
	StrInfo() : iAbstract(0), iLength(0), iLetterNum(0)
	{
	
	}
	
	void SetLetter(char cLetter)
	{
		if (!IsLetterSet(cLetter))
		{
			iAbstract |= (1 << (cLetter - 'a'));
			iLetterNum ++;
		}
		
		iLength ++;
	}
	
	bool IsLetterSet(char cLetter)
	{
		return (iAbstract & (1 << (cLetter - 'a')));
	}
};


bool StrInfoGreater(const StrInfo & stOper1, const StrInfo & stOper2)
{
	if (stOper1.iLength == stOper2.iLength)
	{
		return stOper1.iLetterNum < stOper2.iLetterNum;
	}
	
	return stOper1.iLength > stOper2.iLength;
};


class Solution
{
public:

	int maxProduct(vector<string> & words)
	{
		vector<StrInfo> vecWordInfoList;
		
		for (int iIndex = 0; iIndex < words.size(); iIndex ++)
		{
			StrInfo stStrInfo;
			
			for (int jIndex = 0; jIndex < words[iIndex].length(); jIndex ++)
			{
				stStrInfo.SetLetter(words[iIndex][jIndex]);
			}
			
			vecWordInfoList.push_back(stStrInfo);
		}
		
		sort(vecWordInfoList.begin(), vecWordInfoList.end(), StrInfoGreater);
		
		int iMaxProductResult = 0;
		
		for (int iIndex = 0; iIndex < vecWordInfoList.size(); iIndex ++)
		{
			for (int jIndex = iIndex + 1; jIndex < vecWordInfoList.size(); jIndex ++)
			{
				if ((vecWordInfoList[iIndex].iAbstract & vecWordInfoList[jIndex].iAbstract) == 0)
				{
					int iCurrentResult = vecWordInfoList[iIndex].iLength * vecWordInfoList[jIndex].iLength;
					
					if (iCurrentResult > iMaxProductResult)
					{
						iMaxProductResult = iCurrentResult;
						break;
					}
				}
			}
		}
		
		return iMaxProductResult;
    }
};

/*

一次成功，大赞！

几个优化点也值得后续注意：用位运算判断是否有重复；合理排序（第一长度大优先，第二含有字母数少优先）；合理剪枝（遇到一个结果后这一行就不用看了）

后面注意一定要先想后做！法宝！嘿嘿！

*/
