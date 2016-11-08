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

    bool isPalindrome(ListNode * head)
    {
        if (head == NULL)
        {
            return true;
        }
        
        ListNode * pstSlow = head;
        ListNode * pstFast = head;
        
        while (pstFast -> next != NULL && pstFast -> next -> next != NULL)
        {
            pstSlow = pstSlow -> next;
            pstFast = pstFast -> next -> next;
        }
        
        if (pstFast -> next != NULL)
        {
            pstFast = pstFast -> next;
        }
        
        for (ListNode * pstBehind = pstSlow, * pstFront = pstSlow -> next; pstFront != NULL;)
        {
            ListNode * pstNext = pstFront -> next;
            pstFront -> next   = pstBehind;
            pstBehind          = pstFront;
            pstFront           = pstNext;
        }
        
        // Shit !!!
        pstSlow -> next = NULL;
        
        ListNode * pstHead = head;
        ListNode * pstTail = pstFast;
        
        for (; pstHead != pstSlow; pstHead = pstHead -> next, pstTail = pstTail -> next)
        {
            if (pstHead -> val != pstTail -> val)
            {
                return false;
            }
        }
        
        return pstHead -> val == pstTail -> val;
    }
};

/*

Extremely smart algorithm.

Two pointers. One is fast, the other is slow.

The two pointers divide the list into 2 halves.

Reverse the tail half, and the judgement can run. 

*/
