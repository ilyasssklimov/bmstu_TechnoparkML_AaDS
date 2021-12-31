#include "matrix.h"


MatrixGraph::MatrixGraph(int vert_num)
{
    vertices.resize(vert_num);
    
    for (auto& vertex: vertices)
        vertex.resize(vert_num, false);
}


MatrixGraph::MatrixGraph(const IGraph &graph)
{    
    vertices.resize(graph.VerticesCount());
    
    for (int i = 0; i < graph.VerticesCount(); i++) 
    {
        vertices[i].resize(graph.VerticesCount(), false);
        
        for(auto &vertex: graph.GetNextVertices(i))
            vertices[i][vertex] = true;
    }

}
    
    
int MatrixGraph::VerticesCount() const 
{
    return vertices.size();
}


void MatrixGraph::AddEdge(int from, int to) 
{
    vertices[from][to] = true;
}


std::vector<int> MatrixGraph::GetNextVertices(int vertex) const 
{
    std::vector<int> children;
    
    for (int i = 0; i < vertices[vertex].size(); i++)
        if (vertices[vertex][i])
            children.push_back(i);
    
    return children;
}


std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const 
{
    std::vector<int> parents;

    for (int i = 0; i < vertices.size(); i++)
        if (vertices[i][vertex])
            parents.push_back(i);
    
    return parents;
}
