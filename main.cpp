#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class ListGraph {
public:
    map<int, vector<int>> graph;
    ListGraph() {
        this->graph = map<int, vector<int>>();
    }
    ListGraph(map<int, vector<int>> graph) {
        this->graph = graph;
    }
    void print(){
        for(int, vector<int> : this->graph){

    }
};

class MatrixGraph {
public:
    MatrixGraph() {
        this->graph = {};
    }
    MatrixGraph(vector<vector<int>> matrix) {
        this->graph = std::move(matrix);
    }
    vector<vector<int>> graph;
    void print() {
        cout << "  ";
        for (int i = 0; i < graph.size(); i++)
            cout << i << " ";
        cout << endl;
        for (int i = 0; i < graph.size(); i++) {
            cout << i << " ";
            for (int j = 0; j < graph[i].size(); j++)
                cout << graph[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    MatrixGraph eskib;
    eskib = MatrixGraph({{0, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 1}, {0, 0, 1, 0}});
    eskib.print();
    return 0;
}
