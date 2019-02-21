#include "../headers/arc-graph.h"

ArcGraph::ArcGraph(int vertices_count) : vertices_count(vertices_count) {
    edges.resize(static_cast<unsigned long>(vertices_count));
}

ArcGraph::ArcGraph(const IGraph *old_graph) {
    vertices_count = old_graph->VerticesCount();
    edges.resize(static_cast<unsigned long>(old_graph->VerticesCount()));

    std::vector<int> vertices;
    for (int from = 0; from < old_graph->VerticesCount(); ++from) {
        old_graph->GetNextVertices(from, vertices);
        for (int to : vertices) {
            AddEdge(from, to);
        }
    }
}

ArcGraph::~ArcGraph() = default;

ArcGraph::ArcGraph(const ArcGraph& arc_graph) {
    vertices_count = arc_graph.VerticesCount();
    edges.resize(static_cast<unsigned long>(arc_graph.VerticesCount()));

    std::vector<int> vertices;
    for (int from = 0; from < arc_graph.VerticesCount(); ++from) {
        arc_graph.GetNextVertices(from, vertices);
        for (int to : vertices) {
            AddEdge(from, to);
        }
    }
}

ArcGraph& ArcGraph::operator=(const ArcGraph& arc_graph) {
    if (this == &arc_graph) {
        return *this;
    }

    vertices_count = arc_graph.VerticesCount();
    edges.resize(static_cast<unsigned long>(arc_graph.VerticesCount()));

    std::vector<int> vertices;
    for (int from = 0; from < arc_graph.VerticesCount(); ++from) {
        arc_graph.GetNextVertices(from, vertices);
        for (int to : vertices) {
            AddEdge(from, to);
        }
    }

    return *this;
}

void ArcGraph::AddEdge(int from, int to) {
    edges.push_back(std::make_pair(from, to));
}

int ArcGraph::VerticesCount() const {
    return vertices_count;
}

void ArcGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();

    for (int edge = 0; edge < edges.size(); ++edge) {
        if (edges[edge].first == vertex) {
            vertices.push_back(edges[edge].second);
        }
    }
}

void ArcGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();

    for (int edge = 0; edge < edges.size(); ++edge) {
        if (edges[edge].second == vertex) {
            vertices.push_back(edges[edge].first);
        }
    }
}
