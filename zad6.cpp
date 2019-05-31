#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <istream>
#include <fstream>

template<typename T>
std::string to_string(const T& obj)
{
    std::stringstream ss;
    ss << obj;
    return ss.str();
}

class Matrix
{
    private:
    int i, j;
    float **values;

    public:
    Matrix (int x, int y);
    Matrix (std::string);
    changeSingleCell (int x, int y, double newValue);
    std::string returnSingleCell (int x, int y);
    std::string returnSingleRow (int y);
    std::string returnSingleColumn (int x);
    std::string returnMatrix ();
    addNumber(int number);
    transpose();
    saveToFile(std::string);
};

Matrix :: Matrix (int x, int y)
{
    i=x;
    j=y;
    values=new float*[i];
    for (int a=0; a<i; a++)
    {
        values[a]=new float[j];
    }
    for (int a=0; a<i; a++)
    {
        for (int b=0; b<j; b++)
        {
            values[a][b]=0;
        }
    }
}

Matrix :: changeSingleCell (int x, int y, double newValue)
{
    values[x][y]=newValue;
}

std::string Matrix :: returnSingleCell (int x, int y)
{
    std::string cell_string = to_string(values[x][y]);
    return cell_string;
}

std::string Matrix :: returnSingleRow (int x)
{
    std::string line="";
    for (int a=0; a<j; a++)
    {
        line+=returnSingleCell(x, a);
        line+="    ";
    }
    return line;
}

std::string Matrix :: returnSingleColumn (int y)
{
    std::string column="";
    for (int a=0; a<i; a++)
    {
        column+=returnSingleCell(a, y);
        column+='\n';
        column+='\n';
    }
    return column;
}

std::string Matrix :: returnMatrix()
{
    std::string matrix;
    for (int a=0; a<i; a++)
    {
        matrix+=returnSingleRow(a);
        matrix+='\n';
        matrix+='\n';
    }
    return matrix;
}

Matrix :: addNumber(int number)
{
    for (int a=0; a<i; a++)
    {
        for (int b=0; b<j; b++)
        {
            values [a][b]+=number;
        }
    }
}

Matrix :: transpose()
{
    Matrix *temp=new Matrix(j,i);
    for (int a=0; a<j; a++)
    {
        for (int b=0; b<i; b++)
        {
            temp->values[a][b]=values[b][a];
        }
    }
    i=temp->i;
    j=temp->j;
    values=temp->values;
    delete temp;
}

Matrix :: Matrix(std::string file_name)
{
    std::ifstream file;
    std::string line;
    int rows=0;

    file.open(file_name.c_str(), std::ios::in);                     // zliczenie wierszy z pliku
    if(!file)
    {
        std::cout << "Blad odczytu pliku! " << std::endl;
    }
    else
    {
        while (!file.eof())
        {
            getline(file,line);
            rows++;
        }
    }
    file.close();

    std::vector <float> v1;     // wektor przechowujacy l. rzeczywiste z jednego wiersza
    std::string temp="";
    float value;
    float **temp_values;
    temp_values=new float*[rows];
    int help=0;                             // zmienna pomocnicza

    file.open(file_name.c_str(), std::ios::in);
        if(!file)
        {
            std::cout << "Blad odczytu pliku! " << std::endl;
        }
        else
        {
            while (!file.eof())
            {
                getline(file,line);
                for (int m=0; line[m]!=';'; m++)
                {
                    if (line[m]!=' ') temp+=line[m];
                    else
                    {
                        std::istringstream iss(temp);
                        iss >> value;
                        v1.push_back(value);
                        temp="";
                    }
                }

                i=rows;

                if (help==0)
                {
                    j=v1.size();
                    for (int a=0; a<i; a++)
                    {
                        temp_values[a]=new float[j];
                    }
                }
                for (int a=0; a<j; a++)
                {
                    temp_values[help][a]=v1[a];
                }
                v1.clear();
                help++;

            }
        }
    file.close();

    values=new float*[i];
    for (int a=0; a<i; a++)
    {
        values[a]=new float[j];
    }

    for (int a=0; a<i; a++)
    {
        for (int b=0; b<j; b++)
        {
            values[a][b]=temp_values[a][b];
        }
    }
    delete temp_values;
}

Matrix :: saveToFile (std::string save_to_file)
{
    std::ofstream file1 (save_to_file.c_str());

    for (int a=0; a<i; a++)
    {
        for (int b=0; b<j; b++)
        {
            file1 << values[a][b];
            if (b<j-1) file1 << " ";
        }
        file1 << " ;"; if (a<i-1) file1 << std::endl;
    }
    std::cout << "Zapis wykonany. " << std::endl;
}

int main()
{
    Matrix *matrix1=new Matrix ("demo.txt");
    std::string name;

    matrix1->changeSingleCell(0,0,10);
    matrix1->changeSingleCell(1,1,10);
    matrix1->changeSingleCell(2,2,10);

    time_t t = time(0);
    struct tm *now=localtime(&t);
    std::string time;
    std::ostringstream ss;
    ss << now->tm_hour << now->tm_min << now->tm_sec;
    time=ss.str();
    std::string save_to_file="macierz1_";
    save_to_file+=time+".txt";

    matrix1->saveToFile(save_to_file);

    Matrix *matrix2=new Matrix (save_to_file);

    matrix2->transpose();

    save_to_file="macierz2_";
    save_to_file+=time+".txt";
    matrix2->saveToFile(save_to_file);

    Matrix *matrix3=new Matrix (save_to_file);

    matrix3->addNumber(50);

    save_to_file="macierz3_";
    save_to_file+=time+".txt";
    matrix3->saveToFile(save_to_file);



    return 0;
}
