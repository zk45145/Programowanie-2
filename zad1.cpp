#include <iostream>
#include <string>

using namespace std;

string ConvertFromSymbolic(string x)
{
	int length=x.length();

	for (int loop=0; loop<length; loop++)                                                            // wymazywanie ewentualnych spacji
    {
        if (x[loop]==' ') x.erase(loop,1);
    }

    for (int i=0; i<x.length()-2; i++)                                                              // sprawdzanie czy na poczatku zapisu nie ma liter
    {
        if (x[i]>65 && x[i]<122)
        {
            x="Blad zapisu!";
            return x;
        }
    }

    length=x.length();
    char lastChar=x[length-1];

	if (lastChar==77 || lastChar==66 || lastChar==84 || lastChar==97 || lastChar==105 || lastChar==120 || lastChar==112 || lastChar==99)  //
    {                                                                                                       // ^ sprawdzenie poprawnoœci zapisu formatu
        int i=0;
        int j=0;

        while (x[i]!='.')
        {
            i++;
            if (i==length-1)                                                                           // jeœli nie znaleziono w liczbie kropki
            {
                x[i]=' ';
                if (lastChar==77) return x+"000 000";
                if (lastChar==66) return x+"000 000 000";
                if (lastChar==84) return x+"000 000 000 000";
                if (lastChar==97) {x.erase(i-1,1); return x+"000 000 000 000 000";}
                if (lastChar==105) {x.erase(i-1,1); return x+"000 000 000 000 000 000";}
                if (lastChar==120) {x.erase(i-1,1); return x+"000 000 000 000 000 000 000";}
                if (lastChar==112) {x.erase(i-1,1); return x+"000 000 000 000 000 000 000 000";}
                if (lastChar==99) {x.erase(i-1,1); return x+"000 000 000 000 000 000 000 000 000";}

            }
        }
            x[i]=' ';
            while (x[i+1]!=lastChar)
            {
                    j++;
                    i++;
            }

            if (lastChar==97 || lastChar==105 || lastChar==120 || lastChar==112 || lastChar==99) x.erase(i,2);
            else x.erase (i+1, 1);                     // czy liczba to od Qa w górê (sprawdzamy czy ASCII odpowiada ma³ym literom a,i,x,p,c)?
                                                       // jeœli tak, wymazujemy dwa ostatnie znaki (np. Qa), jeœli nie wymazujemy ostatni znak (np. M)
            length=x.length();

            int dependsOnLastChar;
            if (lastChar==77) dependsOnLastChar=6;      // sprawadzamy ile pêtli potrzebujemy by dopisaæ brakuj¹ce znaki
            if (lastChar==66) dependsOnLastChar=9;
            if (lastChar==84) dependsOnLastChar=12;
            if (lastChar==97) dependsOnLastChar=16;
            if (lastChar==105) dependsOnLastChar=19;
            if (lastChar==120) dependsOnLastChar=22;
            if (lastChar==112) dependsOnLastChar=25;
            if (lastChar==99) dependsOnLastChar=28;

            for (j; j<dependsOnLastChar; j++)            // dopisywanie zer
            {
                x=x+'0';
            }
            int three_chars_counter=3;
            for (int temp=(x.length()); temp>3; temp--)                 // wstawianie spacji w zapisie, co trzy znaki od koñca
            {
                if  (three_chars_counter%3==0 && three_chars_counter!=3) x.insert(temp," ");
                three_chars_counter++;
            }

            return x;
    }

    else
    {
            x="Blad zapisu!";
            return x;
    }

}

int main()
{
	std :: cout << ConvertFromSymbolic ("4M") << std :: endl ;
	std :: cout << ConvertFromSymbolic ("54T") << std :: endl ;
	std :: cout << ConvertFromSymbolic ("5.434 B") << std :: endl ;

	return 0;
}
