#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
struct Info
{
    string name;
    string teleNumber;
    string classNumber;
    ll domitoryNumber;
};

class AddressBook
{
public:
AddressBook(int theCapacity);
~AddressBook(){delete []Infos;}
void push_back();
void erase(int theIndex);
int  findIndexWithName(string name);
void outputClass(string classNumber);
void editMember();
private:
    int arrayLength;
    int listSize=0;
    Info* Infos;
};

AddressBook::AddressBook(int theCapacity)
{
    arrayLength=theCapacity;
    Infos=new Info[arrayLength];
}

void AddressBook::push_back()
{
    string name,teleNumber,classNumber; 
    ll domitoryNumber;
    cin>>name>>teleNumber>>classNumber>>domitoryNumber;
    Info theInfo={name,teleNumber,classNumber,domitoryNumber};
    Infos[listSize++]=theInfo;
}

void AddressBook::erase(int theIndex)
{
    copy(Infos+theIndex+1,Infos+listSize,Infos+theIndex);
    listSize--;
}

//用姓名查找
int  AddressBook::findIndexWithName(string name)
{
    for(int i=0;i<listSize;i++)
    {
        auto theInfo=Infos[i];
        if (theInfo.name==name)
        return i;
    }
    return -1;
}

void AddressBook::outputClass(string classNumber)
{
    ll tmp[arrayLength];
    int index=0;
    for(int i=0;i<listSize;i++)
    {
        auto theInfo=Infos[i];
        if(theInfo.classNumber==classNumber)
        tmp[index++]=theInfo.domitoryNumber;
    }
    int value=0;
    for(int i=0;i<index;i++)
    value^=tmp[i];
    cout<<value<<endl;
}

void AddressBook::editMember()
{
    string name;
    int num;
    cin>>name>>num;
    if(num==1)
    {
        string teleNumber;
        cin>>teleNumber;
        Infos[findIndexWithName(name)].teleNumber=teleNumber;
    }
    else if(num==2)
    {
        string classNumber;
        cin>>classNumber;
        Infos[findIndexWithName(name)].classNumber=classNumber;
    }
    else
    {
        ll domitoryNumber;
        cin>>domitoryNumber;
        Infos[findIndexWithName(name)].domitoryNumber=domitoryNumber;
    }
}
int main()
{
    cin>>n;
    AddressBook s(n);
    int op;
    while(n--)
    {
        cin>>op;
        switch (op)
        {
            case 0:
            {
                s.push_back();
                break;
            }
            case 1:
            {
                string name;
                cin>>name;
                s.erase(s.findIndexWithName(name));
                break;
            }
            case 2:
            {
                s.editMember();
                break;
            }
            case 3:
            {
                string name;
                cin>>name;
                int theIndex=s.findIndexWithName(name);
                if(theIndex==-1)cout<<0<<endl;
                else cout<<1<<endl;
                break;
            }
            default:
            {
                string classNumber;
                cin>>classNumber;
                s.outputClass(classNumber);
                break;
            }

        }
    }
    return 0;
}