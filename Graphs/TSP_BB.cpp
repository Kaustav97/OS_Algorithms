#include <bits/stdc++.h>
using namespace std;

int V;

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do
    {

        // store current Path weight(cost)
        int current_pathweight = 0;

        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        // update minimum
        min_path = min(min_path, current_pathweight);

    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

// driver program to test above function
int main()
{
    // matrix representation of graph
    V=4
    int graph[][V] = {{0, 4, 2, 1},
                      {4, 0, 1, 2},
                      {2, 1, 0, 5},
                      {1, 2, 5, 0}
                      };
    int s = 0;
    cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}
