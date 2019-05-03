#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <istream>
#include <fstream>
#include <ctime>
#include <sstream>
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
    Player (string);
    Player(){}
    ~Player(){}
    showAttributes();
    string saveAttributes(string);
    changeData();
};

class Team
{
    public:
    vector <Player> players;
    Team(vector <Player>);
    Team(const Team &);
    Team(){}
    ~Team(){}
    showAttributes();
    saveAttributes(string);
    readFile(string);
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

Player :: Player (string one_player_data) // przetwarzanie linii wczytanej z pliku na dane zawodnika
{

    int i=0;
    first_name="";
    last_name="";
    v.clear();
    string height_string="";
    string skill="";
    while (one_player_data[i]!=';')                 // wczytywanie danych ze stringa do pól obiektu
    {
        first_name+=one_player_data[i];
        i++;
    }
    i++;
    while (one_player_data[i]!=';')
    {
        last_name+=one_player_data[i];
        i++;
    }
    i++;
    while (one_player_data[i]!=';')
    {
        height_string+=one_player_data[i];
        i++;
    }
    sscanf(height_string.c_str(), "%d", &height);
    i++;

    while (v.size()<5)
    {
        while (one_player_data[i]!=';')
        {
            skill+=one_player_data[i];
            i++;
        }
    v.push_back(skill);
    skill="";
    i++;
    }

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

string Player :: saveAttributes(string save_to_file)
{
    string text;
    char height_string[3];

    sprintf(height_string, "%d", height);

    text=first_name;
    text+=";";
    text+=last_name;
    text+=";";
    text+=height_string;
    text+=";";
    text+=v[0]+";"+v[1]+";"+v[2]+";"+v[3]+";"+v[4];
    text+=";";

    return text;
}


Player :: changeData()
{
    cin.ignore();
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

Team :: Team (vector<Player> players_cin)
{
    for(int i=0; i<5; i++)
    {
        players.push_back(players_cin[i]);
    }
}

Team :: Team (const Team &source)
{
    for (int i=0; i<5; i++)
    {
        players.push_back(source.players[i]);
    }
}

Team :: showAttributes()
{
    for (int i=0; i<5; i++)
    {
        players[i].showAttributes();
    }
    cout << endl;
}

Team :: saveAttributes(string save_to_file)
{
    ofstream save1 (save_to_file.c_str());
    for (int i=0; i<5; i++)
    {
        save1 << players[i].saveAttributes(save_to_file);
        if (i<4) save1 << endl;
    }
    cout << "Zapis zakonczony powodzeniem." << endl;
}


Team :: readFile(string file_name)
{
    ifstream file;
    file.open(file_name.c_str(), ios::in);
        if(!file)
        {
                cout << "Blad odczytu pliku! " << endl;
                return false;
        }

      do
      {
        string one_player_data;
        getline(file,one_player_data);
        Player temp(one_player_data);
        players.push_back(temp);
      }
      while (!file.eof());
      file.close();
}


int main()
{
    Team team4;                                         //utworzenie obiektu druzyny do wczytania z pliku (nazwa pliku: francja.txt)
    string file_name;
    cout << "Podaj nazwe pliku wejsciowego: "<< endl;
    cin >> file_name;
    team4.readFile(file_name);


    vector <Player> players_cin;
    vector <string>skills;
    skills.push_back("Szybki");
    skills.push_back("Silny");
    skills.push_back("Drybler");
    skills.push_back("Dobrze strzela");
    skills.push_back("Gra glowa");
    Player player1 ("Robert", "Lewandowski", 186, skills);
    players_cin.push_back(player1);
    skills.clear();

    skills.push_back("Zwinny");
    skills.push_back("Dobre podanie");
    skills.push_back("Drybler");
    skills.push_back("Kreatywny");
    skills.push_back("Rzuty wolne");
    Player player2 ("Piotr", "Zielinski", 177, skills);
    players_cin.push_back(player2);
    skills.clear();

    skills.push_back("Skoczny");
    skills.push_back("Silny");
    skills.push_back("Wykonczenie");
    skills.push_back("Dobrze strzela");
    skills.push_back("Gra glowa");
    Player player3 ("Krzysztof", "Piatek", 187, skills);
    players_cin.push_back(player3);
    skills.clear();

    skills.push_back("Przywodca");
    skills.push_back("Silny");
    skills.push_back("Wslizgi");
    skills.push_back("Odbior pilki");
    skills.push_back("Gra glowa");
    Player player4 ("Kamil", "Glik", 188, skills);
    players_cin.push_back(player4);
    skills.clear();

    skills.push_back("Szybki");
    skills.push_back("Towarzyski");
    skills.push_back("Drybler");
    skills.push_back("Rzuty rozne");
    skills.push_back("Blyskotliwy");
    Player player5 ("Kamil", "Grosicki", 180, skills);
    players_cin.push_back(player5);
    skills.clear();

    Team team1 (players_cin);
    players_cin.clear();



    skills.push_back("Podania");
    skills.push_back("Rozgrywanie");
    skills.push_back("Drybler");
    skills.push_back("Wizja gry");
    skills.push_back("Strzaly");
    Player player6 ("Karim", "Benzema", 184, skills);
    players_cin.push_back(player6);
    skills.clear();

    skills.push_back("Blyskotliwy");
    skills.push_back("Szybki");
    skills.push_back("Drybler");
    skills.push_back("Kreatywny");
    skills.push_back("Rzuty wolne");
    Player player7 ("Vinicius", "Junior", 174, skills);
    players_cin.push_back(player7);
    skills.clear();

    skills.push_back("Skoczny");
    skills.push_back("Silny");
    skills.push_back("Odbior pilki");
    skills.push_back("Rzuty karne");
    skills.push_back("Gra glowa");
    Player player8 ("Sergio", "Ramos", 186, skills);
    players_cin.push_back(player8);
    skills.clear();

    skills.push_back("Przywodca");
    skills.push_back("Pracowity");
    skills.push_back("Podania");
    skills.push_back("Kreatywny");
    skills.push_back("Walecznosc");
    Player player9 ("Luka", "Modric", 176, skills);
    players_cin.push_back(player9);
    skills.clear();

    skills.push_back("Szybki");
    skills.push_back("Strzaly");
    skills.push_back("Drybler");
    skills.push_back("Rzuty wolne");
    skills.push_back("Wytrzymalosc");
    Player player10 ("Gareth", "Bale", 187, skills);
    players_cin.push_back(player10);
    skills.clear();

    Team team2 (players_cin);
    players_cin.clear();


    Team team3 (team2);


    team1.showAttributes();
    team2.showAttributes();
    team3.showAttributes();
    team4.showAttributes();



    // do zmiany danych zawodnika z wczytanej druzyny:
    team4.players[0].changeData();
    cout << endl;

    team1.showAttributes();
    team2.showAttributes();
    team3.showAttributes();
    team4.showAttributes();

// budowanie nazwy pliku
    time_t t = time(0);
    struct tm *now=localtime(&t);
    string time;
    ostringstream ss;

    ss << now->tm_hour << now->tm_min << now->tm_sec;
    time=ss.str();

    cin.ignore();
    string save_to_file="druzyna_";
    string team_name;
    cout << "Podaj nazwe druzyny nr 1: ";
    getline (cin, team_name);
    save_to_file+=team_name+'_'+time+".txt";
    team1.saveAttributes(save_to_file);

    save_to_file="druzyna_";
    cout << "Podaj nazwe druzyny nr 2: ";
    getline (cin, team_name);
    save_to_file+=team_name+'_'+time+".txt";
    team2.saveAttributes(save_to_file);

    save_to_file="druzyna_";
    cout << "Podaj nazwe druzyny nr 3: ";
    getline (cin, team_name);
    save_to_file+=team_name+'_'+time+".txt";
    team3.saveAttributes(save_to_file);

    save_to_file="druzyna_";
    cout << "Podaj nazwe druzyny nr 4: ";
    getline (cin, team_name);
    save_to_file+=team_name+'_'+time+".txt";
    team4.saveAttributes(save_to_file);


    return 0;
}
