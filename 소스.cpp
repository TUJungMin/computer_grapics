#include <stdio.h>
#define N 8
// �����Լ����� ȣ���ؾ� �ϹǷ� � ������ �ʿ��� �� ���� ���Ͽ� ����
int solveKTUtil(int x, int y, int movei, int sol[N][N],
    int xMove[], int yMove[]);

int isSafe(int x, int y, int sol[N][N])
{// X, Y�� �־��� ���� �������, �̹� ������ ������ �˻��Ѵ�.
    return (x >= 0 && x < N&& y >= 0 && y < N&& sol[x][y] == -1);
}

void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            printf(" %2d", sol[x][y]);
        }
        printf("\n");
    }
}

int solveKT()
{
    int sol[N][N];

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            sol[x][y] = -1;  // �� ���� ���� �ʱ�ȭ
        }
    }

    // Knight�� �� ���� ������ �� �ִ� x, y �Ÿ��� �迭�� ����
    int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

    sol[0][0] = 0; // Knight�� ������ �ʱ�ȭ

    // ���� Ž���� ���� ������ ����� ���ٸ�
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0)
    {
        printf("There's no Solution"); // ���� ������ ���
        return 0;
    }
    else // ��� Ž�� �� �ش��� ������ ��ȯ�ϸ�
    {
        printSolution(sol); // Knight�� ��� ���
    }
    return 1;
}

// ��� Ž���� ������ �Լ� ����
// ���� ��ǥ, �� ��° ����������, ��ü ��, ������ �� �ִ� �Ÿ� �ʿ�
int solveKTUtil(int x, int y, int movei, int sol[N][N],
    int xMove[8], int yMove[8])
{
    int k, next_x, next_y;
    if (movei == N * N) // ���� ��� ���� ���ĿԴٸ�
    {
        return 1; // Ž���� ����
    }

    for (k = 0; k < 8; k++) // Knight�� ������ �� �ִ� ��� ��쿡 ����
    {
        next_x = x + xMove[k]; // ���� x ��ǥ�� ������ �ݿ�
        next_y = y + yMove[k]; // ���� y ��ǥ�� ������ �ݿ�

        if (isSafe(next_x, next_y, sol)) // �ݿ��� ��ǥ�� �������� �˻�
        {
            sol[next_x][next_y] = movei; // �����ϸ� ���� ���������� �ݿ�
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                xMove, yMove) == 1)
            { // ���� �ܰ�κ��� �ع��� ������ ��ȯ������
                return 1; // ���� �ܰ�� �ö� �ع��� ������ ��ȯ
            }
            else // ���� �ع��� ���ٰ� ��ȯ ������ 
            {
                sol[next_x][next_y] = -1; // backtracking
            }
        }
    }
    return 0;
}

int main()
{
    solveKT();
    return 0;
}
