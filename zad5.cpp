#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

class Object
{
    public:
    string name;
    int value;

    Object(){}
    Object(string, int);
};

class Room
{
    public:
    string description;
    int x,y;
    Room *n, *e, *s, *w;
    Object* object;

    Room();
    Room (string, int, int);
    getDescription(string);
    getPointerN(Room*);
    getPointerE(Room*);
    getPointerS(Room*);
    getPointerW(Room*);
    bool checkObject();
    string returnObject();
};

Object :: Object (string name_input, int value_input)
{
    name=name_input;
    value=value_input;
}


Room :: Room (string description_input, int x_input, int y_input)
{
    description=description_input;
    x=x_input;
    y=y_input;
}

Room :: getDescription (string description_input)
{
    description=description_input;
}

Room :: getPointerN (Room *n_input)
{
    *n=*n_input;
}

Room :: getPointerE (Room *e_input)
{
    *e=*e_input;
}

Room :: getPointerS (Room *s_input)
{
    *s=*s_input;
}

Room :: getPointerW (Room *w_input)
{
    *w=*w_input;
}

bool Room :: checkObject()
{
    if (object!=NULL) return 1;
    else return 0;
}

string Room :: returnObject()
{
    return object->name;
}


int main()
{
    srand(time(NULL));

    Room* room1 = new Room ("Pomieszczenie 1", 0, 0);
    Room* room2 = new Room ("Pomieszczenie 2", 0, 1);
    Room* room3 = new Room ("Pomieszczenie 3", 0, 2);
    Room* room4 = new Room ("Pomieszczenie 4", 0, 3);
    Room* room5 = new Room ("Pomieszczenie 5", 0, 4);
    Room* room6 = new Room ("Pomieszczenie 6", 0, 5);
    Room* room7 = new Room ("Pomieszczenie 7", 1, 0);
    Room* room8 = new Room ("Pomieszczenie 8", 1, 1);
    Room* room9 = new Room ("Pomieszczenie 9", 1, 2);
    Room* room10 = new Room ("Pomieszczenie 10", 1, 3);
    Room* room11 = new Room ("Pomieszczenie 11", 1, 4);
    Room* room12 = new Room ("Pomieszczenie 12", 1, 5);
    Room* room13 = new Room ("Pomieszczenie 13", 2, 0);
    Room* room14 = new Room ("Pomieszczenie 14", 2, 1);
    Room* room15 = new Room ("Pomieszczenie 15", 2, 2);
    Room* room16 = new Room ("Pomieszczenie 16", 2, 3);
    Room* room17 = new Room ("Pomieszczenie 17", 2, 4);
    Room* room18 = new Room ("Pomieszczenie 18", 2, 5);

    room1->n=NULL;  room1->e=room2; room1->s=NULL; room1->w=NULL; room1->object=NULL;
    room2->n=NULL;  room2->e=NULL; room2->s=room7; room2->w=room1; room2->object=NULL;
    room3->n=NULL;  room3->e=NULL; room3->s=room9; room3->w=NULL; room3->object=NULL;
    room4->n=NULL;  room4->e=room5; room4->s=room11; room4->w=NULL; room4->object=NULL;
    room5->n=NULL;  room5->e=room6; room5->s=NULL; room5->w=room4; room5->object=NULL;
    room6->n=NULL;  room6->e=NULL; room6->s=room12; room6->w=room5; room6->object=NULL;
    room7->n=room2; room7->e=room8; room7->s=room14; room7->w=NULL; room7->object=NULL;
    room8->n=NULL;  room8->e=room9; room8->s=NULL; room8->w=room7; room8->object=NULL;
    room9->n=room3; room9->e=room10; room9->s=room15; room9->w=room8; room9->object=NULL;
    room10->n=NULL; room10->e=room11; room10->s=NULL; room10->w=room9; room10->object=NULL;
    room11->n=room4; room11->e=NULL; room11->s=room16; room11->w=room10; room11->object=NULL;
    room12->n=room6; room12->e=NULL; room12->s=room18; room12->w=NULL; room12->object=NULL;
    room13->n=NULL;  room13->e=room14; room13->s=NULL; room13->w=NULL; room13->object=NULL;
    room14->n=room7; room14->e=NULL; room14->s=NULL; room14->w=room13; room14->object=NULL;
    room15->n=room9; room15->e=NULL; room15->s=NULL; room15->w=NULL; room15->object=NULL;
    room16->n=room11; room16->e=room17; room16->s=NULL; room16->w=NULL; room16->object=NULL;
    room17->n=NULL;   room17->e=room18; room17->s=NULL; room17->w=room16; room17->object=NULL;
    room18->n=room12; room18->e=NULL; room18->s=NULL; room18->w=room17; room18->object=NULL;

    Room *house [3][6];

    vector <Room*> rooms;
    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);
    rooms.push_back(room4);
    rooms.push_back(room5);
    rooms.push_back(room6);
    rooms.push_back(room7);
    rooms.push_back(room8);
    rooms.push_back(room9);
    rooms.push_back(room10);
    rooms.push_back(room11);
    rooms.push_back(room12);
    rooms.push_back(room13);
    rooms.push_back(room14);
    rooms.push_back(room15);
    rooms.push_back(room16);
    rooms.push_back(room17);
    rooms.push_back(room18);


    for (int j=0; j<3; j++)                                 // wypelnianie tablicy wskaznikami do pomieszczen
    {
        for (int k=0; k<6; k++)
        {
                for (int i=0; i<18; i++)
                {
                    if (j==rooms[i]->x && k==rooms[i]->y)
                    {
                        house [j][k]=rooms[i];
                    }
                }
        }
    }

    for (int j=0; j<3; j++)                                         // wyswietlanie schematu pomieszczen
    {
        for (int k=0; k<6; k++)
        {
            if (k==0 && j==1 && house[j][k]->w==NULL) cout << "X";
            cout << "#";
            if (house[j][k]->e==NULL && k!=5) cout << "X";
        }
        cout << endl;
    }

    cout << endl;

    vector <Room*> v1;                                              // implementacja schematu przejscia przez pomieszczenia
    v1.push_back(house[0][0]);  v1.push_back(v1[0]->e);
    v1.push_back(v1[1]->s);     v1.push_back(v1[2]->s);
    v1.push_back(v1[3]->w);     v1.push_back(v1[4]->e);
    v1.push_back(v1[5]->n);     v1.push_back(v1[6]->e);
    v1.push_back(v1[7]->e);     v1.push_back(v1[8]->s);
    v1.push_back(v1[9]->n);     v1.push_back(v1[10]->n);
    v1.push_back(v1[11]->s);    v1.push_back(v1[12]->e);
    v1.push_back(v1[13]->e);    v1.push_back(v1[14]->n);
    v1.push_back(v1[15]->e);    v1.push_back(v1[16]->e);
    v1.push_back(v1[17]->w);    v1.push_back(v1[18]->w);
    v1.push_back(v1[19]->s);    v1.push_back(v1[20]->s);
    v1.push_back(v1[21]->e);    v1.push_back(v1[22]->e);

    Object* tv = new Object ("Telewizor", 7);
    Object* computer = new Object ("Komputer", 8);
    Object* glass = new Object ("Szklanka", 2);

    int temp;                                                      // kod do losowania pomieszczen dla przedmiotow
    temp=rand()%24;
    v1[temp]->object=tv;
    do
    {
        temp=rand()%24;
    }
    while (v1[temp]->checkObject());
    v1[temp]->object=computer;
    do
    {
        temp=rand()%24;
    }
    while (v1[temp]->checkObject());
    v1[temp]->object=glass;


    for (int i=0; i<24; i++)
    {
        if (v1[i]->checkObject()) cout << "W kroku numer " << i+1 << " znaleziono przedmiot: " << v1[i]->returnObject() << endl << endl ;
    }

    for (int j=0; j<3; j++)                                      // wyswietlanie schematu pomieszczen z pierwszymi literami przedmiotow
    {
        for (int k=0; k<6; k++)
        {
            if (k==0 && j==1 && house[j][k]->w==NULL) cout << "X";
            if (house[j][k]->checkObject()==0) cout << "#"; else cout << house[j][k]->object->name[0];
            if (house[j][k]->e==NULL && k!=5) cout << "X";
        }
        cout << endl;
    }

    delete room1, room2, room3, room4, room5, room6, room7, room8, room9, room10, room11, room12, room12, room13, room14, room15, room16,
           room17, room18, tv, computer, glass;

    return 0;
}
