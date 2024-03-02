#include <iostream>
using namespace std;
class Game
{
private:
    string p1, p2;
    string a, b, c;
    string y, n;
    string choice;

public:
    Game()
    {
        a = "rock";
        b = "scissors";
        c = "paper";
    }
    void condition_check()
    {
        if ((p1 != a && p1 != b && p1 != c) || (p2 != a && p2 != b && p2 != c) || (p1 == p2))
        {
            cout << "invalid input for player 1 and player 2";
        }
    }

    void input()
    {

        cout << "enter the item of player 1 ";
        cin >> p1;
        cout << "enter the item of player 2:";
        cin >> p2;
    }

    void game_algo()
    {
        if (p1 == a && p2 == a || p1 == b && p2 == b || p1 == c && p2 == c)
        {
            cout << "it is draw" << endl;
        }
        else if (p1 == a && p2 == b || p1 == b && p2 == c || p1 == c && p2 == a)
        {
            cout << "player 1 wins" << endl;
        }
        else
        {
            cout << "player 2 wins" << endl;
        }
    }

    void play()
    {

        cout << "Do you want to play again?" << endl;
        cin >> choice;
        if (choice == "y")
        {
            input();
            game_algo();
        }
        else
        {
            cout << "sorry! you cannot play now";
        }
    }
};
int main()
{
    Game g;

    g.input();
    g.game_algo();
    g.play();

    return 0;
}
