class Solution
{
public:

    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> & edges)
    {
        if (edges.size() <= 0)
        {
            return vector<int>(1, 0);
        }
        
        int * piDegreeList = new int[n];
        
        set<int> * psetGraph = new set<int>[n];
        
        set<int> * psetDegreeToPoint = new set<int>[n];
        
        bzero(piDegreeList, n * sizeof(int));
        
        int iMaxDegree = 0;
        
        for (int iIndex = 0; iIndex < edges.size(); iIndex ++)
        {
            psetGraph[edges[iIndex].first].insert(edges[iIndex].second);
            psetGraph[edges[iIndex].second].insert(edges[iIndex].first);
            
            int iOldDegreeFirst  = piDegreeList[edges[iIndex].first];
            int iOldDegreeSecond = piDegreeList[edges[iIndex].second];
            
            int iNewDegreeFirst  = iOldDegreeFirst  + 1;
            int iNewDegreeSecond = iOldDegreeSecond + 1;
            
            if (iOldDegreeFirst > 0)
            {
                psetDegreeToPoint[iOldDegreeFirst].erase(edges[iIndex].first);
            }
            piDegreeList[edges[iIndex].first] = iNewDegreeFirst;
            psetDegreeToPoint[iNewDegreeFirst].insert(edges[iIndex].first);
            
            if (iOldDegreeSecond > 0)
            {
                psetDegreeToPoint[iOldDegreeSecond].erase(edges[iIndex].second);
            }
            piDegreeList[edges[iIndex].second] = iNewDegreeSecond;
            psetDegreeToPoint[iNewDegreeSecond].insert(edges[iIndex].second);
            
            if (iNewDegreeFirst > iMaxDegree)
            {
                iMaxDegree = iNewDegreeFirst;
            }
            
            if (iNewDegreeSecond > iMaxDegree)
            {
                iMaxDegree = iNewDegreeSecond;
            }
        }
        
        int iPointCount = n;
        
        while (iPointCount > psetDegreeToPoint[1].size())
        {
            set<int> setDegree1;
            
            for (set<int>::iterator setIterator = psetDegreeToPoint[1].begin(); setIterator != psetDegreeToPoint[1].end(); setIterator ++)
            {
                iPointCount --;
                
                for (set<int>::iterator setIteratorConn = psetGraph[*setIterator].begin(); setIteratorConn != psetGraph[*setIterator].end(); setIteratorConn ++)
                {
                    int iOldDegree = piDegreeList[*setIteratorConn];
                    int iNewDegree = iOldDegree - 1;
                    
                    psetDegreeToPoint[iOldDegree].erase(*setIteratorConn);
                    piDegreeList[*setIteratorConn] = iNewDegree;
                    
                    if (iNewDegree == 1)
                    {
                        setDegree1.insert(*setIteratorConn);
                    }
                    else
                    {
                        psetDegreeToPoint[iNewDegree].insert(*setIteratorConn);
                    }
                    
                    psetGraph[*setIteratorConn].erase(*setIterator);
                }
            }
            
            psetDegreeToPoint[1] = setDegree1;
        }
        
        vector<int> vecResult;
        
        for (set<int>::iterator setIterator = psetDegreeToPoint[1].begin(); setIterator != psetDegreeToPoint[1].end(); setIterator ++)
        {
            vecResult.push_back(*setIterator);
        }
        
        return vecResult;
    }
};

/*

一开始就想到正确思路，这个倒是可以赞一个，但是过程耽误了几天，该打！

在图中，每次都除去度为 1 的所有点，直到剩下最后的度为 1 的所有的点集，即是最终结果。

因为无论以哪个点为根，叶节点都是最小高度所必须要到达的点，设最小高度为 n，则按照上述策略，第 n-1 次后，一定剩下的是度为 1 的，满足条件的根节点。

不可能在这之前出现度为 0 的点，否则一定有多个联通分量。

还有该打的一点：只有 1 个点且不含有边的图，也是树，没有考虑此边界条件，所以第一次提交时 Runtime Error

*/
