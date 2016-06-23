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

    ListNode * mergeKLists(vector<ListNode *> & lists)
    {
        if (lists.size() <= 0)
        {
            return NULL;
        }
        
        ListNode * pstResult = lists[0];
        
        for (int iIndex = 1; iIndex < lists.size(); iIndex ++)
        {
            pstResult = mergeTwoLists(pstResult, lists[iIndex]);
        }
        
        return pstResult;
    }
    
private:

    ListNode * mergeTwoLists(ListNode * pstList1, ListNode * pstList2)
    {
        ListNode * pstResult     = new ListNode(0);
        ListNode * pstResultTail = pstResult;
        
        while (pstList1 != NULL && pstList2 != NULL)
        {
            if (pstList1 -> val <= pstList2 -> val)
            {
                pstResultTail -> next = pstList1;
                pstResultTail         = pstList1;
                pstList1              = pstList1 -> next;
                pstResultTail -> next = NULL;
            }
            else
            {
                pstResultTail -> next = pstList2;
                pstResultTail         = pstList2;
                pstList2              = pstList2 -> next;
                pstResultTail -> next = NULL;
            }
        }
        
        if (pstList1 == NULL)
        {
            pstResultTail -> next = pstList2;
        }
        else
        {
            pstResultTail -> next = pstList1;
        }
        
        ListNode * pstReturn = pstResult -> next;
        delete pstResult;
        return pstReturn;
    }
};
