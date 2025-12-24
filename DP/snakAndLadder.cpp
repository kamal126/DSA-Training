#include <bits/stdc++.h>
using namespace std;


int snakAndLadder(int N, int arr[])
{
    const int SIZE = 30;
    vector<int> move(SIZE, -1);

    // Build snakes & ladders
    for (int i = 0; i < 2 * N; i += 2)
    {
        move[arr[i]] = arr[i + 1];
    }

    vector<bool> visited(SIZE, false);
    queue<pair<int, int>> q;

    visited[0] = true;
    q.push({0, 0});

    while (!q.empty())
    {
        int currPos = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (currPos == SIZE - 1)
        {
            return steps;
        }

        for (int i = 1; i <= 6 && currPos + i < SIZE; i++)
        {
            int nextPos = currPos + i;
            int dest = (move[nextPos] != -1) ? move[nextPos] : nextPos;

            if (!visited[dest])
            {
                visited[dest] = true;
                q.push({dest, steps + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int N = 8;
    int arr[] = {3, 22, 5, 8, 11, 26, 20, 29, 17, 4, 19, 7, 27, 1, 21, 9};

    cout << snakAndLadder(N, arr);

    return 0;
}