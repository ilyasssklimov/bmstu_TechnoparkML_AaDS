#include "list.h"


ListGraph::ListGraph(int vert_num)
{
    vertices.resize(vert_num);
}


ListGraph::ListGraph(const IGraph &graph)
{
    vertices.resize(graph.VerticesCount());
    
    for (int i = 0; i < graph.VerticesCount(); i++)
        vertices[i] = graph.GetNextVertices(i);
}


int ListGraph::VerticesCount() const
{
    return vertices.size();
}


void ListGraph::AddEdge(int from, int to)
{
    vertices[from].push_back(to);
}


std::vector<int> ListGraph::GetNextVertices(int vertex) const
{
    std::vector<int> children = vertices[vertex];
    return children;
}


std::vector<int> ListGraph::GetPrevVertices(int vertex) const 
{
    std::vector<int> parents;

    for (int i = 0; i < VerticesCount(); i++) 
        for (auto &child: vertices[i]) 
            if (child == vertex) 
            {
                parents.push_back(i);
                break;
            }
        
    return parents;
}
