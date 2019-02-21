#include "igraph.h"
#include <unordered_set>

class SetGraph : public IGraph {
public:
    SetGraph(int vertices_count);
    SetGraph(const IGraph* old_graph);
    
    ~SetGraph() override;
    SetGraph(const SetGraph& set_graph);
    SetGraph& operator=(const SetGraph& set_graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
private:
    std::vector<std::unordered_set<int>> children;
};
