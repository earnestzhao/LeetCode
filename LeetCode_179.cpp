
bool greaterThan(const string & strOper1, const string & strOper2)
{
    string strFirst1 = strOper1 + strOper2;
    string strFirst2 = strOper2 + strOper1;
    return strFirst1.compare(strFirst2) > 0;
}

class Solution
{
public:

    string largestNumber(vector<int> & nums)
    {
        vector<string> vecNumList;
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            ostringstream ossIntToStr;
            ossIntToStr << nums[iIndex];
            vecNumList.push_back(ossIntToStr.str());
        }
        
        sort(vecNumList.begin(), vecNumList.end(), greaterThan);
        
        ostringstream ossFinalResult;
        
        for (int iIndex = 0; iIndex < vecNumList.size(); iIndex ++)
        {
            if (!ossFinalResult.str().empty() || vecNumList[iIndex] != "0")
            {
                ossFinalResult << vecNumList[iIndex];
            }
        }
        
        if (ossFinalResult.str().empty())
        {
            ossFinalResult << "0";
        }
        
        return ossFinalResult.str();
    }
};

/*

The right thinking is simple, but because of complex thinking, there are a lot of bugs appear.

Remember, a simple and clear thinking makes algorithm bug free and solving correct.

This is a greedy algorithm, the key point is finding out the greedy sorting policy.

The key of the sorting policy is to determin which element is bigger between two elements.

Make appending on (strOper1, strOper2) to strFirst1, and (strOper2, strOper1) to strFirst2, then, compare strFirst1 and strFirst2 using string comparing method. 

*/
