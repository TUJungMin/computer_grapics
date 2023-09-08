#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

typedef struct map 
{
	char concealShape = '*';
	char shape;
	char realshape = 'd';
	bool appear;
	int color;
	
}map;


void initializeBoard(map board[][4])
{
	srand((unsigned)time(NULL));
	int colorNum[16] = { 0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7 };
	for (int i = 15; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(colorNum[i], colorNum[j]);
	}
	char AlphaNum[16] = { 'A','A','B','B','C','C','D','D','E','E','F','F','G','G','H','H'};
	for (int i = 15; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(AlphaNum[i], AlphaNum[j]);
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			board[i][j].appear = false;
			board[i][j].shape = AlphaNum[4 * i + j];
			board[i][j].color = colorNum[4 * i + j];
		}
	}
	
}
void PrintALL(const map board[][4])
{
	cout << "\t" << "a\t" << "b\t" << "c\t" << "d" << endl;
	cout << "1\t" << board[0][0].realshape << "\t" << board[0][1].realshape << "\t" << board[0][2].realshape << "\t" << board[0][3].realshape << endl;
	cout << "2\t" << board[1][0].realshape << "\t" << board[1][1].realshape << "\t" << board[1][2].realshape << "\t" << board[1][3].realshape << endl;
	cout << "3\t" << board[2][0].realshape << "\t" << board[2][1].realshape << "\t" << board[2][2].realshape << "\t" << board[2][3].realshape << endl;
	cout << "4\t" << board[3][0].realshape << "\t" << board[3][1].realshape << "\t" << board[3][2].realshape << "\t" << board[3][3].realshape << endl;

}

void gamestart(const char raw1, const char raw2, const int col1, const int col2, map board[][4])
{
	int rawnum1, rawnum2;
	switch (raw1) {

	case 'a':
		rawnum1 = 0;
		break;
	}

}


int main()
{
	map board[4][4];
	initializeBoard(board);
	char raw1, raw2;
	int col1, col2;
	while (1) {
		PrintALL(board);
		cout << "input card1: ";
		cin >> raw1 >> col1;
		if (((raw1 < 'a' || raw1>'d') || (col1 < 1 || col1 >> 4))) {
			cout << "잘못입력했습니다 다시입력하세요!!!" << endl;
			continue;
		}
		
		cout << "input card2: ";
		cin >> raw2 >> col2;
		if (((raw2 < 'a' || raw2>'d') || (col2 < 1 || col2 >> 4))) {
			cout << "잘못입력했습니다 다시입력하세요!!!" << endl;
			continue;
		}

		PrintALL(board);
	}
	
}