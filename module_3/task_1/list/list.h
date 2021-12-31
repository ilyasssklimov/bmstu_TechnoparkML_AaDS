#ifndef __LIST_H__
#define __LIST_H__


#include "../base/base.h"


class ListGraph: public IGraph
{   
public:
    ListGraph(int vert_num);
    ListGraph(const IGraph &graph);
    
    ~ListGraph() override = default;
    
    int VerticesCount() const override;
    void AddEdge(int from, int to) override;
    
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
    
private:
    std::vector<std::vector<int>> vertices;
};


#endif
