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
        
        ListNode * pstWork1 = l1, * pstWork2 = l2, * pstLonger = NULL;
        
        while (pstWork1 != NULL && pstWork2 != NULL)
        {
            int iPlusResult = pstWork1 -> val + pstWork2 -> val + iNextPosPlus;
            iCurrentPosNum  = iPlusResult >= 10 ? iPlusResult - 10 : iPlusResult;
            iNextPosPlus    = iPlusResult >= 10;
            
            pstResultWork = new ListNode(iCurrentPosNum);
            pstResultTail -> next = pstResultWork;
            pstResultTail = pstResultWork;
            
            pstWork1 = pstWork1 -> next;
            pstWork2 = pstWork2 -> next;
        }
        
        pstLonger = pstWork1 != NULL ? pstWork1 : pstWork2;
        
        while (pstLonger != NULL && (iNextPosPlus & 1))
        {
            int iPlusResult = pstLonger -> val + iNextPosPlus;
            iCurrentPosNum  = iPlusResult >= 10 ? iPlusResult - 10 : iPlusResult;
            iNextPosPlus    = iPlusResult >= 10;
            
            pstResultWork = new ListNode(iCurrentPosNum);
            pstResultTail -> next = pstResultWork;
            pstResultTail = pstResultWork;
            
            pstLonger = pstLonger -> next;
        }
        
        if (iNextPosPlus & 1)
        {
            pstResultWork = new ListNode(iNextPosPlus);
            pstResultTail -> next = pstResultWork;
            pstResultTail = pstResultWork;
        }
        else
        {
            pstResultTail -> next = pstLonger;
        }
        
        return pstResultHead -> next;
    }
};

/*

Runtime: 36ms

I don't know why so clear optimization cannot reduce runtime than Leetcode_002_1Loop.cpp ...

*/
