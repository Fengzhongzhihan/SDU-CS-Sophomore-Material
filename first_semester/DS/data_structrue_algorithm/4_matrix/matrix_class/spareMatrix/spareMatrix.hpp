#include"array_list.hpp"
#include"matrixTerm.h"

template<class T>
class SparseMatrix
{   
    public:
        SparseMatrix<T>(){};
        SparseMatrix(int rows,int cols,int theNumberOfValues);
        void transpose(SparseMatrix<T>&b);
        void add(SparseMatrix<T>&b,SparseMatrix<T>&c);
        T get(int theRow,int theColumn);
        void set(int theRow,int theColumn,int theValue);
        void reSetSize(int rows,int cols,int theNumberOfValues);
    public:
        int rows,cols;
        arrayList<MatrixTerm<T>> terms;
};

//重载输出
template <class T>
ostream& operator<<(ostream& out, SparseMatrix<T>& x)
{
    out<<"rows="<<x.rows<<" "<<"columns="<<x.cols<<endl;
    out<<"nonZeroTerms="<<x.terms.size()<<endl;
    
    for(int i=0;i<x.terms.size();i++)
    {
        auto k=x.terms.get(i);
        out<<"a( "<<k.row<<", "<<k.col<<" )="<<k.value<<endl;
    }

    return out;
}

//重载输入
template<class T>
istream& operator>>(istream& in, SparseMatrix<T>& x)
{
    int numberOfTerms;
    cout<<"enter rowsNumber,colsNumber,nonvalueNumber"<<endl;
    in>>x.rows>>x.cols>>numberOfTerms;

    x.terms.reSet(numberOfTerms);

    MatrixTerm<T>mTerm;
    cout<<"enter row,col,nonvalue"<<endl;
    for(int i=0;i<numberOfTerms;i++)
    {
        cout<<(i+1)<<endl;
        in>>mTerm.row>>mTerm.col>>mTerm.value;
        x.terms.set(i,mTerm);
    }
    return in;
}
//转置函数
template <class T>
inline void SparseMatrix<T>::transpose(SparseMatrix<T> &b)
{
    b.cols=rows;
    b.rows=cols;
    b.terms.reSet(terms.size());

    //记录每一列的非零元素个数
    int* colSize=new int[cols+1];
    //记录转置后每一行首个非零元素在b中的索引
    int* rowNext=new int[cols+1];

    //初始化colSize
    for(int i=1;i<=cols;i++)
        colSize[i]=0;
    for(int i=0;i<terms.size();i++)
    {
        auto k=terms.get(i);
        colSize[k.col]++;
    }
    //初始化rowNext
    rowNext[1]=0;
    for(int i=1;i<=cols-1;i++)
        rowNext[i+1]=rowNext[i]+colSize[i];

    //在写出最终的矩阵
    MatrixTerm<T>mTerm;
    for(int i=0;i<terms.size();i++)
    {
        int j = rowNext[terms.get(i).col]++;
        auto k=terms.get(i);
        mTerm.row=k.col;
        mTerm.col=k.row;
        mTerm.value=k.value;
        b.terms.set(j, mTerm);
    }
}

//加法函数
template <class T>
inline void SparseMatrix<T>::add(SparseMatrix<T> &b, SparseMatrix<T> &c)
{
    if(rows!=b.rows||cols!=b.cols)
        throw ("dismatch");

    c.rows=rows;
    c.cols=cols;
    c.terms.clear();

    int i=0,j=0;
    while(i<terms.size()&&j<b.terms.size())
    {
        auto k1=terms.get(i);
        auto k2=b.terms.get(j);
        
        int idx1=k1.row*cols+k1.col;
        int idx2=k2.row*cols+k2.col;

        if(idx1<idx2)
        {
            c.terms.push_back(k1);
            i++;
        }
        else if(idx1==idx2)
        {
            MatrixTerm<T>mTerm;
            mTerm.row=k1.row;
            mTerm.col=k1.col;
            mTerm.value=k1.value+k2.value;
            c.terms.push_back(mTerm);
            i++,j++;
        }
        else
        {
            c.terms.push_back(k2);
            j++;
        }
    }
    //补充剩下的
    while(i<terms.size())
    {
        c.terms.push_back(terms.get(i));
        i++;
    }
    while(j<b.terms.size())
    {
        c.terms.push_back(b.terms.get(j));
        j++;
    }
}

template <class T>
inline T SparseMatrix<T>::get(int theRow, int theColumn)
{
    for(int i=0;i<terms.size();i++)
    {
        auto k = terms.get(i);
        if (k.row == theRow && k.col == theColumn)
            return k.value;
    }
    throw("no element");
}

template<class T>
inline void SparseMatrix<T>::set(int theRow, int theColumn, int theValue)
{
    if (theRow < 1 || theRow > rows || theCol < 1 || theCol > cols)
        throw matrixIndexOutOfBounds();
    int num = terms.size();
    int index; //插入的新三元组在terms 中的下标
        for (int i = 0; i < num; )
        {
            if (terms[i].row > theRow) //目标位置在当前位置和上一个位置之间
            {
            index = i;
            break;
            }
            if (terms[i].row < theRow) //还未查询至第theRow 行
            i++;
            else //查询到第theRow 行
            {
            while(1)
            {
            if (terms[i].col > theCol) //目标位置在当前位置和上一个位置之间
            {
            index = i;
            break;
            }
            if (terms[i].col < theCol) //还未查询至第theCol 列
            i++;
            else //目标位置已有非零元素，无需移动后续元素
            {
            terms[i].value = theValue;
            return;
            }
            }
            break;
            }
        }

        terms.reSet(num + 1); //更改terms 的大小
        for (int i = num; i > index; i--) //将下标为index～num-1 的元素向后移动
            set(i, terms[i - 1]);
            set(index, matrixTerm<T>(theRow, theCol, theValue));
}

template <class T>
inline SparseMatrix<T>::SparseMatrix(int rows,int cols,int theNumberOfValues)
{
    this->rows=rows;
    this->cols=cols;
    this->terms.reserve(theNumberOfValues);
}

template <class T>
inline void SparseMatrix<T>::reSetSize(int rows, int cols, int theNumberOfValues)
{
    this->rows=rows;
    this->cols=cols;
    this->terms.reserve(theNumberOfValues);
}
