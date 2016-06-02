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

    ListNode * reverseBetween(ListNode * head, int m, int n)
    {
        ListNode * pstDummyHead = new ListNode(0);
        ListNode * pstBeforeRev = pstDummyHead;
        pstDummyHead -> next    = head;
        
        while (-- n, -- m)
        {
            pstBeforeRev = pstBeforeRev -> next;
        }
        
        ListNode * pstWorker = pstBeforeRev -> next;
        
        while (n --)
        {
            swap(pstBeforeRev -> next, pstWorker -> next -> next);
            swap(pstBeforeRev -> next, pstWorker -> next);
        }
        
        return pstDummyHead -> next;
    }
    
private:

    void swap(ListNode *& pstOper1, ListNode *& pstOper2)
    {
        ListNode * pstSwap = pstOper1;
        pstOper1 = pstOper2;
        pstOper2 = pstSwap;
    }
};

/*

Fantastic SWAP!!! But a little hard to read...

*/
