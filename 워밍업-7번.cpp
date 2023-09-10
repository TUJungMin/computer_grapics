#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <vector>
using namespace std;


#define SIZE 50

struct Coord {
    int x;
    int y;
};
void makeline(char maze[][SIZE], vector <Coord>& turncoord, int &turn) {
    turn = 0;
    int direction = 0;
    int x = 0, y = 0;
    int cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    int s = 0;
    Coord coord;
    int upCnt = 0, leftCnt = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            maze[i][j] = '1';
        }
    }
    maze[0][0] = '0';
    turncoord.push_back({0,0});
    while (x != SIZE-1 || y != SIZE - 1) {
        direction = rand() % 4;
        switch (direction) {
        case 0:
            x++;
            cnt++;
            if (cnt >= 5) {
                x--;
            }
            cnt1 = 0, cnt2 = 0, cnt3 = 0;
            break;
        case 1:
            if (leftCnt < 12)
            {
                x--;
                cnt1++;
                leftCnt++;
                if (cnt1 >= 5) {
                    x++;
                }
            cnt = 0, cnt2 = 0, cnt3 = 0;
            break;
            }
            else
                continue;
        case 2:
            y++;
            cnt2++;
            if (cnt2 >= 5) {
                y--;
            }
            cnt1 = 0, cnt = 0, cnt3 = 0;
            break;
        case 3:
            if (upCnt < 12)
            {
                y--;
                cnt3++;
                upCnt++;
                if (cnt3 >= 5) {
                    y++;
                }
                cnt1 = 0, cnt2 = 0, cnt = 0;
                break;
            }
            else
            {
                continue;
            }
        }
        if (x > SIZE - 1) {
            x--;
            continue;
        }
        if (x < 0) {
            x++;
            continue;
        }
        if (y > SIZE - 1) {
            y--;
            continue;
        }
        if (y < 0) {
            y++;
            continue;
        }
        maze[y][x] = '0';
        coord.x = x; coord.y = y;
        turncoord.push_back(coord);
    }
}
void printMaze(char maze[][SIZE], vector <Coord>& turncoord,const bool& start, const int& turn) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
          
            if (start) {
                maze[turncoord[turn].y][turncoord[turn].x] = '*';
            }
            else
            {
                maze[turncoord[turn].y][turncoord[turn].x] = '0';
            }
            if (maze[i][j] == '1')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            }
            else if (maze[i][j] == '0')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            }
            else if (maze[i][j] == '*')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            }
            cout << maze[i][j] << " ";
           
        }
        cout << endl;
    }
    maze[turncoord[turn].y][turncoord[turn].x] = '0';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int main() {
    bool objectStart = false;
    char maze[SIZE][SIZE];
    vector <Coord> turncoord;
    int turn = 0;
    char order;
    makeline(maze, turncoord,turn);
    while (1)
    {
        cout << "명령어를 입력하세요: ";
        cin >> order;

        switch (order)
        {
        case'q':
            cout << "프로그램을 종료합니다!!" << endl;
            return 0;

        case 'r':
            objectStart = !objectStart;
            
            break;
        case '+':
            if (turn < turncoord.size())
            {
                turn++;
            }
            else
            {

            }
            break;

        case '-':

            if (turn > 0)
            {
                turn--;
            }
            else
            {   }
            break;

        case 's':
            makeline(maze, turncoord, turn);
        
            break;
        }
        system("cls");
    printMaze(maze,turncoord, objectStart,turn);
    }
   
    

    return 0;
}