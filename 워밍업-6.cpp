#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

typedef struct {
    int x;
    int y;
} Point;

Point generate_random_direction() {
    int direction = rand() % 4;
    Point point;
    switch (direction) {
    case 0:
        point.x = 1;
        point.y = 0;
        break;
    case 1:
        point.x = -1;
        point.y = 0;
        break;
    case 2:
        point.x = 0;
        point.y = 1;
        break;
    case 3:
        point.x = 0;
        point.y = -1;
        break;
    }
    return point;
}

int main() {
    srand(time(NULL));

    int grid[SIZE][SIZE] = { 0 };
    Point current = { 0, 0 };
    int value = 1;

    while (current.x != SIZE - 1 || current.y != SIZE - 1) {
        grid[current.x][current.y] = value;

        int move_count = 0;
        Point direction;

        do {
            direction = generate_random_direction();
            int next_x = current.x + direction.x;
            int next_y = current.y + direction.y;

            if (next_x >= 0 && next_x < SIZE && next_y >= 0 && next_y < SIZE && grid[next_x][next_y] == 0) {
                current.x = next_x;
                current.y = next_y;
                move_count++;
            }
        } while (move_count < 5);

        value++;
    }

    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            printf("%3d ", grid[x][y]);
        }
        printf("\n");
    }

    return 0;
}