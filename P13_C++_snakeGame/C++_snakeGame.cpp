#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// declare variables
bool gameOver;
const int width = 20;
const int height = 20;
int score, x, y;
int tailX[100], tailY[100], nTail;
int fruitX, fruitY;
enum direction {STOP=0, LEFT, RIGHT, UP, DOWN}dir;


// game settings when the game starts
void Setup()
{
    gameOver = false;
    score = 0;
    // Snake head position in the middle
    x = width/2;
    y = height/2;
    // fruit position - random
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Draw()
{
    system("cls");
    // draw the upper line of the frame
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;

    // draw the left and right sides of the frame, the snake
    // and the fruit, and make what left empty
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            if (i == 0)
            {
                cout << "#";
            }
            if (i == x && j == y)
            {
                cout << "O";
            }
            else if (i == fruitX && j == fruitY)
            {
                cout << "F";
            }
            else
            {
                bool isTail = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == i && tailY[k] == j)
                    {
                        cout << "o";
                        isTail = true;
                    }
                }
                if (!isTail)
                    cout << " ";
            }

            if (i == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    // draw the lower line of the frame
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;

    // display the score
    cout << "Score: " << score << endl;

}

void Input()
{
    // check player input and make it a value to dir variable
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }

}

void Logic()
{
    // make the tail elements follow each other
    for (int i = nTail - 1; i > 0; --i)
    {
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }
    // set the position of the first element of the tail as
    // the snake's head position so the rest of elements follow the snake
    tailX[0] = x;
    tailY[0] = y;

    switch (dir)
    {
        // change snake's head position depending on directions
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }

    // make snake loop from the frame borders
    if (x >= width)
    {
        x = 0;
    }
    else if (x < 0)
    {
        x = width - 1;
    }

    if (y >= height)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = height - 1;
    }

    // if snake and tail in the same position game is over
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    // when snake eats fruit; increase tails elements,
    // add 10 to score, change fruit position
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}


int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(10);
    }

    return 0;
}