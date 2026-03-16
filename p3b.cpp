#include <iostream>
#include <cstdlib>
#define INF 0x3f3f3f3f
using namespace std;

const int n = 10; // number of stopping points

//void diagonal(int matrix[][n])
//{
//	for (int i = 0; i < n; i++)
//	{
//		matrix[i][i] = 0;
//	}
//}
//
//void infinite(int matrix[][n])
//{
//	int m = 999;
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 0; j <= i - 1; j++)
//		{
//			matrix[i][j] = m;
//		}
//	}
//}
//
//void weight(int matrix[][n])
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			matrix[i][j] = (rand() % 99 + 1) * 10;
//		}
//	}
//}
// 
// 
// cost matrix

//int matrix[n][n] = { {0,100,20,300,400,500,600,700},
//{INF,0,50,10,100,200,300,400},
//{INF,INF,0,30,10,90,10,150},
//{INF,INF,INF,0,80,160,240,320},
//{INF,INF,INF,INF,0,120,240,600},
//{INF,INF,INF,INF,INF,0,120,240},
//{INF,INF,INF,INF,INF,INF,0,120},
//{INF,INF,INF,INF,INF,INF,INF,0} 
//};
int matrix[n][n] = {
    {0,100,200,40,250,300,400,500,600,700},
{INF,0,50,10,100,200,300,400,500,600},
{INF,INF,0,30,10,90,10,150,200,250},
{INF,INF,INF,0,80,160,240,320,400,430},
{INF,INF,INF,INF,0,120,240,600,650,700},
{INF,INF,INF,INF,INF,0,120,240,300,350},
{INF,INF,INF,INF,INF,INF,0,120,140,160},
{INF,INF,INF,INF,INF,INF,INF,0,200,400},
{INF,INF,INF,INF,INF,INF,INF,INF,0,400},
{INF,INF,INF,INF,INF,INF,INF,INF,INF,0}
};

// Dijkstra's algorithm to find the shortest path
int dijkstra(int start, int end) {
    int dist[n];
    bool visited[n];
    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        // find the unvisited node with the smallest distance from the starting point
        int minDist = INF, u;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        // mark the selected node as visited
        visited[u] = true;

        // update the distances of the neighbors of the selected node
        for (int v = 0; v < n; ++v) {
            if (matrix[u][v] != INF && dist[v] > dist[u] + matrix[u][v]) {
                dist[v] = dist[u] + matrix[u][v];
            }
        }
    }

    return dist[end];
}

int main() {
    int start = 0, end = n - 1;
    int shortestPath = dijkstra(start, end);
    cout << "Optimal cost: " << shortestPath << endl;

    //diagonal(matrix);
	//infinite(matrix);
	//weight(matrix);


    // Find the optimal path using Dijkstra's algorithm
    int path[n], len = 0;
    int cur = end;
    while (cur != start) {
        path[len++] = cur;
        for (int i = 0; i < n; ++i) {
            if (matrix[i][cur] != INF && dijkstra(start, cur) == dijkstra(start, i) + matrix[i][cur]) {
                cur = i;
                break;
            }
        }
    }
    path[len++] = start;

    // Print the optimal path
    cout << "Optimal path: ";
    for (int i = len - 1; i >= 0; --i) {
        cout << path[i] + 1;
        if (i != 0) cout << "->";
    }
    cout << endl;

    return 0;
}