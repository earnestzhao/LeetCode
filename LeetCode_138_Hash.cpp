/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode
 * {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution
{
public:

    RandomListNode * copyRandomList(RandomListNode * head)
    {
        RandomListNode * pstCopyHead = new RandomListNode(INT_MIN);
        
        int iCurrentIndex = 0;
        unordered_map<RandomListNode *, int> hmapSrcNodeIndex;
        unordered_map<int, RandomListNode *> hmapDstIndexNode;
        
        for (RandomListNode * pstSrc = head, * pstDst = pstCopyHead; pstSrc != NULL; pstSrc = pstSrc -> next)
        {
            pstDst -> next = new RandomListNode(pstSrc -> label);
            pstDst         = pstDst -> next;
            
            hmapSrcNodeIndex[pstSrc] = iCurrentIndex;
            hmapDstIndexNode[iCurrentIndex] = pstDst;
            iCurrentIndex ++;
        }
        
        for (RandomListNode * pstSrc = head, * pstDst = pstCopyHead -> next; pstSrc != NULL; pstSrc = pstSrc -> next, pstDst = pstDst -> next)
        {
            if (pstSrc -> random == NULL)
            {
                pstDst -> random = NULL;
            }
            else
            {
                pstDst -> random = hmapDstIndexNode[hmapSrcNodeIndex[pstSrc -> random]];
            }
        }
        
        return pstCopyHead -> next;
    }
};
