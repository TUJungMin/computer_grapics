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
	cout << "x��ǥ : " << max_x << "  y��ǥ : " << max_y << "  z��ǥ : " << max_z << endl;
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
	cout << "x��ǥ : " << min_x << "  y��ǥ : " << min_y << "  z��ǥ : " << min_z << endl;
}

void PrintAll(const store_list* List)
{
	int empty_num = 0;
	for (int i = 9; i >= 0; --i)
	{
		if (List[i].full) {
			cout << i << "��° ����Ʈ :" << List[i].num1 << " " << List[i].num2 << " " << List[i].num3 << endl;
		}
		else
		{
			++empty_num;
			if (empty_num == 10) {
				cout << "����Ʈ�� ����ִ°� �����ϴ�!!" << endl;
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
			num++; //�������� ����
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
		cout << "��ɾ �Է��ϼ��� : ";
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
				//����Ʈ�� �� ���� �Է�

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
				//����Ʈ�� �� �Ʒ��� �Է�
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
				//����Ʈ�� �� ������ �����Ѵ�.
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
				// ����Ʈ�� �� �Ʒ����� �����Ѵ�. (����Ʈ���� ������ ĭ�� ����ִ�.)
				PrintAll(list);
				break;
			case 'l':
				cout << "����Ʈ�� ���� : " << SIZE;
				PrintAll(list);
				// ����Ʈ�� ����� ���� ������ ����Ѵ�.
				break;
			case 'c':
				for (int i = 0; i < 10;++i) {
					list[i].full = false;
				}
				SIZE = 0;
				PrintAll(list);
				// ����Ʈ�� ����. ����Ʈ�� ��� �� �ٽ� �Է��ϸ� 0������ ����ȴ�.
				break;
			case 'm':
				getdistance(list);
				FindFarDistance(list);
				//�������� ���� �� �Ÿ��� �ִ� ���� ��ǥ���� ����Ѵ�.

				break;
			case 'n':
				getdistance(list);
				FindNearDistance(list);
				// �������� ���� ����� �Ÿ��� �ִ� ���� ��ǥ���� ����Ѵ�
				break;
			case 's':
				getdistance(list);
				toggle_S =! toggle_S;
				if (toggle_S) {
					sortbydistance(list);
				}
				else
					PrintAll(list);
				//�������� �Ÿ��� �����Ͽ� �������� (�Ǵ� ��������)���� �����Ͽ� ����Ѵ�. �ε��� 0������ �� ĭ���� �����Ͽ� ����Ѵ�. �ٽ� s�� ������ ������
				//�ε��� ��ġ�� ����Ѵ�.
				break;
			case'q':
				cout << "���α׷��� �����մϴ�!!" << endl;
				return 0;

			default:
				cout << "��ɾ �߸� �Է��߽��ϴ� �ٽ� �Է��ϼ���!!" << endl;
				continue;
			}
			
	}

	return 0;
}