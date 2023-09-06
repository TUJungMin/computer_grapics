#include <iostream>
#include <random>
#include <math.h>



using namespace std;


struct coordinate {
	int x;
	int y;
};


// FLOAT distance = (d - b) * x + (a - c) * y + (b * c - a * d) / sqrt(pow((d - b), 2) + pow((a - c), 2));

bool CheckCollision(coordinate& line1, coordinate& line2, coordinate& rect1, coordinate& rect2)
{
	bool result;
	float distance1 = (line2.y - line1.y) * rect1.x + (line1.x - line2.x) * rect1.y + (line1.y * line2.x - line1.x * line2.y) / sqrt(pow((line2.y - line1.y), 2) + pow((line1.x - line2.x), 2));
	float distance2 = (line2.y - line1.y) * rect1.x + (line1.x - line2.x) * rect2.y + (line1.y * line2.x - line1.x * line2.y) / sqrt(pow((line2.y - line1.y), 2) + pow((line1.x - line2.x), 2));
	float distance3 = (line2.y - line1.y) * rect2.x + (line1.x - line2.x) * rect1.y + (line1.y * line2.x - line1.x * line2.y) / sqrt(pow((line2.y - line1.y), 2) + pow((line1.x - line2.x), 2));
	float distance4 = (line2.y - line1.y) * rect2.x + (line1.x - line2.x) * rect2.y + (line1.y * line2.x - line1.x * line2.y) / sqrt(pow((line2.y - line1.y), 2) + pow((line1.x - line2.x), 2));

	if (distance1 <= 0 && distance2 <= 0 && distance3 <= 0 && distance4 <= 0) {
		result = false;
	}
	else
		if (distance1 >= 0 && distance2 >= 0 && distance3 >= 0 && distance4 >= 0) {
			result = false;
		}
		else if
			(((line1.x < rect1.x) && (line2.x < rect1.x)) || ((line1.x > rect2.x) && (line2.x > rect2.x)) ||
				((line1.y < rect1.y) && (line2.y < rect1.y)) || ((line1.y > rect2.y) && (line2.y > rect2.y))) {
			result = false;
		}

		else result = true;

	return result;		// false면 충돌 x true면 충돌
}
void initail(coordinate& a, coordinate& b, coordinate c, coordinate d) {
	a = c;
	b = d;
}
void swap(coordinate& a, coordinate& b) 
{
	coordinate temp;
	if (a.x > b.x){
		temp.x = a.x;
		a.x = b.x;
		b.x = temp.x;
		}
	if (a.y > b.y) {
		temp.y = a.y;
		a.y = b.y;
		b.y = temp.y;
	}
}
void initialize_coord(int& x, int& y) {
	x = rand() % 201 + 600;
	y = rand() % 201 + 600;
}

void Print_coord(const  coordinate& x1, const  coordinate& x2, const  coordinate& y1, const  coordinate& y2) {
	cout << "RECT: " << "(" << x1.x << "," << x1.y << ") " << "(" << x2.x << "," << x2.y << ") " << endl;
	cout << "line: " << "(" << y1.x << "," << y1.y << ") " << "(" << y2.x << "," << y2.y << ") " << endl;
}

int main() {
	char order;
	srand(unsigned(time(NULL)));

	coordinate rect1;
	coordinate rect2;
	coordinate line1;
	coordinate line2;

	initialize_coord(rect1.x, rect1.y);
	initialize_coord(rect2.x, rect2.y);
	initialize_coord(line1.x, line1.y);
	initialize_coord(line2.x, line2.y);
	while (CheckCollision(line1, line2, rect1, rect2)) {
		initialize_coord(rect1.x, rect1.y);
		initialize_coord(rect2.x, rect2.y);
		initialize_coord(line1.x, line1.y);
		initialize_coord(line2.x, line2.y);
	}
	swap(rect1, rect2);


	
	//initail(line1, line2, { 600,600 }, { 650,650 });
	//initail(rect1, rect2, { 700,700 }, { 780,780 });
	cout << "Input Shape Coordinates value :" << endl;
	Print_coord(rect1, rect2, line1, line2);

	while (true) {
		cout << "Command  : ";
		cin >> order;

		switch (order) 
		{
		case 'w':
			rect1.y -= 60;
			rect2.y -= 60;
			break;
		case 'a':
			rect1.x -= 50;
			rect2.x -= 50;
			break;
		case 's':
			rect1.y += 60;
			rect2.y += 60;
			break;
		case 'd':
			rect1.x += 50;
			rect2.x += 50;
			break;

		case 'i':
			line1.y -= 60;
			line2.y -= 60;
			break;
		case 'j':
			line1.x -= 50;
			line2.x -= 50;
			break;
		case 'k':
			line1.y += 60;
			line2.y += 60;
			break;
		case 'l':
			line1.x += 50;
			line2.x += 50;
			break;
		}
		Print_coord(rect1, rect2, line1, line2);
		if (CheckCollision(line1, line2, rect1, rect2)) {
			cout << "Rectangle & Line collide!!" << endl;
			break;
		}
	}
	return 0;
}



