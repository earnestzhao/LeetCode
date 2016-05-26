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
        
        if (head -> next == NULL)
        {
            return head;
        }
        
        vector<ListNode *> vecNodeList;
        
        for (ListNode * pstWorker = head; pstWorker != NULL; pstWorker = pstWorker -> next)
        {
            vecNodeList.push_back(pstWorker);
        }
        
        k %= vecNodeList.size();
        
        if (k == 0)
        {
            return head;
        }
        
        ListNode * pstRawTail = vecNodeList[vecNodeList.size() - 1];
        ListNode * pstNewHead = vecNodeList[vecNodeList.size() - k];
        ListNode * pstNewTail = vecNodeList[vecNodeList.size() - k - 1];
        
        pstRawTail -> next = head;
        pstNewTail -> next = NULL;
        return pstNewHead;
    }
};

/*

Thinking is right, but some bugs exist.

Put all element pointer into a vector, and then do rotating simply.

*/
