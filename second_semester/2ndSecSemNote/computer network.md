w# 1 概述
## 1.1 细节总览
设备
- 主机 = 端系统
- 在网络边缘运行网络app

包交换
- 传递数据包
- 路由器和交换器

连接线
- 传输速率 : 带宽
- 铜线, 无线电

网络: 
- 设备 , 路由器, 链路层的总和

Internet : "network of networks"
- 互相联系的ISPs(internet service provider)
组成 : 由一系列局域网组成, 包括
- 家庭网
- 移动网络
- 数据中心

协议无处不在
- 控制传递, 接受信息
- http, streaming video, TCP, IP...

服务提供
- 基站提供服务
- 每个网络都有编程接口 : socket

packet switches : 块传输方式
- 路由器
- 链路式交换机

AR : 增强现实(augmented reality)
MR : 混合现实
VR : 虚拟现实

网络标准
- RFC : Request for comments
- IETF : internet Engineering Task Force

协议 (protocal) : 定义了信息的格式, 顺序, 行动
- 制定由IETF, 格式为RFC文档
- 如:  电脑向服务器发出tcp请求, 服务器给出回应, 电脑请求get网址, 服务器返回文件

网络边缘(edge)
- 主机(端系统) 
- 客户
- 服务器(通常在数据中心)

网络核心
- 互联的路由器
- 网络的网络

## 1.2 网络边缘 : 主机, 接入网络和物理媒介

接入网络
- WLAN : 本地局域网络(wifi)
	- 范围小
- 非本地局域网络 : 流量 依靠于基站
	- 范围大
- 基于电缆的接入 : 将终端设备与ISP 路由器相连接, 通过基站(接入点)
	- FDM / TDM 
	- 频分复用(frequency division multiplex)和时分复用
	- 前者将频率切分(横切), 后者将时间切分(竖切)

电视网络 : 通过同一个共享线, 再通过不同的线接入家庭, 并通过分离器来给予主机网络

电话网络: 通过不同的线接入每一个家庭

主机传输方式 : 将message 分解成 packet(L bit) ,再将packet以R速率传输到接入网络中
- 传输时延 L / R
- 单位 bps  : bits per second 
- 也叫做带宽
![image.png](http://verification.fengzhongzhihan.top/202403092101922.png)

转发方式 : 每一个路由器上都有一个转发表(通过路由器算法生成), 通过其决定packet传输方向

中国最大的数据中心 : 中国电信的呼和浩特

物理媒介
	- 有线连接
		- TP(双绞线) : 网线
		- 同轴线 : 同心铜线
		- 光纤 : 传播光信号
	- 无线连接
		- WiFi
		- 流量
		- 蓝牙
			- 省电 + 抗干扰
		- 卫星
		- 半双工(单向收发)
			- 因为切换太快, 因此我们常认为是双工(双向收发)
## 1.3 网络核心(分包转发和电路转发)

发送的过程: 
- 将信息拆分为包
- 包通过电线经过一个一个的路由器发送到目的地
	- 每一个路由器都有对应的转发表(根据路由算法)决定包的去向

>分包转发和电路转发的区别

分包转发 : 分包发送
- 包传输延迟 : L/R 转发到link上
- 存储转发 : 所有的包都到路由器再一起转发
- 发生拥挤/丢包  : 传出速率 << 传入速率, 路由器无法容忍过多的包就会产生丢包
	![image.png](http://verification.fengzhongzhihan.top/202403092111839.png)
- 可以同时拥有很多用户, 因为很多用户同时使用的概率很小
- 需要进行拥塞控制(协议保证)

电路转发 : 没有共享, 保证效率
- 但是占用了别人资源, 永远空闲着
- 经常用于传统的电话网络
- FDM / TDM 
	- 频分复用(frequency division multiplex)和时分复用
	- 前者将频率切分(横切), 后者将时间切分(竖切)

## 1.4 因特网结构和性能度量

主机通过ISP与互联网连接, 而ISP之间是互通的
- 其中为了利益, ISP之间是通过IXP(internet exchange point)进行连接的
- 一些大型企业可能会使用自己的网络提供服务, 例如google, microsoft
![image.png](http://verification.fengzhongzhihan.top/202403092116780.png)


**网络性能度量**
- 丢包率 : 分包传输的时候会出现
	- 丢包的时候, 可能会重新传输或者一点都不传
- 延时 : 分为
	- 排队延时(dqueue) : 数据拥塞
	- 传输延时(dtrans) : 数据从路由器 - > 电路
		- d = l / R
	- 传播延时(dprop) : 数据在电路上传播
		- d = d / s
	- 节点延时(dproc) : 进行数据的处理,方向转发等等
![|375](http://verification.fengzhongzhihan.top/202406102023835.png)
- 吞吐量
	- 从发送端到接收端数据的传输速率
		- 分为即时速率和平均速率
		- 传输的速率受小的决定 (一般称为瓶颈电路)


**包传输延迟**
a : 每一个包平均的到达速率
L : 包长度
R : bit传输速率

流量密度 : La / R 
-  -> 0 : 不堵
-  -> 1 : 快掉包了
-  > 1 : 队列越来越长!

## 1.5 网络安全
发展历史 : 一开始很和谐!~
分类
- 窃听, 盗取数据
- 伪造发送
	- 发送源被更改
- DOS 
	- 使用虚假信息攻击服务器

对应方法
- 实名认证
- 机密性
- 完整性
- 防火墙
- 密码限制

## 1.6 协议层
分层的好处
- 模块化, 透明化
- 方便更新和维护

具体分层
![image.png|600](http://verification.fengzhongzhihan.top/202403101001520.png)
- 应用层 : 支持网络应用, 为各种网络应用程序提供服务接口，如电子邮件、文件传输和网页浏览等。
- 传输层 : 进程之间的数据传输, 确保数据从源主机到目标主机, 负责数据的分段, 重组, 流量控制
- 网络层 : 负责在不同的网络之间实现从源到目的地的路径选择和数据转发。
- 链路层 : 负责在相邻节点之间提供数据传输，并纠正物理层可能引入的错误。
- 物理层 : 负责计算机网络中的数据传输的物理媒介和信号


从 A -> T -> N -> L 依此给M加上头Ht, 组成了一个分段
这个过程类似于套娃

![image.png](http://verification.fengzhongzhihan.top/202403101002037.png)


从发送端到路由器到接收端的过程
![image.png](http://verification.fengzhongzhihan.top/202403101003690.png)
- 交换机只有Link + phisical
- router 还有netWork


## 1.7 互联网发展历史

~ 1961 : 在此之前主要采用电路交换的形式

1961 ~ 1972 : 早期的包交换

1972 ~ 1982 : 互联 + 新的私有网络
- best-effort : 不能保证服务模型

1980 ~ 1990 : 新协议以及网络的增生
- 83 : TCP/ IP部署 + DNS定义
- 82 : SMTP 协议定义(email)
- 85 : ftp(文件传输协议)定义
- 88 : TCP拥塞控制

90~00s : 商业化, 网页, 新的应用
- 90 : 网页Web 
- NSF : 自然科学基金

05~~ : 规模, SDN(软件定义网络), 普及

# 2 应用层

## 2.1 两种模式

创建一个网络app
- 不需要为网络核心设备写程序
- app直接与服务器进行通信
- 允许应用的快速更新和传播普及

**服务器-客户端模式**
- 服务器 
	- 总是在线
	- 恒定的IP地址
	- 总是在数据中心(规模大)
- 客户端
	- 与服务器通信
	- 间歇连接
	- 动态IP地址
	- 并不直接相互联系
	- 举例 : http , IMAP(email), FTP

**P2P模式**
- 并不依赖于服务器
- 终端系统直接相连接
- 新的点会带来新的需求
- 间歇连接以及改变IP地址
	- 例如P2P的文件共享

## 2.2 进程和接口

进程 : 也就是主机运行的程序(App)
- 在相同的主机中, 两个进程使用内在联系进行交流(OS)
- 在不同的主机中, 两个进程交换信息进行交流

分为
- 客户端进程 : 发起交流
- 服务器进程 : 等待联系
	- P2P进程同时有客户端和服务器进程

接口 : 处于A和T之间的部分, 进程通过接口进行传递和接受信息
![image.png](http://verification.fengzhongzhihan.top/202403101020529.png)

但是对于进程来说, 需要有个标识物 : 
- 主机系统有32位的IP地址
- 对于每个主机来说, 每个进程都有对应标识物, 包括IP addr + port numbers
>to send HTTP message to gaia.cs.umass.edu web server:
IP address: 128.119.245.12
port number: 80

## 2.3 应用层和传输层协议

应用层协议定义了
- 传输消息的类型
- 信息的语法(怎么划分的)
- 信息的语义
- 规定如何进程发送接受信息
- 协议是开源的, 每个人都可以接入

应用层需要传输层提供的服务 : 
- 保证数据完整性
	- 有些应用需要100%完整性
- 时延
	- 一些app 需要低时延
- 吞吐量 
- 安全性

![image.png](http://verification.fengzhongzhihan.top/202403101043753.png)
注意 : 一般来说 ; 将interactive games 的data loss 归为 no loss

**传输层协议服务**
- TCP
	- 提供可靠传输(core)
	- 流控  : 发送方不会因为数据量过大压倒接收方
	- 拥塞控制
	- 面向连接 (core)
	- 不提供 : 时延 + 吞吐量保证 + 安全性
- UDP
	- 不稳定的传输
	- 其余均不提供
	- 但是快
![image.png|500](http://verification.fengzhongzhihan.top/202403101046808.png)

安全性 TLS(transport layer security)
- 提供加密的TCP连接
- 保证数据完整性
- 端点的认证
- 在应用层实现 TLS


## 2.4 Web and HTTP
### 2.4.1 HTTP简介
网页页面由很多对象组成
- 由基本的html file 组成, 其包含了 图片, 视频, 音频...
![image.png](http://verification.fengzhongzhihan.top/202403101050113.png)

HTTP : hypertext transfer protocal
- 客户端 : 发出请求的浏览器, 展示web
- 服务器 : 服务器针对请求发回文件
- 没有固定状态 : 服务器不保存任何之前客户端请求的记录
	- 若保存记录则十分复杂
- 分类
	- 非持续性http
		- tcp open
		- 一次最多传一个对象(文件)
		- tcp closed
		- 下载很多的对象需要很多次的连接
	- 持续性http
		- tcp open
		- 许多文件可以一次传
		- tcp closed

非持续型http使用TCP过程 :
![image.png](http://verification.fengzhongzhihan.top/202403101057445.png)
![image.png](http://verification.fengzhongzhihan.top/202403101059803.png)

![image.png|375](http://verification.fengzhongzhihan.top/202403182005805.png)

RTT : 一个包从客户端和服务器来回的时间
非持续型http响应时间
- one RTT : 开始TCP连接
- one RTT : http request 和返回数据
- 总体 = 2RTT + 2RTT * 对象数目
- requires 2 RTTs per object


持续型http响应时间
- one RTT : 开始TCP连接
- one RTT : http request 和返回数据
- 总体 = 2RTT + RTT
- multiple objects can be sent over single TCP connection between client, and that server


### 2.4.2 http 信息
http 信息分类
- request信息和response信息
- 一般用ASCII表示

request信息包括
![image.png|675](http://verification.fengzhongzhihan.top/202403182030804.png)
回车, 行开始的换行符标志着标题行的结束

此外, 还有一个entity body: post从这个地方取东西
![image.png|425](http://verification.fengzhongzhihan.top/202403182033703.png)

![image.png](http://verification.fengzhongzhihan.top/202403182035564.png)
post : 发送信息
get : 请求信息
head : 请求信息, 仅返回标头
put : 用于向服务器上传资源或更新服务器上的资源

HTTP 返回消息
![image.png](http://verification.fengzhongzhihan.top/202403182038866.png)

Apache : 国外的移动(ISP)
返回状态码
- 200 OK
- 301 moved permanently : 已经更新了地方
- 400 bad request : 不被理解
- 404 not found
- 505 http version not supported 

### 2.4.3 cookies

http get/response 是不保存状态的, 仅仅起到数据传输的作用
- 没有多步交换 HTTP 消息来完成 Web“事务”的概念
- 客户端/服务器无需跟踪多步骤交换的“状态”
- 所有 HTTP 请求都是相互独立的
- 客户机/服务器不需要从部分完成但从未完全完成的事务中“恢复”

如果互联网中断, 会重做么?

cookies: 可以存储一些状态
分类1) HTTP 响应消息的 Cookie 头行
2)下一个 HTTP 请求消息中的 Cookie 头行
3)保存在用户主机上的 Cookie 文件，由用户浏览器管理
4)网站后端数据库

当第一次提出http请求的时候
网站创建
- cookie(ID)
- 后端数据库的ID
后续访问, http信息包括ID, 使得可以识别对应的人, 可以返回对应消息

![image.png](http://verification.fengzhongzhihan.top/202403182217113.png)
- cookie其实就是用来赚你钱的!

如何维持状态呢 ? 
在协议端点: 通过消息中的多个事务在发送方/接收方维持状态
HTTP 消息中的 cookie 携带状态

### 2.4.4 Web Cache
用处 : satisfy client requests without involving origin server

用户将本地浏览器指针指向webCache(代理服务器)
![image.png|374](http://verification.fengzhongzhihan.top/202403182220639.png)
若有消息直接返回
若无消息, 先存入Cache, 再返回

用处
- 减少响应时间
- 减少链路流量
- 可以更有效地提供内容

Server 在响应头中告诉缓存的允许缓存:
![image.png](http://verification.fengzhongzhihan.top/202403182223004.png)

计算例题:
**数据**
link rate: 1.54 Mbps
机构路由器到服务器的RTT: 2秒
Web 对象大小: 100K bit
从浏览器到原始服务器的平均请求速率: 15次/秒
- 到浏览器的平均数据速率: 1.50 Mbps

**性能**
link 利用率 (流量密度) = 1.5 / 1.54 = 0.97 (dalay 很严重)
LAN 利用率 : 0.0015
end - end delay  = 网络delay + 传输delay + LANdelay
     = 2sec + minutes + usecs

解决方法
 - 增大link rate ? 太贵了
 - 加入web cache : 假设命中率为0.4 

则到达数据线的数据为0.6 * 1.5Mbps = 0.9mbps
delay = 0.6 * delay + 0.4 * msecs(忽略)

### 2.4.5 Conditional Get

![image.png|312](http://verification.fengzhongzhihan.top/202403182235936.png)
首次请求：
	客户端请求某个资源，服务器返回资源内容以及一个 Last-Modified 头字段，该字段指示资源的最后修改时间。
后续请求：
	客户端在下一次请求该资源时，会在请求头中添加 If-Modified-Since 字段，其值为上次请求时服务器返回的 Last-Modified 值。
	服务器收到请求后，会检查资源的最后修改时间。
	如果资源自指定日期和时间之后没有修改，服务器返回 304 Not Modified 响应，并且不发送资源内容。
	如果资源已经修改，服务器返回 200 OK 响应，并发送新的资源内容及新的 Last-Modified 头字段。

### 2.4.6 HTTP2

关键:  降低多对象HTTP传输时的延时

HTTP1.1: 在单个 TCP 连接上引入了多个流水线 GET, 有一些问题
- 服务器按顺序响应 GET 请求(FCFS: 先到先得的调度)
- 使用 FCFS，小型物体可能必须在大型物体后面等待传输(线头(HOL)阻塞)
- 丢失恢复(重传丢失的 TCP 段)阻止对象传输

HTTP2: 增加了服务器向客户端发送对象的灵活性:
- 方法，状态代码，大多数头字段从 HTTP 1.1保持不变
- 基于客户端指定的对象优先级(不一定是 FCFS)的被请求对象的传输顺序
- 将未请求的对象推送到客户端(不需要重复发送很多请求的信息)
- 将对象划分为帧，调度帧以减轻 HOL(head of line) 阻塞

物体分为帧，帧传输交织
![image.png](http://verification.fengzhongzhihan.top/202403182240835.png)

HTTP2 的问题: 
- 数据包丢失的恢复仍然使所有对象的传输停止
- 与 HTTP 1.1一样，浏览器有动机打开多个并行 TCP 连接，以减少停顿，提高总吞吐量
- 普通 TCP 连接没有安全性
- HTTP/3: 通过 UDP 增加安全性，每个对象错误和拥塞控制(更多流水线)
## 2.5 Email, SMTP, IMAP
### 2.5.1 SMTP
邮件发送分为
- User agent(主机)
	- 存储, 编辑, 阅读mail messages
- mail servers
	- 邮箱包含用户的传入消息
	- 消息队列包含发出(待发送)邮件消息
发送协议: 
mail protocal : SMTP
	- 每一个user对应一个mail server
	- client (send), server (receive)
	- port : 25 , 使用TCP进行传输

SMTP三握手
![image.png|257](http://verification.fengzhongzhihan.top/202403182254476.png)

与HTTP对比
>	HTTP: pull  SMTP : push
>	HTTP: 每个对象封装在自己的响应消息中
	SMTP: 以多部分消息发送的多个对象
	SMTP 使用持久连接
	SMTP 要求消息(头和正文)在7位 ASCII
	SMTP 服务器中使用 CRLF.CRLF 来确定消息的结束
![image.png](http://verification.fengzhongzhihan.top/202403182255791.png)
- 从用户 -> mail server使用SMTP
- 用户代理使用HTTP
- mailserver -> useragent 使用IMAP

SMTP: 电子邮件消息的传递/存储到接收者的服务器  
邮件访问协议: 从服务器检索邮件  
IMAP: 互联网邮件访问协议 \[RFC 3501]：消息存储在服务器上，IMAP 提供在服务器上检索、删除、存储文件夹等功能  
HTTP: Gmail、Hotmail、Yahoo! Mail 等提供基于 Web 的界面，使用 SMTP 发送邮件，使用 IMAP（或 POP）检索电子邮件消息
![image.png](http://verification.fengzhongzhihan.top/202403182258585.png)

### 2.5.2 IMAP

IMAP: Internet Mail Access Protocol : 服务器上存储的消息，IMAP 提供服务器上存储的消息的检索、删除和文件夹
- IMAP是从接收方的mail server -> user agent的协议
- HTTP也可以用作这个协议, 基于 Web 的界面来检索电子邮件消息

## 2.6 DNS(域名系统)
### 2.6.1 DNS定义
每个主机(路由器)都有一个IP地址, name来进行标识
- 如何对IP和name进行映射 -> DNS

域名系统(DNS) :
- 在多个名称服务器的层次结构中实现的分布式数据库
- 应用层协议: 主机、 DNS 服务器通信以解析名称(地址/名称转换)
- 注: 核心 Internet 功能，作为应用层协议实现

DNS服务包括
- 主机名到 IP 地址转换
- 主机别名规范，别名邮件服务器别名
- 负载分布
	- 复制的 Web 服务器: 许多 IP 地址对应一个名称

为什么不使用中心化的DNS
- 一点爆炸, 全部爆炸
- 流量规模
- 相距很远
- 持久性

### 2.6.2 DNS结构

![image.png](http://verification.fengzhongzhihan.top/202403182306590.png)

客户想要访问 \www.amazon.com

1. root 找到.com DNS server
2. .com DNS server找到 amazon.com DNS server
3. amazon.com DNS server 得到IP地址

root servers: 
- 官方的，最后联系人的名字服务器不能解决的名字。非常重要
- 逻辑上全球有13个
- DNSSEC – 提供安全(身份验证，消息完整性)
- ICANN (互联网名称和数字分配公司)管理根 DNS 域

top-lever domain servers(TLD)
- responsible for .com, .org, .net, .edu, .aero, .jobs, .museums, and all top-level country domains, e.g.: .cn, .uk, .fr, .ca, .jp
- Network Solutions: authoritative registry for .com, .net TLD
- Educause: .edu TLD

authoritative DNS servers
- 可以组织自己的 DNS 服务器，为组织的命名主机提供权威的 IP 映射主机名
- 可由组织或服务提供者维护

特殊的local DNS name servers, 不严格属于层次结构
- 当主机进行 DNS 查询时，它被发送到其本地 DNS 服务器
- 回答 : 从最近的名称到地址转换对的本地缓存中(可能已经过时了!)
	- 将请求转发到 DNS 层次结构以进行解决
- 每个 ISP 都有本地 DNS 名称服务器; 找到你的:
	- MacOS:% scutil —— dns
	- Windows: > ipconfig/all

### 2.6.3 DNS的两种查询方式

DNS 名称解析: iterated query 迭代查询
![image.png|400](http://verification.fengzhongzhihan.top/202403182317356.png)
我不知道, 你找x去
2 : 请求.edu
4 : 请求 umass
6: 请求dns.cs.

递归查询recursive query
- 将名称解析的负担放在联系的名称服务器上, 高层次的重负荷
![image.png|525](http://verification.fengzhongzhihan.top/202403182319032.png)
注意, 最后不是直接返回给local DNS server : 因为不知道IP地址


### 2.6.4 缓存信息
一旦名称服务器学习了映射，它将缓存映射，并立即返回一个缓存映射以响应查询
- 缓存提高了响应时间
- 缓存条目超时(消失)一段时间后(TTL): 
- TLD 服务器通常缓存在本地名称服务器中

缓存的条目可能已过期
- 如果命名主机更改 IP 地址，可能不知道, 直到所有 TTL 过期！
- 尽最大努力，名字到IP的翻译

### 2.6.5 DNS格式

![image.png](http://verification.fengzhongzhihan.top/202403182323288.png)
A: hostname -> IP
NS : domain -> hostname of authoritative name server
Cname : 别名 -> 真名
MX : domain ->SMTP mail server 的真名

![image.png|525](http://verification.fengzhongzhihan.top/202403182325898.png)

有着相同的标号(方便对齐): identifications
![image.png](http://verification.fengzhongzhihan.top/202403182325532.png)

**举例** 
建立DNS "Network Utopia" 
- 在域名服务注册 networkuptopia.com (在DNS注册机构例如Network solution注册)
	- 提供权威名称服务器(主服务器和辅助服务器)的名称、 IP 地址
	- Register 将 (NS，A) RRs 插入.com TLD 服务器:
		- (networkutopia.com, (Authoritity)dns1.networkutopia.com, NS)
		 (dns1.networkutopia.com, 212.212.212.1, A)

使用 IP 地址212.212.212.1在本地创建权威服务器
type A record for www.networkuptopia.com
type MX record for networkutopia.com

## 2.7 P2P应用

最主流 : 文件共享, 磁力种子...
**clinet-server**
![image.png](http://verification.fengzhongzhihan.top/202403212007677.png)
- 一个用户需要下载时间为F / dmin
- 总上传时间 NF/ us
**p2p**
![image.png](http://verification.fengzhongzhihan.top/202403212012192.png)
- 一份文件上传到服务器的时间F / us
- 一个用户需要下载时间为F / dmin
- 一共需要上传时间为 NF / us + Σui

![image.png|425](http://verification.fengzhongzhihan.top/202403212013915.png)

服务器: 记录主机上的文件资源等等.
原理 : 拆分文件为文件块
![image.png](http://verification.fengzhongzhihan.top/202403212018102.png)

## 2.8 视频流媒体(非重点)

以恒定速率显示的图像序列 : 例如，每秒24张图片(FPS)
视频本质 : 图片
图片本质 : 像素(RGB)
- 阵列每个像素由位表示

编码:  利用图像内部和图像之间的冗余来减少用于编码图像的位空间 (帧和帧之间很相近)
- 很大
- 暂时的(从一个图像到下一个图像)

编码格式 : CBR(constant bit rate) 和 VBR(variable bit rate)

DASH : (Dynamic ,Adaptive , Streaming over HTTP)
- 每一个分辨率都存了不同的视频

CNDS : Content distribution networks
	包括Akamai, LimeLight
## 2.9 socket编程

连接application process 和 transport层
使用UDP / TCP
- 一个简单的案例 : 客户端 输入小写字符, 服务器变为大写字符并进行返回给客户端
### 2.9.1 UDP
![image.png](http://verification.fengzhongzhihan.top/202403221026349.png)
UDP client
```python
from socket import * // 加入模板库
serverName = ‘hostname’ / IP addr
serverPort = 12000
#创建客户端接口
clientSocket = socket(AF_INET(internet protocal),  SOCK_DGRAM (socket))
# 输入信息
message = raw_input(’Input lowercase sentence:’) # 卡住
# 客户端接口输入信息, 服务器主机名(addr), 服务器端口
clientSocket.sendto(message.encode(),(serverName, serverPort))
# 从客户端接口
modifiedMessage, serverAddress = clientSocket.recvfrom(2048) # 卡住
print modifiedMessage.decode()
clientSocket.close()
```

UDP server
```python
from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print (“The server is ready to receive”)
while True:
	# (IP and port) = clientAddress
    message, clientAddress = serverSocket.recvfrom(2048) # 卡住
    modifiedMessage = message.decode().upper()
    serverSocket.sendto(modifiedMessage.encode(), clientAddress)
```
区别在于server绑定了端口, 而client没有绑定端口

### 2.9.2 TCP

TCP需要建立连接, 可以确保顺序
- 原因 : 主机可以进行校正, 其实接收到的还是无序的

![image.png|425](http://verification.fengzhongzhihan.top/202403221048399.png)
- 此时换成了connectionSocket

TCP client
```python
from socket import *
serverName = ’servername’
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM) # TCP
# 建立连接
clientSocket.connect((serverName,serverPort))
sentence = input(‘Input lowercase sentence:’)
# 已经建立了连接, 因此不需要再指定IP addr和port
clientSocket.send(sentence.encode())
modifiedSentence = clientSocket.recv(1024) # 缓存字节数
print (‘From Server:’, modifiedSentence.decode())
clientSocket.close()

```

TCP server
```python
from socket import *
serverPort = 12000
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind((‘’,serverPort))
serverSocket.listen(1)
print ‘The server is ready to receive’
while True:
	# 从serverSocket里面得到connectionSocket和client的addr
     connectionSocket, addr = serverSocket.accept()
     sentence = connectionSocket.recv(1024).decode()
     capitalizedSentence = sentence.upper()
     connectionSocket.send(capitalizedSentence. encode())
     connectionSocket.close()

```


# 3 传输层

## 3.1 传输层作用和定义
flow control : 流控制(传输层)
congestion control : 拥塞控制(网络层)

传输层提供在不同主机上运行的应用程序进程之间的逻辑通信
传输定义(从上到下, 从下到上)
- 发送方: 将应用程序消息分段，传递到网络层
- 接收方: 将段重新组装成消息，传递到应用层

网络层: 主机之间的逻辑通信
传输层: 进程之间的逻辑通信

TCP : transmission control protocol
UDP: User Datagram Protocal

## 3.2 复用和分解
multiplex : 复用 (从上到下)
(多输入)application -> transport(单输出)

demultiplex : 分解(从下到上)
(单输入)transport -> application(多输出)

host uses IP addresses & port numbers to direct segment to appropriate socket
IP/UDP datagrams with same dest. port #, but different source IP addresses and/or source port numbers will be directed to same socket at receiving host

UDP如何识别正确的socket: demultiplex过程?
- 不同的数据发送到相同的IP/port用的是同一接口
- 接受端口仅用端口号决定

![](http://verification.fengzhongzhihan.top/202406111938111.png)

TCP
- 使用4元组来标识连接(双方的IP/port number)
- 虽然目的地的IP, port相同, 但是还是用不同的socket处理
![](http://verification.fengzhongzhihan.top/202406111940842.png)

源端口号和目的地端口号能一样吗 ? 
	可以, 只有IP是唯一的

## 3.3 可靠性传输原理

### 3.3.1 整体
![image.png|400](http://verification.fengzhongzhihan.top/202403282024364.png)

传输层以下均为不可靠传输
- 数据是单向的, 控制信号是双向的(如ACK, NAK)

rdt介绍
![image.png|525](http://verification.fengzhongzhihan.top/202403282032092.png)

设计RDT
consider only unidirectional data transfer 单向数据传输
	but control info will flow in both directions! 但是双向收发
使用有限状态机(FSM)标识发送端和接收端 :
![image.png](http://verification.fengzhongzhihan.top/202403282032967.png)
- 事件 -> 状态转移

### 3.3.2 RDT各个版本
**rdt 1.0** : 假设无bit错误, 无丢包
发送端和接收端有着独立的fsm
![image.png](http://verification.fengzhongzhihan.top/202403282034582.png)
**rdt 2.0** : 有bit错误, 如何恢复呢?
接收方给发送方消息: 
- acknowledgements (ACK)
	- 若收到, 传下一个
- negative acknowledgements(NAK)
	- 若收到, 则重传一遍
类型 : stop and wait

![image.png|450](http://verification.fengzhongzhihan.top/202403282045338.png)

![image.png|281](http://verification.fengzhongzhihan.top/202403282048856.png)


**rdt 2.1**
若ACK / NAK本身错误如何呢? 
- 不能直接重传; 因为可能会导致重复传输
- 解决方法 : 加入包的编号0 / 1, 接收端对于重复的包直接进行抛弃

![image.png|550](http://verification.fengzhongzhihan.top/202403291022980.png)
- 先发送包0
	- 接受到包
		- 如果是ACK : 准备发送包1
		- 如果是NAK或者 包损坏: 重新发送包0
- 再发送包1
	- 接受到包
		- 如果是ACK:准备发包0
		- 如果是NAK或者 包损坏:  重新发送包1

![image.png|550](http://verification.fengzhongzhihan.top/202403291027848.png)
- 接受包0
	- 如果是包0 : 发送ACK, 准备接受包1
	- 如果包坏了, 发送NAK
	- 如果是包1 : 发送ACK(说明上一次发的消息没收到? 重新发一次)
注意 : 接收端需要1端口包的时候, 如果发来的包是0端口包, 则发送消息为ACK

**rdt2.2 a NAK - free protocal**
解决方法 : 需要 ACK 1 的时候, 将原本的NAK1 = ACK 0 

**TCP使用了这个方法**
![image.png](http://verification.fengzhongzhihan.top/202403291042483.png)

**rdt3.0 : 底层传输包括丢包**
- 此时加入定时功能
	- 发送方等待“合理”的 ACK 时间, 如果此时没有收到 ACK，则重新传输
	- 如果 pkt (或 ACK)只是延迟(没有丢失) : 同理
	- 其实只是加入了如果计时失败就重新发送的功能

![image.png](http://verification.fengzhongzhihan.top/202403302132268.png)

![image.png|365](http://verification.fengzhongzhihan.top/202403302132263.png)
- 如果延时发送的请求, 返回了ACK迟于第一次到的ACK, 则无效
	- 简单来说就是需求不断在变化

这种方式的利用率是很低的
![image.png](http://verification.fengzhongzhihan.top/202403302135801.png)

### 3.3.3 RDT高级版本 流水线
- 增加编号
- 接受发送端加入缓存
![image.png](http://verification.fengzhongzhihan.top/202403302136783.png)

**Go-Back-N sender (回退N步)**

发送端
![image.png](http://verification.fengzhongzhihan.top/202403302138655.png)
接收端
![image.png](http://verification.fengzhongzhihan.top/202403302138597.png)
**回退n步过程**
![image.png|625](http://verification.fengzhongzhihan.top/202403302139812.png)
接收端 : 没有按序接收到pkt2! 因此不断发送ack1的请求, 此时对于后来包直接丢弃
发送端 : 先同时发出4个包, 只有ack到自己窗口最左端才会往后发送
否则进入延迟, pkt2会自动发送

**优化版** : selective repeat : 选择性重传: 有缓存
**sender**
发送者超时/重新发送未经确认的数据包
发送方维护每个 unACKed pkt 的计时器
- 每个都有一个计时器
- 而一般的只有最早的一个的计时器
![image.png](http://verification.fengzhongzhihan.top/202403302144958.png)

**receiver**
接收者单独确认所有正确接收的数据包
将没有正确接受的包放入缓冲，根据需要，最终按顺序传递到上层
![image.png](http://verification.fengzhongzhihan.top/202403302145493.png)


![image.png](http://verification.fengzhongzhihan.top/202403302147488.png)
- 收到ack2后直接移动窗口到6, 7, 8 ,9
- 注意此时接收端发送ack3而不是按照顺序发送ack. 每个包单独确认ack

但是不是没有问题!
![image.png|425](http://verification.fengzhongzhihan.top/202403302149443.png)
如果ack出问题?
## 3.4 UDP
### 3.4.1 特点
User Datagram protocal
why UDP ?
- 没有连接建立(可以添加 RTT 延迟)
- 简单: 在发送方、接收方没有连接状态
- 小头尺寸
- 没有拥塞控制
	- UDP 可以以所需的速度爆炸！
	- 可以在拥塞面前发挥作用

“无花哨”协议：
	数据段可能丢失，可能乱序传输
	尽力服务：“发送并希望最好的结果”

UDP 有其优点：
	不需要设置/握手（不会产生往返时间）
	在网络服务受损时也能工作
	有助于可靠性（校验和）

connectionless:
- no handshaking between UDP sender, receiver
- each UDP segment handled independently of others
- HTTP一般认为跑TCP

如果要求安全性和可靠性
- 使用Application layer保证UDP

**传输过程**

![image.png|625](http://verification.fengzhongzhihan.top/202403282009526.png)
![image.png|625](http://verification.fengzhongzhihan.top/202403282009471.png)
### 3.4.2 checkSum
将 UDP 段的内容（包括 UDP 头字段和 IP 地址）视为一系列 16 位整数。
校验和：段内容的相加（一补和）。
校验和值放入 UDP 校验和字段。
- 检测错误(如比特翻转)
- 相加后进位放最后一位并相加, 最后取反
![image.png](http://verification.fengzhongzhihan.top/202403282018792.png)
- 将最高有效位的进位加到结果中

但是如果10 / 01 变为 01 / 10结果并未改变, 因此保护性比较弱
![](http://verification.fengzhongzhihan.top/202406111951683.png)


构成
![image.png|400](http://verification.fengzhongzhihan.top/202403282016751.png)

## 3.5 TCP

### 3.5.1 组成
MSS: 最大报文大小
可靠按序字节流
点对点(一个发送端一个接收端)

实现
- 流控 : 发送端不会淹没接收端
- 拥塞控制
- 面向连接 : 信息交换前握手初始化信息

包组成
![image.png](http://verification.fengzhongzhihan.top/202404111916902.png)
- A为有效位

例如分组为
01 234 5 6
传输的编号是该分组的第一个字节
- 分别为0 2 5 6
- 使用累计ACK(没有单独ack认证)
- 收到了包0, 返回ACK2 (期待的下一个字节)

接收方如何处理无序段? 
	一般使用缓存

双向传输
![image.png|450](http://verification.fengzhongzhihan.top/202404111929621.png)

### 3.5.2 延时设置
问: 如何设置 TCP 超时值？
- 比 RTT 更长，但是 RTT 是变化的！
- 太短: 过早超时，不必要的重新传输
- 太长: 对分段丢失反应缓慢

SampleRTT 将有所不同，希望估计的 RTT“更平滑”
- 平均几个最近的测量值，而不仅仅是当前的 SampleRTT

![image.png](http://verification.fengzhongzhihan.top/202404111934492.png)
指数加权移动平均(EWMA)

Timeout Interval设置方法
![image.png|600](http://verification.fengzhongzhihan.top/202404111937304.png)

estimated = (1 - α)estimated  + α sample
devRtt = (1 - β)dev + β |sample - estimated|
timeout = estimated + 4 devRtt
### 3.5.3 传输实例
三种情况
![image.png|190](http://verification.fengzhongzhihan.top/202404111947474.png)![image.png|300](http://verification.fengzhongzhihan.top/202404111944532.png)
注意此时为ACK120, 因为对于接收端来说, 已经收到了100 + 20, 因此重复需要120, 而非发来的数据

![image.png|237](http://verification.fengzhongzhihan.top/202404111946144.png)![image.png|300](http://verification.fengzhongzhihan.top/202404112003325.png)
如果接收端没有按序接受到, 则需要ACK没有收到的包

### 3.5.4 流控(接受端)
![image.png|300](http://verification.fengzhongzhihan.top/202404112005979.png)

TCP 接收器在 TCP 报头的 rwnd 字段中“广告”可用缓冲区空间
- 通过套接字选项设置的 RcvBuffer 大小(典型的默认值是4096字节)
- 许多操作系统自动调整 RcvBuffer
- 发送方限制未经处理(“空中”)的数据量到接收的 rwnd (recieved window)
- 保证接收缓冲区不会溢出

### 3.5.5 三握手连接
三握手过程
![image.png|750](http://verification.fengzhongzhihan.top/202404112012769.png)

注意 最后一个传输可以传数据, 因此我们不把它作为额外开销
- 因此默认1RTT

关闭连接
客户端、服务器端各自关闭其连接端
- 发送 FIN 位 = 1的 TCP 段

### 3.5.6 拥塞控制(发送端)
AIMD (Additive increase)  (multiplicative decrease)
![image.png|375](http://verification.fengzhongzhihan.top/202404112018687.png)
线性增大, 突然下降(锯齿状)

cwnd : 拥塞窗口
- cwnd 会因应观察到的拥塞控制而动态调整(实施 TCP 拥塞控制)
- ![image.png|276](http://verification.fengzhongzhihan.top/202404112023311.png)
- lastbytesent - lastbyteacked <= cwnd

慢启动 : 
- 初始cwnd = 1MSS
- 每次接收到一个ACK,则增加一个MSS
- 则是一个指数增长的过程, 每次MSS都是double

问: 指数增长应该在什么时候转变为线性增长？
答: 当 cwnd == ssthresh
![image.png|600](http://verification.fengzhongzhihan.top/202404112029132.png)


![image.png|600](http://verification.fengzhongzhihan.top/202404112038700.png)
超时
- ssthresh = cwnd / 2 
- 则cwnd 置为1
- dupAckcount = 0

3ACK(收到了多个ACK) 
- ssthresh =  cwnd / 2
- 则cwnd = cwnd / 2 + 3 


# 4 网络层(路由器内部)
## 4.1 roadMap
路由器里有什么
- 输入端口，开关，输出端口
- 缓冲区管理、调度
-
IP : 互联网协议
- 数据报格式
- 地址
- 网络地址转换 (NIT)
- IPv6

数据面板
- 每个路由器的本地函数
- 确定到达路由器输入端口的数据包如何转发到路由器输出端口
- 决定转发

控制面板
- 网络范围内的逻辑电路
- 确定数据包是如何在路由器之间沿着从源主机到目标主机的终端路径路由的
- 决定路由器算法

传统的路由算法: 在路由器中实现
每个路由器中的各个路由算法组件在控制平面上相互作用

![image.png|575](http://verification.fengzhongzhihan.top/202404121052365.png)

软件定义网络(SDN) : 在(远程)服务器中实现
![image.png](http://verification.fengzhongzhihan.top/202404121054325.png)

**网络层不可靠 : 因此需要传输层的协议**确保
- best effort方式
- 永远依靠上层协议来确保


**转发方式**
- 使用头字段值，使用输入端口内存中的转发表查找输出端口
- 基于目的地的转发: 仅基于目的地 IP 地址的转发(传统)
- 广义转发: 基于任意头字段值集的转发
- 使用最长前缀进行匹配

![|650](http://verification.fengzhongzhihan.top/202406131643818.png)
1 - 1
2 - 2

## 4.2 路由器内部 : 缓冲情况
![|575](http://verification.fengzhongzhihan.top/202406131647591.png)

input port queuing
(Head-of-the-line) (HOL) blocking
![image.png|500](http://verification.fengzhongzhihan.top/202404222313387.png)
output port queuing
![image.png|500](http://verification.fengzhongzhihan.top/202404222313347.png)

**缓冲设置 ?** 
平均缓冲buffer等于“典型”RTT (比如说250毫秒)乘以链路容量 C
有N个流
则buffer = RTT \* c / 根号N

**缓冲管理**
FCFS(first in, first served)

priority(红色优先)
![image.png](http://verification.fengzhongzhihan.top/202404222320863.png)

round robin : 服务器周期性地重复扫描类队列，依次从每个类(如果可用)发送一个完整的数据包
![image.png|400](http://verification.fengzhongzhihan.top/202404231142325.png)

weighted fair queueing: 有权重, 而不是等重
![image.png|475](http://verification.fengzhongzhihan.top/202404231143132.png)



## 4.3 IP: internet协议

### 4.3.1 数据包格式
![image.png](http://verification.fengzhongzhihan.top/202404230943842.png)

IP 地址: 与每个主机或路由器接口相关联的32位标识符
接口(interface): 主机/路由器和物理链路之间的连接
- 路由器通常有多个接口
- 主机通常有一个或两个接口(例如，有线以太网，无线802.11)

以太网交换机连接有线网接口
while 无线基站连接无线网接口
![image.png|400](http://verification.fengzhongzhihan.top/202404230949905.png)
### 4.3.2 子网
子网是什么？
- 无需通过中间路由器即可物理地相互连接的设备接口
![image.png|350](http://verification.fengzhongzhihan.top/202404230950485.png)

IP 地址结构:
- 子网部分: 同一子网中的设备具有共同的高阶位
- 主机部分: 剩余的低阶位

CIDR: 无类域间路由(发音为“ cider”)(Classless Inter Domain Routing)
- 任意长度地址的子网部分
- 地址格式: a.b.c.d/x，其中 x 是地址的子网部分中的 # bit

![image.png|350](http://verification.fengzhongzhihan.top/202404230953990.png)

**How does host get IP address?**
- hard-coded by sysadmin in config file (e.g., /etc/rc.config in UNIX)
- **DHCP**: Dynamic Host Configuration Protocol: dynamically get address from as server
## 4.4 DHCP(应用层协议)
过程: 
1. host broadcasts DHCP discover msg \[optional]
2. DHCP server responds with DHCP offer msg \[optional]
3. host requests IP address: DHCP request msg
4. DHCP server sends address: DHCP ack msg 

通常，DHCP 服务器将共同定位在路由器，服务所有子网的路由器连接
![](http://verification.fengzhongzhihan.top/202406131703460.png)

![image.png](http://verification.fengzhongzhihan.top/202404230959595.png)

DHCP 可以返回
- 子网上分配的 IP 地址
- 客户端第一跳路由器地址
- DNS 服务器的名称和 IP 地址
- 网络掩码(主机部分地址)

过程
request
![](http://verification.fengzhongzhihan.top/202406131707090.png)

ACK
![](http://verification.fengzhongzhihan.top/202406131708223.png)

Q: how does network get subnet part of IP address?
A: gets allocated portion of its provider ISP’s address space

例如分为
![image.png|500](http://verification.fengzhongzhihan.top/202404231009781.png)



## 4.5 NAT
network address translation : NAT
NAT: 就外部世界而言，本地网络中的所有设备只共享一个 IPv4地址
![image.png](http://verification.fengzhongzhihan.top/202404231018665.png)
- 从addr -> NAT addr

本地网络中的所有设备在“私有”IP 地址空间中都有32位地址，只能在本地网络中使用
优点:
- 只有一个 IP 地址需要从供应商 ISP 的所有设备
- 可以在不通知外界的情况下更改本地网络中的主机地址
- 可以更改 ISP 而无需更改本地网络中设备的地址
- 安全性: 本地网内的设备不能直接寻址，外界可以看到

实现NAT 路由器必须(透明地) :
- 传出数据报: 将每个传出数据报替换(源 IP 地址，端口 #)到(NAT IP 地址，新端口 #)
- 记住(在 NAT 转换表中)每个(源 IP 地址，端口 #)到(NAT IP 地址，新端口 #)转换对
- 传入数据报: 将每个传入数据报的目的地字段中的（NAT IP地址，新端口号）替换为NAT表中存储的对应（源IP地址，端口号）。


![image.png|600](http://verification.fengzhongzhihan.top/202404231027195.png)
广泛应用于家庭和机构网络，4G/5G 蜂窝网络

## 4.6 SDN

广义转发: 简单的包处理规则
- 包头字段中的模式值
- 动作: 对于匹配的数据包: 下降，转发，修改，匹配的数据包或发送匹配的数据包给控制器
- 优先级: 消除重叠模式的歧义
- 计数器: # 字节和 # 数据包

![image.png|450](http://verification.fengzhongzhihan.top/202404231039679.png)

example : 
![image.png|475](http://verification.fengzhongzhihan.top/202404231041767.png)

![image.png](http://verification.fengzhongzhihan.top/202404231044613.png)
![image.png](http://verification.fengzhongzhihan.top/202404231044474.png)

## 4.7 IPV6

格式
![image.png](http://verification.fengzhongzhihan.top/202404231030249.png)

如何统一IPV4 / IPV6?
在 IPv4路由器之间的 IPv4数据报中作为有效负载 承载的 IPv6数据报(“包中包”)

![image.png|475](http://verification.fengzhongzhihan.top/202404231032976.png)
![image.png|425](http://verification.fengzhongzhihan.top/202404231033804.png)
![image.png|475](http://verification.fengzhongzhihan.top/202404231033066.png)
![image.png|450](http://verification.fengzhongzhihan.top/202404231035427.png)

## 4.8 middle Box

IP沙漏身材(bushi)

![image.png|500](http://verification.fengzhongzhihan.top/202404231049609.png)

也有中年小肚腩?
![image.png|450](http://verification.fengzhongzhihan.top/202404231050487.png)


但是还没解决这样一个问题? 
问: 转发表(基于目的地的转发)或流表(通用转发)是如何计算的？
答: 由控制平面(下一章)

# 5 网络层(路由器 - > 路由器)
构建网络控制平面的两种方法:
- 路由器控制(传统)
- 逻辑集中控制(SDN)
## 5.1 路由器协议

路由器算法的分类
- 全球: 所有路由器有完整的拓扑，链路成本信息: “链路状态”算法
- 动态: 路线变化更快定期更新或响应链接成本的变化
- 分散: 迭代计算过程，与邻居交换信息
	- 路由器最初只知道连接到附加邻居的链路成本
	- “距离向量”算法
### 5.1.1 Dijkstra link-state算法
知道全局的链路开销(W)
**变量记录**
Cx，y: 从节点 x 到 y 的直接链路开销; 如果不是直接邻居，则为 = ∞
D (v) : 从源地到目的地的最小费用路径的当前费用估计数 v
P (v) : 从源到 v 的路径上的前置节点
N’: 其最小代价路径确定已知的节点集
![image.png|525](http://verification.fengzhongzhihan.top/202404251932561.png)
**算法过程**
![image.png](http://verification.fengzhongzhihan.top/202404251942334.png)

![image.png](http://verification.fengzhongzhihan.top/202404251950482.png)
![image.png](http://verification.fengzhongzhihan.top/202404251952856.png)

**分析**
算法复杂度: n 个节点
- 每次 n 次迭代: 需要检查所有节点，而不是 N
- N (n + 1)/2比较: O (n^2)复杂度
- 更有效的实现: O (nlogn)

### 5.1.2 Bellman-Ford  DV算法
每个节点时不时地向邻居发送自己的距离向量

对于每个结点
- 等待邻居结点的消息 / 自己的local link cost Change
- 重新计算自身DV(distance vector)
- 如果改变了DV, 则告诉邻居

迭代 + 异步(分布式 + 自我停止)
- 如果DV不变, 则不会再发消息

举例: 
![](http://verification.fengzhongzhihan.top/202406131733198.png)
![image.png|550](http://verification.fengzhongzhihan.top/202404251911166.png)
好消息传的比较快(耗费变小)
收敛速度 : LS O(n^2) DV : 可能有循环


![](http://verification.fengzhongzhihan.top/202406131735042.png)

## 5.2 内部/ 外部路由器算法

将路由器聚合成称为“自治系统”(AS)(又名“域”)(autonomous systems)

内部 AS (又名“内部域”) : 在同一 AS (“网络”)之间进行路由
- 同一AS 中的所有路由器必须运行相同的域内协议
- 不同 AS 中的路由器可以运行不同的域内路由协议
- 网关路由器: 在自己的 AS 的“边缘”，有链接到其他 AS 的路由器

Intra-AS routing
**内部路由器常用OSPF**开放最短路径优先(Open Shortest Path First)

Inter- AS (亦称“域间”) : AS 之间的路由
- 网关执行域间路由(以及域内路由)

routing among ISPs 
**运营商之间的算法 : BGP**边界网关协议(Border Gateway Protocol)

## 5.3 SDN
优势 : 
更容易的网络管理: 避免路由器错误配置，更大的流量灵活性

基于精准控制

OpenFlow protocol : 控制器和路由器之间的协议

![image.png|400](http://verification.fengzhongzhihan.top/202404252006499.png)

## 5.4 ICMP
网际控制报文协议(Internet Control Message Protocol)
报告错误信息

错误类型
![image.png|375](http://verification.fengzhongzhihan.top/202404252011836.png)
数据源将 UDP 段集发送到目的地
- 第一个集合的 TTL = 1，第二个集合的 TTL = 2，等等。
- 第 n 组中的数据报到达第 n 个路由器:
	- 路由器丢弃数据报并发送源 ICMP 消息(类型11，代码0)
	- ICMP 消息可能包括路由器名称和 IP 地址


## 5.5 SNMP
(Simple Network Management Protocol)
简单网络管理协议
- 发送消息类型

网络管理方式
![image.png|550](http://verification.fengzhongzhihan.top/202404252016995.png)
- trap : 挖坑模式
- 请求/ 响应模式

# 6 链路层
## 6.1 概述
学习:
- 错误检测, 纠正
- 广播信道的多设备接入
- 链路层寻址
- 本地网络

不同层分组名称不同
应用层 : message
运输层 : segment
网络层 : datagram 
链路层 frame 

解决问题 : 只负责直接相连的两台设备如何进行通信
- 链路层交换机 只有 链路层 + 物理层 无IP地址
- 不同链路协议在不同链路上传输数据报:

一个网络中所使用的link protocal 不同
- 可能会提供可靠的数据传输

link layer implemented in network interface card (NIC) or on a chip
- in each-and-every host
## 6.2 CRC
EDC : error detection and correction bits (e.g., redundancy) 
D:  data protected by error checking, may include header fields 
![image.png](http://verification.fengzhongzhihan.top/202405092038234.png)

前面学过了checksum, 在UDP中
更强力的: Cyclic Redundancy Check (CRC)
![](http://verification.fengzhongzhihan.top/202406152127804.png)

选择r个CRC比特，R，使得<D,R>能够被G（模2）整除
	接收方知道G，将<D,R>除以G。如果余数非零，则检测到错误！
	可以检测到所有长度小于r+1比特的突发错误
	广泛应用于实践中（以太网，802.11 WiFi）

![|525](http://verification.fengzhongzhihan.top/202406191602751.png)
- 对于接收方而言 : 使用 D * 2^ r  xor  R  /G 如果能除尽, 则成功
## 6.3 多接入协议

两种连接方式
- link 
- wireless broadcast

理想的多接入
需求
- given: multiple access channel (MAC) of rate R bps 
期望
1. when one node wants to transmit, it can send at rate R. 
2. when M nodes want to transmit, each can send at average rate R/M 
3. fully decentralized: no special node to coordinate transmissions no synchronization of clocks, slots 
4. simple 

三种类型
- channel partitioning
		divide channel into smaller “pieces” (time slots, frequency, code)
		allocate piece to node for exclusive use
- random access
		channel not divided, allow collisions
		“recover” from collisions
- “taking turns”
		nodes take turns, but nodes with more to send can take longer turns

### 6.3.1 Channel partitionining
分类
- TDMA: time division multiple access 
- FDMA: frequency division multiple access 
![image.png](http://verification.fengzhongzhihan.top/202405091941376.png)
![image.png|600](http://verification.fengzhongzhihan.top/202405091942117.png)

### 6.3.2 Random access- ALOHA

要求 : 
- 所有帧大小相同
- 时间分为相同大小的插槽(发送1帧的时间)
- 节点开始只传输槽开始
- 节点是同步的
- 如果2个或更多节点在槽中传输，所有节点检测到冲突

当节点获得新鲜帧时，在下一个时间帧中传输
	如果没有冲突:  发送
	如果碰撞: 概率p发送

![image.png|625](http://verification.fengzhongzhihan.top/202405091948786.png)
- c : 冲突 s: 成功  e : 空闲

效率
![image.png](http://verification.fengzhongzhihan.top/202405091952214.png)
    max efficiency = 1/e = .37

### 6.3.3 Random access- CSMA
(Carrier Sense Multiple Access) 载波监听多路访问

simple CSMA: listen before transmit:
	if channel sensed idle: transmit entire frame
	if channel sensed busy: defer transmission human analogy: don’t interrupt others! 
collisions can still occur with carrier sensing: 
	propagation delay means two nodes may not hear each other’s just-started transmission 
仍然会产生冲突 : 延迟

此时产生冲突不终止而会继续发送
- 降低效率
![image.png|250](http://verification.fengzhongzhihan.top/202405092011351.png)
CSMA / CD(collision detection)
如何检测是否冲突? 自己发出的信号自己能接受(双向传输), 如果不能, 则冲突

![image.png|250](http://verification.fengzhongzhihan.top/202405092011241.png)

整体算法: 
![image.png](http://verification.fengzhongzhihan.top/202405092016724.png)
- 在中断传输后, 会有一个backoff: 第m次中断, 在0~2^m - 1中选择随机数K, 等待K * 512bit times, 再选择是否重新传输
- 则冲突越多, 等待的时间越长

效率 : 
![image.png](http://verification.fengzhongzhihan.top/202405092020983.png)
Tprop = 0 : 没有冲突, 发送时间等于接收时间
Ttrans = inf : 一个人一直在发, 另外的人都不发(不是期待的)

### 6.3.4 Taking turns
![image.png](http://verification.fengzhongzhihan.top/202405092044735.png)
灵活性 + 鲁棒性不好
![image.png|500](http://verification.fengzhongzhihan.top/202405092045198.png)



## 6.4 LANs
### 6.4.1 MAC, ARP
MAC地址是局域网中的, 自带的
IP和MAC地址区别：
- 层次：MAC地址用于链路层（局域网内），IP地址用于网络层（广域网和互联网）。
- 标识：MAC地址是硬件地址，由制造商分配，全球唯一；IP地址是逻辑地址，可以动态分配，可以通过DHCP（动态主机配置协议）分配。
- 格式：MAC地址通常为48位，表示为6个字节；IPv4地址为32位，IPv6地址为128位。
- MAC : 从一个接口到另一个接口(interface)

how to determine interface’s MAC address, knowing its IP address?
- 使用ARP地址解析协议(Address Resolution Protocol)
- 已知IP求ARP

过程(A想要发送给B数据, 但是在A的ARP表中无B的MACaddr)
1.A broadcasts ARP query, containing B's IP addr destination 
- 目的地MAC address = FF-FF-FF-FF-FF-FF 
- all nodes on LAN receive ARP query 
![|347](http://verification.fengzhongzhihan.top/202405161924651.png)

2.B replies to A with ARP response, giving its MAC address 
3.A receives B’s reply, adds B entry into its local ARP table 

A, B在不同子网中
A knows B’s IP address 
- DNS
A knows IP address of first hop router, R (how?)
- DHCP
A knows R’s MAC address (how?) 
- ARP

![](http://verification.fengzhongzhihan.top/202405162026138.png)
A发送到
![|350](http://verification.fengzhongzhihan.top/202405162029114.png)

R转发成
![|300](http://verification.fengzhongzhihan.top/202405162028347.png)

### 6.4.2 Ethernet
![](http://verification.fengzhongzhihan.top/202405161927892.png)
以太网帧结构
![](http://verification.fengzhongzhihan.top/202405161927729.png)

preamble : 告诉你数据包来了
type : 表示高层的协议
- IP(mostly), 等等
CRC : 循环冗余校验

特点 : connectionless, unreliable

Ethernet’s MAC protocol: 
- unslotted CSMA/CD with binary backoff 

### 6.4.3 switch
交换机是一个链路层设备：它起到积极的作用
	存储并转发以太网帧
	检查接收到的帧的MAC地址，有选择地将帧转发到一个或多个输出链路
	当帧需要在网络段上转发时，使用CSMA/CD协议访问网络段
	透明性：主机不需要知道交换机的存在
	即插即用，自学习
	交换机不需要配置
 
![|346](http://verification.fengzhongzhihan.top/202405161935154.png)
交换: A-to-A’和 B-to-B’可以同时传输，没有冲突
	but A-to-A’ and C to A’ can not happen simultaneously 
![](http://verification.fengzhongzhihan.top/202406152208595.png)

when  frame received at switch:
1. record incoming link, MAC address of sending host
2. index switch table using MAC destination address
3. if entry found for destination
  then {
     if destination on segment from which frame arrived //如果发给自己
       then drop frame//丢包
           else forward frame on interface indicated by entry
       }   
      else flood  在不是到达接口的所有接口上进行转发

和router的比较
routers: compute tables using routing algorithms, 
IP addresses switches: learn forwarding table using flooding, learning, MAC addresses 

**改进**
VLAN(Virtual LAN)
- 功能比较强的交换机
- 支持 VLAN 功能的交换机可以配置为在单个物理 LAN 基础设施上定义多个虚拟局域网。

![|374](http://verification.fengzhongzhihan.top/202405161949619.png)
CS 用户移动办公室到 EE-物理连接到 EE 交换机，但希望保持逻辑连接到 CS 交换机

流量隔离: 进出端口1-8的帧只能到达端口1-8
- 也可以根据端点的 MAC 地址而不是交换机端口定义 VLAN
VLANS 之间的转发: 通过路由完成(就像使用单独的交换机一样)

***802.1Q VLAN frame format**
![|525](http://verification.fengzhongzhihan.top/202405162013588.png)

802.1 -> 802.1Q可以改协议, 只要修改路由器即可


## 6.5 dataCenter

连接方式
![|500](http://verification.fengzhongzhihan.top/202405162032016.png)
increased throughput between racks (multiple routing paths possible)
increased reliability via redundancy

![|475](http://verification.fengzhongzhihan.top/202405162033048.png)

负载均衡
![](http://verification.fengzhongzhihan.top/202405162037591.png)
期望放到一起去, 但是不一定
灵活性和性能的tradeOff

RDMA : 绕过协议栈, 省去很多访存过程, 直接拷贝数据从底层到顶层
- link layer

transport layer:
- ECN

## 6.6 A day 
场景：学生将笔记本电脑连接到校园网络，请求并接收 www.google.com 页面
### 6.6.1 DHCP
connecting laptop needs to get its own IP address, addr of first-hop router, addr of DNS server: use DHCP
- DHCP request encapsulated in UDP, encapsulated in IP, encapsulated in 802.3 Ethernet
- Ethernet frame broadcast (dest: FFFFFFFFFFFF) on LAN, received at router running DHCP server
- Ethernet demuxed to IP demuxed, UDP demuxed to DHCP 
![|247](http://verification.fengzhongzhihan.top/202406152235047.png)
- DHCP server formulates DHCP ACK containing client’s IP address, IP address of first-hop router for client, name & IP address of DNS server
- encapsulation at DHCP server, frame forwarded (switch learning) through LAN, demultiplexing at client
- DHCP client receives DHCP ACK reply
Client now has IP address, knows name & addr of DNS server, IP address of its first-hop router
![|259](http://verification.fengzhongzhihan.top/202406152237468.png)

### 6.6.2 ARP
- before sending HTTP request, need IP address of www.google.com:  DNS
- DNS query created, encapsulated in UDP, encapsulated in IP, encapsulated in Eth.  To send frame to router, need MAC address of router interface: ARP
- ARP query broadcast, received by router, which replies with ARP reply giving MAC address of router interface
- client now knows MAC address of first hop router, so can now send frame containing DNS query 
![|359](http://verification.fengzhongzhihan.top/202406152240604.png)
### 6.6.3 DNS
- IP datagram containing DNS query forwarded via LAN switch from client to 1st hop router
- IP datagram forwarded from campus network into Comcast network, routed (tables created by RIP, OSPF, IS-IS and/or BGP routing protocols) to DNS server
![](http://verification.fengzhongzhihan.top/202406152241572.png)

### 6.6.4 TCP connection
- to send HTTP request, client first opens TCP socket to web server
- TCP SYN segment (step 1 in TCP 3-way handshake) inter-domain routed to web server
- web server responds with TCP SYNACK (step 2 in TCP 3-way handshake)
- TCP connection established!
![|375](http://verification.fengzhongzhihan.top/202406152244993.png)

### 6.6.5 HTTP 
- HTTP request sent into TCP socket
- IP datagram containing HTTP request routed to www.google.com
- web server responds with HTTP reply (containing web page)
- IP datagram containing HTTP reply routed back to client
# 7 无线网络
## 7.1 总览
![|350](http://verification.fengzhongzhihan.top/202406171431439.png)
无线网络的组成
- 无线设备
	- 笔记本电脑，智能手机，物联网
	- 运行应用程序
	- 可以是固定的(非移动的)或移动的
		  无线并不总是意味着移动性！
- 无线基站
	- 通常连接到有线网络
	- 中继-负责在有线网络和其“区域”内的无线主机之间发送数据包
	- 例如，信号塔，802.11接入点(AP)
- 无线连接
	- 通常用于连接移动设备到基站，也用作主干链路
	- 多址协议协调链路访问
	- 各种传输速率和距离、频带

模式
- 基础设施模式
	- 基站将移动电话连接到有线网络
- 临时安排模式
	- 没有基站
	- 节点只能传输到链路覆盖范围内的其他节点
	- 节点组织成一个网络: 自己路由
	- ![|171](http://verification.fengzhongzhihan.top/202406171436193.png)


分类方法
![](http://verification.fengzhongzhihan.top/202405311437912.png)
基站
- 单跳 : wifl
- 多跳 : mesh net
无基站
- 单跳: bluetooth
- 多跳: manet vanet(汽车之间)

## 7.2 无线连接特点

信号强度降低: 无线电信号在通过物质传播时衰减(路径损失)
- (fd) ^ 2
多重路径传输: 无线电信号从地面反射出来，在稍微不同的时间到达目的地
![](http://verification.fengzhongzhihan.top/202406171440347.png)

来自其他来源的干扰: 许多设备共享的无线网络频率(例如2.4 GHz)(例如 WiFi、蜂窝电话、电机) : 干扰

信噪比: SNR( signal-to-noise ratio)
- 更大的信噪比-更容易从噪声中提取信号

SNR 与 BER(bit error rate) 的权衡
- 给定物理层: 增加功率-> 增加信噪比-> 降低误码率
- 给定信噪比: 选择满足误码率要求的物理层，提供最高的吞吐量
- 信噪比可能随着移动性而变化: 动态适应物理层(调制技术，速率)

![|287](http://verification.fengzhongzhihan.top/202405311441500.png)
- 可见在相同的误码率的情况下, 给定频率越高的信号, 要求的SNR就越高

隐藏终端问题
![](http://verification.fengzhongzhihan.top/202405311442308.png)
当终端A正在与AP通信时，终端C由于无法检测到终端A的通信，可能会尝试同时与AP通信，导致数据包冲突。

CDMA(code division multiple access): 
原理  (d1m1 + d2m2) m2 = d2 
- 其中d1,d2是数据位
- m1, m2是信息
- s1, s2两两正交

## 7.3 802.11(WIFI)
总结来说，WLAN 是一个涵盖所有无线局域网技术的广义术语，而 Wi-Fi 是基于 IEEE 802.11 标准的无线局域网技术的具体实现和品牌名称。Wi-Fi 是目前最常见和广泛使用的 WLAN 技术，但并不是唯一的 WLAN 解决方案。
### 7.3.1 概述
wireless host communicates with base station
	base station = access point (AP)
Basic Service Set (BSS) (aka “cell”) in infrastructure mode contains:
(ad hoc mode: hosts only)
- wireless hosts
- access point (AP): base station
![|325](http://verification.fengzhongzhihan.top/202405311450015.png)

主机: 必须与 AP 联系
- 扫描信道，侦听包含 AP 名称(SSID)和 MAC 地址的信标帧
- 选择与 AP 关联
- 然后可以进行认证
- 然后通常运行 DHCP 来获取在AP 子网中的 IP 地址

两种scanning方式
![|550](http://verification.fengzhongzhihan.top/202405311452934.png)

### 7.3.2 CSMA/CA

![](http://verification.fengzhongzhihan.top/202405311456562.png)
进一步减少冲突
idea: sender “reserves” channel use for data frames using small reservation packets
sender first transmits small request-to-send (RTS) packet to BS using CSMA
- RTSs may still collide with each other (but they’re short)
BS broadcasts (clear-to-send) CTS in response to RTS
CTS heard by all nodes
- sender transmits data frame
- other stations defer transmissions 

![|425](http://verification.fengzhongzhihan.top/202405311459990.png)

### 7.3.3 地址结构
![|600](http://verification.fengzhongzhihan.top/202405311500720.png)\
- 目的地
- 传输者
- AP


802.11 -> 802.3
![](http://verification.fengzhongzhihan.top/202405311501729.png)
![|475](http://verification.fengzhongzhihan.top/202405311504142.png)

# 8 网络安全
## 8.1 概述
cryptography : 密码学
ciphertext : 密码报文
plaintest : 明文

破解加密方式
- 密文攻击：Trudy可以分析密文
两种方法：
1. 暴力破解：搜索所有可能的密钥。
2. 统计分析。
- 已知明文攻击：Trudy拥有与密文相对应的明文。例如，在单字母替换密码中，Trudy确定了a, l, i, c, e, b, o等字母的对应关系。
- 选择明文攻击：Trudy可以为自己选择的明文获取相应的密文。
## 8.2 加密模式
**对称密钥加密**
![](http://verification.fengzhongzhihan.top/202405241021648.png)
- 例如在单密码破解模式中, key就是替换方式
**简单加密**
![|450](http://verification.fengzhongzhihan.top/202405241023718.png)
Encryption key: mapping from set of 26 letters to set of 26 letters
**更复杂点的加密**
Encryption key: n substitution ciphers, and cyclic pattern
key need not be just n-bit pattern


**数据加密标准** : DES(Data Encryption Standard)

**先进加密标准** : AES(Advanced Encryption Standard)
- brute force decryption (try each key) taking 1 sec on DES, takes 149 trillion years for AES 

**公共密钥算法** : Public Key Cryptography
- 加密和解密是不同的key
![|550](http://verification.fengzhongzhihan.top/202405241029604.png)
发给x, 则选择x公钥, x用自己私钥解密
- public encryption key known to all 
- private decryption key known only to receiver 
- m = KB-(KB+(m))

**RSA算法**
![|450](http://verification.fengzhongzhihan.top/202405241038996.png)
![|450](http://verification.fengzhongzhihan.top/202405241041711.png)
- 找两个大的质数p,q ; n  = pq , z = (p - 1)(q - 1)
- 找与z互质的e
- 找d 使得ed - 1 / z 整除
- 则public key : (n, e) private key (n, d)

神奇
- RSA中的指数运算计算密集。  
- DES至少比RSA快100倍。  
- 使用公钥加密来建立安全连接，然后建立第二个密钥——对称会话密钥——用于加密数据。  

会话密钥，KS。  
- Bob和Alice使用RSA交换一个对称会话密钥KS, 就使用对称密钥加密技术
## 8.3 认证
![|390](http://verification.fengzhongzhihan.top/202405241042995.png)

protocal 1 : Alice says “I am Alice”
protocal 2 : Alice says “I am Alice” in an IP packet containing her source IP address 
- Trudy can create a packet “spoofing” Alice’s address 
Protocol ap3.0: Alice says “I am Alice”  and sends her secret password to “prove” it. 
- playback attack: Trudy records Alice’s packet and later plays it back to Bob 
- 可使用时间戳解决
protocol ap4.0: to prove Alice “live”, Bob sends Alice nonce(随机数), R 
Alice must return R, encrypted with shared secret key
- 共享对称密钥很难实现

ap5.0: use nonce, public key cryptography 
- Trudy poses as Alice (to Bob) and as Bob (to Alice)
![|550](http://verification.fengzhongzhihan.top/202405241056516.png)

## 8.4 签名机制
类似于手写签名的加密技术：
	发送者（Bob）对文件进行数字签名：他是文件的拥有者/创建者。
	可验证、不可伪造：接收者（Alice）可以向他人证明文件必须是Bob签名的，且只有Bob能签名（包括Alice在内的任何人都不能伪造）。

简单的消息m的数字签名方法：
Bob使用他的私钥KB对消息m进行加密，创建“签名”消息，即KB-(m)。
![](http://verification.fengzhongzhihan.top/202405310845014.png)
suppose Alice receives msg m, with signature: m, KB-(m)
Alice verifies m signed by Bob by applying Bob’s public key KB to KB(m) then checks KB(KB(m) ) = m.
If KB(KB(m) ) = m, whoever signed m must have used Bob’s private key

信息简化(message digest)
![|436](http://verification.fengzhongzhihan.top/202405310848619.png)
Hash function properties:
	many-to-1
	produces fixed-size msg digest (fingerprint)
	given message digest x, computationally infeasible to find m such that x = H(m)
- but given message with given hash value, it is easy to find another message with same hash value: 

常用的hash算法
- MD5
- SHA-1

**Digital signature = signed message digest***
发送者和接收者
![](http://verification.fengzhongzhihan.top/202405310850429.png)
- Bob加密了H文件 , Kb-(H(m))
- Alice收到了m , 用同样Hash, 认证了H文件, 数据完整性


但是有签名机制还是解决不了问题, 还是会出现伪造的情况
- Trudy sends to Pizza Store her public key, but says it’s Bob’s public key
- Trudy signed the message with her own signatrue

Public key Certification Authorities (CA)
实体（个人、网站、路由器）向证书颁发机构（CA）注册其公钥，并向CA提供“身份证明”。  
	CA创建证书，将身份E与E的公钥绑定。  
	包含E的公钥的证书由CA进行数字签名：CA声明“这是E的公钥”。
![](http://verification.fengzhongzhihan.top/202405310855331.png)
- KB+ 与 identity 绑定
- KCA- 签名, 用KCA+解绑即可获得KB+

when Alice wants Bob’s public key:(获取公钥的方法)
	gets Bob’s certificate (Bob or elsewhere)   (KCA-)
	apply CA’s public key to Bob’s certificate, get Bob’s public key

## 8.5 加密邮件
confidential(机密性)
- 对称加密
![|550](http://verification.fengzhongzhihan.top/202405310903258.png)
![|350](http://verification.fengzhongzhihan.top/202405310903699.png)
- 用KB+锁了KS
- 用KS锁了m

integrity and authentication(完整性和认证)
- hashing + public key
![](http://verification.fengzhongzhihan.top/202405310905683.png)
- 用KA-锁了Hm
- 把m发给bob

confidential, integrity and authentication(三者综合)
![](http://verification.fengzhongzhihan.top/202405310906731.png)
- 用KA-锁了Hm
- 用Ks锁了KA-Hm 和 m
- 用KB+锁了Ks


## 8.6 TLS
Transport-layer security (TLS)
provides:
- confidentiality: via symmetric encryption 
- integrity: via cryptographic hashing(MAC)
- authentication: via public key cryptography

组成
1. handshake: Alice, Bob use their certificates, private keys to authenticate each other, exchange or create shared secret
2. key derivation: Alice, Bob use shared secret to derive set of keys
3. data transfer: stream data transfer: data as a series of records
	- not just one-time transactions
4. connection closure: special messages to securely close connection
![](http://verification.fengzhongzhihan.top/202406061442621.png)
![|450](http://verification.fengzhongzhihan.top/202405310912381.png)
Message Authentication Code(MAC) : 
four keys:
Kc :  encryption key for data sent from client to server
Mc : MAC key for data sent from client to server
Ks :  encryption key for data sent from server to client
Ms : MAC key for data sent from server to client
- keys derived from key derivation function (KDF), takes master secret and (possibly) some additional random data to create new keys


**加密数据**
回顾：TCP提供数据字节流抽象。
问：我们可以在写入TCP套接字时对数据进行流内加密吗？
答：MAC（消息认证码）应放在哪里？如果放在末尾，则在所有数据接收完毕并连接关闭之前没有消息完整性！
解决方案：
- 将流分割成一系列“记录”。
- 每个从客户端到服务器的记录都携带一个MAC，使用Mc创建。
- 接收者可以在每个记录到达时对其进行处理。
![|450](http://verification.fengzhongzhihan.top/202406061439861.png)

**如果有人攻击怎么办?**
攻击方式
	re-ordering: man-in middle intercepts TCP segments and reorders (manipulating sequence  in unencrypted TCP header)
	replay
solutions:
- use TLS sequence numbers (data, TLS-seq-# incorporated into MAC)
- use nonce

**如果有人截断怎么办?**
truncation attack: 
- attacker forges TCP connection close segment
- one or both sides thinks there is less data than there actually is 
solution: record types, with one type for closure
- type 0 for data; type 1 for close

![|475](http://verification.fengzhongzhihan.top/202405310931654.png)


“密码套件”: 可用于密钥生成、加密、 MAC、数字签名的算法, TLS: 1.3(2018) : 比 TLS 1.2(2008)更有限的密码套件选择

1RTT
![|700](http://verification.fengzhongzhihan.top/202405310934751.png)

0RTT
![](http://verification.fengzhongzhihan.top/202405310937674.png)

过程
- **客户端问候（Client Hello）**：客户端向服务器发送一个包含客户端支持的 TLS 版本、加密算法、压缩方法及一个随机数的消息。
- **服务器问候（Server Hello）**：服务器回应一个包含服务器选择的 TLS 版本、加密算法、压缩方法及一个随机数的消息。
	- **服务器证书（Server Certificate）**：服务器向客户端发送数字证书，以验证服务器的身份。
	- **密钥交换（Server Key Exchange）（可选）**：如果选择的加密算法需要额外的信息（如 Diffie-Hellman 参数），服务器会发送这些信息。
- **服务器问候完成（Server Hello Done）**：服务器验证身份, 生成key, 发送一个表明握手阶段结束的消息。
- **客户端密钥交换（Client Key Exchange）**：客户端生成一个预主密钥（pre-master secret），用服务器的公钥加密后发送给服务器。
- **完成握手（Handshake Finished）**：客户端和服务器分别发送一条已加密的消息，表明握手过程已完成，握手阶段结束。