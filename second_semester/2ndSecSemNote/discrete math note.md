前三章 2~3大题
代数结构  2~3大题(环与域不考, 同态同构往后不考, 格不考)
树 + 欧拉 + 着色  2~3大题
命题逻辑  2~3大题
# 1 集合

## 1.1 集合概念和表示

集合 : 明确的 + 互不相同的事物组成的整体.
- 若a是A的元素, a∈A
- 若a不是A的元素, a!∈A

集合中元素的个数称为**基数**或**势**, 用|A|或#A来表示
- 若基数是有限数, 则集合为**有限集**, 否则称为**无限集**

一个集合如果每个元素都是集合, 则称为**集合族**
求和为8的不同正整数的集合的集合族 
- {{8},{1,7},{2,6},{3,5},{1,2,5}, {1,3,4}} 

全体正整数的势是阿列夫 
全体实数的势是2^阿列夫
- | N | = 阿列夫

注意 : 
$$
|\phi| =0 
$$
$$|{\{\phi}\}|=1$$

集合表示方法
- 全部列举法
	- A= {1,2,3};
- 部分列举法
	- Z={+1, -1, +2, -2,...}
- 概括法
	- A = {x | x具有性质P}
- 文氏图(Venn)

“∃|x∈A”表示“存在唯一x∈A”
设P，Q为两个论断，
“P ⇒ Q”表示“如果P则Q”
“P <=> Q”表示“P当且仅当Q”

## 1.2 子集和幂集

子集 : 对于两个集合而言, 如果A集合元素均是B集合元素, 则称A为B的**子集**, 或者A包含于B
记为
$$A\subseteq B$$
- 即任意x∈A, x∈B

集合的包含关系的性质
- 反身性 : A包含于A
- 反对称 : A = B  <=> A包含B, B包含A
- 传递性 : A包含于B , B包含于C, 则A包含于C

注意: 
- 对于任何集合A, 空集为A的子集, 且空集和A称为A的**平凡子集**

$$A\subseteq B且A != B, 则A\subset B$$

**幂集** : 由A的所有子集组成的**集合族** , 记作 P(A) 或2 ^ A
$$P(A)={\{B|B\subseteq A}\}$$
其中 

$$|P(A)|=C_n^0 +C_n^1 +...+C_n^n = 2^n =2^{|A|}$$
因此可得幂集元素中 
- 元素个数为偶数和奇数的集合个数 应该是相等的

C40 C41 C42 C43 C44
1       4      6     4      1
8 = 8
C30 C31 C32 C33 
1        3     3      1
4 = 4
写的时候按照元素个数从小到大写即可

## 1.3 集合的运算

### 1.3.1 名词定义
**并集**
$$A\ U B={\{x|x∈A或x∈B}\}$$
**交集**
$$A\ ∩ B={\{x|x∈A且x∈B}\}$$

**分离**
若A∩B = 空集, 则A与B**分离**/ **不相交**
其中若A是一个集合族, A的元素是两两分离的, 则A为**分离族**
- ｛1，2｝与｛3，4｝是分离的 
- ｛｛a，b｝，｛d，c｝，｛f｝｝是一个分离族 
**空集** : 最小的集合, **全集** : 相对的,没有最大的集合

**差集**
$$A-B={\{x|x∈A,x\notin B}\}$$
称为A和B的差集, B在A中的相对补集

**补集**
A在全集U中的相对补集U - A称为A的绝对补集, 简称补集, 记为 ~A或A'
- 注意 : 全集不一定要包含A中所有元素
![image.png|475](http://verification.fengzhongzhihan.top/202403171033658.png)

**对称差** 
$$A \bigtriangleup B = (A-B)\ U\ (B-A)=A\ U\ B-AB$$

性质: 
![image.png|325](http://verification.fengzhongzhihan.top/202403171440861.png)

![image.png|325](http://verification.fengzhongzhihan.top/202403171446106.png)
从x∈B出发->若x∈ A... -> x∈ C -> B是C子集
->若x不∈A, x不属于A∩B且x∈AUB-> x∈A(+)B -> X∈ A+C  ->... -> X∈C
幂集性质
1. 
$$A\subseteq B \iff P(A) \subseteq P(B) $$

证明: 预证A是B子集, 从任意x∈A开始.. 

$$hitt:若x∈A, 则\{x\} ∈ P(A)$$$$若x∈P(A)则x是A的子集$$
2. 
$$P(A∩B) = P(A)∩P(B)$$
$$hit: x \subseteq A 且 x\subseteq B <=>x \subseteq A∩B$$
3. 
$$P(A) \ U \ P (B) \subseteq P(AUB)$$
$$hit: x\subseteq A∪B 不能推得 x\subseteq A或x\subseteq B, 反之可以推得$$
x ∈ P(A) U P(B) 则 x∈ P(A)或x∈ P(B)
则x是A的子集或x是B的子集
则x是AUB的子集 则x∈ P(A U B)
4. 
$$P(A')\ != (P(A))'$$
证明: 空集∈P(A') 但是不∈ (P(A))'
### 1.3.2 例题
![|550](http://verification.fengzhongzhihan.top/202406052036715.png)

$$\phi \in \phi $$
错: 集合之间不能用∈

$${\{\phi}\} \subseteq {\{\{\phi}\}\} $$
错: 右侧集合并没有包含空集

$$P(\phi)={\{\phi}\}$$
对!

![](http://verification.fengzhongzhihan.top/202406052038225.png)

![image.png](http://verification.fengzhongzhihan.top/202403171442787.png)


证明 : P(A - B)= P(A) - P(B) ?
答 : 错误, 前者包含空集, 右侧不包含空集
- 一般来说 P(A - B) 包含于 (P(A) - P(B) U 空集) $$x\subseteq A 且 x\not \subseteq B 不能推出x\subseteq (A-B)$$如A(1, 2, 3) B(1, 2, 4) : x (1, 3);
- 子集要求完全包含关系

. 设|A| = 88, 问：
             (1) 可构成多少个子集? 
             (2) 其中子集元素为偶数的有多少个?
             (3) 有几个子集元素为89个。

解:  (1) 可构成2^88个子集。		
	  (2) 子集元素为偶数的有2^87		
	  (3) 0个,  不可能有89个元素的子集。

例题: 
![image.png|450](http://verification.fengzhongzhihan.top/202403171505069.png)


## 1.4 有序n元组和笛卡尔积

### 1.4.1 有序n元组

**序偶(有序对)** : 有先后顺序的两个元素, 记作<a, b>或(a, b), 其中a, b叫做分量
$$<x,y>\ = \ <u,v> \iff x=u, y=v$$
两元素依此对应相等,称为**有序对相等**

**有序n元组** : n个有确定次序事物构成的整体, 记作<a1,a2,a3...an>
第i个元素(分量) : 记作ai
### 1.4.2 笛卡尔积
**笛卡尔积**: 设A, B两集合
$$A×B={\{<x,y>|x\in A,y\in B}\}$$
例 : ![image.png](http://verification.fengzhongzhihan.top/202403011637199.png)
因此 : 
$$A×B \ != B×A$$
除非 : 
$$A = B \ or \ A =\phi \ or \ B=\phi$$
注意 : 
 A×B×C != (A×B) ×C!
 - 前者不带 < > , 后者带< > 
![image.png](http://verification.fengzhongzhihan.top/202403171512028.png)


即笛卡尔积不满足**交换律和结合律**! 但是满足**分配律**, 有:
![image.png|425](http://verification.fengzhongzhihan.top/202403011640601.png)

对任意集合A ,A × A × A × A × A... 记作 $$A^n$$
**笛卡尔积的元素个数 = 每个集合元素的个数的连乘**
![|375](http://verification.fengzhongzhihan.top/202406052059009.png)


证明
![image.png](http://verification.fengzhongzhihan.top/202403171516958.png)
![](http://verification.fengzhongzhihan.top/202406052103826.png)

### 1.4.3 多重集

有一组事物 : 若某些事物可重复出现, 则整体称为**多重集**
元素a在A中出现的次数重复度记为 $$M_A(a)$$
若**重复度为0 / 1 ,则多重集就是一个集合**

A和B都为多重集, A U B是一个多重集
- 元素的重复度 = 元素在A, B中重复度的最大值, 
$$M_{A \ UB} (x) = max{\{M_A(x), M_B(x)}\}$$
![image.png](http://verification.fengzhongzhihan.top/202403171520528.png)


A和B都为多重集, A ∩ B是一个多重集
- 元素的重复度 = 元素在A, B中重复度的最小值, 即
$$M_{A \ ∩B} (x) = min{\{M_A(x), M_B(x)}\}$$
![image.png](http://verification.fengzhongzhihan.top/202403171520223.png)


A和B都为多重集, A和B的差A - B是一个多重集
- 元素的重复度 = 元素在A, B中重复度的非负差, 即
$$ m 与n的非负差 = {\{m-n, m>=n}\} //
{\{0, m<n}\}$$
![image.png|400](http://verification.fengzhongzhihan.top/202403171520608.png)

A和B都为多重集, AB的和A + B是一个多重集
- 元素的重复度 = 元素在A, B中重复度的和, 即
$$M_{A \ +B} (x) = M_A(x)+M_B(x)$$
![image.png|425](http://verification.fengzhongzhihan.top/202403171521902.png)


# 2 关系

## 2.1 关系定义

**定义一 : 一个有序对的集合R称作一个二元关系, 简称关系**
 $$R \subseteq A×B  \ 或  R\subseteq A ×A$$
分别称R为A到B的关系, A上的关系
- 因此R是一个集合族, 里面的集合包含了A和B的元素
- 可知 R∈P(A×B)
$$aRa 等同于 <a,a>∈R$$
A = {1, 2, 3, 4}. 
   则  R  = {<a,b> | a整除b} 
	  R  = {<1,1>, <1, 2>, <1,3>, <1, 4>, <2, 2>, <2, 4>, <3, 3>, <4, 4> }

![image.png|500](http://verification.fengzhongzhihan.top/202403051013507.png)
- 多少种不同的关系 等价于 p(A × B)的元素个数

设R为A到B的关系, R中所有有序对的第一元素构成的集合称为**定义域**, 记为
$$dom\  R = {\{x|x∈A, 存在y∈B,使<x,y>∈R}\}$$
设R为A到B的关系, R中所有有序对的第二元素构成的集合称为**值域**, 记为
$$ran\ R ={\{y|y∈B, 存在x∈A,使<x,y>∈R}\}$$
则dom R 是 A 的子集 , ran R是B的子集

![image.png](http://verification.fengzhongzhihan.top/202403051017810.png)

 设A是任意集合, 令
$$I_A = {\{<x,x>| x∈A}\}称为A上的恒等关系$$
$$E_A = {\{<x,y>| x∈A, y∈A}\}称为A上的全域关系$$

## 2.2 关系的图形表示

### 2.2.1 关系图
R是A到B的关系， 其中，A，B是两个有限集，A＝｛ a1, a2 ,…,am ｝，B＝｛ b1, b2 ,…,bn ｝，用圆点表示A，B的元素，并分别画在平面上，当ai R bj时，做一条自ai 向bj的有向弧。

例如R是A上的关系
![image.png](http://verification.fengzhongzhihan.top/202403051030745.png)


### 2.2.2 关系矩阵
![image.png](http://verification.fengzhongzhihan.top/202403171530552.png)

R是A到B的关系
![image.png](http://verification.fengzhongzhihan.top/202403051031444.png)
使用关系矩阵来表示( m× n的矩阵)
- 其中有元素的记为1, 否则记为0

![image.png](http://verification.fengzhongzhihan.top/202403051035651.png)
## 2.3 关系的性质

关系的五大性质
- **自反性** (<x,x>)
- **反自反性** (无自反性)
- **对称性** (<x,y><y,x>)
- **反对称性** (无对称性)
- **传递性** (<x,y><y,z><x,z>)

### 2.3.1 自反性
自反性定义 : 对于任意x∈A, 均有 xRx, 则称R是自反的
- 关系包括 : \==\, >=, <=,  /
- 对于A中的所有元素均满足, 对于R中的所有有序对不一定满足
![image.png|475](http://verification.fengzhongzhihan.top/202403171534729.png)
![image.png](http://verification.fengzhongzhihan.top/202403051044042.png)
### 2.3.2 反自反性
如果对任意x∈A，均没有xRx(<x,x>∈R)，称R是反自反的 
![|450](http://verification.fengzhongzhihan.top/202406052123945.png)
- 一个关系可以不满足自反 + 不满足反自反

![image.png](http://verification.fengzhongzhihan.top/202403051045656.png)
### 2.3.3 对称性
对称性定义 : 当xRy, 必有yRx,称R是对称的
![image.png](http://verification.fengzhongzhihan.top/202403171535206.png)
key : 交换两数位置, 等式仍然成立
![image.png](http://verification.fengzhongzhihan.top/202403051045556.png)
### 2.3.4 反对称
反对称定义 : 当xRy, yRx,必有x == y
![image.png](http://verification.fengzhongzhihan.top/202403171536947.png)
key : 交换两数顺序, 如果等式均成立, 则二者必然相等
![image.png](http://verification.fengzhongzhihan.top/202403051045152.png)
### 2.3.5 传递性
传递性定义 : 当xRy,  yRz时, 必有xRz
 ![image.png|296](http://verification.fengzhongzhihan.top/202403171540269.png)
![image.png](http://verification.fengzhongzhihan.top/202403051046641.png)


![image.png](http://verification.fengzhongzhihan.top/202403171543092.png)
1. 证明: 
若x - y / 3 是整数, 则 y - x / 3 是整数

2. 自反 : 任意x∈A, (x, x)∈R, (x, x)∈S, 则 (x, x)∈R∩S
对称 : x, y∈ A, 且(x, y) ∈R∩S则有(x, y) ∈R,(x, y) ∈ S, 则(y, x)∈R, (y, x)∈S
则(y, x)∈ R∩S
传递, x, y,z∈ A (x, y) ∈R∩S   (y, z) ∈R∩S, 则(x, y) ∈R,(x, y) ∈ S, (y, z) ∈R, (y, z) ∈S, 则(x, z) ∈R (x, z) ∈S
3. 
$$2^{n^2 - n}$$


## 2.4 复合关系和逆关系
### 2.4.1 复合关系

定义 : 设R是从A->B关系, S是从B->C关系,则A->C关系称为S与R的**复合关系**, 记为 **R·S**
![image.png](http://verification.fengzhongzhihan.top/202403171604077.png)
![](http://verification.fengzhongzhihan.top/202406052147900.png)

![image.png](http://verification.fengzhongzhihan.top/202403171605744.png)
复合关系则不满足**交换律** , 但满足**结合律**
![image.png](http://verification.fengzhongzhihan.top/202403171605049.png)
证明 : 
![](http://verification.fengzhongzhihan.top/202406052149296.png)


定义 : R是A上关系,  则R的n次幂定义为
$$R^0 = I_A$$
$$R^n=R^{n-1}·R= R·R...$$
![image.png](http://verification.fengzhongzhihan.top/202403171612132.png)
![image.png](http://verification.fengzhongzhihan.top/202403171613702.png)
有限集可以直接使用关系矩阵进行运算
![](http://verification.fengzhongzhihan.top/202406052153151.png)
R1∘R2 = {(1,a1),(1,a2),(1,a3),(2,a2),(2,a3),(2,a4),(3,a2),(3,a3),(3,a4)} 
### 2.4.2 逆关系
设R为A到B关系
$${\{<b,a>|任意<a,b>∈R}\}$$
称为R的**逆关系**, 记为**R^-1**

其中 
- dom R^-1 = ran R 
- ran R^-1 = dom R
- (R-1)-1 = R
- (R∘S)^-1 = S^-1 ∘ R^-1

![image.png](http://verification.fengzhongzhihan.top/202403171619125.png)


![image.png|400](http://verification.fengzhongzhihan.top/202403171624202.png)

## 2.5 关系的闭包

设R是A上的关系, 如果A上关系R' 满足以下关系
- R'自反(传递, 对称)
- $$R \subseteq R'$$
- R'是满足条件且序偶最少的

则称R'为R的自反闭包

- 一个关系的闭包实际上就是求满足指定条件(如自反)且包含原关系中所有序偶(元素个数)最少的关系

定理
1. r(R) = R ∪ IA (自反闭包)
2. s(R) = R ∪ R-1 (对称闭包)
3. t(R) = R ∪ R^2 U R^3 ....(传递闭包)
	集合A有限集, |A| = n, 则t(R) =  U Ri (i = 1... n)

![image.png](http://verification.fengzhongzhihan.top/202403171635068.png)
![](http://verification.fengzhongzhihan.top/202406082141539.png)

![image.png](http://verification.fengzhongzhihan.top/202403171635586.png)
![image.png](http://verification.fengzhongzhihan.top/202403171637832.png)
![](http://verification.fengzhongzhihan.top/202406082143401.png)
- 注意传递闭包画图时, 可能存在自环

定理5
![image.png|425](http://verification.fengzhongzhihan.top/202403171640135.png)
- 传递时未必S(R)也是传递的
## 2.6 等价关系与集合的划分
**等价关系**: 如果R是A上的关系, 而且R是自反, 对称, 传递的, 则称R是A上的等价关系, **若aRb, 则a等价于b**

例题
![](http://verification.fengzhongzhihan.top/202406082146750.png)

![image.png](http://verification.fengzhongzhihan.top/202403171648420.png)
![](http://verification.fengzhongzhihan.top/202406082149012.png)
![image.png](http://verification.fengzhongzhihan.top/202403171651872.png)

设R1，R2为A上的等价关系，则R1∩R2为A上的等价关系．
证明（1）自反的（2）对称的（3）传递的
- 其实已经证明过了

注意: R1 U R2 未必是等价关系, 不满足传递性
- 自反 : 任意x∈A, xR1x, xR2x, 则x (R1UR2) x
- 对称 : x(R1 U R2)y 则xR1y或xR2y 

![image.png](http://verification.fengzhongzhihan.top/202403171654290.png)

**等价类** : 设R是A上的等价关系, a∈A, 一切与a等价的元素构成a的子集, 叫做**a的R - 等价类**, 其中a称作**代表元**, 记为 $$[a]_R或[a] $$
也就是
	$$[a]_R = {\{x |x∈A , xRa或aRx}\}$$
![](http://verification.fengzhongzhihan.top/202406082203644.png)


**商集** : 设R是A上等价关系,  R的**所有等价类构成的集合族**, 称为**A对R的商集**, 记作A / R = {\[a]\, a∈A }
![image.png](http://verification.fengzhongzhihan.top/202403171657392.png)

性质
![image.png|425](http://verification.fengzhongzhihan.top/202403140932387.png)

![|625](http://verification.fengzhongzhihan.top/202406082206403.png)
- 证明等价类相等, 因此证明集合相等从定义出发
- 证明aRb, 则由a∈\[a]得a∈\[b], 则aRb


**覆盖**: 设A是一个集合, C = {Ci | i ∈ j, j自然数集} 是一个集合族,  Ci ≠ 空集
- 如果U Ci = A, 则C是A的一个覆盖
- 若所有Ci ∩ Cj = 空集, 则C是A的一个**划分**, Ci为**划分块**
- 定理 : **A / R是A的一个划分**
	- 证明三点 : 非空 + 交集为空 + 并集为A

前面两个由定义可得, 如何证明并集为A呢?
- 也就是证明UaR = A
![image.png](http://verification.fengzhongzhihan.top/202403171707496.png)
- 证明两个集合相等
- a∈ \[a]R 且\[a]R是A的子集, 则a∈A, 则U是A的子集
- c∈A, 则c∈\[c]R , \[c]R是U的子集, 则c∈U, 则A是U的子集

**由划分可以确定一个等价关系R ,使得 A / R = C**
- 对划分的每个元素自己对自己求笛卡尔积即可
![image.png](http://verification.fengzhongzhihan.top/202403140938147.png)

![image.png](http://verification.fengzhongzhihan.top/202403171712146.png)

**定理**
R1 = R2 <=> A / R1 = A / R2
![](http://verification.fengzhongzhihan.top/202406082214833.png)
- 证明必要性 : 从左往右证, 若R1 = R2, 而A / R1 = {\[a]R1 | a∈A}  = {\[a]R2|
a∈A}, 则A/R1 = A/ R2
- 证明充分性: 从右往左证, 若A/R1 = A/ R2 , 则任意\[a]R1, 存在\[c]R2使得两者相等, 所以对任意<a, b>∈R1, 有a∈\[a]R1, b∈\[a]R1, 则a∈\[c]R2, b∈\[C]R2, 则<a,b>∈R2, 
- 综上, 都是从定义出发

![image.png](http://verification.fengzhongzhihan.top/202403171719441.png)
10
- 任意b∈ \[a]R∩S, 则(a, b )∈R∩S, (a, b)∈R∩(a, b)∈S, 则b∈\[a]R且b ∈\[a]S
- 任意b∈ \[a]R且b∈ \[a]S, 则(a, b)∈R∩S -> ...
11 
- 自反 : 任意x∈A, (x, x)∈R, 则(x, x)∈S
- 对称 : 任意x, y∈A, 且(x, y)∈S, 则有(x, y)∈R, (y, x)∈R, 则(y, x) ∈S
- 传递 : (x, y)∈S, (y, z)∈S, 有(x, y)∈R,(y,x)∈R, (y, z)∈R, (z, y)∈R, (x, z)∈R (z, x)∈R, (x, z)∈S
12
- 自反: 任意(x, y)∈A. 有(x, y) = (x, y), 则((x,y), (x,y))∈R
- 对称 : 任意(x, y), (u, v) ∈A, {(x, y), (u, v)}∈R, 则x + v = y + u , 则u + y = v + x 则 {(u, v), (x, y)}∈R
- 传递 , 有{(x, y), (u, v)}∈R   有{(u, v), (m, n)}∈R, 则 x + v = y + u, u + n = v + m, 则x + n = y + m, 则....
## 2.7 偏序关系和偏序集

### 2.7.1 定义
设R是A上关系, R**自反**, **反对称**, **传递**, 则R称为**偏序关系**, 简称**偏序**

![image.png](http://verification.fengzhongzhihan.top/202403172154743.png)
举例 : **实数的>=, 集合包含, 整除关系**

**偏序集**: P是一个集合, P上定义了一个偏序关系<=, 则P记为<P, <= >, 也简记P
举例: ![image.png|304](http://verification.fengzhongzhihan.top/202403172158405.png)

对偏序集〈P，≤〉，如果a，b∈P满足a≤b，则说在偏序集P中（或在偏序关系≤下）**a “小于等于”b**，这时也说，**b “大于等于” a**．

设〈P，≤〉是一个偏序集，若a，b∈P满足**a＜b**，且**不存在c**使a＜c＜b，则称**b盖住a**, 或称b是a的**直接前辈**，a是b的**直接后辈**.
- 大的盖住小的
例如，设N是自然数集，≤是通常自然数的“小于等于”关系, 则在偏序集〈N，≤〉中，１盖住０，２盖住１，…，i盖住i－１，…．

### 2.7.2 哈斯图
偏序集的Hasse图(哈斯图) , 根据偏序关系的特点, 可以进行简化 
- 省略自环(自反)
- 省略长弧 : 边长仅为1(无对称性)
- 省略箭头

![image.png](http://verification.fengzhongzhihan.top/202403172202042.png)
![](http://verification.fengzhongzhihan.top/202406091150818.png)
![](http://verification.fengzhongzhihan.top/202406091150898.png)


![image.png](http://verification.fengzhongzhihan.top/202403172205522.png)

### 2.7.3 全序关系
设〈P，≤〉是一个偏序集， x，y∈P，若x≤y或y≤x，称x，y是**可比较的**，否则称x，y**不可比较**．

设≤是P上的偏序，如果对任意x，y∈P，总有x≤y或者ｙ≤x，称**≤为全序关系**（**线序关系**），简称**全序**．当≤是全序关系时，集合〈P，≤〉称为**全序集**

![image.png|475](http://verification.fengzhongzhihan.top/202403172208295.png)

设〈A≤〉是偏序集．若B是A的**子集**且〈B，≤〉是**全序集**，则称〈B，≤〉为**链**
>如： 〈Z，≤〉是全序集， 〈N，≤〉是链。

### 2.7.4 最大元和最小元

设〈P，≤〉是一个偏序集，a∈P．
如果对任意x∈P，均有a≤x，则称a是〈P，≤〉的**最小元**；
如果对任意x∈P均有x≤a，则称a是〈P，≤〉的**最大元**．

设〈P，≤〉是一个偏序集，a∈P．
如果 	“不存在元素x∈P，使a＜x”，则称      a是〈P，≤〉的**极大元**；
如果     不存在元素x∈P，使x＜a，   则称     a为〈P，≤〉的**极小元**．

![image.png|350](http://verification.fengzhongzhihan.top/202403172214022.png)

最大元最小元唯一性
![image.png|475](http://verification.fengzhongzhihan.top/202403172215091.png)

最大元 -> 唯一极大元
a为最大元, x <= a, 若a不是极大元, 则存在x 使得a < x , 则a <= x且a 不为x, 则a = x 矛盾
![image.png](http://verification.fengzhongzhihan.top/202403172215695.png)
- 有限集当中, 唯一极大元- > 最大元

上界, 下界, 对于集合A, A通常是整个集合的子集, 而言
![image.png|500](http://verification.fengzhongzhihan.top/202403172218682.png)
若a是A的上界，且对A的任意上界b，有a≤b，则称a为A的**最小上界**（上确界），
若a是A的下界，且对A的任意下界b，有b≤a，则称a为A的**最大下界**（下确界）．
A的最小上界和A的最大下界分别用**supA**和**infA**表示

![image.png|300](http://verification.fengzhongzhihan.top/202403172220441.png)

![image.png](http://verification.fengzhongzhihan.top/202403172221465.png)

设A是偏序集〈P，≤〉的子集，若A的**最小上界（最大下界**）存在，则必**唯一．**
## 2.8 函数运算

### 2.8.1 函数定义
设f是集合A到B的关系, 如果对于任意x∈A, 都存在唯一的y∈B, 使得<x, y >∈f, 则称f为A到B的函数, 记为f: A->B
- y称为f在x点的值, 也成为x在f下的象
- x为y在f下的原象
- A称为f的定义域, B称为f的陪域, 所有的像组成的集合是B的子集, 称为f的值域
- A到A的函数, 称为A上的函数

![image.png](http://verification.fengzhongzhihan.top/202403181944972.png)
![image.png](http://verification.fengzhongzhihan.top/202403181945564.png)
- 原象可以是一个集合

![](http://verification.fengzhongzhihan.top/202406191141340.png)
限制和扩张
![](http://verification.fengzhongzhihan.top/202406191142598.png)

### 2.8.2 特殊函数

恒等函数
![image.png|500](http://verification.fengzhongzhihan.top/202403181955869.png)
投影函数
![image.png|475](http://verification.fengzhongzhihan.top/202403181955782.png)
自然映射
![image.png|475](http://verification.fengzhongzhihan.top/202403181956620.png)

![image.png|450](http://verification.fengzhongzhihan.top/202403182000027.png)
- 这里的闭区间代表区间
![image.png|475](http://verification.fengzhongzhihan.top/202403182002572.png)



### 2.8.3 单射, 双射, 满射

**单射**: 任意x, y∈A, 若x!=y, 则f(x) != f(y)
- 即若f(x) = f(y) 则x == y
- 也就是值相等, 则自变量相等, 不存在不同的自变量对应相同的值

**满射**: 任意y∈B, 存在x∈ A, 使得f(x) = y
- 即对于所有的y都有对应的x
**双射**: 若f为单射且为满射, 则f为双射(一一对应)

![image.png](http://verification.fengzhongzhihan.top/202403210908489.png)
- 对于不同的x, y 则(x, x + 1) != (y, y + 1)成立
- 对于所有的N * N未必存在x, 比如(x, x  + 2)
![image.png](http://verification.fengzhongzhihan.top/202403210913108.png)
- 证明两个函数的值相等, 则证明两个集合相等, 设y ∈ f(A U B), **要证明y∈f(A) U f(B),** 则存在x使得x∈A U B , f(x) = y; x∈A U x∈B, f(x) = y, 即f(x) ∈ f(A) 或f(x) ∈f(B)故y∈f(A) U f(B)
- 设y∈f(A) U f(B) , 则y∈f(A) U y∈f(B), 则f(x) = y , x∈A U B, 故y ∈f(A U B)

### 2.8.4 复合函数和逆函数

复合函数定义
![image.png|550](http://verification.fengzhongzhihan.top/202403210915883.png)
- 注意函数关系: g·f , 复合关系 f·g
![](http://verification.fengzhongzhihan.top/202406191146063.png)

恒等函数
![image.png](http://verification.fengzhongzhihan.top/202403210917378.png)

![](http://verification.fengzhongzhihan.top/202406191146032.png)


复合函数的结合律
![image.png](http://verification.fengzhongzhihan.top/202403210920325.png)

![](http://verification.fengzhongzhihan.top/202403210923503.png)

定理
![image.png|450](http://verification.fengzhongzhihan.top/202403210924824.png)
证明 :
![|500](http://verification.fengzhongzhihan.top/202406191150541.png)
![|500](http://verification.fengzhongzhihan.top/202406191150184.png)

![image.png|450](http://verification.fengzhongzhihan.top/202403210929640.png)
![](http://verification.fengzhongzhihan.top/202406191151768.png)
![|475](http://verification.fengzhongzhihan.top/202406191151997.png)

逆函数
![image.png](http://verification.fengzhongzhihan.top/202403210932991.png)

答: 逆函数未必是函数, 但是逆函数一定为一种关系

定理 : **f可逆 <=> f为双射**

![image.png](http://verification.fengzhongzhihan.top/202403210937052.png)

![image.png](http://verification.fengzhongzhihan.top/202403210942860.png)
![image.png](http://verification.fengzhongzhihan.top/202403210944415.png)
- 举了一个具体的例子进行证明

证明 :
![image.png|550](http://verification.fengzhongzhihan.top/202403210945301.png)
![image.png|550](http://verification.fengzhongzhihan.top/202403210945582.png)
- 又是证明集合相等
- x∈f-1(A ∩ B), f(x)∈A∩B, 则x∈f-1(A) ∩ x∈f-1(B)
- 此时x里面的集合就代表了结果

# 3 无限集

## 3.1 集合的势

定义 : 对于有限集, 如果存在A到B的双射, 则A和B**等势**, 记为**A~B**
- 规定空集~空集
- 有限集的元素个数相同

**在无限集中, 本身和真子集可以等势**
- 这是无限集和有限集的根本区别

![|275](http://verification.fengzhongzhihan.top/202406091456872.png)

![image.png|250](http://verification.fengzhongzhihan.top/202403211504625.png)
- 证明单射: 不同自变量不同值
- 证明满射 : 给定一个值, 能唯一确定一个自变量
![|475](http://verification.fengzhongzhihan.top/202406091458935.png)

无限集一定与它的一个真子集等势
![image.png|450](http://verification.fengzhongzhihan.top/202403211506426.png)
- 若x在A0中, 则为x
- 不在A0中, 一一对应

 A ~ A , 若A~B, 则B~A, 若A~B, B~C, 则A~C
- 则**等势关系是一种等价关系**
- 把所有等势的集合放在一起称为一个等价类, 标志称为**集合的势**

若Ai ∩ Aj = 空集, Bi ∩ Bj = 空集(i != j) Ai ~ Bi(条件)
则UAi ~ UBi      UAi ~ UBi
- 若**两个集合族内部集合两两之间无交集, 则集合族之间等势**

集合的势为|A|, 空集的势为0
与N等势的集合的势为阿列夫![image.png|96](http://verification.fengzhongzhihan.top/202403211511766.png)
与(0, 1)等势的集合(R)的势为 ![image.png|117](http://verification.fengzhongzhihan.top/202403211512575.png)

若A不与B等势,且A与B的某子集等势, 则称**A势<B势**, 记为|A| < |B|
|A| <= |B| <=> **存在A到B的单射**

则由于|N| < |(0, 1)|则N0 < N


证明集合等势的方法
- |A| <= |B| |B| <= |A| , 证明两个分别为单射即可
- |A| = |C|  |A| = |B|
- 定义

**(三歧定理)** : 对于任意集合A, B, 都一定有|A| < |B| or |A| > |B|, |A| = |B|
![image.png|274](http://verification.fengzhongzhihan.top/202403211515161.png)
![image.png](http://verification.fengzhongzhihan.top/202403211515324.png)

## 3.2 可数集

与N等势的集合称为**可数集**(**可列集**)
- 也就是说集合A具有可数个元素(可单列)

引理1 : 对于A, A为可数集, 当且仅当A的元素可**不重复的**排成无穷序列
a0, a1, a2...

引理2 : 可数集的无穷子集也为可数集

定理1 : 无限集必有可数子集

定理2 : 可数集中加入或删除有限个元素, 仍为可数集

定理3 : A1, A2为可数集, 则A1UA2也为可数集
证明 分两种情况讨论![image.png](http://verification.fengzhongzhihan.top/202403211521806.png)

定理4 : 可数个可数集的集合, 依然是可数集, UAi 为可数集

推论　设A，B为可数集，则A×B必为可数集. 

定理５　设A为无限集，B为可数集或有限集，则A ～ A∪B.

# 4 代数结构

## 4.1 运算

### 4.1.1 定义
设A是一个集合，A×A到A的映射称为A上的**二元运算**．一般地，An到A的映射称为A上的**n元运算**(f) 
- 注意: 输入和输出都∈A中

**举例**
则加减乘均为二元运算, 但**数的除法不是实数集R上的二元运算**．
- 因为0不能做除数
- 但是除法是非0实数集上的二元运算．
设S是一个集合，集合的并、交是P（S）上的二元运算．

将a，b在某运算“\*”下的运算结果 * (a，b) 记为a\*b. 或简写成ab．
- 此时不一定代表乘法

设n为正整数，Zn为模n剩余类 的集合：
Zn＝｛［0］，［1］，…，［n－1］｝
	定义运算 ＋n 与 ×n 如下:

任意\[i]，\[j] ∈ Zn，规定
	［i］＋n［j］＝［i＋j］
	［i］×n［j］＝［ i • j ］
其中，＋ 与 • 为通常整数的加法和乘法． 
- 结果与代表元i，j的选取无关  


设 f 是 A 上的 n元运算，S 是A子集，如果对x1，x2，…，xn∈S，恒有 f（x1，x2，…，xn）∈S，则称**S对运算f是封闭**的．**运算 f 在 S 上是封闭**的。
则有
- 自然数集对加法、乘法封闭, 对减法不是封闭的
- 设A 是S子集, 则P（A）对P（S）上的并、交封闭


### 4.1.2 运算的表示
当A是有限集时，A上的运算可用一个表来表示： 
![image.png|349](http://verification.fengzhongzhihan.top/202403231205093.png)
![](http://verification.fengzhongzhihan.top/202406091526654.png)
此时A^ A也是一个集合, 里面是二元的映射关系
![image.png|450](http://verification.fengzhongzhihan.top/202403231205772.png)

### 4.1.3 运算性质

结合律, 交换律, 左分配律, 右分配律, 分配律
![image.png](http://verification.fengzhongzhihan.top/202403231206915.png)
消去律
![image.png|550](http://verification.fengzhongzhihan.top/202403231206755.png)

**举例**
整数集上的加法、乘法均满足结合律、交换律，减法既不满足交换律，也不满足结合律；
乘法对加法、减法均满足分配律；加法、减法满足消去律

设A是一集合，P（A）上的并、交运算
- 满足结合律、交换律、分配律,不满足消去律．

## 4.2 代数系统
### 4.2.1 定义
**代数系统**
设A是一个非空集合，f1，f2，…，fn是A上的运算（其元数可以不同)
我们说A在运算f1，f2，…，fn下构成一个代数系统，记为<A，f1，f2，…，fn >．在不引起混乱的情况下，也可将其简记为A．

>设A是一个集合，P（A）与集合的并和交运算构成代数系统
<P(A)，∪>，<P(A)，∩>，<P(A)，∪，∩>

>模n剩余类集Zn在运算＋n和×n下可构成代数系统
	<Zn，＋n>，<Zn，×n>，<Zn，＋n，×n>

**子代数**
![image.png|475](http://verification.fengzhongzhihan.top/202403231208029.png)
- 注意必须得是封闭的!!

**单位元**
![image.png|600](http://verification.fengzhongzhihan.top/202403231208750.png)

**定理 :** 
1. 如果代数系统既有左单位元el又有右单位元er, 则el = er
2. 则代数系统〈A，◦〉中的单位元如果存在，则必定唯一．
证明 : el er = er , el er = el   -> el = er

**逆元定义 :** 
  代数系统〈A, \*〉，e是单位元. 
	对于a∈A，
	如果存在b∈A，使得ba ＝ e，则称a为左可逆的，且称b为a的**左逆元**；
	如果存在c∈A，使得ac ＝ e，则称a是右可逆的，且称c为a的**右逆元**；
	如果存在a'∈A，使得a'a＝aa' ＝ e，则称a是**可逆**的，且称a' 为a的**逆元**

**举例**
![image.png](http://verification.fengzhongzhihan.top/202403231210915.png)

![image.png](http://verification.fengzhongzhihan.top/202403231212442.png)

**定理**设〈A，\*〉是有单位元的代数系统， **\* 满足结合律．\
b ＝ b e ＝ b（ac）＝（ba）c ＝ ec ＝ c. 
1. 若a的左逆元b和右逆元c均存在, 则b = c
2. 如果a∈A的逆元存在，则必定唯一．

**幂等元**
设〈A，\*〉是一个代数系统，如果a∈A满足a * a ＝ a，称a为A的**幂等元**．
- 代数系统的**单位元必为幂等元**
〈P（A），∪〉，〈P（A），∩〉
- 任何元素均为幂等元

**〈Zn，＋n，×n〉的性质**
![image.png|400](http://verification.fengzhongzhihan.top/202403231215377.png)
![image.png|400](http://verification.fengzhongzhihan.top/202403231215661.png)
![image.png|400](http://verification.fengzhongzhihan.top/202403231215307.png)

## 4.3 同态与同构

### 4.3.1 同态的定义
![image.png](http://verification.fengzhongzhihan.top/202403281007774.png)
所以同态就是!!!!!!!!! 一个函数映射, 只不过可以同时满足保持运算
我们简称两个代数系统同态的意思是
- 存在一个f使得两者同态

![](http://verification.fengzhongzhihan.top/202406091550537.png)
如果f是单射的，称f为**单同态**；
如果f是满射的，称f为**满同态**；记为 f : A ~ B, B称为A的同态象
- 如果存在满同态, 则A~B
如果f是双射的，称f为**同构映射**，简称为**同构**。f：A~= B    
- 如果存在同构, 则A~=B

设<A,\*>是代数系统，若存在函数f:A->A,并且对x,y∈A,有f(x\*y)=f(x)\*f(y)。称f为<A,\*>的**自同态**；如果f是双射的，则称f为<A,\*>的**自同构**。

设〈A，\*〉是一个代数系统，A上的恒等映射IA是A的自同构．
	若Ａ中存在单位元e，令f(a)=e，任意a∈A，则f是A的自同态
f(x * y ) = f(x) * f(y)  -> e = e * e


![|425](http://verification.fengzhongzhihan.top/202406091554123.png)
![|500](http://verification.fengzhongzhihan.top/202406091555272.png)

### 4.3.2 同态的性质
**同态和同构的性质**
1. 如果两函数是同态、同构的，则复合函数也是同态、同构的。
2. 满同态保持结合律
3. 满同态保持交换律
4. 满同态保持单位元, e -> f(e)
5. 满同态保持逆元  a a'   ->  f(a) f(a')
6. 满同态保持零元
7. 满同态保持幂等元
8. 同构映射运算性质双向保持(f和f逆)

f 是   < A，\*> 到 < B，· >  的同态，
g是   < B，· > 到 < C，△>的同态，则
g◦f是< A，\*> 到 < C，△>的同态. 
且当f，g均为**单同态、满同态、同构**时，g◦f也必是**单同态、满同态、同构**．
![|274](http://verification.fengzhongzhihan.top/202406091559007.png)
- 想要证明保持运算: ...先拆开f(x * y) 再拆开f(x) · f(y)即可
![|500](http://verification.fengzhongzhihan.top/202406091601795.png)
证明同态即可
![](http://verification.fengzhongzhihan.top/202406091606204.png)
![](http://verification.fengzhongzhihan.top/202406091609360.png)
![](http://verification.fengzhongzhihan.top/202406091609861.png)
- 注意证明逆元得证明两次
![](http://verification.fengzhongzhihan.top/202406091610046.png)

## 4.4 同余关系与商代数

设〈A，\*〉是一个代数系统，E是A上的**等价关系**，如果 任意x1，x2，y1, y2∈A，
	当x1 E y1，x2 E y2 时，必有 x1\*x2  E  y1\*y2，
	则称E为A上的**同余关系**．
则整数集Z上的模m同余关系是〈Z，＋〉及〈 Z，· 〉上的同余关系．
m = 5   (1, 6)  (2, 7)     则  (3, 13)   (2, 42)  
- 就是说, x1 * x2和y1 * y2属于一个等价类中

设E为〈A，\*〉上的同余关系，在商集
A/E＝｛\[ x ]E | x∈A｝上合理地引入一个运算：
令 ◦ 是A/E上的运算，由下式定义：
	\[x]◦\[y]＝\[x * y]，\[x]，\[y]∈ A/E
代数系统〈A/E，◦〉，称为A对E的**商代数** 
![|350](http://verification.fengzhongzhihan.top/202406091625400.png)
![|500](http://verification.fengzhongzhihan.top/202406091626983.png)
- f(x * y) = f(x) · f(y)
\[x * y] = \[x] * \[y]

![](http://verification.fengzhongzhihan.top/202406091629683.png)

# 5 群
## 5.1 半群
### 5.1.1 半群, 幺半群
**半群**定义 : <S, * >若* 满足结合律, 则称<S, * >是一个半群
![image.png|525](http://verification.fengzhongzhihan.top/202403281511389.png)

半群〈S，◦〉的运算 ◦ 通常叫做“乘法”
举例 :
![image.png|500](http://verification.fengzhongzhihan.top/202403281051783.png)

![image.png|550](http://verification.fengzhongzhihan.top/202403281053136.png)
需要验证3 ! = 6种

假设<S. * >是一个半群, a∈S, 则a^n = a * a * a...
且满足阶乘的计算公式
![image.png](http://verification.fengzhongzhihan.top/202403281513423.png)
![image.png](http://verification.fengzhongzhihan.top/202403281513052.png)

此时2^n , 表示n个数字进行这样的操作
- 如果是加法, 则结果为2n

如果满足交换律, 则称**可交换半群**
- 在乘积中各项任意交换次序, 则所得运算结果相同

对于可交换半群, 运算符号常用+表示
- 使用加法记号时，单位元常用0表示，称为零元 
- 使用乘法记号时，半群S中的元素0，若关于任意x∈S，有0x=x0=0，则称0为S的**零元**

**幺半群** <- **有单位元**
![](http://verification.fengzhongzhihan.top/202406101544350.png)

若为**幺半群**, 且若a∈S的**逆元**存在, 则由于满足结合律, 则逆元一定为唯一的

负元定义(唯一逆元)
![image.png|475](http://verification.fengzhongzhihan.top/202403281529479.png)

![image.png](http://verification.fengzhongzhihan.top/202403281531151.png)
注意: **幺半群未必满足交换律**

### 5.1.2 子半群, 子幺半群
**子半群** : 
![image.png](http://verification.fengzhongzhihan.top/202403281532817.png)
- 则只需要T对于运算封闭, 则为子半群
- 这个封闭是指自己对自己封闭即可

![](http://verification.fengzhongzhihan.top/202406101549671.png)

注意 : 半群有单位元, 子半群未必有单位元, 且未必相等
举例 : ![image.png](http://verification.fengzhongzhihan.top/202403281533470.png)
- P(A)单位元为A, P(B)单位元为B

**子幺半群:**
S为幺半群, T为子半群, 且**S单位元e∈T,** 则T为S的**子幺半群**
![image.png|349](http://verification.fengzhongzhihan.top/202403281537809.png)
例: 此时S的单位元为1

![image.png](http://verification.fengzhongzhihan.top/202403281537873.png)
- 封闭 : 任意a, b∈T, 有a* a = a, b * b = b, 需要证明a * b∈T, 则证a * b * a * b = a * b 即可
- 结合律: 本来就是可结合的, 符号自带属性
- 单位元 : e * e = e , 则e∈T
## 5.2 群
### 5.2.1 群定义
定义 : 代数系统满足以下几点
- 运算可结合(半群)
- 存在单位元e
- 对于任意a都存在逆元a-1
即满足**任意a都存在逆元a-1的幺半群**
称为**群**

如果一个群满足交换律, 则称为**交换群** 或者**Abel群**

|G|表示群的阶, 可以无限可以有限

判断是否为群
![image.png](http://verification.fengzhongzhihan.top/202403281548558.png)
1. 单位元为空集, 逆元为自身
2. ∩ 单位元为S, 只有S有逆元   U单位元为空集, 只有空集有逆元 

〈Z，＋〉，〈Q，＋〉，〈R，＋〉均为无限交换群，〈Q＋，·〉，〈R＋，·〉也为无限交换群，但〈Q，·〉，〈R，·〉不是群
- 乘号的单位元为1, 0无逆元

<Zn，＋n〉为有限交换群，其中零元(逆元)为［０］，
		 ［i］的负元为\[-i]＝\[n-i]. 

A是非空集合，F = { f | f : A -> A}, 运算"。"是函数的复合运算，
则<F, 。>是群
- 此时F为映射函数的集合
1. 单位元 : 恒等函数 f 复合IA = f
2. 逆元 : 逆函数 f 复合f-1 = IA
3. 可结合的
![image.png|375](http://verification.fengzhongzhihan.top/202403281557543.png)
- 注意双射个数不是函数个数
![|425](http://verification.fengzhongzhihan.top/202406201508076.png)

关系 / 函数 / 双射个数
![image.png|240](http://verification.fengzhongzhihan.top/202403301934303.png)
- 关系个数怎么理解 : A和B的笛卡尔积的子集的数目

### 5.2.2 群性质
定理1
1. 群中**消去律成立**(因为有逆元)
2. **e为群G中唯一幂等元**(a * a = a)
![image.png|400](http://verification.fengzhongzhihan.top/202403301936200.png)
![image.png|625](http://verification.fengzhongzhihan.top/202403301936946.png)

定理2
- **f(a)^-1  = f(a^-1)**
![image.png](http://verification.fengzhongzhihan.top/202403301937037.png)
证明 : 
![image.png|354](http://verification.fengzhongzhihan.top/202403301939589.png)
- 证明两个函数互为逆, 证明相乘为e

**有限群 : 运算表中每一行(列) 都是G中元素的全排列**
![image.png](http://verification.fengzhongzhihan.top/202403302005735.png)

一二三阶群唯一, 四阶群有两个
![image.png](http://verification.fengzhongzhihan.top/202403302009258.png)

![image.png|475](http://verification.fengzhongzhihan.top/202403302007428.png)


若G为二阶群, 则(G × G, 复合) 为四元群

![image.png|371](http://verification.fengzhongzhihan.top/202403302011832.png)
### 5.2.3 代数系统 -> 群
G为群, H为任意代数系统, **若存在G到H的满同态, 则H必为群**
![image.png|550](http://verification.fengzhongzhihan.top/202403301942339.png)
对G运用了定理二
### 5.2.4 半群 -> 群
G是半群, 若
1. **G有左单位元** e a = a
2. **G中任意元素a, 均有一左逆元 a-1** , 使 a-1a =e 
则G为群

证明: 1. 左逆元也是右逆元 2. 左单位元也是右单位元
则左脚右脚来证明
![image.png|400](http://verification.fengzhongzhihan.top/202403301949082.png)
- 证明aa-1 = e 
- 证明ae = a

若G为**半群**, 任意a, b ∈ G, 方程a**x** = b, **y**a = b在G中总有解, 则G为群
![image.png|475](http://verification.fengzhongzhihan.top/202403301952957.png)
- ax = b, ya = b总有解
- 每一个元素都有左单位元: 令yb = b的一个解为e, 则eb = b ,  bx =  a的解为c , bc = a, 则ea = e(bc) = bc = a 
- 每一个元素都有左逆元 : ya = e有解, 则a'a = e有解, 则成立

**有限半群, 如果消去律成立, 则必为群**
![image.png|600](http://verification.fengzhongzhihan.top/202403302003855.png)
- 证明任意a, b∈G, ax = b , ya = b有解
- 若ax = b : 由消去律可得aG中也有n个元素, 则aG 和 G , 且aG是G的子集, 则aG = G, 则b∈aG, 则存在x使得ax= b

![](http://verification.fengzhongzhihan.top/202406101634475.png)


## 5.3 子群和元素的周期
### 5.3.1 子群, 中心, 循环子群
如果G为群, H是G的子集, 如果H在G的运算下也为群, 则H为**子群**
![image.png|500](http://verification.fengzhongzhihan.top/202403302013739.png)
**群G的中心**
![image.png|450](http://verification.fengzhongzhihan.top/202403302038714.png)
- e一定是中心的元素, 但中心不只包含e
- 证明顺序 : 非空 + 封闭 + 逆元存在

![image.png](http://verification.fengzhongzhihan.top/202403302015763.png)
证明子群: 也就是证明封闭 + 群
-  由于f(A)是满同态的, 则A~f(A) , 其中A为子群, 则f(A)是群
- 由于映射到H中, 则f(A)是H子集
![image.png|500](http://verification.fengzhongzhihan.top/202403302017517.png)


**循环子群**
设G是群，a∈G，令 （a）＝｛ a^ i | i∈Z ｝, 则（a）是G的子群，称为由a 生成的**循环子群**． 
证明 : 
![image.png|350](http://verification.fengzhongzhihan.top/202404141446254.png)
非空 + 封闭 + 有单位元 + 有逆元 

设G是群，a∈G，若存在正整数n，使a^n ＝ e，则将满足该条件的最小正整数n称为**a的周期**（阶），若这样的n不存在，称**a的周期为∞**． 

用| a|表示**a的周期（阶）**．并将周期（阶）为n的元素称为**n阶元素**． 
- 区分, 元素的阶和群的阶

### 5.3.2 群和子群的性质
![image.png|500](http://verification.fengzhongzhihan.top/202403302027790.png)
1. 唯一幂等元 == 单位元
2. 逆元均相同, 因为单位元相同

![image.png|400](http://verification.fengzhongzhihan.top/202404141448859.png)
**证明第一个**
设G为群，a∈G，若a的周期为n（或等价地说（a）的阶为n）
则 （a）＝｛a^0，a^1，…，a ^n -1 ｝
![|450](http://verification.fengzhongzhihan.top/202406201603672.png)
![|425](http://verification.fengzhongzhihan.top/202406201605874.png)
先证明有限集
- 先证明(a)  = {a0, a1...an-1}
- 接下来说明互不相同
再证明无限集
- a的周期无穷, 则a1, a2...ai互不相同, |(a)| = 无穷

**再证明第二个**
![|400](http://verification.fengzhongzhihan.top/202406201607657.png)
注意设m = kn + r(很关键)

### 5.3.3 成为子群条件
![image.png|475](http://verification.fengzhongzhihan.top/202403302030862.png)
若为子群 : 1显然成立 , 2显然成立
若1成立, 2成立 : 则证半群 + 单位元 + 逆元

![image.png|550](http://verification.fengzhongzhihan.top/202403302035993.png)
- 单位元 + 逆元 + 封闭

### 5.3.4 例题
![](http://verification.fengzhongzhihan.top/202406201608885.png)
因为逆元必须是成对出现的, 而e只有一个, 因此至少还有一个元素逆元是本身
- 则a a = e
![|400](http://verification.fengzhongzhihan.top/202406201610652.png)
- 证明2次周期<=
## 5.4 循环群

### 5.4.1 循环群, 生成元
![image.png|450](http://verification.fengzhongzhihan.top/202404132222611.png)

由定义可见，G是由a生成的循环群，意味着G的任何元素x，均可表示成a的方幂形式

举例  :
![image.png|475](http://verification.fengzhongzhihan.top/202404132223091.png)

### 5.4.2 循环群同构
![image.png|400](http://verification.fengzhongzhihan.top/202404132223359.png)
证明
![image.png|475](http://verification.fengzhongzhihan.top/202404132223797.png)
- 满射显然, 单射需要证明相同值的定义域一定相同, 若i != j则矛盾

![image.png|450](http://verification.fengzhongzhihan.top/202404132224942.png)
- 满射显然, 单射需要证明相同值的定义域一定相同, 则\[i] = \[j], 显然成立

### 5.4.3 循环群的子群

**循环群的子群必为循环群**
此时H =  (a ^io) io是a的最小正指数
![image.png|475](http://verification.fengzhongzhihan.top/202404132225241.png)
- 分类讨论,  如果H是e, 则H是e生成的循环群
- 如果H不是e, 则i0是a的最小正指数, 接下来证明H = (a^io)
- 令i = kio + r, 则ai = a kio a r -> ar = a-kio a i , 则ar∈H, 则r = 0, 则i = kio , ai = (aio)k

**n阶循环群, m | n,则存在唯一m阶子群**
![image.png|525](http://verification.fengzhongzhihan.top/202404132226701.png)
证明 :
- a^d 的周期是m, 则我需要找一个子群 A = (a^d)是G的m阶子群
- 证明唯一 : 任意m阶子群H = (a ^ i),  n | im ->dm | im -> i = kd , 得到了 i = kd, 则ai = ad ^ k, 则H是A的子集, 又因为元素个数相同(m) ,则唯一

![|475](http://verification.fengzhongzhihan.top/202406101937805.png)


![|450](http://verification.fengzhongzhihan.top/202406101939045.png)
新的循环群的生成元为f(a)
![|450](http://verification.fengzhongzhihan.top/202406101939174.png)
- 设有另外一个生成元 : 且可以和a相互表示

## 5.5 置换群
### 5.5.1 置换, 置换复合, 循环置换
有限集S到自身的双射f称为**S上的置换**，当|S|＝n时，S上的置换也称为**n次置换**．
![|425](http://verification.fengzhongzhihan.top/202406101946760.png)
- 置换是一个函数

**置换复合** : 置换的复合也称为置换的乘法. 两置换σ，τ 进行复合的结果σ◦τ也称为σ与τ的乘积，简记为 στ
![image.png|475](http://verification.fengzhongzhihan.top/202404132229246.png)
注意顺序
![|475](http://verification.fengzhongzhihan.top/202406101947533.png)
- 注意内部是没有顺序的

**循环置换**
![image.png|475](http://verification.fengzhongzhihan.top/202404132230513.png)
![](http://verification.fengzhongzhihan.top/202406101950468.png)


设S＝｛１，２，…，n｝，**所有n次置换**（即S＝｛１，２，…，n｝上的所有置换）**构成的集合**将用符号**Sn**表示．
- Sn是函数的集合

Sn称为**n次对称群**，其子群称为**n次置换群**．
![](http://verification.fengzhongzhihan.top/202406101954483.png)

### 5.5.2 Sn构成群

Sn在置换复合运算下构成群
证明 : ![image.png](http://verification.fengzhongzhihan.top/202404132233018.png)
- 类似 : 封闭 + 结合 + 单位元 + 逆元

|Sn|＝ n！(双射次数)

![image.png|425](http://verification.fengzhongzhihan.top/202404132237148.png)
![image.png|450](http://verification.fengzhongzhihan.top/202404132238505.png)
![image.png|425](http://verification.fengzhongzhihan.top/202404132239477.png)
证明子群 : 封闭 + 单位元 + 逆元
![image.png|450](http://verification.fengzhongzhihan.top/202404132242272.png)

# 6 环和域

## 6.1 基本性质

### 6.1.1 环

![image.png|475](http://verification.fengzhongzhihan.top/202404132248374.png)
- +可交换
- × 结合律
- × 对 ＋满足分配律


例子
![image.png|450](http://verification.fengzhongzhihan.top/202404132248655.png)

![image.png|450](http://verification.fengzhongzhihan.top/202404132250130.png)
![image.png|475](http://verification.fengzhongzhihan.top/202404132251920.png)

在环〈R，＋，· 〉中，若〈R，· 〉为幺半群，则称〈R，· 〉的单位元为环R的**单位元**，通常用１表示，这时称R为有单位元的环或有１的环．
设R为有１的环，a∈R，如果a在〈R，· 〉中有逆元，则称a为R中的**可逆元**．
并把a在半群〈R，· 〉中的逆元，称为a在环R中的**逆元**，用a^{-1}表示．
有１的环R中所有可逆元在乘法运算下构成一个群，该群记为R*，并称为环R的**乘法群.** 

其中 R = {0} 称为零环

### 6.1.2 性质
好像和学过的一模一样 ? 
注意 + 为可交换群, 而* 仅仅要求为半群
![image.png|425](http://verification.fengzhongzhihan.top/202404132256052.png)
![image.png|475](http://verification.fengzhongzhihan.top/202404132256062.png)

![image.png|475](http://verification.fengzhongzhihan.top/202404132258323.png)

例题 : 
![image.png|475](http://verification.fengzhongzhihan.top/202404132301871.png)


plus : 任一环的同态象也是一个环
![](http://verification.fengzhongzhihan.top/202406111536939.png)


当环R的乘法运算满足交换律，即〈R，· 〉为（可）交换半群时，称R（可）交换环． 

例题 : 


![image.png|450](http://verification.fengzhongzhihan.top/202404132312491.png)

设R为有单位元的环，且不只含一个元素，则１≠０．
证明 : 证明 若１＝０，则 任意 a ∈R， a = a·１＝ a·０＝０. 故R只含一个元素０，矛盾． 
我们一般默认为非零环

## 6.2 整环 除环 域

### 6.2.1 整环, 除环, 域
**定义1** 
设〈R，＋，·〉为一个环，a∈R且a≠０，若R中存在**非零元素b**，使ab＝０（ba＝０），则称a为R的左（右）零因子．R的左、右零因子统称为**零因子**．

**推论 :** 对于剩余环〈Zn，＋n，×n 〉，若n不是素数，则Zn中必存在零因子．

**有单位元**、**无零因子**的**交换环**称为**整环**．
例子
![image.png](http://verification.fengzhongzhihan.top/202404132319904.png)
- 如果是零元, 则必有两者均为0元, 则不对

![image.png](http://verification.fengzhongzhihan.top/202404132322432.png)
交运算中含有零因子, 因此不成立


![|450](http://verification.fengzhongzhihan.top/202406111555755.png)

证明三点 : 
![image.png|400](http://verification.fengzhongzhihan.top/202404132343460.png)
- 证明加法为交换群 : 封闭 (代数系统) + 单位元 + 逆元 + 交换律
- 证明乘法为封闭 + 有单位元 + 无零因子(不等于0且可以使别人=0) + 结合律 

![image.png|425](http://verification.fengzhongzhihan.top/202404132343791.png)
- 其实就是乘法得是一个群(条件单位元 + 可逆) -> 环R为除环 , 若除环可交换 -> 域
- 乘法是交换群 ->环R为域

除环的另一个定义
![image.png|300](http://verification.fengzhongzhihan.top/202404132348287.png)

例: 
![image.png|450](http://verification.fengzhongzhihan.top/202404132349944.png)
- 加法 : 可交换群, 单位元为0
- 乘法 : 可交换群, 单位元为1

三者关系
![image.png](http://verification.fengzhongzhihan.top/202404132359125.png)
- 除环 可交换 -> 整环 
- 整环, A- {e}每一个都有逆元->除环(群)
- 除环 可交换 -> 域
- 整环, A- {e}每一个都有逆元   或 有限整环-> 域
![image.png|600](http://verification.fengzhongzhihan.top/202404140000470.png)
- 倒数第二个是正确的
### 6.2.2 零因子和消去律
![image.png|475](http://verification.fengzhongzhihan.top/202404132316746.png)

### 6.2.3 有限环->除环
![image.png|475](http://verification.fengzhongzhihan.top/202404132350630.png)
-  有限环 + 满足消去律半群 -> 群
推论 : 有限整环必为域(素域)

### 6.2.4 域性质

![image.png|425](http://verification.fengzhongzhihan.top/202404132357084.png)
![image.png|237](http://verification.fengzhongzhihan.top/202404132358416.png)
满足正常性质

## 6.3 域的特征 素域

### 6.3.1 域, 子域, 域的特征

设F是一个域，S是 F的子集，若S在F的加法与乘法运算下也构成域，则称S为F的**子域**，F为S的**扩域**（或扩张).

若S是F的子域，则〈S，＋〉是〈F，＋〉的子群，故 ０∈S，〈S*，· 〉是〈F*，· 〉的子群（其中，S\*＝S－｛０｝，F\*＝F－｛０｝），故１∈S．
- 则F的任意子域必含F的０，１． 

设〈F，＋，· 〉是一个域，若〈F，＋〉中**非零元的周期为有限数p**，则称**域F的特征为p**．若〈F，＋〉中非零元的周期为∞，则称域F的特征为０．
- 则域F的特征或者为素数或者为０． 

![image.png](http://verification.fengzhongzhihan.top/202404242039593.png)

环到环的同态
![image.png](http://verification.fengzhongzhihan.top/202404242041544.png)
- 其实就是两个运算均保持


### 6.3.2 域中非零元的周期
**定理１** 设〈F，＋，· 〉是一个域，则： 
（１） 在加法群〈F，＋〉中，每个非零元都具有同样的周（阶）． 
（２） 如果〈F，＋〉中非零元素的周期为有限数p，则p必为素数． 

![image.png|450](http://verification.fengzhongzhihan.top/202404242027229.png)
![image.png|450](http://verification.fengzhongzhihan.top/202404242036115.png)

### 6.3.3 域和子域的特征相同
S是F的子域，则S与F具有相同的特征． 
证明：S与F的运算相同，具有相同的0，1,…． 
### 6.3.4 有限域的特征必为素数p
n元有限域的特征必为素数p，且p｜n． 
证明 若F是n元有限域，则〈F，＋〉是n阶群，故１∈F在〈F，＋〉中的周期必为有限数p，且p｜n．由定义，F的特征为p. 且由定理1知p为素数. 

### 6.3.5 有限域的子域同构
若域F的特征为素数p，则F中必存在与Zp同构的子域 Z'p． 
![image.png](http://verification.fengzhongzhihan.top/202404242046625.png)
从同构观点来看，特征为素数p的域F含有Zp为其最小子域
若域F的特征为０，则Z'0 ＝｛ie ｜i∈Z｝与整数环Z同构，不能构成F的子域 

### 6.3.6 特征为0 , 则与Q同构
若域F的特征为０，则F中含有与有理数域Q同构的子域． 
![image.png|500](http://verification.fengzhongzhihan.top/202404242056997.png)
![image.png|500](http://verification.fengzhongzhihan.top/202404242056130.png)
![image.png|500](http://verification.fengzhongzhihan.top/202404242056206.png)

如果将F中的单位元记为１，则F中的 元素me，可记作m， 可记作 特别地，对于素域Zp，其中的元素 ［i］＝ i \[1] 常记为i，在这种记号下， Zp＝｛０，１，…，p－１｝. 

# 7 格
## 7.1 格和偏序集

### 7.1.1 格, 并运算和交运算

定义１ 设〈L ,≤〉是一个**偏序集**，如果 任意x , y∈L ,｛x , y｝必有最小上界和最大下界，则称〈L ,≤〉为**格**． 

回顾 : 设R是A上的关系，如果R是自反的、反对称的、传递的，则称R是A上的偏序关系，简称偏序．
设P为一集合，如果在P上定义了一个偏序关系≤，则称P在偏序关系≤下构成一偏序集，记为〈P， ≼ 〉，也简记为P
![](http://verification.fengzhongzhihan.top/202406122027981.png)

举例 : 
- 例３ 设S是集合, 则〈P（S），包含〉是一个格， 对任意A，B∈P（S），A∪B是｛A，B｝的最小上界，A∩B是｛A，B｝的最大下界． 
- 例４ 设N是自然数集合，≤ 为通常自然数的小于等于关系，则〈N，≤〉是一个格。对任意i，j∈N，min｛i，j｝为i，j的最大下界，max｛i，j｝为i，j的最小上界． 

在格〈L，≤〉中，a, b的最小上界用 a＋b 表示，a, b的最大下界用 a\*b表示. 
任意 a, b∈L，由最小上界、最大下界的唯一性，a＋b，a\*b都在L上唯一确定 
将 ＋, * 视为L上的两个运算，通常称为〈L，≤〉上的**并运算**与**交运算**． 



### 7.1.2 运算律
幂等律, 交换律, 结合律, 吸收律
![image.png](http://verification.fengzhongzhihan.top/202404271726399.png)
证明结合律: 
![](http://verification.fengzhongzhihan.top/202406122020417.png)
证明吸收率: 
![|425](http://verification.fengzhongzhihan.top/202406122021005.png)
- 由于* 代表了最大下界, 因此 a * (a + b) <= a
- 由于a是(a, a + b)的下界, 则a <= a * (a + b)
![image.png|425](http://verification.fengzhongzhihan.top/202404271726816.png)

![image.png](http://verification.fengzhongzhihan.top/202404271727091.png)

最小上界 :  a | 最小公倍数  
最大下界 : r  | a

## 7.2 格和代数系统

格本身可以派生出一个代数系统<L, + \*>
- 满足条件幂等律, 结合律, 交换律,  吸收率
### 7.2.1 格性质
![image.png|325](http://verification.fengzhongzhihan.top/202404271728610.png)

![image.png](http://verification.fengzhongzhihan.top/202404271729811.png)

引理(代数系统的运算对应了* 和 + )
![image.png|475](http://verification.fengzhongzhihan.top/202404271729555.png)

![image.png|425](http://verification.fengzhongzhihan.top/202404271734937.png)

![image.png|425](http://verification.fengzhongzhihan.top/202404271735308.png)
![image.png|500](http://verification.fengzhongzhihan.top/202404271735487.png)

![image.png|450](http://verification.fengzhongzhihan.top/202404271736541.png)
![image.png|375](http://verification.fengzhongzhihan.top/202404271736267.png)
### 7.2.2 成为格条件
![image.png](http://verification.fengzhongzhihan.top/202404271732142.png)
![image.png](http://verification.fengzhongzhihan.top/202404271732576.png)
![](http://verification.fengzhongzhihan.top/202406122039469.png)
- 得到 a * b <= a只能证明是下界, 证明最大下界还得用c  来证, 得到a * b*  c = c

设S是一个集合，∪，∩为集合的并、交运算，则〈P（S），∪，∩〉是格，且其中的偏序为集合的包含关系．

## 7.3 子格和格同态

### 7.3.1 子格
![image.png](http://verification.fengzhongzhihan.top/202404271738798.png)

举例 
![image.png](http://verification.fengzhongzhihan.top/202404271739063.png)
![image.png](http://verification.fengzhongzhihan.top/202404271739886.png)

设〈L，≤〉是一个格， a≤b 
令T＝｛x | x∈L，x≤a｝，则T是L的子格 
令I［a，b］＝｛x | x∈L，a≤x≤b｝ 则I［a，b］是L的子格，通常称为L的一个闭区间． 

### 7.3.2 格同态
![image.png|450](http://verification.fengzhongzhihan.top/202404271743563.png)


### 7.3.3 格同态和保序映射
设f是格L到L‘ 的同态， 则f是偏序集L到L‘ 的保序映射， 
即任意 x，y∈L，当x≤y时，f（x）≤f（y） 
x ≤ y  ->  x * y＝x  ->  f（x）* f（y）＝f（x * y）＝f（x） ->  
f（x）≤ f（y） 

注意
![image.png|450](http://verification.fengzhongzhihan.top/202404271745000.png)


### 7.3.4 已知双射, 证同构
![image.png](http://verification.fengzhongzhihan.top/202404271747815.png)

已知同构: 证明 
![image.png|525](http://verification.fengzhongzhihan.top/202404271747134.png)
- 已知<=号, 转化为a* b = a
- 双射, 则值相同, 自变量相同

已知条件, 证明同构
![image.png](http://verification.fengzhongzhihan.top/202404271748882.png)
- 则需要证明f(x * y ) = f(x) * f(y)

## 7.4 完全格, 有界格, 补格

### 7.4.1 完全格, 有界格, 补格
**定义１** 设〈L，≤〉是一个格，如果L的**任意子集**均有最小上界和最大下界，则称其为**完全格．** 

**有限格必为完全格**． 
例如
- 无限格整数集Z在通常数的小于等于关系≤下是一个格，其子集E＝｛…，－４，－２，０，２，…｝既无最小上界也无最大下界 
- 实数闭区间［０，１］在通常的小于等于关系 ≤ 下是完全格， 实数开区间（０，１）则不然．
	- (0, 1)
- 集合A的幂集格〈P（A），含于〉是完全格． 

设〈L，≤〉是一个格，如果L中存在最大元与最小元，则称L是**有界格**． 
最大元也称为全上界或单位元，**用１表示**；
最小元也称为全下界或零元，**用０表示**，
对应地，有界格也称为有单位元和零元的格 
**完全格必为有界格** 

设L是一个有界格，a∈L，如果存在b∈L使 a + b＝１；a * b＝０ 则称b是a的**补元** 
- 补元未必是唯一的
〈P（A），含于 〉是A的幂集格，则对P（A）中任意元素S，知A－S是S的补元． 
![image.png|475](http://verification.fengzhongzhihan.top/202404271755059.png)

设L是一个有界格，如果L中每个元素都有补元，则称其为**补格**或有补格． 
 - 集合A的幂集格P（A）是补格 
 - 设L是有界格，则单位元１是零元０的唯一补元
 ![image.png|475](http://verification.fengzhongzhihan.top/202404271756162.png)
### 7.4.2 有界格性质
![image.png|475](http://verification.fengzhongzhihan.top/202404271754625.png)
## 7.5 分配格和模格

### 7.5.1 分配格和模格

![image.png](http://verification.fengzhongzhihan.top/202404271758431.png)
若a >= b 模格
![image.png|425](http://verification.fengzhongzhihan.top/202404272130619.png)
![image.png|525](http://verification.fengzhongzhihan.top/202404271801601.png)
设L是一个格，**如果L中的交对并可分配**，则并对交必可分配．反之亦然． 
![image.png|500](http://verification.fengzhongzhihan.top/202404271759146.png)
- 一个可分配, 则另一个一定可分配
### 7.5.2 分配格的消去律, 但是得两个条件共有
![image.png|400](http://verification.fengzhongzhihan.top/202404271804595.png)

**分配格的补元唯一**
![image.png|500](http://verification.fengzhongzhihan.top/202404272126142.png)
### 7.5.3 分配格必是模格
![image.png](http://verification.fengzhongzhihan.top/202404272132018.png)
### 7.5.4 模格的充要条件
![image.png|425](http://verification.fengzhongzhihan.top/202404272134901.png)
- 根据条件, 得到对应的式子, 再证明A >= B即可
![|500](http://verification.fengzhongzhihan.top/202406122226525.png)
## 7.6 布尔代数
### 7.6.1 布尔代数
一个格，如果既是补格又是分配格则称其为**布尔代数**．
格：L1-L4 
有界格：存在最大元与最小元 
补格：有界格，对所有a∈L，存在补元b 
分配格：并、交运算互相可分配 
- 则**布尔代数补元唯一**
![image.png](http://verification.fengzhongzhihan.top/202405061527141.png)
### 7.6.2 运算律?
![image.png|475](http://verification.fengzhongzhihan.top/202405061539341.png)
## 7.7 布尔表达式

### 7.7.1 布尔表达式
![image.png|550](http://verification.fengzhongzhihan.top/202405061540384.png)
![image.png](http://verification.fengzhongzhihan.top/202405061542023.png)


给定一个有序n元组〈a1，a2，…，an〉∈Bn，
通过布尔表达式f（x1，x2，…，xn）可唯一确定B中的一个元素f（a1，a2，…，an） 
f（x1，x2，…，xn）可视为Bn到B的映射，这时，称 f（x1，x2，…，xn）为**布尔函数**． 

![image.png|450](http://verification.fengzhongzhihan.top/202405061544124.png)

**极小项(有顺序之分)**
![image.png|500](http://verification.fengzhongzhihan.top/202405061545200.png)

![image.png](http://verification.fengzhongzhihan.top/202405061549605.png)

![image.png|450](http://verification.fengzhongzhihan.top/202405061546867.png)

**布尔代数B上任一布尔表达式 f（x1，x2，…，xn）均可化为积和范式** 
定理３表明，一个布尔函数 f（x1，x2，…，xn）可由其在〈０，０，…，０〉，〈０，０，…，１〉，…，〈１，１，…，１〉
这2^n个点处的值完全确定，就象一条直线可由直线上两点决定一样——尽管一条直线上有无穷多个点． 

# 8 图

## 8.1 图的概念
### 8.1.1 图的基本概念
设V是一个非空集合，E是一个V中元素的**无序对**构成的多重集，有序对G＝〈V，E〉称为一个图
其中，V称为顶点集，其元素称为顶点或点，E称为边集，其元素称为边． 
- 注意 : 可以有重边出现(多重集)
- 以上定义的图也称为**无向图**．

由元素u，v构成的无序对用uv或（u，v）表示，也可用一个字母(通常是带或不带下标的e)表示． 
![image.png|500](http://verification.fengzhongzhihan.top/202405061557891.png)

设G是一个图，u，v∈V(G)，e＝uv∈E(G)，称u，v为边e的端点，e为连接u，v的边，并称顶点u，v与边e**彼此关联**． 

在任意图中，同一条边关联的两点，称为**相邻点**，同一个点关联的诸边称为**相邻边**． 

![image.png|425](http://verification.fengzhongzhihan.top/202405061559311.png)
设G是一个图，若e∈E(G)的两端点重合为一点，即e＝uu，则称e为**自环**．若uv∈E(G)的重复度＞1，则称uv是**多重边**． 

设G是一个图，v∈V(G)，与v相关联的边数(自环计算两次)称为**v的度数**，记为dG(v)或简记为d(v)．度数为０的点称为**孤立点**，度数为1的点称为**悬挂点**，度数为奇数的点称为**奇顶点**，度数为偶数的点称为**偶顶点**． 图G中顶点的**最小度数记为δ(G**)，**最大度数记为△(G)** 
![image.png|475](http://verification.fengzhongzhihan.top/202405061600696.png)
设G是图，若V(G)，E(G)均是**有限集**，则称G为**有限图**． 并用υ(G)或υ表示图G的点数，ε(G)或ε表示图G的边数． 
设G是一个图 （１）如果υ＝1，ε＝０，称G是**平凡图**． 
（２）如果ε＝０，称G是**零图**． 
（３）不含多重边和自环的图称为**简单图**．
（４）含有多重边的图称为**多重图**． 
（5）既含有多重边又有自环的图称为**伪图**． 

设G是一个简单图，如果G中任意两顶点之间均有边相连，则称G为**完全图**，具有n个顶点的完全图记为**Kn**． 
![image.png](http://verification.fengzhongzhihan.top/202405061606304.png)

设G是一个图，如果存在V(G)的子集 V1，V2 使得 V1∪V2＝V(G)，V1∩V2＝空集，且V1中任意两点不相邻，V2中任意两点也不相邻，则称G为**二分图**，并称｛V1，V2｝为G的一个**二划分**，进一步地，若V1中每一点皆与V2中所有点相邻，则称G为**完全二分图**，且当 |V1|＝m，|V2|＝n时，将其记为**Km,n**． 
![image.png](http://verification.fengzhongzhihan.top/202405061607989.png)
- kmn 是完全二分图
- km 是完全图
- 但是完全二分图不为完全图

设G是一个图，k是一个常数，若G中每个顶点的度数均为k，则称G为**k次正则图**． 
- k = n - 1   完全图

真子图和生成子图
![image.png|500](http://verification.fengzhongzhihan.top/202405061609647.png)
- 生成子图要求点全部包含, 边是子集

导出子图
![image.png|475](http://verification.fengzhongzhihan.top/202405061610609.png)
![image.png|475](http://verification.fengzhongzhihan.top/202405061610516.png)
- 点导出子图, 点都有, 边是点的边

设G是具有n个顶点的简单图，从这n个顶点构成的完全图Kn中删去G的所有边，但保留顶点集V(G)所得到的图称为G的**补图**，简称G的补，记为～G． 
![image.png|475](http://verification.fengzhongzhihan.top/202405061611135.png)

注意: 在一个图中，顶点的位置，边的长度及形状是不加考虑的，例如图1.8(a)与图1.8(b)看起来似乎不相同，但实际上是同一个图． 
![image.png|425](http://verification.fengzhongzhihan.top/202405061612537.png)

图的同构
![image.png|500](http://verification.fengzhongzhihan.top/202405061612041.png)

![image.png|425](http://verification.fengzhongzhihan.top/202405061613603.png)

![image.png|425](http://verification.fengzhongzhihan.top/202405061615254.png)

![image.png|425](http://verification.fengzhongzhihan.top/202405101713160.png)
![image.png|400](http://verification.fengzhongzhihan.top/202405101714499.png)
### 8.1.2 握手定理
![image.png|475](http://verification.fengzhongzhihan.top/202405061602136.png)

举例
- 在一次围棋比赛中，下过奇数盘棋的人数是偶数
- 总有偶数个人认识奇数个人
证明 : 如果奇顶点个数为奇数, 则乘起来是奇数, 则剩余的偶顶点所有度数加起来为奇数, 矛盾

![image.png|575](http://verification.fengzhongzhihan.top/202405061603165.png)

### 8.1.3 例题
![image.png|525](http://verification.fengzhongzhihan.top/202405061615571.png)
![image.png|525](http://verification.fengzhongzhihan.top/202405061616194.png)

## 8.2 路与连通
### 8.2.1 路, 迹, 连通
定义1 图G的一个非空点、**边交替序列 W**＝v0e1v1 e2 v2…ek vk 称为一条从v0到vk的**路径**或(v0，vk)-路径，其中，vi-1，vi是ei的**端点** (1≤i≤k)． 
称v0为W的**起点**，vk为W的**终点**，vi (1≤i≤k－1)为W的**内点**，k为W的 **路长**．

若W＝v0e1v1e2v2…ekvk是一条(v0，vk)-路径，W逆转后得到的点、边交替序列 vkek…v2e2v1e1v0 必为一条(vk，v0)-路径，这条路径可记为**W^{-1}**．
路径W的部分相连项构成的子序列 vieivi+1…ejvj，０≤i≤ｊ≤k 也必构成一条路径，这条路径称为W的**节**． 
W可以与另一条路径 W ' ＝vkek+1vk+1…elvl也为一条路径，将W与W ' 衔接在一起便得一条新路径，该路径可记为**WW '**  

简单图中可以直接用顶点来表示路径

设v0e1v1e2v2…ekvk为图G中的一条路径，若边e1，e2，…，ek互不相同，则称该路径为**迹**（**简单通路**）；若点v0，v1，…，vk互不相同，则称该路径为**路** 
则 : **一条路必为一条迹**
- 边不同: 迹
- 点不同: 路

设v0e1v1e2v2…ekvk是图G中的一条路径且k≥1，如果v0＝vk，则称该路径为**闭路径**，否则称为开路径． 特别地，若v0e1v1e2v2…ekvk是一条迹，k≥1，当v0＝vk时称为**闭迹**，否则称为开迹．**闭迹也称为回路**． 

设v0e1v1e2v2…ek-1vk-1ekv0是一条**闭迹**，如果v0，v1，…，vk-1互不相同，则称该闭迹为**圈**或k圈，且当k为偶数时称为偶圈，k为奇数时称为奇圈． 
- 点不同: 一个圈
- 如果点相同, 对应着多个圈的情况

设G是一个图，u，v∈V(G)，如果存在从u到v的路，则称u，v是相连的或**连通的**，若G中任意两点都连通，则称**图G是连通的**

设G是一个图，u，v∈V(G)，若u，v是连通的，则称**最短(u，v)-路的长为u，v的距离**，记为**d(u，v)**． 当u，v不连通时，可以认为u，v的距离是∞ 

图G中顶点之间的连通关系是一个等价关系 
根据该关系可将V(G)划分成一些等价类V1，V2，…，Vn，每个Vi导出的子图G(Vi)称为G的一个**连通分支**
G的**连通分支数**通常用ω(G)表示，
- 显然 G是连通的 <=> ω(G)＝1． 

设e是图G的一条边，如果 ω(G－e)＞ω(G)， 则称e是G的**割边**． 

![image.png|475](http://verification.fengzhongzhihan.top/202405101636595.png)
a有割边, b无割边
### 8.2.2 顶点数至少为2必含有圈
若图G中每个顶点度数至少为２，则G中必含有圈． 

连接无向图的每一对不同顶点之间都存在简单通路
![image.png](http://verification.fengzhongzhihan.top/202405101646191.png)

### 8.2.3 二分图无奇圈

一个图G是二分图 <=> G中不含奇圈． 
![|475](http://verification.fengzhongzhihan.top/202406130920326.png)
必要性 : 
- 因为若为奇圈, 则k一定为偶数
- 若k为偶数, 则vk和v0属于同一集合划分, 矛盾

构造划分
- 任意顶点v, 将奇数距离划分v1, 偶数距离划分v2
- 两顶点都在v1或v2中, 则顶点之间距离为偶数
- 若v1,v2两者内部有连线, 则u和v之间距离为奇数, 成了奇圈


### 8.2.4 顶点, 边, 连通分支不等式
![image.png](http://verification.fengzhongzhihan.top/202405101647041.png)
当G有n个顶点ω个分支时，怎样让边最多？ 
G的一个连通分支是n－ω＋1个点的完全图，其余ω－1个连通分支均是弧立点。 
- 则共有边 : (n - w + 1)  * (n - w) / 2
- 至少有n - w + 1个点的连通图, 则至少有n - w个边

当ω＝1时，ε≥n－1．即n个顶点的连通图至少有n－1条边 
**具有n个顶点，n－1条边的连通图称为最小连通图．** 

![image.png|550](http://verification.fengzhongzhihan.top/202405101655361.png)
反证法

![image.png|500](http://verification.fengzhongzhihan.top/202405101656438.png)
- 设一个顶点的连通分支为G' , 则有G'中至少还有一个奇度顶点, 由于G只有两个奇度顶点, 则G'两个奇顶点, 就是G的两个奇顶点, 则存在通路
## 8.3 最短路

### 8.3.1 距离

设G是一个图，若对G中每条边e都规定一个非负实数w(e)，则称G为**赋权图（或权图**），w(e) 称为边e的权．G的边与非负实数的这种对应关系(用w表示)称为**权函数**． 

设G是一个权图，Ｈ是G的子图，Ｈ中各边的权之和称为**子图Ｈ的权**，记为w(Ｈ)，即 

![image.png](http://verification.fengzhongzhihan.top/202405101703514.png)

![image.png](http://verification.fengzhongzhihan.top/202405101703998.png)

### 8.3.2 Dijkstra
![](http://verification.fengzhongzhihan.top/202406131458225.png)

![image.png](http://verification.fengzhongzhihan.top/202405101705296.png)
Dijkstra算法算法的时间复杂度是O(n2) 

**求两个顶点之间的最短通路**
- 此时将到点的距离转化为到集合的距离
![](http://verification.fengzhongzhihan.top/202405181504829.png)

![image.png](http://verification.fengzhongzhihan.top/202405101712187.png)

![image.png](http://verification.fengzhongzhihan.top/202405101707219.png)
⚠️upload failed, check dev console
![image.png](http://verification.fengzhongzhihan.top/202405101715223.png)
![image.png](http://verification.fengzhongzhihan.top/202405101715383.png)
- 4 1 1 1 1
- 3 2 1 1 1
- 2 2 2 1 1
- 2 2 2 2 0
- 3 2 2 1 0
## 8.4 有向图
设V是一个非空集合，A是一个由V中元素的**有序对**构成的多重集，有序对D＝〈V，A〉称为一个有向图，其中，V称为顶点集，其元素称为顶点或点；A称为**弧集**，其元素称为弧． 

设D是一个有向图，若a＝〈u，v〉∈A(D)，则称a从u连接到v，且称u，v与a彼此相关联；称u是a的**尾或起点**，v是a的**头或终点**，且将u，v统称为a的**端点**． 

对于每个有向图D，忽略其弧的方向，即将其每条弧均视为一条无方向的边，这样得到的(无向)图G称为D的**底图**， 
有向图路径可以用顶点序列来表示, 也可以用弧序列来表示
**定向图** : 给无向图的边加上方向, 即确定弧

存在有向(u，v)路，则称v是从u**可达**的 
若u，v互相可达，则称u，v是**双向连通**的 
若对D中任何两顶点，至少有一顶点可从另一顶点可达，则称D是**单向连通图** 
若D中任何两顶点都是双向连通的，则称D是**双向连通图或强连通图** 
Ｄ强连通 <=> Ｄ恰有一个强连通分支。 

有向图D每两个顶点中有一个弧, 则称为**竞赛图**
- D为竞赛图 <-> D为完全图的定向图

其中σ-(D)表示最小入度, σ+(D)表示最小出度
- 顶点的度为入度和出度的和
![](http://verification.fengzhongzhihan.top/202406131509959.png)

## 8.5 图的矩阵表示
一般无向图记为G, 有向图记为D
### 8.5.1 关联矩阵
设G是一个无自环的图 图的**关联矩阵** : 行v, 列Σ (顶点和边的关系)
- 如果vi关联于ej, 则为1, 否则为0
![](http://verification.fengzhongzhihan.top/202405181446479.png)
则有性质
- 每一列恰好有两个1
- 平行边的1位置和个数相同
- 每一行中1的个数是对应顶点的度数； 

D中关联矩阵
- v为头, -1  
- v为尾 1
- 否则为0
则有
- 每一行中1的个数是对应顶点的出度数，－1的个数是对应顶点的入度数，非零元的个数是对应顶点的度数；

### 8.5.2 邻接矩阵
设G是无平行边的图, 图的邻接矩阵: 行和列都为v, 值为权重
- 如果vi和vj相邻, 则为1, 否则为0

则有性质
- 无向图对称矩阵
- 无向图的邻接矩阵除了对角线均为1, 则为完全图

邻接矩阵
- 有弧 : 1
- 无弧 : 0
![](http://verification.fengzhongzhihan.top/202405181454173.png)
![](http://verification.fengzhongzhihan.top/202405181501354.png)

### 8.5.3 路径矩阵
路径矩阵G: 顶点 * 顶点
- 有路: 1
- 无路: 0
- 若G为连通图, 则均为1
### 8.5.4 长度为k的路径数目

X是G的邻接矩阵, 令$$(X^k) = (x_{ij}^{k})$$
则xij^k等于顶点vi, vj之间长度为k的路径数目, 即矩阵相乘结果
- 其中k表示路径的长度
- 求得的数字表示路径的数目

![](http://verification.fengzhongzhihan.top/202405181456966.png)
注意: 回路是闭迹, 这里说的有问题

![](http://verification.fengzhongzhihan.top/202405181459609.png)
- 回路代表对角线上的点

有向图的Xij^k, 与无向图同理
![|625](http://verification.fengzhongzhihan.top/202405181503626.png)

## 8.6 习题

![|575](http://verification.fengzhongzhihan.top/202405181507199.png)
- 在图G中不存在路, 则~G中存在路

![|525](http://verification.fengzhongzhihan.top/202405181508019.png)
- 同构: 边相同

![|550](http://verification.fengzhongzhihan.top/202405181511222.png)
e在G某回路中
- 如果回路中有相同的边, 则去掉多余的回路, 得到C1
- 如果回路中没有相同的顶点, C1就是圈
- 有相同的顶点
	- 出现在通路中, 则直接连接圈
	- 若未出现在通路上, 直接删除, 对新回路分析
![|525](http://verification.fengzhongzhihan.top/202405181511004.png)
![|525](http://verification.fengzhongzhihan.top/202405181513685.png)

# 9 Euler图和humiton图

## 9.1 Euler图
### 9.1.1 Euler图
定义: 
设G为一个图, 包含所有边的迹称为**Euler迹**, 闭的Euler迹称为**Euler闭迹(回路)**,具有Euler回路的图称为**Euler图,** 开的Euler迹称为**Euler开迹**, 具有Euler开迹的图称为**半Euler图**
- 即从一个顶点出发, 走遍所有边, 能回到原位置, 则为Euler图, 否则为开Euler图
- 也就是一笔画路线
![](http://verification.fengzhongzhihan.top/202405181515256.png)

Euler图可以有孤立点 : 对于Euler回路没有影响
- 一个Euler有向图, 如果没有孤立点, 则必为强连通

D中, 若d-v = d+v (入度 == 出度) , 则称顶点v为**平衡**的. 
若D中每个顶点都是平衡的, 则称为**平衡图,** 若存在k使得每个顶点入度 == 出度 == k, 则称为**一致平衡**

Fleury算法(找欧拉通路)
- 割边(桥)最后走, 其他随便走
![](http://verification.fengzhongzhihan.top/202405181529608.png)

### 9.1.2 无向图判定条件
G连通, 顶点度全为偶数: <=> Euler图
G连通, 顶点度恰有两个奇数: <=> 半Euler图
则
- k为偶数的k次正则图则为Euler图
	- 度数为k
- k为奇数的完全图都是Euler图
	- 度数为k - 1

G连通, G是若干条边不相重的圈的并 <=> Euler图
![](http://verification.fengzhongzhihan.top/202405181518306.png)

### 9.1.3 有向图判定条件
D为单连通有向图, D的所有顶点均平衡<=>D为Euler有向图
D中恰有两个奇顶点满足d-u = d+u + 1 ,  d+v = d-v + 1, 其他顶点均为平衡 <=> D为半Euler有向图
![](http://verification.fengzhongzhihan.top/202406141100116.png)



## 9.2 Hamilton图
### 9.2.1 Hamilton图
G中包含所有顶点的圈称为**Hamilton圈**, 含有Hamilton圈的图称为**Hamilton图,** G中含有所有顶点的路称为**Hamilton路**, 含有Hamilton路的图称为**半Hamilton图**
![|575](http://verification.fengzhongzhihan.top/202405181530155.png)
- 经过所有顶点, 未必要经过所有边
- 如果能回来, 则为Hamilton图, 否则为半Hamilton图

Hamilton图性质
- 连通 , 每个顶点度 >= 2
	- 存在度为1的顶点, 则无哈密顿回路
	- 若顶点v度为2, 则回路必经过以v为端点的两条边
	- 若顶点v度>2, 则回路只使用以v为端点的两条边
	- 如果图中必须出现的边构成了回路, 但是并没有遍历所有顶点, 则无哈密顿回路
- n个顶点, 则哈密顿回路长为n, 哈密顿通路长为n-1
- 哈密顿回路不唯一

![](http://verification.fengzhongzhihan.top/202405181536886.png)

![|450](http://verification.fengzhongzhihan.top/202405181536068.png)

### 9.2.2 必要条件
Hamilton图, 对顶点集V中任意非空子集S, 有
w(G - S) <= |S|
- (必要条件), 如果不满足, 则不是哈密顿图
![](http://verification.fengzhongzhihan.top/202405181537921.png)
### 9.2.3 充分条件(迪拉克定理)
**Dirac’s theorem(迪拉克定理)** 
设G是简单图，且υ≥３，δ≥υ/2，则G是Hamilton图． 
- 充分条件, 不是必要条件
- σ代表最小度数
- 如果不满足, 不一定不是Hamilton图
![](http://verification.fengzhongzhihan.top/202405181541418.png)

则
- 完全图K5的顶点度数都为4 >= 5 / 2, 为哈密顿图
- 任意完全图Kn(n >= 3)一定具有Hamilton图
	-  n - 1 >= n / 2

### 9.2.4 充要条件 G + uv

设G是简单图，u和v是G中不相邻的顶点，且满足
d(u)＋d(v)≥υ　　　                     　　　　
    则G是Hamilton图当且仅当G＋uv是Hamilton图．
为判断G是否是Hamilton图，可对图G中满足d(u)＋d(v)≥υ的不相邻顶点对进行连接，且这种连接可反复进行，由此引出图G的闭包的概念．

设G是一个图，反复连接满足d(u)＋d(v)≥υ的不相邻顶点u，v，直到没有这样的顶点对为止，这样得到的图称作图G的**闭包**，记为**C(G)**．
![](http://verification.fengzhongzhihan.top/202405181543088.png)
简单图G是Hamilton图当且仅当C(G)是Hamilton图．

推论1　  若C(G)是完全图，则G是Hamilton图．
推论２　若G中任意不相邻顶点u，v均满足d(u)＋d(v)≥υ，则G是Hamilton图．

![](http://verification.fengzhongzhihan.top/202405181546099.png)
### 9.2.5 有向图的强连通
Hamilton有向图必定是强连通的。 
定理４ 竞赛图必是半Hamilton有向图。 
定理５ 强连通的竞赛图必是Hamilton有向图。 

设有n个城镇，其中每两个城镇之间的直接距离是已知的，一个货郎自一城镇出发巡回售货，问这个货郎应该如何选择路线，使每个城镇恰好经过一次，并且总的行程最短．
- 显然，这个问题也就是要在一个带权完全图中，找一个权最小的Hamilton圈． 

做法 : 
(1) 任选一点v0作起始点，找一个与v0最近的相邻点x，得到一条路v0x；
(2) 设已得到路W＝v0v1…x，x是新加到这条路W中的点，从不在路中的所有点中，选一个与x最近的相邻点y，将它加到W中，构成一条新的路：v0v1…xy，重复该步骤，直到G中所有顶点都在所形成的路中；
(3) 连接v0和最后加到路中的顶点，构成一圈，它就是求出的Hamilton圈．

![](http://verification.fengzhongzhihan.top/202405181553313.png)
![](http://verification.fengzhongzhihan.top/202405181554667.png)

思想: 贪心
- 但是得到的结果未必相同? 
![](http://verification.fengzhongzhihan.top/202406141135766.png)

![](http://verification.fengzhongzhihan.top/202405181554116.png)
![](http://verification.fengzhongzhihan.top/202405181555779.png)
![](http://verification.fengzhongzhihan.top/202405181556309.png)
![|251](http://verification.fengzhongzhihan.top/202406141139404.png)

# 10 树

## 10.1 树
### 10.1.1 树, 树叶,分枝点, 森林
连通无回路的图称为**树**，树中度为1的点称为**树叶**，度大于1的点称为**分枝点**或**内点**，每个连通分支均为树的图称为**森林**． 

### 10.1.2 树的等价条件
定理1　设图T是有n个顶点、ε条边的非平凡图，则下列各条等价．
(1)  T是树．
(2)  T中无回路，且ε＝n－1．
(3)  T连通，且ε＝n－1．
(4)  T中无回路，且在T的任意两个不相邻点之间添加一边恰得一条回路．
(5)  T连通，删去任一边则不连通．
(6)  T的任意两个不同顶点之间恰有一条路．

### 10.1.3 至少有两片树叶
任意一棵非平凡树T中，至少有两片树叶． 
![|525](http://verification.fengzhongzhihan.top/202405181754269.png)
![](http://verification.fengzhongzhihan.top/202405181756014.png)
- 使用条件 : (n - 1) * 2 = 边数

![|375](http://verification.fengzhongzhihan.top/202405181803703.png)
树的直径 ? 
![|525](http://verification.fengzhongzhihan.top/202405181805735.png)

若只有根节点和一个叶节点, 则为路
![|525](http://verification.fengzhongzhihan.top/202405181806273.png)
- 证明其他内点度数为2
## 10.2 生成树
### 10.2.1 生成树
若图G的生成子图T是树，则称T为G的**生成树**． 
![](http://verification.fengzhongzhihan.top/202405181808722.png)

权图G中带权最小的生成树称为**最小生成树**或**最优树** 
### 10.2.2 连通图 <-> 生成树
G是连通图当且仅当G有生成树
### 10.2.3 Kruskal
Kruskal算法得到的图T是G的最小生成树． 
思路: 
![](http://verification.fengzhongzhihan.top/202405181810431.png)
![](http://verification.fengzhongzhihan.top/202405181811031.png)

Prim算法
![](http://verification.fengzhongzhihan.top/202405181812154.png)
![](http://verification.fengzhongzhihan.top/202405181813855.png)

## 10.3 有向树

### 10.3.1 有向树
有根树 : 一个顶点入度为0, 其余顶点入度均为1
- 入度为0的顶点称为根
- 设T是一棵有根树，r是T的根，则r到其余每个顶点恰有一条有向路．

设u是有根树的分枝点，若从u到s有一条弧〈u，s〉，则称s为u的**儿子**，u为s的**父亲**；同一父亲的儿子称为**兄弟**；若从u到v有一条有向路，则称v是u的**子孙**，u是v的**祖先**；从根到某一顶点的路长称为该顶点的**路长**或**层数**，从根到树叶的**最大层数**，称为有根树的**高**． 
- 注意这个层数是指路长, 最大层数是高

设u是有根树T的一个顶点，Vu是u及其子孙构成的顶点集，Vu的导出子图称为T的以u为根的**子树**
例如，图3.3(b)是图3.3(a)的以a1为根的子树．
![|475](http://verification.fengzhongzhihan.top/202406152005334.png)

在有根树中，将每个分枝点发出的弧从左到右依次标以正整数1，2，3，…，则该有根树称为**有序树**
![](http://verification.fengzhongzhihan.top/202405251024826.png)

在有序树中，如果每个（分支点）v都满足ｄ＋(v)≤m，则称该有序树为**m叉树**，如果每个（分支点）v都满足ｄ＋(v)＝m，称该有序树为**正则m叉树**． 
- <= : m叉树
- == 正则m叉树


一类重要的m叉树是二叉树和正则二叉树，对于二叉树，一个分枝点的两个(或一个)儿子按其位置分别称为**左儿子**、**右儿子**，以左、右儿子为根的子树分别称为**左子树**、**右子树**． 


### 10.3.2 正则m叉树的数量关系
正则m叉树中, 分枝点数i与树叶数l满足
**(m - 1) i = l - 1**
- 点数之间关系
设T是正则m叉树，I表示分枝点的路长总和，L表示树叶的路长总和，i是分枝点数
**L＝(m－1)I＋mi**
- 路长之间关系

![|450](http://verification.fengzhongzhihan.top/202405251044396.png)


# 11 平面图和着色

## 11.1 平面图
### 11.1.1 平面图, Jordon曲线
如果一个图的边在端点之外不相交, 则称为**平面图**(可平面嵌入)
平面图G的这样一种画法，称为G的一个**平面嵌入**.
平面图G的平面嵌入称为平图
- 一个图长得不像平面图, 可能可以画成平面图
![](http://verification.fengzhongzhihan.top/202405251046082.png)

连续的, 自身不相交的封闭曲线称为**Jordon曲线**
![|367](http://verification.fengzhongzhihan.top/202405251047192.png)
Jordon曲线J把平面分成了两部分
- 其中一部分是无界的，这一部分(不含曲线J本身)称为J的**外部**，记为**extJ**，extJ的点称为J的**外点**，extJ与J之并称为**extJ的闭包**，记为**ExtJ**；
- 另一部分(不含曲线J本身)称为J的**内部**，记为**intJ**，intJ的点称为J的**内点**，intJ与J之并称为**intJ的闭包**，记为**IntJ**． 

**引理**
设J是一条Jordon曲线，任何连接J的内点与外点的曲线必与J相交． 

设G是一个平图，则G把平面划分成若干个连通区域，每个**连通区域的闭包**称为G的一个**面**，其中恰有一个无界的面，称为**外部面**
- 面 f 的边界中含有的边数(割边计算2次)称为该面 f 的**次数（度数）**, 记为**Deg(f)** 
![](http://verification.fengzhongzhihan.top/202406152017062.png)

![|475](http://verification.fengzhongzhihan.top/202405251051099.png)
- 注意, 此时v1v2计算了两次, R3只计算了一次
### 11.1.2 Euler公式

Deg(f) 之和 = 2m 
![|375](http://verification.fengzhongzhihan.top/202405251543104.png)

Euler公式 : 若G是连通平图，则
v - m + f = 2
- v : 顶点  m: 边数 f : 面
- 顶点 - 边数 + 面 = 2

证明 (数学归纳)
- Σ = 1时成立  , 自环 or 线段
- Σ = m - 1时成立, m时成立
	- 删去度为1的顶点, 则有 v -1顶点, m- 1条边, f个面
	- 如果没有度为1的顶点, 则必有圈, 删除圈中的一条边, 则有v顶点, f - 1面, m- 1边

推论 1  给定平面连通图G，则G的所有平面嵌入有相同的面数． 
推论２ 若G是平面简单图，υ≥３，则 ε≤３υ－６． 
- v - m + f = 2         每个面至少由3个边组成 3 * f <= 2 * m ->  f <=  2 / 3m -> 2 + m - n <= 2 / 3 m -> n - 1/3 m >= 2 -> 3n - m >= 6
推论３ 若平图G的每个面由至少四条边围成，则 ε≤2υ－4． 
	设面f  则 4 * f <= 2 * m  -> n - m + f = 2 -> 2 + m - n <= 1 / 2 m
	-> m <= 2 n - 4
推论４ K5与K3,3是非平面图． 
- Σ = C52 = 10, v = 5
- Σ = 9 v = 6  
![](http://verification.fengzhongzhihan.top/202405251055299.png)
关键
- rL <= 2m

![|625](http://verification.fengzhongzhihan.top/202405251057812.png)
## 11.2 顶点着色
设G是一个图，对G的每个顶点着色，使得没有两个相邻的顶点着上相同的颜色，这种着色称为图的**正常着色**． 
若图G的顶点可用k种颜色正常着色，称G为**k-可着色的**． 
使G是k-可着色的数k的最小值称为**G的色数**，记为χ(G)
- 如果 χ(G)＝k，则称G是k色的． 
![](http://verification.fengzhongzhihan.top/202405251101793.png)
### 11.2.1 常见的染色图
- 完全图: X(kn) = n, X(~Kn) = 1
- 对于n个顶点构成的圈c, 如果n为偶数, X(cn) = 2, n为奇数, X(Cn) = 3
- 非平凡树, X(T) = 2
- G二分图 <=> x(G) = 2
### 11.2.2 色数和度数的数量关系
X(G) <= 1 + ▲(G)
	若简单连通图G不是完全图且不是奇圈，则 χ(G)≤△(G) 

对于任意简单图G，有 χ(G)≤1＋△(G)． 需要证明G是1＋△(G)-可着色的
对G的顶点数施行归纳法，当υ＝1时，△(G)＝0，显然G是1-可着色的
假设υ＝n－1时成立，χn-1(G)≤1＋△n-1(G) 现设υ＝n
- 当△n-1(G)=△n(G)
	- 删去G中一点v及其关联边，得到一个具有n－1个顶点的图，则该图是1＋△n-1(G)可着色的
	- 再将v及其关联边加回该图得到图G，顶点v的度数是△n(G)，v的相邻点最多着上△n(G)种颜色，因此可将v着上第1＋△n(G)种颜色，所以，G是1＋△n(G)可着色的．从而知χn (G)≤1＋△n(G)． 
- △n-1(G)<△n(G)时，给顶点v上新一种颜色，满足χn (G)≤1＋△n(G) 

![](http://verification.fengzhongzhihan.top/202406152048623.png)
三分图

## 11.3 面着色

### 11.3.1 面着色
设e是图G的一条边，如果 ω(G－e)＞ω(G)， 则称e是G的**割边**． 
例如, 在图4.1中，e1，e2，e3是三条割边，其余边不是割边． 
![Uploading file...mi9fl]()
- 一个没有割边的连通平图，称为**地图**． 
设G是一个地图，对G的每个面着色，使得没有两个相邻的面着上相同的颜色，这种着色称为地图的**正常面着色** 
地图G可用k种颜色正常面着色，称G是**k-面可着色**的． 
使得G是k-面可着色的数k的最小值称为**G的面色数**，记为**χ*(G)**．
若χ*(G)＝k，则称G是**k-面色**的． 
 ![](http://verification.fengzhongzhihan.top/202405251120124.png)
地图的k-面可着色问题便可化为平面图的k-(顶点)可着色问题 

### 11.3.2 四色定理和五色定理

1. 任何平面图的色数都<=4
2. 任何无自环的平面图G是5-可着色的
则任何地图都是5可面着色的
# 12 命题逻辑

## 12.1 命题

具有真假意义的陈述句称作**命题**．

在语法上, **命题必须是陈述句**。
- 疑问句、祈使句和感叹句等, 它们无所谓真假, 所以不是命题

命题具有唯一的真值
- 这与我们是否知道它的真假是两回事。

陈述句为真或为假的这种性质, 称为命题的**真值**(truth)。
凡与事实相符的命题为**真命题**, 其真值为**真;** 
- 否则称为**假命题**, 其真值为**假**。

下列语句不是命题
- 请关好门！
- 好大的雪啊！
- 他明天会来吗？
- **本语句为假**
	- 悖论不是命题

如果一个命题是真的，则说这个命题的真值(或值)为“真”，否则，说这个命题的真值(或值)为“假”．
- 通常，“真”用１或T表示，“假”用０或F表示．

为了对命题作逻辑演算，需要将**命题符号化**. 
一般，**用大写字母P，Q，R等表示命题**．例如可用P表示“北京是中国的首都”，Q表示“雪是黑色的”，等等 
但更多的，把这些字母称作**命题变元**或**命题变量**。（变量的值取1或0） 
- 变量-命题变元，常量-命题 

一个命题，如果不能再分解为更简单的命题，则称之为**简单命题**或**原子命题**，
否则，如果它可以分解成更简单的命题及一些“逻辑联结词”，则称之为**复合命题**. 
简单命题或原子命题
- 我在讲课。
复合命题(原子命题 + 逻辑连接词)
- 我在讲课 而且 外面在下雨。

## 12.2 联结词

1. 否定 : 
![](http://verification.fengzhongzhihan.top/202405251136623.png)

2. 析取:记为P∨Q

3. 合取: 记为P∩Q

4. 蕴含: P→Q
P→Q读作“如果P则Q”．
![|245](http://verification.fengzhongzhihan.top/202405251137816.png)
5. 等价 : P<->Q
![](http://verification.fengzhongzhihan.top/202406161157474.png)

∨，∧，→， <-> 均联结两个命题，因此称为**二元联结词** 
否 只作用于一个命题，称为**一元联结词**. 

例１张三和李四都会修电视机．
若用P表示“张三会修电视机”，Q表示“李四会修电视机”，则上述命题可表示为P∧Q．
例２ 张三与李四是表兄弟
   这里虽然用了一个联结词“与”，但这是一个不能再进行分解的简单命题，因此只能用一个字母比如P表示．
例３　除非你努力，否则将失败．
   这句话的意思应是如果你不努力，就会失败. 因此，若用P表示“你努力”，Q表示“你失败”，则上述命题可表为(否P)→Q．
![](http://verification.fengzhongzhihan.top/202405251141167.png)
## 12.3 合式公式

### 12.3.1 合式公式, 指派
合式公式定义如下: 
(１)　命题变元及命题常元０、１是合式公式．
(２)　如果A，B是合式公式，则(否 A)，(A∨B)，(A∧B)，(A→B)，(A <-> B)是合式公式．
(３)　任何合式公式均通过有限次使用(１)、(２)得到．

设G是一个**公式**，对G中出现的**每个命题变元指定一个真值１或０**，则得到该公式中命题变元的一个**真值组合**，称之为对公式G的一个**指派(或解释)**．

公式A在指派I下的真值可记为**A^I**.

例１　对于公式(P∧Q)→Q∨R
- 指定P为１，Q为１，R为１即是对公式的一个指派，在该指派下，公式的真值为１


另一种表达形式
![|450](http://verification.fengzhongzhihan.top/202405251146814.png)
![|475](http://verification.fengzhongzhihan.top/202405251146914.png)
![|500](http://verification.fengzhongzhihan.top/202405251148727.png)
求出一个公式A在所有指派下的真值并列成表，即得到公式A的“**真值表**”． 
![|450](http://verification.fengzhongzhihan.top/202405251149264.png)
设A为一公式，如果在所有指派下A均为真，则称A为**永真式**，
如果在所有指派下A均为假，则称A为**永假式**，
如果至少有一个指派使A为真，则称A为**可满足的**． 
**永真式**又称**重言式**，**永假式**又称**矛盾式**． 


### 12.3.2 优先级
![|500](http://verification.fengzhongzhihan.top/202405251142032.png)
### 12.3.3 代入原则
设A是一个永真式，P１，P２，…，Pn为其中出现的所有命题变元，A１，A２，…，An是任意一组公式，若用Ai (１≤i≤n) 代替A中的Pi得到公式B，则B必为永真式． 
“＝”(<=>)是一个关系符，表达两公式之间的一种关系.
 “<->”是逻辑联词，把两个公式联接成一个新的公式. 


## 12.4 等价式

### 12.4.1 公式之间的等价
任意指派下, A和B的真值都是相同的, 则**A,B等价**, 记为A<=> B, A = B
- 注意 : <=>是公式间的关系, 而<->代表连接公式
- 证明等价式可以用真值表来写(实在没办法了)
P<=>Q 的充要条件为 P<->Q为永真式(重言式)
P->Q = 非P V Q
P<->Q = (P->Q) 且 (Q->P) 
= (P^Q) V (~P^~Q)
![|375](http://verification.fengzhongzhihan.top/202405311513858.png)

```
右
=`PVQ ^ `QVP
= ((`PVQ)^`Q) V ((`PVQ)^P)
= ((`P ^ `Q) V (Q ^ Q`))  V (~P ^ P) V (Q ∩ P)
= (P^Q)V  (`P^`Q)
=P<->Q   
```
![|425](http://verification.fengzhongzhihan.top/202405311516447.png)
![|425](http://verification.fengzhongzhihan.top/202405311517184.png)

若A1是公式A的一部分, 且A1为公式, 则A1为A的**子公式**

设A是一个公式，A１是A的子公式. 如果公式B１满足A１＝B１，则用B１替换A１在A中的一个或若干个出现后得到的公式B必满足A＝B
### 12.4.2 公式等价是一种等价关系
定理１　设A，B，M是公式，则
		(１)　A＝A
		(２)　若A＝B，则B＝A
		(３)　若A＝B，B＝M，则A＝M
	
即，公式的等价“＝”满足自反、对称、传递，是一个等价关系.

## 12.5 范式
### 12.5.1 文字, 短语, 子句, 析取范式, 合取范式

**文字** : 命题变元及其否定
**短语(基本合取式)** : 文字的合取
**子句(基本析取式)** : 文字的析取

析取范式 : 有限个短语的析取   ^ V ^
合取范式 : 有限个子句的合取   V ^ V
- 短语既是析取范式又是合取范式，子句同样既是析取范式又是合取范式．
- 任意命题, 都存在等价于它的析取范式和合取范式
PVQ^R 
- 是析取范式
- 优先级

对于任意公式A，通过如下算法即可得出等价于它的范式．
- 使用基本等价式，将A中逻辑联结词→、 <->去除．
- 使用Morgan律和双重否定律，将A中所有的否定词 都放在命题变元之前，形成文字.
- 反复使用分配律，即可得到等价的范式．

![|450](http://verification.fengzhongzhihan.top/202405311519646.png)
```
(P^(~Q V R)) -> S
= ~(P^(~Q V R)) V S
= (~P)V(Q^~R) V S (析取)
=( (~P V Q) ^ (~P V ~R))  V S
= (~P V Q V S) ^ (~P V ~R V S)
```
![](http://verification.fengzhongzhihan.top/202406161253992.png)


析取范式和合取范式可以判断真假
- 方法：一个公式A永假，当且仅当其析取范式中每个短语永假，而一个短语永假当且仅当该短语中同时含有某命题变元及其否定． 

![|450](http://verification.fengzhongzhihan.top/202405311532612.png)
注意: 范式不是唯一的
- 可以等价写成各种形式

### 12.5.2 极小项, 主合取, 主析取
**极小项**: 所有命题变元的合取^
- 因此, 极小项是一个短语
- 有顺序要求
- 将Pi 记作 1/ 0, 则与二进制的数相对应, 记作mσ1σ2
	- m1100记作m12 , m10记作m2

**极小项的性质**
![|450](http://verification.fengzhongzhihan.top/202405311538747.png)


**主析取范式** : 每一个短语都是极小项
- 任意公式A, 均存在唯一等价主析取范式

P, Q, R三个变元的情况下
- P ^ Q -> (P ^ Q) V (R ^ R-)
		(P ^ Q) ^ (R V R-)

写真值表, 把所有值为1的都并起来
![|425](http://verification.fengzhongzhihan.top/202405311540567.png)
- P<-> Q = 非p∩ 非Q  V p ∩ Q
![|425](http://verification.fengzhongzhihan.top/202405311540797.png)

![|575](http://verification.fengzhongzhihan.top/202405311541707.png)
![](http://verification.fengzhongzhihan.top/202406161302316.png)


**极大项**定义相同
![|289](http://verification.fengzhongzhihan.top/202405311542641.png)
主合取范式: 每一个子句都是**极大项**
- 任意公式A，都存在唯一一个与之等价的主合取范式．
![|425](http://verification.fengzhongzhihan.top/202405311544691.png)

性质
-![](http://verification.fengzhongzhihan.top/202405311545961.png)
![](http://verification.fengzhongzhihan.top/202405311546049.png)
## 12.6 命题逻辑的推理理论

### 12.6.1 定义
推理 : 从某些前提出发推出某些结论 

当前提的真 蕴涵 结论的真时，称前提和结论之间有**可推导性关系**，即前提与结论之间的推理是正确的. 称这种推理为**演绎推理**. 演绎逻辑研究怎样的前提和结论之间有可推导性关系.

定义１　设A，B是两个公式，如果对任何指派I，当A为１时B必为１，则称A蕴涵B，或称B是A的逻辑结果，记为A=>B．
- A称为蕴涵式前件，B称为蕴涵式后件.
- A => B当且仅当A→B永真

![](http://verification.fengzhongzhihan.top/202405311551921.png)

定义２　设 I＝｛A1，A2，…，An｝是一个公式集合，B是公式，
如果A1∧A2∧…∧An => B
则称B是 I (或A1，A2，…，An) 的**逻辑结果**，记为I => B　或A1，A2，…，An => B．
### 12.6.2 推理表
![|475](http://verification.fengzhongzhihan.top/202405312141594.png)

![|450](http://verification.fengzhongzhihan.top/202405312127078.png)

![](http://verification.fengzhongzhihan.top/202405312130175.png)

根据演绎推理的定义及定理３，将构造演绎推理序列必须遵循的规则总结如下：
（１）前提引入规则　在演绎过程中，可随便使用前提，该规则记为P．
（２）结论引用规则　在演绎过程中，可随便引入前边公式的逻辑结果．该规则记为C.
（３）永真式引用规则　在演绎过程中，可随便引入永真式，该规则记为T．
（４）分离规则　由公式A，A→B可引入B．该规则记为MP.
（５）附加条件规则　为证  I => B→C，可证 I∪{B} => C，该规则记为CP．

![|525](http://verification.fengzhongzhihan.top/202405312134657.png)
![](http://verification.fengzhongzhihan.top/202405312143649.png)
![|475](http://verification.fengzhongzhihan.top/202405312148424.png)

### 12.6.3 定理
定理１　公式的蕴涵是反对称关系，即
（１）A=>A
（２）若A=>B，B=>A则A＝B
（３）若A=>B，B=>C则A=>C

定理2（蕴涵式代入原则） 设A, B是两个公式，A  =>B，P１，P２，…，Pn为这两个公式中出现的所有命题变元，A１，A２，…，An是任意一组公式，若用Ai (１≤i≤n) 代替A，B中的Pi分别得到公式A', B'，则A' => B'．

![|475](http://verification.fengzhongzhihan.top/202405312128590.png)

# 13 谓词逻辑

在命题演算中, 把简单命题作为基本研究单位, 对它不再进行分解, 这使得命题逻辑有很大的局限性。有些很简单的推理形式, 如典型的逻辑三段论, 用命题演算的推理理论无法论证它

所有人都会死，
    苏格拉底是人，
    所以，苏格拉底必会死．

在命题逻辑中不能表示这样的推理
    P∧Q =>R   

## 13.1 定义
一个陈述句一般由**主语**部分和**谓语**部分构成

一个命题的主语部分，通常由我们所讨论的对象担任，这些对象称为**个体**，可以用**小写字母**a，b，c，…表示. 
个体所在的范围称为**论域或个体域**，用D表示. 

数理逻辑中，命题的谓语部分一般称作**谓词**，一般用大写字母P，Q，R，…表示
王平是学生． S(...) 表示“…是学生”   S(王平)


谓词中引入个体变元后，谓词便具有**命题的“形式”** 
用具体的个体去代换谓词中的个体变元，便得到一个命题 

设P(x１，x２，…，xn)是一个**谓词**，用论域D中的一组个体a１，a２，…，an代替 x１，x２，…，xn，我们便得到一个**命题**P(a１，a２，…，an)，该命题的真值或为１或为０，所以，可以把P看成是从D^n到｛０，１｝的一个**映射**．
定义１　D^n到｛０，１｝的函数称为**n元谓词**或**n元命题函数**． 
- 命题逻辑中的五个联结词否，∨，∧，→ , <-> ，均可平移到谓词逻辑 

例１　设D＝｛１，２｝，P(x，y)表示“x大于y”，则P(x，y)定义了如下映射：P(１，１)＝０，P(１，２) ＝０，P(２，１)＝１，P(２，２)＝０．
例２　设D＝Ｎ，P(x)表示“x是素数”，则P(x)定义了如下映射：
    P(０)＝０，P(１)＝０，P(２)＝１，P(３)＝１，P(４)＝０，…，，

定义２　（1）表示“所有”、“任意”、“一切”的词称为**全称量词**，记为任意
任意x 表示对论域中的所有个体，x称为任意的**指导变元(全称性变元)**，用来指代所讨论的个体. 
任意x P(x)表示论域中的所有个体都有性质P.  
 （2）表示“存在着”、“至少有一个”的词称为**存在量词**，记为存在.  存在x表示论域中存在个体，同全称量词一样，这里的x也称为存在的指导变元(存在性变元)，用来指代所讨论的个体. 
 而存在xP(x)表示论域中存在着个体具有性质P.
- 论域也就是个体的范围D

**特性谓词**是限定客体变元变化范围的谓词，用于描述个体特征。
在全称量词中，特性谓词常作为**蕴含的前件**出现，如(∀x)(M(x) →F(x))，表示对于所有的x，如果x具有M特性，则x也具有F特性；
在存在量词中，特性谓词常作为**合取项**出现，如(∃ x)(M(x)∧G(x))，表示存在一个x，x同时具有M特性和G特性。

用M(x)表示“x是人”（特性谓词），D(x) 表示“x会死”，
	则“所有人会死”应表为：任意x (M(x) -> F(x) ),
	“有些人会死”则应表为：存在x (M(x)∧D(x) ). 

例5 我为人人，人人为我.

令 论域D为人类集合，S(x，y)：x为y服务，I表示我. 则命题表示为 
	    任意x S(I，x)∧任意x S(x，I).
![](http://verification.fengzhongzhihan.top/202405312158518.png)
![](http://verification.fengzhongzhihan.top/202405312159857.png)


## 13.2 合式公式
四种符号：
1. **常量符号**（个体符号）：a，b，c，… (或a１，a２，…)．
2. **变量符号**：x，y，z … (或x１，x２，…)．
3. **函数符号**：f，g，h，… (或f１，f２，… ). 每个函数符号使用时都有确定的元数. 为了指明元数，n元函数符号通常记为f (x1, x2, …, xn).
4. **谓词符号**：P，Q，R，… (或P１，P２，…,  Q１，Q２，…)，每个谓词符号使用时都有确定的元数. 为了指明元数，n元谓词符号通常记为P(x1, x2, …, xn).

谓词逻辑中的**项**归纳定义为    
1、常量符号是项．
2、变量符号是项．
3、若t１，t２，…，tn是项，则f (t１，t２，…，tn)是项．
4、所有项都是有限次使用(１)，(２)，(３)生成的．

若t１，t２，…，tn是项，则P (t１，t２，…，tn) 是**原子公式**．

谓词逻辑中的**合式公式** ( wff ) 归纳定义如下：
	1、原子公式是合式公式.
	2、若A，B是合式公式，则(﹁A)，(A∨B)，(A∧B)，(A→B)，(A<->B) 是合式公式．
	3、若A是合式公式，则 (任意x A )，(存在x A ) 是合式公式．
	所有合式公式，都是有限次使用(１)，(２)，(３)生成的．  

设A是公式，若A１是A的一部分且本身是公式，则称A１是A的**子公式**．

设A是公式，任意xA１(或存在xA１) 是A的子公式，则A中相应于A１一段称为任意x(或存在x)**辖域．**

设A是一个公式，若个体变元x出现在某个量词的辖域之内，称x的这次出现是**约束**的，否则称x的这次出现是**自由**的. 
一个个体变元，如果至少有一次出现是约束的，则称其为**约束变元**; 如果至少有一次出现是自由的，则称其为**自由变元**．

存在x(P(x，y)→Q(x，z))∨R(x) 
从左向右算起，x的第一，二次出现是约束的，第三次出现是自由的
变量y，z的出现是自由的，x既是约束变元也是自由变元，y，z是自由变元．
![|400](http://verification.fengzhongzhihan.top/202406081452134.png)

![](http://verification.fengzhongzhihan.top/202406081452521.png)
- 注意函数符号为项, 不为原子公式

由于一个合式公式中，个体变元可以同时是约束变元和自由变元，这就给讨论问题带来不便，我们希望一个变元在同一个wff中只以一种面目出现，为达到此目的，我们引入下面的**换名**
任一公式均可用如下换名规则给其中的变元换名．
(1) 将某个个体变元在量词中作为指导变元的出现和它在该量词辖域中的所有出现都用同一个新个体变元去替换．
(2) 所用新个体变元在原式中不出现．
![](http://verification.fengzhongzhihan.top/202406081457868.png)


谓词公式A的一个**解释I**，由对论域D和常量符号、函数符号、谓词符号依下列规则进行的一组指定构成．
1、指定D为一非空集合．
2、对每个常量符号指定D中一个元素．
3、对每个函数符号，指定一个同元函数．
4、对每个谓词符号，指定一个同元谓词．
- 谓词公式A，如果不含自由变元，经过解释后便成为一个命题．

![|475](http://verification.fengzhongzhihan.top/202406081458901.png)
![|450](http://verification.fengzhongzhihan.top/202406081501832.png)

- 任意x都满足P(x) == 1, 则真值为1

注意: 以上都不含有自由变元的情况
谓词公式A，如果含有自由变元，则为使其成为命题，除对A进行解释外，还需要将其中的**自由变元指定为论域中的元素**，即需要**对自由变元“赋值”** 

谓词公式经过解释I和赋值v以后，便成为一个命题, 记为
$$A^{IV}$$

设A是一个公式，如果对任意解释I和赋值v，A的真值总为１，则称A是**有效的（或永真的）**，否则，称A是非有效的．
## 13.3 等价和范式

设A，B是两个公式，如果在A，B的**每一个解释及赋值下**，A，B**总有相同的真值**，则称A与B**等价**，记为A＝B． 
- 显然，A＝B当且仅当A<->B有效． 

**谓词性等价证明  <-> 只能通过推导证明, 不能用真值表**

一些等价式
![|374](http://verification.fengzhongzhihan.top/202406081508596.png)
![|350](http://verification.fengzhongzhihan.top/202406081508511.png)
- 注意∩的情况下任意才能拆开
- 注意U的情况下存在才能拆开
### 13.3.1 前束范式
形如
			Q１x１Q２x２…Qnxn  M
	的公式称为**前束范式**，其中Qixi (１≤i≤n) 是任意xi 或 存在xi，称为**首标**，M中不含任何量词，称为**母式**．如果将M中的原子公式及其否定视为**文字**， 当M是析取范式时，上述公式称为
	**前束析取范式**；当M是合取范式时，上述公式称为**前束合取范式**.

对任意谓词公式A，都存在与其等价的前束范式 .
方法: 
(1)使用等价式
　　　　A <-> B＝(A→B)∧(B→A),  A→B＝非A∨B
		去除→与<-> ，
	(2)使用Morgan律和双重否定律及量词否定型等价式将 非 放在原子公式之前．
	(3)利用量词分配等价式，将所有量词提到公式前面(必要时换名)

![](http://verification.fengzhongzhihan.top/202406081512721.png)
![|400](http://verification.fengzhongzhihan.top/202406081512941.png)
![|425](http://verification.fengzhongzhihan.top/202406081512222.png)
![|425](http://verification.fengzhongzhihan.top/202406081512323.png)
- 答案给错了, 2PQ 2非P非Q

![](http://verification.fengzhongzhihan.top/202406081539076.png)

但前束范式的不足之处是首标中比较杂乱无章，全称量词与存在量词无一定的排列规则。
### 13.3.2 斯柯林范式
首标中**没有存在量词**的**前束范式**，这个前束范式就称为A的**Skolem范式**（斯柯林范式）．

每个谓词公式A均可以变换为与它等值的斯柯林范式。

公式A永假当且仅当其Skolem范式永假．
![](http://verification.fengzhongzhihan.top/202406081950157.png)

## 13.4 推理理论

定义１　设A，B是两个公式，如果对任意解释I及赋值v，当A的真值为１时必有B的真值为１，则称A蕴涵B，记为A => B．

显然，A => B当且仅当A→B有效．
![](http://verification.fengzhongzhihan.top/202406081918466.png)


推理规则
- 全称/ 存在量词消去律和引入律 
![](http://verification.fengzhongzhihan.top/202406081922666.png)
![](http://verification.fengzhongzhihan.top/202406081923047.png)
![](http://verification.fengzhongzhihan.top/202406081923910.png)
![](http://verification.fengzhongzhihan.top/202406081923243.png)

例题
![|400](http://verification.fengzhongzhihan.top/202406081925195.png)
![|400](http://verification.fengzhongzhihan.top/202406081926436.png)
![|450](http://verification.fengzhongzhihan.top/202406081927432.png)

![|450](http://verification.fengzhongzhihan.top/202406081929815.png)
![|450](http://verification.fengzhongzhihan.top/202406081930147.png)




























