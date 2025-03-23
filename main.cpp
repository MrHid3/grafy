#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "BinaryTree.h"
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
    // //matrix z argumentu
    // MatrixGraph matrix1;
    // matrix1 = MatrixGraph({{0, 1, 1, 0, 0}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}});
    // matrix1.print();
    // //lista z argumentu, nie jestem pewien jak zrobić mapę onelinerem
    // map<int, vector<int>> graph1;
    // graph1[0] = {1, 2};
    // graph1[1] = {0, 2};
    // graph1[2] = {0, 1, 3};
    // graph1[3] = {2};
    // ListGraph graph2 = ListGraph(graph1);
    // graph2.print();
    // //matrix z listy
    // MatrixGraph matrix3 = MatrixGraph(graph2);
    // matrix3.print();
    // //vice versa
    // ListGraph graph3 = ListGraph(matrix3);
    // graph3.print();
    // //lista z pliku
    // ListGraph graph4 = ListGraph("../listgraph.txt");
    // graph4.print();
    // //matrix z pliku
    // MatrixGraph matrix4 = ListGraph("../listgraph.txt");
    // matrix4.print();
    vector<int> source = {1,2 ,3 ,4, 5, 6};
    BinaryTree bt = BinaryTree(source);
    // bt.root.right->leftRotate();
    // bt.root->autobalance();
    bt.print();
    // bt.resetRoot();
    // source = bt.inorder();
    // for (int i = 0; i < source.size(); i++){
        // cout << source[i] << endl;
    // }
    return 0;
}
