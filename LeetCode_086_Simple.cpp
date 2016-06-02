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

    ListNode * partition(ListNode * head, int x)
    {
        if (head == NULL)
        {
            return NULL;
        }
        
        ListNode * pstLTList = new ListNode(0);
        ListNode * pstGEList = new ListNode(0);
        
        ListNode * pstLTListTail = pstLTList;
        ListNode * pstGEListTail = pstGEList;
        
        while (head != NULL)
        {
            ListNode * pstCurrent = head;
            head = head -> next;
            pstCurrent  -> next = NULL;
            
            if (pstCurrent -> val < x)
            {
                pstLTListTail -> next = pstCurrent;
                pstLTListTail         = pstCurrent;
            }
            else
            {
                pstGEListTail -> next = pstCurrent;
                pstGEListTail         = pstCurrent;
            }
        }
        
        pstLTListTail -> next = pstGEList -> next;
        return pstLTList -> next;
    }
};

/*

It is simple and common. And it is still one-pass and constant space.

But... Why didn't I think about it???!!!

*/
