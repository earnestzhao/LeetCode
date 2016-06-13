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
        if (node == NULL)
        {
            return NULL;
        }
        
        UndirectedGraphNode * pstNodeCopied = new UndirectedGraphNode(node -> label);
        unordered_map<int, UndirectedGraphNode *> hmapCopied;
        hmapCopied[pstNodeCopied -> label] = pstNodeCopied;
        
        queue<UndirectedGraphNode *> queueTravesal;
        queueTravesal.push(node);
        
        queue<UndirectedGraphNode *> queueCopy;
        queueCopy.push(pstNodeCopied);
        
        while (!queueTravesal.empty())
        {
            UndirectedGraphNode * pstCurrNode = queueTravesal.front();
            queueTravesal.pop();
            
            UndirectedGraphNode * pstCurrCopiedNode = queueCopy.front();
            queueCopy.pop();
            
            for (int iIndex = 0; iIndex < pstCurrNode -> neighbors.size(); iIndex ++)
            {
                unordered_map<int, UndirectedGraphNode *>::iterator hmapIterator = hmapCopied.find(pstCurrNode -> neighbors[iIndex] -> label);
                
                if (hmapIterator == hmapCopied.end())
                {
                    UndirectedGraphNode * pstNextNodeCopied = new UndirectedGraphNode(pstCurrNode -> neighbors[iIndex] -> label);
                    pstCurrCopiedNode -> neighbors.push_back(pstNextNodeCopied);
                    
                    queueCopy.push(pstNextNodeCopied);
                    queueTravesal.push(pstCurrNode -> neighbors[iIndex]);
                    hmapCopied[pstNextNodeCopied -> label] = pstNextNodeCopied;
                }
                else
                {
                    pstCurrCopiedNode -> neighbors.push_back(hmapIterator -> second);
                }
            }
        }
        
        return pstNodeCopied;
    }
};

/*

Another version. Breadth-first search.

*/
