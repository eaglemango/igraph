#include "igraph.h"

struct ArcGraph : public IGraph {
public:
    ArcGraph(int vertices_count);
    ArcGraph(const IGraph* old_graph);
    ~ArcGraph() override;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
private:
    int vertices_count;
    std::vector<std::pair<int, int>> edges;
};
