#include"chain.hpp"
#include<math.h>
struct StudentRecord
{
    int score;
    string name;
    int operator !=(const StudentRecord &x)const
    {
        return score!=x.score;
    }
    operator int ()const {return score;}
    void output(ostream &out);
};

void StudentRecord::output(ostream &out)
{
    out<<name<<" "<<score<<endl;
}

ostream& operator<<(ostream &out, StudentRecord&x)
{
    x.output(out);return out;
}

template<class T>
void binSort(Chain<T>& theChain,int range)
{
    //先初始化箱子,为一个数组,数组里面存的是链表
    Chain<T>* bin=new Chain<T>[range+1];
    
    //取出链表中所有学生信息
    int numberOfIndex=theChain.size();
    for(int i=0;i<numberOfIndex;i++)
    {
       T x=theChain.get(0);
       theChain.erase(0);
       bin[x.score].insert(0,x);
    }
    //从最后一个链表开始,取出信息在链表进行头插
    for(int j=range;j>=0;j--)
    {
        while(!bin[j].empty())
        {
            T x=bin[j].get(0);
            theChain.insert(0,x);
            bin[j].erase(0);
        }
    }
    delete []bin;
}

//基数排序
template<class T>
void radixSort(Chain<T>& theChain,int r,int k)
{
    //先初始化箱子,为一个数组,数组里面存的是链表
    Chain<T>* bin=new Chain<T>[r+1];
    
    //取出链表中所有数字信息
    int numberOfIndex=theChain.size();
    for(int i=0;i<numberOfIndex;i++)
    {
       int  x=theChain.get(0);
       theChain.erase(0);
       int num=(x%(int)(pow(r,k)))/(pow(r,k-1));
       bin[num].insert(0,x);
    }
    //从最后一个链表开始,取出信息在链表进行头插
    for(int j=r;j>=0;j--)
    {
        while(!bin[j].empty())
        {
            T x=bin[j].get(0);
            theChain.insert(0,x);
            bin[j].erase(0);
        }
    }
    delete []bin;
}

template<class T>
void Chain<T>::binSort(int range)
{
    chainNode<T>** bottom, ** top;
    bottom = new chainNode<T>*[range + 1];
    top = new chainNode<T>*[range + 1];

    for (int b = 0; b <= range; b++)
        bottom[b] = NULL;

    while (firstNode != NULL)
    {
        int score = (int)firstNode->element;
        if (bottom[score] == NULL)
            bottom[score] = firstNode;
        else
        {
            top[score]->next = firstNode;
            top[score] = firstNode;
        }
        firstNode = firstNode->next;
    }

    chainNode<T>* y = NULL;

    for (int score = 0; score <= range; score++)
    {
        if (bottom[score] != NULL)
        {
            if (y == NULL)
                firstNode = bottom[score];
            else
                y->next = bottom[score];
            y = top[score];
        }
    }

    if (y != NULL)
        y->next = NULL;
    
    delete[] bottom;
    delete[] top;
}

