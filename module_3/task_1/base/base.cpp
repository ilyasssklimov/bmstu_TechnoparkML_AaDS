#include "base.h"
#include <queue>


static void dfs_aux(const IGraph &graph, int vertex, std::vector<bool> &visited, void (*callback)(int v)) 
{
    visited[vertex] = true;
    
    callback(vertex);

    std::vector<int> children = graph.GetNextVertices(vertex);
    
    for (auto &child: children)
        if (!visited[child])
            dfs_aux(graph, child, visited, callback);
}


void dfs(const IGraph &graph, void (*callback)(int v)) 
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int vertex = 0; vertex < graph.VerticesCount(); vertex++)
        if (!visited[vertex])
            dfs_aux(graph, vertex, visited, callback);
}


void bfs(const IGraph &graph, void (*callback)(int v)) 
{
    std::vector<bool> visited(graph.VerticesCount(), false);
    
    std::queue<int> q;
    int cur = 0;

    for (int vertex = 0; vertex < graph.VerticesCount(); vertex++) 
    {
        if (!visited[vertex]) 
        {
            visited[vertex] = true;
            q.push(vertex);
            
            while (!q.empty()) 
            {
                cur = q.front();
                q.pop();
                
                callback(cur);
                
                std::vector<int> children = graph.GetNextVertices(cur);
                
                for (auto &child: children) 
                    if (!visited[child])
                    {
                        visited[child] = true;
                        q.push(child);
                    }
            }
        }
    }
}