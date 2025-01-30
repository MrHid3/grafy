#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include "ListGraph.h"
#include "MatrixGraph.h"
#pragma once
using namespace std;

MatrixGraph::MatrixGraph(ListGraph list){
    int listlength = 0;
    for(auto it = list.graph.begin(); it != list.graph.end(); it++){
        this->graph.push_back({});
        listlength++;
    }
    int count = 0;
    for(auto it = list.graph.begin(); it != list.graph.end(); it++){
        for(int i = 0; i < listlength; i++){
            bool real = false;
            for(int j = 0; j < it->second.size(); j++){
                if (it->second[j] == i){
                    real = true;
                    break;
                }
            }
            if (real){
                this->graph[count].push_back(1);
            }else{
                this->graph[count].push_back(0);
            }
        }
        count++;
    }
}

ListGraph::ListGraph(MatrixGraph matrix){
    for(int i = 0; i < matrix.graph.size(); i++){
        this->graph[i] = {};
        for (int j = 0; j < matrix.graph[i].size(); j++){
            if (matrix.graph[i][j] == 1){
                this->graph[i].push_back(j);
            }
        }
    }
}


int main() {
    MatrixGraph eskib;
    eskib = MatrixGraph({{0, 1, 1, 0, 0}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}});
    eskib.print();
    map<int, vector<int>> graph;
    graph[0] = {1, 2};
    graph[1] = {0, 2};
    graph[2] = {0, 1, 3};
    graph[3] = {2};
    ListGraph eskib2 = ListGraph(graph);
    eskib2.print();
    ListGraph eskib3 = ListGraph(eskib);
    eskib3.print();
    MatrixGraph eskib4 = MatrixGraph(eskib3);
    eskib4.print();
    return 0;
}
