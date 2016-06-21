/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger
 * {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
public:

    NestedIterator(vector<NestedInteger> & nestedList) : m_iIteratorCurrentIndex(0)
    {
        travesal(nestedList);
    }

    int next()
    {
        return m_vecTravesalList[m_iIteratorCurrentIndex ++];
    }

    bool hasNext()
    {
        return m_iIteratorCurrentIndex < m_vecTravesalList.size();
    }
    
private:

    void travesal(const vector<NestedInteger> & vecNestedList)
    {
        for (int iIndex = 0; iIndex < vecNestedList.size(); iIndex ++)
        {
            if (vecNestedList[iIndex].isInteger())
            {
                m_vecTravesalList.push_back(vecNestedList[iIndex].getInteger());
            }
            else
            {
                travesal(vecNestedList[iIndex].getList());
            }
        }
    }
    
private:

    // Iterator current index
    int m_iIteratorCurrentIndex;

    // Travesal list
    vector<int> m_vecTravesalList;
};
