#include"dictionary.h"
template <class K,class E>
class BSTree:public Dictionary<K,E>
{
    public:
        virtual void ascend()=0;
};