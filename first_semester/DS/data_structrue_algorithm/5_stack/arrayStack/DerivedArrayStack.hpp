#include"stack.h"
#include"array_list.hpp"

template<class T>
class DerivedArrayStack :private arrayList<T>,public stack<T>
{
    public:
        DerivedArrayStack(int theCapacity=30):arrayList<T>(theCapacity){};   
        bool empty() const 
        {
            return arrayList<T>::empty();
        }
        int size()const
        {
            return arrayList<T>::size();
        }
        T top()
        {
            if(arrayList<T>::empty())
                throw stackEmpty();
            return arrayList<T>::get(arrayList<T>::size()-1);
        }
        void pop()
        {
            if(arrayList<T>::empty())
                throw stackEmpty();
            arrayList<T>::erase(arrayList<T>::size()-1);
        }
        void push(const T& theElement)
        {
            arrayList<T>::push_back(theElement);
        }
};