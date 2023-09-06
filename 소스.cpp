#include <stdio.h>
#define N 8
// 메인함수에서 호출해야 하므로 어떤 조건이 필요한 지 먼저 명세하여 정의
int solveKTUtil(int x, int y, int movei, int sol[N][N],
    int xMove[], int yMove[]);

int isSafe(int x, int y, int sol[N][N])
{// X, Y가 주어진 셀을 벗어나는지, 이미 지나간 곳인지 검사한다.
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
            sol[x][y] = -1;  // 각 셀에 대해 초기화
        }
    }

    // Knight가 한 번에 움직일 수 있는 x, y 거리를 배열로 정의
    int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

    sol[0][0] = 0; // Knight의 시작점 초기화

    // 만약 탐색이 끝날 때까지 결과가 없다면
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0)
    {
        printf("There's no Solution"); // 답이 없음을 출력
        return 0;
    }
    else // 재귀 탐색 중 해답이 있음를 반환하면
    {
        printSolution(sol); // Knight의 경로 출력
    }
    return 1;
}

// 재귀 탐색을 진행할 함수 정의
// 현재 좌표, 몇 번째 움직임인지, 전체 맵, 움직일 수 있는 거리 필요
int solveKTUtil(int x, int y, int movei, int sol[N][N],
    int xMove[8], int yMove[8])
{
    int k, next_x, next_y;
    if (movei == N * N) // 만약 모든 셀을 거쳐왔다면
    {
        return 1; // 탐색을 종료
    }

    for (k = 0; k < 8; k++) // Knight가 움직일 수 있는 모든 경우에 대해
    {
        next_x = x + xMove[k]; // 다음 x 좌표에 움직임 반영
        next_y = y + yMove[k]; // 다음 y 좌표에 움직임 반영

        if (isSafe(next_x, next_y, sol)) // 반영된 좌표가 가능한지 검사
        {
            sol[next_x][next_y] = movei; // 가능하면 다음 움직임으로 반영
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                xMove, yMove) == 1)
            { // 이후 단계로부터 해법이 있음을 반환받으면
                return 1; // 이전 단계로 올라가 해법이 있음을 반환
            }
            else // 만약 해법이 없다고 반환 받으면 
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
