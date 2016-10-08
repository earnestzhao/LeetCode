/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger
 * {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// Stack Node Type
enum StackNodeType
{
    SNT_VALUE,
    SNT_LIST_HEAD,
    SNT_COMPLETE_OBJECT,
};

// Stack Node
struct StackNode
{
    // Constucture
    StackNode(StackNodeType iType, int iValue, bool bNegative) : type(iType), value(iValue), negative(bNegative)
    {
        
    }
    
    // Type
    StackNodeType type;
    
    // Value
    int value;
    
    // Value Negative
    bool negative;
    
    // Complete Object
    NestedInteger object;
};

class Solution
{
public:

    NestedInteger deserialize(string s)
    {
        stack<StackNode *> stackDeserialize;
        
        for (int iIndex = 0; iIndex < s.length(); iIndex ++)
        {
            if (s[iIndex] == '-')
            {
                stackDeserialize.push(new StackNode(SNT_VALUE, 0, true));
            }
            else if (s[iIndex] >= '0' && s[iIndex] <= '9')
            {
                if (stackDeserialize.empty() || stackDeserialize.top() -> type != SNT_VALUE)
                {
                    stackDeserialize.push(new StackNode(SNT_VALUE, s[iIndex] - '0', false));
                }
                else
                {
                    if (stackDeserialize.top() -> negative)
                    {
                        stackDeserialize.top() -> value = stackDeserialize.top() -> value * 10 - (s[iIndex] - '0');
                    }
                    else
                    {
                        stackDeserialize.top() -> value = stackDeserialize.top() -> value * 10 + (s[iIndex] - '0');
                    }
                }
            }
            else if (s[iIndex] == '[')
            {
                stackDeserialize.push(new StackNode(SNT_LIST_HEAD, 0, false));
            }
            else
            {
                
            }
            
            if (s[iIndex] == ',' || s[iIndex] == ']' || iIndex == s.length() - 1)
            {
                if (stackDeserialize.top() -> type == SNT_VALUE)
                {
                    stackDeserialize.top() -> type = SNT_COMPLETE_OBJECT;
                    stackDeserialize.top() -> object.setInteger(stackDeserialize.top() -> value);
                }
            }
            
            if (s[iIndex] == ']')
            {
                vector<StackNode *> vecStackNodeList;
                
                while (!stackDeserialize.empty() && stackDeserialize.top() -> type != SNT_LIST_HEAD)
                {
                    vecStackNodeList.push_back(stackDeserialize.top());
                    stackDeserialize.pop();
                }
                
                StackNode * pstObject = stackDeserialize.top();
                pstObject -> type     = SNT_COMPLETE_OBJECT;
                
                for (int iReverseIndex = vecStackNodeList.size() - 1; iReverseIndex >= 0; iReverseIndex --)
                {
                    pstObject -> object.add(vecStackNodeList[iReverseIndex] -> object);
                }
            }
        }
        
        return stackDeserialize.top() -> object;
    }
};

/*

Stack.

Almost the same as recurision ... even in runtime ...

*/
