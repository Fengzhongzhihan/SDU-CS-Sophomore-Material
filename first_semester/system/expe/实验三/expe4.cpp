
int func4(int x)
{
    if(x<2)
        return 1;
    else 
        return func4(x-1)+func4(x-2);
}
//设学号最后一位为d

int x;
cin>>x;
if(x<=0)
    explode_bomb();
else 
{
    if(d&1)
    {
        if(func(x)==8)
            phase_5();
        else 
            explode_bomb();
    }
    else 
    {
        if(func(x)==13)
            phase_5();
        else 
            explode_bomb();
    }

}
