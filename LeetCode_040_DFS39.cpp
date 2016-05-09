class Solution
{
public:

	vector<vector<int>> combinationSum2(vector<int> & candidates, int target)
	{
		vector<int> vecCombination;
		
		set<vector<int>> setFinalResult;
		
		vector<vector<int>> vecFinalResult;
		
		sort(candidates.begin(), candidates.end());
		
		if (target > 0 && candidates.size() > 0)
		{
			combinationSumDFS(candidates, 0, target, setFinalResult, vecCombination);
		}
		
		for (set<vector<int>>::iterator setIterator = setFinalResult.begin(); setIterator != setFinalResult.end(); setIterator ++)
		{
			vecFinalResult.push_back(*setIterator);
		}
		
		return vecFinalResult;
    }
	
private:

	void combinationSumDFS(vector<int> & vecCandidates, int iIndex, int iTarget, set<vector<int>> & setResult, vector<int> & vecCombination)
	{
		if (iIndex >= vecCandidates.size())
		{
			return;
		}
		
		vecCombination.push_back(vecCandidates[iIndex]);
		
		int iTargetLeft = iTarget - vecCandidates[iIndex];
		
		if (iTargetLeft == 0)
		{
			setResult.insert(vecCombination);
		}
		else if (iTargetLeft > 0)
		{
			combinationSumDFS(vecCandidates, iIndex + 1, iTargetLeft, setResult, vecCombination);
		}
		else
		{
			
		}
		
		vecCombination.pop_back();
		
		combinationSumDFS(vecCandidates, iIndex + 1, iTarget, setResult, vecCombination);
	}
};

/*

This one has a same method as LeetCode.039. 

*/
