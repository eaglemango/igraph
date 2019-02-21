#include "igraph.h"

class ListGraph : public IGraph {
public:
    ListGraph(int vertices_count);
    ListGraph(const IGraph* old_graph);
    
    ~ListGraph() override;
    ListGraph(const ListGraph& list_graph);
    ListGraph& operator=(const ListGraph& list_graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
private:
    std::vector<std::vector<int>> children;
};
