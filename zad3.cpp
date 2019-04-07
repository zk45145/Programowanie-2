#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

class Player
{
    private:
    string first_name;
    string last_name;
    int height;
    vector <string> v;

    public:
    Player(string, string, int, vector<string>);
    Player(const Player &);
    Player(){}
    ~Player(){}
    showAttributes();
    changeData();
};

class Team
{
    public:
    Player player1;
    Player player2;
    Player player3;
    Player player4;
    Player player5;
    Team(Player, Player, Player, Player, Player);
    Team(const Team &);
    Team(){}
    ~Team(){}
    showAttributes ();
};

Player :: Player(string first_name_cin, string last_name_cin, int height_cin, vector <string> v_cin)
{
    first_name=first_name_cin;
    last_name=last_name_cin;
    height=height_cin;
    v=v_cin;
}

Player :: Player(const Player &source)
{
    first_name=source.first_name;
    last_name=source.last_name;
    height=source.height;
    v=source.v;
}

Player :: showAttributes()
{
    string text, temp;
    char height_string[3];

    sprintf(height_string, "%d", height);

    text=first_name;
    text+=" ";
    text+=last_name;
    text+="  ";
    text+=height_string;
    text+="  ";
    text+=v[0]+"  "+v[1]+"  "+v[2]+"  "+v[3]+"  "+v[4];
    cout << text << endl;
}

Player :: changeData()
{
    cout << "Podaj nowe dane zawodnika: " << endl;
    cout << "Imie: ";
    getline(cin, first_name);
    cout << "Nazwisko: ";
    getline(cin, last_name);
    cout << "Wzrost (w cm): ";
    cin >> height;
    getchar();
    for (int i=0; i<v.size(); i++)
    {
        cout << "Umiejetnosc nr " << i+1 << ": ";
        getline(cin, v[i]);
    }
}

Team :: Team (Player player1_cin, Player player2_cin, Player player3_cin, Player player4_cin, Player player5_cin)
{
    player1=player1_cin;
    player2=player2_cin;
    player3=player3_cin;
    player4=player4_cin;
    player5=player5_cin;
}

Team :: Team (const Team &source)
{
    player1=source.player1;
    player2=source.player2;
    player3=source.player3;
    player4=source.player4;
    player5=source.player5;
}

Team :: showAttributes()
{
    player1.showAttributes();
    player2.showAttributes();
    player3.showAttributes();
    player4.showAttributes();
    player5.showAttributes();
    cout << endl;
}

int main()
{
    vector <string>skills, skills2, skills3, skills4, skills5;
    skills.push_back("Szybki");
    skills.push_back("Silny");
    skills.push_back("Drybler");
    skills.push_back("Dobrze strzela");
    skills.push_back("Gra glowa");
    Player player1 ("Robert", "Lewandowski", 186, skills);
    skills.clear();

    skills.push_back("Zwinny");
    skills.push_back("Dobre podanie");
    skills.push_back("Drybler");
    skills.push_back("Kreatywny");
    skills.push_back("Rzuty wolne");
    Player player2 ("Piotr", "Zielinski", 177, skills);
    skills.clear();

    skills.push_back("Skoczny");
    skills.push_back("Silny");
    skills.push_back("Wykonczenie");
    skills.push_back("Dobrze strzela");
    skills.push_back("Gra glowa");
    Player player3 ("Krzysztof", "Piatek", 187, skills);
    skills.clear();

    skills.push_back("Przywodca");
    skills.push_back("Silny");
    skills.push_back("Wslizgi");
    skills.push_back("Odbior pilki");
    skills.push_back("Gra glowa");
    Player player4 ("Kamil", "Glik", 188, skills);
    skills.clear();

    skills.push_back("Szybki");
    skills.push_back("Towarzyski");
    skills.push_back("Drybler");
    skills.push_back("Rzuty rozne");
    skills.push_back("Blyskotliwy");
    Player player5 ("Kamil", "Grosicki", 180, skills);
    skills.clear();

    Team team1 (player1, player2, player3, player4, player5);

    skills.push_back("Podania");
    skills.push_back("Rozgrywanie");
    skills.push_back("Drybler");
    skills.push_back("Wizja gry");
    skills.push_back("Strzaly");
    Player player6 ("Karim", "Benzema", 184, skills);
    skills.clear();

    skills.push_back("Blyskotliwy");
    skills.push_back("Szybki");
    skills.push_back("Drybler");
    skills.push_back("Kreatywny");
    skills.push_back("Rzuty wolne");
    Player player7 ("Vinicius", "Junior", 174, skills);
    skills.clear();

    skills.push_back("Skoczny");
    skills.push_back("Silny");
    skills.push_back("Odbior pilki");
    skills.push_back("Rzuty karne");
    skills.push_back("Gra glowa");
    Player player8 ("Sergio", "Ramos", 186, skills);
    skills.clear();

    skills.push_back("Przywodca");
    skills.push_back("Pracowity");
    skills.push_back("Podania");
    skills.push_back("Kreatywny");
    skills.push_back("Walecznosc");
    Player player9 ("Luka", "Modric", 176, skills);
    skills.clear();

    skills.push_back("Szybki");
    skills.push_back("Strzaly");
    skills.push_back("Drybler");
    skills.push_back("Rzuty wolne");
    skills.push_back("Wytrzymalosc");
    Player player10 ("Gareth", "Bale", 187, skills);
    skills.clear();

    Team team2 (player6, player7, player8, player9, player10);

    Team team3 (team2);

    team1.showAttributes();
    team2.showAttributes();
    team3.showAttributes();


    // do zmiany danych zawodnika:
    player1.changeData();
    team1.player1=player1;
    cout << endl;

    team1.showAttributes();
    team2.showAttributes();
    team3.showAttributes();


    return 0;
}
