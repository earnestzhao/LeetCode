/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode * head)
    {
        for (ListNode * pstCurrent = head; pstCurrent != NULL; pstCurrent = pstCurrent -> next)
        {
            m_vecValueList.push_back(pstCurrent -> val);
        }
        
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom()
    {
        return m_vecValueList[rand() % m_vecValueList.size()];
    }
    
private:

    vector<int> m_vecValueList;
};
