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

    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        
        ListNode * pstTail = headB;
        
        while (pstTail -> next != NULL)
        {
            pstTail = pstTail -> next;
        }
        
        // Store it for recovering ...
        pstTail -> next = headB;
        
        ListNode * pstSlow = headA;
        ListNode * pstFast = headA;
        
        while (pstFast != NULL && pstFast -> next != NULL)
        {
            pstSlow = pstSlow -> next;
            pstFast = pstFast -> next -> next;
            
            if (pstSlow == pstFast)
            {
                break;
            }
        }
        
        if (pstFast == NULL || pstFast -> next == NULL)
        {
            pstTail -> next = NULL;
            return NULL;
        }
        
        for (pstSlow = headA; pstSlow != pstFast; pstSlow = pstSlow -> next, pstFast = pstFast -> next)
        {
            
        }
        
        pstTail -> next = NULL;
        return pstSlow;
    }
};

/*

Good thinking, but a lot of edge bugs.

1. I should recover the tail pointer to NULL before each exit.

2. I should test the two pointers same after they move when loop entrance checking ...

*/
