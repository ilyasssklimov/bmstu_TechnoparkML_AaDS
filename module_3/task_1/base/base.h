#ifndef __BASE_H__
#define __BASE_H__


#include <iostream>
#include <vector>


struct IGraph 
{
    virtual ~IGraph() {}
    virtual void AddEdge(int from, int to) = 0;

	virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};


void dfs(const IGraph &graph, void (*callback)(int v));
void bfs(const IGraph &graph, void (*callback)(int v));


#endif
