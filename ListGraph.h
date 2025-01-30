#ifndef LISTGRAPH_H
#define LISTGRAPH_H
#pragma once

class MatrixGraph;

class ListGraph {
public:
	std::map<int, std::vector<int>> graph;
	ListGraph() {
		this->graph = std::map<int, std::vector<int>>();
	}
	ListGraph(std::map<int, std::vector<int>> graph) {
		this->graph = std::move(graph);
	}
	ListGraph(MatrixGraph matrix);
	void print(){
		for(auto it = graph.begin(); it != graph.end(); it++){
			std::cout << it->first << ": ";
			for(int i = 0; i < it->second.size(); i++){
				std::cout << it->second[i] << ", ";
			}
			std::cout << "\n";
		}
	}
};

#endif //LISTGRAPH_H
