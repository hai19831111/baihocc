#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <limits.h>
#define WIDTH   18
#define HEIGHT  10

char board[HEIGHT][WIDTH];
int x, y; 
int dx, dy;
int ax, ay;
int SCORES = 0;
int countP = 0, countS = 0;

void initialize(int, int);
void display();
bool is_blocked();
bool bait_eat();
void turn();
void move();
void bait();
void srand();
void lenght();
void bait1();

  // khoi tao game 
void initialize(int start_x, int start_y) {
    for (int i = 0; i < WIDTH; i++) {
        board[0][i] = board[HEIGHT - 1][i] = '#';
    }

    for (int i = 1; i < HEIGHT-1; i++) {
        for (int j = 1; j < WIDTH-1; j++) {
            board[i][j] = ' ';
        }
    }

	 for (int i = 0; i < HEIGHT; i++) {
        board[i][0] = board[i][WIDTH - 1] = '#';
    }

    x = start_x;
    y = start_y;
    dx = dy = 1;
    board[x][y] = '@';
}

void bait(){
	srand((NULL));
	int ax = rand() % 18;
	int ay = rand() % 8;
    if (board[ax][ay] == ' ') {
        board[ax][ay]= '+';
    } else {
        bait();
    }
    printf("%i %i", ax, ay);
}

void bait1(){
	srand((NULL));
	int ax = rand() % 18;
	int ay = rand() % 8;
	if (board[ax][ay] == ' ') {
        board[ax][ay]= '-';
    } else {
        bait1();
    }
    printf("%i %i", ax, ay);
}

bool bait_eat(){
	return (x== ax && y== ay);
}
	// hien thi bang game
void display() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}
	// ct di chuyen trong ham
	bool is_blocked() {
    return board[x + dx][y + dy] != ' ';
}

//void lenght(){
//	int arr[1][6];
//	for (int i=0;i<6;i++){
//		print("lenght%d\n", arr[i]);
//	}
//}

void turn() {
    if (board[x + dx][y] != ' ')
        dx = -dx;
    else
        dy = -dy;
}

void move() {
    board[x][y] = ' ';
    x += dx;
    y += dy;
    if (board[x][y] == '+') {
        SCORES++;
        countP--;
    } else if (board[x][y] == '-') {
        SCORES--;
        countS--;
    }
    board[x][y] = '@';
}


int main(void)
{
    initialize(1, 1);
    while (1) {
        while (is_blocked()) {
            turn();
        }
        if (countP <= 5) {
            bait();
            countP++;
        }
        if (countS <= 5) {
            bait1();
            countS++;
        }
        printf("%i", countP);
        printf("%i", countS);
        move();
        display();
        Sleep(500);
        system("cls");
    }
    return 0;
}

