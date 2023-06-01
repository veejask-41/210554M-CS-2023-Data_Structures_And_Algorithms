#include <iostream>
#include <stdio.h>
using namespace std;
#define INFINITY 9999
#define MAX 6

void Dijkstra(int Graph[MAX][MAX], int startNode)
{

    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Creating cost matrix
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];

    // Initializing pred[], distance[] and visited[]
    for (i = 0; i < MAX; i++)
    {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = 0;
    }

    distance[startNode] = 0;
    visited[startNode] = 1;
    count = 1;

    while (count < MAX - 1)
    {
        mindistance = INFINITY;

        // Nextnode gives the node at minimum distance
        for (i = 0; i < MAX; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }

        // Check if a better path exists through nextnode
        visited[nextnode] = 1;
        for (i = 0; i < MAX; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    // printing the average value from startNode to all other nodes
    int sum = 0;
    for (i = 0; i < MAX; i++)
        if (i != startNode)
            sum += distance[i];
    cout << "Average value from startNode to all other nodes = " << sum / (MAX - 1) << endl;

    // Printing the distance
    for (i = 0; i < MAX; i++)
        if (i != startNode)
        {
            cout << "\nDistance of node " << i << " = " << distance[i];
            cout << "\nPath = " << i;
            j = i;
            do
            {
                j = pred[j];
                cout << " <- " << j;
            } while (j != startNode);
        }
};

int main()
{
    int Graph[MAX][MAX] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}};

    for (int startNode = 0; startNode < MAX; startNode++)
    {
        cout << "\n\nFor node " << startNode << endl;
        Dijkstra(Graph, startNode);
    }

    return 0;
}