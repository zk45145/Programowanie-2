#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <istream>
#include <fstream>
#include <stdexcept>
#include "macierze.h"

Matrix :: Matrix (int x, int y)
{
    i=x;
    j=y;

    for (int a=0; a<i; a++)
    {
        for (int b=0; b<j; b++)
        {
            vcolumns.push_back(0);
        }
        vrows.push_back(vcolumns);
        vcolumns.clear();
    }
}

void Matrix :: changeSingleCell (int x, int y, double newValue)
{
    vrows[x][y]=newValue;
}

std::string Matrix :: returnSingleCell (int x, int y)
{
    std::string cell_string = to_string(vrows[x][y]);
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
    matrix+='\n';
    return matrix;
}

void Matrix :: transpose()
{
    Matrix *temp=new Matrix(j,i);
    for (int a=0; a<j; a++)
    {
        for (int b=0; b<i; b++)
        {
            temp->vrows[a][b]=vrows[b][a];
        }
    }
    i=temp->i;
    j=temp->j;
    vrows=temp->vrows;
    delete temp;
}

Matrix *Matrix :: addNumber(double number)
{
    Matrix *Result=new Matrix(i,j);
    Result->vrows=vrows;
    for (int a=0; a<i; a++)
    {
        for (int b=0; b<j; b++)
        {
            Result->vrows [a][b]+=number;
        }
    }
    return Result;
}

Matrix :: Matrix(std::string file_name)
{
    std::ifstream file;
    std::string line;

    std::string temp="";
    double value;
    std::vector<std::vector<double> > temp_vrows;
    std::vector<double> temp_vcolumns;

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
                        vcolumns.push_back(value);
                        temp="";
                    }
                }
                vrows.push_back(vcolumns);
                vcolumns.clear();

            }
        }
    file.close();
    i=vrows.size();
    j=vrows[0].size();
}

void Matrix :: saveToFile (std::string save_to_file)
{
    std::ofstream file1 (save_to_file.c_str());

    for (int a=0; a<i; a++)
    {
        for (int b=0; b<j; b++)
        {
            file1 << vrows[a][b];
            if (b<j-1) file1 << " ";
        }
        file1 << " ;"; if (a<i-1) file1 << std::endl;
    }
    std::cout << "Zapis wykonany. " << std::endl << std::endl;
}

Matrix *Matrix :: addMatrix (Matrix *A)
{
    if (i!=A->i || j!=A->j) throw std::invalid_argument ("Niezgodne wymiary macierzy - nie mozna wykonac dodawania ");
    Matrix *Result=new Matrix(i,j);
    for (int a=0; a<i; a++)
    {
        for (int b=0; b<j; b++)
        {
            Result->vrows[a][b]=vrows[a][b]+A->vrows[a][b];
        }
    }
    return Result;
}

Matrix *Matrix :: subtractMatrix(Matrix* A)
{
    if (i!=A->i || j!=A->j) throw std::invalid_argument ("Niezgodne wymiary macierzy - nie mozna wykonac odejmowania ");
    Matrix *Result=new Matrix(i,j);
    for (int a=0; a<i; a++)
    {
        for (int b=0; b<j; b++)
        {
            Result->vrows[a][b]=vrows[a][b]-A->vrows[a][b];
        }
    }
    return Result;
}

Matrix *Matrix :: multiplyMatrix (Matrix* A)
{
    if (j!=A->i) throw std::invalid_argument ("Niezgodne wymiary macierzy - nie mozna wykonac mnozenia ");
    double s;
    Matrix *Result=new Matrix(i,A->j);
    for (int a=0; a<i; a++)
    {
        for (int b=0; b<A->j; b++)
        {
            s=0;
            for (int c=0; c<j; c++)
            {
                s+=vrows[a][c]*A->vrows[c][b];
            }
            Result->vrows[a][b]=s;
        }
    }
    return Result;
}

