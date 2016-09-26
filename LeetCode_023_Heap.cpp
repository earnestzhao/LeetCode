/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class ListNodeGreater
{
public:

    bool operator()(ListNode * pstOper1, ListNode * pstOper2)
    {
        return pstOper1 -> val > pstOper2 -> val;
    }
};

class Solution
{
public:

    ListNode * mergeKLists(vector<ListNode *> & lists)
    {
        priority_queue<ListNode *, std::vector<ListNode *>, ListNodeGreater> priqSelectMin;
        
        for (int iIndex = 0; iIndex < lists.size(); iIndex ++)
        {
            if (lists[iIndex] != NULL)
            {
                priqSelectMin.push(lists[iIndex]);
            }
        }
        
        ListNode * pstResult     = new ListNode(0);
        ListNode * pstResultTail = pstResult;
        
        while (!priqSelectMin.empty())
        {
            ListNode * pstCurrent = priqSelectMin.top();
            priqSelectMin.pop();
            
            ListNode * pstNext    = pstCurrent -> next;
            pstCurrent    -> next = NULL;
            pstResultTail -> next = pstCurrent;
            pstResultTail         = pstCurrent;
            
            if (pstNext != NULL)
            {
                priqSelectMin.push(pstNext);
            }
        }
        
        return pstResult -> next;
    }
};
