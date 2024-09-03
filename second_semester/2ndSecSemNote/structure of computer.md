# 1 计算机系统概论

## 1.1 计算机系统

包含
- 硬件 
	- 主机
		- 主存 <- (数据, 指令)
		- CPU
			- CU(core)
			- ALU
		- 以及包含其他所有部件
	- 外设
		- 输入设备
		- 输出设备
- 软件
	- 系统软件
		- MASM
		- 操作系统
		- 服务型程序
		- 数据库
	- 应用软件
		- app

>计算机体系结构和计组的区别

前者 : 程序员见到的(有无), 指令系统, 数据类型等等...
后者 : 如何实现前者提到的属性

## 1.2 计算机的基本组成

**冯诺依曼体系架构特点**
1. 由五大部件构成
2. 指令数据均存于存储器, 用二进制表示
3. 指令用操作码 + 地址码构成
4. 存储程序执行(core)
	1. 事先编制程序
	2. 存入主存
	3. 开始运行
5. 以运算器为中心

组成图
![image.png|450](http://verification.fengzhongzhihan.top/202402291827710.png)


指令格式包括 : 操作码 + 地址码
- 操作码的个数由操作类型种数决定
以$$ax^2+bx+c$$举例
![|450](http://verification.fengzhongzhihan.top/202403092007416.png)


### 1.2.1 存储器
![image.png|134](http://verification.fengzhongzhihan.top/202402291831135.png)

存储体 <- 存储单元(一连串二进制数字) <- 存储元件(0/1元器件, 如半导体)
- 存储字 : 二进制代码
- 存储字长 : 二进制代码位数

MAR: 地址寄存器 ->反映存储单元个数
MDR : 数据寄存器 -> 反映存储字长

### 1.2.2 运算器

构成
![image.png|138](http://verification.fengzhongzhihan.top/202402291832974.png)
ALU + ACC + MQ + X

运算规则
![image.png|425](http://verification.fengzhongzhihan.top/202402291833850.png)
ACC + X - > ACC
ACC - X - > ACC
X * MQ -> ACC + MQ
ACC / X -> MQ ... ACC
### 1.2.3 控制器
![|550](http://verification.fengzhongzhihan.top/202406222156708.png)
PC : 存放当前欲执行的指令地址
IR : 寄存器, 存放指令

完成一条指令的过程, 以取数为例
![image.png](http://verification.fengzhongzhihan.top/202403091959415.png)

1. 取指令 : PC -> MAR ->mem-> MDR -> IR
2. 分析指令 : OP(IR) -> CU 
3. 执行指令 Ad(IR) -> MAR -> mem->MDR -> ACC

存数为例
3. Ad(IR) -> MAR -> mem  Acc->mdr mdr ->mem

>数据和指令的区分方法

1. 通过不同的时间段来区分指令和数据，即在取指令阶段（或取指微程序）取出的为指令，在执行指令阶段（或相应微程序）取出的即为数据。
2. 通过地址来源区分，由PC提供存储单元地址的取出的是指令，由指令地址码部分提供存储单元地址的取出的是操作数。
3. 一般将指令和数据分别存放在存储区的不同区域

## 1.3 计算机硬件的主要技术指标
1. 机器字长 : CPU 一次能处理数据的位数, 与register位数有关
2. 运算速度
	- 主频 : 1s能执行多少时钟周期数
	- 吉普森法 
	- MIPS : 
		- 若MIPS相同, 但指令架构未必相同, 无法直接判断计算机性能
	- CPI : 执行一条指令所需要的时钟周期数
	- Flops : 每秒浮点运算次数
3. 存储容量 : 存放二进制信息位数
	- 主存容量(小)
		- 存储单元个数 * 存储字长
	- 辅存容量(大)
	- 单位: byte

benchMark : 通用程序测时间
>若MAR = 10, MDR = 8, 则主存容量为? 
>答 : 2^10 * 8 / 8 = 1KB

CPU和芯片的关系 : 
- CPU芯片(一个分类)
- fpga芯片
CPU : 一个IP(API)/柜子/ 芯片
综上所述，CPU是芯片的一种，作为计算机的核心组件执行各种计算任务，而芯片是一个更广泛的概念，涵盖了所有集成电路模块。现代计算系统中，CPU与其他芯片协同工作，共同实现复杂的计算和控制功能。

# 2 数的表示形式

## 2.1 有符号数和无符号数

机器数 : 计算机内部使用的数

真值 : 机器数代表的数的实际值

原码 : 最高位为符号位, 0为正 ,1为负, 数据位为数的绝对值

- 定点小数 : 0.111  -> 0.111  1.111 -> -0.111
- 定点整数 : X = - 10110; X = 110110
- +0和-0的原码不相同

补码 
- 定点小数 : 0.1101 -> 0.1101 -0.1011 -> 1.0101
- 已知x补 , 求(-x)补 
	- 对x补连同符号位进行求补
	- 因此我们求负数的补码的时候, 一般先求正数的补码

移码 
- 用于比较阶码的大小(可以保证 > 0)
- 符号位取反的补码

8位的二进制代码
![image.png](http://verification.fengzhongzhihan.top/202403092016421.png)

注意 -0的原码  -> 补码表示最小负数
## 2.2 定点和浮点表示

定点机 : 用定点表示数的机器
![image.png](http://verification.fengzhongzhihan.top/202403092019138.png)

浮点表示
![image.png](http://verification.fengzhongzhihan.top/202403092019586.png)

上溢 : 指阶码 > 最大阶码 
下溢 : 指 阶码 < 最小阶码 , 通常按0处理

习题 : 
![image.png](http://verification.fengzhongzhihan.top/202403092023114.png)

规格化 : 
- 尾数的最高位为1(原码表示情况下)
- 最大的区别是最小正数最小为2^-1

如何判断规格化的数?
![image.png](http://verification.fengzhongzhihan.top/202403261652461.png)
则原码的第一位数一定为1
补码的符号位(可能有两位)和第一位数一定符号位不同

规格化的左规(往左移从而达到规格化的效果)
![image.png](http://verification.fengzhongzhihan.top/202403261656357.png)
如果发生了溢出, 我们一般使用右规
![image.png](http://verification.fengzhongzhihan.top/202403261658196.png)


![image.png|550](http://verification.fengzhongzhihan.top/202403092024325.png)


![image.png](http://verification.fengzhongzhihan.top/202403092026599.png)
先写成 2^{ -7}的形式

原反补 : 阶码和尾数均写成这个形式
- 机器数 : 写成一串数字, 包含原码, 反码, 补码
- 定点数或者浮点数 : 直接写就行


![image.png](http://verification.fengzhongzhihan.top/202403092030104.png)

## 2.3 算数移位和逻辑移位
算数移位(有符号数)
![image.png|450](http://verification.fengzhongzhihan.top/202403131415555.png)
- 仅数值位变化 : 反码均补1, 补码右移补符号位, 其余均补0


逻辑右移(无符号数)
- 全部填0
![](http://verification.fengzhongzhihan.top/202406231543955.png)


![image.png|475](http://verification.fengzhongzhihan.top/202403131421128.png)

因为负数的反码丢1相当于负数的原码丢0 
- 左移丢0 : 正确
- 右移丢0 : 正确

负数(正数)的原码
- 左移丢1: 出错
- 右移丢1 : 影响精度

// 1 0101 : 补码 1 1011  
// 左移丢1 : 1 0110  原码  1 1010
// 右移丢1 : 1 1101 原码   1 0011
负数的补码丢1
- 左移丢1: 正确 
- 右移丢1: 影响精度  
## 2.4 补码的计算
### 2.4.1 补码加减运算
![image.png|475](http://verification.fengzhongzhihan.top/202403131427428.png)

>例题: x = 9 / 16, y = 11 / 16, 则x + y = 
0.1001 + 0.1011 = 1.0100, 符号位为负号, 则答案为 -3 / 4×

补码 : 1.0100 -> 1.1100 -> -3/4

>机器数字长为8位(1位符号位), A = - 97, B = +41. 则A - B = ?
1.0011111 + 1.1010111 = 10.1110110, 答案为 + 118 ×

### 2.4.2 溢出
>背景 : 空难和2038计算机事件

参加操作的 两个数（减法时即为被减数和“求补” 以后的减数）符号相同，其结果的符号与原操作 数的符号不同，即为溢出 

发生溢出只有两种情况
- 正数 + 正数
- 负数 + 负数

溢出的判断:
**单符号位的表示**
- 正数 + 正数 = 负数 : 上溢
	- 符号位进位Cs = 0, 最高位进位Cn = 1(0 + 0 + 1 = 1)
- 负数 + 负数 = 正数 : 下溢
	- 符号位进位Cs = 1, 最高位进位Cn = 0(1 + 1 + 0 = 0)
- 若Cs ^ Cn= 1则溢出

 **双符号位的表示**
00表示正, 无溢出
11表示负, 无溢出
01表示正溢
10表示负溢
- 本质上还是单符号位
![|500](http://verification.fengzhongzhihan.top/202406231513931.png)

![](http://verification.fengzhongzhihan.top/202406231514488.png)


### 2.4.3 补码硬件控制
![image.png|475](http://verification.fengzhongzhihan.top/202403131429097.png)

其中n+1位加法器是一位全加器的组合

$$S_i = A^{-} B^{-}$$

$$C_i=A_iB_i+(A_i+B_i)C_{i-1}$$
令di = AiBi, ti = Ai + Bi
则$$C_i = d_i+t_iC_{i-1}$$
此时串行加法器得到进位的时间为2nt

多位加法器 : 可以进行性能的提升
- 并行进位链 : 直接可以算出来Ci, 但是实现电路复杂
- 使用中庸思想: 均用, 如4位并行加法器, 组内并行, 组间串行

### 2.4.4 原码一位乘
以原码一位乘法为例

![image.png|305](http://verification.fengzhongzhihan.top/202403131523645.png)

符号位单独处理
乘数决定了被乘数需要左移x位进行加法运算

n位数相乘需求
- 乘数寄存器需要n位
- 被乘数寄存器需要2n位, 需要左移
- 部分积寄存器需要2n位, 存储数据
- 移位器 : 2n位
- 加法器:  2n位

如何改进降低位数 ? 
- 被乘数左移, 相对论, 部分积右移可以保证对齐
- 部分积寄存器右移时多出来的如S0可以放入乘数寄存器(右移一位空出空间)

被乘数0.1101 乘数0.1011
![image.png](http://verification.fengzhongzhihan.top/202403131547730.png)

操作的次数
- 加n次, 移位n次
- 由乘数的末位决定被乘数是否与原部分积相加，然后 右移1 位形成新的部分积，同时 乘数 右移1位（末位移丢），空出高位存放部分积的低位。
	- 此时为绝对值运算, 因此最高位直接补0
	- 三个寄存器 : 乘法寄存器, 被乘数寄存器, 部分积寄存器

### 2.4.5 补码一位乘

补码乘法的结论
- 如果乘数Y为正, 则不管被乘数符号, 都有X×Y补 = X补×Y补
- 如果乘数Y为负, 则先按照正数运算, 最后加上矫正量-X补
![image.png](http://verification.fengzhongzhihan.top/202403201406630.png)

Booth法. 将两种情况进行统一

![image.png](http://verification.fengzhongzhihan.top/202403201407621.png)

 基本操作：被乘数\[X]补乘以对应的相邻两位乘数之差，再与原部分积累加，然后右移一位，形成该步的部分积(累加和)。
     * 因为每步要右移一位，所以参与比较的两位乘数始终位于最末的Yn、Yn+1 
     * 注：最后一步y1 - y0不移位。

由两位的值所决定的操作，规则为：

![image.png|375](http://verification.fengzhongzhihan.top/202403201409081.png)

例题
![image.png|575](http://verification.fengzhongzhihan.top/202403201412296.png)
- 注意 : 进行算术右移

最后算完y1 - y0 之后直接保存结果, 丢弃最后两位
乘数保留符号位
### 2.4.6 原码一位除

![image.png|600](http://verification.fengzhongzhihan.top/202403201418020.png)

原理: 比较余数和除数的大小可以用减法进行判断
- 注意, 减过之后如果<0 , 需要加回来, 再进行移位
- 上商原则 : 余数左移一位 - 除数 = 新余数

例题

![image.png](http://verification.fengzhongzhihan.top/202403201424438.png)
⚠️upload failed, check dev console

每次减完还要加回来?
- 恢复余数法
	- 若上'0', 则Ri + y*, 恢复余数
- 不恢复余数法
	- 若上'1', 则2* Ri  - y*
	- 若上'0', 则2 * Ri + y * = 2(Ri + y*) - y*
	- 其实就是相当于把两步进行合并
	- 也称为加减交替法

![image.png](http://verification.fengzhongzhihan.top/202403201436869.png)

如果上0, 最后一步总要加回余数



## 2.5 浮点数的四则运算

### 2.5.1 浮点数加减运算

x = Sx * 2^jx
y = Sy * 2 ^jy

方法
1. 求阶差dj = jx - jy
	- dj = 0 : 已对齐
	- dj > 0 : jx > jy :, y向x看齐, Sy -> 1, jy + 1
	- dj < 0 : jx < jy :, x向y看齐, Sx -> 1, jx + 1

注 :  统一对阶原则为小阶向大阶看齐
2. 尾数求和
3. 进行规格化(左规, 右规)

例题: 
![image.png|550](http://verification.fengzhongzhihan.top/202403261647488.png)

规格化?
![](http://verification.fengzhongzhihan.top/202406231603660.png)


正数的运算
![image.png|450](http://verification.fengzhongzhihan.top/202403261713052.png)
![image.png|400](http://verification.fengzhongzhihan.top/202403261716719.png)

负数的运算
![image.png|450](http://verification.fengzhongzhihan.top/202403261724425.png)
![image.png|425](http://verification.fengzhongzhihan.top/202403261724897.png)

注意 : 尾数虽然看上去溢出, 但是实际上浮点数并没有溢出, 仅仅是因为阶码对应改变了
而浮点数的溢出是由阶码决定的是否溢出

## 2.6 浮点数乘除运算

乘法 : 尾数相乘, 阶数相加
除法 : 尾数相除, 阶数相减


# 3 存储器

存储内容: 程序和数据

## 3.1 存储器分类
按存储介质分类 (代表0/ 1的原理不同)
- 半导体存储器 (TTL, MOS) : 容易丢失(以下均不易丢失)
- 磁表面存储器 
- 磁芯存储器
- 光盘存储器

存取时间与物理地址无关 (随机访问)
- 随机存储器 
- 只读存储器

存取时间与物理地址相关
- 顺序存储
- 直接存取

存储器
- 主存
	- RAM 
		- SRAM : 缓存(静态)
		- DRAM : 主存(动态)
	- ROM : 只读
- FLash Memory 
- Cache
- 辅存

三个特性: 速度, 容量, 价格
![image.png|550](http://verification.fengzhongzhihan.top/202403271424724.png)

缓存背景: CPU运行速度 >> 从主存中读取数据
- 因此使用缓存可以很快取数据
![image.png|400](http://verification.fengzhongzhihan.top/202403271430272.png)

## 3.2 主存

![image.png|134](http://verification.fengzhongzhihan.top/202402291831135.png)
内部有存储器硬件译码电路
- 根据外部地址线直接选择对应地址

大端存储和小端存储
![image.png|475](http://verification.fengzhongzhihan.top/202403271447705.png)
- 按字节寻址: 每一个地址都对应一个字节
- 按字寻址 : 每一个地址对应2 / 4byte, 则共可以访存内容减少2 / 4倍

主存的技术指标 : 
- 存储容量: 主存存放的二进制代码的位数
- 存储速度
	- 存取时间,  存储器的 访问时间 (读出, 写入)
	- 存取周期:  连续两次独立的存储器操作所需的 最小间隔时间 
- 存储器的带宽 32 M / s

## 3.3 半导体存储芯片
![image.png|500](http://verification.fengzhongzhihan.top/202403271508231.png)

片选线 : 一组芯片有效, 则片选信号有效(CS, CE)
(WR) : 读写控制信号  OE: 允许读  WE: 允许写

![image.png|350](http://verification.fengzhongzhihan.top/202403271509636.png)

译码驱动方式
- 线选法
![image.png|425](http://verification.fengzhongzhihan.top/202403271511449.png)
类似于三八译码器, 输入3 , 输出8条线

- 重合法(x, y确定坐标)
![image.png|375](http://verification.fengzhongzhihan.top/202403271512689.png)

## 3.4 (RAM)(ROM)
随机存取存储器
静态RAM(触发器): 主要用作缓存
![image.png|400](http://verification.fengzhongzhihan.top/202403271519079.png)


动态RAM刷新(电容): 主要用作主存
电容漏电 : 高电平 ->  低电平
- 因此会造成信息丢失
- 需要刷新信息

**集中刷新**
- 集中安排一段时间进行刷新
![image.png|450](http://verification.fengzhongzhihan.top/202403271522161.png)
存在死区: 罢工
- 存取周期不变

**分散刷新**
- 每一个读写周期都取一段用来刷新
![image.png|375](http://verification.fengzhongzhihan.top/202403271525647.png)
存取周期增加

相结合: **异步刷新**
- 每次刷新一行, 2ms内刷新完所有行
![image.png|400](http://verification.fengzhongzhihan.top/202403271527835.png)

优化方式 : 将死区放入指令译码阶段(无需从mem中取指)

**只读存储器** ROM
熔丝断 : 0  熔丝不断:  1
PROM: 一次性编程

## 3.5 存储器和CPU的连接

**存储器容量的扩展**

**位扩展** : 增加存储字长
: 1K * 4位 组成 1K * 8位存储器
- 用几片组成 ?  2片
- CPU伸出10地址线, 8数据线

![image.png|400](http://verification.fengzhongzhihan.top/202404091622346.png)

**字扩展:** 增加存储字数量
: 1K* 8位 组成 2K* 8位存储器 
- 由2片组成
- CPU伸出11地址线, 8数据线
![](http://verification.fengzhongzhihan.top/202406232007470.png)
A10为0, 第一个芯片工作, A10为1, 第二个芯片工作, 因此可以区分11位地址
- 上1k个房间的第一位都为0, 下1k个房间的第一位都是1

**字位扩展:** 均增加
: 1K * 4 位 组成 4 K * 8 位
- 由8片组成
- CPU伸出12地址线, 8数据线
- 分组 : 2个为一组, 译码对应不同的组
	- 10 00 01 11 : 剩下8位

![image.png](http://verification.fengzhongzhihan.top/202404091639337.png)


总结 : 位数改变 -> 将存储芯片数据位拼起来(不一定需要有序拼)
地址改变 -> 利用不同的高位译码器来激活相应的存储芯片
都改变 -> 分组确定位数, 片选信号确认地址
**例题**
![image.png|475](http://verification.fengzhongzhihan.top/202404091719146.png)

ROM
0110 0000 0000 0000
0110 0101 1111 1111
RAM
0110 1000 0000 0000
0110 1011 1111 1111

![image.png|450](http://verification.fengzhongzhihan.top/202404091724957.png)

A10 : 如果操作到A10 = 1的空间范围则会出错

A11 ~ A13 : 3 - 8 译码器
A14 ~ A15 + MREQ : 控制信号

**例题**
![image.png|550](http://verification.fengzhongzhihan.top/202404091734124.png)
000 0 0000 0000 0000
000 0 0111 1111 1111

000 0 1000 0000 0000
000 0 1111 1111 1111
000 1 0000 1000 1000
000 1 0011 1111 1111 

![image.png|425](http://verification.fengzhongzhihan.top/202404091741888.png)

![](http://verification.fengzhongzhihan.top/202406232052323.png)


ROM
0000 0000 0000 0000
0001 1111 1111 1111

RAM
0010 0000 0000 0000
0011 1111 1111 1111

0100 0000 0000 0000
0101 1111 1111 1111

RAM
1111 0000 0000 0000
1111 1111 1111 1111

![image.png](http://verification.fengzhongzhihan.top/202404091755171.png)
![image.png|450](http://verification.fengzhongzhihan.top/202404091756948.png)

## 3.6 存储器的校验

如何校验存储器的数据有无出错(合法数据之间的差异性)

**汉明码的组成**
n位有效代码需要增加k位检测位
2^k >= n +k + 1

例如n= 4, k = 3
xxxx kkk
检测位的位置 ? 插入2^i的位置
则为kkxkxxx

![image.png|450](http://verification.fengzhongzhihan.top/202403271542153.png)

异或可以判断1的个数是不是偶数
- 偶校验 : 0 代表满足, 1表示不满足
校验方法 : 
![](http://verification.fengzhongzhihan.top/202406232110580.png)
![](http://verification.fengzhongzhihan.top/202406232110419.png)

## 3.7 提高访存速度措施

**单体多字系统**
本来只从mem中一次取一个字, 现在想一次取多个字, 则用一个大的寄存器
![image.png|425](http://verification.fengzhongzhihan.top/202404021636636.png)
	 
**多体并行系统**
主存由多体M组成
数据顺序存放在M当中
- 将时间复杂度优化为O(m + n)
高位交叉
![image.png|450](http://verification.fengzhongzhihan.top/202404021638307.png)

低位交叉
![image.png|450](http://verification.fengzhongzhihan.top/202404021640981.png)

低位交叉优势: 
- 在不改变存取周期的前提下，增加存储器的带宽(读取数据的速度)
- 低位交叉通过将数据分布到多个模块，并允许这些模块并行工作，在不改变每个模块存取周期的前提下，提高了内存系统的整体带宽。这种方式充分利用了并行处理的优势，减少了单一模块的瓶颈，提高了数据传输的效率。

**流水线**
![image.png|550](http://verification.fengzhongzhihan.top/202404021646446.png)


![image.png|450](http://verification.fengzhongzhihan.top/202404021651262.png)
注意: 这个仅为n为4的情况
## 3.8 Cache

如何将主存addr -> Cache addr?
- 映射关系

写
- 写cache和主存
- 只写cache 不写主存
	- 如果process1改cache1数据了, 但是process2需要cache2数据, 共用同一个主存, 这个时候则发生问题.


Cache改进
- 增加cache级数
	- L1cache L2cache
- 统一缓存和分立缓存
	- I-cache D-cache
### 3.8.1 直接映射
![image.png|525](http://verification.fengzhongzhihan.top/202404021756541.png)
![](http://verification.fengzhongzhihan.top/202405221414704.png)
(1)Cache容量4KB=212B,Cache地址12位
每个字块大小=16字x 32位/字÷8位/字节
=64字节
Cache块数=4KB:64B/块=64 块
(2)主存容量512KB=219B,主存地址19位
主存块数=512KB:64B/块=8192块
直接映射方式下:
(3)主存的第64n+5块(n=0,
1.….127)可以映射到第五块
(4)内存地址共19位，其中:
a.字块64字节，内地址6位
b.缓存64块，缓存字块地址6位
c.剩余7位作为主存字块标记

### 3.8.2 全相联映射
![|475](http://verification.fengzhongzhihan.top/202405281656306.png)


### 3.8.3 组相联映射

![](http://verification.fengzhongzhihan.top/202405281657582.png)
此时主存 -> 组内地址
- 将标记去掉, 在中间加上组内的块号

![|575](http://verification.fengzhongzhihan.top/202405221417431.png)
⚠️upload failed, check dev console
![](http://verification.fengzhongzhihan.top/202406232224746.png)
![](http://verification.fengzhongzhihan.top/202406232224349.png)

# 4 输入输出系统

## 4.1 概念
CPU 与 I / O设备的连接

早期 : 分散连接 : 串行工作
![image.png|425](http://verification.fengzhongzhihan.top/202404101441207.png)

后期 : 总线连接 : 并行工作 
- 中断
- DMA方式
![|525](http://verification.fengzhongzhihan.top/202406241908825.png)


通道指令 : 通道自身的指令

I / O设备编址方式 : 
- 统一编址 : 和内存统一编址
	- 通过地址的位置来判断是否属于I / O地址
- 不统一编址 :
	- 专门的I/O指令
	- I / O指令 : 是指令的一部分 : 
		- 操作码 + 命令码 + 设备码
		- 如I / O  + 读 + 鼠标

用设备判断电路识别是否选中 : 设备自己判断CPU发送的地址是否匹配

传送方式
- 串行
- 并行

## 4.2 I/O设备, 主机交互

**程序查询方式**

![image.png|300](http://verification.fengzhongzhihan.top/202404101504718.png)

注意是从I / O读入 CPU , 再从CPU读入主存
	此时CPU和I /O串行执行 , 踏步等待

**程序中断方式**

I / O准备的时候, CPU干自己的事情
没有踏步等待, CPU传输数据的时候中断现行程序

![image.png|400](http://verification.fengzhongzhihan.top/202404101507323.png)

**DMA方式**

从I / O直接读入主存, 不需要CPU中断现行程序
- 但是如果CPU执行了访存指令, 会造成总线的冲突

此时 DMA窃取了CPU的一个存取周期
![image.png|525](http://verification.fengzhongzhihan.top/202404101516458.png)

## 4.3 接口

![image.png|275](http://verification.fengzhongzhihan.top/202404101527741.png)

每一个设备都有对应的接口

接口的组成
![image.png|450](http://verification.fengzhongzhihan.top/202404101530474.png)

还包括一些触发器来进行数据交换
![image.png|364](http://verification.fengzhongzhihan.top/202404101531399.png)

![image.png|525](http://verification.fengzhongzhihan.top/202404101535881.png)

数据信息可以是
- 数据量
- 模拟量 : 其中模拟量必须先经过接口电路中的“模/数”转换器（图中未画）转换为数字量后，才能输入CPU进行处理。 
- 开关量

状态信息表示外设当前所处的工作状
- 如用READY（就绪信号）表示输入设备已准备好
- 用BUSY（忙信号）表示输出设备是否能接收。 

控制信息是由CPU发出的，用于控制外设接口工作方式，以及启动和停止外设。 

数据信息、状态信息和控制信息（如设置外设接口工作方式）通常以数据形式通过CPU的数据线进行传送，这些信息分别放在外设接口（interface）的不同寄存器中。 

![image.png](http://verification.fengzhongzhihan.top/202404241423993.png)

这些寄存器被称作端口（port），如图所示的数据口、状态口和控制口，它们分别存放数据信息、状态信息和控制信息
CPU可对这些端口（寄存器）进行“读”或“写”操作，因此每个端口都有一个“地址”对应。
CPU对这些端口可编程的。 图中的地址线来自CPU，用以指明每个端口的地址。 控制线包括RD（读）或WR（写）等，一般与I/O接口电路中的读/写控制逻辑（图中未标）相连，以控制设备的读写。 

## 4.4 程序查询方式
![image.png|243](http://verification.fengzhongzhihan.top/202404241509018.png)


![|625](http://verification.fengzhongzhihan.top/202404241502930.png)
1. 启动命令
2. D = 0 B = 1启动设备
3. CPU输入数据到DBR
4. 设备工作结束
5. 准备就绪
6. 数据线输出数据

![image.png](http://verification.fengzhongzhihan.top/202404241507857.png)

## 4.5 中断处理

### 4.5.1 中断周期
![|450](http://verification.fengzhongzhihan.top/202406241928738.png)

1.配置中断请求触发器(INTR = 1有请求)和中断屏蔽触发器(MASK = 1被屏蔽) 
![|450](http://verification.fengzhongzhihan.top/202406241930893.png)

2. 排队器
![](http://verification.fengzhongzhihan.top/202406241930738.png)

3. 中断向量地址生成部件
![|575](http://verification.fengzhongzhihan.top/202406241932804.png)

总电路图
![](http://verification.fengzhongzhihan.top/202406241939739.png)

设备编码 : 产生向量地址, 由向量地址转入(中断服务程序入口地址)
- 中断服务程序完成的功能 : 传送数据
排队器 : 不同设备

### 4.5.2 中断服务程序流程
![image.png|550](http://verification.fengzhongzhihan.top/202404241725003.png)
保护PC的指令 : 中断隐指令

步骤
- 保护现场
- 中断服务
- 恢复现场
- 中断返回

单重中断和双重中断
- 区别在于是否允许级别更高的中断源中断现行的中断服务程序
![image.png|500](http://verification.fengzhongzhihan.top/202404241728906.png)
- 区别在于开中断的位置
- 一次中断过程包含6个阶段：中断请求、中断屏蔽、中断判优、中断响应、中断处理、中断返回 

宏观 上 CPU 和 I/O 并行 工作 
微观 上 CPU 中断现行程序 为 I/O 服务 


解：调用中断服务程序和调用子程序的区别是： 
（1）中断服务程序与中断时CPU正在运行的程序是相互独立的，它们之间没有确定的关系。子程序调用时转入的子程序与CPU正在执行的程序段是同一程序的两部分。 
（2）通常中断产生都是随机的，而子程序调用是由CALL指令（子程序调用指令）引起的。 
（3）中断服务程序的入口地址可以通过硬件向量法产生向量地址，再由向量地址找到入口地址。
子程序调用的子程序入口地址是由**CALL指令**中的地址码给出的。 
（4）调用中断服务程序和子程序都需保护程序断点，前者由**中断隐指令**完成，后者由**CALL指令**本身完成。 
（5）处理中断服务程序时，对多个同时发生的中断需进行裁决，而调用子程序时一般没有这种操作。

## 4.6 DMA
与主存交换数据三种方式
- 停止CPU访存操作
- 周期窃取 
	- CPU不访存
	- CPU正在访存 : 等待
	- CPU请求访存 : DMA优先
![image.png](http://verification.fengzhongzhihan.top/202404241738247.png)
让了一个存取周期
- 交替访问, C1给DMA, C2给CPU
![image.png](http://verification.fengzhongzhihan.top/202404241739230.png)
- 不需要 申请建立和归还 总线的使用权 
接口功能
![image.png|425](http://verification.fengzhongzhihan.top/202404241741480.png)


传输过程: 预处理 + 数据传送 + 后处理
- 预处理 : 主存地址 + 设备地址 + 传送数据个数  -> DMA
![image.png](http://verification.fengzhongzhihan.top/202404241746748.png)
预处理一次 + 一个数据块 + 后处理
- 一个数据块 -> 一个字一个字传

数据输入和输出的过程仅仅到设备的箭头不同
![image.png](http://verification.fengzhongzhihan.top/202404241755923.png)

例题
![image.png|650](http://verification.fengzhongzhihan.top/202404241759309.png)
![image.png|650](http://verification.fengzhongzhihan.top/202404241801651.png)

![image.png|550](http://verification.fengzhongzhihan.top/202404241804952.png)
## 4.7 简答题

**1. 试从下面几个方面比较程序查询、程序中断和DMA三种方式的综合性能**
（1）数据传送依赖软件还是硬件。 
（2）传送数据的基本单位。 
（3）并行性。 
（4）主动性。 
（5）传输速度。
（6）经济性 
（7）应用场合 
解：比较如下： 
（1）程序查询、程序中断方式的数据传送主要依赖软件，DMA主要依赖硬件。 （注意：这里指主要的趋势） 
（2）程序查询、程序中断传送数据的基本单位为字或字节，DMA为数据块。 
（3）程序查询方式传送时，CPU与I/O设备串行工作；程序中断方式时，CPU与I/O设备并行工作，现行程序与I/O传送串行进行；DMA方式时，CPU与I/O设备并行工作，现行程序与I/O传送并行进行。 
 (4)程序查询方式时，CPU主动查询I/O设备状态；程序中断及DMA方式时，CPU被动接受I/O中断请求或DMA请求。 
 （5）程序中断方式由于软件额外开销时间比较大，因此传输速度最慢；程序查询方式软件额外开销时间基本没有，因此传输速度比中断快；DMA方式基本由硬件实现传送，因此速度最快；
	 注意：**程序中断方式虽然CPU运行效率比程序查询高，但传输速度却比程序查询慢。** 
 （6）程序查询接口硬件结构最简单，因此最经济；程序中断接口硬件结构稍微复杂一些，因此较经济；DMA控制器硬件结构最复杂，因此成本最高； 
 （7）程序中断方式适用于**中、低速设备的I/O交换**；程序查询方式适用于中、低速**实时处理**过程；DMA方式适用于**高速设备的I/O交换**； 

**2.CPU对DMA请求和中断请求的响应时间是否一样？为什么？**
（1）CPU对DMA请求和中断请求的响应时间不一样，因为两种方式的交换速度相差很大，因此,CPU必须以更短的时间间隔查询并响应DMA请求。响应中断请求是在每条指令执行周期结束的时刻，而响应DMA请求是在存取周期结束的时刻
（2）中断方式是程序切换，而程序又是由指令组成，所以必须在一条指令执行完毕才能响应中断请求，而且CPU只有在每条指令执行周期结束的时刻才发出查询信号，以获取中断请求信号，若此时条件满足，便能响应中断请求。
（3）DMA请求是由DMA接口根据设备的工作状态向CPU申请占用总线，此时只要总线未被CPU占用，即可立即响应DMA请求；若总线正被CPU占用，则必须等待该存取周期结束时，CPU才交出总线的使用权。

3. **CPU响应中断的时间和条件**
![|450](http://verification.fengzhongzhihan.top/202406242019199.png)

# 5 指令系统

## 5.1 指令概述
指令 = 操作码 + 地址
扩展操作码应遵循的原则： 使用频度高的指令应分配短的操作码，使用频率低的指令相应地分配较长的操作码。 

扩展操作码技术
![image.png|575](http://verification.fengzhongzhihan.top/202404241432067.png)

>例：某指令字长16位，每个操作数地址码长6位。指令分为无操作数、单操作数和双操作数三类。若双操作数指令为K种，无操作数指令为L种，问单操作数指令最多可能是多少种？ 

答 : \[(2^4-K)\*2^6-x]\*2^6=L 
## 5.2 寻址方式

形式地址 : 指令字中的 地址
有效地址 : 操作数的真实地址
指令字长 = 存储字长 = 机器字长 
**立即寻址**
![image.png|550](http://verification.fengzhongzhihan.top/202404241451430.png)
- 注意不访存, 可以归为从寄存器里面寻址
**直接寻址**
有效地址由形式地址直接给出
![image.png|525](http://verification.fengzhongzhihan.top/202404241452098.png)
**隐含寻址**
![image.png|525](http://verification.fengzhongzhihan.top/202404241454459.png)


**间接寻址**
![image.png|525](http://verification.fengzhongzhihan.top/202404241414366.png)
- 用处 : 扩大寻址范围
- 有一个标志位flag, 来判断是不是最终地址

**寄存器寻址**
有效地址为寄存器编号
![|355](http://verification.fengzhongzhihan.top/202406242043832.png)

**寄存器间接寻址**
有效地址在寄存器中
![image.png|425](http://verification.fengzhongzhihan.top/202404241416466.png)
- 有效地址在寄存器中

**基址寻址**
![image.png|425](http://verification.fengzhongzhihan.top/202404241418631.png)
- EA = BR + A
- 同样的 , BR也可以用寄存器代替(非专业)
- 在程序的执行过程中 BR 内容不变，形式地址 A 可变 

**变址寻址**
- EA = IX + A 
	- IX是变址寄存器
	- 通用寄存器也可以作为变址寄存器 EA  = Ri + A
	-  便于处理数组问题 
	-  在程序的执行过程中 IX 内容可变，形式地址 A 不变 
![image.png|450](http://verification.fengzhongzhihan.top/202405091558527.png)

试比较基址寻址和变址寻址。
1）都可有效地扩大指令寻址范围。
2）基址寻址时，基准地址由基址寄存器给出，地址的改变反映在位移量A的取值上；变址寻址时，基准地址由A给出，地址的改变反映在变址值的自动修改上，变址值由变址寄存器给出。
3）基址寄存器内容通常由系统程序设定，变址寄存器内容通常由用户设定。
4）基址寻址适用于程序的动态重定位，变址寻址适用于数组或字符串处理，适用场合不同。

**相对寻址**
EA = PC  + A
- 广泛用于转移指令(jump指令)
- 程序浮动

举例
设数据块首地址为 D，求 N 个数的平均值
![image.png|475](http://verification.fengzhongzhihan.top/202404241429823.png)

相对寻址
![image.png|500](http://verification.fengzhongzhihan.top/202404241438773.png)

![image.png|475](http://verification.fengzhongzhihan.top/202404241437205.png)

堆栈寻址
![image.png|425](http://verification.fengzhongzhihan.top/202404241440302.png)

![image.png](http://verification.fengzhongzhihan.top/202404241442605.png)
SP移动代表了压栈的东西的大小
- 压栈了一个PC, 2字节
- 此时压栈的是地址, 因此站2字节
栈顶内容代表PC指向下一条指令的地址
- 一个指令为4个字节, 因此下一个为2004H
- 此时压栈的是指令, 因此站4字节


## 5.3 例题

![image.png|475](http://verification.fengzhongzhihan.top/202404241504335.png)

![image.png](http://verification.fengzhongzhihan.top/202404241520664.png)

此时再安排寄存器寻址的一地址指令


![image.png](http://verification.fengzhongzhihan.top/202404241529360.png)

![image.png](http://verification.fengzhongzhihan.top/202404241530686.png)

![image.png](http://verification.fengzhongzhihan.top/202404241540198.png)
![image.png|375](http://verification.fengzhongzhihan.top/202404241540326.png)
![image.png|375](http://verification.fengzhongzhihan.top/202404241540080.png)
# 6 CPU的结构和功能

## 6.1 指令周期
介绍和第九章类似
![image.png|250](http://verification.fengzhongzhihan.top/202405081635821.png)

## 6.2 指令流水线

### 6.2.1 概论
![image.png|475](http://verification.fengzhongzhihan.top/202405081643931.png)

取指, 指令译码, 计算操作数地址, 取操作数, 执行指令, 写操作数

结构问题
![image.png](http://verification.fengzhongzhihan.top/202405081649214.png)

数据冲突问题
![image.png|400](http://verification.fengzhongzhihan.top/202405081650195.png)
控制相关
![image.png|350](http://verification.fengzhongzhihan.top/202405081651227.png)
![image.png](http://verification.fengzhongzhihan.top/202405081655655.png)

### 6.2.2 性能

吞吐率
![image.png|450](http://verification.fengzhongzhihan.top/202405081657032.png)

加速比
![image.png|450](http://verification.fengzhongzhihan.top/202405081657126.png)

效率
![image.png|450](http://verification.fengzhongzhihan.top/202405081658981.png)
## 6.3 中断系统
### 6.3.1 概述

引起中断的因素
- 人为设置中断
- 事故, 故障
- I / O设备

中断请求标记 :  INTR
- 多个INTR       组成 中断请求标记寄存器
- 一个请求源     一个 INTR 中断请求标记触发器
- 分散 在各个中断源的 接口电路中
- 集中在CPU中断系统中

中断判优逻辑
- 硬件实现 : 排队器
- 软件实现 : 程序查询
![image.png|400](http://verification.fengzhongzhihan.top/202405081706735.png)

入口地址查找
- 硬件 : 硬件向量法
- 软件: 中断识别程序

对于CPU来说 : 
响应中断条件 : EINT = 1
时间 : 指令执行周期结束时刻由CPU 发查询信号 

保护现场: 
- 程序断点: 中断隐指令完成
- 寄存器: 中断服务程序

恢复现场 : 中断服务程序完成

### 6.3.2 多重中断
![image.png|575](http://verification.fengzhongzhihan.top/202405081711689.png)

屏蔽触发:
![image.png|575](http://verification.fengzhongzhihan.top/202405081714938.png)

屏蔽字
![image.png|575](http://verification.fengzhongzhihan.top/202405081714086.png)

可以改变处理的优先等级
但是不能改变响应的优先等级
![image.png|475](http://verification.fengzhongzhihan.top/202405081715777.png)
![image.png|625](http://verification.fengzhongzhihan.top/202405081716361.png)
![image.png|625](http://verification.fengzhongzhihan.top/202405081716963.png)

此时中断服务程序变为
![image.png|129](http://verification.fengzhongzhihan.top/202405081717658.png)

三次中断，三个断点都存入 “ 0 ” 地址 
此时断点如何保护 ?
通过return来保护
![image.png|550](http://verification.fengzhongzhihan.top/202405081722261.png)

# 7 控制单元的功能

## 7.1 操作命令的分析

执行一条指令一般包含4种工作周期
- 取指周期
- 间址周期
- 执行周期
- 中断周期
### 7.1.1 取指周期
![image.png|550](http://verification.fengzhongzhihan.top/202405071629855.png)

### 7.1.2 间址周期
****(最后一步实际上不成立)
![image.png|525](http://verification.fengzhongzhihan.top/202405071630118.png)

### 7.1.3 执行周期
非访存指令
![image.png|375](http://verification.fengzhongzhihan.top/202405071633216.png)
访存指令
![image.png|375](http://verification.fengzhongzhihan.top/202405071639226.png)

![image.png|375](http://verification.fengzhongzhihan.top/202405071646745.png)
转移指令
![image.png|400](http://verification.fengzhongzhihan.top/202405071648267.png)
### 7.1.4 中断周期
![image.png|550](http://verification.fengzhongzhihan.top/202405071656946.png)
- 程序断点存入0 / SP - 1 

不同微操作对应不同微命令
![image.png|525](http://verification.fengzhongzhihan.top/202405141613565.png)

**取指周期:** 
PC -> MAR  **PC out , ARin, Read**
M(MAR) -> MDR  **DREin**
MDR -> IR **DRout IRin**
OP(IR) -> ID 
PC + 1 -> PC **+1**

**执行周期**
1.mov Ro #6
ad(IR) -> R0  **IRout R0in**
2.ldr R1 10
ad(IR) -> MAR **IRout ARin** 
m(MAR) -> MDR **DREin**
MDR -> R1 **Rin DREout**
3 . add r0 r1
R0 -> X **R0out Xin**
(x) + (R1) -> Z **Zin Xout**
z -> R0 **Zout R0in**
4.str Ro \[R2]
R2 -> MAR **R2out** **ARin**
R0 -> MDR **DRin R0out**
MDR -> M(MAR) **DREout, Write**

## 7.2 控制单元的功能

CU外特性
![image.png|475](http://verification.fengzhongzhihan.top/202405071746125.png)

输入信号
![image.png|375](http://verification.fengzhongzhihan.top/202405071748640.png)

内部和外部的控制信号(输出信号)
![image.png|375](http://verification.fengzhongzhihan.top/202405071748959.png)

add @mem : 指从mem包含的地址中取数据
- 则有间址周期 : 形式地址 -> MAR , MAR -> MDR  MDR -> IR(其实直接从MDR中取地址)取得有效地址IR 
- 得到有效地址 : 则MDR -> MAR, 取数据->MDR -> Y

add @ R : 指从R中直接取地址
# 8 组合逻辑设计
## 8.1 周期概念
机器周期是所有指令执行过程中的一个基准时间
	若指令字长 = 存储字长则取指周期 = 机器周期
- 一个指令周期包含若干个机器周期

时钟周期是控制计算机操作的最小单位时间 : 将一个机器周期分成若干个时间相等的时间段（节拍、状态、时钟周期）,  用时钟周期控制产生一个或几个微操作命令
- 一个机器周期包含若干个时钟周期(节拍)


![](http://verification.fengzhongzhihan.top/202406261244445.png)
![](http://verification.fengzhongzhihan.top/202406261245621.png)

在机器周期所含时钟周期数 相同 的前提下，此时每个指令含有的时钟周期相同(CPI相同), 则两机每s执行的指令数之比 等于 两机主频之比   MIPS1 / MIPS2  = f1 / f2, 主频是1s执行的时钟周期数
![](http://verification.fengzhongzhihan.top/202406261425660.png)


## 8.2 节拍安排
一个周期包含4节拍, 一个节拍包含一个上升沿和一个下降沿
同一个沿可以作用于不同的操作对象上
- 注意: IR -> CU 不需要沿信号
- 注意 : 向量地址 -> PC使用外总线

节拍安排原则
- 原则一   微操作的 先后顺序不得 随意 更改 
- 原则二   被控对象不同 的微操作尽量安排在  一个节拍 内完成
- 原则三   占用 时间较短 的微操作尽量 安排在 一个节拍 内完成, 并允许有先后顺序

以**取指周期**为例
T0 : PC -> MAR 1-> R
T1 : M(MAR) -> MDR   PC + 1 -> PC
T2 : MDR -> IR  OP(IR) -> CU (这是个特殊, 不需要沿信号, 可以直接传输)

**间址周期**
T0 ad(IR) -> MAR 1-> R
T1 M(MAR) -> MDR
T2 MDR -> ad(IR)

**执行周期**
T0和T1一般为访存操作, 如果没有的话则置为0
![image.png|550](http://verification.fengzhongzhihan.top/202405141636434.png)
![image.png|525](http://verification.fengzhongzhihan.top/202405141637217.png)
**中断周期**
![image.png|500](http://verification.fengzhongzhihan.top/202405141654885.png)

例题
![image.png](http://verification.fengzhongzhihan.top/202405141654234.png)
![image.png](http://verification.fengzhongzhihan.top/202405141655305.png)
![](http://verification.fengzhongzhihan.top/202406261437717.png)

(1) ADD B, C
执行周期 : 
T0: B -> R1
T1: (R1) + (C) -> R2
T2: R2 -> B

(2) SUB E @H
T0 : (H) -> MAR 1->R
T1 : E -> R1 M(MAR) -> MDR
T2 : (R1) - MDR -> R2
T3 : R2 -> E

(3)STA @mem
间址周期
IR -> MAR
M(MAR) -> MDR

MDR -> MAR 1-> W
ACC -> MDR
MDR -> M(MAR)

![image.png](http://verification.fengzhongzhihan.top/202405141752677.png)
ADD (R1), R0  功能 (R0) + ((R1)) -> (R1)

T0 :  R1 -> MAR
T1 : M(MAR) -> MDR , R0->A(当M(MAR) -> MDR时, 可以进行一个寄存器操作)
T2 : MDR + A -> AC
T3 : AC -> MDR
T4 : MDR -> M(MAR)

![|425](http://verification.fengzhongzhihan.top/202406261450160.png)


## 8.3 组合逻辑设计
1、安排每条指令中微操作的节拍
- 写节拍  + 对应微操作 + 对应微命令
2、列出微操作命令的操作时间表
		         指令名称
 - T0 : ... (微命令)  √
-  T1 : ... (微命令)
![](http://verification.fengzhongzhihan.top/202405152021206.png)
3、写出每一个微操作命令的逻辑表达式
微命令 = 取指 * T1 * 指令... 
![](http://verification.fengzhongzhihan.top/202405152021981.png)
- 取指 : FE 间址: IND EX: 执行
4、画出相应的组合逻辑电路图
![](http://verification.fengzhongzhihan.top/202406261458095.png)

## 8.4 微程序设计

### 8.4.1 概念
组合逻辑控制器：由大量的逻辑门和触发器组成
1.设计不规整
2.不易修改
微程序控制器：基于“存储程序，顺序执行”的思想体制。

微命令：构成控制信号序列的最小单位。如PCout, 1->R
微操作：由微命令控制实现的最基本操作。 如M(MAR) -> MDR
微指令：若干个微命令的组合。如T0, T1
微周期：指从控制存储器中读取一条微指令并执行相应的微操作所需的时间。 执行T0的时间
微程序：一系列微指令的有序集合
- 微程序是机器指令的实时解释器，每一条机器指令都对应一个微程序。 

控制存储器：存放微程序的只读存储器。
微程序(一个机器周期...如取指阶段..)
- 微指令 (一个节拍)
		微命令 <-> 微操作
		微命令 <-> 微操作\
	微指令
		微命令 <-> 微操作
		微命令 <-> 微操作

QA
什么是微指令和微操作？微程序和机器指令有何关系？微程序和程序之间有何关系？ 
```
答：微指令是控制计算机各部件完成某个基本微操作的命令。微操作是指计算机中最基本的、不可再分解的操作。微指令和微操作是一一对应的，微指令是微操作的控制信号，微操作是微指令的操作过程。
微指令是若干个微命令的集合,微程序是一系列微指令的有序集合。微程序是机器指令的实时解释器，每一条机器指令都对应一个微程序。 
微程序和程序是两个不同的概念。微程序是由微指令组成的，用于描述机器指令，实际上是机器指令的实时解释器，微程序是由计算机的设计者事先编制好并存放在控制存储器中的，一般不提供给用户；程序是由机器指令组成的，由程序员事先编制好并存放在主存放器中。
```

![|475](http://verification.fengzhongzhihan.top/202405152027065.png)
- 最后一个下地址为M: 回到取指周期
基本控制原理
![|450](http://verification.fengzhongzhihan.top/202405152025997.png)
- op: 通过微地址形成部件生成对应的入口P, K
- 通过下地址进行下一步的地址跳转

微指令地址序列产生方式
![|425](http://verification.fengzhongzhihan.top/202406261611533.png)
![|425](http://verification.fengzhongzhihan.top/202406261612742.png)
![|425](http://verification.fengzhongzhihan.top/202406261613145.png)
- 多了一个转移方式 + 分支逻辑


### 8.4.2 取指周期
第一个取指周期的入口地址M由硬件自身产生, 后者指令周期的最后一个指令直接通过下地址跳转到M
![|450](http://verification.fengzhongzhihan.top/202405152028937.png)
- M -> CMAR CM(CMAR) -> CMDR  CMDR发命令
- ad(CMDR) -> CMAR  CM(CMAR) -> CMDR  CMDR发命令
### 8.4.3 执行周期
![|475](http://verification.fengzhongzhihan.top/202405152030525.png)
- 通过OP(IR) -> 地址生成部件 -> CMAR  CM(CMAR) -> CMDR 发命令
- ad(CMDR) -> CMAR  CM(CMAR )-> CMDR CMDR发命令 
- 全部微指令存在 CM 中，程序执行过程中 只需读出

### 8.4.4 总结
![](http://verification.fengzhongzhihan.top/202406261538797.png)

1. 优点：
 ①结构规整，设计效率高；
 ②易于修改，扩展指令系统功能；
 ③可靠性高；
 ④性价比高。
2. 缺点：
 ①执行速度较慢: 访存较频繁, 转移多
 ②执行效率不高 : 未充分发挥数据通路本身具有的并行能力
3. 应用：
  用于对速度要求不太高的、功能较复杂的机器中，特别适用于系列机。

## 8.5 微指令的编码方式
### 8.5.1 直接编码
![](http://verification.fengzhongzhihan.top/202405152034430.png)
### 8.5.2 字段直接编码
注意: 也是直接
![](http://verification.fengzhongzhihan.top/202405152034281.png)
注意 : x个指令当作x + 1个指令处理, 因为都没有也是一种信号

### 8.5.3 字段间接编码
![](http://verification.fengzhongzhihan.top/202406261610112.png)
混合编码 : 直接编码和字段编码（直接和间接）混合使用


