#ifndef __ARC_H__
#define __ARC_H__


#include "../base/base.h"
#include <unordered_set>


class ArcGraph: public IGraph 
{
public:
    ArcGraph(const IGraph &graph);
    ~ArcGraph() override = default;
    
    int VerticesCount() const override;
    void AddEdge(int from, int to) override;
    
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> edges;
};

#endif