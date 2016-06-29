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

    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2)
    {
        int iCurrentPosNum = 0, iNextPosPlus = 0;
    
        ListNode * pstResultHead = new ListNode(-1), * pstResultTail = pstResultHead, * pstResultWork = NULL;
        
        ListNode * pstWork1 = l1, * pstWork2 = l2;
        
        while (pstWork1 != NULL || pstWork2 != NULL)
        {
            int iPlusResult = 0;
            
            if (pstWork1 == NULL)
            {
                iPlusResult = pstWork2 -> val + iNextPosPlus;
            }
            else if (pstWork2 == NULL)
            {
                iPlusResult = pstWork1 -> val + iNextPosPlus;
            }
            else
            {
                iPlusResult = pstWork1 -> val + pstWork2 -> val + iNextPosPlus;
            }
            
            iCurrentPosNum = iPlusResult >= 10 ? iPlusResult - 10 : iPlusResult;
            iNextPosPlus   = iPlusResult >= 10;
            
            pstResultWork = new ListNode(iCurrentPosNum);
            pstResultTail -> next = pstResultWork;
            pstResultTail = pstResultWork;
            
            pstWork1 = (pstWork1 == NULL ? NULL : pstWork1 -> next);
            pstWork2 = (pstWork2 == NULL ? NULL : pstWork2 -> next);
        }
        
        if (iNextPosPlus & 1)
        {
            pstResultWork = new ListNode(iNextPosPlus);
            pstResultTail -> next = pstResultWork;
            pstResultTail = pstResultWork;
        }
        
        return pstResultHead -> next;
    }
};

/*

Runtime: 36ms

*/
