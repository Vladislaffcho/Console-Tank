#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "source.h"
#include <conio.h>
#include <process.h>

// Defines

#define hCon GetStdHandle(STD_OUTPUT_HANDLE)
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SHOT 32
#define EXIT 27

// Datatypes

typedef enum {
    SOUTH = 0,
    NORTH,
    EAST,
    WEST
}TankDirection;

typedef struct  {
    COORD position;
    TankDirection direction;
    bool isFirstTurn;
    bool isShot;
}Tank;

// Functions

void func_map(const int *mapa)
{
    int i;
    
    for (i = 0; i < 9074; i++)
    {
        switch(mapa[i]) {
        case 0:
            printf("%c",32);
            break;
        case 1:
            printf("%c", 178);
            break;
        case 2:
            printf("%c", 177);
            break;
        case 3:
            printf("%c", 187);
            break;
        case 4:
            printf("%c", 200);
            break;
        case 5:
            printf("%c", 188);
            break;
        case 6:
            printf("%c", 205);
            break;
        case 7:
            printf("%c", 186);
            break;
        }
    }
}

void drawTank(Tank *tank) {

    switch(tank->direction)
    {
        case SOUTH:
        {
            SetConsoleCursorPosition(hCon,tank->position);
            printf("  %c  \n",220);
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            printf("  %c  \n",186);
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c%c%c%c\n",178,178,202,178,178);
            }else{
                printf("%c%c%c%c%c\n",176,176,202,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c %c%c\n",178,178,178,178);
            }else{
                printf("%c%c %c%c\n",176,176,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c %c%c\n",178,178,178,178);
            }else{
                printf("%c%c %c%c\n",176,176,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c%c%c%c\n",178,178,205,178,178);
            }else{
                printf("%c%c%c%c%c\n",176,176,205,176,176);
            }
            tank->position.Y -= 5;
            break;
        }
        case NORTH:
        {
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c%c%c%c\n",178,178,205,178,178);
            }else{
                printf("%c%c%c%c%c\n",176,176,205,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c %c%c\n",178,178,178,178);
            }else{
                printf("%c%c %c%c\n",176,176,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c %c%c\n",178,178,178,178);
            }else{
                printf("%c%c %c%c\n",176,176,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c%c%c%c\n",178,178,203,178,178);
            }else{
                printf("%c%c%c%c%c\n",176,176,203,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            printf("  %c  \n",186);
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            printf("  %c  \n",223);
            tank->position.Y -= 5;
            break;
        }
        case WEST:
        {
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.X % 2 == 0)
            {
                printf("  %c%c%c%c%c%c\n",178,176,178,176,178,176);
            }else{
                printf("  %c%c%c%c%c%c\n",176,178,176,178,176,178);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            printf("%c%c%c    %c\n",254,205,185,186);
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.X % 2 == 0)
            {
                printf("  %c%c%c%c%c%c\n",178,176,178,176,178,176);
            }else{
                printf("  %c%c%c%c%c%c\n",176,178,176,178,176,178);
            }
            tank->position.Y -= 2;
            break;
        }
        case EAST:
        {
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.X % 2 == 0)
            {
                printf("%c%c%c%c%c%c  \n",178,176,178,176,178,176);
            }else{
                printf("%c%c%c%c%c%c  \n",176,178,176,178,176,178);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            printf("%c    %c%c%c\n",186,204,205,254);
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.X % 2 == 0)
            {
                printf("%c%c%c%c%c%c  \n",178,176,178,176,178,176);
            }else{
                printf("%c%c%c%c%c%c  \n",176,178,176,178,176,178);
            }
            tank->position.Y -= 2;
            break;
        }
    }
}

bool printBullet (COORD bulletPosition, int one) {
    SetConsoleCursorPosition(hCon,bulletPosition);
    if (MAP[one] == 0) {
        printf("%c", 254);
        return true;
    } else if (MAP[one] == 2 || MAP[one] == 4) {
        MAP[one] = 0;
        printf(" ");
        return false;
    } else return false;
}

bool bulletWay(Tank *tank) {
    
    COORD bulletPosition = tank->position;
    TankDirection shootDir = tank->direction;
    int i = 0;

    switch(shootDir) {
        case NORTH:
            bulletPosition.Y +=5;
        case SOUTH:
            bulletPosition.X +=2;
            break;
        case EAST:
            bulletPosition.X +=8;
        case WEST:
            bulletPosition.Y +=1;
            break;
    }

    while (1) {
        Sleep(20);
        i++;
        switch (shootDir) {
            case SOUTH: {
                int one = 165 * (bulletPosition.Y - 1) + bulletPosition.X;
                if (i > 1) {
                    SetConsoleCursorPosition(hCon,bulletPosition);
                    printf(" ");
                }
                bulletPosition.Y = (bulletPosition.Y - 1);
                if(!printBullet(bulletPosition, one)) return false;
                continue;
            }
            case NORTH: {
                int one = 165 * (bulletPosition.Y + 1) + bulletPosition.X;
                if (i > 1) {
                    SetConsoleCursorPosition(hCon,bulletPosition);
                    printf(" ");
                }
                bulletPosition.Y = (bulletPosition.Y + 1);
                if(!printBullet(bulletPosition, one)) return false;
                continue;
            }
            case EAST: {
                int one = 165 * (bulletPosition.Y) + (bulletPosition.X + 1);
                if (i > 1) {
                    SetConsoleCursorPosition(hCon,bulletPosition);
                    printf(" ");
                }
                bulletPosition.X = (bulletPosition.X + 1);
                if(!printBullet(bulletPosition, one)) return false;
                continue;
            }
            case WEST: {
                int one = 165 * (bulletPosition.Y) + (bulletPosition.X - 1);
                if (i > 1) {
                    SetConsoleCursorPosition(hCon,bulletPosition);
                    printf(" ");
                }
                bulletPosition.X = (bulletPosition.X - 1);
                if(!printBullet(bulletPosition, one)) return false;
                continue;
            }
        }
    }
    

}

void shootThread(void* pParams) {

    Tank *tank = (Tank*) pParams;
    tank->isShot = true;    
    while(bulletWay(tank));
    tank->isShot = false;
  }

void init(){
    system("mode con cols=165 lines=55");
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = false;
    SetConsoleCursorInfo(hCon ,&cci);
}



bool isFreeWay(Tank *tank, TankDirection direction) {
    switch (direction) {
        case SOUTH:{
            int one = MAP[165 * (tank->position.Y - 1) + tank->position.X];
            int two = MAP[165 * (tank->position.Y - 1) + tank->position.X + 1];
            int three = MAP[165 * (tank->position.Y - 1) + tank->position.X + 2];
            int four = MAP[165 * (tank->position.Y - 1) + tank->position.X + 3];
            int five = MAP[165 * (tank->position.Y - 1) + tank->position.X + 4];
            if (one == 0 && two == 0 && three == 0 && four == 0 && five == 0) {
                return true;
            } else {
                return false;
            }
        }
        break;
        case NORTH:{
            int one = MAP[165 * (tank->position.Y + 6) - (165 - tank->position.X)];
            int two = MAP[165 * (tank->position.Y + 6) + tank->position.X + 1];
            int three = MAP[165 * (tank->position.Y + 6) + tank->position.X + 2];
            int four = MAP[165 * (tank->position.Y + 6) + tank->position.X + 3];
            int five = MAP[165 * (tank->position.Y + 6) + tank->position.X + 4];
            if (one == 0 && two == 0 && three == 0 && four == 0 && five == 0) {
                return true;
            } else {
                return false;
            }
        }

        break;
        case WEST:{
            int up = MAP[165 * tank->position.Y + (tank->position.X - 1)];
            int middle = MAP[165 * (tank->position.Y + 1) + (tank->position.X - 1)];
            int down = MAP[165 * (tank->position.Y + 2) + (tank->position.X - 1)];

            if (up == 0 && middle == 0 && down == 0)
                return true;
            else
                return false;
        }
        break;
        case EAST:{
            int up = MAP[165 * tank->position.Y + (tank->position.X + 8)];
            int middle = MAP[165 * (tank->position.Y + 1) + (tank->position.X + 8)];
            int down = MAP[165 * (tank->position.Y + 2) + (tank->position.X + 8)];

            if (up == 0 && middle == 0 && down == 0)
                return true;
            else
                return false;

        }
        break;
    }
}

void ereasePreviousPosition(Tank *tank)
{
    COORD pos = tank->position;

    if (tank->isFirstTurn)
    {
        switch (tank->direction)
        {
            case NORTH:
            case SOUTH:
            {
                pos.Y += 3;
                SetConsoleCursorPosition(hCon,pos);
                printf("     ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf("     ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf("     ");
                break;
            }
            case EAST:
            case WEST:
            {
                pos.X += 5;
                SetConsoleCursorPosition(hCon,pos);
                printf("   ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf("   ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf("   ");
                break;
            }
        }
    }
    else
    {
        switch (tank->direction)
        {
            case NORTH:
            {
                pos.Y;
                SetConsoleCursorPosition(hCon,pos);
                printf("     ");
                break;
            }
            case SOUTH:
            {
                pos.Y += 5;
                SetConsoleCursorPosition(hCon,pos);
                printf("     ");
                break;
            }
            case WEST:
            {
                pos.X += 7;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                break;
            }
            case EAST:
            {
                pos.X;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                break;
            }
        }
    }
}

void checkCollision(Tank *tank, TankDirection direction) {
    switch(direction) {
    case NORTH:
    case SOUTH:{
        int y;
        int i;
        for (i = 0, y = tank->position.Y + 3; i < 3; y++, i++) {
            int one = MAP[165 * y + tank->position.X];
            int two = MAP[165 * y + tank->position.X + 1];
            int three = MAP[165 * y + tank->position.X + 2];
            int four = MAP[165 * y + tank->position.X + 3];
            int five = MAP[165 * y + tank->position.X + 4];
            if (one == 0 && two == 0 && three == 0 && four == 0 && five == 0) {
                continue;
            } else {
                tank->position.Y = y - 6;
                return;
            }
        }
    }
        break;

    case EAST:
    case WEST:{
        int y;
        int i;
        int step;
        for (step = 3,i = 0, y = tank->position.Y; i < 3; y++, i++, step--) {
            int one = MAP[165 * y + tank->position.X + 5 + i];
            int two = MAP[165 * (y + 1) + tank->position.X + 5 + i];
            int three = MAP[165 * (y + 2) + tank->position.X + 5 + i];
            if (one == 0 && two == 0 && three == 0) {
                continue;
            } else {
                tank->position.X -= step;
                return;
            }
        }
        }
        break;
    }
}

void moveTankWithDirection(Tank *tank, TankDirection direction) {

    if (tank->direction == direction) {
        tank->isFirstTurn = false;
    } else {
        tank->isFirstTurn = true;
    }
    ereasePreviousPosition(tank);
    if (tank->isFirstTurn) {
        checkCollision(tank, direction);
        tank->direction = direction;
    } else {
        switch (direction) {
            case SOUTH:
            if (isFreeWay(tank, direction)) {
                tank->position.Y--;
            }
            break;
            case NORTH:
            if (isFreeWay(tank, direction)) {
                tank->position.Y++;
            }
            break;
            case WEST:
            if (isFreeWay(tank, direction)) {
                tank->position.X--;
            }
            break;
            case EAST:
            if (isFreeWay(tank, direction)) {
                tank->position.X++;
            }
            break;
        }
        tank->direction = direction;
    }
    drawTank(tank);
}


int main() {

    init();

    Tank *tank = (Tank*)calloc(1,sizeof(Tank));
    tank->direction = SOUTH;
    tank->position.X = 80;
    tank->position.Y = 48;
    tank->isFirstTurn = false;
    tank->isShot = false;

    func_map(MAP);

    drawTank(tank);

    while(true) {
        int key = getch();
        switch (key) {
            case UP:
            moveTankWithDirection(tank, SOUTH);
            drawTank(tank);
            break;
            case DOWN:
            moveTankWithDirection(tank, NORTH);
            drawTank(tank);
            break;
            case LEFT:
            moveTankWithDirection(tank, WEST);
            drawTank(tank);
            break;
            case RIGHT:
            moveTankWithDirection(tank, EAST);
            drawTank(tank);
            break;
            case SHOT:
            if(tank->isShot) break;
            _beginthread(shootThread, 0, (void*) tank);
            break;
            case EXIT:
            exit(0);
            break;
        }

    }

    return 0;
}
