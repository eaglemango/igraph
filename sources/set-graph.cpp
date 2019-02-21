#include "../headers/set-graph.h"

SetGraph::SetGraph(int vertices_count) {
    children.resize(static_cast<unsigned long>(vertices_count));
}

SetGraph::SetGraph(const IGraph* old_graph) {
    children.resize(static_cast<unsigned long>(old_graph->VerticesCount()));

   std::vector<int> vertices;
   for (int from = 0; from < old_graph->VerticesCount(); ++from) {
       old_graph->GetNextVertices(from, vertices);
       for (int to : vertices) {
           AddEdge(from, to);
       }
   }
}

SetGraph::~SetGraph() = default;

SetGraph::SetGraph(const SetGraph& set_graph) {
    children.resize(static_cast<unsigned long>(set_graph.VerticesCount()));

    std::vector<int> vertices;
    for (int from = 0; from < set_graph.VerticesCount(); ++from) {
        set_graph.GetNextVertices(from, vertices);
        for (int to : vertices) {
            AddEdge(from, to);
        }
    }
}

SetGraph& SetGraph::operator=(const SetGraph& set_graph) {
    if (this == &set_graph) {
        return *this;
    }

    children.resize(static_cast<unsigned long>(set_graph.VerticesCount()));

    std::vector<int> vertices;
    for (int from = 0; from < set_graph.VerticesCount(); ++from) {
        set_graph.GetNextVertices(from, vertices);
        for (int to : vertices) {
            AddEdge(from, to);
        }
    }

    return *this;
}

void SetGraph::AddEdge(int from, int to) {
    children[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(children.size());
}

void SetGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();

    for (int to : children[vertex]) {
        vertices.push_back(to);
    }
}

void SetGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();

    for (int from = 0; from < VerticesCount(); ++from) {
        if (children[from].find(vertex) != children[from].end()) {
            vertices.push_back(from);
        }
    }
}
