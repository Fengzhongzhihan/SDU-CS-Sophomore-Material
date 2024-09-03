template<class T>
class MatrixTerm
{
    public:
        int row;
        int col;
        T value;

    operator T()const {return value;}
};
