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
    ListNode *swapPairs(ListNode *head) 
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *pstResult     = new ListNode(-1);
        ListNode *pstInsertHead = pstResult;
        ListNode *pstInsertTail = pstResult;

        bool bInsertFromTail = true;
        for (ListNode *pstTraversal = head; pstTraversal != NULL; bInsertFromTail = !bInsertFromTail)
        {
            ListNode *pstCurrent = pstTraversal;
            pstTraversal = pstCurrent->next;

            if (bInsertFromTail)
            {
                pstInsertTail->next = pstCurrent;
                pstCurrent->next = NULL;
                pstInsertTail = pstCurrent;
            }
            else
            {
                pstCurrent->next = pstInsertHead->next;
                pstInsertHead->next = pstCurrent;
                pstInsertHead = pstInsertTail;
            }
        }

        return pstResult->next;
    }
};

