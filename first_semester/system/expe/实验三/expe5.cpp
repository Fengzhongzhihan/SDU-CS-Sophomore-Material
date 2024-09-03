string s;
string ans="giants";
string temp="isrveawhobpnutfg"
char str[6];
cin>>s;
if(strlen(s)!=6)
    explode_bomb();
else
{
    for(int i=0;i<6;i++)
    {
        char c=s[i];
        int index=c&15;
        str[i]=temp[index];
    }
    if(str==ans)
        phase_6()
    else 
        explode_bomb();
}