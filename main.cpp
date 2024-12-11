#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class ListGraph {
    set<int> graph;
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
