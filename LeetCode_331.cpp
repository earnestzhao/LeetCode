class Solution
{
public:

	bool isValidSerialization(string preorder)
	{
		string strLastReplaced = preorder;
		
		string strReplaced = LeafNodeReplace(strLastReplaced);
		
		while (strLastReplaced != strReplaced)
		{
			strLastReplaced = strReplaced;
			
			strReplaced = LeafNodeReplace(strLastReplaced);
		}
		
		return strReplaced == "#";
	}
	
private:

	string LeafNodeReplace(string strPreOrder)
	{
		string::size_type uiPosition = strPreOrder.find(",#,#");
		
		if (uiPosition == string::npos)
		{
			return strPreOrder;
		}
		
		string::size_type uiReplaceEnd = uiPosition + 3;
		 
		while (uiPosition > 0 && strPreOrder[uiPosition - 1] >= '0' && strPreOrder[uiPosition - 1] <= '9')
		{
			uiPosition --;
		}
		
		string strReplaced;
		strReplaced.append(strPreOrder.substr(0, uiPosition));
		strReplaced.append(strPreOrder.substr(uiReplaceEnd));
		return strReplaced;
	}
};
