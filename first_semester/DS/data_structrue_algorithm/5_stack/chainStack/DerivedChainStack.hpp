#include"stack.h"
#include"extendedChain.hpp"
#include"myExceptions.h"

template<class T>
class DerivedChainStack :private extendedChain<T>,public stack<T>
{
    public:
        DerivedChainStack(int theCapacity=30):extendedChain<T>(theCapacity){};   
        bool empty() const 
        {
            return extendedChain<T>::empty();
        }
        int size()const
        {
            return extendedChain<T>::size();
        }
        T top()
        {
            if(extendedChain<T>::empty())
                throw stackEmpty();
            return extendedChain<T>::get(0);
        }
        void pop()
        {
            if(extendedChain<T>::empty())
                throw stackEmpty();
            extendedChain<T>::erase(0);
        }
        void push(const T& theElement)
        {
            extendedChain<T>::insert(0,theElement);
        }
};