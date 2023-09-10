#include <iostream>
#include <list>
#include <vector>
#include <math.h>
using namespace std;



struct store_list {
	bool full = false;
	int num1, num2, num3;
	float distance;

	
};
void FindFarDistance(store_list* list) 
{
	int max_distace = 0;
	int max_x=0, max_y=0, max_z = 0;

	for (int i = 0; i < 9; ++i) {
		if (list[i].full == true) {
			
			if (max_distace <= list[i].distance) {
				max_distace = list[i].distance;
				max_x = list[i].num1;
				max_y = list[i].num2;
				max_z = list[i].num3;
			}
		}
	}
	cout << "x좌표 : " << max_x << "  y좌표 : " << max_y << "  z좌표 : " << max_z << endl;
}
void getdistance(store_list* list) {
	for (int i = 0; i < 10; ++i) {
		if (list[i].full == true) {
			list[i].distance = sqrt(pow(list[i].num1, 2) + pow(list[i].num2, 2) + pow(list[i].num3, 2));
		}
	}
}
void FindNearDistance(store_list* list)
{
	int min_distace =INT_MAX;
	int min_x = 0, min_y = 0, min_z = 0;

	for (int i = 0; i < 9; ++i) {
		if (list[i].full == true) {
			
			if (min_distace >= list[i].distance) {
				min_distace = list[i].distance;
				min_x = list[i].num1;
				min_y = list[i].num2;
				min_z = list[i].num3;
			}
		}
	}
	cout << "x좌표 : " << min_x << "  y좌표 : " << min_y << "  z좌표 : " << min_z << endl;
}

void PrintAll(const store_list* List)
{
	int empty_num = 0;
	for (int i = 9; i >= 0; --i)
	{
		if (List[i].full) {
			cout << i << "번째 리스트 :" << List[i].num1 << " " << List[i].num2 << " " << List[i].num3 << endl;
		}
		else
		{
			++empty_num;
			if (empty_num == 10) {
				cout << "리스트에 들어있는게 없습니다!!" << endl;
			}
		}
	}
}

void sortbydistance(const store_list* list) 
{
	store_list copylist[10];
	int num = 0;
	for (int i = 0; i < 10; ++i) {
		if (list[i].full == true) {
			copylist[num] = list[i];
			num++; //데이터의 개수
		}
	}
	store_list temp;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - i; j++)
		{
			if (copylist[j].distance > copylist[j + 1].distance)
			{
				temp = copylist[j];
				copylist[j]= copylist[j + 1];
				copylist[j + 1] = temp;
			}
		}
	}
	PrintAll(copylist);
}

int main()
{
	char order;
	store_list list[10];
	int SIZE = 0;
	bool toggle_S = false;
	while (true) {
		cout << "명령어를 입력하세요 : ";
		cin >> order;

			switch (order)
			{
			case '+':
			{
				int max_size = SIZE;
				if (SIZE != 0) {
					for (int i = 0; i < SIZE; ++i) {
						if (list[i].full == false) {
							SIZE = i;
							break;
						}
					}
				}
				cin >> list[SIZE].num1 >> list[SIZE].num2 >> list[SIZE].num3;
				list[SIZE].full = true;
				SIZE = max_size;
				SIZE++;
				//리스트의 맨 위에 입력

			}
			PrintAll(list);
				break;
			case 'e':
				if (SIZE != 0) {
					for (int a = SIZE-1; a >= 0; a--) {
						if (a != 9) {
							list[a + 1] = list[a];
						}
					}
				}
				cin >> list[0].num1 >> list[0].num2 >> list[0].num3;
				list[SIZE].full = true;
				SIZE++;
				//리스트의 맨 아래에 입력
				PrintAll(list);
				break;
			case '-':
				for (int i = 9; i >= 0; --i) {
					if (list[i].full == true) {
						list[i].full = false;
						break;
					}
				}
				
				if (SIZE > 0) {
					SIZE--;
				}
				//리스트의 맨 위에서 삭제한다.
				PrintAll(list);
				break;

			case 'd':
				for (int i = 0; i <= 9; ++i) {
					if (list[i].full == true) {
						list[i].full = false;
						break;
					}
				}
				if (SIZE > 0) {
					SIZE--;
				}
				// 리스트의 맨 아래에서 삭제한다. (리스트에서 삭제된 칸이 비어있다.)
				PrintAll(list);
				break;
			case 'l':
				cout << "리스트의 길이 : " << SIZE;
				PrintAll(list);
				// 리스트에 저장된 점의 개수를 출력한다.
				break;
			case 'c':
				for (int i = 0; i < 10;++i) {
					list[i].full = false;
				}
				SIZE = 0;
				PrintAll(list);
				// 리스트를 비운다. 리스트를 비운 후 다시 입력하면 0번부터 저장된다.
				break;
			case 'm':
				getdistance(list);
				FindFarDistance(list);
				//원점에서 가장 먼 거리에 있는 점의 좌표값을 출력한다.

				break;
			case 'n':
				getdistance(list);
				FindNearDistance(list);
				// 원점에서 가장 가까운 거리에 있는 점의 좌표값을 출력한다
				break;
			case 's':
				getdistance(list);
				toggle_S =! toggle_S;
				if (toggle_S) {
					sortbydistance(list);
				}
				else
					PrintAll(list);
				//원점과의 거리를 정렬하여 오름차순 (또는 내림차순)으로 정렬하여 출력한다. 인덱스 0번부터 빈 칸없이 저장하여 출력한다. 다시 s를 누르면 원래의
				//인덱스 위치에 출력한다.
				break;
			case'q':
				cout << "프로그램을 종료합니다!!" << endl;
				return 0;

			default:
				cout << "명령어를 잘못 입력했습니다 다시 입력하세요!!" << endl;
				continue;
			}
			
	}

	return 0;
}