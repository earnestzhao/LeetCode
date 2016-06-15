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

    ListNode * insertionSortList(ListNode * head)
    {
        if (head == NULL || head -> next == NULL)
        {
            return head;
        }
        
        ListNode * pstHeadDummy = new ListNode(INT_MIN);
        pstHeadDummy -> next    = head;
        
        for (ListNode * pstSeqBehind = pstHeadDummy, * pstSeqFront = pstHeadDummy -> next; pstSeqFront != NULL;)
        {
            ListNode * pstInsertBehind = pstHeadDummy;
            ListNode * pstInsertFront  = pstHeadDummy -> next;
            
            while (pstInsertFront != pstSeqFront)
            {
                if (pstInsertFront -> val > pstSeqFront -> val)
                {
                    ListNode * pstInsertDst = pstSeqFront;
                    pstSeqFront             = pstSeqFront -> next;
                    pstSeqBehind -> next    = pstSeqFront;
                    pstInsertDst -> next    = pstInsertBehind -> next;
                    pstInsertBehind -> next = pstInsertDst;
                    break;
                }
                
                pstInsertFront  = pstInsertFront  -> next;
                pstInsertBehind = pstInsertBehind -> next;
            }
            
            if (pstInsertFront == pstSeqFront)
            {
                pstSeqFront  = pstSeqFront  -> next;
                pstSeqBehind = pstSeqBehind -> next;
            }
        }
        
        return pstHeadDummy -> next;
    }
};

/*

Almost bug free once.

Normal insertion sort. Take care of corner conditions.

*/
