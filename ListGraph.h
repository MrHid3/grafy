#ifndef LISTGRAPH_H
#define LISTGRAPH_H
#pragma once
#include <fstream>

class MatrixGraph;

class ListGraph {
public:
	std::map<int, std::vector<int>> graph;
	ListGraph() {
		this->graph = std::map<int, std::vector<int>>();
	}
	explicit ListGraph(std::map<int, std::vector<int>> graph) {
		this->graph = std::move(graph);
	}
	explicit ListGraph(const std::string& directory){
		std::ifstream f(directory);
		if (!f.is_open()) {
			this->graph = std::map<int, std::vector<int>>();
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
		for (int i = 0; i < text.size(); i++){
			std::string current = "";
			int start, key;
			for (int j = 0; j < text[i].size(); j++){
				if (text[i][j] == ':'){
					key = stoi(current);
					start = j + 1;
				}else{
					current += text[i][j];
				}
			}
			// this->graph.push_back({});
			current = "";
			for (int j = start; j < text[i].size(); j++){
				if (text[i][j] == ','){
					this->graph[key].push_back(stoi(current));
					current = "";
				}else{
					current += text[i][j];
				}
			}
			// this->graph[i].push_back(stoi(current));
		}
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
