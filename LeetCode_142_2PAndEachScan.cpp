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

    ListNode * detectCycle(ListNode * head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        
        ListNode * pstSlow = head;
        ListNode * pstFast = head -> next;
        
        while (pstFast != NULL)
        {
            if (pstFast == pstSlow || pstFast -> next == pstSlow)
            {
                break;
            }
            
            pstSlow = pstSlow -> next;
            pstFast = pstFast -> next;
            
            if (pstFast != NULL)
            {
                pstFast = pstFast -> next;
            }
        }
        
        if (pstFast == NULL)
        {
            return NULL;
        }
        
        if (pstFast -> next == pstFast)
        {
            return pstFast;
        }
        
        for (ListNode * pstScanner = head; ; pstScanner = pstScanner -> next)
        {
            for (ListNode * pstInnerLoop = pstFast -> next; pstInnerLoop != pstFast; pstInnerLoop = pstInnerLoop -> next)
            {
                if (pstInnerLoop == pstScanner)
                {
                    return pstScanner;
                }
            }
        }
        
        return NULL;
    }
};

/*

Thinking is right, but not bug free because of a corner condition.

Normal two pointers and scaning algorithm.

1. Using two pointers algorithm to judge cycle exist.

2. Outer travesal from 'head', for each node, if inner cycle traversal meet the current node of outer traversal, it is the result.

Time complexity: O(n*n). Space complexity: O(1). There must be better solutions.

*/
