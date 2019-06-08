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
    std::vector <std::vector<double> > vrows;
    std::vector <double> vcolumns;

    public:
    Matrix (){};
    Matrix (int x, int y);
    Matrix (std::string);
    void changeSingleCell (int x, int y, double newValue);
    std::string returnSingleCell (int x, int y);
    std::string returnSingleRow (int x);
    std::string returnSingleColumn (int y);
    std::string returnMatrix ();
    void transpose();
    Matrix *addNumber(double number);
    Matrix *addMatrix(Matrix*);
    Matrix *subtractMatrix(Matrix*);
    Matrix *multiplyMatrix (Matrix* A);
    void saveToFile(std::string);
};
