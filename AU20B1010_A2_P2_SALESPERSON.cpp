#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int min_cost = INT_MAX;
int path[7];
bool visited_path[6];

void temp_path(int current_path[])
{
    /*
    this function initially stores a temporary path
    after that as per the short path gets noticed it will be overwritten
    */
    for (int i = 0; i < 6; i++)
    {
        path[i] = current_path[i];
    }
}

int cost(int route[6][6], int temp)
{
    /*
    this function return an initial cost of salesman's path
    */

    int minimum = INT_MAX;
    for (int k = 0; k < 6; k++)
    {
        if (route[temp][k] < minimum && temp != k)
        {
            minimum = route[temp][k];
        }
    }
    return minimum;
}

int minimum_cost(int route[6][6], int i)
{
    /*
    this function returns the shortest cost of the path
    after comparing the cost from "cost" function
    */

    int first = INT_MAX, second = INT_MAX;
    int min;
    for (int j = 0; j < 6; j++)
    {
        if (i == j)
        {
            continue;
        }

        if (route[i][j] <= first)
        {
            second = first;
            first = route[i][j];
        }
        else if (route[i][j] <= second && route[i][j] != first)
        {
            second = route[i][j];
        }

        min = min + second;
    }
    return second;
}

void path_record(int root[6][6], int temp, int weight, int level, int direction[])
{
    /*
    this function is used for recording the shortest path
    from where the salesperson can go from
    */

    if (level == 6)
    {
        if (root[direction[level - 1]][direction[0]] != 0)
        {
            int result = weight + root[direction[level - 1]][direction[0]];

            if (result < min_cost)
            {
                temp_path(direction);
                min_cost = result;
            }
        }
        return;
    }

    for (int i = 0; i < 6; i++)
    {

        if (root[direction[level - 1]][i] != 0 && visited_path[i] == false)
        {
            int a = temp;
            weight += root[direction[level - 1]][i];

            if (level - 1)
            {
                temp -= ((cost(root, direction[level - 1]) + cost(root, i)) / 2);
            }
            else
            {
                temp -= ((minimum_cost(root, direction[level - 1]) + cost(root, i)) / 2);
            }

            if (temp + weight < min_cost)
            {
                direction[level] = i;
                visited_path[i] = true;

                path_record(root, temp, weight, level + 1, direction);
            }

            weight -= root[direction[level - 1]][i];
            temp = temp;

            memset(visited_path, false, sizeof(visited_path));
            for (int j = 0; j <= level - 1; j++)
            {
                visited_path[direction[j]] = true;
            }
        }
    }
}

void traveller(int root[6][6])
{
    int direction[7];
    int temp = 0;

    memset(direction, -1, sizeof(direction));
    memset(visited_path, 0, sizeof(direction));

    for (int i = 0; i < 6; i++)
    {
        temp += (cost(root, i) + minimum_cost(root, i));
    }
    temp = (temp & 1) ? temp / 2 + 1 : temp / 2;

    visited_path[0] = true;
    direction[0] = 0;

    path_record(root, temp, 0, 1, direction);
}

int main()
{
    int distance[6][6] = {{0, 7, 9, 21, 23, 14},
                          {7, 0, 10, 15, 21, 12},
                          {9, 10, 0, 12, 11, 2},
                          {21, 15, 12, 0, 6, 14},
                          {23, 21, 11, 6, 0, 9},
                          {14, 12, 2, 14, 9, 0}};

    traveller(distance);
    cout << "minimum cost -> " << min_cost << endl;
    cout << "New Path -> ";

    for (int i = 0; i <= 6; i++)
    {
        cout << path[i];
    }

    return 0;
}
