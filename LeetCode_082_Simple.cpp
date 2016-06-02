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

    ListNode * deleteDuplicates(ListNode * head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        
        if (head -> next == NULL)
        {
            return head;
        }
        
        ListNode * pstHeadBlank = new ListNode(0);
        pstHeadBlank -> next    = head;
        
        for (ListNode * pstWorker = pstHeadBlank; pstWorker -> next != NULL;)
        {
            ListNode * pstSameScanner = pstWorker -> next;
            
            while (pstSameScanner != NULL && pstWorker -> next -> val == pstSameScanner -> val)
            {
                pstSameScanner = pstSameScanner -> next;
            }
            
            if (pstSameScanner == pstWorker -> next -> next)
            {
                pstWorker = pstWorker -> next;
            }
            else
            {
                pstWorker -> next = pstSameScanner;
            }
        }
        
        return pstHeadBlank -> next;
    }
};

/*

If the solution is simple, it has less bugs.

Simple Key:

1. A blank previous node.

2. Same comparing.

*/
