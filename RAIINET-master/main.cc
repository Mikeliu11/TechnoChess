#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Display.h"
#include "abDownload.h"
#include "abFirewall.h"
#include "abLinkedBoost.h"
#include "abPolarize.h"
#include "abScan.h"
#include "ability.h"
#include "abStrengthBoost.h"
#include "board.h"
//#include "GraphicsDisplay.h"
#include "TextDisplay.h"

using namespace std;

vector<Ability *> addAbilities(string a, int player)
{
    int size = a.length();
    if (size != 5)
        cerr << "Warning: Did not input 5 abilities for a player " << endl;
    vector<Ability *> ab;
    for (int i = 0; i < size; ++i)
    {
        if (a[i] == 'L')
        {
            Ability *newAb = new LinkedBoost(player);
            ab.emplace_back(newAb);
        }
        else if (a[i] == 'F')
        {
            Ability *newAb = new Firewall(player);
            ab.emplace_back(newAb);
        }
        else if (a[i] == 'D')
        {
            Ability *newAb = new Download(player);
            ab.emplace_back(newAb);
        }
        else if (a[i] == 'S')
        {
            Ability *newAb = new Scan(player);
            ab.emplace_back(newAb);
        }
        else if (a[i] == 'P')
        {
            Ability *newAb = new Polarize(player);
            ab.emplace_back(newAb);
        } else if (a[i] == 'B') {
            Ability *newAb = new StrengthBoost(player);
            ab.emplace_back(newAb);
        }
    }
    return ab;
}

vector<Link> addLinks(string a, int player)
{
    int counter = 0;
    vector<Link> lk;
    int size = a.length();
    if (size != 16)
        cerr << "Warning: Did not input 8 links for player " + player << endl;
    for (int i = 0; i < size; ++i)
    {
        char charType = a[i];
        LinkType type;
        if (charType == 'D')
        {
            type = LinkType::Data;
        }
        else
        {
            type = LinkType::Virus;
        }
        ++i;
        int strength = a[i] - '0';
        char name;
        if (player == 1)
        {
            name = counter + 'a';
        }
        else
        {
            name = counter + 'A';
        }
        ++counter;
        Link newLink{name, strength, type, player};
        lk.emplace_back(newLink);
    }
    return lk;
}

vector<vector<Square>> addGrid(vector<Link> &p1Links, vector<Link> &p2Links)
{
    vector<vector<Square>> grid;
    for (int i = 0; i < 8; i++)
    {
        vector<Square> temp;
        for (int j = 0; j < 8; j++)
        {
            if (i == 0)
            {
                if (j != 3 && j != 4)
                {
                    temp.emplace_back(Square(i, j, 0, 0, &p1Links[j]));
                }
                else
                {
                    temp.emplace_back(Square(i, j, 1, 0, nullptr));
                }
            }
            else if (i == 1 && (j == 3 || j == 4))
            {
                temp.emplace_back(Square(i, j, 0, 0, &p1Links[j]));
            }
            else if (i == 6 && (j == 3 || j == 4))
            {
                temp.emplace_back(Square(i, j, 0, 0, &p2Links[j]));
            }
            else if (i == 7)
            {
                if (j != 3 && j != 4)
                {
                    temp.emplace_back(Square(i, j, 0, 0, &p2Links[j]));
                }
                else
                {
                    temp.emplace_back(Square(i, j, 2, 0, nullptr));
                }
            }
            else
            {
                temp.emplace_back(Square(i, j, 0, 0, nullptr));
            }
        }
        grid.emplace_back(temp);
    }
    return grid;
}

int main(int argc, char *argv[])
{
    vector<Ability *> player1Abilities = addAbilities("LFDSP", 1);
    vector<Ability *> player2Abilities = addAbilities("LFDSP", 2);
    vector<Link> player1Links = addLinks("V1V2V3V4D1D2D3D4", 1);
    vector<Link> player2Links = addLinks("V1V2V3V4D1D2D3D4", 2);
    bool graphics = false;
    int position = 1;
    while (position < argc)
    {
        string cmd = argv[position];
        if (cmd == "-ability1")
        {
            ++position;
            string abilities = argv[position];
            player1Abilities.clear();
            player1Abilities = addAbilities(abilities, 1);
        }
        else if (cmd == "-ability2")
        {
            ++position;
            string abilities = argv[position];
            player2Abilities.clear();
            player2Abilities = addAbilities(abilities, 2);
        }
        else if (cmd == "-link1")
        {
            ++position;
            string linkPosn = argv[position];
            player1Links.clear();
            player1Links = addLinks(linkPosn, 1);
        }
        else if (cmd == "-link2")
        {
            ++position;
            string linkPosn = argv[position];
            player2Links.clear();
            player2Links = addLinks(linkPosn, 2);
        }
        else if (cmd == "-graphics")
        {
            graphics = true;
        }
        ++position;
    }
    Player playerOne{1, player1Abilities, player1Links, player2Links};
    Player playerTwo{2, player2Abilities, player2Links, player1Links};
    vector<Player *> players;
    players.emplace_back(&playerOne);
    players.emplace_back(&playerTwo);

    vector<vector<Square>> grid = addGrid(player1Links, player2Links);

    Board b{players, grid}; // OUR BOARD!!

    TextDisplay display{&b};
    display.showBoard();
    int winner = 0;
    bool redo = false;
    bool again = false;
    bool ability = false;
    bool seq = false;
    ifstream infile;
    string firstInput;
    cin >> firstInput;
    if (firstInput == "sequence")
    {
        string filename;
        cin >> filename;
        infile.open(filename);
        seq = true;
    }
    istream &i = seq ? infile : cin;

    while (true)
    {
        again = false;
        redo = false;
        string input;
        char ID;
        if (!seq)
        {
            input = firstInput;
        }
        else
        {
            display.showBoard();
            i >> input;
        }
        if (i.eof())
        {
            break;
        }
        if (input == "ability")
        {
            string info;
            if (ability == true)
            {
                redo = true;
                getline(i, info);
            }
            else
            {
                ability = true;
                int abID;
                i >> abID;
                abID--;
                ws(i);
                getline(i, info);
                stringstream ss(info);
                char c;
                while (ss >> c)
                {
                    if (c >= '0' && c <= '7')
                    {
                        char c2;
                        ss >> c2;
                        if (c2 >= '0' && c2 <= '7')
                        {
                            int row = c - '0';
                            int col = c2 - '0';
                            if (!b.useAbility(abID, b.getSquare(row, col)))
                            {
                                redo = true;
                            }
                        }
                        else
                        {
                            redo = true;
                        }
                    }
                    else
                    {
                        if (b.hasLink(c))
                        {
                            if (!b.useAbility(abID, b.getSquare(c)))
                            {
                                redo = true;
                            }
                        }
                        else
                        {
                            redo = true;
                        }
                    }
                    if(!redo){again = true;}
                }
            }
        }
        if (input == "move")
        {
            i >> ID;
            string dir;
            i >> dir;
            if (b.hasLink(ID))
            {
                if (!b.move(b.getSquare(ID), dir))
                {
                    redo = true;
                }
            }
            else
            {
                redo = true;
            }
            ability = false;
        }
        if (input == "abilities")
        {
            b.printAbilities();
            again = true;
        }
        else if (input == "board")
        {
            again = true;
            display.showBoard();
        }
        else if (input == "quit")
        {
            break;
        }
        if (b.isGameOver())
        {
            winner = b.whoWon();
            break;
        }

        if (redo)
        {
            cout << endl<< "invalid input. Try again" << endl;
        }
        else if (!again)
        {
            b.nextTurn();
        }
        seq = true;
    }
    cout << endl <<"Player " << winner << " Wins!" << endl;
    return 0;
}