    //
    // Created by Lenovo on 2024-03-19.
    //
    #include <iostream>
    #include <vector>
    #include<algorithm>
    #include <string>
    #include <list>
    #include <queue>
    using namespace std;

    struct noodle{
        int t=0;
        int content[4]= {0,0,0,0};
        friend bool operator < (noodle a, noodle b){
            return a.t>b.t;
        }
    };
    struct guest{
        int s;
        vector<int>like;
        friend bool operator <(guest a, guest b){
            return a.s<b.s;
        }
    };
    list<noodle> noodles;
    list<guest> guests;
    int main(){
        int n, m, k;
        scanf("%d %d %d",&n,&m,&k);
        //cin>>n>>m>>k;

        vector<int> times;
        for(int i=0; i<n; i++){
            int t;
            scanf("%d", &t);
            //cin>>t;
            times.push_back(t);
        }

        //read n kind of noodle made in different time
        for(int i=0; i<n; i++){
            int typenum;
            scanf("%d", &typenum);
            //cin>>typenum;

            noodle temp;
            temp.t = times[i];

            //read n kind of contents
            while(typenum--){
                int index;
                scanf("%d", &index);
                //cin>>index;
                temp.content[index]=1;
            }

            noodles.push_front(temp);
        }

        vector<int> s;
        for(int i=0; i<m; i++){
            int temp;
            cin>>temp;
            s.push_back(temp);
        }

        //read m likeness
        for(int i=0; i<m; i++){
            int c;
            scanf("%d",&c);
            //cin>>c;
            guest temp;
            temp.s = s[i];
            //read the likeness of the m th costomer
            while(c--){
                int temp2;
                scanf("%d",&temp2);
                //cin>>temp2;
                temp.like.push_back(temp2);
            }

            guests.push_back(temp);
        }

        //process______________________________

        while(!guests.empty()){
            list<guest>::iterator it = guests.begin();
            int isfound = 0;

            for(auto i = noodles.begin(); i!=noodles.end(); i++){
                //check the like
                int valid = 1;

                for(auto ii:it->like){
                    if(i->content[ii]!=1){
                        valid = 0;
                        break;
                    }
                }
                if(!valid){
                    //no this noodle!
                    continue;
                }
                else{
                    printf("%d\n",it->s-i->t);
                    //cout<<it->s-i->t<<endl;
                    noodles.erase(i);
                    isfound = 1;
                    break;
                }
            }
            if(!isfound)
                printf("Angry\n");
            //cout<<"Angry"<<endl;
            guests.erase(it);
        }


        //cout<<"********************"<<endl;
    }

