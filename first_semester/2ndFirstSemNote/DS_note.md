# 1 排序

排序分类
- 比较性排序(时间复杂度最好O(nlogn))
	- 其余排序
- 非比较性(时间复杂度O(n))
	- 基数排序
	- 桶排序
[[C语言学习笔记]]
**稳定排序**
定义:相同元素相对位置不变的排序
1、堆排序、快速排序、希尔排序、直接选择排序**不是稳定**的排序算法；

2、基数排序、冒泡排序、直接插入排序、折半插入排序、归并排序**是稳定**的排序算法。
## 1.1 名次排序
```c++
//名次定义:比它小的元素个数+左边出现的相同元素个数
//计算名次
void rank_compute(int a[],int n,int r[])
{
    // 避免重复遍历
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
        if(a[j]<=a[i])r[i]++;
        else r[j]++;
}
//按照名次排序
void rank_sort(int a[],int n,int r[])
{
    //新开辟一个数组
    int *u=new int [n];
    for(int i=0;i<n;i++)
    // r[i]表示第i个元素应该在的位置
    u[r[i]]=a[i];

    for(int i=0;i<n;i++)
    a[i]=u[i];

    delete[] u;
}

//不使用额外数组进行排序,进行交换即可
void rank_sort_without_u(int a[],int n,int r[])
{
    for(int i=0;i<n;i++)
    while(r[i]!=i)
    {
        int t=r[i];
        // 注意,此时两个都需要交换
        swap(a[i],a[t]);
        swap(r[i],r[t]);
    }
}
int main()
{
    
    int a[]{1,3,5,3,9};
    int n=sizeof(a)/sizeof(a[0]);
    int r[n]={0};
    rank_compute(a,n,r);
    //打印
    for(auto k:a)
    cout<<k<<" ";
    cout<<endl;
    
    rank_sort_without_u(a,n,r);
    for(auto k:a)
    cout<<k<<" ";
    cout<<endl;

    return 0;
}
```

```c++
//名次定义:比它小的元素个数+左边出现的相同元素个数
//计算名次
void rank_compute(int a[],int n,int r[])
{
    // 避免重复遍历
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
        if(a[j]<=a[i])r[i]++;
        else r[j]++;
}
//按照名次排序
void rank_sort(int a[],int n,int r[])
{
    //新开辟一个数组
    int *u=new int [n];
    for(int i=0;i<n;i++)
    // r[i]表示第i个元素应该在的位置
    u[r[i]]=a[i];

    for(int i=0;i<n;i++)
    a[i]=u[i];

    delete[] u;
}

//不使用额外数组进行排序,进行交换即可
void rank_sort_without_u(int a[],int n,int r[])
{
    for(int i=0;i<n;i++)
    while(r[i]!=i)
    {
        int t=r[i];
        // 注意,此时两个都需要交换
        swap(a[i],a[t]);
        swap(r[i],r[t]);
    }
}
```
## 1.2 选择排序

稳定性：不稳定
时间复杂度：最佳：O(n2) ，最差：O(n2)， 平均：O(n2)
空间复杂度：O(1)
排序方式：In-place
```c++
#include<iostream>
using namespace std;

int indexofmax(int a[],int n)
{
    if(n<=0)return 0;
    int indexofmax=0;
    for(int i=0;i<n;i++)
	    if(a[i]>a[indexofmax])
		    indexofmax=i;
    return indexofmax;
}

void selection_sort(int a[],int n)
{
    for(int i=n-1;i>=1;i--)
    {
        // 注意,此时枚举最大值一定要包含自己,因为自己有可能就是最大的
        swap(a[i],a[indexofmax(a,i+1)]);
    }
}

// 及时终止的选择排序
void improve_selection_sort(int a[],int n)
{       bool sort=false;//是否有序,无序为false,有序为true
    for(int i=n-1;i>=1&&!sort;i--)
    {      
        sort=true;
        int indexofmax=0;
        // 如果一直在交换,则设为true
        for(int j=1;j<i+1;j++)
	        if(a[j]>a[indexofmax])
	        {
	            indexofmax=j;
	        }
	        else sort=false;
        swap(a[indexofmax],a[i]);
    }
}

int main()
{
    int a[]={1,3,4,5,2};
   // 1 3 4 5 2
    
    int len=sizeof(a)/sizeof(a[0]);
    selection_sort(a,len);
    for(auto k:a)
    cout<<k<<" ";
}
// 及时终止的选择排序
void selection_sort(int a[],int n)
{
	for(int i=n)
}
```

![image.png](http://verification.fengzhongzhihan.top/202312221731315.png)

## 1.3 冒泡排序

稳定性：稳定
时间复杂度：最佳：O(n) ，最差：O(n2)， 平均：O(n2)
空间复杂度：O(1)
排序方式：In-place
```c++
#include<iostream>
#include<math.h>
using namespace std;
void bubble_sort(int a[],int n)
{
    for(int i=n-1;i>=1;i--)
    for(int j=0;j<i;j++)
        if(a[j]>a[j+1])swap(a[j],a[j+1]);
}
// 及时终止的冒泡排序
void improve_bubble_sort(int a[],int n)
{
    bool sort=false;
    for(int i=n-1;i>=1&&!sort;i--)
    {
        sort=true;
        for(int j=0;j<i;j++)
	        if(a[j]>a[j+1])
	        {
	            swap(a[j],a[j+1]);
	            sort=false;
	        }
    }
}
    int main()
{
    int a[]={1,3,4,5,2};
   // 1 3 4 5 2
    
    int len=sizeof(a)/sizeof(a[0]);
    bubble_sort(a,len);
    for(auto k:a)
    cout<<k<<" ";
}

```


## 1.4 插入排序

稳定性：稳定
时间复杂度：最佳：O(n) ，最差：O(n2)， 平均：O(n2)
空间复杂度：O(1)$
排序方式：In-place
```c++
#include<iostream>
using namespace std;

void insert(int a[],int n,int x)
{
    int i;
    //对n-1长度的数组中插入元素x使得数组仍然有序,此时长度为n
    for(i=n-1;i>=0&&x<a[i];i--)
    {
        a[i+1]=a[i];
    }
    a[i+1]=x;
}

void insert_sort(int a[],int n)
{
    //从第二个元素开始插入
    for(int i=1;i<n;i++)
    {
        insert(a,i,a[i]);
    }
}

int main()
{
     int a[5]={1,3,4,5,2};
   // 1 3 4 5 2
    
    int len=sizeof(a)/sizeof(a[0]);
    insert_sort(a,len);
    for(int i=0;i<len;i++)
    cout<<a[i]<<" ";
    return 0;
}
```
## 1.5 归并排序

```c++
template<class T> 归并排序算法
mergeSort( T *a, int left, int right)
{//对a[left:right]中的元素进行排序
	if (left < right) 
	{//至少两个元素
		int middle = (left + right)/2; //中心位置
		mergeSort(a, left, middle);
		mergeSort(a, middle +1, right);
		merge(a, b, left, middle, right); //从a归并到b
		copy(b, a, left, right); //排序结果复制到a
	}
}

template<class T>
void merge(T c[], T d[], int startOfFirst, int endOfFirst,
int endOfSecond)
{//把c[startOfFirst : endOfFirst]和c[endOfFirst+1 : endOfSecond]
	//归并到d[startOfFirst : endOfSecond].
	int first = startOfFirst, // 第一段的游标
	second = endOfFirst+1, // 第二段的游标
	result = startOfFirst; // 结果段的游标
	//当两个被归并段都未处理完，则不断进行归并
	while ((first <= endOfFirst) && (second <= endOfSecond))
		if (c[first] <= c[second]) 
			d[result++] = c[first++];
	else 
		d[result++] = c[second++];
	// 考虑余下的部分
	if (first > endOfFirst)
		for (int q = second; q <= endOfSecond; q++)
		d[result++] = c[q];
	else for (int q = first; q <= endOfFirst; q++)
		d[result++] = c[q];
}
```
## 1.6 快速排序

```c++
template<class T> 快速排序实现
void quickSort(T a[], int n)
{// 对a[0:n-1] 进行快速排序
	if(n<=1) return;
	//把最大元素移动数组右端,如果不满足，例如，当支点是最大元素时，第一个do循环语句的结果是左索引值大于n-1
	int max= indexOfMax(a, n);
	swap(a[n-1], a[max])
	quickSort(a, 0, n-2);
} 
template<class T>
void quickSort(T a[], int leftEnd, int rightEnd)
{//排序a[leftEnd : rightEnd]，a[rightEnd+1]有最大关键值
	if (leftEnd >= rightEnd) return;
	int leftCursor = leftEnd, // 从左至右的游标
	rightCursor = rightEnd+1; // 从右到左的游标
	T pivot = a[leftEnd];
	//把左侧不小于pivot的元素与右侧不大于pivot 的元素进行交换
	while (true) 
	{
		do {// 在左侧寻找不小于pivot 的元素
		leftCursor++;
		} while (a[leftCursor] < pivot);
		do {// 在右侧寻找不大于pivot 的元素
		rightCursor--;
		} while (a[rightCursor] > pivot);
		
		if (leftCursor >= rightCursor) break; // 未发现交换对象
		Swap(a[leftCursor], a[rightCursor]);
	}
	//交换两者位置
	a[leftEnd] = a[rightCursor];
	a[rightCursor] = pivot;
	//进行递归排序
	quickSort(a, leftEnd, rightCursor-1); // 对左段排序
	quickSort(a, rightCursor+1, rightEnd); // 对右段排序
}
```
## 1.7 堆排序
```c++
#include<iostream>
#include"maxHeap.hpp"
using namespace std;

template<class T>
void heapSort(T* a,int n)
{
    MaxHeap<T>heap(1);
    heap.initialize(a,n);
    for(int i=n;i>=1;i--)
    {
        T x=heap.top();
        heap.pop();
        a[i]=x;
    }

	//这一步是为了保证heap自动析构的时候, 不会将array也跟着析构掉
    heap.deactiveArray();
}

#include"heapSort.hpp"

int main()
{
    int a[6]={0,3,6,4,2,9};
    heapSort(a,5);
    for(int i=1;i<=5;i++)
    {
        cout<<a[i]<<" ";
    }
}
```
## 1.8 箱子排序

全局函数实现
```c++
#include"chain.hpp"
#include<math.h>
struct StudentRecord
{
    int score;
    string name;
    int operator !=(const StudentRecord &x)const
    {
        return score!=x.score;
    }
    operator int ()const {return score;}
    void output(ostream &out);
};

void StudentRecord::output(ostream &out)
{
    out<<name<<" "<<score<<endl;
}

ostream& operator<<(ostream &out, StudentRecord&x)
{
    x.output(out);return out;
}

template<class T>
void binSort(Chain<T>& theChain,int range)
{
    //先初始化箱子,为一个数组,数组里面存的是链表
    Chain<T>* bin=new Chain<T>[range+1];
    
    //取出链表中所有学生信息
    int numberOfIndex=theChain.size();
    for(int i=0;i<numberOfIndex;i++)
    {
       T x=theChain.get(0);
       theChain.erase(0);
       bin[x.score].insert(0,x);
    }
    //从最后一个链表开始,取出信息在链表进行头插
    for(int j=range;j>=0;j--)
    {
        while(!bin[j].empty())
        {
            T x=bin[j].get(0);
            theChain.insert(0,x);
            bin[j].erase(0);
        }
    }
    delete []bin;
}
```
成员函数实现
```c++
//在成员函数中的实现
template<class T>
void Chain<T>::binSort(int range)
{
    chainNode<T>**bottom,**top;
    bottom=new chainNode<T>*[range+1];
    top=new chainNode<T>*[range+1];
    for(int b=0;b<=range;b++)
        bottom[b]=NULL;
    while(firstNode!=NULL)
    {   
        int score=(int)firstNode->element;
        if(bottom[score]==NULL)
            bottom[score]=firstNode;
        else
        {
            top[score]->next=firstNode;
            top[score]=firstNode;
        }
        firstNode=firstNode->next;
    }
    chainNode<T>*y=NULL;
    for(int score=0;score<=range;score++)
    {
        if(bottom[score]!=NULL)
        {
            if(y==NULL)
                firstNode=bottom[score];
            else 
                y->next=bottom[score];
            y=top[score];
        }
    }
    if(y!=NULL)
        y->next=NULL;
    delete []bottom;
    delete []top;
}
```

## 1.9 基数排序

![image.png](http://verification.fengzhongzhihan.top/202401061853386.png)

```c++
//基数排序
template<class T>
void radixSort(Chain<T>& theChain,int r,int k)
{
    //先初始化箱子,为一个数组,数组里面存的是链表
    Chain<T>* bin=new Chain<T>[r+1];
    
    //取出链表中所有数字信息
    int numberOfIndex=theChain.size();
    for(int i=0;i<numberOfIndex;i++)
    {
       int  x=theChain.get(0);
       theChain.erase(0);
       int num=(x%(int)(pow(r,k)))/(pow(r,k-1));
       bin[num].insert(0,x);
    }
    //从最后一个链表开始,取出信息在链表进行头插
    for(int j=r;j>=0;j--)
    {
        while(!bin[j].empty())
        {
            T x=bin[j].get(0);
            theChain.insert(0,x);
            bin[j].erase(0);
        }
    }
    delete []bin;
}

//test
#include"radixSort.hpp"
int main()
{
    // Chain<StudentRecord>x;
    // x.push_back(StudentRecord{10,"limei"});
    // x.push_back(StudentRecord{20,"hanshuang"});
    // x.push_back(StudentRecord{35,"wangshi"});
    // x.push_back(StudentRecord{15,"fwf"});
    // x.push_back(StudentRecord{15,"dqew"});
    // cout<<x;
    // cout<<"------------------"<<endl;
    // binSort(x,35);
    // cout<<x;
    Chain<int>s;
    int n;cin>>n;
    while(n--)
    {
        int x;cin>>x;
        s.push_back(x);
    }
    int r,c=0;
    cin>>r;
    int x=s.max();
    while(x)
    {
        x/=r;c++;
    }
    cout<<"r="<<r<<endl;
    cout<<"c="<<c<<endl;
    cout<<s<<endl;
    //基数排序
    for(int i=1;i<=c;i++)
    radixSort<int>(s,r,i);
    cout<<s<<endl;
}
```

# 2 整体概述
## 2.1 数据结构的概念
**数据结构?**

定义:数据对象在计算机中的组织形式
包含:数据对象集和操作集

**分类**
- 逻辑结构
  - 定义:数据对象中数据元素之间的相互关系
  - 分类
    - 集合结构:属于同一集合
    - 线性结构:元素一一对应
    - 树形结构:元素之间存在一对多的层次关系
    - 图形结构:元素直接存在多对多的层次关系
- 注意
  - 每一个数据元素看作一个结点,用圆圈表示
  - 元素之间的逻辑关系用结点之间的连线表示
- 物理结构
  - 定义:数据的逻辑结构在计算机中的存储形式
  - 分类
    - 顺序存储结构:把数据元素存放在地址连续的存储单元里,逻辑关系和物理关系是一致的
    - 链式存储结构:把数据元素存放在任意的存储单元里,可以连续,可以不连续,其存储关系无法反映其逻辑关系

**抽象数据类型**(ADT):只关心是什么,而不关心怎么做到的

**解决问题的效率**
- 数据的组织方式
- 空间利用方式
- 算法的巧妙程度

## 2.2 时间复杂度
- 假设算法的问题规模为n，那么操作单元数量便用函数f(n)来表示，随着数据规模n的增大，算法执行时间的增长率和f(n)的增长率相同，这称作为算法的渐近时间复杂度，简称**时间复杂度，记为 O(f(n))**
- O代表上界,当用它作为算法的最坏情况运行时间的上界，就是对任意数据输入的运行时间的上界
	- **一般O表示一般情况, 不表示最坏情况**
- 在决定使用哪些算法的时候，**不是时间复杂越低的越好**（因为简化后的时间复杂度忽略了常数项等等），要考虑数据规模，如果数据规模很小甚至可以用O(n^2)的算法比O(n)的更合适（在有常数项的时候）。
- 为什么一般简写为logn :
	- 因为我们log2可以通过log10* C来进行实现
![image.png|550](http://verification.fengzhongzhihan.top/202312202222980.png)


分析举例 :
>找出n个字符串中相同的两个字符串

如果是暴力枚举的话，时间复杂度是多少呢，是O(n^2)么？

这里一些同学会忽略了字符串比较的时间消耗，这里并不像int 型数字做比较那么简单，除了n^2 次的遍历次数外，字符串比较依然要消耗m次操作（m也就是字母串的长度），所以时间复杂度是O(m × n × n)。

先排对n个字符串按字典序来排序，排序后n个字符串就是有序的，意味着两个相同的字符串就是挨在一起，然后在遍历一遍n个字符串，这样就找到两个相同的字符串了。

那看看这种算法的时间复杂度，快速排序时间复杂度为O(nlogn)，依然要考虑字符串的长度是m，那么快速排序每次的比较都要有m次的字符比较的操作，就是O(m × n × log n) 。

之后还要遍历一遍这n个字符串找出两个相同的字符串，别忘了遍历的时候依然要比较字符串，所以总共的时间复杂度是 O(m × n × logn + n × m)。

我们对O(m × n × log n + n × m) 进行简化操作，把m × n提取出来变成 O(m × n × (logn + 1))，再省略常数项最后的时间复杂度是 O(m × n × log n)。

最后很明显O(m × n × logn) 要优于O(m × n × n)！

## 2.3 算法超时分析

运算速度: 主要看CPU的配置

- 1GHz（兆赫）= 1000MHz（兆赫）
- 1MHz（兆赫）= 1百万赫兹

一秒脉冲10亿次, 共有10亿次时钟周期, 但并不代表只有10亿次运算

>- 火箭科学家需要大致知道一枚试射火箭的着陆点是在大海里还是在城市中；医学研究者需要知道一次药物测试是会杀死还是会治愈实验对象

![image.png|450](http://verification.fengzhongzhihan.top/202312172205078.png)

## 2.4 递归的时间复杂度分析

本质上需要看: **递归的次数 * 每次递归中的操作次数**。

面试题：求x的n次方

```c++
int function1(int x, int n) {
    int result = 1;  // 注意 任何数的0次方等于1
    for (int i = 0; i < n; i++) {
        result = result * x;
    }
    return result;
}


```
此时面试官会说，有没有效率更好的算法呢。
```c++
int function2(int x, int n) {
    if (n == 0) {
        return 1; // return 1 同样是因为0次方是等于1的
    }
    return function2(x, n - 1) * x;
}
```

每次n-1，递归了n次时间复杂度是O(n)，每次进行了一个乘法操作，乘法操作的时间复杂度一个常数项O(1)，所以这份代码的时间复杂度是 n × 1 = O(n)。

这个时间复杂度就没有达到面试官的预期。于是又写出了如下的递归算法的代码：

```c++
int function3(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    if (n % 2 == 1) {
        return function3(x, n / 2) * function3(x, n / 2)*x;
    }
    return function3(x, n / 2) * function3(x, n / 2);
}
```
求x的n次方，这个递归树有多少个节点呢?

$$m=log_2n-1 $$
带入总结点数, 得到总结点数k= n-1

仍然为O(n)

```c++
int function4(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    int t = function4(x, n / 2);// 这里相对于function3，是把这个递归操作抽取出来
    //是奇数就返回t * t * x
    if (n % 2 == 1) {
        return t * t * x;
    }
    return t * t;
}
```

## 2.5 简历写法

主要有如下几点：

- 简历篇幅不要过长
- 谨慎使用“精通”
- 拿不准的绝对不要写在简历上
- 项目经验中要突出自己的贡献
	- **项目经验中要突出自己的贡献**，不要描述一遍项目就完事，要突出自己的贡献，是添加了哪些功能，还是优化了那些性能指数，最后再说说受益怎么样。
- 面试中如何变被动为主动
	- 这里还是有一些技巧的，首先是**做项目的时候时刻保持着对难点的敏感程度**，很多我们费尽周折解决了一个问题，然后自己也不做记录，就忘掉了，**此时如果及时将自己的思考过程记录下来，就是面试中的重要素材，养成这样的习惯非常重要**。
- 博客的重要性
	- 博客的重要性简历上可以放上自己的博客地址、Github地址甚至微博（如果发了很多关于技术的内容），**通过博客和github 面试官就可以快速判断同学们对技术的热情，以及学习的态度**，可以让面试官快速的了解同学们的技术水平。

**词语的强烈程度：精通 > 熟悉（推荐使用）> 掌握（推荐使用）> 了解（推荐使用）**

## 2.6 空间复杂度

定义:是对一个算法在运行过程中占用内存空间大小的量度，记做S(n)=O(f(n)。

很多同学都会混淆程序运行时内存大小和程序本身的大小。这里强调一下**空间复杂度是考虑程序运行时占用内存的大小，而不是可执行文件的大小。**

说到空间复杂度，我想同学们在OJ（online judge）上应该遇到过这种错误，就是超出内存限制，一般OJ对程序运行时的所消耗的内存都有一个限制。

举例
O(1)
```c++
int j = 0;
for (int i = 0; i < n; i++) {
    j++;
}
```

O(n)

当消耗空间和输入参数n保持线性增长，这样的空间复杂度为O(n)，来看一下这段C++代码

```c++
int* a = new int(n);
for (int i = 0; i < n; i++) {
    a[i] = i;
}
```

## 2.7 递归算法的空间复杂度

**递归算法的空间复杂度 = * 递归深度 *每次递归的空间复杂度 

### 2.7.1 斐波那契数列递归分析
```c++
int fibonacci(int i) {
       if(i <= 0) return 0;
       if(i == 1) return 1;
       return fibonacci(i-1) + fibonacci(i-2);
}
```


一棵深度（按根节点深度为1）为k的二叉树最多可以有 2^k - 1 个节点。
所以该递归算法的时间复杂度为O(2^n)

所以这种求斐波那契数的算法看似简洁，其实时间复杂度非常高，一般不推荐这样来实现斐波那契。

```c++
int fibonacci(int first, int second, int n) {
    if (n <= 0) {
        return 0;
    }
    if (n < 3) {
        return 1;
    }
    else if (n == 3) {
        return first + second;
    }
    else {
        return fibonacci(second, first + second, n - 1);
    }
}
```
这里相当于用first和second来记录当前相加的两个数值，此时就不用两次递归了。

因为每次递归的时候n减1，即只是递归了n次，所以时间复杂度是 O(n)。

同理递归的深度依然是n，每次递归所需的空间也是常数，所以空间复杂度依然是O(n)。

代码（版本二）的复杂度如下：

- 时间复杂度：O(n)
- 空间复杂度：O(n)

递归第n个斐波那契数的话，递归调用栈的深度就是n。
那么每次递归的空间复杂度是O(1)， 调用栈深度为n，所以这段递归代码的空间复杂度就是O(n)。

![image.png|450](http://verification.fengzhongzhihan.top/202312172239642.png)
### 2.7.2 二分法递归性能分析

```c++
int binary_search( int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);
        return binary_search(arr, mid + 1, r, x);
    }
    return -1;
}
```
**每一层递归都是公用一块数组地址空间的**，所以 每次递归的空间复杂度是常数即：O(1)。

再来看递归的深度，二分查找的递归深度是logn ，递归深度就是调用栈的长度，那么这段代码的空间复杂度为 1 * logn = O(logn)。

## 2.8 代码内存消耗

### 2.8.1 内存管理方式

**不同的编程语言各自的内存管理方式。**
- C/C++这种内存堆空间的申请和释放完全靠自己管理
- Java 依赖JVM来做内存管理，不了解jvm内存管理的机制，很可能会因一些错误的代码写法而导致内存泄漏或内存溢出
- Python内存管理是由私有堆空间管理的，所有的python对象和数据结构都存储在私有堆空间中。程序员没有访问堆的权限，只有解释器才能操作。

以C++为例
- 固定部分的内存消耗 是不会随着代码运行产生变化的， 可变部分则是会产生变化的
![image.png](http://verification.fengzhongzhihan.top/202312172246550.png)


在可变部分中，栈区间的数据在代码块执行结束之后，系统会自动回收，而堆区间数据是需要程序员自己回收，所以也就是造成内存泄漏的发源地。

- **而Java、Python的话则不需要程序员去考虑内存泄漏的问题，虚拟机都做了这些事情**

### 2.8.2 计算占用内存
为什么64位的指针就占用了8个字节，而32位的指针占用4个字节呢？

安装64位的操作系统的计算机内存都已经超过了4G，也就是指针大小如果还是4个字节的话，就已经不能寻址全部的内存地址，所以64位编译器使用8个字节的指针才能寻找所有的内存地址。

### 2.8.3 内存对齐

原因:
1. 平台原因：不是所有的硬件平台都能访问任意内存地址上的任意数据，某些硬件平台只能在某些地址处取某些特定类型的数据，否则抛出硬件异常。为了同一个程序可以在多平台运行，需要内存对齐
2. 硬件原因：经过内存对齐后，CPU访问内存的速度大大提升。

![image.png](http://verification.fengzhongzhihan.top/202312172251748.png)
![image.png](http://verification.fengzhongzhihan.top/202312172252121.png)
**大家可能会发现内存对齐岂不是浪费的内存资源么？**

是这样的，但事实上，相对来说计算机内存资源一般都是充足的，我们更希望的是提高运行速度。

**编译器一般都会做内存对齐的优化操作，也就是说当考虑程序真正占用的内存大小的时候，也需要认识到内存对齐的影响**。

## 2.9 C++基础
### 2.9.1 引用
引用参数节省空间,且可以改变变量的值
```c++
int abc(int &a,int &b,int &c)
{
    return a+b+c;
}
```
常量引用参数,不可修改变量的值,但是节省空间
```c++
int abc(const int &a,const int &b,const int &c)
{
    return a+b+c;
}
```
引用返回
```c++
int & abc(int &a,int b,int c)
{
   a=20;
   return a;
}
```
常量引用返回,注意此时必须要将值赋给const 常量
```c++
const int &ab(int a)
{
    int b ;
    return b;
}
```
### 2.9.2 异常处理
```c++
int abc(int a,int b,int c)
{
    if(a<0||b<0||c<0)
        throw"all parameters should be >0";
    return a+b+c;
}
int main()
{
    try{cout<<abc(10,20,-1);}
    catch(char const *e)//注意得是char const *
    {
        cout<<"FALSE"<<endl;
        cout<<e<<endl;
        return 1;
    }
    return 0;
}

//内存分配异常
const long long  N=100000000000000000;

int main()
{
    int *y=new int (10);
    float *array;
    try{array=new float[N];}
    catch(bad_alloc e)
    {
        cout<<"out of memory "<<endl;
        exit(1);
    }
    return 0;
}
```

### 2.9.3 二维数组不指定列的方法
```c++
// 捕获异常

void make2darray(int ** &x,int rows,int cols)
{
    x=new int *[rows];
    for(int i=0;i<rows;i++)
    x[i]=new int [cols];
}

//释放内存
void delete2darray(int ** &x,int rows)
{
    //先释放行内存
    for(int i=0;i<rows;i++)
    delete [] x[i];

    //再释放列内存
    delete []x;
    x=NULL;
}

int main()
{
    int **x;
    try{make2darray(x,ROW,COL);}
    catch(bad_alloc)
    {
        cerr<<"couldn't create 2darray"<<endl;
        exit(1);
    }
    return 0;
    
}
```
### 2.9.4 类的实现
	
注意:.
file_name.cpp和file_name.h文件名必须要相同,不然无法包含.cpp文件

运算符的重载
```c++
Currency Currency::operator+ (const Currency&x)const
{
    Currency result;
    result.my_amount=x.my_amount+my_amount;
    return result;
}
//返回引用,方便链式法则
ostream & operator<<(ostream& out,const Currency &x)
{
    // x.output(out);return out;
    if(x.my_amount<0)out<<"-";
   ul dollars=x.getDollars();
   out<<"$"<<dollars<<".";
   ui cents=x.getCents();
   if(cents<10)out<<"0";
   out<<cents<<endl;
}

```
不加入友元,使用成员函数
```c++
//不加入友元的写法
void Currency::output(ostream& out)const
{
    if(my_amount<0)out<<"-";
   ul dollars=getDollars();
   out<<"$"<<dollars<<".";
   ui cents=getCents();
   if(cents<10)out<<"0";
   out<<cents<<endl;
}
```
加入友元,使用全局函数
```c++
ostream & operator<<(ostream& out,const Currency &x)
{
    // x.output(out);return out;

    if(x.my_amount<0)out<<"-";
   ul dollars=x.getDollars();
   out<<"$"<<dollars<<".";
   ui cents=x.getCents();
   if(cents<10)out<<"0";
   out<<cents<<endl;
}
```

### 2.9.5 递归函数

基本条件+递归条件
```c++
// 计算n的阶乘
int factorial(int n)
{
    if(n==1)return 1;
    else return (factorial(n-1)*n);
}

// 计算n个元素的和的非递归实现
int sum(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=a[i];
    return sum;
}

//递归实现
int rec_sum(int a[],int n)
{
    if(n>0)
    return (sum(a,n-1)+a[n-1]);
    return 0;
}
//全排列,前缀为list[0:k-1],后缀为list[k:m]
void permutations(int list[],int k,int m)
{
    if(k==m)
    {
	    //输出该排列,要包含#include<iterator>头文件
        copy(list,list+m+1,ostream_iterator<int>(cout, ""));
        cout<<endl;
    }
    else
    for(int i=k;i<=m;i++)
    {
        swap(list[k],list[i]);
        permutations(list,k+1,m);
        swap(list[k],list[i]);
    }
}
```
### 2.9.6 两个stl函数
```c++
//accumulate 
//累加和
int sum(int a[],int n)
{
    int theSum=0;
    return accumulate(a,a+n,theSum);
}

// copy和next_permutation
void permutations(int list[],int k,int m)
{
    do
    {
    copy(list,list+m+1,ostream_iterator<int>(cout,""));
    cout<<endl;
    }while(next_permutation(list,list+m+1));
}
```
### 2.9.7 多项式求值
```c++
//多项式求值(朴素)
int polyEval(int coeff[],int n,const int &x)
{
    int y=1;int value=coeff[0];
    for(int i=1;i<=n;i++)
    {
        y*=x;
        value+=y*coeff[i];
    }
    return value;
}   

// Horner法则求多项式,每次都少一次乘法
int horner(int coeff[],int n,const int &x)
{
    int value=coeff[n];
    for(int i=1;i<=n;i++)
    {
        value=value*x+coeff[n-i];
    }
    return value;
}
```

# 3 线性表
**定义**:表示元素的一个有序集合,拥有元素的先后关系
## 3.1 线性表的定义

**由同类型数据元素构成的有序序列的线性结构**

- 长度:元素个数
- 表头和表尾:字面意思
- 空表:线性表没有元素
## 3.2 线性表的顺序存储

### 3.2.1 建立,构造和析构函数

```c
#pragma once
#include<iostream>
using namespace std;
template <class T>
class LinearList
{
    public: 
    virtual ~LinearList(){};
    virtual bool empty()const =0;
    virtual int size()const =0;
    virtual T get(int theIndex)const =0;
    virtual int indexOf(const T& x)const =0;
    virtual void erase(int theIndex)=0;
    virtual void insert(int theIndex,const T &x)=0;
    virtual void output(ostream& out)const=0;
    virtual void clear()=0;
    virtual void push_back(const T& x)=0;
};

template<class T>
class arrayList:public LinearList<T>
{
    public:
    arrayList(int initialCapacity);
    arrayList(const arrayList<T>&);
    ~arrayList(){delete [] element;}

    //重写父类虚构函数
     virtual bool empty()const  {return listSize==0;}
     virtual int size()const {return listSize;}
     virtual T get(int theIndex)const;
     virtual int indexOf(const T&x)const;
     virtual void erase(int theIndex);
     virtual void insert(int theIndex,const T &x);
     virtual void output(ostream& out)const;
    //其他函数
    int capacity()const{return arrayLength;}
    void push_back(const T&x);
    void pop_back();
    void reserve(int theCapacity);
    void clear();
    
    protected:
    void checkIndex(int theIndex)const;
    T* element;
    int arrayLength=0;
    int listSize=0;
};

//直接构造函数
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
    if(initialCapacity<1)return;
    arrayLength=initialCapacity;
    element=new T[arrayLength];
}

//拷贝构造函数
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
   arrayLength= theList.arrayLength;
   element=new T[arrayLength];
   listSize=theList.listSize;;
   copy(theList.element,theList.element+listSize,element);
}
```


### 3.2.2 主要操作集的实现
- 改变数组的长度
```c++
template<class T>
void changeLength(T*& a,int oldLength,int newLength)
{
    if(newLength<0)return;
    T *temp=new T[newLength];
    int size=min(oldLength,newLength);
    copy(a,a+size,temp);
    delete[]a;
    a=temp;
}
```

- 根据索引返回元素

```c++
template<class T>
T arrayList<T>::get(int theIndex)const
{
    checkIndex(theIndex);
    return element[theIndex];
}
```

- 根据元素返回索引
```c++
template<class T>
int arrayList<T>::indexOf(const T&x)const
{
    int theIndex=(int)(find(element,element+listSize,x)-element);
    if(theIndex==listSize)
    return -1;
    else return theIndex;
}
```

- 在第i个元素之前插入一个元素

```c++
//插入函数
template<class T>
void arrayList<T>::insert(int theIndex,const T&x)
{
    //检查是否为有效索引,可以写到末尾即listSize
    if(theIndex<0||theIndex>listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<"size="<<listSize;
        throw(s.str());
    }

    //满了则扩容
    if(listSize==arrayLength)
    {
        changeLength(element,listSize,listSize*2);
        arrayLength*=2;
    }
    //插入,往后移动
    copy_backward(element+theIndex,element+listSize,element+listSize+1);
    element[theIndex]=x;
    listSize++;
}
```

- 删除第i个元素

```c++

//根据索引删除一个元素
template<class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element+theIndex+1,element+listSize,element+theIndex);
    //释放最后一个元素的内存
    element[--listSize].~T();
}
```

- 输出和重载
```c++
//输出
template<class T>
void arrayList<T>::output(ostream&out)const
{
    if(listSize==0)
    {
        cout<<"empty";return;
    }
    //在元素之间插入空格
    copy(element,element+listSize,ostream_iterator<T>(out," "));
}

//重载
template<class T>
ostream& operator<<(ostream & out,const arrayList<T>&arr)
{
    arr.output(out);return out;
}
```
- 尾部插入和尾部删除元素
```c++
//尾部插入一个元素
template<class T>
void arrayList<T>::push_back(const T&x)
{
    if(listSize==arrayLength)
    {
        changeLength(element,arrayLength,arrayLength*2);
        arrayLength*=2;
    }

    element[listSize++]=x;
}

//尾部删除一个元素
template<class T>
void arrayList<T>::pop_back()
{
    if(listSize<=0)
    {
        cout<<"already empty"<<endl;
        return;
    }
    else
     element[--listSize].~T();
}
```
- 保留长度和清空列表
```c++
//保留长度
template<class T>
void arrayList<T>::reserve(int theCapacity)
{
    if(theCapacity<=0)
    {
        cout<<"theCapacity should be >0";
        return;
    }
    arrayLength=max(arrayLength,theCapacity);
}

//清空线性表
template<class T>
void arrayList<T>::clear()
{
    listSize=0;
    arrayLength=0;
    delete []element;
    element=NULL;
}
```
## 3.3 线性表的链式存储((不含头结点))

链式存储不要求逻辑上相邻的元素物理上也相邻,此时插入和删除操作不需要移动元素

### 3.3.1 结点类和链表类

```c++
 template<class T>
//结点
class chainNode
{
    public:
    T element;
    chainNode<T>* next;

    chainNode(){};

    //两个构造函数
    chainNode(const T& element){this->element=element;}
    chainNode(const T& element,chainNode<T>*next)
    {
        this->element=element;
        this->next=next;
    }
};

template<class T>
class Chain:public LinearList<T>
{
    public:
    //似乎没用
    Chain(int initialCapacity);
    Chain(const Chain<T>&);
    ~Chain();

    //ADT
    virtual bool empty()const  {return listSize==0;}
    virtual int size()const {return listSize;}
    virtual T get(int theIndex)const;
    virtual int indexOf(const T& x)const;
    virtual void erase(int theIndex);
    virtual void insert(int theIndex,const T &x);
    virtual void output(ostream& out)const;

    //后加ADT
    virtual void clear();
    virtual void push_back(const T& x);

    protected:
    void checkIndex(int theIndex)const;
    chainNode<T>* firstNode;
    chainNode<T>* lastNode;
    int listSize;
};
//赋值构造函数
template<class T>
Chain<T>::Chain(int initialCapacity)
{
    if(initialCapacity<1)return;
    firstNode=lastNode=NULL;
    listSize=0;
}
//拷贝构造函数
template<class T>
Chain<T>::Chain(const Chain<T>&theList)
{   
    listSize=theList.listSize;
    if(listSize==0)
    {
        firstNode=lastNode=NULL;
        return;
    }
    else
    {
        //先把被copy链表第一个结点作为第一个结点
        //sourceNode:指向被copy的结点
        //targetNode:指向copy链表的尾部结点
        chainNode<T>* sourceNode=theList.firstNode;
        firstNode=new chainNode<T>(sourceNode->element);
        sourceNode=sourceNode->next;
        chainNode<T>* targetNode=firstNode;
        while(sourceNode!=NULL)
        {
            targetNode->next=new chainNode<T>(sourceNode->element);
            targetNode=targetNode->next;
            sourceNode=sourceNode->next;
        }
        targetNode->next=NULL;
        lastNode=targetNode;
    }
}
```

### 3.3.2 主要操作集的实现

根据索引返回元素

```c++
template<class T>
int Chain<T>::indexOf(const T& x)const
{
    chainNode<T>* currentNode=firstNode;
    int index=0;
    while(currentNode!=NULL&&currentNode->element!=x)
    {
        currentNode=currentNode->next;
        index++;
    }
    if(currentNode==NULL)
    return -1;
    else return index;
}
```

- 根据元素返回索引
```c++
template<class T>
T Chain<T>::get(int theIndex)const
{
    checkIndex(theIndex);
    chainNode<T>* currentNode=firstNode;
    for(int i=0;i<theIndex;i++)
    {
        currentNode=currentNode->next;
    }
    return currentNode->element;
}
```

- 在第i个元素之前插入一个元素

```c++
template<class T>
void Chain<T>::insert(int theIndex,const T&x)
{
    if(theIndex<0||theIndex>listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<"size="<<listSize;
        throw(s.str());
    }

    //无需扩容
    if(theIndex==0)
    firstNode=new chainNode<T>(x,firstNode);
    else
    {
        chainNode<T>*p=firstNode;
        for(int i=0;i<theIndex-1;i++)
        p=p->next;
        p->next=new chainNode<T>(x,p->next);
    }
    listSize++;
    chainNode<T>* p=firstNode; 
    for(int i=0;i<listSize-1;i++)
    p=p->next;
    lastNode=p;
}
```

- 删除第i个元素

```c++

template<class T>
void Chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T>* deleteNode;
    //先判断是否删除第0结点
    if(theIndex==0)
    {
        deleteNode=firstNode;
        firstNode=firstNode->next;
    }
    //找到第theIndex-1的位置p
    else
    {
        chainNode<T>*p=firstNode;
        for(int i=0;i<theIndex-1;i++)
        p=p->next;

        deleteNode=p->next;
        p->next=deleteNode->next;
    }
    delete deleteNode;
    listSize--;
    chainNode<T>* p=firstNode;
    for(int i=0;i<listSize-1;i++)
    p=p->next;
    lastNode=p;
}
```

- 输出和重载
```c++
//输出
template<class T>
void Chain<T>::output(ostream& out)const
{
    if(listSize==0)
    {
        out<<"empty";return;
    }
    
    for(chainNode<T>*currentNode=firstNode;currentNode!=NULL;currentNode=currentNode->next)
    {
        out<<currentNode->element<<" ";
    }
}
//重载
template<class T>
ostream& operator<<(ostream& out,const Chain<T>x)
{
    x.output(out);return out;
}
```
- 尾部插入和清空列表
```c++
//后缀元素
template<class T>
void Chain<T>::clear()
{
    while(firstNode!=NULL)
    {
        chainNode<T>* nextNode=firstNode->next;
        delete firstNode;
        firstNode=nextNode;
    }
    listSize=0;
}

template<class T>
void Chain<T>::push_back(const T&x)
{
    chainNode<T>* newNode=new chainNode<T>(x,NULL);
    if(firstNode==NULL)
        firstNode=lastNode=newNode;
    else
    {
        lastNode->next=newNode;
        lastNode=newNode;
    }
    listSize++;
}
```

## 3.4 应用
### 3.4.1 箱子排序

全局函数实现
```c++
#include"chain.hpp"
#include<math.h>
struct StudentRecord
{
    int score;
    string name;
    int operator !=(const StudentRecord &x)const
    {
        return score!=x.score;
    }
    operator int ()const {return score;}
    void output(ostream &out);
};

void StudentRecord::output(ostream &out)
{
    out<<name<<" "<<score<<endl;
}

ostream& operator<<(ostream &out, StudentRecord&x)
{
    x.output(out);return out;
}

template<class T>
void binSort(Chain<T>& theChain,int range)
{
    //先初始化箱子,为一个数组,数组里面存的是链表
    Chain<T>* bin=new Chain<T>[range+1];
    
    //取出链表中所有学生信息
    int numberOfIndex=theChain.size();
    for(int i=0;i<numberOfIndex;i++)
    {
       T x=theChain.get(0);
       theChain.erase(0);
       bin[x.score].insert(0,x);
    }
    //从最后一个链表开始,取出信息在链表进行头插
    for(int j=range;j>=0;j--)
    {
        while(!bin[j].empty())
        {
            T x=bin[j].get(0);
            theChain.insert(0,x);
            bin[j].erase(0);
        }
    }
    delete []bin;
}
```
成员函数实现
```c++
//在成员函数中的实现
template<class T>
void Chain<T>::binSort(int range)
{
    chainNode<T>**bottom,**top;
    bottom=new chainNode<T>*[range+1];
    top=new chainNode<T>*[range+1];
    for(int b=0;b<=range;b++)
        bottom[b]=NULL;
    while(firstNode!=NULL)
    {   
        int score=(int)firstNode->element;
        if(bottom[score]==NULL)
            bottom[score]=firstNode;
        else
        {
            top[score]->next=firstNode;
            top[score]=firstNode;
        }
        firstNode=firstNode->next;
    }
    chainNode<T>*y=NULL;
    for(int score=0;score<=range;score++)
    {
        if(bottom[score]!=NULL)
        {
            if(y==NULL)
                firstNode=bottom[score];
            else 
                y->next=bottom[score];
            y=top[score];
        }
    }
    if(y!=NULL)
        y->next=NULL;
    delete []bottom;
    delete []top;
}
```

### 3.4.2 基数排序
```c++
//基数排序
template<class T>
void radixSort(Chain<T>& theChain,int r,int k)
{
    //先初始化箱子,为一个数组,数组里面存的是链表
    Chain<T>* bin=new Chain<T>[r+1];
    
    //取出链表中所有数字信息
    int numberOfIndex=theChain.size();
    for(int i=0;i<numberOfIndex;i++)
    {
       int  x=theChain.get(0);
       theChain.erase(0);
       int num=(x%(int)(pow(r,k)))/(pow(r,k-1));
       bin[num].insert(0,x);
    }
    //从最后一个链表开始,取出信息在链表进行头插
    for(int j=r;j>=0;j--)
    {
        while(!bin[j].empty())
        {
            T x=bin[j].get(0);
            theChain.insert(0,x);
            bin[j].erase(0);
        }
    }
    delete []bin;
}

//test
#include"radixSort.hpp"
int main()
{
    // Chain<StudentRecord>x;
    // x.push_back(StudentRecord{10,"limei"});
    // x.push_back(StudentRecord{20,"hanshuang"});
    // x.push_back(StudentRecord{35,"wangshi"});
    // x.push_back(StudentRecord{15,"fwf"});
    // x.push_back(StudentRecord{15,"dqew"});
    // cout<<x;
    // cout<<"------------------"<<endl;
    // binSort(x,35);
    // cout<<x;
    Chain<int>s;
    int n;cin>>n;
    while(n--)
    {
        int x;cin>>x;
        s.push_back(x);
    }
    int r,c=0;
    cin>>r;
    int x=s.max();
    while(x)
    {
        x/=r;c++;
    }
    cout<<"r="<<r<<endl;
    cout<<"c="<<c<<endl;
    cout<<s<<endl;
    //基数排序
    for(int i=1;i<=c;i++)
    radixSort<int>(s,r,i);
    cout<<s<<endl;
}
```

### 3.4.3 并查集

**等价关系和等价类**

等价关系满足条件
![image.png](http://verification.fengzhongzhihan.top/202309251131707.png)
**等价类**即相互等价元素的最大集合
**并查集**是用来实现已知等价关系和一组元素,来确定等价类的过程

**在线等价类和离线等价类的区别**
在线等价类是指在处理等价关系问题时，我们在接收到新的等价关系时立即处理，更新等价类的信息。这种方法的优点是可以实时获取等价类的信息，但是可能需要频繁的更新操作，效率较低。

离线等价类是指在处理等价关系问题时，我们先接收所有的等价关系，然后一次性处理，更新等价类的信息。这种方法的优点是可以减少更新操作的次数，提高效率，但是在处理过程中无法获取实时的等价类信息

- 注意:每个元素只能属于一个等价类

![image.png|450](http://verification.fengzhongzhihan.top/202310101100682.png)

在线等价类问题就是并查集问题
- 第一种解决方法
```c++
//第一种解决方法
//初始化
int n;
int * equivClass;
void initialize(int numberOfIndex)
{
    n=numberOfIndex;
    equivClass=new int[n+1];
    for(int e=1;e<=n;e++)
        equivClass[e]=e;
}
//合并类classA和classB,假设两类并不相同
void unite(int classA,int classB)
{
    for(int k=1;k<=n;k++)
        if(equivClass[k]==classB)
            equivClass[k]=classA;
}
//找到某个元素的类
int find(int e)
{
    return equivClass[e];
}

void combine(int a, int b)
{
	int classA = find(a);
	int classB = find(b);
	if (classA != classB)
		unite(classA, classB);
}
```
- 第二种解决方法
```c++
针对每个等价类设立一个相应的链表——等价类链表
每个元素都在一个等价类链表中
initialize ：为每个元素设置一个只拥有该元素的链表
Unite：合并两个链表
Find：查找元素所在的链表
```
# 4 数组和矩阵

## 4.1 数组的映射

映射方式
- 行主映射:从第一行开始,依此对每一行的索引进行编号
- 此时map函数值为对应的索引位置
- 行主次序:索引对应的数
- 此时二维映射函数为map(i1,i2)=i1 * u2+i2
0 1 2 3 4 5 6
6 7 8 9 10 11
12 13 14 15 16 

列主映射
0 3 6
1 4 7
2 5 8..
- 此时函数为map(i1,i2)= u1 * i2 + i1

三维行主映射 
```
score [u1] [u2] [u3]
[0][0][0],[0][0][1],[0][0][2],[0][0][3],[0][l][0],[0][l][l],[0][1][2],[0][1][3],
[1][0][0],[l][0][l],[1][0][2],[1][0][3],[1][1][0],[1][1][1],[1][1][2],[1][1][3],
[2][0][0],[2][0][1],[2][0][2],[2][0][3],[2][1][0],[2][1][1],[2][l][2],[2][1][3]
```

三维映射函数为map(i1,i2,i3)=i1* u2* u3 +i2* u3+i3
- 第一个坐标小于i1个数为i1* u2* u3
- 第一个坐标等于i1,第二个坐标小于i2的个数i2* u3
- 第一个坐标等于i1,第二个坐标等于i2,第三个坐标小于i3的个数为i3

不规则二维数组和规则二维数组
- 每行元素个数相同:规则,否则不规则

多维数组的定位方式
```c++
//数组的数组
C++定位x[i][j]的过程：
n 利用一维数组的映射函数找到指针x[i]
n 利用一维数组的映射函数找到指针x[i]所指的第i行中索引
为j的元素
//行主描述和列主描述
定位x[i][j]的过程：
n 利用二维数组的映射函数(map(i1,i2)= u2 *i1 + i2)计算x[i][j]在一维数组y中的位置u,
n 利用一维数组的映射函数(map(i1)=i1)访问
元素y[u]
```
创建不规则二维数组
```c++
#include<iostream>
using namespace std;

int main()
{
    int numberOfRows=5;
    int length[5]={6,3,4,2,7};

    int **irregularArray=new int *[numberOfRows];

    for(int i=0;i<numberOfRows;i++)
    {
        irregularArray[i]=new int[length[i]];
    }

    irregularArray[2][3]=5;
    irregularArray[4][6]=irregularArray[2][3]+3;
    irregularArray[1][1]=3;
    cout<<irregularArray[2][3]<<endl;
    cout<<irregularArray[4][6]<<endl;
    cout<<irregularArray[1][1]<<endl;
    return 0;
}
```

## 4.2 矩阵类
矩阵相乘
![image.png|500](http://verification.fengzhongzhihan.top/202310101425673.png)

类matrix
```c++
#include<iostream>
using namespace std;

template<class T>
class Matrix
{
public:
    //构造析构函数
    Matrix(int theRows=0,int theColumns=0);
    Matrix(const Matrix<T>&);
    ~Matrix(){delete[]element;}
    int rows()const {return theRows;}
    int columns()const {return theColumns;}
    void set(int i,int j,const T& value);
    T& get(int i,int j)const;
    
    //运算符重载
    T& operator()(int i,int j)const ;
    Matrix<T>&operator=(const Matrix<T>&);
    Matrix<T>operator+()const;
    Matrix<T>operator+(const Matrix<T>&)const;
    Matrix<T>operator-()const;
    Matrix<T>operator-(const Matrix<T>&)const;
    Matrix<T>operator*(const Matrix<T>&)const;
    Matrix<T>&operator+=(const T&)const;
private:
    int theRows,theColumns;
    T* element;
};

//含参构造
template <class T>
Matrix<T>::Matrix(int theRows,int theColumns)
{
    if(theRows<0||theColumns<0)
        throw ("Rows and colums must be >=0");
    //一个等于零且一个不等于零
    if((theRows==0||theColumns==0)&&(theRows!=0||theColumns!=0))
        throw ("Either both or neither rows and columns should be zero");
    
    this->theRows=theRows;
    this->theColumns=theColumns;
    element=new T[theRows*theColumns];
}

//拷贝构造
template<class T>
Matrix<T>::Matrix(const Matrix<T>&x)
{
    theRows=x.theRows;
    theColumns=x.theColumns;
    element=new T[theRows*theColumns];
    copy(x.element,x.element+theRows*theColumns,element);
}

template <class T>
inline void Matrix<T>::set(int i, int j,const T& value)
{
    element[(i-1)*theColumns+j-1]=value;
}

template <class T>
inline T& Matrix<T>::get(int i, int j) const
{
    return element[(i-1)*theColumns+j-1];
}

//()重载
template <class T>
T& Matrix<T>::operator()(int i, int j) const
{
    if(i<1||i>theRows||j<1||j>theColumns)
        throw ("index out of bounds");
        
    return element[(i-1)*theColumns+j-1];
}

//=重载
template <class T>
inline Matrix<T> &Matrix<T>::operator=(const Matrix<T> &x)
{
    //不能赋值自己
    if(this!=&x)
    {
        delete[]element;
        theRows=x.theRows;
        theColumns=x.theColumns;
        element=new T[theRows*theColumns];
        copy(x.element,x.element+theRows*theColumns,element);
    }
    return *this;
}

//+重载
template <class T>
inline Matrix<T> Matrix<T>::operator+(const Matrix<T> &x) const
{
    if(theRows!=x.theRows||theColumns!=x.theColumns)
        throw ("matrix size not matching");

    Matrix<T>w(theRows,theColumns);
    for(int i=0;i<theColumns*theRows;i++)
        w.element[i]=element[i]+x.element[i];
    return w;
}

template <class T>
inline Matrix<T> Matrix<T>::operator*(const Matrix<T> &x) const
{
    if(theColumns!=x.theRows)
        throw("mismatch");

    Matrix<T>w(theRows,x.theColumns);

    int ct=0,cx=0,cw=0;
    //进行赋值
    for(int i=1;i<=theRows;i++)
    {
        //求出w中一行的元素
        for(int j=1;j<=x.theColumns;j++)
        {
            //先写出来第一项
            T sum=element[ct]*x.element[cx];
            for(int k=2;k<=theColumns;k++)
            {
                ct++;
                cx+=x.theColumns;
                sum+=element[ct]*x.element[cx];
            }
            w.element[cw++]=sum;
            ct=ct+1-theColumns;
            cx=j;
        }
        //行求完了,换下一行继续求
        ct+=theColumns;
        cx=0;
    }

    return w;
}

```

注意:自己构造矩阵类的时候,构造和析构函数都要被调用,且时间复杂度为O(theRows* theColumns)

## 4.3 特殊矩阵
分类
- 对角矩阵:当且仅当i!=j的时候,M(i,j)=0
- 三对角矩阵:当且仅当|i-j|>1的时候,M(i,j)=0
- 下三角矩阵:当且仅当i<j的时候,M(i,j)=0
- 上三角矩阵:当且仅当i>j的时候,M(i,j)=0
- 对称矩阵:M(i,j)=M(j,i)

图示
![image.png](http://verification.fengzhongzhihan.top/202312262319372.png)

### 4.3.1 对角矩阵
```c++
#include<iostream>
using namespace std;

template<class T>
class DiagonalMatrix
{
public:
    //构造析构函数
    DiagonalMatrix(int theN=10);
    ~DiagonalMatrix(){delete[]element;}
    void set(int i,int j,const T& value);
    T& get(int i,int j)const;
private:
    int n;
    T* element;
};

template <class T>
inline DiagonalMatrix<T>::DiagonalMatrix(int theN)
{
    if(theN<1)
        throw ("matrix size must be >0");

    n=theN;
    element=new T[n];
}   

template <class T>
inline void DiagonalMatrix<T>::set(int i, int j, const T &value)
{
    if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    if(i==j)
        element[i-1]=value;
    else
        if(value!=0)
            throw ("nondiagonal elements must be zero");
    return;
}

template <class T>
inline T &DiagonalMatrix<T>::get(int i, int j) const
{
    if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    if(i==j)
        return element[i-1];
    else
        return 0;
}


```
### 4.3.2 三对角矩阵

映射方式
![image.png|575](http://verification.fengzhongzhihan.top/202312262322129.png)

```c++
#include<iostream>
using namespace std;

template<class T>
class TriDiagonalMatrix
{
public:
    //构造析构函数
    TriDiagonalMatrix(int theN=10);
    ~TriDiagonalMatrix(){delete[]element;}
    void set(int i,int j,const T& value);
    T& get(int i,int j)const;
private:
    int n;
    T* element;
};

template <class T>
inline TriDiagonalMatrix<T>::TriDiagonalMatrix(int theN)
{
    if(theN<1)
        throw ("matrix size must be >0");
    n=theN;
    //n+n-1+n-1
    element=new T[3n-2];
}   

template <class T>
inline void TriDiagonalMatrix<T>::set(int i, int j, const T &value)
{
     if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    switch (i-j)
    {
        //低对角线
        case 1:
        {
            element[i-2]=value;
            break;
        }
        //主对角线
        case 0:
        {
            //n-1+i-1
            element[n+i-2]=value;
            break;
        }
        //高对角线
        case -1:
        {
            //n-1+n+i-1
            element[2*n+i-2]=value;
            break;
        }
        default:
        {
            break;
        }
    }

}

//按对角线从低到高排列
template <class T>
inline T &TriDiagonalMatrix<T>::get(int i, int j) const
{
    if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    switch (i-j)
    {
        //低对角线
        case 1:
        {
            return element[i-2];
            break;
        }
        //主对角线
        case 0:
        {
            //n-1+i-1
            return element[n+i-2];
            break;
        }
        //高对角线
        case -1:
        {
            //n-1+n+i-1
            return element[2*n+i-2];
            break;
        }
        default:
        {
            break;
        }
    }
}


```
### 4.3.3 下三角矩阵
```c++
#include<iostream>
using namespace std;

//下三角矩阵
template<class T>
class lowerTriangularMatrix
{
public:
    //构造析构函数
    lowerTriangularMatrix(int theN=10);
    ~lowerTriangularMatrix(){delete[]element;}
    void set(int i,int j,const T& value);
    T& get(int i,int j)const;
private:
    int n;
    T* element;
};

template <class T>
inline lowerTriangularMatrix<T>::lowerTriangularMatrix(int theN)
{
    if(theN<1)
        throw ("matrix size must be >0");
    n=theN;
    //n+n-1+n-1
    element=new T[n*(n+1)/2];
}   

template <class T>
inline void lowerTriangularMatrix<T>::set(int i, int j, const T &value)
{
     if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    if(i>=j)
    {
        element[i*(i-1)/2+j-1]=value;
        //按列映射则
        //element[(2n-(j-2))*(j-1)/2+i-j]=value;
    }
    else 
    {
        if(value!=0)
            throw("elements not in lower triangle must be zero");
    }
}
```

对称矩阵即对称的上/下三角矩阵,则同样的用三角矩阵存储即可
### 4.3.4 上三角矩阵
```c++
//下三角矩阵
#include<iostream>
using namespace std;
template<class T>
class higherTriangularMatrix
{
public:
    //构造析构函数
    higherTriangularMatrix(int theN=10);
    higherTriangularMatrix(const higherTriangularMatrix<T>& s);
    ~higherTriangularMatrix(){delete[]element;}
    int size()const {return n;}
    void set(int i,int j,const T& value);
    T get(int i,int j)const;
    void output(ostream& out);
private:
    int n;
    T* element;
};

template <class T>
inline higherTriangularMatrix<T>::higherTriangularMatrix(int theN)
{
    if(theN<1)
        throw ("matrix size must be >0");
    n=theN;
    //1+2+...+n
    element=new T[n*(n+1)/2];
}

//拷贝构造很重要
template <class T>
inline higherTriangularMatrix<T>::higherTriangularMatrix(const higherTriangularMatrix<T> &s)
{
    this->n=s.n;
    int len=n*(n+1)/2;
    element=new T[len];
    copy(s.element,s.element+len,element);
}

template <class T>
inline void higherTriangularMatrix<T>::set(int i, int j, const T &value)
{
     if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    if(i<=j)
    {
        element[(2*n-(i-2))*(i-1)/2+j-i]=value;
 //按列映射则element[(1 + (j - 1))(j - 1) / 2 + i - 1]=value;
    }
    else 
    {
        if(value!=0)
            throw("elements not in lower triangle must be zero");
    }
}

template <class T>
inline T higherTriangularMatrix<T>::get(int i, int j) const
{
    if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    if(i<=j)
        return element[(2*n-i+2)*(i-1)/2+j-i];
    else
        return 0;
}

template <class T>
inline void higherTriangularMatrix<T>::output(ostream& out)
{
    for(int i=1;i<=size();i++)
    {
        for(int j=1;j<=size();j++)
            out<<get(i,j)<<" ";
        out<<endl;
    }
}

```
## 4.4 稀疏矩阵
sparse matrix
- 默认,元素个数小于n^2/3为稀疏
	- 则上三角矩阵仍为稠密矩阵
	- n 对角矩阵,三对角矩阵（n×n）：稀疏矩阵

### 4.4.1 稀疏矩阵的加法
```c++
template <class T>
void SparseMatrix<T>::operator+(SparseMatrix<T> &b)
{
    if(rows!=b.rows||cols!=b.cols)
    {
        cout<<"-1"<<endl;
        *this=b;
        return;
    }
    SparseMatrix<T>c;
    c.reSetSize(rows,cols);
    int i=0,j=0;
    int n=terms.size();
    int m=b.terms.size();
    while(i<n&&j<m)
    {
        auto k1=terms.get(i);
        auto k2=b.terms.get(j);
        
        int idx1=k1.row*cols+k1.col;
        int idx2=k2.row*cols+k2.col;

        if(idx1<idx2)
        {
            c.terms.push_back(k1);
            i++;
        }
        else if(idx1==idx2)
        {
            MatrixTerms<T>mTerm;
            mTerm.row=k1.row;
            mTerm.col=k1.col;
            mTerm.value=k1.value+k2.value;
            c.terms.push_back(mTerm);
            i++,j++;
        }
        else
        {
            c.terms.push_back(k2);
            j++;
        }
    }
    //补充剩下的
    while(i<n)
    {
        c.terms.push_back(terms.get(i));
        i++;
    }
    while(j<m)
    {
        c.terms.push_back(b.terms.get(j));
        j++;
    }
    
    *this=c;
}
```
### 4.4.2 稀疏矩阵乘法
```c++
template <class T>
inline void SparseMatrix<T>::operator*(SparseMatrix<T> &b)
{
    if(cols!=b.rows)
    {
        cout<<"-1"<<endl;
        *this=b;
        return;
    }

    //结果矩阵
    SparseMatrix<T>c;
    c.reSetSize(rows,b.cols);

    //思路:按左矩阵的每一行列举,找到相同行的非零元素,找到对应列,再通过找到右矩阵相同行上的元素进行累加即可
    T rowSize[b.rows+1];
    T nextRow[b.rows+1];
    T answerRow[b.cols+1];

    for(int i=1;i<=b.rows;i++)
        rowSize[i]=0;

    for(int i=0;i<b.terms.size();i++)
    {
        auto k=b.terms.get(i);
        rowSize[k.row]++;
    }

    nextRow[1]=0;
    for(int i=2;i<=b.rows;i++)
        nextRow[i]=nextRow[i-1]+rowSize[i-1];

    int p=0;
    for(int i=1;p<terms.size()&&i<=rows;i++)
    {
        for(int k=1;k<=b.cols;k++)
            answerRow[k]=0;
        //左侧矩阵有该行元素,而且该元素右侧列有元素
        while(p<terms.size()&&terms.get(p).row==i)
        {
            if(rowSize[terms.get(p).col]!=0)
            {
                auto k=terms.get(p);
                for(int q=nextRow[k.col];q<nextRow[k.col]+rowSize[k.col];q++)
                {
                    auto tmp=b.terms.get(q);
                    answerRow[tmp.col]+=k.value*tmp.value;
                }
            }
            p++;
        }
        //将answer输入
        for(int j=1;j<=b.cols;j++)
        {
            if (answerRow[j]!=0)
            {
                MatrixTerms<T> mTerm;
                mTerm.col=j;
                mTerm.row=i;
                mTerm.value=answerRow[j];
                c.terms.push_back(mTerm);
            }
        }     
    }
    //把c赋给原矩阵
    *this=c;
}
```
### 4.4.3 稀疏矩阵转置
```c++
template <class T>
inline void SparseMatrix<T>::transpose()
{
    //只有转置矩阵的时候需要进行位置的选择
    //时间复杂度O(cols)
    SparseMatrix<T>b;
    b.reSetSize(cols,rows);

    int colSize[cols+1];
    int nextRow[cols+1];

    for(int i=1;i<=cols;i++)
        colSize[i]=0;

    for(int i=0;i<terms.size();i++)
    {
        auto k=terms.get(i);
        colSize[k.col]++;
    }

    nextRow[1]=0;
    for(int i=2;i<=cols;i++)
        nextRow[i]=nextRow[i-1]+colSize[i-1];

    for(int i=0;i<terms.size();i++)
    {
        auto k=terms.get(i);
        MatrixTerms<T>mTerm;
        mTerm.row=k.col;
        mTerm.col=k.row;
        mTerm.value=k.value;
        
        int index=nextRow[k.col]++;
        b.terms.set(index,mTerm);
    }

    *this=b;
};

```

### 4.4.4 稀疏矩阵链式存储
![image.png](http://verification.fengzhongzhihan.top/202312262352338.png)

# 5 栈
定义:一种特殊的线性表,插入和删除操作在表的的同一端进行,该端称为栈顶,另一端称为栈底

特性:先进后出(first in last out)

```c++
#include<iostream>
using namespace std;

template<class T>
class stack
{
    public:
    virtual ~stack(){}
    virtual bool empty() const =0;
    virtual int size()const =0;
    virtual T top()=0;
    virtual void pop()=0;
    virtual void push(const T& theElement)=0;
};
```
## 5.1 基于线性表数组描述的栈类

```c++
#include"stack.h"
#include"array_list.hpp"

template<class T>
class DerivedArrayStack :private arrayList<T>,public stack<T>
{
    public:
        DerivedArrayStack(int theCapacity=30):arrayList<T>(theCapacity){};   
        bool empty() const 
        {
            return arrayList<T>::empty();
        }
        int size()const
        {
            return arrayList<T>::size();
        }
        T top()
        {
            if(arrayList<T>::empty())
                throw stackEmpty();
            return arrayList<T>::get(arrayList<T>::size()-1);
        }
        void pop()
        {
            if(arrayList<T>::empty())
                throw stackEmpty();
            arrayList<T>::erase(arrayList<T>::size()-1);
        }
        void push(const T& theElement)
        {
            arrayList<T>::push_back(theElement);
        }
};
```
## 5.2 自己实现的数组描述栈
```c++
#include"stack.h"
#include"myExceptions.h"

template<class T>
class ArrayStack :public stack<T>
{
public:
    ArrayStack(int theCapacity=10);
    ~ArrayStack(){delete[] stack;}
    bool empty() const{return stackTop==-1;}
    int size()const {return stackTop+1;}
    T top()
    {
        if(stackTop==-1)
            throw stackEmpty();
        return stack[stackTop];
    }
    void pop()
    {
        if(stackTop==-1)
            throw stackEmpty();
        stack[stackTop--].~T();
    }
    void push(const T& theElement);
private:
    int stackTop;
    int arrayLength;
    T* stack;
};
template<class T>
void changeLength(T*& a,int oldLength,int newLength)
{
    if(newLength<0)
        throw illegalParameterValue("the newlength must >0");
    T *temp=new T[newLength];
    int size=min(oldLength,newLength);
    copy(a,a+size,temp);
    delete[]a;
    a=temp;
}

template <class T>
inline ArrayStack<T>::ArrayStack(int theCapacity)
{
    if(theCapacity<1)
        throw illegalParameterValue("Capacity must >0");
    arrayLength=theCapacity;
    stack=new T[theCapacity];
    stackTop=-1;
}

template <class T>
inline void ArrayStack<T>::push(const T &theElement)
{
    if(stackTop+1==arrayLength)
    {
        changeLength(stack,arrayLength,arrayLength*2);
        arrayLength*=2;
    }
    stack[++stackTop]=theElement;
}

```
## 5.3 基于线性表链式描述的栈类
```c++
#include"stack.h"
#include"extendedChain.hpp"
#include"myExceptions.h"

template<class T>
class DerivedChainStack :private extendedChain<T>,public stack<T>
{
    public:
        DerivedChainStack(int theCapacity=30):extendedChain<T>(theCapacity){};   
        bool empty() const 
        {
            return extendedChain<T>::empty();
        }
        int size()const
        {
            return extendedChain<T>::size();
        }
        T top()
        {
            if(extendedChain<T>::empty())
                throw stackEmpty();
            return extendedChain<T>::get(0);
        }
        void pop()
        {
            if(extendedChain<T>::empty())
                throw stackEmpty();
            extendedChain<T>::erase(0);
        }
        void push(const T& theElement)
        {
            extendedChain<T>::insert(0,theElement);
        }
};
```
## 5.4 自己实现的链表描述栈
```c++
#include"stack.h"
#include"chainNode.h"
#include"myExceptions.h"
template<class T>
class linkedStack:public stack<T>
{
public:
    linkedStack(int theCapacity=10)
    {
        stackTop=NULL;
        stackSize=0;
    }
    ~linkedStack();
    bool empty()const
    {
        return stackSize==0;
    }
    int size()const 
    {
        return stackSize;
    }
    T top()
    {
        if(stackSize==0)
            throw stackEmpty();
        return stackTop->element;
    }
    void pop();
    void push(const T& theElement)
    {
        stackTop=new chainNode<T>(theElement,stackTop);
        stackSize++;
    }

    void pushNode(chainNode<T>* theNode);
    T popNode();

private:
    int stackSize;
    chainNode<T>* stackTop;
};

template <class T>
inline linkedStack<T>::~linkedStack()
{
   while(stackTop!=NULL)
    {
        chainNode<T>* nextNode=stackTop->next;
        delete stackTop;
        stackTop=nextNode;
    }
}

 
template<class T>
inline void linkedStack<T>::pop()
{
    if(stackSize==0)
        throw stackEmpty();
    
    chainNode<T>* nextNode=stackTop->next;
    delete stackTop;
    stackTop=nextNode;
    stackSize--;
}

template <class T>
inline void linkedStack<T>::pushNode(chainNode<T> *theNode)
{
    theNode->next=stackTop;
    stackTop=theNode;
    stackSize++;
}

template <class T>
inline T linkedStack<T>::popNode()
{
    if(empty())
        throw stackEmpty();
    chainNode<T>* deleteNode=stackTop;
    T value=deleteNode->element;
    stackTop=stackTop->next;
    stackSize--;
    delete deleteNode;
    return value;
}

```

## 5.5 应用
### 5.5.1 括号匹配
```c++
#include"arrayStack.hpp"

void printMatchedPairs(string s)
{
    ArrayStack<int>stk;
    int length=s.size();

    for(int i=0;i<length;i++)
    {
        if(s[i]=='(')
            stk.push(i);
        else if(s[i]==')')
            try
            {
                cout<<stk.top()<<" "<<i<<endl;
                stk.pop();
            }
            catch(stackEmpty)
            {
                cout<<"No match for right pairs at "<<i<<endl;
            }
    }
    //输出剩下没有匹配的左括号
    while(!stk.empty())
    {
        cout<<"No match for left parenthesis at "<<stk.top()<<endl;
        stk.pop();
    }
}

int main()
{
    string str1("(a+b))))");
    printMatchedPairs(str1);
    string str2("(((aaa()))");
    printMatchedPairs(str2);
    return 0;
}
```

[[C++学习笔记]]
### 5.5.2 走迷宫
```c++
#include"arrayStack.hpp"
int n,m;
const int N=100;
bool st[N][N];
struct position
{
    int row,col;
};

bool findPath()
{
    ArrayStack<position> path;
    int nextRow,nextCol;
    position offset[4];
    offset[0].row=0;offset[0].col=1; //右
    offset[1].row=1;offset[1].col=0; //下
    offset[2].row=0;offset[2].col=-1; //左
    offset[3].row=-1;offset[3].col=0; //上

    //建立(n+2)*(n+2)的迷宫,给边界设置障碍
    for(int i=0;i<=n+1;i++)
    {
        st[0][i]=st[n+1][i]=1;
        st[i][0]=st[i][n+1]=1;
    }
    position here={1,1};
    int option=0,lastOption=3;
    while(here.row!=n||here.col!=n)
    {
        while(option<=lastOption)
        {
            nextRow=here.row+offset[option].row;
            nextCol=here.col+offset[option].col;
            if(!st[nextRow][nextCol])
                break;
            option++;
        }

        //找到了位置
        if(option<=lastOption)
        {
            path.push(here);
            here.row=nextRow;
            here.col=nextCol;
            st[nextRow][nextCol]=1;
            option=0;//继续选择
        }
        //没有找到位置
        else
        {
            if(path.empty())
                return false;
            
            position next=path.top();
            path.pop();

            //此时next是原来的位置,here
            //如果是左右平移,退回 下 上
            if(next.row==here.row)
                option=2+next.col-here.col;
            else 
                option=3+next.row-here.row;

            here=next;
        }
    }

    while(!path.empty())
    {
        cout<<path.top().row<<" "<<path.top().col<<endl;
        path.pop();
    }
    return true;
}


int main()
{
    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        st[x][y]=1;
    }
    if(findPath())
        cout<<"Success"<<endl;
    else 
        cout<<"Fairlure"<<endl;
    return 0;
}
```




### 5.5.3 列车车厢重排
```c++
#include"arrayStack.hpp"
const int N= 1e5+10;
ArrayStack<int>* track;
int numberOfCars,numberOfTracks,smallestCar,itsTrack,inputOrder[N];

bool putCarIntoHodingTrack(int);
void outputCarFromHodingTrack();

bool railRoadReset()
{
    track=new ArrayStack<int>[numberOfTracks+1];

    int nextCar=1;
    smallestCar=N;//随意初始化

    for(int i=1;i<=numberOfCars;i++)
    {
        //如果左侧的车厢是下一个需要输出的车厢,直接从左轨道移到右轨道
        if(inputOrder[i]==nextCar)
        {
            cout<<" move car "<<inputOrder[i]<<" from input track to output track"<<endl;
            nextCar++;

            //再判断轨道中能不能继续输出
            while(smallestCar==nextCar)
            {
                outputCarFromHodingTrack();
                nextCar++;
            }
        }
        //否则移到缓冲轨道
        else
        {
            if(!putCarIntoHodingTrack(inputOrder[i]))
                return false;
        }
    }
    return true;
}

bool putCarIntoHodingTrack(int inputValue)
{
    int bestTrack=0;
    int bestTop=numberOfCars+1;

    //找轨道
    for(int i=1;i<=numberOfTracks;i++)
    {
        if(!track[i].empty())
        {
            int t=track[i].top();
            if(t>inputValue&&t<bestTop)
            {
                bestTop=t;
                bestTrack=i;
            }
        }
        //如果有空轨道,且这个时候还没有找到轨道
        else 
            if(bestTrack==0)bestTrack=i;
    }

    //如果一直找不到轨道
    if(bestTrack==0)return false;

    //放东西
    track[bestTrack].push(inputValue);
    cout<<" move car "<<inputValue<<" from input track to holding track "<<bestTrack<<endl;
    //有无可能更新最小值
    if(inputValue<smallestCar)
    {
        smallestCar=inputValue;
        itsTrack=bestTrack;
    }
    return true;
}

void outputCarFromHodingTrack()
{
    cout<<" move car "<<smallestCar<<" from hoding track "<<itsTrack<<" to output track"<<endl;
    track[itsTrack].pop();
    //更新最小值
    smallestCar=N;
    for(int i=1;i<=numberOfTracks;i++)
    {
        if(!track[i].empty()&&track[i].top()<smallestCar)
        {
            smallestCar=track[i].top();
            itsTrack=i;
        }
    }
}

int main()
{
    cin>>numberOfCars>>numberOfTracks;
    for(int i=1;i<=numberOfCars;i++)
        cin>>inputOrder[i];
    if(railRoadReset())
    cout<<"reSet Successful"<<endl;
    else cout<<"reSet failure"<<endl;
    return 0;
}
```

### 5.5.4 汉诺塔问题
```c++
#include<iostream>
#include"arrayStack.hpp"
using namespace std;
//表示三个塔
ArrayStack<int>tower[4];

//递归算法
void towersOfHanoi(int n,int x,int y,int z)
{
    //将n盘子从x移到y中
    if(n>0)
    {
        towersOfHanoi(n-1,x,z,y);
        cout<<"move top disk from tower "<<x<<" to tower "<<y<<endl;
        towersOfHanoi(n-1,z,y,x);
    }
}

//栈实现
void moveAndShow(int n,int x,int y,int z)
{
    if(n>0)
    {
        moveAndShow(n-1,x,z,y);
        int d=tower[x].top();
        tower[x].pop();
        tower[y].push(d);
        moveAndShow(n-1,z,y,x);
    }
}
void towerOfHanoiWithStack(int n)
{
    for(int d=n;d>=1;d--)
        tower[1].push(d);
    moveAndShow(n,1,2,3);
    while(!tower[2].empty())
    {
        cout<<tower[2].top()<<endl;
        tower[2].pop();
    }
}




int main()
{
    towerOfHanoiWithStack(4);
    return 0;
}
```

# 6 队列

特点:先进先出
## 6.1 自己实现的数组描述
```c++
#include"extendedQueue.hpp"

template <class T>
class ExtendedArrayQueue :public Queue<T>,public ExtendedQueue<T>
{
    public:
    ExtendedArrayQueue(int theCapacity=10);
    ExtendedArrayQueue(){delete[] queue;}
    bool empty() const{return queueBack==queueFront;}
    bool full() const {return queueFront==(queueBack+1)%arrayLength;}
    int size()const {return (queueBack-queueFront+arrayLength)%arrayLength;}
    int capacity()const {return arrayLength;}
    T front()
    {
        if(empty())
            throw queueEmpty();
        return queue[(queueFront+1)%arrayLength];
    }
    T back()
    {
        if(empty())
            throw queueEmpty();
        return queue[queueBack];
    }
    void pop()
    {
        if(empty())
            throw queueEmpty();
        queueFront=(queueFront+1)%arrayLength;
        queue[queueFront].~T();
    }
    void push(const T& theElement);
    void doubleQueueLength();
    //新增ADT
    void inputQueue();
    void outputQueue();
    void devideQueue();
    void mergeQueue();
    void clear();
private:
    int queueFront;
    int queueBack;
    int arrayLength;
    T *queue;
};

template <class T>
inline ExtendedArrayQueue<T>::ExtendedArrayQueue(int theCapacity)
{
    if(theCapacity<1)
        throw illegalParameterValue("Capacity must >0");
    arrayLength=theCapacity;
    queue=new T[theCapacity];
    queueFront=queueBack=0;
}

template <class T>
inline void ExtendedArrayQueue<T>::push(const T &theElement)
{
    //扩容
    if(full())
    {
        doubleQueueLength();
    }
    queueBack=(queueBack+1)%arrayLength;
    queue[queueBack]=theElement;
}

template <class T>
inline void ExtendedArrayQueue<T>::doubleQueueLength()
{
    T* newQueue=new T[2*arrayLength];

    int start=(queueFront+1)%arrayLength;
    //未形成环形
    if(start<2)
        copy(queue+start,queue+start+arrayLength-1,newQueue);
    //形成环形
    else
    {
        copy(queue+start,queue+arrayLength,newQueue);
        copy(queue,queue+queueBack+1,newQueue+arrayLength-start);
    }

    queueFront=2*arrayLength-1;
    queueBack=arrayLength-2;
    arrayLength*=2;
    delete[]queue;
    queue=newQueue;
}

template <class T>
inline void ExtendedArrayQueue<T>::inputQueue()
{
    T element;
    cin>>element;
    push(element);
}

template <class T>
inline void ExtendedArrayQueue<T>::outputQueue()
{
    for(int queueCurrent=(queueFront+1)%arrayLength;queueCurrent!=(queueBack+1)%arrayLength;queueCurrent=(queueCurrent+1)%arrayLength)
    {
        cout<<queue[queueCurrent]<<" ";
    }
    cout<<endl;
}

template <class T>
inline void ExtendedArrayQueue<T>::devideQueue()
{
    ExtendedArrayQueue<T>p1(10),p2(10);
    bool flag=true;
    for(int queueCurrent=(queueFront+1)%arrayLength;queueCurrent!=(queueBack+1)%arrayLength;queueCurrent=(queueCurrent+1)%arrayLength)
    {
        int t=queue[queueCurrent];
        if (flag)
        {
            p1.push(t);
            flag=false;
        }
        else 
        {
            p2.push(t);
            flag=true;
        }
    }
    cout<<"divide result"<<endl;
    cout<<"p1: "<<endl;
    p1.outputQueue();
    cout<<"p2: "<<endl;
    p2.outputQueue();
}

template <class T>
inline void ExtendedArrayQueue<T>::mergeQueue()
{
    clear();

    ExtendedArrayQueue<T>p1(10),p2(10);
    cout<<"enter numbers of values of p1 and p2"<<endl;
    int n,m;cin>>n>>m;
    cout<<"enter values of p1 and p2"<<endl;
    while(n--)p1.inputQueue();
    while(m--)p2.inputQueue();
    
    bool flag=true;
    while(!p1.empty()&&!p2.empty())
    {
        T value1=p1.front();
        T value2=p2.front();
        if(flag)
        {
            push(value1);
            p1.pop();
            flag=false;
        }
        else 
        {
            push(value2);
            p2.pop();
            flag=true;
        }
    }
    while(!p1.empty())
    {
        push(p1.front());
        p1.pop();
    }
    while (!p2.empty())
    {
        push(p2.front());
        p2.pop();
    }
    cout<<"merge result"<<endl;
    outputQueue();
}

template <class T>
inline void ExtendedArrayQueue<T>::clear()
{
    queueFront=queueBack=0;
}
```

# 7 散列
## 7.1 字典的链表实现

```c++
#pragma once
#include"dictionary.h"
#include"pairNode.h"
template<class K,class E>
class SortedChain:public Dictionary<K,E>
{
    public:
        bool empty()const
        {
            return chainSize==0;
        }
        int size()const
        {
            return chainSize;
        }
        pair<K,E>* find(const K& )const;
        void insert(const pair<K,E>&);
        void erase(const K&);
    private:
        PairNode<K,E>* firstNode=NULL;
        int chainSize=0;
};

template <class K, class E>
inline pair<K, E> *SortedChain<K, E>::find(const K &theKey) const
{
    PairNode<K,E>* currentNode=firstNode;
    while(currentNode!=NULL&&currentNode->element.first<theKey)
    {
        currentNode=currentNode->next;
    }
    //判断是否匹配
    if(currentNode!=NULL&& currentNode->element.first==theKey)
        return &currentNode->element;

    return NULL;
}

template <class K, class E>
inline void SortedChain<K, E>::insert(const pair<K, E> &thePair)
{
    int theKey=thePair.first;
    PairNode<K,E>*tp=NULL;
    PairNode<K,E>*p=firstNode;
    while(p!=NULL&&p->element.first<theKey)
    {
        tp=p;
        p=p->next;
    }

    //找到了相同关键字
    if(p!=NULL&&p->element.first==theKey)
    {
        p->element.second=thePair.second;
    }
    //没找到
    else 
    {
        PairNode<K,E> *newNode=new PairNode<K,E>(thePair,p);
        if(tp==NULL)
            firstNode=newNode;
        else 
        {
            tp->next=newNode;
        }
        chainSize++;
    }
    return ;
}

template <class K, class E>
inline void SortedChain<K, E>::erase(const K &theKey) 
{
    PairNode<K,E>*tp=NULL;
    PairNode<K,E>*p=firstNode;
    while(p!=NULL&&p->element.first<theKey)
    {
        tp=p;
        p=p->next;
    }
    //找到了
    if(p!=NULL&&p->element.first==theKey)
    {
        //找到了第一个结点
        if(tp==NULL)
            firstNode=p->next;
        else 
        {
            tp->next=p->next;
        }
        delete p;
        chainSize--;
    }
    //没找到
    else 
    {
        cout<<"no pair"<<endl;
        return ;
    }
}

```
## 7.2 字典和散列函数
字典:形如(key,value)的数对组成的集合
- key:关键字
- value:值
多重字典:两个或更多的数对可以有相同的key

访问字典数对的方式
- 随机访问(Random Access)
	- 按照给定关键字找数对
- 顺序访问(Sequential Access)
	- 按照关键字递增顺序逐个访问数对

理想散列
- 每个位置最多存放一个数对
- 初始化O(n),查找插入删除O(1)
- 理想情况下,时间复杂度O(1)
- 关键字范围太大的时候,无法按理想散列建立数组

散列函数和散列表
- 多个关键字映射到同一位置
- 桶(bucket):散列表中的每个位置
- 起始桶:k数对,f(k)
- 桶的数目:散列表长度或大小

常用散列函数
- f(k)=k%D(散列表大小)
- 位置索引0~D-1
- D为素数/没有小于20的素数因子  性能最佳

冲突
- 两个不同的关键字对应的起始桶相同时
溢出
- 存储桶没有空间存储一个新数对

散列函数的好坏(是否为良好散列函数)
- 均匀散列函数:
- 映射到任意一个桶里的关键字数目大致相同

## 7.3 线性探查法解决溢出问题
在寻找下一个可用桶的时候,散列表视为环形表

搜索(search)
- 找到了k
- 到达一个空桶(不存在)    策略2:空桶的neverUsed=true
- 回到起始点f(k)(不存在)

删除(erase) 保证搜索的方法
- 策略1:移动删除结点后的若干元素
- 策略2:增加域neverUsed,若删除,不改变neverUsed,插入元素的时候neverUsed=true
	- 为了提高性能,很多neverUsed域都被置为false的情况下,必须重新组织散列表

```c++
#pragma once
#include<iostream>
using namespace std;
#include"myExceptions.h"

template<class K,class E>
class hashTable
{
public:
    hashTable(int theDivisor);
    ~hashTable(){delete[]table;}
    bool empty()const {return dSize==0;}
    int size()const {return dSize;}
    
    int searchIndex(const K&theKey)const;
    pair<K,E>* findPair(const K&theKey)const;
    void insert(const pair<K,E>& thePair);
private:
    hash<K> hash;
    pair<K,E>** table;
    int dSize;
    int divisor;
};

template <class K, class E>
inline hashTable<K, E>::hashTable(int theDivisor)
{
    divisor=theDivisor;
    dSize=0;

    table =new pair<K,E>* [divisor];
    for(int i=0;i<divisor;i++)
        table[i]=NULL;
}

//搜索对应的桶的编号
template <class K, class E>
inline int hashTable<K, E>::searchIndex(const K &theKey) const
{
    int i=(int)hash(theKey) %divisor;
    int j=i;
    do
    {
        if(table[j]==NULL||table[j]->first==theKey)
            return j;
        j=(j+1)%divisor;
    } while (j!=i);
    //如果表已经满了,回到了原来的位置
    return j;
}

//找到对应的pair
template <class K, class E>
inline pair<K, E> *hashTable<K, E>::findPair(const K &theKey) const
{
    int b=searchIndex(theKey);
    //没有找到
    if(table[b]!=NULL&&table[b]->first==theKey)
        return table[b];
    else 
        return NULL;
}

template <class K, class E>
inline void hashTable<K, E>::insert(const pair<K, E> &thePair)
{
    int b=searchIndex(thePair.first);
    //有相关位置
    if(table[b]==NULL)
    {
        table[b]=new pair<K,E> (thePair);
        dSize++;
    }
    else
    {
        //检查是有相同的关键字,还是表满了
        if(table[b]->first==thePair.first)
        {
            table[b]->second=thePair.second;
        }
        else
        {
            throw hashTableFull();
        }
    }
}

```


## 7.4 链表散列
通过创建数组table[divisor],每个元素是类sortedChain
```c++
#pragma once
#include"sortedChain.hpp"

template<class K,class E>
class HashChains
{
public:
    HashChains(int theDivisor)
    {
        divisor=theDivisor;
        dSize=0;
        table=new SortedChain<K,E>[divisor];
    }
    ~HashChains()
    {
        delete[] table;
    }
    bool empty()const
    {
        return dSize==0;
    }
    int size()const
    {
        return dSize;
    }
    pair<K,E>* findPair(const K&theKey)const
    {
        return table[hash(theKey)%divisor].find(theKey);
    }
    void insert(const pair<K,E>& thePair)
    {
        int homeBucket=(int)hash(thePair.first)%divisor;
        int homeSize=table[homeBucket].size();
        table[homeBucket].insert(thePair);
        if(table[homeBucket].size()>homeSize)
            dSize++;
    }
    void erase(const K& theKey)
    {
        table[hash(theKey)%divisor].erase(theKey);
    }
    void output(ostream& mout)const
    {
        for(int i=0;i<divisor;i++)
            if(table[i].size()==0)
                mout<<"NULL"<<endl;
            else
                mout<<table[i]<<endl;
    }

private:
    int divisor;
    SortedChain<K,E>* table;
    int dSize;
    hash<K>hash;
};

template<class K,class E>
ostream& operator<<(ostream &mout,const HashChains<K,E>&x)
{
    x.output(mout);return mout;
}

```


# 8 二叉树和其他树
## 8.1 术语
二叉树和树不是同一个数据结构

树定义:
- 非空的有限元素的集合(不能为空)
- 子树是无序的!

树术语
- 层次中最高层称为根
- 根的下一级元素:孩子
- 没有孩子的元素称为叶子
- 级:树根级为1,孩子级=父母级+1
- 元素的度:孩子数目
- 树的度:最大元素度

二叉树定义
- 有限个元素的合集(可以为空)
- 子树之间是有顺序的!

二叉树术语
- 满二叉树:高度为h的二叉树恰好有2^n-1个元素
- 完全二叉树:从右下依此删除元素

二叉树性质
1. 包含n个元素的二叉树边数为n-1
2. 高度为h的二叉树,最少有h个元素,最多有2^h-1个元素
3. n个元素的二叉树,树高度最多为n,最小为log(n+1) (向上取整)
4. n个元素的完全二叉树,树高度为log(n+1)(向上取整)
5. 任一元素为i,则若存在,则左孩子编号为2i,右孩子为2i+1,父节点为(i/2)向下取整

## 8.2 数组描述
有n个元素的二叉树需要空间为n~2^n-1
- 右斜树浪费的空间最多
- 仅当缺少的元素数目比较少的时候,这种描述方法才比较有用

## 8.3 链表描述
设置节点
- 左孩子,右孩子,值

一共有2n-(n-1)=n+1的指针域没有值
- 因为边数为n-1

```c++
#pragma once
#include"binaryTreeNode.h"
#include"binaryTree.h"
#include"arrayQueue.hpp"

template<class E>
class LinkedBinaryTree:public BinaryTree<BinaryTreeNode<E>>
{
    public:
        LinkedBinaryTree()
        {
            root=NULL;
            treeSize=0;
            visit=output;
        }
        ~LinkedBinaryTree()
        {
            erase();
        }
        void createTreeByLevel();
        bool empty() const
        {
            return treeSize==0;
        }
        int size()const
        {
            return treeSize;
        }
        //遍历函数,传入visit函数指针
        void preOrder(void (*theVisit) (BinaryTreeNode<E>*))
        {
            visit=theVisit;preOrder(root);
        }
        void inOrder(void (*theVisit) (BinaryTreeNode<E>*))
        {
            visit=theVisit;inOrder(root);
        }
        void postOrder(void (*theVisit) (BinaryTreeNode<E>*))
        {
            visit=theVisit;postOrder(root);
        }
        void leverOrder(void (*theVisit) (BinaryTreeNode<E>*))
        {
            visit=theVisit;leverOrder(root);
        }
        void preOrderOutput()
        {
            preOrder(output);
            cout<<endl;
        }
        void inOrderOutput()
        {
            inOrder(output);
            cout<<endl;
        }
        void postOrderOutput()
        {
            postOrder(output);
            cout<<endl;
        }
        void leverOrderOutput()
        {
            leverOrder(output);
            cout<<endl;
        }
        void erase()
        {
            postOrder(dispose);
            root=NULL;
            treeSize=0;
        }
        int height() const
        {
            return height(root);
        }

        void makeTree(const E& theElement,LinkedBinaryTree<E>&a,LinkedBinaryTree<E>&b);

    private:
        BinaryTreeNode<E>* root;
        int treeSize;
        //定义函数指针,规定如何访问元素
        static void (*visit)(BinaryTreeNode<E>*);
        static void preOrder(BinaryTreeNode<E>*t);
        static void inOrder(BinaryTreeNode<E>*t);
        static void postOrder(BinaryTreeNode<E>*t);
        static void leverOrder(BinaryTreeNode<E>*t);
        static void output(BinaryTreeNode<E>*t)
        {
            cout<<t->element<<" ";
        }
        static void dispose(BinaryTreeNode<E>*t)
        {
            delete t;
        }
        static int height(BinaryTreeNode<E>*t)
        {
            if(t==NULL)
                return 0;
            int hl=height(t->leftChild);
            int hr=height(t->rightChild);
            if(hl>hr)
                return ++hl;
            else 
                return ++hr;
        }
        
};


template<class E>
void (*LinkedBinaryTree<E>::visit)(BinaryTreeNode<E>*);

template <class E>
inline void LinkedBinaryTree<E>::createTreeByLevel()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    ArrayQueue<BinaryTreeNode<E>*>q;
    
    int index=0;
    root=new BinaryTreeNode<E> (a[index++]);
    q.push(root);
    BinaryTreeNode<E>* p=NULL;
    while(!q.empty()&&index<n)
    {
        p=q.front();
        q.pop();
        //如果不空就创建一个节点
        BinaryTreeNode<E>* leftNode=new BinaryTreeNode<E>(a[index++]);
        p->leftChild=leftNode;
        q.push(leftNode);
        treeSize++;

        if(index<n)
        {
            BinaryTreeNode<E>* rightNode=new BinaryTreeNode<E>(a[index++]);
            p->rightChild=rightNode;
            q.push(rightNode);
            treeSize++;
        }
    }
}

template <class E>
inline void LinkedBinaryTree<E>::preOrder(BinaryTreeNode<E> *t)
{   
    if(t!=NULL)
    {
        LinkedBinaryTree::visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

template <class E>
inline void LinkedBinaryTree<E>::inOrder(BinaryTreeNode<E>*t)
{   
    if(t!=NULL)
    {
        inOrder(t->leftChild);
        LinkedBinaryTree<E>::visit(t);
        inOrder(t->rightChild);
    }
}

template <class E>
inline void LinkedBinaryTree<E>::postOrder(BinaryTreeNode<E>*t)
{   
    if(t!=NULL)
    {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        LinkedBinaryTree<E>::visit(t);
    }
}

template <class E>
inline void LinkedBinaryTree<E>::leverOrder(BinaryTreeNode<E>*t)
{   
    ArrayQueue<BinaryTreeNode<E>*> q;
    while(t!=NULL)
    {
        visit(t);

        if(t->leftChild!=NULL)
            q.push(t->leftChild);
        if(t->rightChild!=NULL)
            q.push(t->rightChild);
        
        if(!q.empty())
        {
            t=q.front();
            q.pop();
        }
        else
            return;
    }
}

template <class E>
inline void LinkedBinaryTree<E>::makeTree(const E &theElement, LinkedBinaryTree<E> &a, LinkedBinaryTree<E> &b)
{
    BinaryTreeNode<E>* tmp=b.root;
    root=new BinaryTreeNode<E> (theElement,a.root,tmp);
    treeSize=a.treeSize+b.treeSize+1;

    a.root=b.root=NULL;
    a.treeSize=b.treeSize=0;
}
//我们一般从最右下角开始向上编号,这样才能保证置空后的树不会被使用到
```

## 8.4 应用

设置信号放大器

degradeFromParent(i) —— 节点i 与其父节点间的衰减量
- If degradeFromParent(i)＞容忍值，则不可能通过在节点i处放置放大器来使信号的衰减不超过容忍值。

degradeToLeaf(i) —— 从节点i 到以i 为根节点的子树的任一叶子的衰减量的最大值。
- 若i 为叶节点， 则degradeToLeaf(i) = 0
- 对其它节点i， degradeToLeaf(i)= max{degradeToLeaf(j) +degradeFromParent (j) } : j 是i的孩子

```c++
template <class E>
inline void LinkedBinaryTree<E>::placeBoosters(BinaryTreeNode<E> *x)
{
    x->element.degradeToLeaf=0;
    BinaryTreeNode<booster>* y=x->leftChild;
    //左子树找
    if(y!=NULL)
    {
        int degradation=y->element.degradeToLeaf+y->element.degradeFromParent;
        if(degradation>tolerance)
        {
            y->element.boosterHere=true;
            x->element.degradeToLeaf=y->element.degradeFromParent;
        }
        else
        {
            x->element.degradeToLeaf=degradation;
        }
    }

    y=x->rightChild;
    if(y!=NULL)
    {
        int degradation=y->element.degradeToLeaf+y->element.degradeFromParent;
        if(degradation>tolerance)
        {
            y->element.boosterHere=true;
            degradation=y->element.degradeFromParent;
        }
        x->element.degradeToLeaf=max(x->element.degradeToLeaf,degradation);
    }
}
```

## 8.5 森林转换

森林 : 0棵或者多棵树的集合

森林 -> 二叉树转化
- 先得到每棵树的二叉树描述
	- 方法 : 左孩子指向第一个孩子, 右孩子指向下一个兄弟
- 第i棵作为第i-1棵树的右子树

![image.png](http://verification.fengzhongzhihan.top/202401042130733.png)


二叉树 -> 树转化
![image.png](http://verification.fengzhongzhihan.top/202401042133387.png)

**二叉树 -> 森林转化**
二叉树转换为森林比较简单，其步骤如下：
（1）从根节点开始, 把每个结点与右孩子结点的连线删除，得到
分离的二叉树；
（2）把分离后的每棵二叉树转换为树；
（3）整理第（2）步得到的树，使之规范，这样得
到森林。
# 9 优先级队列

定义:
0个或多个元素的集合:每个元素都有一个优先级或值
分为最大/最小优先级队列

操作:
- 查找
- 插入
- 删除
其中查找和删除都是针对最大/最小优先级的元素

## 9.1 线性表描述
以最大优先级为例

无序线性描述
- 数组
	- 插入O(1):表尾
	- 删除O(n):查找优先级最大的
- 链表
	- 插入O(1):表头
	- 删除O(n):查找优先级最大的

有序线性描述
- 数组(递增)
	- 插入:O(n)
	- 删除:O(1)
- 链表(递减)
	- 插入O(n)
	- 删除O(1)

## 9.2 堆描述
大根树(最大树)
- 每个节点的值都>=其子节点的值
- 注意此时不要求为二叉树:子节点个数可以大于2

大根堆
- 满足两个条件
	- 完全二叉树
	- 大根树

在样例里我们用一维数组描述堆
- ![image.png|475](http://verification.fengzhongzhihan.top/202311021640065.png)

大根堆插入和删除的复杂度均为Olog2n(树的高度)
- 大根堆删除最小值

大根堆初始化(将一颗二叉树转化为大根堆)
- 时间复杂度O(n)
- 进行n次插入操作为O(nlogn)
```c++
#pragma once
#include"maxPriorityQueue.h"
template<class T>
class MaxHeap:public MaxPriorityQueue<T>
{
public:
    MaxHeap(int arraySize)
    {
        arrayLength=arraySize;
        heap=new T[arrayLength];
        heapSize=0;
    }
    ~MaxHeap()
    {
        delete[] heap;
    }
    void push(const T& theElement);
    void pop();
    const T& top()
    {
        return heap[1];
    }
    int size()const
    {
        return heapSize;
    }
    bool empty()const
    {
        return heapSize==0;
    }
    void initialize(T* theHeap,int heapSize);
    void output(ostream& out)const
    {
        for(int i=1;i<=heapSize;i++)
            out<<heap[i]<<" ";
    }

private:
    T *heap;
    int arrayLength;
    int heapSize;
};

template<class T>
void doubleArraySize(T*& heap,int arrayLength)
{
    T* newArray=new T[arrayLength*2];
    copy(heap,heap+arrayLength,newArray);
    delete []heap;
    heap=newArray;
}

//时间复杂度,高度logn
template <class T>
inline void MaxHeap<T>::push(const T &theElement)
{
    //数组满,扩大数组
    if(heapSize==arrayLength-1)
    {
        doubleArraySize(heap,arrayLength);
        arrayLength*=2;
    }
    
    //父节点下沉
    int currentNode=++heapSize;
    while(currentNode!=1&&heap[currentNode/2]<theElement)
    {
        heap[currentNode]=heap[currentNode/2];
        currentNode/=2;
    }

    heap[currentNode]=theElement;
}

//时间复杂度logn,为高度h
template <class T>
inline void MaxHeap<T>::pop()
{
    if(heapSize==0)
    {
        cout<<"heap empty"<<endl;
        return;
    }
    
    heap[1].~T();
    T lastElement=heap[heapSize--];

    int currentNode=1,child=2;

    while(child<=heapSize)
    {
        if(child<heapSize&&heap[child+1]>heap[child])
            child++;

		//可以把lastElement放入heap[currentNode]吗
        if(lastElement>=heap[child])
            break;

        heap[currentNode]=heap[child];
        currentNode=child;
        child*=2;
    }
    heap[currentNode]=lastElement;
}

//传入一个根结点和结点数量
template<class T>
inline void MaxHeap<T>::initialize(T* theHeap,int theHeapSize) 
{
    heap=theHeap;
    heapSize=theHeapSize;//5
    for(int root=heapSize/2;root>=1;root--)
    {
        T element=heap[root];
        int cur=root;
        int child=cur*2;

        while(child<=heapSize)
        {
            if(child<heapSize&&heap[child+1]>heap[child])
                child++;
            //可以把element放入cur的位置吗, 不能则孩子上移
            if(element>=heap[child])
                break;
            
            heap[cur]=heap[child];
            cur=child;
            child*=2;
        }

        heap[cur]=element;
    }
}

template<class T>
ostream & operator<<(ostream& out,const MaxHeap<T> &x)
{
    x.output(out);return out;
}


```
## 9.3 左高树
适用 : 
- 合并两个优先队列或者多个长度不同的队列

分类
- HBLT
- WBLT

扩充二叉树:拥有外部节点
- 外部:代替树中的空子树
- 内部:其余结点

s(x)含义:从节点x到子树的外部节点中所有路径最短的一条
- 若x为外部节点s(x)=0
- 若x为内部节点s(x)=min(s[L],s[R])+1

高度优先左高树(HBLT)(height-biased leftist tree)
- 每一个内部节点的左孩子的s大于等于右孩子的s

最大HBLT:
- 满足HBLT的同时是大根树
- 不要求为完全二叉树

性质
(a)以x 为根的子树的节点数目至少2 ^ s(x) – 1
(b)若以x 为根的子树有m 个节点，则s(x)最多为
log2(m+1)
(c)通过最右路径(即，此路径是从x 开始沿右孩子移动)
从x 到达外部节点的路径长度为s(x) .

w(x)含义:子树的内部节点数
重量优先左高树(WBLT)(weight-biased leftist tree)
- 每一个内部节点的左孩子的w值大于等于右孩子的w值
- 若x为内部节点，其重量为其孩子节点的重量之和加1

最大WBLT(weight-biased leftist tree)
- 同时是大根树
- 不要求为完全二叉树

最大HBLT的操作

合并操作 (复杂度O(n))
![image.png](http://verification.fengzhongzhihan.top/202401042214776.png)
```c++
#pragma once
#include"linkedBinaryTree.hpp"
#include"maxPriorityQueue.h"
template<class T>
class MaxHblt:public LinkedBinaryTree<pair<int,T>>
{
    public:
        using LinkedBinaryTree<pair<int,T>>::treeSize;
        using LinkedBinaryTree<pair<int,T>>::root;
        using LinkedBinaryTree<pair<int,T>>::postOrder;
        using LinkedBinaryTree<pair<int,T>>::inOrder;
        using LinkedBinaryTree<pair<int,T>>::visit;


        bool empty()
        {
            return treeSize ==0;
        }
        int size()
        {
            return treeSize;
        }
        const T& top()
        {
            if(treeSize==0)
                return 0;
            return root->element.second;
        }
        void pop()
        {
            if(treeSize==0)
                return;
            BinaryTreeNode<pair<int,T>> * left=root->leftChild;
            BinaryTreeNode<pair<int,T>> * right=root->rightChild;
            delete root;
            meld(left,right);
            root=left;
            treeSize--;
        }
        void push(const T& theElement)
        {
            BinaryTreeNode<pair<int,T>> * newNode=new BinaryTreeNode<pair<int,T>>(pair<int,T>(1,theElement));
            meld(root,newNode);
            treeSize++;
        }
        void meld(MaxHblt<T>& theHblt)
        {
            meld(root,theHblt.root);
            treeSize+=theHblt.treeSize;
            theHblt.root=NULL;
            theHblt.treeSize=0;
        }
        void initilize(T* theHeap,int theSize);
        void postOrderOutput()
        {
            postOrder(hbltOutput);
            cout<<endl;
        }
        void inOrderOutput()
        {
            inOrder(hbltOutput);
            cout<<endl;
        }
    private:
        void meld(BinaryTreeNode<pair<int,T>>*&x,BinaryTreeNode<pair<int,T>>*&y);
        static void hbltOutput(BinaryTreeNode<pair<int,T>>* t)
        {
             cout<<"s:"<<t->element.first<<" "<<"value:"<<t->element.second<<" "<<endl;
        }
};

template <class T>
inline void MaxHblt<T>::meld(BinaryTreeNode<pair<int, T>> *&x, BinaryTreeNode<pair<int, T>> *&y)
{
    if(y==NULL)
        return;
    if(x==NULL)
    {
        x=y;
        return;
    }

    if(x->element.second<y->element.second)
        swap(x,y);
    
    meld(x->rightChild,y);

    //左子树为空或者右子树值比较大的时候需要更换
    if(x->leftChild==NULL)
    {
        x->leftChild=x->rightChild;
        x->rightChild=NULL;
        x->element.first=1;
    }
    else
    {
        if(x->leftChild->element.first<x->rightChild->element.first)
            swap(x->leftChild,x->rightChild);
        x->element.first=x->rightChild->element.first+1;
    }
}

template <class T>
inline void MaxHblt<T>::initilize(T *theHeap, int theSize)
{
    queue<BinaryTreeNode< pair<int,T> >*>q;
    //依此放入待排列的元素
    for(int i=0;i<theSize;i++)
    {
        q.push(new BinaryTreeNode<pair<int,T>>(pair<int,T>(1,theHeap[i])));
    }

    //进行排列,共需要theSize-1次,因为每次都相当于少了一个元素,最后还要剩下一个元素
    for(int i=0;i<theSize-1;i++)
    {
        BinaryTreeNode<pair<int,T>>* a=q.front();
        q.pop();
        BinaryTreeNode<pair<int,T>>* b=q.front();
        q.pop();
        meld(a,b);
        q.push(a);
    }

    if(theSize>0)
        root=q.front();
    treeSize=theSize;
}

```
## 9.4 应用
### 9.4.1 堆排序
```c++
#include<iostream>
#include"maxHeap.hpp"
using namespace std;

template<class T>
void heapSort(T* a,int n)
{
    MaxHeap<T>heap(1);
    heap.initialize(a,n);
    for(int i=n;i>=1;i--)
    {
        T x=heap.top();
        heap.pop();
        a[i]=x;
    }

    heap.deactiveArray();
}

#include"heapSort.hpp"

int main()
{
    int a[6]={0,3,6,4,2,9};
    heapSort(a,5);
    for(int i=1;i<=5;i++)
    {
        cout<<a[i]<<" ";
    }
}
```

### 9.4.2 霍夫曼编码
基于LZW算法
- 蓝波-立夫-卫曲编码法（Lempel-Ziv-Welch，缩写_LZW_），是以色列科学家亚伯拉罕·蓝波、杰可布·立夫与美国学者泰瑞·卫曲共同提出的一种无损数据压缩_算法_。

Huffman code
目的:压缩文本空间

如何设计霍夫曼编码(可变长编码)
- 当每个字符出现的频率很大变化的的时候,可以通过可变长来降低编码串长度
- 若使用可变长编码，编码需要满足 : 没有任何一个代码是另一代码的前缀

>举例 : aaxuaxz:
频率: a:3 x:2 u:1 z:1
编码: a:0 x:10 u:110 z:111
n aaxuaxz: 0010110010111

![image.png|425](http://verification.fengzhongzhihan.top/202401042231092.png)


WEP(加权外部路径长度)
- 计算公式:ΣL(i)* F(i),i代表每一个外部节点,L(i)代表根到i的路径长度,F(i)是字符i出现的频率

霍夫曼树
- 若给定频率,WEP最小,则这棵树称为霍夫曼树

构造方法
1. 初始化二叉树集合，每个二叉树含一个外部节点，每个外部节点代表字符串中一个不同的字符.
2. 从集合中选择两棵具有最小权值的二叉树，并把它们合并成一棵新的二叉树。合并方法是把这两棵二叉树分别作为左右子树，然后增加一个新的根节点。新二叉树的权值为两棵子树的权值之和。
3. 重复第2步，直到仅剩下一棵树为止。

```c++
#include"HuffmanNode.h"
#include"minHeap.hpp"

//huffmanNode 包括tree和weight
template<class T>
class HuffmanNode
{
    public:
    LinkedBinaryTree<int>* tree;
    T weight;

    operator T()const {return weight;}
};

//构造huffmantree
template <class T>
LinkedBinaryTree<int>* createHuffmanTree(T weight[],int n)
{
    //初始化huffmanNode
    HuffmanNode<T>* hnode=new HuffmanNode<T>[n+1];
    LinkedBinaryTree<int> emptyTree;
    for(int i=1;i<=n;i++)
    {
        int tmp=weight[i];
        hnode[i].weight=tmp;
        hnode[i].tree=new LinkedBinaryTree<int>;
        hnode[i].tree->makeTree(i,emptyTree,emptyTree);
    }

    MinHeap<HuffmanNode<T>>heap(1);
    heap.initialize(hnode,n);

    HuffmanNode<T>w,x,y;
    LinkedBinaryTree<int>* z;
    for(int i=1;i<n;i++)
    {
        x=heap.top();heap.pop();
        y=heap.top();heap.pop();

        z=new LinkedBinaryTree<int>;
        z->makeTree(0,*x.tree,*y.tree);
        w.weight=x.weight+y.weight;
        w.tree=z;
        heap.push(w);

        delete x.tree;
        delete y.tree;
    }

    return heap.top().tree;
}

```

示例
![image.png](http://verification.fengzhongzhihan.top/202401042234269.png)


# 10 二叉搜索树
定义 : 适合于描述字典的树形结构。

%% 时间优势体现在
- 查找,插入,删除平均logn,最坏n,升序输出n,找到最接近k的关键字操作时间n,对于散列表来说n+D
- 给dictionary加入以下操作,则散列平均性能不是很好
	- 输出字典元素(1)
	- 按升序找到第k个元素(2)
	- 删除第k个元素等等(3)
- 操作(1) 链表:D+nlogn,nlogn排序,n输出 线性探查:b+nlogn
- 操作(2)  链表O(D+n),线性探查O(b)
 %%
> 若使用平衡搜索树,则操作(1): O(n)  索引平衡搜索树:操作(2) O(logn)

二叉搜索树是二叉树,可能为空
-  每个元素的关键字都是唯一的
		- 若有重复值,称为有重复值的二叉搜索树
	- 左子树上的所有值<根结点的值<右子树上的所有值
	- 根的左右都是二叉搜索树

索引二叉搜索树
- 元素多一个域leftsize:表示左子树的元素个数'
![image.png](http://verification.fengzhongzhihan.top/202311150859554.png)

## 10.1 二叉搜索树

删除的三种情况
1. p 是树叶；
2. p 只有一个非空子树；
3. p 有两个非空子树。

```c++
#include"linkedBinaryTree.hpp"
#include"bsTree.h"

template<class K,class E>
class BinarySearchTree:public LinkedBinaryTree<pair<K,E>>,
                        public BSTree<K,E>
{
    public:
        using LinkedBinaryTree<pair<K,E>>::inOrderOutput;
        using LinkedBinaryTree<pair<K,E>>::treeSize;
        using LinkedBinaryTree<pair<K,E>>::root;
        void ascend()
        {
            inOrderOutput();
        }
        bool empty()const
        {
            return treeSize==0;
        }
        int size()const
        {
            return treeSize;
        }
        pair<K,E>* find(const K& theKey)const;
        void erase(const K& theKey);
        void insert(const pair<K,E>& thePair);
        void BSSort(BinaryTreeNode<pair<K,E>> *t);
};

template <class K, class E>
inline pair<K, E> *BinarySearchTree<K, E>::find(const K &theKey) const
{
    
    BinaryTreeNode<pair<K,E>>*p=root;
    while(p!=NULL)
    {
        if(theKey<p->element.first)
            p=p->leftChild;
        else if(theKey>p->element.first)
            p=p->rightChild;
        else 
            return &p->element;
    }
    return NULL;
    
}

template <class K, class E>
inline void BinarySearchTree<K, E>::insert(const pair<K, E> &thePair)
{
    BinaryTreeNode<pair<K,E>>* p=root,*pp=NULL;
    int theKey=thePair.first;
    while(p!=NULL)
    {
        pp=p;
        if(theKey<p->element.first)
        {
            p=p->leftChild;
        }
        else if(theKey>p->element.first)
        {
            p=p->rightChild;
        }
        else 
        {
            p->element.second=thePair.second;
            return;
        }
    }

    BinaryTreeNode<pair<K,E>>* newNode=new BinaryTreeNode<pair<K,E>>(thePair);
    if(root!=NULL)
    {
        if(theKey<pp->element.first)
        {
            pp->leftChild=newNode;
        }
        else 
        {
            pp->rightChild=newNode;
        }
    }
    else 
    {
        root=newNode;
    }
    treeSize++;
}

template <class K, class E>
inline void BinarySearchTree<K, E>::erase(const K &theKey)
{
    BinaryTreeNode<pair<K,E>>* p=root,*pp=NULL;
    while(p!=NULL&&theKey!=p->element.first)
    {
        pp=p;
        if(theKey<p->element.first)
        {
            p=p->leftChild;
        }
        else if(theKey>p->element.first)
        {
            p=p->rightChild;
        }
    }
    if(p==NULL)
    {
        return ;
    }
    //两个孩子都不为空
    if(p->leftChild!=NULL&&p->rightChild!=NULL)
    {
        //找到左孩子的最大值
        BinaryTreeNode<pair<K,E>>* s=p->leftChild,*ps=p;
        //沿着右孩子搜
        while (s->rightChild!=NULL)
        {
            ps=s;
            s=s->rightChild;
        }
        
        //先建立q结点
        BinaryTreeNode<pair<K,E>>* q=new BinaryTreeNode<pair<K,E>>
        (s->element,p->leftChild,p->rightChild);
        //给q找到位置
        if(pp==NULL)
            root=q;
        else if(p==pp->leftChild)
            pp->leftChild=q;
        else 
            pp->rightChild=q;

        //因为马上要删除p,所以不能将ps直接赋给pp,而是将q赋给pp.因为q->leftchild==s
        if(p==ps)
            pp=q;
        else 
            pp=ps;
        
        delete p;
        p=s;
    }
    //此时p最多只有一个孩子
    BinaryTreeNode<pair<K,E>>*c=NULL;
    if(p->leftChild!=NULL)
        c=p->leftChild;
    else   
        c=p->rightChild;
    
    if(p==root)
        root=c;
    else if(p==pp->leftChild)
        pp->leftChild=c;
    else 
        pp->rightChild=c;
    treeSize--;
    delete p;
}
```

## 10.2 索引二叉搜索树
```c++
#include"indexedBSTree.h"
#include"linkedBinaryTree.hpp"
#include "IdxNode.h"



template<class K,class E>
class IndexedBinarySearchTree:public indexedBSTree<K,E>,public LinkedBinaryTree<IdxNode<K,E>> 
{   
    public:
        using LinkedBinaryTree<IdxNode<K,E>>::inOrderOutput;
        using LinkedBinaryTree<IdxNode<K,E>>::treeSize;
        using LinkedBinaryTree<IdxNode<K,E>>::root;
        pair<K,E>* get(int theIndex)const;
        void eraseWithIndex (int theIndex);
        bool empty()const
        {
            return treeSize==0;
        }
        int size()const
        {
            return treeSize;
        }
        pair<K,E>* find(const K& theKey)const;
        void erase(const K& theKey);
        void insert(const pair<K,E>& thePair);
};

template <class K, class E>
inline pair<K, E>  *IndexedBinarySearchTree<K, E>::get(int theIndex)const
{
    BinaryTreeNode<IdxNode<K,E>>*p=root;
    while(p!=NULL&&p->element.index!=theIndex)
    {
        if(theIndex<p->element.index)
            p=p->leftChild;
        else if(theIndex>p->element.index)
        {
            theIndex=theIndex-p->element.index-1;
            p=p->rightChild;
        }
    }
    if(p==NULL)
        return NULL;
    else 
        return &(p->element.pair);
}

template <class K, class E>
inline void IndexedBinarySearchTree<K, E>::eraseWithIndex(int theIndex)
{
    BinaryTreeNode<IdxNode<K,E>>*p=root,*pp=NULL;
    while(p!=NULL&&p->element.index!=theIndex)
    {
        pp=p;
        if(theIndex<p->element.index)
        {
            p->element.index--;
            p=p->leftChild;
        }
        else if(theIndex>p->element.index)
        {
            theIndex=theIndex-p->element.index-1;
            p=p->rightChild;
        }
    }
    if(p==NULL)
        return ;

    if(p->leftChild!=NULL&&p->rightChild!=NULL)
    {
        //找到左孩子的最大值
        BinaryTreeNode<IdxNode<K,E>>* s=p->leftChild,*ps=p;
        //沿着右孩子搜
        while (s->rightChild!=NULL)
        {
            ps=s;
            s=s->rightChild;
        }
        
        //先建立q结点
        BinaryTreeNode<IdxNode<K,E>>* q=new BinaryTreeNode<IdxNode<K,E>>
        (s->element,p->leftChild,p->rightChild);
        //给q找到位置
        if(pp==NULL)
            root=q;
        else if(p==pp->leftChild)
            pp->leftChild=q;
        else 
            pp->rightChild=q;

        //因为马上要删除p,所以不能将ps直接赋给pp,而是将q赋给pp.因为q->leftchild==s
        if(p==ps)
            pp=q;
        else 
            pp=ps;
        
        delete p;
        p=s;
    }
    //此时p最多只有一个孩子
    BinaryTreeNode<IdxNode<K,E>>*c=NULL;
    if(p->leftChild!=NULL)
        c=p->leftChild;
    else   
        c=p->rightChild;
    
    if(p==root)
        root=c;
    else if(p==pp->leftChild)
        pp->leftChild=c;
    else 
        pp->rightChild=c;
    treeSize--;
    delete p;
}

template <class K, class E>
inline pair<K, E> *IndexedBinarySearchTree<K, E>::find(const K &theKey) const
{
    BinaryTreeNode<IdxNode<K,E>>*p=root;
    while(p!=NULL)
    {
        if(theKey<p->element.pair.first)
            p=p->leftChild;
        else if(theKey>p->element.pair.first)
            p=p->rightChild;
        else 
            return &p->element.pair;
    }
    return NULL;
}

template <class K, class E>
inline void IndexedBinarySearchTree<K, E>::erase(const K &theKey)
{
    BinaryTreeNode<IdxNode<K,E>> * p=root,*pp=NULL;
    while(p!=NULL&&p->element.pair.first!=theKey)
    {
        pp=p;
        if(theKey<p->element.pair.first)
        {
            p->element.index--;
            p=p->leftChild;
        }
        else 
            p=p->rightChild;
    }

    if(p==NULL)
        return;
    
    if(p->leftChild!=NULL&&p->rightChild!=NULL)
    {
        //找到左孩子的最大值
        BinaryTreeNode<IdxNode<K,E>>* s=p->leftChild,*ps=p;
        //沿着右孩子搜
        while (s->rightChild!=NULL)
        {
            ps=s;
            s=s->rightChild;
        }
        
        //先建立q结点
        BinaryTreeNode<IdxNode<K,E>>* q=new BinaryTreeNode<IdxNode<K,E>>
        (s->element,p->leftChild,p->rightChild);
        //给q找到位置
        if(pp==NULL)
            root=q;
        else if(p==pp->leftChild)
            pp->leftChild=q;
        else 
            pp->rightChild=q;

        //因为马上要删除p,所以不能将ps直接赋给pp,而是将q赋给pp.因为q->leftchild==s
        if(p==ps)
            pp=q;
        else 
            pp=ps;
        
        delete p;
        p=s;
    }
    //此时p最多只有一个孩子
    BinaryTreeNode<IdxNode<K,E>>*c=NULL;
    if(p->leftChild!=NULL)
        c=p->leftChild;
    else   
        c=p->rightChild;
    
    if(p==root)
        root=c;
    else if(p==pp->leftChild)
        pp->leftChild=c;
    else 
        pp->rightChild=c;
    treeSize--;
    delete p;
}

template <class K, class E>
inline void IndexedBinarySearchTree<K, E>::insert(const pair<K, E> &thePair)
{
    BinaryTreeNode<IdxNode<K,E>>* p=root,*pp=NULL;
    int theKey=thePair.first;

    while(p!=NULL)
    {
        pp=p;
        if(theKey<p->element.pair.first)
        {
            p->element.index++;
            p=p->leftChild;
        }
        else if(theKey>p->element.pair.first)
        {
            p=p->rightChild;
        }
        else
        {
            p->element.pair.second=thePair.second;
            return;
        }
    }

    IdxNode<K,E> tmp={0,pair<K,E>(thePair)};
    BinaryTreeNode<IdxNode<K,E>>* newNode=new BinaryTreeNode<IdxNode<K,E>> (tmp);

    if(pp!=NULL)
    {
        if(pp->leftChild==p)
            pp->leftChild=newNode;
        else if(pp->rightChild==p)
            pp->rightChild=newNode;
    }
    else
        root=newNode;

    treeSize++;
}

```

# 11 平衡搜索树

优化:二叉搜索树的最坏情况是O(n),平衡搜索树最坏情况还是O(logn)

## 11.1 AVL树

AVL(Adelson-Velsky和Landis1962年提出)

平衡树: 最坏情况下高度为O(logn)的树

AVL树(可以为空)
- TL和TR是AVL树
- |hL-hR|<=1
- 二叉树

AVL搜索树
- 既是二叉搜索树,也是AVL树
- 索引AVL搜索树:加上index

AVL树高度(斐波那契数列)
- 设高度为h,Nh是最少的节点数,则满足
	- Nh=F(h+2)-1
	- Nh=Nh-1 + Nh-2 + 1 N0=0, N1=1
	- F0 = 0, F1 = 1, F2 =1 ,F3 = 2 
- 得Nh![image.png](http://verification.fengzhongzhihan.top/202401051105117.png)

- 若树中有n个结点,则树的最大高度为![image.png](http://verification.fengzhongzhihan.top/202311211138064.png)
- 最小高度 ：log2 (n+1).

节点X：在插入前，我们从根节点往下移动寻找新元素的插入位置时，从根节点到新元素的路径上，最后一个遇到的平衡因子是-1或1的节点.
![image.png](http://verification.fengzhongzhihan.top/202401051116932.png)
- 若x不存在, 则不会产生不平衡现象
- 

### 11.1.1 AVL树的插入
- LL:在左子树的左子树插入
![image.png](http://verification.fengzhongzhihan.top/202311211139938.png)
此时该子树的高度不发生改变,不会影响其他地方的平衡因子
- LR:在左子树的右子树插入
![image.png](http://verification.fengzhongzhihan.top/202311211141649.png)

此时该子树的高度不发生改变,不会影响其他地方的平衡因子
- RR
- RL

### 11.1.2 AVL树的删除
- R0:删除右子树,此时左子树的结点为B的平衡因子为0,同LL旋转
![image.png|500](http://verification.fengzhongzhihan.top/202311211145451.png)
此时该子树的高度不发生改变,不会影响其他地方的平衡因子

- R1:删除右子树,此时左子树的结点为B的平衡因子为1,同LL旋转
![image.png](http://verification.fengzhongzhihan.top/202311211146476.png)

此时该子树的高度-1,会影响其他地方的平衡因子,需要考虑再次进行旋转,旋转次数为O(logn)
- R-1:删除右子树,此时左子树的结点为B的平衡因子为-1,同LR旋转
![image.png|500](http://verification.fengzhongzhihan.top/202311211146839.png)
此时该子树的高度-1,会影响其他地方的平衡因子,需要考虑再次进行旋转,旋转次数为O(logn)

## 11.2 B-树

用处:磁盘索引顺序访问文件

### 11.2.1 m叉搜索树

m叉搜索树:可以是一个空树,如果非空需要满足
- 含有p个元素的结点有p+1个孩子
- 每个结点最多有m-1个元素,m个孩子
- 结点中的元素有序,且指向的子树的关键字都小于,小于等于,或大于元素

搜索
- 到达外部节点就没搜到
- 磁盘访问次数 : 搜索深度

插入
- 若结点满,则生成新结点成为孩子

删除
- 若删除叶子结点,直接删除即可
- 若删除不是叶子结点
	- 用相邻的非空左子树的最大值或右子树最小值来替换他(可套娃)


$高度为h,则最少有h个元素,最多有(m^h-1)/(m-1)个结点,每个结点有m-1个元素共有 m^h-1个元素$
$反过来,一个有n个元素的m叉搜索树,高度[logm(n+1)),n]$

### 11.2.2 m阶B树

扩展树满足条件
- 是m叉搜索树
- 根节点至少两个孩子
- 根结点之外,所有内部结点至少有m/2(向上取整)个孩子
- 所有外部结点在同一层

特殊
- 2-3搜索树:3阶
- 满二叉树:2阶

高度为h的m阶B树,元素个数为n满足
![image.png](http://verification.fengzhongzhihan.top/202311211201058.png)

![image.png](http://verification.fengzhongzhihan.top/202311211202574.png)
从第二层开始等比数列计算

插入
- 先搜索到外部结点,然后直接合并
- 如果已经满了.取中间向上裂开
- 磁盘访问次数 : 搜索深度 + 分裂次数* 2 + 1
	- 1的含义 : 回写新的根节点或插入后没有导致分裂的节点

删除(两种情况)
- 叶结点
	- 元素个数大于最少数,直接删除
	- 元素个数等于最少数
		- 用邻近的左兄弟和右兄弟来借一个,注意要先和父节点交换
		- 如果借不了:则将与父节点元素合并
		- 删除10 / 删除44

![image.png|450](http://verification.fengzhongzhihan.top/202311211213800.png)
![image.png|450](http://verification.fengzhongzhihan.top/202311211213941.png)
![image.png|450](http://verification.fengzhongzhihan.top/202311211215004.png)


- 非叶结点
	- 转化为叶结点,用左子树最大或右子树最小来替换,再删除叶结点即可
- 磁盘访问次数
	- 搜索深度 + 获取相邻兄弟读的次数 + 修改的节点个数


# 12 图
## 12.1 术语

**边和顶点**
G=(V,E) (顶点集,  边集)
- 顶点,节点,点
- 边,弧,连线
- (i,j)表示一条无向边,称为i,j是邻接的,(i,j)关联于i,j
- (i,j)表示有向边,i邻接至j,j邻接于i ,边关联至j,  关联于i

无向边:(i,j)(j,i)相同
有向边:(i , j )和(j, i)不同

无向图:所有的边都是无向边,  简称为图

有向图:所有边都是有向边  ,简称为有向图

网络:加权有向图(无向图), 每一条边都有对应权重
- 所有图都可以看作网络的一种特殊情况

**路径**

简单路径:路径中所有顶点均不相同(第一个和最后一个顶点可以相同)

路径长度:所有边的长度和

i到j的最短路径:路径长度最短的路径


**生成树**

连通图:当且仅当G(无向图)中每一对顶点之间都有一条路径,称为连通图

子图:顶点和边均是G的子集

环路:起始节点和结束节点  相同 的简单路径

树: 没有环路的无向连通图

树的cost : 所有边cost之和

度di
- 无向图中: 与顶点i相连的边的数目
	- n个顶点  e条边  则di之和为2e  0<=e<=n*(n-1)/2
	- 有n*(n-1)/2个e的 图是完全无向图
- 有向图中: 
	- 分为入度和出度
	- 入度和出度的和分别为e
	- 0<=e<=n*(n-1)
	- 有n*(n-1)个e的 图是完全有向图

图的生成树: 包含G中所有顶点且是G的子图的树
- n个顶点  n-1条边
- 最小生成树(最小代价生成树)

## 12.2 图的存储

抽象类graph
```c++
#pragma once
#include<iostream>
using namespace std;
#include"edge.h"
#include"vertexIterator.h"
template<class T>//权的类型
class graph
{
    public:
        virtual ~graph(){};

        virtual int numberOfVertices()const=0;
        virtual int numberOfEdges()const =0;
        virtual bool existsEdge(int ,int )const =0;
        virtual void insertEdge(Edge<T>* )=0;
        virtual void eraseEdge(int ,int)=0;
        virtual int inDegree(int) const =0;
        virtual int outDegree(int )const =0;

        virtual bool directed()const =0;
        virtual bool weighted()const =0;
        virtual VertexIterator<T>* iterator(int )=0;

};
```

图的存储方法
- 邻接矩阵
- 邻接链表
- 邻接数组

图的类型分为
- 无向有权(无权)
- 有向有权(无权)

因此共有3* 4种实现方法

### 12.2.1 邻接矩阵(有权)

特性
- A(i,i)=0 
- 对称(无向图才有)
- 每一行或每一列的数值总和都表示出度或入度

对于无向图,最优化方法 : 只存储上三角或下三角元素

插入和删除都O(1)
找出入度和出度O(n)
```c++
#pragma once
#include"graph.h"
#include"edge.h"
#include"vertexIterator.h"
#include<iostream>
using namespace std;

template <class T>
void make2dArray(T ** &x, int numberOfRows, int numberOfColumns)
{
    x = new T * [numberOfRows];
    
    // get memory for each row
    for (int i = 0; i < numberOfRows; i++)
        x[i] = new int [numberOfColumns];
}


template<class T>
class AdjacencyWDigraph :public graph<T>
{

    protected:
        int n;
        int e;
        T ** arr;
        T noEdge;

    public:
        bool checkVertex(int theVertex)const 
        {
            if(theVertex>=1&&theVertex<=n)
                return true;
            else 
                return false;
        }
        AdjacencyWDigraph(int numberOfVertices=0, T theNoEdge=0)
        {
            if(numberOfVertices<0)
            {
                cout<<"wrongVertices"<<endl;
                return;
            }
            n=numberOfVertices;
            e=0;
            noEdge=theNoEdge;
            make2dArray(arr,n+1,n+1);

            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    arr[i][j]=noEdge;
            }
        }
        int numberOfVertices()const
        {
            return n;
        }
        int numberOfEdges()const
        {
            return e;
        }
        bool existsEdge(int i,int j)const
        {
            if(checkVertex(i)&&checkVertex(j)&&arr[i][j]!=noEdge)
                return true;
            else
                return false;
        }
        void insertEdge(Edge<T>* theEdge)
        {
            int v1=theEdge->vertex1();
            int v2=theEdge->vertex2();
            if(checkVertex(v1)&&checkVertex(v2))
            {
                if(arr[v1][v2]==noEdge)
                     e++;
                arr[v1][v2]=theEdge->weight();
            }
        }
        void eraseEdge(int i,int j)
        {
            if(checkVertex(i)&&checkVertex(j)&&arr[i][j]!=noEdge)
            {
                arr[i][j]=noEdge;
                e--;
            }
            else 
            {
                cout<<"no right edge"<<endl;
                return;
            }
        }

        int inDegree(int theVertex) const
        {
            if(checkVertex(theVertex))
            {
                int sum=0;
                for(int j=1;j<=n;j++)
                    if(arr[j][theVertex]!=noEdge) 
                        sum++;

                return sum;
            }
            return 0;
        }

        int outDegree(int theVertex)const
        {
            if(checkVertex(theVertex))
            {
                int sum=0;
                for(int j=1;j<=n;j++)
                    if(arr[theVertex][j]!=noEdge) 
                        sum++;

                return sum;
            }
            return 0;
        }

        bool directed()const
        {
            return true;
        }

        bool weighted()const
        {
            return true;
        }
        class myIterator:public VertexIterator<T>
        {
            public:
                myIterator(T * theRow,T theNoEdge, int numberOfVertices)
                {
                    row=theRow;
                    noEdge=theNoEdge;
                    n=numberOfVertices;
                    currentVertex=1;
                }

                ~myIterator(){}

                int next(T & theWeight)
                {
                    //寻找下一个邻接顶点,并找出对应的权
                    for(int j=currentVertex;j<=n;j++)
                    {
                        if(row[j]!=noEdge)
                        {
                            currentVertex=j+1;
                            theWeight=row[j];
                            return j;
                        }
                    }
                    //找不到邻接节点了
                    currentVertex=n+1;
                    return 0;
                }

                int next()
                {
                    //寻找下一个邻接顶点,并找出对应的权
                    for(int j=currentVertex;j<=n;j++)
                    {
                        if(row[j]!=noEdge)
                        {
                            currentVertex=j+1;
                            return j;
                        }
                    }
                    //找不到邻接节点了
                    currentVertex=n+1;
                    return 0;
                }

            protected:
                T* row; //找到某个顶点的对应的行
                T noEdge;
                int n;
                int currentVertex;
        };

        myIterator* iterator(int theVertex)
        {
            if(checkVertex(theVertex))
                return new myIterator(arr[theVertex],noEdge,n);
            else 
                return NULL;
        }
};

```

### 12.2.2 邻接表(无权)

邻接表是一个线性表, 每一个顶点元素都对应着一个线性表

链表描述
- alist[i].firstNode指向顶点i的邻接表的第一个顶点  (i,element)就是图的一条有向边

邻接数组
- 相对于邻接链表少用4m个字节(无指针域)
- 数组的用时要小于链表

```c++
#include"edge.h"
#include"graph.h"
#include"graphChain.h"

class LinkedDigraph:public graph<bool>
{
    protected:
        int n;
        int e;
        GraphChain<int> *aList; //邻接表

    public:
        LinkedDigraph(int numberOfVertices=0)
        {
            if(numberOfVertices<0)
            {
                cout<<"wrong"<<endl;
                return;
            }
            n=numberOfVertices;
            e=0;
            aList= new GraphChain<int> [n+1];
        }

        ~LinkedDigraph(){delete[] aList;}
        
        int numberOfVertices()const
        {
            return n;
        }

        int numberOfEdges()const
        {
            return e;
        }    

        bool existsEdge(int i,int j)const
        {
            if(i>=1&&i<=n&&j>=1&&j<=n&&aList[i].indexOf(j)!=-1)
                return true;
            else 
                return false;
        }

        void insertEdge(Edge<bool>* theEdge)
        {
            int v1=theEdge->vertex1();
            int v2=theEdge->vertex2();
            //新边才插入
            if(aList[v1].indexOf(v2)==-1)
            {
                e++;             
                aList[v1].insert(0,v2);
            }
        }

        void eraseEdge(int i,int j)
        {

            if(i>=1&&i<=n&&j>=1&&j<=n)
            {
                int *v=aList[i].eraseElement(j);
                if(v!=NULL)
                    e--;
            }
        }

        int inDegree(int theVertex) const
        {
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                if(aList[i].indexOf(theVertex)!=-1)
                    sum++;
            }
            return sum;
        }
        int outDegree(int theVertex)const
        {
            if(theVertex>=1&&theVertex<=n)
                return aList[theVertex].size();
            else 
                return 0;
        }
        bool directed()const
        {
            return true;
        }
        bool weighted()const
        {
            return false;
        }
        class myIterator : public VertexIterator<bool>
      {
         public:
            myIterator(chainNode<int> *theNode) 
            {
                currentNode = theNode;
            }
      
            ~myIterator() {}
      
            int next()
            {
               if (currentNode == NULL)
                  return 0;
               int nextVertex = currentNode->element;
               currentNode = currentNode->next;
               return nextVertex;
            }
      
            int next(bool& theWeight)
            {
               if (currentNode == NULL)
                  return 0;
               int nextVertex = currentNode->element;
               currentNode = currentNode->next;
               theWeight = true;
               return nextVertex;
            }
      
         protected:
            chainNode<int> *currentNode;
      };

      myIterator* iterator(int theVertex)
      {// Return iterator for vertex theVertex.
            if(theVertex>=1&&theVertex<=n)
                return new myIterator(aList[theVertex].firstNode);
            else 
                return NULL;
      }
};
```

无权边
```c++
#pragma once
#include<iostream>
#include"edge.h"
using namespace std;

class UnWeightedEdge: public Edge<bool>
{
    public:
        int vertex1() const
        {
            return v1;
        }
        int vertex2() const
        {
            return v2;
        }
        UnWeightedEdge(int v1,int v2)
        {
            this->v1=v1;
            this->v2=v2;
        }
        bool weight()const 
        { 
            return false;
        }

    protected:
        int v1,v2;
};
```
## 12.3 图的遍历
### 12.3.1 dfs
深度优先搜索(DFS----Depth-First Search)

```c++
virtual void dfs(int v,int reach[],int lable)
{
	this->reach=reach;
	this->lable=lable;
	rdfs(v);
}

void rdfs(int v)
{
	reach[v]=lable;
	VertexIterator<T>* iv=iterator(v);
	int u;
	while((u=iv->next())!=0)
	{
		//没有被遍历过
		if(reach[u]==0)
			rdfs(u);    
	}
	delete iv;
}
```
### 12.3.2 bfs
广度优先搜索 : BFS----Breadth-First Search
```c++
  virtual void bfs(int v,int reach[],int lable)
        {
            queue<int>q ;
            reach[v]=lable;
            q.push(v);

            while(!q.empty())
            {
                int w=q.front();
                q.pop();

                VertexIterator<T>* iw =iterator(w);

                int u;
                while((u=iw->next())!=0)
                {
                    if (reach[u] == 0)
                    {
                        q.push(u);
                        reach[u]=lable;
                    }
                }
                delete iw;
            }
        }
```

区别![image.png](http://verification.fengzhongzhihan.top/202311292154415.png)

## 12.4 应用
### 12.4.1 寻找一条路径
```c++
//成功找到返回Path,否则返回NULL
int * findPath(int theSource, int theDestination)
{
	//初始化
	desitination=theDestination;
	int n=numberOfVertices();
	path=new int [n+1];     
	reach=new int [n+1];
	for(int i=0;i<=n;i++)
	{
		reach[i]=0;
		path[i]=0;
	}
	path[1]=theSource;
	length=1;
	//找到一条路径,则将path[0]更新为边长
	if(theSource==theDestination||dfs(theSource))
	{
		path[0]=length-1;
	}
	else 
	{
		delete[]path;
		path=NULL;
	}

	delete []reach;
	return path;
}

bool dfs(int s)
{
	reach[s]=1;
	VertexIterator<T>* is=iterator(s);

	int u;
	while((u=is->next())!=0)
	{
		if(reach[u]==0)
		{
			path[++length]=u;
			if(u==desitination||dfs(u))
				return true;
			//如果没有找到从u开始的路径,就把length--,继续找下一个u
			length--;
		}
	}

	delete is;
	return false;
}
```
### 12.4.2 连通图

标记无向图的构件

```c++
int lableComponents(int c[])
{
	int n=numberOfVertices();

	for(int i=1;i<=n;i++)
		c[i]=0;
	
	lable=0;
	//遍历所有元素
	for(int i=1;i<=n;i++)
	//如果没有被标记
	if(c[i]==0)
	{
		lable++;
		bfs(i,c,lable);
	}
	return lable;
}
```

# 13 贪心算法
最优化问题
- 存在限制条件和优化函数
- 符合限制条件的一组解称为可行解
- 使得优化函数出现最佳解的可行解称为最优解

## 13.1 0-1背包问题

优化函数max(ΣXiPi)
约束条件 Σwixi<=c  ,  xi∈{0,1}

## 13.2 拓扑排序

使得i->j的情况下, i始终在j的前面
思想:将所有入度为0的点挑出来,放入拓扑序列
```c++
 bool topologicalOrder(int *theOrder)
{
	int n=numberOfVertices();
	int *inDegree=new int [n+1];
	fill(inDegree+1, inDegree+1+n, 0);

	//遍历每一个点
	for(int i=1;i<=n;i++)
	{
		VertexIterator<T> *ii= iterator(i);
		//初始化InDegree
		int u;
		while((u=ii->next())!=0)
		{
			inDegree[u]++;
		}
	}

	stack<int> s;
	for(int i=1;i<=n;i++)
	{
		if(inDegree[i]==0)
			s.push(i);
	}
	int j=0;
	while(!s.empty())
	{
		int t=s.top();
		s.pop();
		theOrder[j++]=t;

		VertexIterator<int>* ii=iterator(t);
		int u;
		while((u=ii->next())!=0)
		{
			inDegree[u]--;
			if(inDegree[u]==0)
				s.push(u);
		}
	}  

	return j==n;
}
```
## 13.3 dijkstra算法

distanceFromSource[i]：
在当前已产生的最短路径中加入一条边,从而使得扩充的路径到达顶点i的最短长度。

数组predecessor[]:存储最短路径
- predecessor[i]——从sourceVertex到达i的路径中, 顶点i前面的那个顶点。 
- 可以通过这个读出对应的路径
>本例中predecessor[1:5] = [0, 1, 1, 3, 4], 从i = 5开始， predecessor[5]=4, predecessor[4]=3, predecessor[3] =1 = sourceVertex, 因此路径 1 3 4 5 , 

表newReachableVertices : 存储所有predecessor > 0 的顶点
- 从中选择并删除distanceFromSource值最小的顶点i
- 更新i的邻接点 j的distanceFromSource 为 min{distanceFromSource[j],
distanceFromSource[i] +a[i]  [j] ;


[ 1)]初始化
distanceFromSource[i] = a[sourceVertex][i](1≤i≤n)，
predecessor[i] = sourceVertex, //邻接于sourceVertex的顶点
predecessor[sourceVertex] = 0；
predecessor[i] = -1; //其余的顶点
创建一个表newReachableVertices，保存所有predecessor[i]>0的顶点。
2) 当newReachableVertices为空时,算法停止,否则转至3);
3) 从newReachableVertices中选择并删除distanceFromSource值最小的顶点i。
4) 对于所有邻接于顶点i的顶点j, 更新distanceFromSource[j]值为
min{distanceFromSource[j], distanceFromSource[i] +a[i]  [j]}；

若distanceFromSource[j]改变，
则置predecessor[j]=i，而且，若j没有在表newReachableVertices中，则将j 加入newReachableVertices。

## 13.4 最小生成树
最小生成树: 有权无向图有n-1个边,包含n个顶点的树
### 13.4.1 prim算法
先将第一个顶点放入最小堆
如果堆不空,就取出堆头元素,如果没有遍历过这个元素,便放入最小生成树集合中,并更新相邻顶点的最小边权值，若可以更新,则将相邻顶点放入最小堆中,重复循环,直到堆空为止

Prim (普里姆)算法思想：
§ 从具有一个单一顶点(可以是原图中任意一个
顶点)的树T开始
§ 重复地加一条边和一个顶点.
Ø往T中加入一条代价最小的边(u,v) 使
TÈ{(u, v)}仍是一棵树.
Þ对于边(u,v) ， u 、v 中正好有一个顶点位
于T中.
§ 直到T 中包含n-1 条边为止.

![image.png](http://verification.fengzhongzhihan.top/202401102331410.png)


```c++
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
const int N=1e6+10;
int n,m;
int e[N],ne[N],w[N],h[N],idx;
int d[N];
bool st[N];
priority_queue<PII,vector<PII>,greater<PII>> heap;

void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}

long long  prim()
{
    long long  res=0;
    memset(d,0x3f,sizeof(d));
    d[1]=0;

    heap.push({0,1});

    while(!heap.empty())
    {
        auto t=heap.top();
        heap.pop();

        int val=t.second,dis=t.first;
        //取出该结点,包含到集合里面来
        if(!st[val])
        {   
            res+=dis;
            st[val]=true;
            //对于结点的每个边,都进行更新
            for(int i=h[val];i!=-1;i=ne[i])
            {
                int j=e[i];
                //如果距离发生更新, 则将边的结点放入heap中
                if(d[j]>w[i])
                {
                    d[j]=w[i];
                    heap.push({d[j],j});
                }
            }
        }
    }
    
    return res;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        {
            add(x,y,z);
            add(y,x,z);
        }
    }
    
    cout<<prim();
    return 0;
}
```

### 13.4.2 cruskal算法
使用并查集来判断图中的节点是否属于同一个连通分量。
结构体 Edge 存储边的信息，包括边的两个端点和边权值。

对所有边按照权值从小到大进行排序。
遍历排序后的边，对于每条边的两个端点，若不在同一个连通分量中，则将它们合并，并将边的权值加入到最小生成树的权值之和中。若产生环路, 则放弃这条边 (如果在同一子图中就会产生环路, 否则不会产生)

开始，初始化含有n个顶点0条边的森林.
• Kruskal算法所使用的贪婪准则是：从剩下的边
中选择一条不会产生环路的具有最小耗费的边
加入已选择的边的集合中。
§ Kruskal算法分e步(e是网络中边的数目)。
§ 按耗费递增的顺序来考虑这e条边，每次考
虑一条边。
§ 当考虑某条边时，若将其加入到已选边的集
合中会出现环路，则将其抛弃，否则，将它
选入。

![image.png](http://verification.fengzhongzhihan.top/202401102324228.png)

```c++
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3e5+10;
const int M=2*N;
int n,m;
int idx;
//并查集
int p[N];

struct Edge
{
    int v1,v2,w;
}Edges[M];

int find(int x)
{
    if(p[x]!=x)
        p[x]=find(p[x]);
    return p[x];
}

bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}

long long  cruskal()
{
    long long  res=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
        p[i]=i;
    
    sort(Edges,Edges+idx,cmp);

    for(int i=0;i<idx;i++)
    {
        auto k=Edges[i];
        int a=k.v1,b=k.v2,c=k.w;

        a=find(a);b=find(b);

        if(a!=b)
        {
            p[a]=b;
            res+=c;
        }
    }
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    int a,b,c;
    while(m--)
    {
        cin>>a>>b>>c;
        Edges[idx++]=Edge{a,b,c};
    }

    cout<<cruskal()<<" ";
}
```

# 14 动态规划

## 14.1 0-1背包问题

![image.png|475](http://verification.fengzhongzhihan.top/202401052026563.png)
![image.png](http://verification.fengzhongzhihan.top/202401052029647.png)

```c++
int f(int i,int theCapacity)
{
	if (i == numberOfObjects)
		return(theCapacity < weight[numberOfObjects]? 
		0 :profit[i])
	if (theCapacity < weight[i])
		return f(i+1, theCapacity);
	return max(f(i+1, theCapacity), f(i+1, theCapacity - weight[i]) + profit[i]);
}

时间复杂度 O(2 ^ n)
```


## 14.2 Floyd算法

令c(i,j,k)表示从顶点i 到顶点j的最短路径的长度，其中该路径中允许经过的顶点编号都不大于k
则
![image.png](http://verification.fengzhongzhihan.top/202401052040922.png)

更新方式

![image.png](http://verification.fengzhongzhihan.top/202401052040150.png)

```c++
//寻找最短路径的长度
//初始化c(i，j，0)
for(int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	c(i,j,0)=a(i,j);//a是长度邻接矩阵
//计算c(i,j,k)(1≤k≤n)
for (int k = 1; k <= n; k++)
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (c(i,k,k-1) + c(k,j,k-1)< c(i,j,k-1) )
				c(i,j,k) = c(i,k,k-1) + c(k,j,k-1)
			else 
				c(i,j,k) = c(i,j,k-1)
```

令kay(i,j) 表示从i 到j 的最短路径中最大的k值。
• 初始, kay(i,j)=0 (最短路径中没有中间顶点).

优化方法
```c++
template<class T>
void Allpairs(T **c, int **kay)
{//所有点对的最短路径;对于所有i和j，计算c[i][j]和kay[i][j]
//初始化c[i][j]=c(i，j，0)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++){
		c[i][j]=a[i][j];
		kay[i][j]=0;}
	for (i=1;i<=n;i++)
		c[i][i]=0;

	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{if (c[i][k]!=NoEdge && c[k][j]!=NoEdge &&
		(c[i][j]==NoEdge || c[i][j] > c[i][k] + c[k][j]))
		{
			c[i][j]= c[i][k] + c[k][j];
			kay[i][j]=k;
		}
	}
}
```

最终求出来对应的路径点有哪些
已知kay矩阵
 : 1-7最大点为8, 则1-8最大点为5, 8-7最大点为6, ...找到最大点为0说明两点相邻
![image.png](http://verification.fengzhongzhihan.top/202401052050204.png)

```c++
template<class T>
void outputPath(T **c, int **kay, T noEdge, int i, int j)
{// 输出从i 到j的最短路径
	if (c[i][j] = = noEdge) {
	cout << "There is no path from " << i << " to " << j <<
	endl;
	return;}
	cout << "The path is" << endl;
	cout << i << ' ';
	outputPath(kay, i, j);
	cout << endl;
}

void outputPath(int **kay, int i, int j)
{//输出i 到j 的路径的实际代码
// 不输出路径上的第一个顶点(i)
	if (i = = j) return;
	if (kay[i][j] = = 0) //路径上没有中间顶点
	cout<<j << ' ';
	else {// kay[i][j]是路径上的中间顶点
	outputPath(kay, i, kay[i][j]);
	outputPath(kay, kay[i][j], j);}
}
```

# 15 课程设计

## 15.1 外排序

![image.png](http://verification.fengzhongzhihan.top/202404082238563.png)

基本思路 : k路归并, n个元素
1. 先找出顺串
2. 根据元素个数将顺串的元素提取出来, 并进行取最小值, 放入输出序列, 再从外存中读入元素, 依此往复
3. 时间复杂度为O(nk)

使用竞赛树可以简化为O(k + nlogk)

归并趟数, 影响与外存的IO, 大小为
$$[\log_k{M}]$$
优化方法
- 降低M : 初始顺串有方法
- 增大K : 但也会增大内排序消耗, 需要权衡

## 15.2 竞赛树

定义 : 
- 完全二叉树
- 具有n个外部节点和n-1个内部结点
- 类型
	- 赢者树 : 列出赢的人
	- 输者树 : 列出输的人
	- 最小 : 分小获胜, 我们需要找出最小值
	- 最大 : 分高获胜, 我们需要找出最大值

### 15.2.1 最小赢者树

初始化方法 : 后序遍历每个结点(每个结点表示一场比赛, 通过分数来确定值)

重构方法 : O(logn) : n为竞赛的人

可以找出最小值, 不断重构

### 15.2.2 最小输者树

记录的是输者, 我们需要找出最小值, 则找出胜者, 则比较的人还是胜者

![image.png|275](http://verification.fengzhongzhihan.top/202402291737479.png)
还有一个小啾啾, 记录最终的胜者

## 15.3 残缺棋盘问题

2^k * 2^k的棋盘, 其中有一个残缺的棋子, 需要通过三格板进行覆盖. 则一定能覆盖完

解决策略 : 分置思想 : 我们继续划分, 加上残缺的棋子, 使得恰好能被三格板覆盖

## 15.4 任务调度问题

目的 : 寻找整个项目最短完成时间(考虑并行执行)

所需总时间 : 找最长路径

事件的最早发生时间
- 从源点到结点的最长路径
- Ve(j) = max (Ve(j) + length(j,i));

事件的最晚发生时间
- 从下一个结点往前递推
- Vl(i) = min (V(j) - length(i,j));

活动的最早发生时间
- 起始结点 的最早发生时间

活动的最晚发生时间
- 末节点的最晚发生时间 - 边长

此时活动的最早发生时间 = 最晚发生时间, 则为关键结点, 进行路径压缩

# 16 跳表
## 16.1 定义
如果有序链表中查找n个数对, 则需要n次关键字比较, 如果在链表中部节点加上指针, 比较次数可以减少为 n / 2 + 1(类似于二分第一步)

![image.png](http://verification.fengzhongzhihan.top/202403241047640.png)
自下而上, 依此称为一级链表, 二级链表, 三级链表
查询时 : 从三级开始 -> 二级 - > 一级
- 第i级链表有n / 2^i 个记录

跳表定义: 该结构有一组等级链表, 0级包含所有数对, 1集链表数对为0级链表数对的一个子集...

## 16.2 插入和删除

![image.png](http://verification.fengzhongzhihan.top/202403241054609.png)

若插入节点属于第i类链表, 则指针仅仅影响 0 ~ i级链表

删除 : 逆过程,  将指针指向后面的结点即可

## 16.3 级的分配
s
设置p : 第 i - 1级链表同时属于第i级链表的概率
对于一般的p: 链表的级数为$$[log_{1/p} n](up) - 1$$

lg n / lg (1/p)
分配方法
1. 一般来说, 用一个随机数模拟器: 如果ran <= p, 则级数 + 1
2. 还有另一种等级分配方法，把随机数生成器产生的数分为几段。第一段是1~ 1/p，第二段是 l/p~ 1/p2，等等。若产生的随机数出现在第i段，则把数对插人 i- 1 级链表。

问题
1. 如果分配的级数 >> log1/p N , 其中N为字典数对的最大预期数目, 可以设定级数上限为 \[log1/p N] - 1
2. 如果中间有空级链表无好处, 因此我们将新纪录的链表等级调整为最大


## 16.4 时间复杂度

![image.png](http://verification.fengzhongzhihan.top/202403241650998.png)
