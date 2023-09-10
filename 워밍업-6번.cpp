#include <iostream>

using namespace std;
#define SIZE 30
struct Point {
	int x;
	int y;
};

struct Rect {
	Point LT;
	Point RB;
};




void initializeBoard(char board[][30], Rect& rect)
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; ++j) {
			board[i][j] = '.';
		}
	}

	while (1) {
		cout << "input coord value: ";
		cin >> rect.LT.x >> rect.LT.y >> rect.RB.x >> rect.RB.y;
		if ((rect.LT.x > 29 || rect.LT.x < 0) || (rect.LT.y > 29 || rect.LT.y < 0)
			|| (rect.RB.x > 29 || rect.RB.x < 0) || (rect.RB.y > 29 || rect.RB.y < 0))
		{
			cout << "범위에 맞는 좌표를 적어주세요!!!" << endl;
			continue;
		}
		if (rect.LT.x >= rect.RB.x) {
			swap(rect.LT.x, rect.RB.x);
		}
		if (rect.LT.y >= rect.RB.y) {
			swap(rect.LT.y, rect.RB.y);
		}
		break;
	}
	for (int i = rect.LT.y; i <= rect.RB.y; ++i) {
		for (int j = rect.LT.x; j <= rect.RB.x; ++j) {
			board[i][j] = '0';
		}
	}

}
void PrintAll(char board[][30])
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; ++j) {
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}

}
void checkrect(Rect& rect)
{
	if (rect.LT.x < 0 && rect.RB.x < 0)
	{
		rect.LT.x += 30;
		rect.RB.x += 30;
	}
	if (rect.LT.y < 0 && rect.RB.y < 0)
	{
		rect.LT.y += 30;
		rect.RB.y += 30;
	}
	if (rect.LT.x > SIZE && rect.RB.x > SIZE)
	{
		rect.LT.x -= 30;
		rect.RB.x -= 30;
	}
	if (rect.LT.y > SIZE && rect.RB.y > SIZE)
	{
		rect.LT.y -= 30;
		rect.RB.y -= 30;
	}
}
void moveboard(char board[][30], Rect& rect)
{
	int num_y;
	int num_x;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; ++j) {
			board[i][j] = '.';
		}

	}

	checkrect(rect);


	for (int i = rect.LT.y; i <= rect.RB.y; ++i) {	//3	4
		for (int j = rect.LT.x; j <= rect.RB.x; ++j) {	//1	3
			if (j % SIZE < 0)
			{
				num_x = SIZE + (j % SIZE);
			}
			else {
				num_x = j % SIZE;
			}
			if (i % SIZE < 0)
			{
				num_y = SIZE + (i % SIZE);
			}
			else {
				num_y = i % SIZE;
			}
			board[num_y][num_x] = '0';
		}
	}
}
void gamestart(char board[][30], Rect& rect)
{
	char order;

	cout << "input order: ";
	cin >> order;
	switch (order)
	{
	case 'x':
		rect.LT.x++;
		rect.RB.x++;
		break;
	case 'X':
		rect.LT.x--;
		rect.RB.x--;
		break;
	case 'y':
		rect.LT.y++;
		rect.RB.y++;
		break;
	case 'Y':
		rect.LT.y--;
		rect.RB.y--;
		break;
	case 'S':
		if (rect.LT.x <= rect.RB.x) {
			if (rect.RB.x >= SIZE) {
				rect.LT.x--;
			}
			else
				rect.RB.x++;
		}
		if(rect.LT.y <= rect.RB.y)
		if (rect.RB.y >= SIZE ) {
			rect.LT.y--;
		}
		else
			rect.RB.y++;

		break;

	case 's':
		if (rect.LT.x <= rect.RB.x-1) {
			if (rect.LT.x < 0) {
				rect.RB.x--;
			}
			else if (rect.RB.x > SIZE)
				rect.LT.x++;
			else
				rect.RB.x--;
		}
		if (rect.LT.y <= rect.RB.y-1) {
			if (rect.LT.y < 0 && rect.LT.y < rect.RB.y) {
				rect.RB.y--;
			}
			else if (rect.RB.y > SIZE && rect.LT.y < rect.RB.y)
				rect.LT.y++;
			else
				rect.RB.y--;
		}
		//s/S: x와 y 모두 한 칸 축소/확대 (범위를 넘어가는 축은 변경 안됨)
		break;

	case 'i':
		if (rect.LT.x <= rect.RB.x) {
			if (rect.RB.x >= SIZE) {
				rect.LT.x--;
			}
			else
				rect.RB.x++;
		}
		break;
	case 'j':
		if (rect.LT.x <= rect.RB.x - 1) {
			if (rect.LT.x < 0) {
				rect.RB.x--;
			}
			else if (rect.RB.x > SIZE)
				rect.LT.x++;
			else
				rect.RB.x--;
		}
		break;
	case 'k':
		if (rect.LT.y <= rect.RB.y)
			if (rect.RB.y >= SIZE) {
				rect.LT.y--;
			}
			else
				rect.RB.y++;

		break;
	case 'l':
		if (rect.LT.y <= rect.RB.y - 1) {
			if (rect.LT.y < 0 && rect.LT.y < rect.RB.y) {
				rect.RB.y--;
			}
			else if (rect.RB.y > SIZE && rect.LT.y < rect.RB.y)
				rect.LT.y++;
			else
				rect.RB.y--;
		}
		break;
	case 'R':
		initializeBoard(board, rect);
		//• i / j: x축 한 칸 확대 / 축소
		//	• k / l : y축 한 칸 확대 / 축소
		//• R : 모든 것을 리셋하고 다시 좌표값을 입력받는다.
	default:
		break;
	}
	moveboard(board, rect);



}
int main()
{
	Rect rect;
	char board[30][30];
	initializeBoard(board, rect);

	while (1) {
		PrintAll(board);
		gamestart(board, rect);
		system("cls");
	}

	return 0;

}