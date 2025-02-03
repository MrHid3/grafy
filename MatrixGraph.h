#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H
#pragma once
#include "ListGraph.h"
#include <fstream>

class MatrixGraph {
public:
	std::vector<std::vector<int>> graph;
	MatrixGraph() {
		this->graph = {};
	}
	explicit MatrixGraph(std::vector<std::vector<int>> matrix) {
		this->graph = std::move(matrix);
	}
	explicit MatrixGraph(const std::string& directory){
		std::ifstream f(directory);
		if (!f.is_open()) {
			this->graph = {};
			return;
		}
		std::vector<std::string> text;
		std::string line;
		while (std::getline(f, line)){
			text.push_back(line);
		}
		if (text.size() == 0){
			this->graph = {};
			return;
		}
		int length = text[0].size();
		for (int i = 0; i < text.size(); i++){
			if (text[i].size() != length){
				this->graph = {};
				return;
			}
			this->graph.push_back({});
			std::string current = "";
			for (int j = 0; j < text[i].size(); j++){
				if (text[i][j] == ' '){
					this->graph[i].push_back(stoi(current));
					current = "";
				}else{
					current += text[i][j];
				}
			}
			this->graph[i].push_back(stoi(current));
		}
	}
	explicit MatrixGraph(ListGraph graph);
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
