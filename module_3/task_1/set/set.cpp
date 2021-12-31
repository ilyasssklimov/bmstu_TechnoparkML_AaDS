#include "set.h"


SetGraph::SetGraph(int vert_num) 
{
    vertices.resize(vert_num);
}


SetGraph::SetGraph(const IGraph &graph) 
{
    vertices.resize(graph.VerticesCount());
    
    for (int i = 0; i < graph.VerticesCount(); i++) 
    {
        std::vector<int> children = graph.GetNextVertices(i);
        for (auto &child: children)
            vertices[i].insert(child);
    }
}

int SetGraph::VerticesCount() const
{
    return vertices.size();
}


void SetGraph::AddEdge(int from, int to) 
{
    vertices[from].insert(to);
}


std::vector<int> SetGraph::GetNextVertices(int vertex) const
{
    std::vector<int> children;
    
    for (auto child: vertices[vertex])
        children.push_back(child);
        
    return children;
}


std::vector<int> SetGraph::GetPrevVertices(int vertex) const 
{
    std::vector<int> parents;
    
    for (int i = 0; i < vertices.size(); i++)
        for (auto child : vertices[i])
            if (child == vertex)
                parents.push_back(i);
    
    return parents;
}