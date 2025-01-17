#  网络全局：

### 1.七层和四层模型

**实际网络是按照四层模型进行构建的，七层模型只是一个理论上的参考模型**

![七层与四层](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\七层与四层.jpg)

![image-20220228214950173](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220228214950173.png)

<u>**路由器位于网络层**</u>

<u>**交换机位于数据链路层**</u>   

### 2.ping命令

ping命令是**基于网络层的ICMP协议**的一个**应用层命令**，它用来确定本地主机是否能与另一台主机成功交换数据包(发送与接收)。

ping的基本原理是

ping命令是基于ICMP 协议开发的，ICMP是一种基于IP协议的控制协议。ping程序在使用时，会组装成一个IP报文。报文的目的地址为ping 的目标地址，源地址就是发送ping命令时的主机地址，按照ICMP报文格式在IP报文后面填上更多数据，然后IP报文会通过ARP协议，将源地址和目的地址翻译成MAC地址，经过数据链路层，把报文被传输出去。当报文到达目的地址之后，目的地址所对应的主机也按照ICMP协议进行应答。

命令格式：ping 主机名/ping 域名/ping IP地址 

ping不通:同网段/跨网段

![ping](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\ping.jpg)



### 3.DNS

将主机域名转换为ip地址，属于应用层协议，使用UDP传输

##### 3.1 DNS为何采用UDP协议

因为UDP协议更快，DNS底层使用UDP协议能使域名解析时间更短，UDP不需要建立连接，减小DNS服务器的负担。

##### 3.2 DNS解析过程

主机名.次级域名.顶级域名.根域名www.baidu.com.root

(1). 首先查找浏览器也就是用户主机上的DNS缓存列表(维护一张域名与IP的对应表)，如果有记录，那么直接返回对应IP地址，若没有；

(2). 查找用户主机上域名解析文件hosts文件，如果有记录，那么返回对应的IP地址，若没有；

(3). 查找本地DNS服务器，本地DNS服务器先查找自己的缓存记录，如果有记录，返回对应的IP地址，若没有，本地DNS服务器向根域名服务器发起请求；

(4). 根域名服务器收到请求后，查看是(.com)顶级域名，于是返回(.com)顶级域名服务器的IP地址给到本地DNS服务器；

(5). 本地DNS服务器收到回复后，向(.com)顶级域名服务器发起请求；

(6). (.com)顶级域名服务器收到请求后，查看是(.baidu.com)次级域名，于是返回(.baidu.com)次级域名服务器的IP地址给到本地DNS服务器；

(7). 本地DNS服务器收到回复后，向(.baidu.com)次级域名服务器发起请求；

(8). (.baidu.com)次级域名服务器收到请求后，查看是自己管理的域名，于是查找域名和IP地址映射表，把所查找域名([www.baidu.com](http://www.baidu.com))对应的IP地址返回给本地DNS服务器；

(9). 本地DNS服务器收到回复后，向用户主机回复所查找域名对应的IP地址，并把记录写入本地DNS服务器的缓存里；

(10). 用户主机收到回复后，使用IP地址访问网站，并把记录写入自己的DNS缓存列表中。     



### 4.IP/MAC地址

MAC地址是一个硬件地址，用来定义网络设备的位置，主要由数据链路层负责。

IP地址是IP协议提供的一种统一的地址格式，为互联网上的每一个网络和每一台主机分配一个逻辑地址，以此来屏蔽物理地址的差异。



### 5.各层的典型协议

  TCP/IP 4层模型：网（链路层/网络接口层）、网、传、应			——编写程序常用

​    应用层：http、ftp、nfs、ssh、telnet。。。

​    传输层：TCP、UDP

​    网络层：IP、ICMP、IGMP

​    链路层：以太网帧协议、ARP

![image-20220904203055613](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220904203055613.png)









# 传输层：TCP

### 0.TCP、UDP头部

TCP头部：TCP 首部长度较长，会有一定的开销，首部在没有使用「选项」字段时是 `20` 个字节，如果使用了「选项」字段则会变长的。

UDP头部：UDP 首部只有 8 个字节，并且是固定不变的，开销较小。

![TCP头部](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\TCP头部.png)

![UDP首部](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\UDP首部.png)

### <u>1.传输层TCP/UDP的区别和适用场景</u>

区别：(1)(有无连接)TCP是有连接的协议，发送数据之前要先建立连接，UDP是无连接的协议

(2)(可靠性)TCP提供交付保证，传输过程中数据丢失会重传，TCP更加可靠。而UDP不提供任何交付保证，数据传输不可靠。

(3)(有序性)TCP会保证消息的有序性，即使到达的客户端顺序不同，TCP也会排序。而UDP不提供有序保证。 

(4)(数据边界)TCP不保证数据边界，而UDP一次交付一个完整的报文，既不合并也不拆分，保证数据边界。

(5)TCP使用滑动窗口机制实现流量控制，通过动态改变拥塞窗口大小进行拥塞控制，而UDP没有流量控制和拥塞控制。

(6)(头部开销不同)TCP数据包的包头最小长度是20字节，UDP数据报包头只有8个字节

(7)(服务对象)TCP只能一对一的进行通信，而UDP可以一对一、一对多、多对多

TCP提供可靠的服务，适用于通讯质量要求高的场景，一般文件传输都是TCP协议；UDP传输速度快，适用于实时性要求高，且丢失一两个数据包也不会造成多大问题的场景，比如QQ语音、视频会议等。

### <u>2.TCP如何保证可靠(拥塞、流量控制、滑动窗口)</u>

(TCP为什么可靠:校验和、序列号和确认机制、连接管理(3握4挥)、重传机制、滑动窗口和流量控制、拥塞控制)

2.0 校验和：  (位于TCP报文头)                                                                                                                                                                                   通过检查校验和的方式，接收端可以检测出收到的数据是否有异常，如有异常会将这个数据丢弃，发送端重新发送。TCP在计算校验和会在TCP首部加上12字节的伪首部(伪首部中包含主机ip地址，可以判断数据是从哪发来的)，检验和总共计算3部分：TCP首部、TCP数据、TCP伪首部

2.1 序列号与确认应答:                                                                                                                                                             TCP传输时会把每个字节的数据都进行编号，使用序列号可以将收到的数据按照序列号排序，去掉重复数据。发送一方每发送一个数据给接收方，接收方收到数据后都会回一个ASK数据包，进行确认应答，这个ASK数据包中包含一个确认号ask(小)，表示ask号之前的数据我都收到了，你下一次从ask号开始给我发送数据。

2.2 连接管理机制就是三次握手四次挥手

2.3 重传机制：(这里只答超时重传就好应该)

超时重传：                                                                                                                                                                                  发送方在发送数据时，会开启一个计时器，设定超时重传时间为RTO，如果RTO时间到了，也没有收到接收方发回的确认包，就认为数据包丢失了，重新发送数据包，一直重发直到达到重发上限或收到确认包为止。(RTO>RTT发出数据包的往返时间，RTO是我们使用每次测得的RTT样本，计算加权平均往返时间RTTs，RTO设置的应该略大于RTTs)

快速重传：                                                                                                                                                                                     发送方收到三个相同的ACK数据包时（这个ACK数据包是接收端接收到发送端上上次发的数据包后生成的），它会知道接收方没有收到我上次发给它的数据，于是会在定时器过期之前（RTO时间之前），重新发送之前丢失的数据包。（这样就不用再等到RTO时间了，所以叫快速重传）

**2.4 设置滑动窗口和流量控制：**

滑动窗口设置：                                                                                                                                                                             如果发送端每发送一个数据包都要等待一个应答数据包的话，当数据包的往返时间较长时，通信效率会比较低，发送端可以设定滑动窗口，窗口大小就是在无需等待确认包的情况下还能继续发送的最大数据量(发送多个数据包直到达到最大窗口值时，只回一个应答数据包即可，累计确认模式)，这样做可以提高数据传输效率。发送方的窗口大小由接收方根据自己当前所能接受字节数来确定。

**流量控制：**                                                                                                                                                                           如果发送方不考虑接收方的接收能力，一直向接收方发送数据，可能导致接收方的缓冲区满了无法再接收数据，造成大量的数据丢包，引发重传机制。然后在重传过程中，若接收方的接收缓冲区情况仍未好转，则会将大量的时间浪费在重传数据上，降低传送数据的效率。所以通过滑动窗口进行流量控制，接收方告诉发送方自己的窗口大小，来控制发送方所发的数据量。

**2.5拥塞控制：**                                                                                                                                                                                流量控制主要是接收方告诉发送方它的接收窗口大小，来控制发送窗口大小。**拥塞控制**是防止过多的数据注入到网络中造成网络资源过载(路由器、交换机)，流量控制只考虑发送端和接收端，拥塞控制是从网络链路全局来考虑的。

拥塞情况的判断: 当收到三个相同的ACK应答表示可能要出现拥塞，当重传定时器超时了说明已经发生了拥塞。

TCP通过维持一个拥塞窗口CWND的方法进行拥塞控制：                                                                                                           拥塞窗口的大小取决于网络的拥塞程度，拥塞窗口会根据网络的拥塞情况动态变化。                                                                                                                                                                                                        发送方的窗口大小取决于接收方公告的接收窗口（滑动窗口）和拥塞窗口(网络的拥塞情况)。                                                                                                                                              真正的发送窗口值 = Min(对方窗口（滑动窗口），拥塞窗口值)

![拥塞控制](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\拥塞控制.jpg)

![image-20220904223832939](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220904223832939.png)

拥塞控制主要是四个算法：对应上图 

(1)慢启动：慢启动不是说拥塞窗口cwnd的增长速度慢(指数增长)，而是指TCP最初设置拥塞窗口初值为1。                                                                                                   

思路：不要一开始就发送大量的数据，先探测一下网络的拥塞程度，也就是说由小到大逐渐增加拥塞窗口的大小。拥塞窗口大小是以字节为单位的。   (1，2，4，8，16，17，18...) （每收到一个ACK就把cwnd加1，所以从宏观上看每一轮都是呈指数上升）    

为了防止cwnd增长过大引起网络拥塞，设置一个慢开始门限（ssthresh状态变量）,当超过这个门限值时，会进入“拥塞避免算法”                                                                                                   (2)拥塞避免：在拥塞避免阶段将拥塞窗口控制为按线性规律增长，这样可以让网络比较不容易出现拥塞。                                                                                                                               思路：让拥塞窗口cwnd缓慢地增大，即每经过一个往返时间RTT就把发送方的拥塞控制窗口加一。（每一传输轮次cwnd只加1）                                                                                                                                                                                                                          (3)快重传：快重传要求接收方在收到一个失序的报文段后就立即发出重复确认(为的是使发送方及早知道有报文段没有到达对方)而不是等到自己发送数据时捎带确认。**快重传算法规定，**发送方只要一连收到三个重复确认ACK就应当立即重传对方尚未收到的报文段，而不必继续等待设置的重传计时器时间到期。                                                                                                (4)快恢复：当发现超时说明网络拥塞，重回到慢启动阶段发送数据。而收到3个相同的ACK，说明当前网络还没有拥堵，从快恢复状态重新发送数据，发送方将慢开始门限值ssthresh调整为当前窗口的一半，拥塞窗口大小cwnd调整为新的ssthresh（也有的算法是将cwnd调整为ssthresh后再加3，加3是因为快重传机制收到了3个ACK，说明有3个报文已经离开了网络），之后继续采用拥塞避免算法。



### 3.TCP如何保证有序

主机每次发送数据，TCP会给每个数据包分配一个序列号并且在一个特定的时间内等待接收方对分配的这个序列号进行确认，如果发送主机在一个特定时间内没有收到接收方的确认，发送主机会重传这个数据包。接收方利用序列号对接收的数据进行确认，方便检测对方发送的数据是否有丢失或者乱序问题，接收方收到已经顺序化的数据后，就将这些数据按正确的顺序重组成数据流传递到上层进行处理。

### 4. TCP滑动窗口和重传机制

1. 设置滑动窗口有两个目的：                                                                                                                                                第一，如果发送端每发送一个数据包都要等待一个应答数据包的话，当数据包的往返时间较长时，通信效率会比较低，发送端可以设定滑动窗口，窗口大小就是在无需等待确认包的情况下还能继续发送的最大数据量，然后使用累计确认模式提高数据传输效率（每次收到序列号x+1表示接收方已经接受到了x之前的包）。发送方的窗口大小由接收方根据自己当前所能接受字节数来确定。                                                                                                                     第二，如果发送方不考虑接收方的接收能力，一直向接收方发送数据，则可能导致接收方的缓冲区满了而无法再接收数据，造成大量的数据丢包丢失，引发重传机制。在重传的过程中，若接收方的接收缓冲区情况仍未好转，大量的时间会浪费在重传数据上，降低传送数据的效率。所以通过设置滑动窗口实现流量控制，接收方告诉发送方自己的窗口大小，来控制发送方所发的数据量。

   

2. 重传机制包括超时重传和快速重传：                                                                                                                              超时重传：                                                                                                                                                                                  发送方在发送数据时，会开启一个计时器，设定超时重传时间为RTO，如果RTO时间到了，也没有收到接收方发回的确认包，就认为数据包丢失了，重新发送数据包，一直重发直到达到重发上限或收到确认包为止。(RTO>RTT发出数据包的往返时间，RTO是我们使用每次测得的RTT样本，计算加权平均往返时间RTTs，RTO设置的应该略大于RTTs)

   快速重传：                                                                                                                                                                                     超时重传还没时间还没到，发送方收到三个相同的ACK数据包时，它会知道接收方没有收到我之前发给它的数据，于是会在定时器过期之前，重新发送之前丢失的数据包。

为什么次数是三：两次可能是网络延迟，经验值三次

### 5.滑动/拥塞窗口区别

**滑动窗口：**是接收数据端使用的窗口大小，用来告知发送端接收端的缓存大小，以此可以控制发送端发送数据的大小，从而达到流量控制的目的。 

**拥塞窗口：**防止过多的数据注入到网络中，避免网络中的路由器或链路过载。拥塞控制是一个全局性的过程，涉及到所有的主机、路由器，以及与降低网络传输性能有关的所有因素。

**滑动窗口与拥塞窗口的区别：**滑动窗口取决于接收端的缓存大小，拥塞窗口取决于当 前网络的负载能力。滑动窗口位于传输层（区别于数据链路层的），拥塞控制更关注网络层。

### <u>6.三次握手过程</u>

![三次握手](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\三次握手.jpg)

根据收发数据包号来说，先说收，然后检查，在设置，再说发，最后是状态。基本就是SYN、ACK、seq、ack

1) 第一次握手，客户端会组建一个数据包，设置 SYN 标志位，表示该数据包是用来建立同步连接的。同时生成一个随机数x，作为发送数据的起始包号，向服务器发送数据包，然后客户端进入`SYN-SENT`状态。
2) 第二次握手，服务器端收到数据包，检测到了 SYN 标志位，知道客户端在请求建立连接。服务器端也会组建一个数据包，并设置 SYN 和 ACK 标志位，表示收到了客户端发来的数据包，同时我也要和客户端建立连接。服务器生成一个随机数 y，作为起始包号，再将客户端数据包序号x加1，作为确认号(ack)，将这个数据包发出，进入`SYN-RECV`状态。

3) 第三次握手，客户端收到数据包，检测到了SYN和ACK标志位，知道服务器收到了我之前发送的数据包，并且服务器也请求建立连接。客户端会先检测确认号(ack)，看它的值是否为 x+1，如果是就说明客户端到服务器的连接建立成功。

之后，客户端继续组建数据包，并设置ACK标志位，表示收到了服务器发来的数据包。将刚才服务器发来的数据包序号y加1，作为确认号(ack)。客户端将数据包发出，进入`ESTABLISED`[ɪˈstæblɪʃ] 状态，表示连接已经成功建立。

4) 服务器端收到数据包，检测到了ACK 标志位，知道客户端收到了我之前发送的数据包。服务器会检测确认号（ack），看它的值是否为y+1，如果是就说明连接建立成功，服务器也进入`ESTABLISED`状态，接下来就可以收发数据了。



### <u>7.为什么两次/四次不行</u>

两次：TCP为了实现可靠数据传输，要求通信双方，都必须维护一个数据包序号，标识发送出去的数据包中，哪些是已经被对方收到的。**三次握手的过程就是通信双方相互告知对方自己的数据包序号起始值，并确认对方已经收到了这个数据包序号的过程，如果只是两次握手，最多只能是主动发起连接的一方的起始序号能被确认，另一方得不到确认。**

四次：三次握手在理论上已经可以建立可靠连接，所以不需要使用更多的通信次数

### 8.什么是SYN flood，防止

(什么情况下会出现半开连接，如何解决?我认为这里说的出现半连接就是SYN攻击了)

（SYN Flood是互联网上最原始、最经典的DDoS攻击之一。它利用了TCP协议的三次握手机制，攻击者通常向服务器发送海量的变源IP地址或变源端口的TCP SYN报文，服务器响应了这些报文后就会生成大量的半连接，当系统资源被耗尽后，服务器将无法提供正常的服务。）

SYN攻击就是客户端在短时间内伪造大量不存在的IP地址，并向服务器端不断发送SYN数据包，服务器端收到SYN数据包后，会发送携带SYN和ACK标志位的应答数据包，进入SYN_RCVD(半连接)状态，等待客户端确认，因为客户端所发SYN的源IP地址都是未知的，所以服务器得不到应答，服务器端就会不断重发直到超时，这些伪造的IP发送的SYN数据包会长时间占用服务器的半连接队列，如果队列满了，正常客户端的请求就会被服务器拒绝。

检测 SYN 攻击非常的方便，当你在服务器上看到大量的半连接状态时，特别是源IP地址是随机的，基本上可以断定这是一次SYN攻击。在 Linux/Unix上可以使用系统自带的netstats命令来检测 SYN 攻击。

```shell
netstat -n -p TCP | grep SYN_RECV
```

常见的防御SYN攻击的方法：

(1)减少SYN+ACK的重传次数：SYN攻击的基本原理就是耗尽主机的半开放连接资源，当服务器受到SYN攻击时，会有大量的TCP连接处于半连接状态，当重传次数达到上限时，就会断开这个连接，我们可以减少这个上限值，加快处于半连接状态的TCP连接被释放                                                                       (2)增加最大半连接数：SYN攻击会占用半连接队列，所以我们增加半连接队列的大小。(修改Linux内核参数，涉及三个变量tcp_max_syn_backlog还有两个用于增大全连接队列的参数somaxconn和backlog)

### <u>9.TCP半连接队列和全连接队列</u>

服务器会为每个监听套接字维护一个半连接队列和全连接队列。

半连接队列：半连接队列中保存着完成一次握手的连接项。

半连接：是服务器第一次收到客户端的SYN，并发送SYN+ACK后，处于SYN_RCVD状态，此时双方还没有完全建立其连接，就是半连接状态。

全连接队列：完成三次握手的连接项会从半连接队列移到全连接队列中，处于 ESTABLISHED 状态。

### 10.心跳包

心跳包是在网络中，客户端和服务器端每隔一段时间发送一些简单的信息，告诉对方自己状态的一种机制。在TCP协议里的保活机制，就是这种心跳包的机制，使用setsockopt()函数设置套接字的SO_KEEPALIVE选项，就会开启这一端的TCP保活机制。

### 11.TCP连接建立，一端出现故障(保活机制)

TCP连接两端一个突然断连，另一端如何感知？

TCP中有一个保活机制，使用保活选项的一端一般都是服务器端，如果客户端也想知道对方是否已经断开连接，也可以使用这个选项。服务器每收到一次客户的数据，就重新设置保活计时器，时间的设置通常是两个小时。若两个小时都没有收到客户端的数据，服务端就发送一个探测报文段，以后则每隔 75秒钟发送一次。若连续发送10个探测报文段后仍然无客户端的响应，服务端就认为客户端已经不在线了，接着就关闭这个连接。(系统内核将错误信息通知给上层应用程序。)

### <u>12.四次挥手</u>

<img src="G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\四次挥手.jpg" alt="四次挥手" style="zoom: 50%;" />

第一次挥手：客户端向服务器发送数据包，并设置FIN标志位，表示请求断开连接，发送完毕后客户端进入`FIN_WAIT_1`状态。

第二次挥手：服务器收到数据包后，检测到了FIN标志位，于是向客户端发送数据包，并设置ACK标志位，告诉客户端我收到了你的数据包，进入`CLOSE_WAIT`状态。客户端收到数据包，检测到了ACK标志位，知道服务器收到了我刚才发的请求断开连接的数据包，然后进入`FIN_WAIT_2`状态。

第三次挥手：服务器发送完数据后，主动向客户端发送数据包，并设置FIN标志位，表示服务器也要断开连接，进入`LAST_ACK`状态。

第四次挥手：客户端收到数据包以后，检测到FIN标志位，知道服务器想要断开连接，于是再向服务器发送ACK包，告诉它我收到了你的数据包，你断开连接吧。然后进入`TIME_WAIT`状态，在`TIME_WAIT`状态等待2MSL时长后进入`CLOSED`状态。服务器收到客户端的ACK包后，就断开连接，关闭套接字，进入`CLOSED`状态。客户端等待2MSL时间后，也断开连接，关闭套接字，进入`CLOSED`状态。

### 13. 为什么四次挥手不是三次

因为TCP支持半关闭状态（TCP是全双工通信，每个方向都要关闭），所以第二次挥手和第三次挥手不能合并在一起，半关闭状态就是原本可以互相通信的双方，其中一方主动断开连接，它只能收数据不能发数据(半关闭不是关闭连接，关闭的是socket的写缓冲区，读缓冲区还是开放的)（不能写数据了，只能最后收到对端的FIN后再发一个ACK），而另一方可能还在传输数据，需要等待数据传输完毕后再断开连接。

举个例子：A 和 B 打电话，通话即将结束后，A 说“我没啥要说的了”，B回答“我知道了”，但是 B 可能还会有要说的话，A 不能要求 B 跟着自己的节奏结束通话，于是 B 可能又巴拉巴拉说了一通，最后 B 说“我说完了”，A 回答“知道了”，这样通话才算结束。



### 14. 2MSL时长

Linux环境下2MSL大约60s。TIME_WAIT—2MSL时长(40s)—CLOSED(关闭状态) ，2MSL一定发生在主动关闭连接一端，因为它服务于最后一个ACK，最后一个ACK是主动关闭连接一端发送的。  

### <u>15. TIME_WAIT(2MSL)的原因意义</u>

什么是MSL以及等2MSL时长的意义(TIME_WAIT状态意义)：

MSL是指最大报文段寿命，它是报文在网络上存在的最长时间，超过这个时间报文将被丢弃。

原因1：防止旧连接的数据包出现在本次连接中。如果服务端在关闭连接前传输的报文因为网络延迟了而没有到达客户端，这时如果没有2msl等待时间而是直接关闭连接，那么之后相同端口的TCP连接被复用后(相同端口重新建立TCP连接)，之前被延迟的过期报文可能会被客户端接收，这时就会产生数据错乱等严重的问题。所以，TCP 就设计出了这么一个机制，经过 `2MSL` 这个时间，**足以让两个方向上的数据包都被丢弃，使得原来连接的数据包在网络中都自然消失，再出现的数据包一定都是新建立连接所产生的。**

​                                                                                                                      

原因2：是让主动关闭方等待足够的时间以确保最后的ACK能让被动关闭方收到，帮助它正常关闭。主动关闭一方发送最后一个ACK时，如果当时网络不可靠会导致最后的ACK丢失，主动方如果没有等待2MSL，而直接进入CLOSED状态，它就失去了当前状态的上下文，只能回复一个RST操作，就导致被动关闭方出现错误。如果主动方等待2MSL，在等待过程中，被动方没有收到最后一个ACK，它还会重新发送FIN报文给主动方，主动方收到FIN后会再次发送ACK，使被动方可以进入正常的CLOSED状态，最后他们都正常关闭了。

### 16.大量TIME_WAIT危害及优化

##### 1.危害：

如果服务器处于time_wait状态，说明是由服务器方主动发起断开请求的。                                                                                                                       过多的 TIME-WAIT 状态主要的危害有两种：                                                                                                                                                                         第一是占用自动关闭方的内存资源；

第二是占用自动关闭方的端口资源的占用：一个TCP连接至少消耗一个本地端口，端口资源是有限的(一般可以开启的端口为 32768～61000，也可以通过如下参数设置指定net.ipv4.ip_local_port_range)，如果服务端TIME_WAIT状态过多，占满了所有端口资源，则会导致无法创建新连接。

这种2MSL等待的另一个结果是这个TCP连接在2MSL等待期间，定义这个连接的插口（客户的IP地址和端口号，服务器的IP地址和端口号）不能再被使用。这个连接只能在2MSL结束后才能再被使用。

##### 2.优化：设置端口复用

可以通过设置内核参数复用处于TIME_WAIT的套接字为新的连接所用。（使用setsockopt()设置socket描述符的选项SO_REUSEADDR为1，表示允许创建端口号相同但IP地址不同的多个socket描述符）

在server的TCP连接没有完全断开之前不允许重新监听是不合理的。因为，TCP连接没有完全断开指的是connfd（127.0.0.1:6666）没有完全断开，而我们重新监听的是lis-tenfd（0.0.0.0:6666），虽然是占用同一个端口，但IP地址不同，connfd对应的是与某个客户端通讯的一个具体的IP地址，而listenfd对应的是wildcard address。解决这个问题的方法是使用setsockopt()设置socket描述符的选项SO_REUSEADDR为1，表示允许创建端口号相同但IP地址不同的多个socket描述符。

也就是当server主动断开连接时等2MSL是不合理的（若此时打开新的server就会提示端口被占用），解决这一问题的办法就是端口复用

在server代码的socket()和bind()调用之间插入如下代码：

```cpp
int opt = 1;	// 设置端口复用。
setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (void *）&opt, sizeof(opt));
//成功0，失败-1
```



### 17.大量close_wait的原因

有什么解决方法？                                                                                                                     close_wait状态是在TCP四次挥手的时候收到FIN但是没有发送自己的FIN时出现的，服务器出现大量close_wait状态的原因有两种：一种是服务器内部业务处理占用了过多时间，都没能处理完业务，还有数据需要发送；另一种是服务器的业务逻辑有问题，没有执行close()方法                                                                                                                                                                                                                                           (可能的问题：服务器的父进程派生出子进程，子进程继承了socket，收到FIN的时候子进程处理但父进程没有处理 该信号，导致socket的引用不为0无法回收)                                                                                                                                                                                                                               处理方法： 停止应用程序 修改程序里的bug

### <u>18.TCP粘包/拆包的原因、解决</u>

一个完整的业务可能会被TCP拆分成多个包进行发送，这是**拆包**（原因：数据包的长度大于socket发送缓冲区），也有可能把多个小的包封装成一个大的数据包发送，这是**粘包**。

出现粘包的原因：

从发送方看：由于TCP需要尽可能高效和可靠，所以TCP协议默认采用Nagle [ˈneɪgəl]算法，以合并相连的小数据包，再一次性发送，以达到提升网络传输效率的目的。这个合并过程就是在发送缓冲区中进行的，也就是说数据发送出来它已经是粘包的状态了。但是接收方并不知道发送方合并数据包，而且数据包的合并在TCP协议中是没有分界线的，所以这就会导致接收方不能还原其本来的数据包。
 从接受方看：TCP是基于“流”的。网络传输数据的速度可能会快过接收方处理数据的速度，这时候就会导致，接收方在读取缓冲区时，缓冲区存在多个数据包。在TCP协议中接收方是一次读取缓冲区中的所有内容，所以不能反映原本的数据信息。（放数据的速度 > 应用层拿数据速度）

解决办法：

(1)可以考虑格式化数据，就是在数据包的包尾添加空格或回车之类的特殊符号进行分割 （自定义协议，添加包头包尾）

(2)消息定长发送，发送数据时，把这个数据包的长度信息一起发送过去，接收方根据这个长度信息，可以判断数据的开始和结束位置

### <u>19.UDP如何保证可靠</u>

UDP是传输层协议，仅提供最基本的数据传输功能，可以考虑在UDP上层的应用层来模仿TCP的可靠性传输，比如：

- 添加seq/ack机制(添加序号和确认机制)，确保数据可以有序不重复的发送到对端。
- 添加发送和接收缓冲区和超时重传机制，解决数据包丢失问题。

(没收到ack的数据包会放在发送缓冲区,如果超时就重传,udp是没有缓冲区的)

### 20.如何唯一确定一个TCP连接

TCP四元组可以唯一确定一个连接，四元组包括:源地址、源端口、目的地址、目的端口。

### 21.TCP与Http的keep-alive

Http的Keep-Alive，是由应用层(用户态)实现的，称为Http长连接。

TCP的Keepalive，是由TCP层(内核态)实现的，称为TCP的保活机制。

HTTP是基于TCP传输协议实现的，客户端与服务端要进行HTTP通信前，需要先建立TCP连接，然后客户端发送HTTP请求，服务端收到后返回响应，(至此「请求-应答」的模式就完成了)，再释放TCP连接。如果一次连接只能请求一次资源，就称为**短连接**，**长连接**是一次HTTP请求过后，不断开TCP连接，继续使用这个TCP连接来发送和接收多个HTTP请求/应答，避免了连接建立和释放的开销，HTTP长连接的特点是，只要任意一端没有明确提出断开连接，则保持TCP连接状态。

### <u>22.socket通信流程</u>

先解释下什么是socket套接字：socket是在应用层和传输层之间的一个抽象层，它本质上是编程接口(API)，它把TCP/IP层复杂的操作抽象为几个简单的接口供应用层调用来实现进程在网络中通信。(TCP/IP只是一个协议栈，必须要具体实现，同时还要提供对外的操作接口（API），这就是Socket接口。通过Socket,我们才能使用TCP/IP协议。)

![socket](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\socket.jpg)

![image-20220303214858949](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220303214858949.png)

服务器端：

(1)服务器端调用**socket()**函数，根据IP地址(IPV4、IPV6)、套接字类型(数据报套接字、数据流套接字)、传输协议(TCP、UDP)来创建一个用于监听的套接字。 

(2)服务器端创建完套接字以后，调用**bind()**函数将创建出来的套接字与服务器一个有效的IP地址和端口号进行绑定（通过sockaddr地址结构体），这样流经该IP地址和端口的数据才会交给套接字处理。

(3)服务器端调用**listen()**函数让套接字处于被监听状态，等待新的客户端请求到来，并通过backlog参数，设置可以同时和服务器建立连接的客户端的上限数。  

(4)服务器端调用**accept()**函数阻塞等待，直到接收到客户端的连接请求才解除阻塞，accept()函数会返回一个新的用于和客户端通信的已连接套接字。

(5)接下来就是接收到客户端连接以后，和客户端进行通信，调用write()和read()函数进行数据的读写。

客户端：

(1)客户端也调用**socket()**函数创建一个用于通信的套接字。                                                                             (2)客户端调用**connect()**函数，根据服务器IP地址和端口号去尝试连接服务器。调用connect函数将激发TCP的三次握手过程，而且仅在连接建立成功或出错时返回。                                                                                                        (3)连接成功以后，客户端就可以和服务器通信，调用write()和read()函数进行数据的读写。

### 23.socket与三次握手对应关系



### 24.close()和shutdown()区别

进程一般都是调用close()或shutdown()来关闭连接。close()函数表示完全关断，它是一种比较粗暴的关闭方式，既不可以发数据也不可以接收数据，而调用shutdown()，是一种比较优雅的关断方式，它可以控制只关闭一个方向的连接(读数据方向或写数据方向)，shutdown函数的第二个参数可以设置，关闭连接的读数据还是写数据，或是都关闭。



举一个具体的情景：我们在进行四次挥手的时候，主动关闭方先调用close()。关闭自己的读写缓冲区，被动关闭方可能因为还有数据要发送不会立即关闭，在被动关闭方给主动方发送数据时，由于主动方调用的close()，所以当它收到主动方发来的数据，就会回RST关闭了，如果想接收这个数据的话，就可以选择用shutdown来指定关闭写数据方向，而不关闭读数据方向。



### 25.网络字节序

网络字节序：

  小端字节序：（**pc本地存储**）  高位存高地址。低位存低地址。  int a = 0x12345678

  大端字节序：（**网络存储**） 高位存低地址。低位存高地址。

| 内存地址 | 小端模式存放内容 | 大端模式存放内容 |
| -------- | ---------------- | ---------------- |
| 0x4000   | 0x78             | 0x12             |
| 0x4001   | 0x56             | 0x34             |
| 0x4002   | 0x34             | 0x56             |
| 0x4003   | 0x12             | 0x78             |

### 26.socket相关函数

#### 1.网络字节序相关

**网络字节序与主机字节序的转换：**

  htonl --> 本地--》网络 （IP）     192.168.1.11 --> string --> atoi --> int --> htonl --> 网络字节序

  htons --> 本地--》网络 (port)

  ntohl --> 网络--》 本地（IP）

  ntohs --> 网络--》 本地（Port）

```cpp
#include <arpa/inet.h>

uint32_t htonl(uint32_t hostlong);//h:host,本地	n：net，网络   l：long—早期的int，4字节32位，对应IP地址
uint16_t htons(uint16_t hostshort);//h:host,本地	n：net，网络   s：short,2字节16位，对应端口号port
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);
```

#### 2.IP地址转换函数

```cpp
#include <arpa/inet.h>
int inet_pton(int af, const char *src, void *dst);		//本地字节序（string IP） ---> 网络字节序
		af：AF_INET、AF_INET6
		src：传入，IP地址（点分十进制）
		dst：传出，转换后的 网络字节序的 IP地址。 
		返回值：
			成功： 1
			异常： 0， 说明src指向的不是一个有效的ip地址。
			失败：-1，errno
```

```cpp
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);	//网络字节序 ---> 本地字节序（string IP）
		af：AF_INET、AF_INET6
		src: 网络字节序IP地址
		dst：本地字节序（string IP）
		size： dst 的大小。
		返回值： 成功：dst。 	
			失败：NULL
```

#### 3.sockaddr数据结构

![image-20220302214831613](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220302214831613.png)

![image-20220302214215064](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220302214215064.png)

sockaddr地址结构：  IP + port --> 在网络环境中唯一标识一个进程。

```cpp
//ipv4的sockaddr
struct sockaddr_in addr;
//ipv4的sockaddr的三个成员变量	man 7 ip
addr.sin_family = AF_INET/AF_INET6  //ipv4    
addr.sin_port = htons(9527);  //网络端口号
 int dst;	
 inet_pton(AF_INET, "192.157.22.45", (void *)&dst);
addr.sin_addr.s_addr = dst;		//IP地址

★addr.sin_addr.s_addr = htonl(INADDR_ANY);    取出系统中有效的任意IP地址。二进制类型 

 bind(fd, (struct sockaddr *)&addr, size);
```

#### 4.socket流程函数

详见22.

socket()、bind()、listen()、accept()、connect()、read()、wirte()、close()‘



#### 5.select函数

原理：  借助内核， select 来监听， 客户端连接、数据通信事件。

```cpp
#include <sys/select.h>
/* According to earlier standards */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);
		nfds：监听的所有文件描述符中，最大文件描述符+1
	 	readfds： 读事件 文件描述符监听集合。	传入、传出参数
		writefds：写事件 文件描述符监听集合。	传入、传出参数		NULL
		exceptfds：异常事件 文件描述符监听集合	传入、传出参数		NULL
		timeout： 	> 0: 	设置监听超时时长， 微秒。
					NULL:	阻塞监听
					0：	非阻塞监听，轮询
		返回值：
			>· 0:	所有监听集合（3个）中， 满足对应事件的总数。
			0：	没有满足监听条件的文件描述符
			-1： 	errno
```

传入传出的三个参数集合的理解：传入的是对应的事件要监听的socket描述符，传出的是实际发生该事件（满足对应事件）的socket描述符。

![image-20220317210706032](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220317210706032.png)

因为实际向这三个fd_set参数集合中添加文件描述符需要用到位操作，所以还要学习一些位操作函数

```cpp
void FD_ZERO(fd_set *set);	--- 清空一个文件描述符集合。
		fd_set rset;
		FD_ZERO(&rset);

void FD_SET(int fd, fd_set *set);	--- 将待监听的文件描述符，添加到监听集合中
		FD_SET(3, &rset);	FD_SET(5, &rset);	FD_SET(6, &rset);

void FD_CLR(int fd, fd_set *set);	--- 将一个文件描述符从监听集合中 移除。
		FD_CLR（4， &rset）;

int  FD_ISSET(int fd, fd_set *set);	--- 判断一个文件描述符是否在监听集合中。
		返回值： 在：1；不在：0；
		FD_ISSET（4， &rset）;
```

编程中先进行位操作，再调用select()

**思路分析**

```c
	int maxfd = 0；
	lfd = socket() ;			//创建套接字
	maxfd = lfd；
	bind();						//绑定地址结构
	listen();					//设置监听上限
	fd_set rset， allset;		//创建r监听集合
	FD_ZERO(&allset);			//将r监听集合清空
	FD_SET(lfd, &allset);		//将 lfd 添加至读集合中。
	while（1） {
		rset = allset；			//保存监听集合	
		ret  = select(lfd+1， &rset， NULL， NULL， NULL);		//监听文件描述符集合对应事件。
		if（ret > 0） {							//有监听的描述符满足对应事件
			if (FD_ISSET(lfd, &rset)) {				// 1 在。 0不在。
				cfd = accept（）；				//建立连接，返回用于通信的文件描述符
				maxfd = cfd；
				FD_SET(cfd, &allset);				//添加到监听通信描述符集合中。
			}
			for （i = lfd+1； i <= 最大文件描述符; i++）{
				FD_ISSET(i, &rset)				//有read、write事件
				read（）
				小 -- 大
				write();
			}	
		}
	}

```

![image-20220317215343822](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220317215343822.png)

#### 6.poll函数

poll是对select的改进，但是它是个半成品，相对select提升不大。最终版本是epoll，所以poll了解一下就完事儿，**重点掌握epoll。**

优点：

​    自带数组结构。 可以将 监听事件集合 和 返回事件集合 分离。

​    拓展 监听上限。 超出 1024限制。

缺点：

​    不能跨平台。 Linux

​    无法直接定位满足监听事件的文件描述符， 编码难度较大。

poll：

```cpp
#include <poll.h>
int poll(struct pollfd *fds, nfds_t nfds, int timeout);
	struct pollfd {
		int fd; /* 文件描述符 */
		short events; /* 监控的事件 */
		short revents; /* 监控事件中满足条件返回的事件，传入时， 给0。如果满足对应事件的话， 返回 非0 --> POLLIN、POLLOUT、POLLERR */
	};
	fds：监听的文件描述符【数组】
	事件：
   ★POLLIN			普通或带外优先数据可读,即POLLRDNORM | POLLRDBAND
	POLLRDNORM		数据可读
	POLLRDBAND		优先级带数据可读
	POLLPRI 		高优先级可读数据
   ★POLLOUT		普通或带外数据可写
	POLLWRNORM		数据可写
	POLLWRBAND		优先级带数据可写
   ★POLLERR 		发生错误
	POLLHUP 		发生挂起
	POLLNVAL 		描述字不是一个打开的文件

	nfds 			监控数组中有多少文件描述符需要被监控
	timeout 		毫秒级等待
		-1：阻塞等，#define INFTIM -1 				Linux中没有定义此宏
		0：立即返回，不阻塞进程
		>0：等待指定毫秒数，如当前系统时间精度不够毫秒，向上取值
    返回值：返回满足对应监听事件的文件描述符 总个数。
```

  优点：

​    自带数组结构。 可以将 监听事件集合 和 返回事件集合 分离。

​    拓展 监听上限。 超出 1024限制。

  缺点：

​    不能跨平台。 Linux

​    无法直接定位满足监听事件的文件描述符， 编码难度较大。



#### epoll

epoll是Linux下多路复用IO接口**select/poll的增强版本**，它能显著提高程序在**大量并发连接中只有少量活跃的情况下**的系统CPU利用率，因为它会**复用文件描述符**集合来传递结果而不用迫使开发者每次等待事件之前都必须重新准备要被侦听的文件描述符集合，另一点原因就是获取事件的时候，它无须遍历整个被侦听的描述符集，只要遍历那些被内核IO事件异步唤醒而加入Ready队列的描述符集合就行了。

目前epoll是linux大规模并发网络程序中的热门首选模型。

epoll除了提供select/poll那种IO事件的**电平触发（Level Triggered）**外，还提供了**边沿触发（Edge Triggered）**，这就使得用户空间程序有可能缓存IO状态，减少epoll_wait/epoll_pwait的调用，提高应用程序效率。

可以使用cat命令查看一个进程可以**打开的socket描述符上限**。

```shell
cat /proc/sys/fs/file-max	//当前计算机所能打开的文件描述符的个数，与硬件相关
ulimit -a  	//当前用户进程下，open files:默认打开的文教描述符个数
ulimit -n 1024 	//需要注销用户才生效
```

如有需要，可以通过修改配置文件的方式修改该上限值。

```shell
sudo vi /etc/security/limits.conf

  在文件尾部写入以下配置,soft软限制，hard硬限制。如下图所示。

* soft nofile 65536
* hard nofile 100000
```

##### 基础API

![image-20220321214325076](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220321214325076.png)

1.创建一个epoll句柄，参数size用来告诉内核监听的文件描述符的个数，跟内存大小有关。

```cpp
#include <sys/epoll.h>
int epoll_create(int size)   //创建监听红黑树。size：创建的红黑树的监听节点数目（仅供内核参考，实际可能比这大——连接的客户端数目比设置的size大时会自动扩容）
//成功返回新创建的红黑树的根节点 fd，失败-1 errno
```

2.控制某个epoll监控的文件描述符上的事件：注册、修改、删除。

```cpp
#include <sys/epoll.h>
	int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)	//操作监听红黑树节点
		epfd：	为epoll_creat的句柄（返回值）
		op：		表示动作，用3个宏来表示：
			EPOLL_CTL_ADD (注册新的fd到监听红黑树)，
			EPOLL_CTL_MOD (修改已经注册的fd在监听红黑树上的监听事件)，
			EPOLL_CTL_DEL (从监听红黑树上删除一个fd，即取消监听)；
        fd:	待监听的fd
            
		event：监听事件	本质 struct epoll_event //结构体 地址 
            events: EPOLLIN/EPOLLOUT/EPOLLERR/EPOLLET
            data: 联合体
		struct epoll_event {
			__uint32_t events; /* Epoll events */
			epoll_data_t data; /* User data variable */
		}; 
		typedef union epoll_data {
			void *ptr;		//epoll反应堆模型（回调函数）:epoll ET模式 + 非阻塞、轮询 + void *ptr
			int fd;			//对应监听事件的fd
			uint32_t u32;	// 不用
			uint64_t u64;	// 不用
		} epoll_data_t;		

		★EPOLLIN ：	表示对应的文件描述符可以读（包括对端SOCKET正常关闭）
		★EPOLLOUT：	表示对应的文件描述符可以写
		EPOLLPRI：	表示对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）
		★EPOLLERR：	表示对应的文件描述符发生错误
		EPOLLHUP：	表示对应的文件描述符被挂断；
		★EPOLLET： 	将EPOLL设为边缘触发(Edge Triggered)模式，这是相对于水平触发(Level Triggered)而言的
		EPOLLONESHOT：只监听一次事件，当监听完这次事件之后，如果还需要继续监听这个socket的话，需要再次把这个socket加入到EPOLL队列里
            //返回值：成功0，失败-1 errno
```

3.等待所监控文件描述符上有事件的产生，类似于select()调用。

```cpp
struct epoll_event events[1024];
#include <sys/epoll.h>
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout)//阻塞监听。
    	epfd：		//为epoll_creat的句柄（返回值）
		events：		//用来存内核得到事件的集合，【数组】，传出参数，传出满足监听条件的fd结构体
		maxevents：	//数组 元素总个数 1024。告之内核这个events有多大，这个maxevents的值不能大于创建epoll_create()时的size，
		timeout：	//超时时间
			-1：	//阻塞
			0：	//立即返回，非阻塞
			>0：	//指定毫秒
		返回值：	
    		>0: 成功返回有多少文件描述符就绪（满足监听的总个数），可以用作循环上限。
            0: 时间到时返回0
            -1: 出错返回-1
```



### 27.epoll ET LT

#### ET模式

Edge Triggered (ET) 边缘触发只有数据到来才触发，不管缓存区中是否还有数据。只有子进程（客户端）发数据才会触发，缓冲区剩余未读尽的数据不会导致 epoll_wait 返回。 新的事件满足，才会触发。

```cpp
struct epoll_event event;
event.events = EPOLLIN | EPOLLET;
```

#### LT模式

水平触发模式，只要缓冲区有数据就触发。

Level Triggered (LT) 水平触发只要有数据都会触发。默认模式。缓冲区剩余未读尽的数据会导致 epoll_wait 返回。

#### 比较

LT是**缺省**（默认）的工作方式，并同时支持block和no-block socket。在这种做法中，内核告诉你一个文件描述符是否就绪了，然后你可以对这个就绪的fd进行IO操作。如果你不做任何操作，内核还是会继续通知你的，所以这种模式编程出错可能性要小一些。**传统的select/poll都是这种模式的代表。**

**ET是高速工作方式，只支持no-block socket。**在这种模式下，当描述符从未就绪变为就绪时，内核通过epoll告诉你。然后他会假设你知道文件描述符已经就绪，并且不会再为那个文件描述符发送更多的就绪通知。请注意，如果一直不对这个fd作IO操作（从而导致它再次变成未就绪），内核不会发送更多的通知。

#### 结论

epoll 的 ET模式， 高效模式，但是只支持 非阻塞模式。 --- 忙轮询。

```cpp
struct epoll_event event;
event.events = EPOLLIN | EPOLLET;
epoll_ctl(epfd, EPOLL_CTL_ADD, cfd， &event);	
int flg = fcntl(cfd, F_GETFL);	
flg |= O_NONBLOCK;
fcntl(cfd, F_SETFL, flg);
```

#### epoll优缺点

优点：

​	高效。突破1024文件描述符。

缺点：
	不能跨平台。 Linux。

# 应用层：HTTP

HTTP是无状态协议，无状态协议(Stateless Protocol) 就是指浏览器对于事务的处理没有记忆能力。举个例子来说就是比如客户请求获得网页之后关闭浏览器，然后再次启动浏览器，登录该网站，但是服务器并不知道客户关闭了一次浏览器。与cookie配合使用，使得浏览器有记忆功能。

### 0、HTTP底层什么协议，可用其他的吗

HTTP协议底层基于是基于TCP/IP协议，HTTP只是一个传输协议，关于寻址、路由、数据完整性这些传输细节，HTTP协议一概不管，这些工作就得交给它的下层协议去做，而TCP/IP协议正好满足这方面的要求。感觉应该不可用其他的。

### <u>1. HTTP1.0,1.1,2.0区别</u>

http/1.0 :

(1)较之前版本增加了Head，Post等新方法，增加了响应状态码； 

(2) 引入了Content-Type，使传输的数据不再限于文本。还引入了头部，即请求头和响应头； 

但是

(3)默认不支持长连接，需要设置keep-alive参数指定

(4)每请求一个资源都得新建一个 TCP 连接，而且只能串行请求

http 1.1 :

(1)使用TCP长连接的方式改善了HTTP1.0短连接造成的开销

(2)增加了缓存管理和控制

(3)支持管道网络传输，只要第一个请求发出，不必等它回来就可以发送第二个请求，可减少整体的响应时间。

但是

(4)http1.1的请求头或响应头未经压缩就会发送，首部信息越多延迟越大。

(5)服务器按请求顺序响应，如果服务器响应慢，会导致客户端一直请求不到数据，也就是队头阻塞。

(6)请求只能从客户端开始，服务器只能被动响应。

http/2.0 :

(1)多路复用，http/2可以一个连接并发多个请求或回应，不用按顺序排队等待，不会出现队头阻塞问题，降低延迟提高连接利用率。

(2)二进制格式编码传输(1.1是纯文本)，因为计算机只懂二进制，这样收到报文后，不用再将明文转为二进制，直接解析二进制报文，增加传输效率。

(3)使用HPACK算法做header压缩，在客户端和服务器同时维护一张头信息表，所有字段都会存入这个表中，生成一个索引号，以后就不发送同样的字段了，只发送索引号，提高传输速度

(4)增加服务端推送功能，服务器不再被动等待也可以主动向客户端发送消息,(加速客户端渲染速度)。

数据流：http2的数据包不是按顺序发送的，同一个连接里面有连续的数据包，可能属于不同的回应，因此必须对数据包做标记，指出它属于哪个回应。每个请求或回应的数据包，称为一个数据流。



### 2.短链接和长连接？

HTTP1.0每次发起一个请求，都需要建立一次TCP连接(三次握手)，数据发送完毕就关闭连接，在通信过程中做了很多无畏的连接和断开，增加了通信开销，这就是短连接。

所以HTTP1.1提出了长连接的通信方式，也叫持久连接。它的特点是，只要通信双方没有一端明确提出断开连接则保持TCP连接状态。这样减少了TCP连接重复建立和断开(四次挥手)所造成的额外开销。长连接的好处是效率高，缺点是占用资源。
**使用场景:**

**长连接**：多用于操作频繁，点对点的通讯，而且客户端连接数目较少的情况。比如即时通讯。

**短连接**：用户数目较多的Web网站的HTTP服务一般用短连接。比如京东，淘宝这样的大型网站一般客户端数量达到千万级甚至上亿，若采用长连接会使得服务端大量的资源被无效占用，所以一般使用的是短连接。

### <u>3. http请求报文和响应报文</u>

请求报文包括：请求首行、请求头、空行、请求体。

![http请求报文](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\http请求报文.png)

请求头包括：

Host:指定接收请求的服务器域名                                                                                                      User-Agent(浏览器名称):标识客户端身份的名称                                                                              Accept(传输文件类型):指客户端可以接受的文件类型                                                                      Accept—Encoding：客户端可以接受的编码方式                                                             Connection(连接类型):表示客户端与服务器的连接类型                                                         **Cookie(Cookie)**:浏览器用这个属性向服务器发送Cookie。Cookie是在浏览器中寄存的小型数据体，它可以记载和服务器相关的用户信息。（当浏览器第一次向服务器发送请求，服务器对浏览器响应的时候会加上一个Cookie，浏览器下一次向同一服务器发请求时会带上这个Cookie，服务器就可以通过这个Cookie识别浏览器）                                                                                                               Content-Length: 请求体的长度



响应报文包括：响应行、响应头、响应正文

![http响应报文](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\http响应报文.png)

响应头包括：

Date:表示报文创建的时间                                                                                                                                                         server:服务器名字。                                                                                                                                                       Connection：浏览器与服务器之间连接的类型                                                                                                                  Content-type:表示后面的文档属于什么MIME类型                                                                                                                          Content-Length:内容长度                                                                                                                                                         Content-Encoding:文案编码方式                                                                                                                                              Set-Cookie:设置和页面关联的Cookie    



### 4.HTTP状态码

1、一般1xx类状态码属于提示信息，是协议处理中的中间状态，实际用到的比较少。

2、一般2xx类状态码表示服务器成功处理了客户端的请求。

200 ok：正常被处理                                                                                                                        204 No Content：请求处理成功，但没有资源可返回。

3、一般3xx类是重定向状态码，需要进行附加操作以完成请求。

301:永久重定向。说明请求资源不存在了，需改用新的URL再次访问                                                                           302:临时重定向,说明请求资源还在，暂时用一个新的URL再来访问                                                                                                                  

4、一般4xx类是表示客户端发送报文有错误状态码，服务器无法处理请求。

400 Bad Request：请求报文中存在语法错误                                                                                                                                 403:表示服务器禁止访问资源                                                                                                                                                          404 Not Found：服务器无法找到请求资源



### <u>5.HTTP和HTTPS区别</u>

![https](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\https.jpg)

1、HTTP协议传输的数据是明文传输，没有加密，使用HTTP协议传输隐私信息不安全， HTTPS协议是TLS(前身是SSL)+HTTP协议构建的可进行加密传输、身份认证的网络协议，比http协议安全。

2、http协议建立连接比较简单，TCP三次握手之后就可以进行http的报文传输。而https在TCP三次握手之后，还需要TLS\SSL握手过程，才可以进行加密报文传输。

3、https所用端口是80，https所用端口是443。

4、https协议需要向CA(证书权威机构)申请数字证书，来保证服务器的身份是可信的。(证书需要一定费用)

### 6.什么是SSL/TLS？作用？

SSL/TLS是建立在TCP/IP之上的一个负责加密通信的安全协议。它综合了对称加密、非对称加密、摘要算法、数字签名、数字证书等技术，能够在不安全的环境中为通信的双方创建出一个安全的传输通道，就好像给HTTP套上一副盔甲，保护一下。

SSL/TLS协议作用：认证用户和服务，加密数据，维护数据的完整性。

### 7.对称加密和非对称加密区别

数字加密由明文，密钥，密文组成，明文通过密钥的加密，会生成对应的密文，目前主流加密方式有对称加密和非对称加密

![对称加密](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\对称加密.jpg)

![非对称](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\非对称.jpg)

**对称加密(也叫共享加密)**，是指客户端和服务端对于加密和解密使用同一个密钥，而密钥在网络传输过程中可能会被攻击者获得，所以对称加密有一定风险。

**非对称加密**是使用公开密钥和私有密钥两把密钥进行加密解密。发送密文的一方使用对方的公开密钥进行加密处理，对方收到被加密的信息后，再使用自己的私有密钥进行解密，这种加密方式更安全 ，缺点是处理速度比较慢。(客户端和服务端都有自己的公钥和私钥，客户端发送时用服务端的公钥加密，接收时用自己的私钥进行解密，服务端发送时用客户端的公钥加密)

现实中使用的往往是两种加密方式相结合，混合加密的机制。

### 8.HTTPS 如何保证数据安全及流程

（SSL是怎么保证工作安全的，也是HTTPS握手过程吧？）

Https的加密机制是一种共享密钥加密和公开密钥加密并用的混合加密机制。

在交换密钥环节，使用非对称(公开密钥)加密方式，保证密钥能够实现安全交换，之后建立通信交换报文阶段再使用对称加密(共享密钥的加密)方式来通信，提高效率。

1）浏览器客户端发起加密请求，请求信息包括客户端支持的SSL/TLS加密协议版本，客户端支持的非对称加密算法和哈希算法，默认使用服务端的443端口进行连接；
2）服务端收到请求，确认使用的SSL/TLS加密协议版本，确认使用的加密算法和hash算法，将自己的身份信息放到配置好的证书中返回给客户端，证书中包括网站地址、加密公钥等信息，和公钥对应的私钥保留在服务端不公开；
3）客户端收到证书，检验合法性，包括是否在有效期内、域名是否匹配等，若不通过，显示警告信息，如果通过浏览器地址栏上会出现一把小锁，之后客户端生成一个用于对称加密的随机密钥Key，并用证书内的公钥对随机密钥加密(这是非对称加密)，并用约定好的哈希函数计算报文的哈希值，用随机密钥对报文进行加密，把报文、哈希值、公钥加密后的随机密钥Key都发给服务端，(此时用的是对称加密);
4）服务端收到消息后，使用公钥配对的私钥解密出客户端发送的随机密钥Key，再用随机密钥Key解密出客户端发来的报文，计算报文的hash值，验证与浏览器发送过来的hash值是否一致，如果一致说明报文没问题，之后服务端再使用随机密钥Key对它想发送的报文进行对称加密，并计算报文的哈希值，把这些都发给客户端；
5）客户端使用随机密钥Key对称解密密文，得到HTTP数据报文，计算报文哈希值，如果与服务端发送哈希值相同，握手结束。他们后续通信都使用之前交换好的随机密钥key来对称加密。

![httpss](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\httpss.jpg)



### 9.http缓存机制

Http缓存主要分为两种：**强缓存**和**协商缓存**。两种缓存分别通过Http报文头部不同的字段进行控制

·**强缓存基本原理**：所请求的数据在缓存数据库中未过期的话，不与服务器进行交互，直接使用缓存数据库中的数据。

·Expire 其指定了一个日期/时间

·Cache-Control通用消息头用于http 请求和响应中通过指定指令来实现缓存机制

·private：客户端可以缓存

·public：客户端和代理服务器都可以缓存

·max-age=xxx：缓存的内容将在xxx 秒后失效

·no-cache：需要使用**协商缓存**来验证缓存数据

·no-store：所有内容都不会缓存，**强缓存和协商缓存都不会触发**

**·**当强缓存过期未命中或者响应报文``Cache-Control``中有``must-revalidate``标识必须每次`` ``请求验证资源的状态时，便使用协商缓存的方式去处理缓存文件。```

·**协商缓存主要原理**是从缓存数据库中取出缓存的标识，然后向浏览器发送请求验证请求的数据是否已经更新，如果已更新则返回新的数据，若未更新则使用缓存数据库中的缓存数据

### <u>10.Get和Post的区别</u>

GET:对服务器资源获取的简单请求

POST:用于发送包含用户提交数据的请求

1.Post比Get要更加安全，因为Get请求会将要提交的数据直接显示在URL后面，(URL统一资源定位符，我所请求的资源在网络中的位置)而Post请求会把要提交的数据放在请求体里面。

2.get请求把传送的参数放到URL后面，所以这个长度是有限制的，而POST是放在请求体里，这个长度没有限制。

### 11.HTTP的请求方法

HEAD：获取头部信息

DELETE：请求服务器删除指定的页面

OPTIONS：允许客户端查看服务器的性能

### 15.服务器怎么判断客户端断开连接

TCP的保活机制，项目中检测用于通信的文件描述符对应的epoll事件是**EPOLLRDHUP**时，就说明客户端关闭了连接

1. 检测连接是否丢失的方法大致有两种：keepalive和heart-beat
2. （tcp内部机制）采用keepalive，它会先要求此连接一定时间没有活动（一般是几个小时），然后发出数据段，经过多次尝试后（每次尝试之间也有时间间隔），如果仍没有响应，则判断连接中断。可想而知，整个周期需要很长的时间。
3. （应用层实现）一个简单的heart-beat实现一般测试连接是否中断采用的时间间隔都比较短，可以很快的决定连接是否中断。并且，由于是在应用层实现，因为可以自行决定当判断连接中断后应该采取的行为，而keepalive在判断连接失败后只会将连接丢弃。



### 20.Cookie 和 Session 

##### 20.1它们存在的原因

http是无状态的协议对于事物处理没有记忆能力，每次客户端和服务端会话完成后，服务端不会存储任何会话信息，每个请求都是完全独立的，服务端无法确认当前访问者的身份信息，所以服务器为了与浏览器进行会话跟踪，知道是谁在访问我，就需要主动维护一个状态，这个状态用于告知服务器端前后两个请求是否为同一来源，这个状态就需要通过cookie或Session去实现。

##### 20.2 什么是Cookie 和 Session 

Cookie是客户端保持状态的方法

Cookie实际上是服务器发给浏览器并保存在它本地的一小块数据。浏览器之后向同一服务器再次发起请求时会携带上这个Cookie，用于告知服务端两个请求是否来自同一浏览器。

Session是服务器保持状态的方法。

Session保存在服务器上，客户端第一次访问服务器时，创建对应的Session，服务器返回唯一标识这个Session的SessionID给浏览器，浏览器接收到了，会将此信息存入Cookie中，同时Cookie记录此SessionID是属于哪个域名。这样用户第二次访问服务器时，请求会自动判断此域名下是否存在Cookie信息，如果存在，就自动将Cookie信息也发送给服务端，服务端会从Cookie中获取SessionID，再根据 SessionID查找对应的Session信息，如果没有找到，说明用户没有登录或者登录失效，如果找到Session证明用户已经登录可执行后面操作了。

##### 20.3 二者区别

1. 存储位置不同，Cookie保存在客户端(浏览器)，Session保存在服务器端。
2. 存取方式的不同，Cookie 只能保存字符串类型，Session 可以存任意数据类型。(一般情况下我们可以在 Session 中保持一些常用变量信息，比如说UserId等。)
3. 安全性不同，Cookie存储在客户端，比较容易遭到不法获取，Session 存储在服务端，安全性相对 Cookie 要好一些。
4. 有效期不同，Cookie 可设置为长时间保持,像我们使用过的默认登陆功能就是。session失效时间短，一般客户端关闭或Session超时都会失效。(当用户登录网站后较长一段时间没有与服务器进行交互，将会导致服务器上的用户会话数据即session被销毁就是Session超时)
5. 单个Cookie保存的数据不能超过4K，Session可存储数据远高于Cookie（但是访问量过多会占用服务器资源）



### 24.URI和URL的区别

- URI，是统一资源标志符，作用是唯一标识一个资源。
- URL，是统一资源定位符，作用是提供资源的路径。打个比喻，URI像是身份证，可以唯一标识一个人，URL更像一个住址，可以通过URL找到这个人。

### <u>25.URL输入后的执行过程</u>(http通信过程)

http通信过程(精简版，没有展开)

1、在浏览器地址栏输入网址                                                                                                                                            

2、浏览器通过**DNS解析**到域名对应的IP地址

(1). 首先查找浏览器也就是用户主机上的DNS缓存列表(维护一张域名与IP的对应表)，如果有记录，那么直接返回对应IP地址，跳过DNS解析，若没有则继续；

(2). 查找用户主机上的（硬盘里的）域名解析文件hosts文件，如果有记录，那么返回对应的IP地址，若没有则继续；

(3). 查找本地DNS服务器，本地DNS服务器先查找自己的缓存记录，如果有记录，返回对应的IP地址，若没有，本地DNS服务器向根域名服务器（DNS跟服务器）发起请求；

(4). 根域名服务器收到请求后，查看是(.com)顶级域名，于是返回(.com)顶级域名服务器的IP地址给到本地DNS服务器；

(5). 本地DNS服务器收到回复后，向(.com)顶级域名服务器发起请求；

(6). (.com)顶级域名服务器收到请求后，查看是(.baidu.com)次级域名，于是返回(.baidu.com)次级域名服务器的IP地址给到本地DNS服务器；

(7). 本地DNS服务器收到回复后，向(.baidu.com)次级域名服务器发起请求；

(8). (.baidu.com)次级域名服务器收到请求后，查看是自己管理的域名，于是查找域名和IP地址映射表，把所查找域名([www.baidu.com](http://www.baidu.com))对应的IP地址返回给本地DNS服务器；

(9). 本地DNS服务器收到回复后，向用户主机回复所查找域名对应的IP地址，并把记录写入本地DNS服务器的缓存里；

(10). 用户主机收到回复后，使用IP地址访问网站，并把记录写入自己的DNS缓存列表中。                                                       

3、域名解析过后，浏览器发起tcp的三次握手，浏览器根据随机分配的端口向服务器的80端口发起tcp连接。                               

4、tcp连接建立完成后，浏览器向服务器发送一个http请求                                                                                       

5、服务器处理浏览器的请求，返回浏览器它所需要的html文件                                                                                

6、浏览器请求嵌入在html中的资源(图片、音视频等)                                                                                                 

7、得到所需要的资源后，浏览器对页面进行渲染，呈现给用户                                                                                 

8、浏览器发送请求获取嵌入在HTML中的资源(图片、音视频、CSS等)







8.TCP和UDP哪个协议有包长限制 ？ UDP限制512字节

什么命令能够查看网络状态  netstate

* TCP和UDP哪个协议有包长限制

* IP数据分片有什么弊端？（拆包和粘包？）

* TCP连接两端一个突然断连，另一端如何感知（心跳包保活机制）

* 

  服务器第一次收到客户端的 SYN 之后，就会处于 SYN_RCVD 状态，此时双方还没有完全建立其连接， 服务器会把此种状态下请求连接放在一个队列里，我们把这种队列称之为半连接队列。 当然还有一个全连接队列，就是已经完成三次握手，建立起连接的就会放在全连接队列中。如果队列满 了就有可能会出现丢包现象。

* 

* 





对于FIN_WAIT_2，CLOSE_WAIT状态和TIME_WAIT状态？你知道多少? 

FIN_WAIT_2： 

半关闭状态。

发送断开请求一方还有接收数据能力，但已经没有发送数据能力。

 CLOSE_WAIT状态： 

被动关闭连接一方接收到FIN包会立即回应ACK包表示已接收到断开请求。 

被动关闭连接一方如果还有剩余数据要发送就会进入CLOSED_WAIT状态。

 TIME_WAIT状态： 

又叫2MSL等待状态。 

如果客户端直接进入CLOSED状态，如果服务端没有接收到最后一次ACK包会在超时之后重新再 发FIN包，此时因为客户端已经CLOSED，所以服务端就不会收到ACK而是收到RST。所以 TIME_WAIT状态目的是防止最后一次握手数据没有到达对方而触发重传FIN准备的。 

在2MSL时间内，同一个socket不能再被使用，否则有可能会和旧连接数据混淆（如果新连接和旧 连接的socket相同的话）。







1) 第一次握手，客户端会组建一个数据包，设置 SYN 标志位，表示该数据包是用来建立同步连接的。同时生成一个随机数x，作为发送数据的起始包号，向服务器发送数据包后，客户端进入`SYN-SENT`状态。
2) 第二次握手，服务器端收到数据包，检测到了 SYN 标志位，知道客户端在请求建立连接。服务器端也会组建一个数据包，并设置 SYN 和 ACK 标志位，表示收到了客户端发来的数据包，同时我也要和客户端建立连接。服务器生成一个随机数 y，作为起始包号。服务器将客户端数据包序号x加1，作为确认号(ack)。服务器将数据包发出，进入`SYN-RECV`状态。

3) 第三次握手，客户端收到数据包，检测到了SYN和ACK标志位，知道服务器收到了我之前发送的数据包，并且服务器也请求建立连接。客户端会检测确认号(ack)，看它的值是否为 x+1，如果是就说明客户端到服务器的连接建立成功。

接下来，客户端继续组建数据包，并设置ACK标志位，表示收到了服务器发来的数据包。将刚才服务器发来的数据包序号y加1，作为确认号(ack)。客户端将数据包发出，进入`ESTABLISED`状态，表示连接已经成功建立。

4) 服务器端收到数据包，检测到了ACK 标志位，知道客户端收到了我之前发送的数据包。服务器会检测确认号（ack），看它的值是否为y+1，如果是就说明连接建立成功，服务器进入也`ESTABLISED`状态，接下来就可以收发数据了。







