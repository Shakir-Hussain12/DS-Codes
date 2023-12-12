#include <iostream>
using namespace std;

void show(int **arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int **arr, int N, int a, int b)
{
    int mx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int my[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int i = 0; i < 8; i++)
    {
        int x = a + mx[i];
        int y = b + my[i];

        if (x < 0 || x >= N || y < 0 || y >= N)
            continue;

        if (arr[x][y] == 1)
            return false;
    }

    return true;
}

void NKnights(int **arr, int N, int i, int j, int target)
{
    if (target == 0)
    {
        show(arr, N);
        return;
    }

    if (j == N)
    {
        j = 0;
        i += 1;
    }

    if (i == N)
        return;

    if (isSafe(arr, N, i, j))
    {
        arr[i][j] = 1;

        NKnights(arr, N, i, j + 1, target - 1);

        arr[i][j] = 0;
    }

    NKnights(arr, N, i, j + 1, target);
}

int main()
{
    int N = 8;
    int target = 32;
    int **arr = new int *[N];
    for (int i = 0; i < N; i++)
        arr[i] = new int[N]{0};

    NKnights(arr, N, 0, 0, target);
}
