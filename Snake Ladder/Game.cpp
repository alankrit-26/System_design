#include <bits/stdc++.h>
using namespace std;

class Dice
{
public:
    int roll()
    {
        return rand() % 6 + 1; // 1–6
    }
};

class Player
{
public:
    string name;
    int id;
    int x;
    int y;
    Player(string name, int id)
    {
        this->name = name;
        this->id = id;
        this->x = 0;
        this->y = 0;
    }
};
class Board : public Dice
{
public:
    vector<vector<int>> board;
    map<pair<int, int>, pair<int, int>> mp;
    Board()
    {
        board.resize(10);
        for (int i = 0; i < 10; i++)
        {
            board[i].resize(10, 0);
        }
        // snake
        mp[{5, 6}] = {2, 3};
        mp[{9, 8}] = {0, 0};
        mp[{6, 5}] = {4, 1};
        mp[{0, 9}] = {0, 1};
        mp[{3, 4}] = {2, 0};
        // ladder
        mp[{1, 2}] = {4, 5};
        mp[{3, 0}] = {7, 1};
        mp[{0, 8}] = {6, 9};
        mp[{0, 4}] = {9, 2};
        mp[{2, 5}] = {8, 5};
    }
    void play(Player &p)
    {
        int num = roll();
        if (p.x + num > 9)
        {
            if (p.y == 9)
            {
                cout << "Can't make move";
                return;
            }
            else
            {
                int x1 = (p.x + num) % 10;
                int y1 = p.y + (p.x + num) / 10;

                if (mp.find({x1, y1}) != mp.end())
                {
                    x1 = mp[{x1, y1}].first;
                    y1 = mp[{x1, y1}].second;
                }
                p.x = x1;
                p.y = y1;
                if (p.x == 9 && p.y == 9)
                {
                    cout << "Player: " << p.name << "Won the game" << endl;
                    return;
                }
                cout << "Current position of " << p.name << " is " << p.x << " " << p.y << endl;
                return;
            }
        }
        else
        {
            int x1 = (p.x + num) % 10;
            int y1 = p.y + (p.x + num) / 10;

            if (mp.find({x1, y1}) != mp.end())
            {
                x1 = mp[{x1, y1}].first;
                y1 = mp[{x1, y1}].second;
            }
            p.x = x1;
            p.y = y1;
            if (p.x == 9 && p.y == 9)
            {
                cout << "Player: " << p.name << "Won the game" << endl;
                return;
            }
            cout << "Current position of " << p.name << " is " << p.x << " " << p.y << endl;
            return;
        }
    }
};

int main()
{
    srand(time(0));
    Player p1("Alankrit", 1);
    Player p2("Ritik", 2);
    Board b;
    bool start = 0;
    bool win = 0;
    for (int i = 0; i < 100; i++)
    {
        if (!start)
        {
            b.play(p1);
        }
        else
        {
            b.play(p2);
        }
        if (p1.x == 9 && p1.y == 9)
        {
            break;
        }
        else if (p2.x == 9 && p2.y == 9)
        {
            break;
        }
        start = !start;
    }
}