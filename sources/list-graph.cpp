#include "../headers/list-graph.h"

ListGraph::ListGraph(int vertices_count) {
    children.resize(static_cast<unsigned long>(vertices_count));
}

ListGraph::ListGraph(const IGraph* old_graph) {
    children.resize(static_cast<unsigned long>(old_graph->VerticesCount()));

    std::vector<int> vertices;
    for (int from = 0; from < old_graph->VerticesCount(); ++from) {
        old_graph->GetNextVertices(from, vertices);
        for (int to : vertices) {
            AddEdge(from, to);
        }
    }
}

ListGraph::~ListGraph() = default;

ListGraph::ListGraph(const ListGraph& list_graph) {
    children.resize(static_cast<unsigned long>(list_graph.VerticesCount()));

    std::vector<int> vertices;
    for (int from = 0; from < list_graph.VerticesCount(); ++from) {
        list_graph.GetNextVertices(from, vertices);
        for (int to : vertices) {
            AddEdge(from, to);
        }
    }
}

ListGraph& ListGraph::operator=(const ListGraph& list_graph) {
    if (this == &list_graph) {
        return *this;
    }

    std::vector<int> vertices;
    for (int from = 0; from < list_graph.VerticesCount(); ++from) {
        list_graph.GetNextVertices(from, vertices);
        for (int to : vertices) {
            AddEdge(from, to);
        }
    }

    return *this;
}

void ListGraph::AddEdge(int from, int to) {
    children[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return static_cast<int>(children.size());
}

void ListGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();

    vertices = children[vertex];
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();

    for (int from = 0; from < VerticesCount(); ++from) {
        for (int to : children[from]) {
            if (to == vertex) {
                vertices.push_back(from);
            }
        }
    }
}
