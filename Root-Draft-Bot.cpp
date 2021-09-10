#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

class Factions {
public:
    string Name;
    int Reach, Number;

};

    
int main()
{

    int PlayerNum, FactionChoice;
    string PlayerName;
    vector<string> Players;

    cout << "Welcome to the Root Draft Bot" << endl << endl;
    cout << "How many players are playing" << endl << endl;
    cin >> PlayerNum;
    int NumPlayer = PlayerNum;
    cout << endl;
    int RandPlayer = rand() % PlayerNum;

    cout << "Who is playing" << endl << endl;
    for (int a = PlayerNum; a > 0; a--)
    {
        cin >> PlayerName;
        Players.push_back(PlayerName);
    }
    cout << endl;

    cout << "Turn Order:" << endl << endl;

    srand(unsigned(std::time(0)));
    random_shuffle(Players.begin(), Players.end());
    for (unsigned i = 0; i < PlayerNum; ++i)
        cout << Players[i] << endl;

    cout << "Drafting:" << endl << endl;

    int ReachGoal = 0;
    vector<Factions> AvailFactions;
    AvailFactions.resize(9);
    AvailFactions[0].Name = "Marquise De Cat"; AvailFactions[0].Reach = 10; AvailFactions[0].Number = 0;
    AvailFactions[1].Name = "Duchy"; AvailFactions[1].Reach = 8; AvailFactions[1].Number = 1;
    AvailFactions[2].Name = "Eyrie"; AvailFactions[2].Reach = 7; AvailFactions[2].Number = 2;
    AvailFactions[3].Name = "Vagabond #1"; AvailFactions[3].Reach = 6; AvailFactions[3].Number = 3;
    AvailFactions[4].Name = "Riverfolk"; AvailFactions[4].Reach = 5; AvailFactions[4].Number = 4;
    AvailFactions[5].Name = "Woodland"; AvailFactions[5].Reach = 3; AvailFactions[5].Number = 5;
    AvailFactions[6].Name = "Corvids"; AvailFactions[6].Reach = 3; AvailFactions[6].Number = 6;
    AvailFactions[7].Name = "Vagabond #2"; AvailFactions[7].Reach = 2; AvailFactions[7].Number = 7;
    AvailFactions[8].Name = "Lizard Cult"; AvailFactions[8].Reach = 2; AvailFactions[8].Number = 8;

    if (PlayerNum == 2)
    {
        ReachGoal = 17;
        AvailFactions.resize(3);
    }
    if (PlayerNum == 3)
        ReachGoal = 18;
    if (PlayerNum == 4)
        ReachGoal = 21;
    if (PlayerNum == 5)
        ReachGoal = 25;
    if (PlayerNum == 6)
        ReachGoal = 28;

    
    for (unsigned i = 0; i < PlayerNum; ++i)
    {
        cout << Players[PlayerNum - i - 1] << " you're up!" << endl << endl;
        cout << "Options:" << endl << endl;
        for (unsigned a = 0; a < AvailFactions.size(); ++a)
            cout << AvailFactions[a].Number << ". " << AvailFactions[a].Name << endl;
        cin >> FactionChoice;
        ReachGoal = ReachGoal - AvailFactions[FactionChoice].Reach;
        AvailFactions.erase(AvailFactions.begin() + FactionChoice);
        NumPlayer--;
        for (int a = AvailFactions.size()-1; a >= 0; a--)
        {
            if (NumPlayer > 0)
            AvailFactions[a].Number = a;
                if (NumPlayer == 1)
                    if (AvailFactions[a].Reach < ReachGoal)
                    {
                        AvailFactions.erase(AvailFactions.begin() + a);
                    }
                if (NumPlayer == 2)
                    if (AvailFactions[a].Reach < ReachGoal - AvailFactions[0].Reach)
                    {
                        AvailFactions.erase(AvailFactions.begin() + a);
                    }
                if (NumPlayer == 3)
                    if (AvailFactions[a].Reach < ReachGoal - AvailFactions[0].Reach - AvailFactions[1].Reach)
                    {
                        AvailFactions.erase(AvailFactions.begin() + a);
                    }
                if (NumPlayer == 4)
                    if (AvailFactions[a].Reach < ReachGoal - AvailFactions[0].Reach - AvailFactions[1].Reach - AvailFactions[2].Reach)
                    {
                        AvailFactions.erase(AvailFactions.begin() + a);
                    }
                if (NumPlayer == 5)
                    if (AvailFactions[a].Reach < ReachGoal - AvailFactions[0].Reach - AvailFactions[1].Reach - AvailFactions[2].Reach - AvailFactions[3].Reach)
                    {
                        AvailFactions.erase(AvailFactions.begin() + a);
                    }


        }
    }

    cout << "Done!" << endl;
    return(0);
}