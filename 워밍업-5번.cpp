#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <random>
#include <windows.h>
using namespace std;

struct map
{
	char concealShape = '*';
	char shape;
	char realshape = 'd';

	int color;

};

struct Card {
	int color;
	char alpha;
	//bool appear;
};

struct DATA {
	Card* data;
	bool appear;
};


void initializeBoard(array <DATA, 16>& board, Card* card)
{
	//srand((unsigned)time(NULL));
	std::random_device rd;
	std::default_random_engine dre(rd());
	vector <int> colorNum = { 1,2,3,4,5,6,7,8 };
	shuffle(colorNum.begin(), colorNum.end(), dre);
	char AlphaNum[8] = { 'A','B','C','D','E','F','G','H' };
	for (int i = 0; i < 8; i++) {
		//card[i].appear = false;
		card[i].alpha = AlphaNum[i];
		card[i].color = colorNum[i];
	}
	for (int i = 0; i < 8; i++) {
		board[2 * i].appear = false;
		board[2 * i + 1].appear = false;
		board[2*i].data = &card[i];
		board[2*i + 1].data = &card[i];
	}
	shuffle(board.begin(), board.end(), dre);
	for (int i = 7; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(AlphaNum[i], AlphaNum[j]);
	}


}
void PrintALL(const array <DATA, 16>& board,const int &score)
{
	cout << "SCORE: "<<score << endl;
	cout << "\t" << "a\t" << "b\t" << "c\t" << "d" << endl;
	for (int i = 0; i < 4; ++i) {
		cout << i + 1 << "\t";
		for (int j = 0; j < 4; ++j) {
			if (board[4 * i + j].appear == false) {
				cout << "*" << "\t";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), board[4 * i + j].data->color);
				cout << board[4 * i + j].data->alpha << "\t";
			}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		cout << endl;
	}


	

}

void gamestart(array <DATA, 16>& board,int &score)
{
	int turn = 0;
	int col1, col2;
	char order, raw1, raw2;
	cout << "input card1: ";
	cin >> raw1 >> col1;
	if (((raw1 < 'a' || raw1>'d') || (col1 < 1 || col1 >> 4))) {
		cout << "잘못입력했습니다 다시입력하세요!!!" << endl;
	}

	cout << "input card2: ";
	cin >> raw2 >> col2;
	if (((raw2 < 'a' || raw2>'d') || (col2 < 1 || col2 >> 4))) {
		cout << "잘못입력했습니다 다시입력하세요!!!" << endl;
	}
	int rawnum1, rawnum2;
	switch (raw1) {

	case 'a':
		rawnum1 = 0;
		break;
	case 'b':
		rawnum1 = 1;
		break;
	case 'c':
		rawnum1 = 2;
		break;
	case 'd':
		rawnum1 = 3;
		break;
	}

	switch (raw2) {

	case 'a':
		rawnum2 = 0;
		break;
	case 'b':
		rawnum2 = 1;
		break;
	case 'c':
		rawnum2 = 2;
		break;
	case 'd':
		rawnum2 = 3;
		break;
	}
	board[4 * (col1 - 1) + rawnum1].appear = true;
	board[4 * (col2 - 1) + rawnum2].appear = true;
	PrintALL(board,score);
	turn++;
	cout << "턴 수 :" << turn << endl;
	score--;
	cout << endl << endl;

	board[4 * (col1 - 1) + rawnum1].appear = false;
	board[4 * (col2 - 1) + rawnum2].appear = false;
	if (board[4 * (col1 - 1) + rawnum1].data->alpha == board[4 * (col2 - 1) + rawnum2].data->alpha) {
		board[4 * (col1 - 1) + rawnum1].appear = true;
		board[4 * (col2 - 1) + rawnum2].appear = true;
		score++;
		score += 20;
	}
}


int main()
{

	Card card[8];
	array <DATA, 16> board;		//배열이 아니라 클래스이다!!
	int score = 10;
	
	initializeBoard(board, card);
	char order;
	
		PrintALL(board,score);
	
	while (1) {
		cout << "명령어를 입력해주세요(r:재시작 s:시작 q:종료 ): ";
		cin >> order;
		switch (order)
		{
		case 'r':
			initializeBoard(board, card);
			break;
		case 'q':
			cout << "프로그램을 종료합니다!!" << endl;
			return 0;
		default:
			cout << "Invalid!!!!" << endl;
			continue;
		case 's':
			gamestart(board,score);
			break;
		}
		PrintALL(board,score);
	}

}