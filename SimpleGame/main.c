#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

int height = 10, width = 20, gameover, score;
int x, y, fruitX, fruitY, flag;

void Draw()
{
    system("cls");
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printf("#");
            }
            else{
                if(i == x && j == y)
                {
                    printf("+");
                }
                else if(i == fruitX && j == fruitY)
                {
                    printf("x");
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    printf("Your score: %d\n", score);
    printf("Press X to quit game");
}

void Setup()
{
    srand(time(NULL));

    gameover = 0;

    x = height/2;
    y = width/2;

    label1:
        fruitX = rand()%9;
        if(fruitX == 0 || fruitX == x)
        {
            goto label1;
        }
    label2:
        fruitY = rand()%19;
        if(fruitY == 0 || fruitY == y)
        {
            goto label2;
        }
    score = 0;
}

void Input()
{
    switch(getch())
    {
        case 's':
            flag = 1;
            break;
        case 'a':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
    }
}

void Logic()
{
    sleep(0.01);

    switch(flag)
    {
        case 1:
            x++;
            break;
        case 2:
            y--;
            break;
        case 3:
            y++;
            break;
        case 4:
            x--;
            break;
    }

    if (x < 1 || x > height - 2 || y < 1 || y > width - 2)
    {
        gameover = 1;
    }

    if(x == fruitX && y == fruitY)
    {
        srand(time(NULL));

        label3:
            fruitX = rand()%9;
            if(fruitX == 0 || fruitX == x)
            {
                goto label3;
            }
        label4:
            fruitY = rand()%19;
            if(fruitY == 0 || fruitY == y)
            {
                goto label4;
            }
        score += 100;
    }
}

int main()
{
    Setup();

    while(!gameover)
    {
        Draw();
        Input();
        Logic();
    }

    return 0;
}
