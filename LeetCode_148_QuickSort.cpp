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

    ListNode * sortList(ListNode * head)
    {
        ListNode * pstSortedTail = NULL;
        return sortList(head, pstSortedTail);
    }
    
private:

    ListNode * sortList(ListNode * pstHead, ListNode *& pstSortedTail)
    {
        if (pstHead == NULL)
        {
            pstSortedTail = NULL;
            return NULL;
        }
        
        if (pstHead -> next == NULL)
        {
            pstSortedTail = pstHead;
            return pstHead;
        }
        
        ListNode * pstLTListHead = new ListNode(INT_MIN);
        ListNode * pstGTListHead = new ListNode(INT_MAX);
        ListNode * pstEQListHead = new ListNode(pstHead -> val);
        
        ListNode * pstLTListTail = pstLTListHead;
        ListNode * pstGTListTail = pstGTListHead;
        ListNode * pstEQListTail = pstEQListHead;
        
        while (pstHead -> next != NULL)
        {
            ListNode * pstDstNode = pstHead -> next;
            pstHead    -> next    = pstDstNode -> next;
            pstDstNode -> next    = NULL;
            
            if (pstDstNode -> val < pstHead -> val)
            {
                pstLTListTail -> next = pstDstNode;
                pstLTListTail         = pstDstNode;
            }
            else if (pstDstNode -> val > pstHead -> val)
            {
                pstGTListTail -> next = pstDstNode;
                pstGTListTail         = pstDstNode;
            }
            else
            {
                pstEQListTail -> next = pstDstNode;
                pstEQListTail         = pstDstNode;
            }
        }
        
        pstLTListHead = sortList(pstLTListHead -> next, pstLTListTail);
        pstGTListHead = sortList(pstGTListHead -> next, pstGTListTail);
        
        ListNode * pstSortedHead = new ListNode(INT_MIN);
        pstSortedTail            = pstSortedHead;
        
        if (pstLTListHead != NULL)
        {
            pstSortedTail -> next = pstLTListHead;
            pstSortedTail         = pstLTListTail;
        }
        
        pstSortedTail -> next = pstEQListHead;
        pstSortedTail         = pstEQListTail;
        
        if (pstGTListHead != NULL)
        {
            pstSortedTail -> next = pstGTListHead;
            pstSortedTail         = pstGTListTail;
        }
        
        return pstSortedHead -> next;
    }
};

/*

Thinking is right, but TLE first, and a bug is occured when optiminize.

Normal quick sort on linked list.

*/
