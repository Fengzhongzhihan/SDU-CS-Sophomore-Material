# 1 总体概述

DBS(数据库系统)
- 包括 : DB(一组相互关联的数据的集合 ) + DBMS 
DBMS(数据库管理系统)
- 定义 : 一组用以访问这些数据的程序
- 存在于系统的外存之中, 用户通过DBMS来操纵DB
- 位于操作系统和应用API之间,可以操作文件系统
发展历史
- 层次数据库
- 网状数据库
- 关系数据库
## 1.1 数据库特点
数据库观点 : 
- 数据不是依赖于处理过程的附属品，而是现实世界中独立存在的对象

文件系统 : 程序直接对数据进行存取
数据库系统 : 程序通过DBMS统一对数据进行存取

DBMS 位置
![image.png|400](http://verification.fengzhongzhihan.top/202312201519026.png)


DBMS VS 文件系统
- 数据冗余和不一致
	- 冗余 : 同一信息的多次存储, 容易造成数据不一致
	- 不一致 : 
		- 同一数据不同副本不一致
		- 数据库数据和现实世界的不一致
	- 文件系统 : 不同程序自己管理数据, 冗余大, 容易产生不一致(反过来说), 数据库系统统一组织 + 冗余小 + 保证一致性
- 数据访问
	- 解决(无法迅速找到数据)
- 数据孤立性
	- (数据分散在不同文件, 各文件格式也不同)
- 完整性(满足一致性约束的能力)
- 原子性(要么全做,要么全不做)
- 并发访问 (串行运行的进程，在并行运行时可能出现错误)
	- DBMS由事务保证没有并发错误
- 安全性(支持数据安全管理)
- 备份与恢复(支持备份和恢复)

列出文件处理系统和DBMS 的四个主要区别
1 这两个系统都包含一组数据和一组访问该数据的程序。数据库管
理系统协调数据的物理访问和逻辑访问，而文件处理系统只协调
物理访问。
2 数据库管理系统通过确保一个物理数据对所有授权访问它的程序
可用来减少数据的重复量，而文件处理系统中一个程序写入的数
据可能无法被另一个程序读取。
3 数据库管理系统的设计是为了方便灵活地存取数据(即，查询)，
而文件处理系统被设计成允许预先确定的数据访问(即编译程序)。
4 数据库管理系统旨在协调多个用户同时访问相同的数据。文件处
理系统通常被设计成允许一个或多个程序同时访问不同的数据文
件。在文件处理系统中，只有当两个程序都对文件具有只读访问
权限时，两个程序才能同时访问一个文件。

数据库系统总体特点 : 
①应用目标明确：面向一个企业(组织)
②统一的数据模型：冗余小，易扩充，易访问
③与程序相对独立：数据独立性高，共享程度高
④统一的控制功能: 安全性、完整性控制、并发控制、备份与恢复


补充: 
- 数据库需要文件系统来操作硬件设备
- 文件->数据库,是理念和技术的巨大创新
- 数据库->分布式文件(大数据,只读但不需要改)
## 1.2 数据模型

模式，schema：
数据库的总体设计
数据的组织结构和特征
是数据库的（型）

如 表：Student（学生信息）
字段：StudentID（学生ID，整数）、Name（姓名，字符串）、Age（年龄，整数）

实例，instance：
特定时刻，db中信息的集合
是数据库的（值）

如
StudentID: 1, Name: "John", Age: 20
StudentID: 2, Name: "Alice", Age: 22
StudentID: 3, Name: "Bob", Age: 21

![image.png|500](http://verification.fengzhongzhihan.top/202312201532708.png)

### 1.2.1 三级模式和两级映像

**三级模式**
- 外模式(子模式, 用户模式)
	- 用户看到的数据逻辑结构
- 逻辑模式(全局模式)
	- 全体数据的逻辑结构
- 物理模式
	- 数据的存储结构

**二级映像**
- 物理映像, 逻辑映像

**二级数据独立性**
- 数据的物理独立性：当物理模式发生变化时，通过调整物理/逻辑模式映像，可以保持逻辑模式不变，进而应用程序不需改变。这种数据和程序的独立性，称为数据的物理独立性。
	- 适应性和灵活性： 物理数据独立性允许数据库管理员或系统设计者更灵活地选择适应特定硬件或性能需求的存储结构。这使得系统可以在不影响应用程序的情况下进行优化和调整。

- 数据的逻辑独立性：当全局模式发生变化时，通过调整外/全局模式映像，可能保持外模式不变，进而应用程序不变。这种数据和程序的独立性，称为数据的逻辑独立性。

![image.png|475](http://verification.fengzhongzhihan.top/202312201527392.png)

### 1.2.2 数据模型(data model)
模型：（严格定义的）（一组）关于（数据、联系、语义、约束）概念的集合。
目标：陈述清楚数据的结构、联系、语义、约束...


模型层次 : 
- 概念模型(ER图)
- 逻辑模型
	- 网状
	- 层次
	- 关系....

### 1.2.3 几大用户
- naive users - application interfaces
- application programmers - application programs
- sophisticated users - query tools(需要懂技术才能用)
- database administrators - administration tools
### 1.2.4 事务管理

定义 : 完成单一逻辑功能的操作的集合

特征 : ACID 
- Atomicity : 原子性
- Concistency : 一致性
- Isolation : 隔离性 
- Durability : 持久性
### 1.2.5 体系结构

发展历史
- 主机方式
- 双层体系结构(客户+服务器)
- 多层体系结构:更完善

在两层体系结构中，应用程序驻留在客户机上，通过查询语言表达式
来调用服务器上的数据库系统功能。
- 客户端直接与数据库调用

而在一个三层体系结构中，客户机只作为一个前端并且不包含任何直
接的数据库调用。客户端通常通过一个表单界面与应用服务器进行通
信。而应用服务器与数据库系统通信与访问数据。
- 客户端只是作为一个前端, 通过表单与应用服务器交互, 应用服务器与数据库系统交互

对Web 应用来说，显然使三层体系结构更好。因为Web 应用的访问量
很大，客户机直接通过查询语言与数据库系统进行交互可能会出现阻
塞（访问量太大），数据更新不及时（高并发引起），数据丢失（大数
据量）等问题，通过一个应用服务器，我们可以进行负载均衡、分发
等设置，由此来缓解数据库系统的压力。
## 1.3 关系模型
### 1.3.1 关系表
**关系数据库**:由一系列表组成,每个表由唯一的名字做标识

**二维表**
- 每个表由若干行组成(元组),若干列组成(属性),对应的值(行列值)称为元组分量
- 域:同一列,也是同类型值的集合
- 笛卡尔积(Cartesian Product):D1* D2 * D3...个数等于n1* n2  * n3...
	- 关系:笛卡尔积的的子集

**关系和表的区别**
- 关系无限,表有限
- 表无次序,关系列有序

对关系进行限制
- 令关系元组数目是有限的
- 赋予关系列属性名,取消次序
- 此时关系=表

我们一般认为关系 = 表

**关系的基本特征**
- 行无序,行不同,列无序,列不同,不同列可出自同一个域
- 无序和不同代表集合中的元素特性

关系模式(型)(SC)
关系(变量)(sc) 是关系模式的一个实例 

![image.png](http://verification.fengzhongzhihan.top/202312202128640.png)

### 1.3.2 码(对关系模式的约束)
- Superkey:超码:能唯一标识元组
- candidate key:候选码:超码的最小单元, 任意真子集都不是超码
- primary key:主码:选定一个候选码作为主码
- foreignKey:外码(一个关系中的域是另一个关系中的主码)
	- 关系R的一组属性F，如果F同关系S的主码相对应，则称：
		F是R的外码
		R是参照关系(Referencing Relation)
		S是被参照关系(Referenced Relation)
		R通过外码F参照关系S

### 1.3.3 模式图

![image.png](http://verification.fengzhongzhihan.top/202312201546848.png)
模式图表示各关系模式
- 属性
- 主码
- 关系引用

## 1.4 关系代数

![image.png](http://verification.fengzhongzhihan.top/202309141007694.png)

分别表示选择,投影,并,差,笛卡尔积,更名
- 其中并,差要求相容

相容关系:
- 同元
- 对应列同域
- 不要求列同名

注意: 
- 投影和并可以分配
	Πpid,name(S∪T)≡Πpid,name(S) ∪ Πpid,name(T)
- 投影和差不可分配
	Πpid,name(S-T)≠Πpid,name(S)  - Πpid,name(T)


# 2 SQL
## 2.1 基本数据类型
**字符类型**
char,varchar(~string)
**数类型**
int ,smallint,numeric,real,double pricision
(~double,前n位为数字个数,后m位为小数个数),float
**时间类型**
date:**YYYY-MM-DD**
datetime:**YYYY-MM-DD HH:MM:SS**
timestamp:**YYYY-MM-DD HH:MM:SS**

```sql
cast '2001-01-31'as timestamp
extract(year from Vdatetime)
date1-date2=两日期间的天数
```

强制类型转换type coercion
**自定义数据类型**
- distinct type
- structured type
```sql
create type person(pid char,name varchar)
create domain person(pid char,name varchar)
--两者区别:前者不支持强制类型转化(强类型),后者可以直接进行运算(弱类型)
```

## 2.2 DDL部分
数据定义语言
   (DataDefinitionLanguage,DDL)
	通过变更数据字典，完成模式的定义和修改


DDL：create/drop/alter
DCL：grant/revoke
DML：select/delete/insert/update
事务管理语句：commit/rollback

```sql
-- 表的建立
create table s
(
	sno char(2),
	sname varchar(8)not null,
	sage int,
	primary key(sno),
	check(sage between 16 and 30)--添加约束
);
-- 表的删除和增加列
drop table s;
alter table s add(dept varchar(6));
--add,modify,drop
--注意:ddl与事务无关
```

定义索引
常用索引:B+,hash索引
```sql
--产生索引
create unique index s1 on s(sno);
create index s3 on s(dept,sage);
--删除行
drop index s1;
```
## 2.3 DML查询

数据操纵语言(DataManipulationLanguage,DML)
	完成数据库实例的查询和修改

### 2.3.1 查询基本结构

```sql
--select a1,a2...from r1,r2....where P,在选定m列对应的行的的个数n1,n2.n3...共有(m,n1*n2*n3...)个元素的笛卡尔积中进行选择
select sno,sname,sage
from s
where dept='计科'
select all--不去重复元组(可省略all)
select distinct--去重复元组
select * --选择全部属性
r.* -- 表示r全部属性
-- 逻辑连词
not/and/or
between and
not between and
-- 更名,相当于拷贝了一份新的,as本身可以省略
oldname as newname

```
order by不影响关系本身,只是为显示次序方便
```sql
-- 升序 asc(可以忽略) 降序 desc
select *
from sc
where score>60
order by cno,score,desc   --(先按照cno从小到大排,若相同再...)
```

实例:将parent表转化为grandparant
```sql
select u.id, w.pid as gpid
from parent as u,parent as w
where u.pid=w.id;
```
### 2.3.2 字符串操作
```sql
-- like中,%表示任意字符串,_表示任意一个字符
addr like'%济南%'
-- 转义字符%
-- 如匹配以’%’开头的字符
like ‘\%%’
```
### 2.3.3 聚集函数

**重复的处理理念**
任何元组都有标识属性rowid(伪列)

**聚集函数**
sum,count,max,min,avg
注意
- 只有count可以加*
- 返回结果是一个关系
- 都是默认作用于多重集,此时一行语句必须都是聚集关系
- 强制作用集合使用distinct

**分组聚集**

group by:按照某一列不同属性进行分组
- 此时select可以选择该列,但不可以选择别的列

having:对分组进行限定
- 一般跟在group by 后面, 一般带有聚集函数
- 其实having是一种取行运算σ

**例题**:求三门以上及格课程的学生和及格门数
```sql
select sno,count(*)
from sc
where score>=60
group by sno
having count(*)>=3

⑤select s.sno,sname,avg(score)
① 	from s,sc
②  	where s.sno=sc.sno
		 and score>=60
③ 	group by s.sno,sname
④ 	having count(*)>=3
⑥ 	order by s.sno;

```
求学生的平均成绩
```sql
select sno,count(*),avg(score)
from sc
group by sno
```


### 2.3.4 null判定

三值:true,false,unknown,其中unknown与false同样处理
- 聚集函数的输入集合忽略null
- 作用于空集合:count(null)=0,其他返回null
### 2.3.5 嵌套子查询

**in**
枚举集合
```sql
select * from sc
where cno in (‘c1’,’c2’,’c5’);
```

显示出没有选某些课的某些学生
```sql
Select sno,cno 
From s,c
Where (sno,cno) not in
	(select sno,cno from sc)
```

**exists**
求选了c1的学生
```sql
select * from s
where exists
(select * --此处写什么都无所谓
	 from sc 
	 where sc.sno=s.sno and cno=‘c1’)
 
```

求没有选C1的学生, 相当于对于选C1的学生求补集
```sql
select * from s
		where not exists
		(select * 
		     from sc 
		     where sc.sno=s.sno
			and cno=‘c1’)

```

分别用in, exist , 笛卡尔积来求学了c1的学生

```sql
求学了c1的学生
①  select * from s
		where sno in
		(select sno from sc where cno=‘c1’);
② select * from s	where exists
		(select *  from sc  
			where  sc.sno=s.sno and cno=‘c1’); 
③ select s.* from s,sc
where s.sno=sc.sno and cno=‘c1’;
```

求没有学c1的学生
```sql
求没有学c1的学生
① select * from s
		where sno not in
		(select sno from sc where cno=‘c1’);
②select * from s
		where not exists
		(select *  from sc 
		      where sno=s.sno and cno=‘c1’);
无法通过笛卡尔积(from r1,r2)实现“不存在”的语义, 因为选了c1以及别的课程的学生也会被选出来
Select * from s,sc
where s.sno=sc.sno and cno <>'c1'
```
### 2.3.6 集合比较(代替exist)

some:某一个
all:所有

求不是最低成绩的修课记录
```sql
select * from sc where score>
some(select score from sc as t
  where t.cno=sc.cno)
```

求修课最多的人数

```sql
select cno,count(*)  from sc
group by cno
having count(*)>=
	all(select count(*) from sc
	group by cno)
```

求各门课程成绩均不相同的学生
```sql
select * from s
where unique
	(select score
		 from sc
		where sc.sno=s.sno)
```
### 2.3.7 集合连接操作

**运算符**
交intersect 并union 差 except

连接分类
- 自连接(self-join)
	- from cos as c1, cos as c2
- 自然连接((natural join)
	- 和内连接区别
		- 自然连接只能是**同名属性**的内连接。
		- 内连接可以使用using或on子句来指定连接条件，连接条件中指出某两字段相等（**可以不同名**）


- 内连接
	- 是有条件的交叉连接
	- 内连接返回的是两列id
- 外连接(outer join)
	- 左/右外连接:包括左/右的所有属性,不顾是否条件相等
	- 全外连接:包括全部属性:笛卡尔积
- 交叉连接(join)
	- 笛卡尔积

### 2.3.8 全部概念处理
- 超集(superset)
not exists(B-A)
```sql
select ... 
from s
where not exists
(
select
	B--全部的...
	except
select
	A--需要判断的...
)
```
求选了所有课程的同学

```sql
select sno from s
 where not exists
(
-- 所有课程
(select cno from c)
	except
-- 该学生选的课程
(select cno from sc 
where sc.sno=s.sno)
)

(select sno from s)
	except
   (select sno
		   from (
			(select sno,cno from s,c)
			except
		           (select sno,cno from sc)
		   ) as r(sno,cno)
   )

```

- 关系代数(➗符号)
not int not in
sc ➗ c
```sql
--学生不在 有课没上的学生列表里面
select sno from s
 where sno not in
(select sno 
	from s,c
  where (sno,cno) not in
	(select sno,cno from sc))

```

- 任意
not exist not exist
```sql
-- 不 不满足课都有对应的学生
select sno from s
  where not exists
( -- 找出没人选的课
select * from c 
	  where not exists 
	  -- 满足有学生选
   (select * from sc	
	where  sc.sno=s.sno 
		 and sc.cno=c.cno))
```

### 2.3.9 派生, with和视图

派生: 指from加select语句, 把查询结果用在from中

求平均成绩良好(≥80)的学生人数；
```sql
select count(*)  
   from (select sno,avg(score)
		from sc
		group by sno
		)as avgsc(sno,avgscore)
  where avgscore>=80

with avgsc(sno,avgscore) as
 (select sno,avg(score)
	from sc
	group by sno
	)
	select count(*)  
		from avgsc
		where avgscore>=80

```
自己查询建立一个关系,设为with即可

**优点**
- 安全:只能显示部分内容
- 方便:但是不能提高效率

--With
视图,相当于函数,只有在使用的时候才会创建视图
- 使用的时候视图和表等价使用
```sql
create view avgscv(sno,avgscore) as
		  select sno,avg(score)
		       from sc  group by sno
select count(*)  
		     from avgscv
		     where avgscore>=80
```

视图的更新
- 子集视图:原视图的某些行或者某些列
- 一般情况下,行列子视图可以更新,带聚集的不适合更新(若只选一门另说)
	- 行列子视图特征
		- select子句中只有属性名
		- 没有distinct,表达式,聚集...
		- from子句只有一个关系
		- 不含group by,having子句

with check option
- 指出在可更新视图上所进行的修改都要符合select语句所指定的限制条件，这样可以确保数据修改后，仍可通过视图看到修改的数据
```sql
create view sv1 as
		 select sno,sname,sage from s
		       where sdept=‘计’ and sage>=20
		with check option;
update sv1 set sage=19 where sno=‘s3’;
	--不可以更新，update语句将被DBMS拒绝
	--如果不带,则update产生delete效果
```

### 2.3.10 union组合查询

具有相同的列数目即可union
- 如果列名不同,按顺序, 取union前的表名
```sql
select * 
from ( select * from t union select * from s ) as a
```

select * from t union select * from s
### 2.3.11 事务(transaction)
一个sql执行, 便开启了一个事务, 但未必结束了事务

下列都代表了结束事务, 未出现的时候sql同属于一个事务
- commit 提交事务
- rollback 回滚事务:相当于事务没有发生

## 2.4 DML更新数据
delete insert update
### 2.4.1 delete

删除的关系型和原子性:
- 先通过where语句统一打上标记最后再统一删除

```sql
delete 
from 
where..--若无where,则表示删除r中的所有元组
```
删除低于本门课平均成绩的修课记录
```sql
delete from sc 
		where score<
		(select avg(score)
			from sc as t
			where t.cno=sc.cno)
```


### 2.4.2 insert
```sql
insert into table1 
values('2002','wyh')
-- 如果插入属性不是按照顺序来的,则需要在table后加入属性名(a,b,c)..
-- 例如 insert into sc(sno, cno, score) values('s1', 'c3', null)
-- 如果只插入前两列, 则后面可以省略insert into sc(sno,cno)
-- values(‘s1’, ‘c3’)

insert all into table1 
values(...)
--嵌套
insert into table1 
select * from dual
```

插入s1选修c3，无成绩
```sql
insert into sc 
	   values(‘s1’, ‘c3’,null)
```

尚未学c3的计算机系学生，全部学习课程c3，无成绩
```sql
insert into sc(sno,cno)
select sno,’c3’
	 from s
	 where dept=‘计’ 
	and sno not in
	(select sno from sc 
		where cno=‘c3’)

```

### 2.4.3 update
```sql
update 
set ..
where..

--嵌套
update
set(A1,A2..)=select..
where..
```

把hw的成绩并入sc
![image.png|170](http://verification.fengzhongzhihan.top/202309271419244.png)

```sql
update sc
		set score=(
		select sc.score+hw.score
				from hw
				where hw.sno=sc.sno
				      and hw.cno=sc.cno)
		where exists
		(select * from hw 
		      where hw.sno=sc.sno	
			     and hw.cno=sc.cno)
```

重新设置计算机系学生
	学习课程门数cnum和平均成绩avgs：

```sql
update s
	set (cnum,avgs)=(select count(*),avg(score)
		  from sc
		  where sc.sno=s.sno
		  )
	where dept=‘计’;
```
## 2.5 中级SQL

### 2.5.1 用户定义类型
```sql
create type Dollars as numeric (12,2)
create type person
			(pid char(18),
			name varchar(8));

```

### 2.5.2 LOB
large object :用于存储大空间的值

LOB 数据通常通过指针和文件的组合来实现。数据库会将实际的大型对象存储在外部文件中，而数据库表中则存储对这些对象的引用指针。

分类
- BLOB:二进制
- CLOB:字符型

### 2.5.3 模式, 目录, 环境

![image.png](http://verification.fengzhongzhihan.top/202401131642828.png)

一个dbms可以管理多个catalog(instance)
一个instance可以含多个schema(userschema)
一个schema可以含多个关系(table/view)

### 2.5.4 授权和命令
```sql
grant select on test8_00 to user+'id'--给与权限
select * from user+'id'.table
revoke select on test8_00 from user+'id'--收回权限
```

### 2.5.5 完整性约束

RDB完整性约束分类
- 实体完整性
- 参照完整性
- 用户自定义完整性
实体完整性
- 主码非空、唯一
- 定义了主码，系统自动保证实体完整性
参照完整性
- 定义了外码，系统自动保证参照完整性
用户自定义完整性
- 根据语义约束，用户自定义的完整性约束
- not null, unique,check,assertion…

```sql
not null--不允许出现空值
unique(A1,A2,A3)--不允许关系中的元组取值都相同
check(P)
create table s(… 
		  check (sage between 16 and 30),
	    check (sdept<>’D3’ or sage<25)
		 check dno in (select dno from dept)
     )

- foreign key 
create table s(foreign key(dno)references dept(dno))
--其中insert/delete/update 需要注意三种选项
-- cascade:级联 set null :置空 restrict(默认)(拒绝删除)
create table s(foreign key(dno)references dept(dno)on delete cascade) (一同删除)

```
**断言**
assertion是定义在数据库上的约束，不是关系模式(table)的定义约束

每个人的选课门数小于等于50
```sql
create assertion ass1 check(50>=all(select count * from sc group by sno))
```

### 2.5.6 授权
角色 : 一组权限的集合

用户和角色的关系
- 连接使用数据库，必须以一个特定的用户身份
- 不能使用role身份直接连接使用数据库
- 一个用户和角色 : 多对多关系, 用户包含角色
- 角色可以拥有角色
- 角色拥有关系可以传递
- 权限可以授予用户或者角色
- 用户拥有授给本用户的所有权利，以及本用户具有的角色的所有权利
- 每个用户对自己模式下的表,视图…拥有属主权(owner)

grant 
例子:u1将s(sno,sname) 的查询权授予u2
```sql
grant select (sno,name)on s to user2 
```

转授权
``` sql
grant with grant option--具有转授权
u1:grant select on s to u4 with grant option;
		//u4拥有了select s权,并有转授权权
	u4:grant select on s to u5;
		//成功，u5拥有了select s权

```

在sql中,若收回从u1到u2,从DBA->user有连通则不收回权限,否则均收回权限

权限回收
```sql
revoke select on s from s
u1:grant select on sc to u2 with grant option;
		u2:grant select on sc to u3; 
		u1:revoke select on sc from u2;
		    //u2权力被回收后，u3不再具有select sc权

```
### 2.5.7 用户管理
```sql
create user username identified by password;
drop user  username;
create role rolename;
drop role  rolename;

-- 赋予用户角色
grant role1 to u1;
revoke role1 from u1;
```
## 2.6 C++ DBMS的联系
对于C++而言,需要一个包来支持sql进行包装pack1
对于DMBS而言,需要一个包来解析pack1

因此JDBC和ODBC是联系两者的桥梁
- JDBC:java(Java DataBase Connectivity)
- ODBC:c++(Open Database Connectivity)

# 3 关系代数(过程语言)

输入一个或两个关系
输出一个新的关系
## 3.1 六大基本操作符 : σ, Π, ∪, -, ×, ρ
select:σ 
- 相当于where, 按照行来选择元组
- 三大连接符![image.png](http://verification.fengzhongzhihan.top/202310261656975.png)
- 六大运算符号![image.png](http://verification.fengzhongzhihan.top/202310261656307.png)

project:Π
- 相当于select
- 注意会默认去重
- 选择列

union:∪
- 需要列数相同
- 需要列属性匹配

set diffenrence:-
- 要求和union相同

cartesian product :x
- 相当于a,b中的

rename:ρ
- 重命名关系名(A1,A2,A3...)

**例子 : 找出最大收入的教授**
1. 找出不是最大收入的教授的收入
![image.png](http://verification.fengzhongzhihan.top/202310261700229.png)
2. 找出最大收入的教授
![image.png](http://verification.fengzhongzhihan.top/202310261700862.png)

**找到物理系的教授ID和他们教授的课程**
两种表达方式
![image.png](http://verification.fengzhongzhihan.top/202310261701882.png)
![image.png](http://verification.fengzhongzhihan.top/202310261701692.png)

**相应的符号**
![image.png](http://verification.fengzhongzhihan.top/202310261702730.png)
## 3.2 空值的使用
- 空值类型unknown,或者根本不存在
- 参加判断
	- 介于true 和 false 之间![image.png](http://verification.fengzhongzhihan.top/202310261716894.png)

- 聚集函数忽略null
- 算数函数包含null的结果统一是null
- 对于去重和分组,null和其他元素一样,算做同一类
- 返回查询的时候如果是null 则认为是false 
## 3.3 冗余操作 : 简化表达式
### 3.3.1 ∩
- 列数相同
- 属性相配
- r∩s = r - (r-s)

### 3.3.2 natural join
- 符号![image.png](http://verification.fengzhongzhihan.top/202310261703241.png)
- 举例
- ![image.png|425](http://verification.fengzhongzhihan.top/202312271504928.png)

- 方法
	- 先做笛卡尔积
	- 再找到相同名称的列,进行筛选一样的
	- 去重
![image.png|292](http://verification.fengzhongzhihan.top/202310261707330.png)

找到计算机学院所有老师的名字以及他们教的课
![image.png](http://verification.fengzhongzhihan.top/202310261707368.png)

### 3.3.3 assignment (⬅)
- 其实就是临时量:把一个关系赋给t
### 3.3.4 division(➗)

- t表示找到R中包含全部s属性的其他属性
![image.png](http://verification.fengzhongzhihan.top/202310261709742.png)

- 实现
![image.png](http://verification.fengzhongzhihan.top/202312271518431.png)

![image.png|475](http://verification.fengzhongzhihan.top/202312271519857.png)

### 3.3.5 outer join

作用 : 避免信息的丢失

- 分为inner,left,right,full
![image.png|316](http://verification.fengzhongzhihan.top/202310261714149.png)
![image.png|226](http://verification.fengzhongzhihan.top/202310261714918.png)

![image.png|425](http://verification.fengzhongzhihan.top/202310261714214.png)
![image.png|425](http://verification.fengzhongzhihan.top/202310261714896.png)
![image.png|425](http://verification.fengzhongzhihan.top/202310261714697.png)
![image.png|450](http://verification.fengzhongzhihan.top/202310261714977.png)

具体的实现(以outerjoin为例)
![image.png](http://verification.fengzhongzhihan.top/202312271524799.png)

## 3.4 聚集


![image.png](http://verification.fengzhongzhihan.top/202310261717148.png)
- G1,G2..Gn代表group by G1,G2..Gn
- F代表聚集函数
- Ai代表属性名称
- 常用ρ来对聚集函数进行as重命名
![image.png](http://verification.fengzhongzhihan.top/202312271529614.png)

默认支持命名属性为聚集操作的一环
![image.png](http://verification.fengzhongzhihan.top/202312271530115.png)

## 3.5 SQL和关系代数

![image.png](http://verification.fengzhongzhihan.top/202312271536106.png)

![image.png](http://verification.fengzhongzhihan.top/202312271536158.png)

## 3.6 修改操作

所有修改操作都可以用assignment来写

### 3.6.1 Deletion
- 只能删除整个元组
- ![image.png](http://verification.fengzhongzhihan.top/202310261727591.png)
- 此时E代表删除的内容

例子
![image.png](http://verification.fengzhongzhihan.top/202312271539436.png)

### 3.6.2 insertion
- ![image.png](http://verification.fengzhongzhihan.top/202310261731497.png)

### 3.6.3 Updating
- ![image.png|203](http://verification.fengzhongzhihan.top/202310261731383.png)
直接在F处进行修改即可
![image.png](http://verification.fengzhongzhihan.top/202312271547355.png)


**例子**
查找所有拥有贷款和银行账户的客户的姓名。
![image.png](http://verification.fengzhongzhihan.top/202310261733502.png)

查找所有在银行有贷款的客户姓名
![image.png](http://verification.fengzhongzhihan.top/202310261733321.png)

查找所有同时在downtown和uptown分行的顾客
![image.png|500](http://verification.fengzhongzhihan.top/202310261735984.png)

## 3.7 元组计算表示(非过程化查询语言)

表示方法

![image.png](http://verification.fengzhongzhihan.top/202312271551416.png)

**原子公式**
![image.png|350](http://verification.fengzhongzhihan.top/202310261721120.png)
等价公式
![image.png](http://verification.fengzhongzhihan.top/202310261721805.png)


**例子**
此时选择的时候就默认了属性

找到薪水大于80000的全部信息
![image.png](http://verification.fengzhongzhihan.top/202312271555418.png)

只显示id
![image.png|475](http://verification.fengzhongzhihan.top/202310261722614.png)

找到部门在watson楼的老师
![image.png](http://verification.fengzhongzhihan.top/202310261723180.png)

找到选修了所有生物部门开的课的学生
![image.png|500](http://verification.fengzhongzhihan.top/202310261724961.png)
## 3.8 元组表达式的安全性
有可能产生无限关系的表达式时不安全的, 因此需要限制集合

r中所有值的集合
![image.png](http://verification.fengzhongzhihan.top/202310261725734.png)

安全性定义
![image.png](http://verification.fengzhongzhihan.top/202310261725349.png)

举例
![image.png|475](http://verification.fengzhongzhihan.top/202310261725713.png)

### 3.8.1 元组关系运算和关系代数关系
![image.png](http://verification.fengzhongzhihan.top/202310261726066.png)
# 4 存储和文件结构
## 4.1 存储设备
用户<=>DBMS(逻辑)<=>OS(物理)<=>HW访问

物理介质分类
- volatile storage(易失)
	- Cache-fastest(内存)
	- Main memory-main(内存)
	- 电源关闭不复存在
- non-volatile storage
	- Flash memory-闪存(外存)(常用于便捷式可携带设备)
	- magnetic disks-磁盘(外存)
	- optical storage(外存)
	- tape storage(磁带)   
	- 包括二级和三级存储，以及备份的主存储器。
	- 即使电源关闭依然存在
关系
![image.png|350](http://verification.fengzhongzhihan.top/202310261752262.png)
从上而下:访问速度下降,访问容量增大
从上而下每两个分为一类
- primary storage : 最快但是易失
- secondary storage : 如闪存, 磁盘
- tertiary storage : 如磁带, 光盘

## 4.2 磁盘
### 4.2.1 磁盘工作原理
![image.png|475](http://verification.fengzhongzhihan.top/202310261754696.png)
转圈,转到磁头就读取数据

磁头: 定位非常接近磁盘表面(几乎接触它)读取或写入磁编码信息。

扇区是可以读写的数据的最小单位。
扇区大小通常为512字节每个轨道的典型扇区:

读取过程
- 盘臂摆动，使磁头位于正确的轨道上
- 盘片不断旋转; 当扇区从头下经过时读/口写数据

磁盘通常直接连接到计算机系统
在存储区域网络(SAN)中，大量的磁盘通过高速网络连接到许多服务器
在网络附加存储(NAS)网络存储中，使用网络文件系统协议提供一个文件系统接，而不是提供一个磁盘系统接口

### 4.2.2 磁盘性能度量


访问时间包括
- 寻道时间-需要重新定位手臂在正确的轨道
	- 平均寻道时间是最坏情况寻道时间的1/2。
- 等待时间-这个扇区进入到头部下方所需的时间。
	- 平均等待时间是最坏情况等待时间的1/2。

数据传输速率
- 数据从磁盘检索或存储到磁盘的速率。
- 多个磁盘可以共享一个控制器，因此控制器能够处理的速率也很重要

平均故障时间(MTTF)-预计磁盘连续运行而不会发生任何故障的平均时间。

### 4.2.3 磁盘传输优化
块-一个连续的扇区序列从一个单一的轨道
- 数据在磁盘和主存之间传输

磁盘臂调度算法命令暂停访问的轨道，使磁盘臂移动最小化

文件组织-通过组织块以对应于如何访问数据来优化块访问时间

非易失性写缓冲区-通过立即将块写入非易失性 RAM 缓冲区来加速磁盘写入

日志磁盘-专门用于编写块更新的顺序日志的磁盘

文件系统通常重新排序写到磁盘以提高性能
- 日志记录文件系统以安全的顺序将数据写入 NV-RAM 或日志磁盘
- 重新排序而不记录: 文件系统数据损坏的风险

### 4.2.4 闪存和RAID

闪存 : 写入很快, NAND : 擦除很慢
将逻辑页地址重新映射到物理页地址可以避免等待擦除

RAID: 独立磁盘的冗余阵列
- 管理大量磁盘的磁盘组织技术，提供单个磁盘的视图
- 并行使用多个磁盘，容量大、速度快，数据冗余存储可靠性高，即使磁盘故障也能恢复数据
- 一组 N 个磁盘中的某个磁盘发生故障的可能性远远高于一个特定磁盘发生故障的可能性。

利用冗余提高可靠性
冗余-存储可用于重新生成在磁盘故障中丢失的信息的额外信息

复制每个磁盘。逻辑磁盘由两个物理磁盘组成。
每次写操作都在两个磁盘上执行，读操作可以从任何一个磁盘进行

如果一对磁盘中的一个出现故障，另一个磁盘中的数据仍然可用
磁盘系统并行性的两个主要目标:
1. 负载平衡多个小访问以提高吞吐量
2. 并行化大型访问以减少响应时间。

**六大级别**
RAID 级别0: 块条带化; 非冗余。
- 在数据丢失不是关键的高性能应用程序中使用。
RAID 级别1: 具有块条带的镜像磁盘
- 提供最佳的写入性能。适用于在数据库系统中存储日志文件等应用程序。
RAID 级别2: 带位条带的内存样式错误纠正代码(ECC)。
RAID 级别3: 位交织奇偶校验
RAID 级别4: 块-交织奇偶校验; 使用块级别条带化，并在单独的磁盘上为来自 N 个其他磁盘的对应块保留一个奇偶校验块。
RAID 级别5: 块交织的分布式奇偶校验; 在所有 N + 1磁盘中分区数据和奇偶校验，而不是将数据存储在 N 个磁盘中，奇偶校验存储在1个磁盘中。
RAID 级别6: P + Q 冗余方案; 类似于级别5，但是存储额外的冗余信息以防止多个磁盘故障。

**分类**
软件 RAID: RAID 实现完全在软件中完成，没有特殊的硬件支持
硬件 RAID: 具有特殊硬件的 RAID 实现
## 4.3 文件结构
数据库存储为一组文件。每个文件是一个记录序列。记录是一系列字段。

地区(列)->记录(元组)->文件->数据库

简单方法
- 假定记录长度固定
- 每个文件只有一种类型
- 不同关系用不同文件

每个记录i的起始地址是byte n*(i-1)
- 但是不同的记录可能会跨块,因此不允许跨块
- 删除记录i方法
	- 向前移动记录
	- 将n号记录放到i的位置
	- 将空记录放在空闲链表中
		- 表中的空位置可以存放下个空位置的指针从而节省空间
		- 在文件头中存储第一个删除记录的地址。使用第一个记录来存储第二个被删除记录的地址，依此类推
		- 可以将这些存储的地址视为指针，因为它们“指向”记录的位置
		- 更有效的空间表示: 重用空闲记录的普通属性空间来存储指针。(在已用记录中没有存储指针

可变记录
- 一个文件存储不同类型的记录
- 允许拥有可变长度(varchar等)
	- 实际数据存放在定长文件之后
- 属性按序排放
- 空属性用null-value bitmap
- 可变长度属性由固定大小(偏移量，长度)表示，如21,5..实际数据存储在所有固定长度属性之后
![image.png](http://verification.fengzhongzhihan.top/202310271123935.png)


**分槽页结构**
![image.png|575](http://verification.fengzhongzhihan.top/202310271119521.png)
blockheader
- 记录入口的个数
- 块中可用空间的末尾
- 每一个记录的位置和大小

记录之间不允许有空值,且可以移动,同时blockheader进行改变
指针不应该直接指向记录,应该指向标头



## 4.4 记录文件的组织形式
堆:可以放在任意一个有空间的地方
顺序:根据记录的搜索键值按顺序存储记录
- 文件里的记录按搜索码顺序排列
- 删除-使用指针链
- 插入-定位记录要插入的位置，如果有空闲空间插入，如果没有空闲空间，将记录插入溢出块。
- 在任何情况下，指针链都必须更新需要不时地重新组织文件以恢复顺序

散列:根据每条记录的某些属性计算出的散列函数; 结果指定记录应该放置在文件的哪个块中

多表聚集文件:一个文件可以存放不同关系的记录
- 将相关记录存储在同一块中，以最小化 I/O
- 不适用于仅涉及部门结果的查询

关系名称的信息关系名称，每个关系名称的类型和属性的长度，以及视图完整性的定义约束用户和会计信息，包括密码每个关系中元组的统计和描述数据数量物理文件组织信息关系如何存储(顺序/哈希/...)关系的物理位置关于索引的信息

数据字典(也称为系统目录)存储元数据; 即关于数据的数据
- 关于关系名称的信息
	- 关系名称
	- 每个关系的属性的类型和长度, 名称
	- 视图的定义和名称
	- 以及完整性约束的定义
- 关于索引的信息
- 物理文件组织信息
- User and accounting information, including passwords
- Statistical and descriptive data number of tuples in each relation

磁盘上的关系表示
为高效访问内存而设计的专用数据结构
![image.png](http://verification.fengzhongzhihan.top/202401132155024.png)

## 4.5 内存访问
数据库文件被划分为固定长度的存储单元（称为块）。 
- 块是存储分配和数据传输的单位
目的:减少磁盘和内存之间的块传输数量I/O
- 可以通过在主内存中保留尽可能多的块来减少IO。


cache——主内存的一部分，可用于存储磁盘块的副本。
缓冲区管理器——负责在主内存中分配缓冲区空间的子系统。

当程序需要磁盘上的块时，程序会调用缓冲区管理器。
- 如果该块已经在缓冲区中，则缓冲区管理器返回该块在主内存中的地址
- 如果该块不在缓冲区中，
	- 则缓冲区管理器在缓冲区中为块分配空间
	- 将块从磁盘读取到缓冲区，并将块在主存中的地址返回给请求者。

如果需要，替换（扔掉）其他一些块，为新块腾出空间。
- 固定块-不允许写回磁盘的内存块。处理的时候打上块
- 替换块策略:
	- LRU策略(least used block),使用过去预测未来
		- 涉及到重复数据扫描的访问模式,LRU可能是坏策略
	- 立即抛出策略——一旦处理完该块的最终元组，就释放该块占用的空间
	- 最近使用（MRU）策略 - 系统必须固定当前正在处理的块
	- 数据字典被频繁访问, 因此将数据字典块保留在主内存缓冲区中
# 5 索引和哈希

## 5.1 索引类型
索引:用来加速查找

Search Key-属性到用于在文件中查找记录的一组属性。
索引文件由记录(称为索引条目)组成
- search-key + pointer 

按有序分类
- 有序索引:搜索键按排序顺序存储
- 哈希索引:使用哈希函数将搜索键分布在桶中

有效支持的类型
- 在属性中具有指定值的记录
- 或者在属性值范围内具有指定值的记录。

按主次分类
- 主索引(聚类索引):顺序文件中,其搜索键指定文件的顺序,
	- 注意:搜索键未必是主码,如age
- 辅助索引((聚类索引):):搜索键顺序与文件顺序不同
- 索引顺序文件:具有主索引的有序顺序文件

按稠密分类
- 稠密索引:每一个索引都对应了一个记录
![image.png](http://verification.fengzhongzhihan.top/202401141506605.png)

- 稀疏索引:仅包含某些搜索键值的索引记录
	- 适用于在搜索键上按顺序排列记录的情况
	- 如果要找K, 先找到小于K的文件, 再进行顺序搜索
	- 与稠密索引相比：
		- 插入和删除所需的空间和维护开销更少
		- 定位记录时通常比密集索引慢
	- 文件中每个块都有一个索引条目，对应于块中的最小搜索键值。
	- 索引记录指向一个存储桶，该存储桶包含指向具有该特定搜索键值的所有实际记录的指针。
![image.png](http://verification.fengzhongzhihan.top/202401141510264.png)

辅助索引 : 必须顺序+稠密
索引记录指向一个存储桶，该存储桶包含指向具有特定搜索键值的所有实际记录的指针。
![image.png](http://verification.fengzhongzhihan.top/202401141514972.png)

总结 : 索引搜索记录的时候非常好用, 但是更新索引会增加数据库修改的开销——当修改文件时，文件上的每个索引都必须更新
- 使用主索引进行顺序扫描是有效的
- 但是使用次索引进行顺序扫描是昂贵的

如果主索引不适合内存，访问就会变得昂贵。
解决方案: 将保存在磁盘上的主索引视为一个顺序文件，并在其上构造一个稀疏索引。
此时
- 外部索引-主索引的稀疏索引
- 内部索引-主索引文件
在从文件中插入或删除时，必须更新所有级别的索引。

![image.png|375](http://verification.fengzhongzhihan.top/202401141519586.png)

## 5.2 索引操作

单级索引条目删除：
- 密集索引 – 删除搜索键类似于删除文件记录。
- 稀疏索引 
	- 如果索引中存在搜索关键字的条目，则通过用文件中的下一个搜索关键字值替换索引中的条目。
		- 如果下一个搜索键值已经有索引条目，则该条目将被删除。
- 如果删除的记录是文件中具有特定搜索关键字值的唯一记录，则搜索关键字也会从索引中删除

单级索引插入：
- 使用要插入的记录中出现的搜索键值执行查找。
	- 密集索引 – 如果搜索键值未出现在索引中，则将其插入。
	- 稀疏索引 – 如果索引为文件的每个块存储一个条目，则不需要对索引进行任何更改，除非创建新块。
	- 如果创建了新块，则新块中出现的第一个搜索键值将插入到索引中。

我们可以为每个搜索键值创建一个带有索引记录的辅助索引
## 5.3 B+树索引
是顺序索引文件的替代方法

索引顺序文件坏处
- 随着文件的增长，性能会下降，因为会创建许多溢出块。
- 需要定期重组整个文件。

B+树索引文件的优点：
- 面对插入和删除，它会自动通过小的、局部的变化来重新组织自己。
- 不需要重新组织整个文件来维持性能。
- 额外的插入和删除开销，空间开销

总览
![image.png|500](http://verification.fengzhongzhihan.top/202401141529059.png)


特性:
- 从根到叶的长度相同(平衡树)
- 非根结点非叶结点
- 根不是叶子,至少有两个孩子

![image.png](http://verification.fengzhongzhihan.top/202310251426674.png)


B +-tree 的非叶级构成了稀疏索引的层次结构。
如果文件中有 K 个搜索键值，那么树的高度不会超过 log n/2(K) ，因此可以有效地进行搜索
对主文件的插入和删除可以得到有效的处理，因为索引可以在对数时间内重新构造(如我们将看到的)。
## 5.4 哈希索引
创建主码的时候会自动创建主码的索引,以便判断是否重复插入

在哈希文件组织中，我们使用哈希函数直接从记录的搜索键值获取记录的存储桶。
- 哈希函数h是从所有搜索关键字值K的集合到所有桶地址B的集合的函数。
- 存储桶是包含一条或多条记录的存储单元(磁盘块)。
- 哈希函数用于定位记录以进行访问、插入和删除。
- 必须顺序搜索整个存储桶才能找到记录。


**最差哈希函数**
将所有搜索键值映射到同一个存储桶； 这使得访问时间与文件中搜索关键字值的数量成正比。
**理想的哈希函数**
- 统一，从所有可能值的集合中为每个存储桶分配相同数量的搜索关键字值。
- 随机，因此无论文件中搜索关键字值的实际分布如何，每个存储桶都会分配相同数量的记录。

**典型的散列函数**对搜索关键字的内部二进制表示进行计算。
例如，对于字符串搜索键，可以将字符串中所有字符的二进制表示相加，并且可以返回对桶数进行模的总和。 

溢出桶
![image.png|375](http://verification.fengzhongzhihan.top/202311230946118.png)


散列不仅可以用于文件组织，还可以用于索引结构创建。
哈希索引将搜索键及其关联的记录指针组织到哈希文件结构中。
严格来说，哈希索引始终是二级索引
如果文件本身是使用散列进行组织的，则不需要使用相同的搜索键对其进行单独的主散列索引。
但是，我们使用术语“哈希索引”来指代二级索引结构和哈希组织文件。

在静态哈希中，函数 h 将搜索关键字值映射到一组固定的 B 桶地址。 数据库随着时间的推移而增长或缩小。
更好的解决方案：**允许动态修改桶的数量**。


在实践中：
PostgreSQL 支持哈希索引，但由于性能不佳而不鼓励使用
Oracle 支持静态哈希组织，但不支持哈希索引
SQLServer 仅支持 B+ 树

范围查询:
- B+树更方便
点查询:
- hash更方便

# 6 查询处理
![image.png|450](http://verification.fengzhongzhihan.top/202310251523604.png)

## 6.1 基本步骤
- 解析翻译
	- 解析器检查语法,校验关系
	- 将查询翻译成关系代数
- 代数和物理优化
	- 一个关系代数有很多等价的表达式,优化为最简单的
- 执行
	- 执行计划:带有详细执行策略标注的表达式
	- 选择查询执行计划,执行计划,返回查询结果
## 6.2 查询代价
总体度量:查询总时间
- 磁盘访问(主要代价)
	- 寻道次数- 寻道的时间tS
	- 读块个数-  传输块的时间tT
		- 若b块传输和s次寻道,则代价为$b*t_T+S*t_S$
	- 写块个数(忽略)
		- 写一个块比读一个块代价更大,因为会有回读,确保写的是成功的
- CPU
- 网络通讯

聚集操作是个大操作
- 每次都将所有数据放入内存

**算法**
- 逻辑算法:选择什么时候σ(基于规则)
- 物理算法;IO尽可能少(选择方法)

## 6.3 σ算法
预计算算法并且估算成本进行执行

br:块数量 
- 线性搜索(对小表很有用)(通用)
	- 思想:扫描所有文件块(顺序存放因此只要寻道一次)
	- 成本:br block transefers +1 seek(寻道)
	- 若选择的是码属性(唯一不重复),找到就可以停止搜索 
	- 可以不用考虑的
		- 选择条件
		- 文件组织形式
- 索引搜索(tt:块传输时间  ts:寻道时间)
	- 主索引且为码
		- 成本$$(hi+1)*(t_t+t_s)$$
	- 主索引且不为码
		- 唯一区别:可能有多项重复的数据(令 b = 包含匹配记录的块的个数)
		- 成本$$(hi+1)*t_s +(hi+b)t_t$$
	- 辅助索引(稠密索引)
		- 数据块上有多个块,查找多个块,且块之间未必连续
		- 若搜索码是候选码，检索单个记录
		$(hi+1)*(t_t+t_s)$
		- 搜索吗不是候选码成本可能很大$$(h_i+n)*(t_t+t_s)$$
- 若搜寻不等条件
	- 主索引可以连续扫块,辅助索引只能挨个扫记录
- 条件且
	- 找到选择性最好的条件,先放入内存再进行筛选
	- 如何估计呢?
		- 一个索引,基数估计
		- 复合索引:直接找块
- 条件或
	- 可以求指针的并
- 条件否
	- 可以寻求逆来进行

## 6.4 归并排序
排序一般是大操作,需要搜索所有的元素

排序方法
- 对于内存而言,使用quick_sort
- 对于外存而言,使用 external sort-merge

**外排序归并步骤**
令M为内存大小

1. 创建排好序的 归并段.  令 i 初值为 0 
 反复下列步骤直到关系末尾:$N*M=总块数$
     (a)  读关系的 M 个块到内存
     (b)  对内存块进行排序
     (c)  把排好序的数据写到 Ri 段 (N的一段)i++

令写出的段数为N,1块用于存储输出,把每个段的第一块读入缓冲区
2. 归并段(N-路归并)(N<M)
- 选择所有缓冲区页中的第一条记录（按排序顺序）
- 将记录写入输出缓冲区。 如果输出缓冲区已满，则将其写入磁盘。
- 从其输入缓冲区页中删除该记录。 如果缓冲区页变空，则将运行的下一个块（如果有）读入缓冲区。
- 直到所有输入缓冲区页面为空：
3. N>M,需要若干趟归并(细分)
	在每一个趟, 归并 M - 1 段. 
	每一个趟，减少 M -1 规模的段, 并且创建同样倍增长度的段
	例如.  如果 M=11, 并且有90个段, 则每趟减少9个段,产生原段的10倍长度的新段
	重复多趟，直到所有的段归并为一个

先将内存分成不同的段,进行排序,再进行归并
![image.png|325](http://verification.fengzhongzhihan.top/202310271156569.png)
先排序再做连接,σ比较方便
- 可能最后会有一个Order_by

**代价分析**
在合并过程中，每次运行1个块会导致过多的搜索
- 相反，每次运行使用 bb 缓冲区块
- 外排序的块传输总数是: br (2 log ([M/bb]-1)(br/M) + 1)
- 寻道次数2br/M + br/bb (2log M/bb-1(br/M) -1)


## 6.5 连接运算

几种不同的算法来实现连接
- 嵌套循环连接
- 基于块的嵌套循环连接
- 索引嵌套循环连接
- 归并连接
- 散列连接

**嵌套循环连接**
![image.png](http://verification.fengzhongzhihan.top/202311011547025.png)
- 两层for循环
- r称为外关系,s称为内关系
- 适用于没有索引
- 代价昂贵

(n代表记录个数,b代表块的个数)
- 最坏情况下, 如果内存只能够存储每个关系的一块，估计代价是 
nr bs + br   块传输,(对于每个外关系的元组,都需要遍历一遍内关系的块)
nr + br          寻道
- 如果小一些的关系能够完全适合内存, 应作为内关系.
 减少成本到 br  + bs 块传输,2 次寻道


以下列信息作为示例
记录个数：   student:  5,000     takes: 10,000
块的个数：   student:     100     takes:      400

最坏情况下的代价是：
student 作为外关系:
5000 * 400 + 100 = 2,000,100 block transfers,
5000 + 100 = 5100 seeks 
 takes  作为外关系 
10000 * 100 + 400 = 1,000,400 block transfers and 10,400 seeks

如果更小的关系 (student) 完全放入内存, 代价估计是 500 块传输.

**基于块的嵌套循环算法**
(将nr换成了br)
最坏情况估计:  br * bs + br  块传输
2 * br  寻道

最好情况（内存可容内层关系）: br + bs 块传输 + 2 寻道

对嵌套循环和基于块的嵌套循环的改进方法
在基于块嵌套循环中, 使用 M — 2 磁盘块作为外层关系的块, 其中 M = 内存块数; 剩余2个块作为内层关系和输出的缓冲

**索引嵌套循环连接**

索引查找可替换文件扫描，当
- 连接是等值或自然连接
- 内层关系连接属性上有可用索引

外层关系 r 的每个元组 tr 使用索引查找 s 中的满足连接条件的元组 ts
最坏情况:  缓冲区只有 r 的一页空间，对于r 里的每个元组，执行一次s 上的索引查找.
连接代价:  br 块传输  , br 寻道  nr* c
- c是遍历索引并为r的一个元组获取所有匹配的s元组的成本

如果r 和 s连接属性上的索引都可用，使用元组数少的关系作为外层关系

![image.png](http://verification.fengzhongzhihan.top/202311231602053.png)
## 6.6 表达式执行
评估整个表达式树的替代方案
**（物化）**
- 生成输入为关系或已计算的表达式的结果，将其物化（存储）在磁盘上。 重复。
- 物化执行（Materializedvaluation）：从最低级别开始，一次评估一个操作。 使用具体化为临时关系的中间结果来评估下一级操作。

![image.png](http://verification.fengzhongzhihan.top/202311231608055.png)

总成本 = 各个操作的成本之和 + 将中间结果写入磁盘的成本
双缓冲：每个操作使用两个输出缓冲区，当一个已满时将其写入磁盘，而另一个已满,允许磁盘写入与计算重叠并减少执行时间
**（流水线）**

即使正在执行操作，也将元组传递给父操作

同时评估多个操作，将一个操作的结果传递给下一个操作。
将元组直接传递给连接。不存储连接结果，将元组直接传递给投影
因此比物化便宜得多：不需要存储与磁盘的临时关系。

流水线可能并不总是可行的——例如排序、散列连接。

为了使流水线有效，请使用评估算法来生成输出元组，即使接收到操作输入的元组也是如此。
Pipelines可以通过两种方式执行
- 需求驱动
- 生产者驱动

**需求驱动**
- 系统重复地从顶层操作请求下一个元组
- 每个操作根据需要从子操作请求下一个元组，以便输出其下一个元组
- 在调用之间，操作必须保持“状态”，以便知道接下来要返回什么

**生产者驱动**
运算符急切地生成元组并将其传递给父级
- 运算符之间维护的缓冲区，子级将元组放入缓冲区，父级从缓冲区中删除元组
- 如果缓冲区已满，子进程会等待缓冲区有空间，然后生成更多元组
系统调度在输出缓冲区中有空间并且可以处理更多输入元组的操作

替代名称：流水线的拉推模型

# 7 查询优化

查询的评估计划之间的成本差异可能很大

基于成本的查询优化的步骤
1. 使用等价规则生成逻辑上等价的表达式
2. 注释结果表达式以获得替代查询计划
3. 根据估计成本选择最便宜的计划

计划成本估算基于：
- 有关关系的统计信息
	- 元组的数量，属性的不同值的数量
- 中间结果统计估计
	- 计算复杂表达式的成本
- 使用统计计算的算法成本公式


## 7.1 **等效表达式**
如果两个关系代数表达式在每个合法数据库实例上生成相同的元组集，则称这两个表达式是等价的
- 注意：元组的顺序无关紧要

![image.png](http://verification.fengzhongzhihan.top/202311231621183.png)
![image.png](http://verification.fengzhongzhihan.top/202311231621471.png)
![image.png](http://verification.fengzhongzhihan.top/202311231623796.png)
![image.png](http://verification.fengzhongzhihan.top/202311231623429.png)
![image.png](http://verification.fengzhongzhihan.top/202311231623264.png)


尽早执行选择可以减少要连接的关系的大小。
**例题**
![image.png](http://verification.fengzhongzhihan.top/202311231639660.png)
![image.png](http://verification.fengzhongzhihan.top/202311231639316.png)


尽早执行投影可以减小规模
![image.png](http://verification.fengzhongzhihan.top/202311231641508.png)

计算和存储一个更小的关系
![image.png](http://verification.fengzhongzhihan.top/202311231643826.png)


## 7.2 代价的数字信息

nr：r 中的元组数量
br：r 的块数
lr：r中元组单位大小。
fr：r中块包含元组数目
V(A, r)：ΠA(r)的大小。

如果 r 的元组物理上存储在一个文件中，则br=(nr/fr)向上取整
![image.png](http://verification.fengzhongzhihan.top/202311231652739.png)


## 7.3 选择评估计划
选择评估计划时必须考虑评估技术的相互作用
独立地为每个操作选择最便宜的算法可能不会产生最佳的整体算法
- 合并连接可能比散列连接成本更高，但可以提供排序的输出，从而降低外层聚合的成本。
- 嵌套循环连接可能为流水线提供机会

实用的查询优化器包含以下两种主要方法的元素：
1. 搜索所有方案并根据成本选择最佳方案。
2. 使用启发式方法选择计划。

即使使用动态规划，基于成本的优化也是昂贵的。
系统可以使用启发式方法来减少必须以基于成本的方式做出的选择数量。
启发式优化通过使用一组通常（但并非在所有情况下）提高执行性能的规则来转换查询树：
- 尽早执行选择（减少元组数量）
- 尽早执行投影（减少属性数量）
- 在其他类似操作之前执行最严格的选择和连接操作（即具有最小的结果大小）。
- 一些系统仅使用启发式方法，其他系统则将启发式方法与部分基于成本的优化相结合。

## 7.4 冗余操作
设交集： v = r ∩ s
- 当一个元组插入到 r 中时，我们检查它是否存在于 s 中，如果存在，我们将其添加到 v 中。
- 如果从 r 中删除该元组，则我们将其从交集中删除（如果存在）。
- s 的更新是对称的
- 其他集合运算、并集和集合差都以类似的方式处理。


例子
Q1：select * from (r 自然连接 t) 自然连接 s
Q2: select * from (r 自然连接 u) 自然连接 s
两个查询共享公共子表达式（r 自然连接 s）
计算 (r 自然连接 s) 一次并在两个查询中使用它可能很有用
- 但在某些情况下这可能会更昂贵
- 例如 (r 自然连接 s) 可能很昂贵，查询中所示的计划可能更便宜

多查询优化：找到一组查询的最佳总体计划，利用查询之间有用的公共子表达式的共享
# 8 事务管理
## 8.1 事务概念
事务是访问并可能更新各种数据项的程序执行单元。
需要解决一些问题
- 各种故障，例如硬件故障和系统崩溃
- 多个事务并发执行

为了保证DBMS的完整性,需要保证
**ACID概念理解**
将 50 美元从账户 A 转入账户 B 的交易：
**原子性**
如果在步骤3之后和步骤6之前交易失败，资金将“丢失”，导致数据库状态不一致
系统应确保**部分执行**的事务的更新不会反映在数据库中,事务的所有操作要么都正确反映在数据库中，要么没有
**持久性**
一旦事务完成,即使出现软件或硬件故障，交易对数据库的更新也必须持续存在。
**隔离性**
尽管多个事务可以并发执行，但每个事务必须不知道其他并发执行的事务。 中间事务结果必须对其他并发执行的事务隐藏。
也就是说，对于每对事务 Ti 和 Tj，Ti 看起来要么 Tj 在 Ti 开始之前完成执行，要么 Tj 在 Ti 完成之后开始执行
**一致性**。 隔离执行事务可以保持数据库的一致性。

事务的四种状态
Active – 执行时
Partially committed – 执行完最后一句话
Failed -- 发现无法继续执行
Aborted – 事务终止并且已经回滚到之前的状态
Committed – 完成后

![image.png](http://verification.fengzhongzhihan.top/202401142230865.png)


中止后两个选择
- restart the transaction
 can be done only if no internal logical error
- kill the transaction

系统中允许多个事务同时运行。目的:
提高处理器和磁盘利用率，从而提高事务吞吐量
例如
- 一个事务可以使用 CPU，而另一个事务可以从磁盘读取或写入磁盘
- 短事务不需要在长事务后面等待。
并发控制方案——实现隔离的机制
-  即控制并发事务之间的交互，防止它们破坏数据库的一致性


## 8.2 可串行化
并发执行可能产生的数据不一致性
![image.png](http://verification.fengzhongzhihan.top/202401142232315.png)
![image.png](http://verification.fengzhongzhihan.top/202401142233227.png)
![image.png](http://verification.fengzhongzhihan.top/202401142233166.png)


Schedule – 指定并发事务指令执行时间顺序的指令调度
- 成功完成执行的事务将有一个提交指令作为最后一条语句
- 未能成功完成执行的事务将有一条中止指令作为最后一条语句

基本假设 – 每个事务都保持数据库一致性。
因此，一组事务的串行执行可以保持数据库的一致性。

**可串行化调度**
多个事务并发执行结果与这组事务的某一个串行调度执行结果相同
- 可串行化是并发执行正确性的判定标准

不同形式的时间表等效性
1.冲突可串行化
2.视图可串行化

**冲突可串行化**
当且仅当存在 li 和 lj 都访问的某些项 Q，一旦一个有写的操作, 则指令冲突
- 除了read read不冲突之外,其余均冲突
- 非冲突操作交换不影响结果
- 冲突操作不能交换
直观上，li 和 lj 之间的冲突迫使它们之间存在（逻辑）时间顺序。

如果调度 S 可以通过一系列非冲突指令的交换转换为调度 S´，我们说 S 和 S´ 是**冲突等价**的。

如果调度 S 与串行调度冲突等价，则我们说调度 S 是**冲突可串行化**的
![image.png](http://verification.fengzhongzhihan.top/202401142243684.png)

**视图可串行化**
令 S 和 S´ 是具有相同事务集两个调度。对于每个数据项 Q,如果均满足条件，则 S 和 S´ 是等效的：
- 如果在调度 S 中，事务 Ti 读取 Q 的初始值，那么在调度 S’中，事务 Ti 也必须读取 Q 的初始值。
	- 初始读相等
- 如果在调度 S 中，事务 Ti 执行 read(Q)，并且该值是由事务 Tj（如果有）生成的，那么在调度 S' 中，事务 Ti 也必须读取由同一 write(Q) 操作生成的 Q 的值 交易 Tj 。
	- 写后读取的值相同
- 在调度 S 中执行最终写入 (Q) 操作的事务（如果有）也必须在调度 S’中执行最终写入 (Q) 操作。
	- 最后write相同
可以看出，视图等效性**纯粹基于读取和写入**。

每个冲突可序列化计划也是视图可序列化的。
- 但反之不能推
- 这是一个视图可串行化,但不是冲突可序列化
![image.png|375](http://verification.fengzhongzhihan.top/202311171149621.png)

每个不可冲突序列化的视图可序列化计划都具有盲写。

**特例**
有一些不是冲突和视图但结果相同
![image.png|293](http://verification.fengzhongzhihan.top/202311171152508.png)
此时不是纯粹看读和写

**优先图**
![image.png|500](http://verification.fengzhongzhihan.top/202311171153350.png)
Ti->Tj,Ti表示访问较早的数据项
当且仅当其优先级图是无环的时，调度才是冲突可序列化的。
如果优先图是无环的，则可以通过图的拓扑排序来获得可串行化顺序。
  这是与图的偏序一致的线性顺序。

注意 特殊情况需要考虑
![image.png](http://verification.fengzhongzhihan.top/202401142316721.png)

## 8.3 可恢复调度
可恢复的调度——如果事务 Tj 读取了事务 Ti 先前写入的数据项，则 Ti 的提交操作将出现在 Tj 的提交操作之前。
![image.png](http://verification.fengzhongzhihan.top/202401151015540.png)

如果 T9 在读取后立即提交，则以下调度不可恢复
![image.png](http://verification.fengzhongzhihan.top/202311231724080.png)

需要解决事务失败对并发运行的事务的影响。
如果 T8 中止，T9 将读取（并可能向用户显示）不一致的数据库状态。 因此，数据库必须确保调度是可恢复的。

**级联回滚**
单个事务失败会导致一系列事务回滚。
考虑以下调度，其中尚未提交任何事务（因此该调度是可恢复的）。如果 T10 失败，T11 和 T12 也必须回滚。可能导致大量工作白费
![image.png](http://verification.fengzhongzhihan.top/202311231725837.png)


**无级联调度**
- 读数据之前必须等待提交完, 不读脏数据
- 每个无级联调度也是可恢复的
- 最好将调度限制为无级联的调度
![image.png](http://verification.fengzhongzhihan.top/202401151016529.png)

目标 – 开发确保可串行性的并发控制协议。

并发控制
- 为了数据库一致性，调度必须是冲突的或视图可序列化和可恢复的，并且最好是无级联的。
- 一次只能执行一个事务的策略会生成串行调度，但并发性较差。
- 并发控制方案在允许的并发量和产生的开销之间进行权衡。
- 某些方案仅允许生成冲突可串行化调度，而其他方案允许查看视图可串行化调度

较低的一致性程度对于收集有关数据库的近似信息很有用

数据操作语言必须包含用于指定构成事务的一组操作的构造。
- 在 SQL 中，事务是隐式开始的。
- SQL 中的事务以以下方式结束：
	- 提交工作提交当前事务并开始一个新事务。
	- 回滚工作会导致当前事务中止。

在几乎所有数据库系统中，默认情况下，每个 SQL 语句如果执行成功也会隐式提交
隐式提交可以通过数据库指令关闭
# 9 并发控制
为了保证事务的隔离性, 系统必须对并发事务之间的相互作用加以控制, 这种机制称为并发控制机制
分类
- 基于锁的协议
- 基于时间戳的协议
- 基于验证的协议
- 多粒度
- 多版本方案
- 插入和删除操作
- 索引结构中的并发性

## 9.1 锁
### 9.1.1 锁概述

锁是一种控制对数据项的并发访问的机制, 指事务T在操作某个对象之前, 向并发控制管理器提出加锁请求
- 加锁成功再操作
- 加锁失败进行等待

数据项可以通过两种模式锁定：
     1.排他锁（X） 数据项可以w,r。 使用lock-X指令请求X锁。
     - 别的事务不能加x和r锁
     2.共享锁（S） 数据项只能r。 S锁是使用lock-S指令请求。
	- 别的事务可以继续加上r锁, 但不能加x锁
向并发控制管理器发出锁定请求。 


锁兼容性矩阵
- 若Q上有B锁, 此时可以立即获得Q锁, 则是相容的
![image.png](http://verification.fengzhongzhihan.top/202311151444294.png)

如果兼容，则可以授予该事务对该项目的锁
- 任意数量的事务都可以持有一个项目的共享锁
如果任何事务持有该项目的排他性,不能授予锁
- 如果无法授予锁，则请求事务将等待，直到释放其他事务持有的所有不兼容的锁。 然后授予锁定。

**死锁**
![image.png|222](http://verification.fengzhongzhihan.top/202311151447841.png)

T3 和 T4 都无法取得进展 - 
执行 lock-S(B) 会导致 T4 等待 T3 释放其对 B 的锁定，
而执行 lock-X(A) 会导致 T3 等待 T4 释放其对 A 的锁定。
- 要处理死锁，必须回滚 T3 或 T4 之一并释放其锁。

### 9.1.2 锁协议
事务饿死 : 永远不能取得进展
- 避免饿死 : 申请加锁的时候不存在冲突锁的事务且不存在等待加锁先于其加锁的事务

**两段锁协议是一个确保并行事务可串行性的协议。**

**每个事务分两个阶段提出加锁/ 解锁申请**
第一阶段：成长阶段
- 事务可以获得锁, 不能释放锁
第二阶段：收缩阶段
- 事务可以释放锁, 不能获得锁
- 此时释放指令不必出现在事务末尾

事务可以按照事务封锁点（即事务获得最终锁的点）进行排序, 
则这个顺序就是一个事务的可串行化序列
- 事务遵循两段锁协议是可串行化调度的充分条件, 不是必要条件

**两阶段锁定并不能确保避免死锁**
![image.png|425](http://verification.fengzhongzhihan.top/202401151123843.png)


**因一个事务故障导致一系列事务回滚的现象称为级联回滚**
- 在两阶段锁定下可以进行级联回滚(均回滚)。 为了避免这种情况，遵循严格两阶段锁定
![image.png](http://verification.fengzhongzhihan.top/202401151127709.png)

**严格的两阶段锁定**
- 要求事务持有的所有排他锁必须在事务结束之后才可以释放
- 可以避免级联回滚

**强两阶段封锁协议**
- 事务提交之前不能释放任何锁
	- 其他有冲突请求的事务只能等待
- 此时事务可以按照提交的顺序串行化


**带锁转换的两阶段锁定
-  第一阶段：
	可以获得物品上的锁-S
	可以获得物品上的锁-X
	可以将lock-S转换为lock-X（升级）
- 第二阶段：
	可以释放锁-S
	可以释放锁-X
	可以将 lock-X 转换为 lock-S（降级）
该协议确保可串行化。 但仍然依赖程序员插入各种锁定指令。

无需显式锁定调用
read(D) is processed as:
if Ti has a lock on D
 then
		read(D) 
 else begin 
		   if necessary wait until no other  
			   transaction has a lock-X on D
		   grant Ti a  lock-S on D;
		   read(D)
		end

write(D) is processed as:
if Ti has a  lock-X on D 
then 
  write(D)
else begin
	if necessary wait until no other trans. has any lock on D,
	if Ti has a lock-S on D
		 then
			upgrade lock on D  to lock-X
		else
			grant Ti a lock-X on D
		write(D)
 end;
All locks are released after commit or abort

**锁管理器**
锁管理器可以实现为一个单独的进程，事务向该进程发送锁定和解锁请求.

锁管理器通过发送锁授予消息（或在发生死锁时要求事务回滚的消息）来回复锁请求
请求事务等待其请求得到答复

锁管理器维护一个称为锁表的数据结构，用于记录授予的锁和待处理的请求
- 锁表通常实现为内存中的哈希表，该哈希表以被锁定的数据项的名称为索引

![image.png|400](http://verification.fengzhongzhihan.top/202311151548456.png)
![image.png](http://verification.fengzhongzhihan.top/202401151137831.png)

## 9.2 时间戳
解决事务可串行化的另一个策略 : 时间戳排序
每一个事务Ti, 将唯一的时间戳与他联系, 记为TS(Ti)
实现时间戳的两个简单方法
- 系统时钟
- 逻辑计数器


每个事务在进入系统时都会发出一个时间戳。
如果旧事务Ti具有时间戳TS(Ti)，则新事务Tj被分配时间戳TS(Tj)，使得TS(Ti)<TS(Tj)。
该协议管理并发执行，以便时间戳确定可串行化顺序。
为了确保这种行为，协议为每个数据 Q 维护两个时间戳值：

W-timestamp(Q) 是成功执行 write(Q) 的任何事务的最大时间戳。
R-timestamp(Q) 是成功执行 read(Q) 的任何事务的最大时间戳。
- 每当有新的read()和write()指令执行的时候, 这些时间戳就更新
![image.png](http://verification.fengzhongzhihan.top/202401151150031.png)
![image.png](http://verification.fengzhongzhihan.top/202401151152638.png)

如果回滚, 则重新启动时间戳

保证 : 冲突可串行化, 无死锁 ...
缺点 : 可能导致长事务反复回滚重启, 可能产生不可恢复的调度
## 9.3 多粒度
允许数据项具有各种大小并定义数据粒度的层次结构，其中小粒度嵌套在较大粒度中
- 树的每个结点可以单独加锁
- 当事务显式锁定树中的一个节点时，它会以相同的模式隐式锁定该节点的所有后代。

锁定的粒度（完成锁定的树中的级别）：
- 细粒度（树中较低）：高并发、高锁定开销
- 粗粒度（树中较高）：锁定开销低，并发性低

## 9.4 有效性检查
要求每个事务Ti在生命周期中按两个/三个阶段执行, 取决于事务是一个只读事务还是一个更新事务
## 9.5 多版本

解决读需要等待的问题
- 写新版本读老版本
- 每次成功写入都会创建所写入数据项的新版本。

多版本方案保留旧版本的数据项以提高并发性。
- 多版本时间戳排序
- 多版本两相锁定

使用时间戳来标记版本。
- 当发出 read(Q) 操作时，根据事务的时间戳选择合适的 Q 版本，并返回所选版本的值。
- 读取永远不必等待，因为会立即返回适当的版本。

每个数据项Q具有版本序列<Q1，Q2，....，Qm>。 每个版本Qk包含三个数据字段：
- 版本Qk的值。
- W-timestamp(Qk) -- 创建（写入）版本 Qk 的事务的时间戳
- R-timestamp(Qk) -- 成功读取版本Qk的事务的最大时间戳

当事务Ti创建Q的新版本Qk时，Qk的W时间戳和R时间戳被初始化为TS(Ti)。
每当事务 Tj 读取 Qk 时，Qk 的 R 时间戳就会更新，并且 TS(Tj) > R 时间戳(Qk)。

# 10 恢复系统
分类
- 故障分类
- 存储结构
- 恢复和原子性
- 基于日志的恢复
- 远程备份系统

高可靠,高安全,高性能
## 10.1 故障分类

事务失败：
- 逻辑错误：由于某些内部错误情况，事务无法完成
- 系统错误：由于错误情况（例如死锁），数据库系统必须终止活动事务

系统崩溃：电源故障或其他硬件或软件故障导致系统崩溃。
- 故障停止假设：假设非易失性存储内容不会因系统崩溃而损坏
- 数据库系统有大量的完整性检查来防止磁盘数据损坏

磁盘故障：磁头崩溃或类似的磁盘故障会破坏全部或部分磁盘存储
- 假设破坏是可检测的：磁盘驱动器使用校验和来检测故障

日志只要记录写的动作
- 无需记录读的操作

## 10.2 磁盘, 内存和缓冲区

**物理块**磁盘块。
**缓冲区**是暂存于主存储器中的块。
磁盘和主存之间的块移动是通过以下两个操作启动的
- input(B) 将物理块 B 传输到缓冲区
	- read:将缓冲区传输到内存
- output(B）将缓冲区块B写回磁盘，并替换那里一开始读的物理块。
	- write:内存写到缓冲区

![image.png|400](http://verification.fengzhongzhihan.top/202311151523537.png)

每个事务 Ti 都有其私有工作区
- 注意：write(X) 可以在事务提交之前的任何时间执行,output(BX) 不需要紧跟在 write(X) 之后。 系统可以在认为合适的时候执行输出操作。
	- 因为BX中可能包含其他正在访问的数据项
- 第一次访问X之前必须执行read(X)（后续读取可以来自本地副本）

原子性和恢复性
- 原子性 : 要么执行所有, 要么不执行
- 保证 : 修改数据库之前先向稳定存储器中输出信息, 描述要做的修改

系统故障,内存清空
- 违背了A特性: 未提交事务发生了对磁盘的修改.
	- 撤销
- 违背了D特性: 已提交事务没有完成对磁盘的修改
	- 重做一遍

## 10.3 日志恢复
### 10.3.1 日志概述
日志保存在稳定的存储中,是一系列日志记录，并维护数据库上更新活动的记录

更新日志记录 : (描述一次数据库写的操作)
- 事务标识 : Ti
- 数据项标识 : Xj
- 旧值 : V1
- 新值 : V2

其他日志记录 : (用于记录事务处理过程中的重要事件)
- <T1 start (commit)(abort)>

当事务Ti开始时，它通过写入日志记录来注册自己
Ti执行write(X)之前会写入一条日志记录<Ti, X, V1, V2>，其中V1旧值，V2是 新值。
当 Ti 完成最后一条语句时，将写入日志记录 $<Ticommit>$。
- 必须先添加日志记录再操作数据库

### 10.3.2 redo和undo恢复
修改数据步骤
1. 先在私有工作区计算
2. 修改主存的磁盘缓冲中的数据块
3. 执行output操作, 将数据库写到磁盘中

恢复算法
- 事务已提交, 数据库修改还没有写入到磁盘中
- 已修改数据库, 但是事务中止
- 解决方法 : 对更新的数据项获取排他锁, 持有直至事务提交/中止

数据库修改
- 延迟数据库修改 : 事务提交的时候没有修改数据库, 事务创建更新数据项的本地拷贝
- 立即数据库修改 : 修改数据库在事务仍然活跃的时候发生

先写日志再写buffer
- 防止内存炸裂

恢复系统 
- redo, 通过日志扫描来保证更新顺序
- undo,保证原子性	- 反向扫描日志来回滚, 保证undo顺序
	- 恢复旧值后, 写redo-only日志来记录更新
	- 对T1的undo操作完成, 写"T1 abort"日志记录, 确保日志中事务要么是commit要么是abort
- 系统崩溃后, 查阅日志确定恢复类型
	- 如果有start无commit和abort则 undo
	- 有start有commit/abort, 则redo
		- 有abort记录的redo: 则undo

![image.png](http://verification.fengzhongzhihan.top/202401151507511.png)

下面我们显示了在三个时间点出现的日志。
![image.png|525](http://verification.fengzhongzhihan.top/202311171020191.png)

上述每种情况下的恢复操作是：
(a)undo(T0)：B恢复为2000，A恢复为1000，并写出日志记录<T0,B,2000>,<T0,A,1000>,<T0,abort>
(b)redo(T0)和undo(T1)：A和B设置为950和2050，C恢复为700。日志记录<T1，C，700>，<T1，abort>被写出。
(c)redo(T0)和redo(T1)：A和B分别设置为950和2050,然后C设置为600
- 没提交用Undo,已提交用redo
### 10.3.3 检查点机制
**优化**
redo:数量很大,不太能接受,需要优化
- 解决方法 : 对日志缓冲区进行刷盘
- 刷盘的过程中,将所有buffer的都输入到disk中(check points)
undo:数量比较少,可以接受

![image.png](http://verification.fengzhongzhihan.top/202311231741022.png)


检查点执行过程 :
-  先将主存的日志 -> 磁盘, 再将修改的buffer -> 磁盘, 
- 将日志记录 "check point L"->磁盘
- 进行检查点时所有更新都会停止
- 则崩溃的时候只需要找到最后一条check point L记录, 对L中事务和之后的记录进行Undo和redo

在恢复期间，我们只需要考虑在检查点之前开始的最近事务 Ti 以及在 Ti 之后开始的事务。

从日志末尾向后扫描以查找最新的checkpoint L 记录
- 只有在L中或在检查点之后开始的事务才需要redo/undo

⚠️upload failed, check dev console

对于日志本身而言
- 日志缓冲区需要在特定情况下刷盘
	- 提交事务
	- 将页面放入磁盘

总结 : 
并发控制保证了事务的隔离性和一致性
- 基于锁的协议
- 基于时间戳的协议
恢复系统保证了事务的原子性和持久性
- 稳定存储器实现
- 基于日志的恢复算法

# 11 ER图
## 11.1 系统开发
数据库系统开发生命周期
- 数据库规划
	- 任务陈述、任务目标
- 系统定义
	- 系统边界、用户视图
- 需求的收集与分析
	- 用户需求：数据需求、事务需求
	- 系统需求
数据库设计、DBMS选型、应用程序设计
实现、构建原型(可选)
数据转换与加载
测试
操作性维护

![image.png|206](http://verification.fengzhongzhihan.top/202311241041353.png)

## 11.2 ER图
要素集合
![image.png|400](http://verification.fengzhongzhihan.top/202312011047582.png)
![image.png|400](http://verification.fengzhongzhihan.top/202312011048251.png)


一般是二元联系, 也有三元联系
![image.png|350](http://verification.fengzhongzhihan.top/202311241055764.png)

![image.png|475](http://verification.fengzhongzhihan.top/202401151532794.png)

**三要素:**
- 实体
	- **实体**是存在的并且可以区别于其他对象的对象。
	- **实体集**是具有相同属性的相同类型的实体的集合。
- 属性
	- 属性也可以是关系集的属性。
	- 实体型=实体名+属性名(关系模式)![image.png](http://verification.fengzhongzhihan.top/202311241046309.png)如可能有日期属性
	- 属性分类 : 简单属性/ 复杂属性(可以划分为更小的属性)
		- 或者单值/ 多值属性: 取值唯一或者可以多于1, 派生属性 : 由别的属性推得
			- 多值属性用双椭圆表示
			- 派生属性用虚椭圆表示
		- ![image.png|287](http://verification.fengzhongzhihan.top/202401151540501.png)

	- ![image.png|142](http://verification.fengzhongzhihan.top/202311241048816.png)

- 联系 : 多个实体间的相互关联
	- 联系集之间的关联称为参与, 实体集E参与联系集R
	- 联系集的组成: 实体集主码 + 联系的属性
	- 联系集超码 :key1 + key2 + key3.. 
	- 主码
		- 若多对多 : 超码
		- 一对多或者多对一 : 多方的实体集的主码构成
			- 如学生<->老师 , 则由学生
		- 一对一 :任意一个都行

**域** : 属性的取值范围


**三约束**
- 映射基数约束
	- 映射基数 : 表示可以通过关系集关联另一个实体的实体数量。
		对于二元关系集，映射基数必须是以下类型之一：
		一对一(至多一个),一对多,多对一,多对多
		注意 : 一对一不是一一对应
	- 表示方法 : 一对一 <-> 一对多 <-  多对一 -> 多对多 -
	- 同一实体集也有着联系和约束
	- ![image.png|188](http://verification.fengzhongzhihan.top/202401151546635.png)

- 码约束 : 用下划线表示
- 参与约束
	- 全参与（用双线表示）：实体集中的每个实体至少参与关系集中的一个关系
		示例：学生对顾问的参与是全部
	- 部分参与：某些实体可能不参与关系集中的任何关系
		示例：导师对顾问的参与是部分的

关系和实体可以进行合并
- 尽量合并参与的多的 部分

**角色（Role）**
实体在联系中的作用称为实体的角色
当同一个实体集不止一次参与一个联系集时，为区别各实体的参与联系的方式，需要显式指明其角色
如：学生与学生间的班长关系；职工与职工之间的经理关系；课程之间的先修关系。
- 在连线上注明角色
![image.png|450](http://verification.fengzhongzhihan.top/202311241030056.png)
多值属性用大括号来表示(出现多次)

**基数限制也可以表示参与约束**

左边的数代表最小映射基数, 右边代表最大映射基数
instructor: 对应(0.. * )学生
student: 对应(1.. 1)老师
- 若两边最大值都是1, 则联系一对一
![image.png](http://verification.fengzhongzhihan.top/202311241036459.png)
## 11.3 弱实体集

存在依赖
- 如果实体集x存在依赖于y存在, 则x存在依赖于y
若A存在依赖于B, 则A全部参与联系R

思想: 属性实体化
- 属性实体化之后,实体无法独立表示
- 行号,日期都只能在一个账户内分辨多值属性,缺少全局标识

弱实体集提出的背景:存在一些场景，需要表达：
- 一个实体的属性与其它实体之间的关系
- 或者属性之间相互的关联关系

在表达属性参与的联系时，需要进行属性实体化
- 某些属性实体化之后，实体可以独立标识，如电话；
- 某些属性实体化之后，实体自身无标识属性，如账户交易

属性实体化后，**若不能独立标识，形成弱实体**
 
弱实体定义
- 没有足够属性标识以形成主码的实体，称为弱实体
- 反之称为强实体 :有主码的实体集
- 弱实体需要依赖属主实体而存在，不能独立存在
![image.png|475](http://verification.fengzhongzhihan.top/202311241058674.png)

**属主实体/标识性实体**：弱实体依赖于属主实体存在
**标识性联系**：多对一、全部参与
**分辨符**：弱实体集自身的属性(需要加虚线下划线)
**弱实体的主键**：属主实体标识(主码)+分辨符

![image.png|500](http://verification.fengzhongzhihan.top/202311241103683.png)

实体集与关系集的使用 可能的准则是指定一个关系集来描述实体之间发生的操作
![image.png|375](http://verification.fengzhongzhihan.top/202311241141433.png)

使用弱实体集的意义
- 避免数据冗余, 带来数据不一致性
- 反映了一个实体对其他实体依赖的逻辑结构
- 可以随着强实体集删除而删除, 存储而存储

什么时候使用
- 一些多值, 复合属性可以抽取出来
- 弱实体集还参与其他实体集的联系,或者本身属性很多
- 弱实体集之间用普通的菱形表示

## 11.4 转换为关系模式

实体集 -> 关系

属性 -> 关系的属性

复合属性 -> 拆分为组合属性

多值属性 -> 新关系 + 实体集码 + 建立外码约束
![image.png](http://verification.fengzhongzhihan.top/202401151608468.png)
- 若只有两个属性, 可以把多值属性拆分

弱实体集 -> 新关系 + 外码约束

普通联系集 -> 找外码 + 新关系

连接弱实体集和强实体集的联系集 -> 新关系 (和弱实体集一样)

模式的合并 (一方完全参与) -> 将完全参与一方的实体集和联系集进行合并
![image.png](http://verification.fengzhongzhihan.top/202401151616817.png)

## 11.5 ISA和聚合

ISA联系：某些实体型是某个实体型的子类型。这种父类-子类联系称为ISA联系。
为了表示聚合和实体之间的关系，创建一个包含以下内容的模式：
- 聚合关系的主键，关联实体集的主键,任何描述性属性

例如，要表示关系 proj_guide 和实体集evaluation之间的聚合 eval_for
eval_for(s_id,prj_id,i_id,evalutaion_id)
- 只要我们愿意存储与模式 eval_for 相关的属性 evaluation_id 的空值,模式 proj_guide 是多余的，
![image.png|300](http://verification.fengzhongzhihan.top/202312011044693.png)

### 11.5.1 专业化方法
**方法一：**
形成更高级别实体的模式
为每个下层实体集形成一个模式，包括上层实体集的主键和本地属性
缺点：获取有关员工的信息需要访问两种关系，一种对应于低级模式，另一种对应于高级模式
- 缺点：浪费了时间
![image.png|426](http://verification.fengzhongzhihan.top/202312011034242.png)

**方法二：**
为每个实体集形成一个具有所有本地和继承属性的模式
如果专业化是完全的，则不需要通用实体集模式(person)来存储信息,可以存为视图

但外键约束可能仍然需要显式模式
- 缺点：浪费了空间
![image.png|475](http://verification.fengzhongzhihan.top/202312011034875.png)

# 12 DB设计

![image.png|400](http://verification.fengzhongzhihan.top/202312101757878.png)

四种异常
- 冗余度:高
- 插入异常
- 删除异常
- 更新异常 

原因: 构造关系模式过程中，忽视了属性之间存在着相互关联，相互依赖，相互制约的联系，盲目地把依赖不紧密的属性硬凑在一起。
## 12.1 几种码的复习

候选码：K→完全函数依赖U， K完全决定U，候选码的任何真子集都不函数决定U。
超码：K’ →部分函数依赖U， K’部分决定U，存在K ’的真子集函数决定U。
全码： R=(U)中的子集彼此不存在任何依赖，所有属性组成全码
## 12.2 函数依赖

  
**函数依赖**
令α∈R,β∈R
给定r(R)的一个实例，满足函数依赖α → β的条件：
- 对实例中的所有元组对t1 和t2 ，若t1[α ] = t2 [α ] ，则t1[β] = t2[β]
- r(R)的每个实例都满足函数依赖α → β
- 此时称为α函数确定β, β依赖于α
- 如果X→Y且Y→X，则X与Y是一一对应函数依赖，记作X←→Y。
- R下所有函数依赖组成R的函数依赖集, 称为F

注意:
- 如果两属性集X，Y的属性值之间有
	 1∶1的联系，则X←→Y  (一对一)
	 n∶1的联系，则X→Y (多对一)
	 m∶n的联系，则X!→Y，Y!→X(多对多) 
- 码→R的所有属性

分类
**平凡/非平凡**
- 平凡函数依赖
	- x->y 且 y∈x  比如 姓名学号-> 姓名
- 非平凡函数依赖
	- y∈!x

**完全/部分**
- 完全函数依赖
	- X→Y，对于X的任何一个真子集X’, 都有 X’ ↛ Y, 则称Y对X完全函数依赖,记作F
- 部分函数依赖
	- 反之 ,部分

![image.png|350](http://verification.fengzhongzhihan.top/202312101555203.png)
- 传递函数依赖
	- 如果X→Y(Y⊈X)，Y↛X，Y→Z(Z⊈Y), 则称Z对X传递函数依赖(transitive functional dependency)。记为：$X →^{传递} Z$。
	- 若Y->X,则X<-->Y, Z直接依赖于X了

举例
![image.png|325](http://verification.fengzhongzhihan.top/202312101548544.png)

## 12.3 第一范式
原子域: 元素不可再分,不具有子结构

范式: 是关系模式的集合。一个关系模式R达到某种级别，记为R∈nNF

第一范式: 如果关系模式R的所有属性都是原子,则称为第一范式,R∈1NF
- 要求: 二维表,排除了属性值为元组,数组等情况,关系中每一分量不可再分。即不能以集合、序列等作为属性值
- 不满足第一范式的数据库不能称为关系数据库
- 六种范式 : 1,2,3, BC,4,5

## 12.4 第二范式

主属性与非主属性
- 主属性 ：所有候选码中的属性为主属性。
- 非主属性 ： 不在候选码中的属性。

第二范式(2NF)
- 定义：若关系模式R∈1NF并且所有的非主属性都完全函数依赖于R的候选码，则R∈2NF。 
- 如果关系模式的每个侯选码只含一个属性，那么一定属于2NF。 
	- 2NF模式存在插入、删除等异常现象
![image.png](http://verification.fengzhongzhihan.top/202401151643045.png)

举例
![image.png|450](http://verification.fengzhongzhihan.top/202312101601741.png)
不满足第二范式
存在非主属性部分依赖于码：学号→姓名 等,课程号→课程名 等


## 12.5 BCNF范式(Boyce-Codd)
**定义**

具有函数依赖集F的关系模式R，对F+中所有的型如α → β的函数依赖下面至少有一项成立：
- α → β 是平凡的函数依赖(即β ∈α)
- α是模式R的一个超码。
![image.png](http://verification.fengzhongzhihan.top/202401151646141.png)

分解方法
- 将不满足条件的α->β拿出去单独形成一个模式
- 剩下的+α形成一个模式

举例
![image.png](http://verification.fengzhongzhihan.top/202312101608233.png)


**保持依赖**

![image.png](http://verification.fengzhongzhihan.top/202312101610524.png)

**判定**
- 对于整个表来说,则只需要检查所有F的依赖关系是不是都满足条件即可
- 对于子模式来说,需要检查F+的依赖关系!!!

算法复杂度:NP :非多项式

![image.png](http://verification.fengzhongzhihan.top/202401151744584.png)
![image.png](http://verification.fengzhongzhihan.top/202401151744616.png)

这个方法不能保证保持依赖

## 12.6 第三范式

具有函数依赖集F的关系模式R，对F+中所有的型如α → β的函数依赖下面至少有一项成立：
- α → β 是平凡的函数依赖(即β ∈α)
- α是模式R的一个超码。
- β - α 中的每个属性A都包含于R的一个候选码中。

相比BFNF更为宽松
![image.png](http://verification.fengzhongzhihan.top/202312101612514.png)

分解方法
- Step1:计算Fc(正则覆盖)
- Step2:对每一α→β∈Fc ，构造关系(αβ)
- Step3:如果step2构造的所有模式都不含R的码，选择R的一个候选码α，构造关系(α)。
注意
- Step2必须是对Fc中的函数依赖构造关系(不能是F中函数依赖)

![image.png](http://verification.fengzhongzhihan.top/202312101727688.png)

与BCNF的区别
 对任意R(F)，模式分解
- 可以无损分解到BCNF,但不一定能保持依赖
- 可以无损、保持依赖地分解到3NF

## 12.7 闭包
### 12.7.1 术语

**函数依赖集的闭包**
定义：关系模式R=(U)中，函数依赖集F及F所蕴涵的全体函数依赖称为F的闭包，记为F+。
- F是告诉你的,F+是推出来的
- 逻辑蕴涵:设F是关系模式R的一个函数依赖集，X、Y是R的属性子集，如果从F中的函数依赖能够推出X→Y，则称F逻辑蕴涵X→Y。

**属性集的闭包** 
**定义**
- 设 X ∈ U ，则属性集X关于函数依赖集F的属性集闭包为
	X+F ={A｜A∈U且X→A能由F 根据推理规则推出}
	即在函数依赖集F下，被X函数确定的所有属性集合。
- X+F最大等于U，是有限的

### 12.7.2 Armstrong 公理
- 自反律
	- 如果 Y∈X,则X->Y
- 增补律
	- 如果X→Y，且Z ∈ U，则XZ→YZ成立。(XZ代表X∪Z)
- 传递律
	- 如果X→Y和Y→Z，则X→Z成立
- 合并律
	- 如果X→Y，X→Z，则有X→YZ
- 分解律
	- 如果α → βγ，则α → β和α → γ成立。
		- 如果X→Y，且 Z ∈Y ，则X→Z成立
- 伪传递律
	- 如果X→Y，WY→Z，则XW→Z。

意义
- 把判断X→Y是否属于F+，转化为判断Y是否属于X+F 。
- F+不易求， X+F不难求。
- 判断α是否为超码，计算α+，检查α+是否包含R中的所有属性；
- 通过检查β ∈ α + ，可以检查α → β是否成立(是否属于F+)

例题
![image.png|450](http://verification.fengzhongzhihan.top/202312101632380.png)


求候选码
- 一个属性集函数确定U，若它的任一个子集都不能函数确定U，则属性集可作为候选码
-   候选码从箭头左边的属性中找。仅在箭头左边的属性(不在右边)一定在候选码中。
![image.png](http://verification.fengzhongzhihan.top/202401151707921.png)

### 12.7.3 等价/无关属性/正则覆盖

**函数依赖集的等价**
定义 设R=(U)的两个函数依赖集F和G，如果F+=G+，则称F和G是等价的，如果F和G是等价的，则称F覆盖G且G覆盖F。
- 检查F中的每个函数依赖X→Y，检查Y是否属于X+G。
- 检查G中的每个函数依赖X->Y, 检查Y是否术语X+F

![image.png](http://verification.fengzhongzhihan.top/202401151708337.png)

**函数依赖集的冗余**

![image.png](http://verification.fengzhongzhihan.top/202401151710518.png)


**无关属性**
定义 : 去除函数依赖中的一个属性不改变该函数依赖集的闭包,称该属性为无关属性
对F，去掉f中的某一个属性后，记为F’
- 同时也可以表示**属性的闭包**
- 不影响F的表示能力，即F+=F’+

![image.png](http://verification.fengzhongzhihan.top/202312101650500.png)

**正则覆盖**
关系模式R(F),F 的正则覆盖记为Fc, Fc要满足：
Fc<=>F，并且：
1)Fc不含无关属性
2)Fc函数依赖左端都是唯一的。
![image.png|335](http://verification.fengzhongzhihan.top/202401151717488.png)

![image.png](http://verification.fengzhongzhihan.top/202401151718184.png)

![image.png](http://verification.fengzhongzhihan.top/202401151720609.png)
但Fc并不唯一

**最小覆盖定义**
关系模式R(F),F 的最小覆盖记为Fm, Fm要满足：
Fm<=>F，并且：
1)Fm不含无关属性




2)Fm函数依赖右端属性都是唯一的。
## 12.8 分解

### 12.8.1 分类
- 有损分解
	- Lossy decomposition
- 无损分解
	- 令r(R)为一个关系模式，F为r(R)上的函数依赖集。令R1和R2为R的分解。如果用两个关系模式r1(R1)和r2(R2)替代r(R)时没有信息损失，则称该分解是无损分解(lossless decomposition),也称分解是无损的。
	- ![image.png](http://verification.fengzhongzhihan.top/202312101654941.png)

![image.png|450](http://verification.fengzhongzhihan.top/202312101656780.png)


无损分解定理
- 关系模式R(C), {R1,R2}是R(C)的分解；
	当下面两个函数依赖至少有一个在R(C)上成立时，分解是无损分解：(充分条件)
		R1∩R2→R1
		R1∩R2→R2

### 12.8.2 保持依赖

(dependency-preserving)
- R的分解中，不依靠不同关系连接就能验证R上成立的所有函数依赖，称分解保持依赖

官方定义
- 限定:关系模式R(F), {R1,R2…Rn}是R的一个分解；
	F+中所有只包含Ri中属性的函数依赖的集合Fi，称为F在Ri上的限定,注意是f+不是f
- 关系模式R(F),{R1,R2…Rn}是R的一个分解，
	Fi是F在Ri上的限定，F’= F1∪F2∪…∪Fn：
	- 如果F’<=>F,则称分解是保持依赖的分解

举例
![image.png|425](http://verification.fengzhongzhihan.top/202312101700639.png)
![image.png](http://verification.fengzhongzhihan.top/202401151736492.png)



## 12.9 第四范式
背景
![image.png](http://verification.fengzhongzhihan.top/202312101732253.png)

定义一：
关系模式r(R)， α∈R且β ∈R ，γ=R-α-β；
	如果对任意r均有下述命题成立：
		 任意t1,t2∈ r，如果t1[α]=t2[α],则必存在t3,t4,使
			t3[α]= t4[α]= t1[α] =t2[α],
			t3[β]=t1[β]，t3[γ]=t2[γ]
			t4[β]=t2[β]，t4[γ]=t1[γ] 
	则称：	α多值决定β，β多值依赖于α多值依赖α→→β在R上成立
![image.png|375](http://verification.fengzhongzhihan.top/202312101736182.png)
定义二
- 关系模式R， α，β ∈ R，γ=R-α-β；
	如果给定一个α值，有一组β值与之对应，β取值与γ无关，则称α→→β。

分类
- 平凡
	- ![image.png](http://verification.fengzhongzhihan.top/202312101738593.png)

- 否则 : 称为非平凡


推理
- 若α→β ，则α→→β，每一个函数依赖也是一个多值依赖。(函数依赖是多值依赖的特例)
- 若α→→β， 则α→→R – α –β

所有依赖的闭包
- 关系模式R(D), 依赖集D是其上成立的**函数依赖和多值依赖的集合**；
 D逻辑蕴含的所有函数依赖和多值依赖的集合，称作D的闭包，记作D+；


关系模式r(R)属于4NF的条件：(消除非平凡的多值依赖)
对D+中所有型如α→→β的多值依赖，至少以下之一成立：
	1) α→→β 是一个平凡的多值依赖
	2) α是一个超码

![image.png|500](http://verification.fengzhongzhihan.top/202312101747439.png)

4NF只讲一件事
- ![image.png](http://verification.fengzhongzhihan.top/202401152045610.png)


分解算法
![image.png|450](http://verification.fengzhongzhihan.top/202312101753593.png)

![image.png|450](http://verification.fengzhongzhihan.top/202312101753920.png)







