
# 网络中的结构体 

```c
struct sockaddr {
	unsigned short sa_family;		// 地址类型，AF_XXX
	char sa_data[14];				// 14字节的端口和地址
};
// 使用起来不方便
```

# 新的结构体

```c
struct sockaddr_in {
	short int sin_family;			// 地址类型
	unsigned short int sin_port;	// 端口号
	struct in_addr sin_addr;		// 地址
	unsigned char sin_zero[8];		// 为了保持和struct sockaddr一样的长度,可能会强制相互转换,bind函数传入的是旧的结构体。
};

struct in_addr {
	unsigned long s_addr;			// 地址
};
```

```c
struct hostent{
	char *h_name;					// 主机名
	char **h_aliases;				// 主机所有别名构成的字符串数组，同一ip可以绑定多个域名
	int h_addrtype;					// 主机ip地址的类型，例如ipv4还是ipv6
	int h_length;					// 主机ip地址长度，ipv4地址为4，ipv6地址为6
	char **h_addr_list;				// 主机的ip地址，以网络字节序存储
};

#define h_addr h_addr_list[0] /* for backforward compatibility */

// gethostbyname函数可以利用字符串格式的域名获得ip字节顺序地址
struct hostent *gethostbyname(const char *name);
```

```c
int inet_aton(const char *cp, struct in_addr *inp);
// 
```