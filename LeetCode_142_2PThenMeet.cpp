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
        ListNode * pstFast = head;
        
        while (true)
        {
            if (pstFast == NULL || pstFast -> next == NULL)
            {
                return NULL;
            }
            
            pstSlow = pstSlow -> next;
            pstFast = pstFast -> next -> next;
            
            if (pstFast == pstSlow)
            {
                break;
            }
        }
        
        for (pstSlow = head; pstSlow != pstFast; pstSlow = pstSlow -> next, pstFast = pstFast -> next)
        {
            
        }
        
        return pstSlow;
    }
};

/*

Two pointers, but a smart algorithm. The smart point is the last loop.

1. Define 'len' is the element number of the cycle list.

2. Define 'a' is the inter length of cycle start node and the 'head'.

3. Define 'b' is the inter length of cycle start node and the slow pointer and the fast pointer meeting node.

4. Define 's' is the length of walking of the slow pointer when the slow pointer and the fast pointer meeting.

Then, it has:

s = a + b, 2s = s + kr => a + b = kr => a + b = (k - 1)r + r => a + b = (k - 1)r + len - a => a = (k - 1)r + len - a - b

So, set a pointer PA on head, and a pointer PB on the node which the slow pointer and the fast pointer meeting.

PA and PB move to next each time, when they are meet, the result is the meeting node.

Time complexity: O(n). Space complexity: O(1).

*/
