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

    void reorderList(ListNode * head)
    {
        int iListNodeCount = 0;
        
        for (ListNode * pstCounter = head; pstCounter != NULL; pstCounter = pstCounter -> next)
        {
            iListNodeCount ++;
        }
        
        if (iListNodeCount <= 1)
        {
            return;
        }
        
        ListNode * pstRearList = head;
        
        for (int iIndex = 1; iIndex < iListNodeCount / 2 + 1; iIndex ++)
        {
            pstRearList = pstRearList -> next;
        }
        
        ListNode * pstNewTail = pstRearList;
        pstRearList = pstRearList -> next;
        pstNewTail -> next = NULL;
        
        if (pstRearList == NULL)
        {
            return;
        }
        
        ListNode * pstRevBehind = pstRearList;
        ListNode * pstRevFront  = pstRearList -> next;
        
        while (pstRevFront != NULL)
        {
            ListNode * pstRevFrontNext = pstRevFront -> next;
            pstRevFront -> next        = pstRevBehind;
            pstRevBehind               = pstRevFront;
            pstRevFront                = pstRevFrontNext;
        }
        
        pstRearList -> next = NULL;
        pstRearList = pstRevBehind;
        
        for (ListNode * pstRaw = head; pstRearList != NULL; pstRaw = pstRaw -> next -> next)
        {
            ListNode * pstInsert = pstRearList;
            pstRearList          = pstRearList -> next;
            pstInsert -> next    = pstRaw -> next;
            pstRaw -> next       = pstInsert;
        }
    }
};

/*

Thinking is right, but many small bugs.

Normal linked list algorithm, including count and reverse.

1. Travesal linked list, and get the count of the elements (n).

2. Divide the linked list into 2 parts LA and LB. LA contains n / 2 + 1 elements from head, and LB contains the remain elements.

3. Reverse LB.

4. Insert each element of LB after each element of LA. After insertion: LA(0)->LB(0)->LA(1)->LB(1)->...

*/
