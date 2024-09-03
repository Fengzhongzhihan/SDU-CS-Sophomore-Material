#include"dictionary.h"
template <class K,class E>
class indexedBSTree:public Dictionary<K,E>
{
    public:
        virtual int get(int )const=0;
        virtual int eraseWithIndex (int) =0;
};