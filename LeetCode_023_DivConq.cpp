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

    ListNode * mergeKLists(vector<ListNode *> & lists)
    {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
    
private:

    ListNode * mergeKLists(vector<ListNode *> & vecLists, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex > iEndIndex)
        {
            return NULL;
        }
        
        if (iStartIndex == iEndIndex)
        {
            return vecLists[iStartIndex];
        }
        
        int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
        ListNode * pstMergeLeft  = mergeKLists(vecLists, iStartIndex,   iMidIndex);
        ListNode * pstMergeRight = mergeKLists(vecLists, iMidIndex + 1, iEndIndex);
        return mergeTwoLists(pstMergeLeft, pstMergeRight);
    }

    ListNode * mergeTwoLists(ListNode * pstList1, ListNode * pstList2)
    {
        ListNode * pstResult     = new ListNode(0);
        ListNode * pstResultTail = pstResult;
        
        while (pstList1 != NULL && pstList2 != NULL)
        {
            if (pstList1 -> val <= pstList2 -> val)
            {
                pstResultTail -> next = pstList1;
                pstResultTail         = pstList1;
                pstList1              = pstList1 -> next;
                pstResultTail -> next = NULL;
            }
            else
            {
                pstResultTail -> next = pstList2;
                pstResultTail         = pstList2;
                pstList2              = pstList2 -> next;
                pstResultTail -> next = NULL;
            }
        }
        
        if (pstList1 == NULL)
        {
            pstResultTail -> next = pstList2;
        }
        else
        {
            pstResultTail -> next = pstList1;
        }
        
        ListNode * pstReturn = pstResult -> next;
        delete pstResult;
        return pstReturn;
    }
};

/*

Fantastic !!!

T(kn) = 2T(kn/2) + O(kn) = O(kn * log(kn))

*/
