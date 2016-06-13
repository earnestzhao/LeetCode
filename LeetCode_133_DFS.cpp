/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode
 * {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution
{
public:

    UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node)
    {
        unordered_map<int, UndirectedGraphNode *> hmapCopied;
        return cloneGraph(node, hmapCopied);
    }
    
private:

    UndirectedGraphNode * cloneGraph(UndirectedGraphNode * pstCurrNode, unordered_map<int, UndirectedGraphNode *> & hmapCopied)
    {
        if (pstCurrNode == NULL)
        {
            return NULL;
        }
        
        unordered_map<int, UndirectedGraphNode *>::iterator hmapIterator = hmapCopied.find(pstCurrNode -> label);
        
        if (hmapIterator != hmapCopied.end())
        {
            return hmapIterator -> second;
        }
        
        UndirectedGraphNode * pstCurrNodeCopied = new UndirectedGraphNode(pstCurrNode -> label);
        
        hmapCopied[pstCurrNodeCopied -> label] = pstCurrNodeCopied;
        
        for (int iIndex = 0; iIndex < pstCurrNode -> neighbors.size(); iIndex ++)
        {
            pstCurrNodeCopied -> neighbors.push_back(cloneGraph(pstCurrNode -> neighbors[iIndex], hmapCopied));
        }
        
        return pstCurrNodeCopied;
    }
};

/*

Almost bug free once, but miss a corner condition judgement, because of ... concentration lacking ...

Normal depth-first search.

*/
