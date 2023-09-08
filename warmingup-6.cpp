#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

#define SIZE 40
#define MAX_CONSECUTIVE_MOVES 5

void generateRandomPath(int maze[][SIZE]) {
    srand((unsigned)time(NULL));

    int x = 0, y = 0; // ������
    int value = 1; // ���۰�
    vector<pair<int, int>> path; // �̵� ��θ� �����ϴ� ����
    int consecutiveMoves = 0; // �� �������� �����ؼ� �̵��� Ƚ���� ���

    maze[x][y] = value;
    path.push_back(make_pair(x, y));

    while (true) {
        int directions[] = { 0, 1, 2, 3 }; // 0: ��, 1: ��, 2: ��, 3: ��
        for (int i = 0; i < 4; ++i) {
            int randomIndex = rand() % 4;
            swap(directions[i], directions[randomIndex]);
        }

        bool moved = false;

        for (int i = 0; i < 4; ++i) {
            int newX = x, newY = y;
            if (directions[i] == 0) { // ��
                newX--;
            }
            else if (directions[i] == 1) { // ��
                newX++;
            }
            else if (directions[i] == 2) { // ��
                newY--;
            }
            else { // ��
                newY++;
            }

            if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
                bool alreadyVisited = false;
                for (const auto& pos : path) {
                    if (pos.first == newX && pos.second == newY) {
                        alreadyVisited = true;
                        break;
                    }
                }
                if (!alreadyVisited && (consecutiveMoves < MAX_CONSECUTIVE_MOVES || newX == SIZE - 1 || newY == SIZE - 1)) {
                    x = newX;
                    y = newY;
                    maze[x][y] = ++value;
                    path.push_back(make_pair(x, y));
                    moved = true;
                    if (directions[i] != 0) {
                        consecutiveMoves = 0;
                    }
                    else {
                        consecutiveMoves++;
                    }
                    break;
                }
            }
        }

        if (!moved) {
            // ��Ż �� �ٸ� ������ �����ϵ��� ���� �߰�
            bool escape = false;
            for (int i = 0; i < SIZE && !escape; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    if (maze[i][j] == 0) {
                        x = i;
                        y = j;
                        maze[x][y] = ++value;
                        path.push_back(make_pair(x, y));
                        escape = true;
                        break;
                    }
                }
            }
            if (!escape) {
                break;
            }
        }
    }
}

void printMaze(int maze[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout <<setw(5)<<maze[i][j];
        }
        cout << endl;
    }
}

int main() {
    int maze[SIZE][SIZE] = { 0 };

    generateRandomPath(maze);
    printMaze(maze);

    return 0;
}