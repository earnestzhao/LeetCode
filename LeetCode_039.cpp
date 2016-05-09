class Solution 
{
public:

	vector<vector<int>> combinationSum(vector<int> & candidates, int target)
	{
		vector<int> vecCombination;
		vector<vector<int>> vecFinalResult;
		
		if (candidates.size() > 0)
		{
			sort(candidates.begin(), candidates.end());
			combinationSumBEIndex(candidates, 0, target, vecFinalResult, vecCombination);
		}
		
		return vecFinalResult;
    }
	
private:

	void combinationSumBEIndex(vector<int> & candidates, int iIndex, int iTarget, vector<vector<int>> & vecResult, vector<int> & vecCombination)
	{
		if (iIndex >= candidates.size())
		{
			return;
		}
		
		vecCombination.push_back(candidates[iIndex]);
		
		int iTargetLeft = iTarget - candidates[iIndex];
		
		if (iTargetLeft == 0)
		{
			vecResult.push_back(vecCombination);
		}
		else if (iTargetLeft > 0)
		{
			combinationSumBEIndex(candidates, iIndex, iTargetLeft, vecResult, vecCombination);
		}
		else
		{
			
		}
		
		vecCombination.pop_back();
		
		combinationSumBEIndex(candidates, iIndex + 1, iTarget, vecResult, vecCombination);
	}
};

/*

I had imaged DFS first, but gave it up after know element could be repeated. FUCK!!!

It has no much different with normal DFS, a little different is:

1. If current element is chosen, then, recurse on the same element list;

2. If current element is not chosen, then, recurse on element list without current element.

*/
