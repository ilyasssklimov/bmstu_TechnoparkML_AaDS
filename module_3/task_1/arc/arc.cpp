#include "arc.h"


ArcGraph::ArcGraph(const IGraph &graph) 
{
    for (int i = 0; i < graph.VerticesCount(); i++) 
    {
        std::vector<int> children = graph.GetNextVertices(i);
        
        for (auto &child: children) 
            edges.push_back(std::make_pair(i, child));
    }
}


int ArcGraph::VerticesCount() const 
{
    std::unordered_set<int> vertices;

    for (auto &edge: edges)
    {
        vertices.insert(edge.first);
        vertices.insert(edge.second);
    }
    
    return vertices.size();
}


void ArcGraph::AddEdge(int from, int to) 
{
    edges.push_back(std::make_pair(from, to));
}


std::vector<int> ArcGraph::GetNextVertices(int vertex) const 
{
    std::vector<int> children;

    for (auto& edge: edges)
        if (edge.first == vertex)
            children.push_back(edge.second);
    
    return children;
}


std::vector<int> ArcGraph::GetPrevVertices(int vertex) const 
{
    std::vector<int> parents;
    
    for(auto& edge: edges)
        if (edge.second == vertex)
            parents.push_back(edge.first);
    
    return parents;
}