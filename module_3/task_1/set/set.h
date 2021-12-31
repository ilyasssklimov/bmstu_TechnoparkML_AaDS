#ifndef __SET_H__
#define __SET_H__


#include "../base/base.h"
#include <unordered_set>


class SetGraph: public IGraph
{   
public:
    SetGraph(int vert_num);
    SetGraph(const IGraph &graph);
    
    ~SetGraph() override = default;
    
    int VerticesCount() const override;
    void AddEdge(int from, int to) override;
    
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
    
private:
    std::vector<std::unordered_set<int>> vertices;
};


#endif