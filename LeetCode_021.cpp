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

    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2)
    {
        ListNode * pstResult     = new ListNode(INT_MIN);
        ListNode * pstResultTail = pstResult;
        
        while (l1 != NULL && l2 != NULL)
        {
            if (l1 -> val <= l2 -> val)
            {
                pstResultTail -> next = l1;
                pstResultTail         = l1;
                l1                    = l1 -> next;
            }
            else
            {
                pstResultTail -> next = l2;
                pstResultTail         = l2;
                l2                    = l2 -> next;
            }
        }
        
        if (l2 == NULL)
        {
            pstResultTail -> next = l1;
        }
        else
        {
            pstResultTail -> next = l2;
        }
        
        return pstResult -> next;
    }
};
