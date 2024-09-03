#include"dictionary.h"
template <class K,class E>
class indexedBSTree:public Dictionary<K,E>
{
    public:
        virtual pair< K,E>* get(int )const=0;
        virtual void eraseWithIndex (int) =0;
};