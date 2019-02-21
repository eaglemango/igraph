#include "igraph.h"

class MatrixGraph : public IGraph {
public:
    MatrixGraph(int vertices_count);
    MatrixGraph(const IGraph* old_graph);
    
    ~MatrixGraph() override;
    MatrixGraph(const MatrixGraph& matrix_graph);
    MatrixGraph& operator=(const MatrixGraph& matrix_graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
private:
    std::vector<std::vector<int>> matrix;
};
