#include "../headers/matrix-graph.h"

MatrixGraph::MatrixGraph(int vertices_count) {
    matrix.resize(static_cast<unsigned long>(vertices_count));

    for (int i = 0; i < vertices_count; ++i) {
        matrix[i].resize(static_cast<unsigned long>(vertices_count), 0);
    }
}

MatrixGraph::MatrixGraph(const IGraph *old_graph) {
    matrix.resize(static_cast<unsigned long>(old_graph->VerticesCount()));

    for (int i = 0; i < old_graph->VerticesCount(); ++i) {
        matrix[i].resize(static_cast<unsigned long>(old_graph->VerticesCount()));
    }

    std::vector<int> vertices;
    for (int from = 0; from < old_graph->VerticesCount(); ++from) {
        old_graph->GetNextVertices(from, vertices);
        for (int to : vertices) {
            AddEdge(from, to);
        }
    }
}

MatrixGraph::~MatrixGraph() = default;

MatrixGraph::MatrixGraph(const MatrixGraph& matrix_graph) {
    matrix.resize(static_cast<unsigned long>(matrix_graph.VerticesCount()));

    for (int i = 0; i < matrix_graph.VerticesCount(); ++i) {
        matrix[i].resize(static_cast<unsigned long>(matrix_graph.VerticesCount()));
    }

    std::vector<int> vertices;
    for (int from = 0; from < matrix_graph.VerticesCount(); ++from) {
        matrix_graph.GetNextVertices(from, vertices);
        for (int to : vertices) {
            AddEdge(from, to);
        }
    }
}

MatrixGraph& MatrixGraph::operator=(const MatrixGraph& matrix_graph) {
    if (this == &matrix_graph) {
        return *this;
    }

    for (int i = 0; i < matrix_graph.VerticesCount(); ++i) {
        matrix[i].resize(static_cast<unsigned long>(matrix_graph.VerticesCount()));
    }

    std::vector<int> vertices;
    for (int from = 0; from < matrix_graph.VerticesCount(); ++from) {
        matrix_graph.GetNextVertices(from, vertices);
        for (int to : vertices) {
            AddEdge(from, to);
        }
    }

    return *this;
}

void MatrixGraph::AddEdge(int from, int to) {
    matrix[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(matrix.size());
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();

    for (int to = 0; to < VerticesCount(); ++to) {
        if (matrix[vertex][to] != 0) {
            vertices.push_back(to);
        }
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();

    for (int from = 0; from < VerticesCount(); ++from) {
        if (matrix[from][vertex] != 0) {
            vertices.push_back(from);
        }
    }
}
