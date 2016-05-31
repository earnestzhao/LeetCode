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

    ListNode * deleteDuplicates(ListNode * head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        
        if (head -> next == NULL)
        {
            return head;
        }
        
        bool bHeadDelete = false;
        
        if (head -> val == head -> next -> val)
        {
            bHeadDelete = true;
        }
        
        ListNode * pstBehind = head;
        ListNode * pstMiddle = head -> next;
        ListNode * pstFront  = head -> next -> next;
        
        while (pstFront != NULL)
        {
            if (pstMiddle -> val == pstFront -> val)
            {
                while (pstFront != NULL && pstFront -> val == pstMiddle -> val)
                {
                    pstFront = pstFront -> next;
                }
                
                if (pstFront != NULL)
                {
                    pstMiddle -> val  = pstFront  -> val;
                    pstMiddle -> next = pstFront  -> next;
                    pstFront          = pstMiddle -> next;
                }
                else
                {
                    pstBehind -> next = NULL;
                    break;
                }
            }
            else
            {
                pstBehind = pstMiddle;
                pstMiddle = pstFront;
                pstFront  = pstFront -> next;
            }
        }
        
        if (head -> next != NULL && head -> val == head -> next -> val)
        {
            return head -> next -> next;
        }
        
        if (bHeadDelete)
        {
            return head -> next;
        }
        
        return head;
    }
};

/*

Thinking is right, but not bug free, and a little complex.

Three pointers. (pstBehind, pstMiddle, pstFront)

Traversal from head to NULL, find out each same range, and then delete it.

Do processing on head at last.

Take care of corner conditions!!!

There must be better solutions. Research it later.

*/
