#include"linkedBinaryTree.hpp"
struct lr
{
    int left,right;
};

int n;
int main()
{
    cin>>n;
    LinkedBinaryTree<int>tree[n+1];
    LinkedBinaryTree<int> a;
    int height[n+1];
    int size[n+1];
    struct lr st[n+1];

    //先存下left和right
    for(int i=1;i<=n;i++)
    {
        int left,right;
        cin>>left>>right;
        st[i].left=left;
        st[i].right=right;
    }
    //对于每一颗树,进行合并
    for(int i=n;i>=1;i--)
    {
        if(st[i].left!=-1&&st[i].right!=-1)
        {
            tree[i].makeTree(i,tree[st[i].left],tree[st[i].right]);
        }
        else if(st[i].left==-1&&st[i].right!=-1)
        {
            tree[i].makeTree(i,a,tree[st[i].right]);
        }
        else if(st[i].left!=-1&&st[i].right==-1)
        {
            tree[i].makeTree(i,tree[st[i].left],a);
        }
        else
        {
            tree[i].makeTree(i,a,a);
        }
        height[i]=tree[i].height();
        size[i]=tree[i].size();
    }

    //输出结果
    tree[1].preOrderOutput();
    tree[1].inOrderOutput();
    tree[1].postOrderOutput();
    tree[1].leverOrderOutput();
    for(int i=1;i<=n;i++)
    {
        cout<<size[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<height[i]<<" ";
    }
}