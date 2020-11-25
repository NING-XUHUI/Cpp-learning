# socket编程

### 1.服务端在调用listen()之前，客户端不能向服务端发起连接请求的
### 2.服务端在调用listen()之后，服务端的socket开始监听客户端的连接
### 3.客户端调用connect()向服务端发起连接请求
### 4.在TCP底层，客户端和服务端握手后建立起通信通道，如果有多个客户端请求，在服务端就会形成一个已经准备好的连接的队列
### 5.服务端调用accpet()函数，从队列中获取一个已经准备好的连接，函数返回一个新的socket，新的socket用于与客户端通信，listen的socket之负责监听客户端的连接请求

## listen的socket队列
### 内核会为listen状态的socket维护两个队列：不完全连接请求队列（SYN_RECV）状态个等待accept建立socket的队列（ESTABLISHED状态）
### Linux内核2.2之后，backlog参数的行为改变了，现在他指等待accept的完全建立的socket的队列长度，而不是不完全连接请求的数量。不完全连接队列的长度可以使用/proc/sys/net/ipv4/tcp_max_syn_backlog,则截断

## recv和send

