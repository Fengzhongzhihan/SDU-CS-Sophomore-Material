#include"ori_expe4-1.hpp"
int n,q;
int main()
{
    cin>>n>>q;
    Chain<int>s;
    for(int i=0;i<n;i++)
        {
            int x;cin>>x;s.push_back(x);
        }
    while(q--)
    {
        int op;cin>>op;
        switch (op)
        {
            case 1:
            {
                int idx,val;cin>>idx>>val;
                s.insert(idx,val);
                break;
            }    
            case 2:
            {
                int val;cin>>val;
                if(!s.erase(val))cout<<-1<<endl;
                break;
            }
            case 3:
            {
                s.reverse();
                break;
            }
            case 4:
            {
                int val;cin>>val;
                int index=s.findIndex(val);
                if(index==-1)
                    cout<<-1<<endl;
                else cout<<index<<endl;
                break;
            }
            case 5:
            {
                s.outputXorSum();
                break; 
            }
            default:
                break;
        }
    }
    return 0;
}