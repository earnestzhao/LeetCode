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

    ListNode * rotateRight(ListNode * head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        
        int iElementNumber    = 0;
        ListNode * pstNewHead = NULL;
        ListNode * pstNewTail = NULL;
        reverse(head, iElementNumber, &pstNewHead, &pstNewTail);
        
        int iLoopCount = k % iElementNumber;
        
        for (int iIndex = 0; iIndex < iLoopCount; iIndex ++)
        {
            ListNode * pstDstNode = pstNewHead;
            pstNewHead            = pstNewHead -> next;
            pstDstNode -> next    = NULL;
            pstNewTail -> next    = pstDstNode;
            pstNewTail            = pstDstNode;
        }
        
        ListNode * pstResultHead = NULL;
        ListNode * pstResultTail = NULL;
        reverse(pstNewHead, iElementNumber, &pstResultHead, &pstResultTail);
        return pstResultHead;
    }
    
private:

    void reverse(ListNode * pstHead, int & iCount, ListNode ** ppstNewHead, ListNode ** ppstNewTail)
    {
        if (pstHead == NULL)
        {
            iCount       = 0;
            *ppstNewHead = NULL;
            *ppstNewTail = NULL;
            return;
        }
        
        iCount = 1;
        
        if (pstHead -> next == NULL)
        {
            *ppstNewHead = pstHead;
            *ppstNewTail = pstHead;
            return;
        }
        
        ListNode * pstBehind = pstHead;
        ListNode * pstFront  = pstHead -> next;
        
        while (pstFront != NULL)
        {
            ListNode * pstFrontNext = pstFront -> next;
            pstFront -> next        = pstBehind;
            pstBehind               = pstFront;
            pstFront                = pstFrontNext;
            iCount ++;
        }
        
        *ppstNewHead           = pstBehind;
        *ppstNewTail           = pstHead;
        (*ppstNewTail) -> next = NULL;
    }
};

/*

Error understanding the topic of question first...

Then, thinking is right, but a lot of compile and small bugs.

The algorithm is simple:

1. Reverse the linked list.

2. Loop from 0 to k % iCount, delete the head node and add it to tail.

3. Reverse the linked list back.

*/
