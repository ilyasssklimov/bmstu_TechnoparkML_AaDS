#ifndef __MATRIX_H__
#define __MATRIX_H__


#include "../base/base.h"


class MatrixGraph: public IGraph
{   
public:
    MatrixGraph(int vert_num);
    MatrixGraph(const IGraph &graph);
    
    ~MatrixGraph() override = default;
    
    int VerticesCount() const override;
    void AddEdge(int from, int to) override;
    
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
    
private:
    std::vector<std::vector<bool>> vertices;
};


#endif