#include<iostream>
using namespace std;
int vertex_array[7][7]; //the adjacency matrix initially 0
int count = 0;
void display(int v) {
    int i, j;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            cout << vertex_array[i][j] << " ";
        }
        cout << endl;
    }
}
void parse_edge(int u, int v, int w) {       //function to add edge into the matrix
    vertex_array[u][v] = w;
    vertex_array[v][u] = w;
}
int main(int argc, char* argv[]) {
    int v = 7;    //there are 6 vertices in the graph
    cout << "Below is the Adjacency Matrix of the Given Weighted Graph" << endl;

    parse_edge(1, 2, 30);
    parse_edge(1, 3, 15);
    parse_edge(1, 4, 10);
    parse_edge(2, 4, 25);
    parse_edge(2, 5, 60);
    parse_edge(3, 4, 40);
    parse_edge(3, 6, 20);
    parse_edge(4, 7, 35);
    parse_edge(5, 7, 20);

    display(v);
}