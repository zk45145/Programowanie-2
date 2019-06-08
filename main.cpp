#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <istream>
#include <fstream>
#include <stdexcept>
#include "macierze.hpp"

int main()
{
    Matrix *A=new Matrix("A.txt");
    Matrix *B=new Matrix("B.txt");
    Matrix *C=new Matrix;
    C=A->multiplyMatrix(B);

    std::cout << "Wyswietlenie macierzy A:" << std::endl << std::endl;
    for (int i=0; i<A->vrows.size(); i++)
    {
        std::cout << "    " << A->returnSingleRow(i) << std::endl << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Wyswietlenie macierzy B i C obok siebie:" << std::endl << std::endl;
    for (int i=0; i<C->vrows.size(); i++)
    {
        if (i<B->vrows.size())
        {
            std::cout << B->returnSingleRow(i);
            std::cout << "       ";
        }
        if (i==B->vrows.size()) std::cout << "                                   ";
        std::cout << C->returnSingleRow(i) << std::endl << std::endl;
    }
    std::cout << "Proba zapisu macierzy C do pliku C.txt:" << std::endl;
    C->saveToFile("C.txt");

    std::cout << "Proba wykonania mnozenia macierzy A*C:" << std::endl;
    try
    {
        A->multiplyMatrix(C);
    }

    catch (std::exception& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl << std::endl;
    }

    Matrix *D=new Matrix ("C.txt");
    std::cout << D->returnMatrix();
    D=D->addNumber(5);

    Matrix *E=new Matrix ();
    E=C->addMatrix(D);

    Matrix *F=new Matrix ();
    F=C->addMatrix(D);

    Matrix *G=new Matrix ();
    G=E->subtractMatrix(F);

    std::cout << "Wyswietlenie macierzy C, D i E obok siebie:" << std::endl << std::endl;
    for (int i=0; i<C->vrows.size(); i++)
    {
        std::cout << C->returnSingleRow(i);
        std::cout << "       ";
        std::cout << D->returnSingleRow(i);
        std::cout << "       ";
        std::cout << E->returnSingleRow(i);
        std::cout << std::endl << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Macierze F oraz G:" << std::endl << std::endl;
    std::cout << F->returnMatrix();
    std::cout << G->returnMatrix();


    std::cout << "Proba dodania A+B: " << std::endl << std::endl;
    try
    {
        A->addMatrix(B);
    }

    catch (std::exception& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }


    delete A; delete B; delete C;  delete E; delete F; delete G;
    return 0;
}
