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

    ListNode * reverseKGroup(ListNode * head, int k)
    {
        int iListCount = 0;
        
        for (ListNode * pstNode = head; pstNode != NULL; pstNode = pstNode -> next)
        {
            iListCount ++;
        }
        
        ListNode * pstResultList = new ListNode(0);
        ListNode * pstResultTail = pstResultList;
        
        for (; iListCount >= k; iListCount -= k)
        {
            ListNode * pstResultNewTail = NULL;
            
            for (int iIndex = 0; iIndex < k; iIndex ++)
            {
                ListNode * pstCurrent = head;
                head                  = pstCurrent -> next;
                pstCurrent -> next    = pstResultTail -> next;
                pstResultTail -> next = pstCurrent;
                
                if (pstResultNewTail == NULL)
                {
                    pstResultNewTail = pstCurrent;
                }
            }
            
            pstResultTail = pstResultNewTail;
        }
        
        pstResultTail -> next = head;
        return pstResultList -> next;
    }
};

/*

Bug free once, and a good optimization.

Normal algorithm. Get a node and connect it to new list for each 'k' group.

*/
