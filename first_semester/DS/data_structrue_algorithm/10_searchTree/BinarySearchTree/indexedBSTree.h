#include"dictionary.h"
template <class K,class E>
class indexedBSTree:public Dictionary<K,E>
{
    public:
        virtual pair<const K,E>* get(int )const=0;
        virtual void delete (int) =0;
};