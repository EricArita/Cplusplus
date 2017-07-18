#include "Util.h"
#include<bits/stdc++.h>
using namespace std;

struct Pos2D {
   int x,y,ox,oy;
};

int boardW, boardH, snakeLength,Score=0,Speed,Level; 
Pos2D direction, snake[100],food; 
bool endGame,eatFood;
//..............................................
void init() {
    // kh?i t?o m?t s? giá tr? ban d?u
    endGame = false; 
    boardW = 65; boardH = 50;
    Speed=100;
    Level=1;
    // kh?i t?o con r?n g?m có 5 ô
    snake[0].x = 5; snake[0].y = 5;
    snake[1].x = 4; snake[1].y = 5;
    snake[2].x = 3; snake[2].y = 5;
    snake[3].x = 2; snake[3].y = 5;
    snakeLength = 4;
    // hu?ng di chuy?n ban d?u là di xu?ng
    direction.x = 1; direction.y = 0;
    // d?t màu n?n cho màn hình
    SetBGColor(8);
    for (int i = 0; i < boardW; i++) {
        for (int j = 0; j < boardH; j++) {
            gotoxy(i, j);
            printf(" ");
        }
    }
    
    SetColor(10);
    gotoxy(1,0); 
    cout<<"SCORE: 0";
    
    gotoxy(boardW-10,0);
    cout<<"LEVEL: 1";
    
    gotoxy(0,3);
    for(int i=1;i<=boardW;i++) cout<<"=";
}
//................................................
void moveSnake(Pos2D dir) {
    for (int i = 0; i < snakeLength; i++) {
        if (i == 0) {
            // di chuy?n d? r?n
            snake[0].ox = snake[0].x; snake[0].oy = snake[0].y;
            snake[0].x += dir.x; snake[0].y += dir.y;
        }else{
            // di chuy?n ph?n thân r?n
            snake[i].ox = snake[i].x; snake[i].oy = snake[i].y;
            snake[i].x = snake[i - 1].ox; snake[i].y = snake[i - 1].oy;
        }
         
        // khi r?n vu?t ra kh?i màn hình thì cho nó xu?t hi?n l?i
        if (snake[i].x >= boardW) snake[i].x = 0;
        if (snake[i].x < 0) snake[i].x = boardW - 1;
        if (snake[i].y >= boardH) snake[i].y = 4;
        if (snake[i].y <= 3){
        	snake[i].y = boardH - 1;
    	}
         
        // ki?m tra coi con r?n có c?n trúng nó không
        if (i != 0 && (snake[0].x == snake[i].x && snake[0].y == snake[i].y)) 
					  	endGame = true;
    }
}
//...............................................
void drawSnake() {
	SetColor(14);
    for (int i = 0; i < snakeLength; i++) {
        gotoxy(snake[i].x, snake[i].y);
        printf("%c", 1); // dùng kí t? hình kim cuong d? v? con r?n
    }
    gotoxy(snake[snakeLength-1].ox, snake[snakeLength-1].oy);
    printf(" "); // xóa ph?n duôi tru?c dó c?a nó
}
//...............................................
void drawFood(){
		SetColor(12);
		srand(time(NULL));
		food.x=rand() % (boardW-2);
		food.y=rand() % (boardH-4)+4;
		gotoxy(food.x,food.y);
		cout<<"O";
		eatFood=false;
}
//...............................................
void check_eatFood(){
		if (snake[0].x==food.x && snake[0].y==food.y){
				gotoxy(food.x,food.y);
				cout<<" ";
				gotoxy(snake[snakeLength-1].ox,snake[snakeLength-1].oy);
				printf("%c",1);
				snake[snakeLength].x=snake[snakeLength-1].ox;
				snake[snakeLength].y=snake[snakeLength-1].oy;
				snakeLength++;
				Score++;
				SetColor(10);
				gotoxy(1,0);
				cout<<"SCORE: "<<Score;
				if (Score>0 && Score % 5==0){
					  Level++;
					  if (Speed>10) Speed-=10;
					  else if (Speed>1) Speed-=1;
				}
				gotoxy(boardW-10,0);
    			cout<<"LEVEL: "<<Level;
				eatFood=true;
		}
}
//...............................................
void mainloop() {
    moveSnake(direction);
    
    check_eatFood();
    if (eatFood) drawFood();
 
    if (checkKey(KEY_LEFT)) {
        if (direction.x != 1) {
            direction.x = -1; direction.y = 0;
        }
    }
    else if (checkKey(KEY_RIGHT)) {
        if (direction.x != -1) {
            direction.x = 1; direction.y = 0;
        }
    }
    else if (checkKey(KEY_UP)) {
        if (direction.y != 1) {
            direction.y = -1; direction.x = 0;
        }
    }
    else if (checkKey(KEY_DOWN)) {
        if (direction.y != -1) {
            direction.y = 1; direction.x = 0;
        }
    }
 
    if (checkKey(KEY_ESC)) {
        endGame = true;
    }
}
//...............................................
void drawGame(){
		drawSnake();
}
//...............................................
int main() {    
        
    init();
    ShowCur(false); // ?n con tr?
    drawFood();
    while (!endGame){
      		Tick(Speed, mainloop, drawGame); // Mainloop
    }
    			
    gotoxy(25,20);
	cout<<"GAME OVER";
	clrscr();
    
    return 0;
}
