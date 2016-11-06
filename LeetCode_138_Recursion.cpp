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
        unordered_map<RandomListNode *, RandomListNode *> hmapSrcDst;
        return copyRandomList(head, hmapSrcDst);
    }
    
private:

    RandomListNode * copyRandomList(RandomListNode * pstHead, unordered_map<RandomListNode *, RandomListNode *> & hmapSrcDst)
    {
        RandomListNode * pstLead = new RandomListNode(INT_MIN);
        
        for (RandomListNode * pstSrc = pstHead, * pstDst = pstLead; pstSrc != NULL; pstSrc = pstSrc -> next)
        {
            unordered_map<RandomListNode *, RandomListNode *>::iterator hmapIterator = hmapSrcDst.find(pstSrc);
            
            if (hmapIterator != hmapSrcDst.end())
            {
                pstDst -> next = hmapIterator -> second;
                break;
            }
            
            pstDst -> next     = new RandomListNode(pstSrc -> label);
            pstDst             = pstDst -> next;
            hmapSrcDst[pstSrc] = pstDst;
            
            if (pstSrc -> random == NULL)
            {
                pstDst -> random = NULL;
            }
            else
            {
                hmapIterator = hmapSrcDst.find(pstSrc -> random);
                
                if (hmapIterator != hmapSrcDst.end())
                {
                    pstDst -> random = hmapIterator -> second;
                }
                else
                {
                    pstDst -> random = copyRandomList(pstSrc -> random, hmapSrcDst);
                }
            }
        }
        
        return pstLead -> next;
    }
};
