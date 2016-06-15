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
        int iNodeCount = 0;
        
        for (ListNode * pstCount = head; pstCount != NULL; pstCount = pstCount -> next)
        {
            iNodeCount ++;
        }
        
        return sortList(head, iNodeCount);
    }
    
private:

    ListNode * sortList(ListNode * pstHead, int iNodeCount)
    {
        if (iNodeCount <= 1)
        {
            return pstHead;
        }
        
        if (iNodeCount == 2)
        {
            if (pstHead -> val > pstHead -> next -> val)
            {
                swap(pstHead -> val, pstHead -> next -> val);
            }
            
            return pstHead;
        }
        
        ListNode * pstHalfLeftTail = pstHead;
        
        for (int iLeftCount = 1; iLeftCount < iNodeCount / 2; iLeftCount ++)
        {
            pstHalfLeftTail = pstHalfLeftTail -> next;
        }
        
        ListNode * pstHalfRightHead = pstHalfLeftTail -> next;
        pstHalfLeftTail -> next     = NULL;
        
        ListNode * pstLeftSortedListHead  = sortList(pstHead,          iNodeCount / 2);
        ListNode * pstRightSortedListHead = sortList(pstHalfRightHead, iNodeCount - iNodeCount / 2);
        
        ListNode * pstMergeListHead = new ListNode(INT_MIN);
        ListNode * pstMergeListTail = pstMergeListHead;
        
        while (pstLeftSortedListHead != NULL && pstRightSortedListHead != NULL)
        {
            ListNode * pstDstNode = NULL;
            
            if (pstLeftSortedListHead -> val <= pstRightSortedListHead -> val)
            {
                pstDstNode            = pstLeftSortedListHead;
                pstLeftSortedListHead = pstLeftSortedListHead -> next;
            }
            else
            {
                pstDstNode             = pstRightSortedListHead;
                pstRightSortedListHead = pstRightSortedListHead -> next;
            }
            
            pstDstNode -> next       = NULL;
            pstMergeListTail -> next = pstDstNode;
            pstMergeListTail         = pstDstNode;
        }
        
        if (pstLeftSortedListHead == NULL)
        {
            pstMergeListTail -> next = pstRightSortedListHead;
        }
        
        if (pstRightSortedListHead == NULL)
        {
            pstMergeListTail -> next = pstLeftSortedListHead;
        }
        
        return pstMergeListHead -> next;
    }
    
    void swap(int & iOper1, int & iOper2)
    {
        int iSwap = iOper1;
        iOper1    = iOper2;
        iOper2    = iSwap;
    }
};
