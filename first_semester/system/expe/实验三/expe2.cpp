int i=1;
//设输入的数字是a[0..5],输入学号为num[0..11]
for(int i=1;i<6;i++)
{
    if(a[i]!=a[i-1]*num[12-i])
    {
        explode_bomb();
        return;
    }
}
phase_3();