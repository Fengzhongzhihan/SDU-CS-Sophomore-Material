string s;
cin>>s;
int d;//学号的最后一位
if(strlen(s)<3)
    explode_bomb()
else 
{
    int a=s[0];
    char b=s[1];
    int c=s[2];
    switch (a)
    {
        case 0:
        {
            if(d*c!=777||b!=113)
                explode_bomb();
            else
                phase_4();
        }
        case 1:
        {
            if(d*c!=214||b!=98)
                explode_bomb();
            else
                phase_4();

        }
        case 2:
        {
            if(d*c!=755||b!=98)
                explode_bomb();
            else
                phase_4();
        }
        case 3:
        {
            if(d*c!=0||b!=107)
                explode_bomb();
            else
                phase_4();
        }
        case 4:
        {
            if(d*c!=228||b!=111)
                explode_bomb();
            else
                phase_4();
        }
        case 5:
        {
            if(d*c!=513||b!=116)
                explode_bomb();
            else
                phase_4();
        }
        case 6:
        {
            if(d*c!=780||b!=118)
                explode_bomb();
            else
                phase_4();
        }
        case 7:
        {
            if(d*c!=824||b!=98)
                explode_bomb();
            else
                phase_4();
        }
        default
        {
            explode_bomb();
        }
    }
}