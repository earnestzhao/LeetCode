class Solution
{
public:
        
    vector<int> eventualSafeNodes(vector<vector<int>> & graph)
    {
        queue<int>          queueDegreeZero;
        vector<int>         vecOutDegree(graph.size(), 0);
        vector<vector<int>> vecInGraph(graph.size(), vector<int>());

        for (int iIndex = 0; iIndex < graph.size(); iIndex ++)
        {
            vecOutDegree[iIndex] = graph[iIndex].size();
            
            if (vecOutDegree[iIndex] == 0)
            {
                queueDegreeZero.push(iIndex);
            }

            for (int jIndex = 0; jIndex < graph[iIndex].size(); jIndex ++)
            {
                vecInGraph[graph[iIndex][jIndex]].push_back(iIndex);
            }
        }

        vector<int> vecResult;

        while (!queueDegreeZero.empty())
        {
            int iVertexZeroDegree = queueDegreeZero.front();
            vecResult.push_back(iVertexZeroDegree);
            queueDegreeZero.pop();

            for (int iIndex = 0; iIndex < vecInGraph[iVertexZeroDegree].size(); iIndex ++)
            {
                if (-- vecOutDegree[vecInGraph[iVertexZeroDegree][iIndex]] == 0)
                {
                    queueDegreeZero.push(vecInGraph[iVertexZeroDegree][iIndex]);
                }
            }
        }

        sort(vecResult.begin(), vecResult.end());
        return vecResult;
    }
};

