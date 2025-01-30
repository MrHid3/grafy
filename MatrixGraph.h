#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H
#pragma once
#include "ListGraph.h"

class MatrixGraph {
public:
	std::vector<std::vector<int>> graph;
	MatrixGraph() {
		this->graph = {};
	}
	MatrixGraph(std::vector<std::vector<int>> matrix) {
		this->graph = std::move(matrix);
	}
	MatrixGraph(ListGraph graph);
	void print() {
		std::cout << "  ";
		for (int i = 0; i < graph.size(); i++)
			std::cout << i << " ";
		std::cout << "\n";
		for (int i = 0; i < graph.size(); i++) {
			std::cout << i << " ";
			for (int j = 0; j < graph[i].size(); j++)
				std::cout << graph[i][j] << " ";
			std::cout << "\n";
		}
	}
};

#endif //MATRIXGRAPH_H
