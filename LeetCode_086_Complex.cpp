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
        
        ListNode * pstHead = head;
        ListNode * pstTail = head;
        
        while (pstTail -> next != NULL)
        {
            pstTail = pstTail -> next;
        }
        
        if (pstHead == pstTail)
        {
            return pstHead;
        }
        
        ListNode * pstWorkerCurr = pstHead;
        ListNode * pstWorkerTail = pstTail;
        
        while (pstWorkerCurr != pstWorkerTail)
        {
            if (pstWorkerCurr -> val < x)
            {
                pstWorkerCurr = pstWorkerCurr -> next;
            }
            else
            {
                ListNode * pstDelete = pstWorkerCurr -> next;
                swap(pstWorkerCurr, pstDelete);
                
                if (pstDelete != pstTail)
                {
                    pstWorkerCurr -> next = pstDelete -> next;
                    pstDelete     -> next = NULL;
                    pstTail       -> next = pstDelete;
                    pstTail               = pstDelete;
                }
                
                if (pstDelete == pstWorkerTail)
                {
                    break;
                }
            }
        }
        
        if (pstWorkerCurr -> val >= x)
        {
            ListNode * pstDelete = pstWorkerCurr -> next;
            
            if (pstDelete != NULL)
            {
                swap(pstWorkerCurr, pstDelete);
                
                if (pstDelete != pstTail)
                {
                    pstWorkerCurr -> next = pstDelete -> next;
                    pstDelete     -> next = NULL;
                    pstTail       -> next = pstDelete;
                    pstTail               = pstDelete;
                }
            }
        }
        
        return pstHead;
    }
    
private:

    void swap(ListNode * pstNode1, ListNode * pstNode2)
    {
        int iSwapValue  = pstNode1 -> val;
        pstNode1 -> val = pstNode2 -> val;
        pstNode2 -> val = iSwapValue;
    }
};

/*

Thinking is right, but there are a lot of bugs in edge condition.

Travesal the linked list. If the value of current element is no bigger to x, then, delete it and move it to the end.

Take care of corner status!!!

There must be better solutions. Research it later!

*/
