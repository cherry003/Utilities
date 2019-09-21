//
//winsock constants
#define P_INVALID_SOCKET   (unsigned int)(~0)
#define P_SOCKET_ERROR   -1

#define P_PF_INET         2
#define P_INADDR_ANY 0x00000000  //INADDR_ANY
//
#define P_SOCK_STREAM 1
#define P_SOCK_DGRAM  2
//
#define P_IPPROTO_TCP 6
#define P_IPPROTO_UDP 17
//
#define P_SO_REUSEADDR    SO_REUSEADDR
#define P_SOMAXCONN       0x7fffffff
#define P_WSAECONNRESET  10054
#define P_WSAEWOULDBLOCK 10035
//
#define P_WSAEISCONN 10056


#define P_FD_READ_BIT      0
#define P_FD_READ          (1 << P_FD_READ_BIT)

#define P_FD_WRITE_BIT     1
#define P_FD_WRITE         (1 << P_FD_WRITE_BIT)

#define P_FD_OOB_BIT       2
#define P_FD_OOB           (1 << P_FD_OOB_BIT)

#define P_FD_ACCEPT_BIT    3
#define P_FD_ACCEPT        (1 << P_FD_ACCEPT_BIT)

#define P_FD_CONNECT_BIT   4
#define P_FD_CONNECT       (1 << P_FD_CONNECT_BIT)

#define P_FD_CLOSE_BIT     5
#define P_FD_CLOSE         (1 << P_FD_CLOSE_BIT)

#define P_FD_QOS_BIT       6
#define P_FD_QOS           (1 << P_FD_QOS_BIT)

#define P_FD_GROUP_QOS_BIT 7
#define P_FD_GROUP_QOS     (1 << P_FD_GROUP_QOS_BIT)

#define P_FD_ROUTING_INTERFACE_CHANGE_BIT 8
#define P_FD_ROUTING_INTERFACE_CHANGE     (1 << P_FD_ROUTING_INTERFACE_CHANGE_BIT)

#define P_FD_ADDRESS_LIST_CHANGE_BIT 9
#define P_FD_ADDRESS_LIST_CHANGE     (1 << P_FD_ADDRESS_LIST_CHANGE_BIT)

#define P_FD_MAX_EVENTS    10
#define P_FD_ALL_EVENTS    ((1 << P_FD_MAX_EVENTS) - 1)
#define WSA_ASYNC  0x0400+1
 //