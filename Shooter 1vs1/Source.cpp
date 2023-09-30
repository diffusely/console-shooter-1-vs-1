#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

string Bullet1[5];
string Healt1[5];
string Bullet2[5];
string Healt2[5];
int q = 4, q1 = 4;
int d = 4, d1 = 4;

class Bullet
{
public:
    int damage = 1;
    int speed = 1;
    int x = 25;
    int y = 25;
    bool bulletmove = false;
};

class Player
{
public:

    bool gameover = true;
    int quantity = 5;
    int health = 5;
    int speed = 1;
    int x = 5;
    int y = 2;

    void PlayerPoss(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

};

void Map(const int rows, const int cols, string arr[][26])
{
    for (int i = 0; i < 5; i++)
    {
        Healt2[i] = Healt1[i] = "&";
        Bullet2[i] = Bullet1[i] = "|";
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 || i == rows - 1)  // TT --- ||
            {
                arr[i][j] = "#";
            }
            else if (j == 0 || j == cols - 1) // TT --- ||
            {
                arr[i][j] = "#";
            }
            else arr[i][j] = " ";
        }
    }
}


void MapPrint(const int rows, const int cols, string arr[][26], Player& player1, Player& player2)
{

    for (int i = 0; i < rows; i++)
    {
        if (i == 0) cout << "|player1|             ";
        else if (i == 1)
        {
            cout << "Healt:";
            for (int k = 0; k < 5; k++)
            {
                cout << Healt1[k];
            }
            cout << "           ";
        }
        else if (i == 2)
        {
            cout << "Bullet:";
            for (int k = 0; k < 5; k++)
            {
                cout << Bullet1[k];
            }
            cout << "          ";
        }
        else cout << "                      ";
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j];
        }
        if (i == 0)
        {
            cout << "    |player2|";

        }
        if (i == 1)
        {
            cout << "    " << "Healt:";
            for (int k = 0; k < 5; k++)
            {
                cout << Healt2[k];
            }

        }
        if (i == 2)
        {
            cout << "    " << "Bullet:";
            for (int k = 0; k < 5; k++)
            {
                cout << Bullet2[k];
            }
        }
        cout << endl;
    }

}


void Move(Player& player1, Player& player2, string arr[][26], Bullet bullet[], int rows, int cols)
{

    if (GetAsyncKeyState(68) && player1.y < cols - 2)
    {
        arr[player1.x][player1.y] = " ";
        player1.y += player1.speed;
        arr[player1.x][player1.y] = "@";
    }
    if (GetAsyncKeyState(65) && player1.y > 1)
    {
        arr[player1.x][player1.y] = " ";
        player1.y -= player1.speed;
        arr[player1.x][player1.y] = "@";
    }
    if (GetAsyncKeyState(87) && player1.x > 1)
    {
        arr[player1.x][player1.y] = " ";
        player1.x -= player1.speed;
        arr[player1.x][player1.y] = "@";
    }
    if (GetAsyncKeyState(83) && player1.x < rows - 2)
    {
        arr[player1.x][player1.y] = " ";
        player1.x += player1.speed;
        arr[player1.x][player1.y] = "@";
    }
    if (GetAsyncKeyState(39) && player2.y < cols - 2)
    {
        arr[player2.x][player2.y] = " ";
        player2.y += player2.speed;
        arr[player2.x][player2.y] = "*";
    }
    if (GetAsyncKeyState(37) && player2.y > 1)
    {
        arr[player2.x][player2.y] = " ";
        player2.y -= player2.speed;
        arr[player2.x][player2.y] = "*";
    }
    if (GetAsyncKeyState(40) && player2.x < rows - 2)
    {
        arr[player2.x][player2.y] = " ";
        player2.x += player2.speed;
        arr[player2.x][player2.y] = "*";
    }
    if (GetAsyncKeyState(38) && player2.x > 1)
    {
        arr[player2.x][player2.y] = " ";
        player2.x -= player2.speed;
        arr[player2.x][player2.y] = "*";
    }
    if (GetAsyncKeyState(VK_SPACE))
    {
        for (int i = 0; i < 5; i++)
        {
            if (bullet[i].bulletmove == false)
            {
                player1.quantity--;
                Bullet1[d--] = " ";
                bullet[i].bulletmove = true;
                bullet[i].x = player1.x;
                bullet[i].y = player1.y;
                break;
            }
        }


    }

    if (GetAsyncKeyState(VK_ESCAPE))
    {
        for (int i = 5; i < 10; i++)
        {
            if (bullet[i].bulletmove == false)
            {
                player2.quantity--;
                Bullet2[d1--] = " ";
                bullet[i].bulletmove = true;
                bullet[i].x = player2.x;
                bullet[i].y = player2.y;
                break;
            }
        }


    }

    for (int i = 0; i < 5; i++)
    {
        if (bullet[i].bulletmove)
        {
            if (player1.x != bullet[i].x || player1.y != bullet[i].y)
            {
                arr[bullet[i].x][bullet[i].y] = " ";
            }
            bullet[i].y += bullet[i].speed;
            arr[bullet[i].x][bullet[i].y] = "o";


        }
        if (bullet[i].y == cols - 1)
        {
            bullet[i].bulletmove = false;
            arr[bullet[i].x][bullet[i].y] = "#";
            bullet[i].x = 14;
            bullet[i].y = 25;
            player1.quantity++;
            Bullet1[++d] = "|";
        }
    }
    for (int i = 5; i < 10; i++)
    {
        if (bullet[i].bulletmove)
        {
            if (player2.x != bullet[i].x || player2.y != bullet[i].y)
            {
                arr[bullet[i].x][bullet[i].y] = " ";
            }
            bullet[i].y -= bullet[i].speed;
            arr[bullet[i].x][bullet[i].y] = "o";


        }
        if (bullet[i].y == 0)
        {
            bullet[i].bulletmove = false;
            arr[bullet[i].x][bullet[i].y] = "#";
            bullet[i].x = 14;
            bullet[i].y = 25;
            player2.quantity++;
            Bullet2[++d1] = "|";
        }
    }
}

void Damage(Bullet bullet[], Player& player2, string arr[][26], Player& player1)
{
    for (int i = 0; i < 5; i++)
    {
        if (bullet[i].x == player2.x && bullet[i].y == player2.y)
        {
            Healt2[q--] = "";
            player2.health--;
            player1.quantity++;
            Bullet1[++d] = "|";
            bullet[i].bulletmove = false;
            arr[player2.x][player2.y] = "*";
            bullet[i].x = 14;
            bullet[i].y = 25;
        }
    }
    for (int i = 5; i < 10; i++)
    {
        if (bullet[i].x == player1.x && bullet[i].y == player1.y)
        {
            Healt1[q1--] = " ";
            player1.health--;
            player2.quantity++;
            Bullet2[++d1] = "|";
            bullet[i].bulletmove = false;
            arr[player1.x][player1.y] = "@";
            bullet[i].x = 14;
            bullet[i].y = 25;
        }
    }


}

void GameOver(Player& player1, Player& player2)
{
    if (player1.health == 0)
    {
        player1.gameover = false;
    }
    if (player2.health == 0)
    {
        player2.gameover = false;
    }
}

int main()
{
    const int rows = 12;
    const int cols = 24;
    string arr[14][26];
    Player player1, player2;
    Bullet bullet[10];
    player1.PlayerPoss(6, 2);
    player2.PlayerPoss(5, 20);
    Map(rows, cols, arr);
    arr[player1.x][player1.y] = "@";
    arr[player2.x][player2.y] = "*";

    do {

        MapPrint(rows, cols, arr, player1, player2);
        Move(player1, player2, arr, bullet, rows, cols);
        Damage(bullet, player2, arr, player1);
        GameOver(player1, player2);
        Sleep(100);
        system("cls");

    } while (player1.gameover && player2.gameover);

    if (player1.gameover)
    {
        cout << "win player1!!";

    }
    else cout << "win player2 !!";


    return 0;
}