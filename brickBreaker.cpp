#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
class GameElement {
protected:
    int x, y;
public:
    GameElement(int startX = 0, int startY = 0) : x(startX), y(startY) {}

    void setPosition(int newX, int newY) {
 x = newX;
 y = newY;
}

int getX() { return x; }
int getY() { return y; }

virtual void draw() = 0;
};

class Paddle : public GameElement {
private:
int width, height;
public:
Paddle(int startX, int startY, int w, int h) : GameElement(startX, startY), width(w), height(h) {}
void draw() {
setfillstyle(SOLID_FILL, BLUE);
bar(x, y, x + width, y + height);
}

void move(char direction) {
if (direction == 'a' && x > 0) {
x -= 20;
} 

else if (direction == 'd' && x + width < getmaxx()) {
x += 20;
}
}
};

class Ball : public GameElement {
private:
int dirX, dirY;
public:
Ball(int startX, int startY, int dx, int dy) : GameElement(startX, startY), dirX(dx), dirY(dy) {}

void draw() {
setfillstyle(SOLID_FILL, YELLOW);
fillellipse(x, y, 10, 10);
}

void move() {
x += dirX;
y += dirY;
}

    void bounceOffWalls() {
 if (x - 10 <= 0 || x + 10 >= getmaxx()) {
     dirX = -dirX;
 }
 if (y - 10 <= 0) {
     dirY = -dirY;
 }
    }

    void bounceOffPaddleOrBrick() {
 dirY = -dirY;
    }

    int getDirX() { return dirX; }
    int getDirY() { return dirY; }
};

class Brick : public GameElement {
private:
    int width, height;
    int isVisible;
public:
    Brick(int startX, int startY, int w, int h) : GameElement(startX, startY), width(w), height(h), isVisible(1) {}

    void draw() {
 if (isVisible) {
     setfillstyle(SOLID_FILL, RED);
     bar(x, y, x + width, y + height);
 }
    }

    int checkCollision(int ballX, int ballY) {
 if (isVisible && ballX + 10 > x && ballX - 10 < x + width && ballY + 10 > y && ballY - 10 < y + height) {
     isVisible = 0;
     return 1;
 }
 return 0;
    }
};

class Game {
private:
    Paddle paddle;
    Ball ball;
    Brick* bricks[5][10];
    int score;

public:
int i,j;
    Game() : paddle(getmaxx() / 2 - 50, getmaxy() - 20, 100, 10), ball(getmaxx() / 2, getmaxy() / 2, 2, 2), score(0) {
 for ( i = 0; i < 5; i++) {
     for ( j = 0; j < 10; j++) {
  bricks[i][j] = new Brick(j * 50, i * 20, 50, 20);
     }


 }
    }

    void run() {
 char scoreText[20];
 int gameOver = 0;
 while (!gameOver) {
     cleardevice();
     paddle.draw();
     ball.draw();
     for (int i = 0; i < 5; i++) {
  for (int j = 0; j < 10; j++) {
      bricks[i][j]->draw();
  }
     }

     ball.move();
     ball.bounceOffWalls();
     if (ball.getY() + 10 >= getmaxy() - 20 && ball.getX() >= paddle.getX() && ball.getX() <= paddle.getX() + 100) {
  ball.bounceOffPaddleOrBrick();
     }
     for ( i = 0; i < 5; i++) {
  for (j = 0; j < 10; j++) {
      if (bricks[i][j]->checkCollision(ball.getX(), ball.getY())) {
   ball.bounceOffPaddleOrBrick();
   score += 10;
      }
  }
     }
     if (ball.getY() + 10 > getmaxy()) {
  setcolor(RED);
  outtextxy(getmaxx() / 2 - 50, getmaxy() / 2, "Game Over");
            setcolor(CYAN);
  
sprintf(scoreText, "Final Score: %d", score);
  outtextxy(getmaxx() / 2 - 50, getmaxy() / 2 + 20, scoreText);
  getch();
  closegraph();
  exit(0);
     }
    
 if (kbhit()) {
  char ch = getch();
  if (ch == 'a' || ch == 'd') {
      paddle.move(ch);
  }
     }
     delay(10);
 }
    }
};
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    Game brickBreakerGame;
    brickBreakerGame.run();
    closegraph();
    return 0;
}