#include<iostream>
using namespace std;
const int maxsize=1e5;
template <class T>
class LinearList
{
    public: 
    virtual ~LinearList(){};
    virtual bool empty()const =0;
    virtual int size()const =0;
    virtual T get(int theIndex)const =0;
    virtual int indexOf(const T& x)const =0;
    virtual void erase(int theIndex)=0;
    virtual void insert(int theIndex,const T &x)=0;
    virtual void output(ostream& out)const=0;
};
#include<algorithm>
#include<sstream>
#include<iterator>

template<class T>
class arrayList:public LinearList<T>
{
    public:
    arrayList(int initialCapacity);
    arrayList(const arrayList<T>&);
    arrayList()
    {
        element=new T [maxsize];
    }
    ~arrayList(){delete [] element;}

    //重写父类虚构函数
     virtual bool empty()const  {return listSize==0;}
     virtual int size()const {return listSize;}
     virtual T get(int theIndex)const;
     virtual int indexOf(const T&x)const;
     virtual void erase(int theIndex);
     virtual void insert(int theIndex,const T &x);
     virtual void output(ostream& out)const;

    //其他函数
    int capacity()const{return arrayLength;}
    void push_back(const T&x);
    void pop_back();
    void clear();
    void set(int theIndex ,T theElement);
    void reserve(const int& theCapacity);
    
    protected:
    void checkIndex(int theIndex)const;
    T* element;
    int arrayLength=0;
    int listSize=0;
};


template<class T>
void changeLength(T*& a,int oldLength,int newLength)
{
    if(newLength<0)return;
    T *temp=new T[newLength];
    int size=min(oldLength,newLength);
    copy(a,a+size,temp);
    a=temp;
}

//直接构造函数
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
    if(initialCapacity<1)return;
    arrayLength=initialCapacity;
    element=new T[arrayLength];
}

//拷贝函数
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
   arrayLength= theList.arrayLength;
   element=new T[arrayLength];
   listSize=theList.listSize;;
   copy(theList.element,theList.element+listSize,element);
}
//检查是否合法
template<class T>
void arrayList<T>::checkIndex(int theIndex)const
{
    if(theIndex<0||theIndex>=listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<"size="<<listSize;
        throw(s.str());
    }
}
//返回元素
template<class T>
T arrayList<T>::get(int theIndex)const
{
    checkIndex(theIndex);
    return element[theIndex];
}

//找索引
template<class T>
int arrayList<T>::indexOf(const T&x)const
{
    int theIndex=(int)(find(element,element+listSize,x)-element);
    if(theIndex==listSize)
    return -1;
    else return theIndex;
}

//根据索引删除一个元素
template<class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element+theIndex+1,element+listSize,element+theIndex);
    //释放最后一个元素的内存
    element[--listSize].~T();
}

//插入函数
template<class T>
void arrayList<T>::insert(int theIndex,const T&x)
{
    //检查是否为有效索引,可以写到末尾即listSize
    if(theIndex<0||theIndex>listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<"size="<<listSize;
        throw(s.str());
    }

    //满了则扩容
    if(listSize==arrayLength)
    {
        changeLength(element,listSize,listSize*2);
        arrayLength*=2;
    }
    //插入,往后移动
    copy_backward(element+theIndex,element+listSize,element+listSize+1);
    element[theIndex]=x;
    listSize++;
}

//输出
template<class T>
void arrayList<T>::output(ostream&out)const
{
    if(listSize==0)
    {
        cout<<"empty";return;
    }
    //在元素之间插入空格
    copy(element,element+listSize,ostream_iterator<T>(out," "));
}

//重载
template<class T>
ostream& operator<<(ostream&out,const arrayList<T>&arr)
{
    arr.output(out);return out;
}

//尾部插入一个元素
template<class T>
void arrayList<T>::push_back(const T&x)
{
    element[listSize++]=x;
}

//尾部删除一个元素
template<class T>
void arrayList<T>::pop_back()
{
    if(listSize<=0)
    {
        cout<<"already empty"<<endl;
        return;
    }
    else
     element[--listSize].~T();
}


//清空线性表
template<class T>
void arrayList<T>::clear()
{
    listSize=0;
    arrayLength=0;
}

template <class T>
inline void arrayList<T>::set(int theIndex, T theElement)
{
    element[theIndex]=theElement;
    listSize++;
}

template<class T>
void arrayList<T>::reserve(const int& theCapacity) 
{
    arrayLength = theCapacity;
    listSize=0;
}

template<class T>
class MatrixTerms
{
    public:
        int row;
        int col;
        T value;
    operator T()const {return value;}
};


template<class T>
class SparseMatrix
{   
    public:
        SparseMatrix<T>(){};
        SparseMatrix(int rows,int cols);
        SparseMatrix(const SparseMatrix<T>&);
        void transpose();
        void operator* (SparseMatrix<T>&b);
        void operator+ (SparseMatrix<T>&b);
        SparseMatrix<T>& operator= (SparseMatrix<T>&b);
        void reSetSize(int rows,int cols);
        void inputNonZero(int theNumberOfValues);
    public:
        int rows,cols;
        arrayList<MatrixTerms<T>> terms;
};

//重载输出
template <class T>
ostream& operator<<(ostream& out, SparseMatrix<T>& x)
{
    out<<x.rows<<" "<<x.cols<<endl;
    int k=0;
    for(int i=1;i<=x.rows;i++)
    {
        for(int j=1;j<=x.cols;j++)
        {
            bool flag=false;
            if(k<x.terms.size())
            {
                auto tmp=x.terms.get(k);
                if(tmp.row==i&&tmp.col==j)
                {
                    cout<<tmp.value<<" ";
                    flag=true;
                    k++;
                }
            }
            if(!flag)
                cout<<"0"<<" ";
        }
        cout<<endl;
    }
    return out;
}

//重载输入
template<class T>
istream& operator>>(istream& in, SparseMatrix<T>& x)
{
    MatrixTerms<T>mTerm;
    int b;
    //按行主列来存
    for(int i=1;i<=x.rows;i++)
        for(int j=1;j<=x.cols;j++)
        {
            in>>b;
            if(b!=0)
            {
                mTerm.row=i;
                mTerm.col=j;
                mTerm.value=b;
                x.terms.push_back(mTerm);
            }
        }
    return in;
}
//输入所有元素


//转置函数
template <class T>
inline void SparseMatrix<T>::transpose()
{
    //只有转置矩阵的时候需要进行位置的选择
    SparseMatrix<T>b;
    b.reSetSize(cols,rows);

    int colSize[cols+1];
    int nextRow[cols+1];

    for(int i=1;i<=cols;i++)
        colSize[i]=0;

    for(int i=0;i<terms.size();i++)
    {
        auto k=terms.get(i);
        colSize[k.col]++;
    }

    nextRow[1]=0;
    for(int i=2;i<=cols;i++)
        nextRow[i]=nextRow[i-1]+colSize[i-1];

    for(int i=0;i<terms.size();i++)
    {
        auto k=terms.get(i);
        MatrixTerms<T>mTerm;
        mTerm.row=k.col;
        mTerm.col=k.row;
        mTerm.value=k.value;
        
        int index=nextRow[k.col]++;
        b.terms.set(index,mTerm);
    }

    *this=b;
};

template <class T>
void SparseMatrix<T>::operator+(SparseMatrix<T> &b)
{
    if(rows!=b.rows||cols!=b.cols)
    {
        cout<<"-1"<<endl;
        *this=b;
        return;
    }
    SparseMatrix<T>c;
    c.reSetSize(rows,cols);
    int i=0,j=0;
    int n=terms.size();
    int m=b.terms.size();
    while(i<n&&j<m)
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
            MatrixTerms<T>mTerm;
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
    while(i<n)
    {
        c.terms.push_back(terms.get(i));
        i++;
    }
    while(j<m)
    {
        c.terms.push_back(b.terms.get(j));
        j++;
    }
    
    *this=c;
}

template <class T>
inline void SparseMatrix<T>::operator*(SparseMatrix<T> &b)
{
    if(cols!=b.rows)
    {
        cout<<"-1"<<endl;
        *this=b;
        return;
    }

    //结果矩阵
    SparseMatrix<T>c;
    c.reSetSize(rows,b.cols);

    //思路:按左矩阵的每一行列举,找到相同行的非零元素,找到对应列,再通过找到右矩阵相同行上的元素进行累加即可
    T rowSize[b.rows+1];
    T nextRow[b.rows+1];
    T answerRow[b.cols+1];

    for(int i=1;i<=b.rows;i++)
        rowSize[i]=0;

    for(int i=0;i<b.terms.size();i++)
    {
        auto k=b.terms.get(i);
        rowSize[k.row]++;
    }

    nextRow[1]=0;
    for(int i=2;i<=b.rows;i++)
        nextRow[i]=nextRow[i-1]+rowSize[i-1];

    int p=0;
    for(int i=1;p<terms.size()&&i<=rows;i++)
    {
        for(int k=1;k<=b.cols;k++)
            answerRow[k]=0;
        //左侧矩阵有该行元素,而且该元素右侧列有元素
        while(p<terms.size()&&terms.get(p).row==i)
        {
            if(rowSize[terms.get(p).col]!=0)
            {
                auto k=terms.get(p);
                for(int q=nextRow[k.col];q<nextRow[k.col]+rowSize[k.col];q++)
                {
                    auto tmp=b.terms.get(q);
                    answerRow[tmp.col]+=k.value*tmp.value;
                }
            }
            p++;
        }
        //将answer输入
        for(int j=1;j<=b.cols;j++)
        {
            if (answerRow[j]!=0)
            {
                MatrixTerms<T> mTerm;
                mTerm.col=j;
                mTerm.row=i;
                mTerm.value=answerRow[j];
                c.terms.push_back(mTerm);
            }
        }     
    }
    //把c赋给原矩阵
    *this=c;
}

template<class T>
SparseMatrix<T>&  SparseMatrix<T>::operator=(SparseMatrix<T>&x)
{
    reSetSize(x.rows,x.cols);
    for(int i=0;i<x.terms.size();i++)
    {
        auto k=x.terms.get(i);
        terms.push_back(k);
    }
    return *this;
}

template <class T>
inline SparseMatrix<T>::SparseMatrix(int rows,int cols)
{
    this->rows=rows;
    this->cols=cols;
}

template <class T>
inline SparseMatrix<T>::SparseMatrix(const SparseMatrix<T> &x)
{
    *this->reSetSize(x.rows,x.cols);
    for(int i=0;i<x.terms.size();i++)
    {
        auto k=x.terms.get(i);
        terms.push_back(k);
    }
}

template <class T>
inline void SparseMatrix<T>::reSetSize(int rows, int cols)
{
    this->rows=rows;
    this->cols=cols;
    terms.reserve(maxsize);
}

template <class T>
inline void SparseMatrix<T>::inputNonZero(int theNumberOfValues)
{
    MatrixTerms<T>mTerm;
    for(int i=0;i<theNumberOfValues;i++)
    {
        scanf("%d%d%d",&mTerm.row,&mTerm.col,&mTerm.value);
        terms.push_back(mTerm);
    }
}

int main()
{   SparseMatrix<int>s;
    int w,op;
    scanf("%d",&w);
    while(w--)
    {
        scanf("%d",&op);
        switch (op)
        {
            case 1:
            {
                int n,m;
                scanf("%d%d",&n,&m);
                s.reSetSize(n,m);
                cin>>s;
                break;
            }
            case 2:
            {
                int n,m,t;
                scanf("%d%d%d",&n,&m,&t);
                //初始化右矩阵
                SparseMatrix<int>tmp;
                tmp.reSetSize(n,m);
                tmp.inputNonZero(t);
                s*tmp;
                break;
            }
            case 3:
            {
                int n,m,t;
                scanf("%d%d%d",&n,&m,&t);
                //初始化右矩阵
                SparseMatrix<int>tmp;
                tmp.reSetSize(n,m);
                tmp.inputNonZero(t);
                s+tmp;
                break;
            }
            case 4:
            {
                cout<<s;
                break;
            }
            case 5:
            {
                s.transpose();
                break;
            }
            default:
                break;
        }
    }
    return 0;
}