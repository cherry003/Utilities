#ifndef PortableSockH
#define PortableSockH

#include "portableSock/portable_sockaddr_in.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "portableSock/PortableSockParameter.h"
typedef unsigned int SOCKET;
		
class PortableSock{
  public:
	PortableSock(){};
	virtual ~PortableSock(){};
	
	virtual unsigned int portableSocket(int af, int type, int protocol)=0;
	virtual int portableSend(unsigned int ps,const void *msg, int len, unsigned int flags)=0;
	virtual int portableSendto(unsigned int ps,char* buffer, int msg_len, int options,
	   portable_sockaddr_in* addr)=0;
	virtual int portableRecvfrom(unsigned int ps,char* buffer, int maxsize, int options,
	   portable_sockaddr_in* addr)=0;

	virtual int portableRecv(unsigned int ps,void *buf, int len, unsigned int flags)=0;
	virtual int portableBind(unsigned int ps,portable_sockaddr_in* addr)=0;

	virtual int portableClose(unsigned int ps)=0;
	virtual int portableAccept(unsigned int ps,portable_sockaddr_in* saddr,portable_sockaddr_in* caddr)=0;
	virtual int portableListen(unsigned int ps,int backlog)=0;
	
	virtual unsigned long portable_inet_addr(char* ipadd)=0;
	virtual unsigned short portable_htons(unsigned short host)=0;
	virtual unsigned short portable_ntohs(unsigned short host)=0;
	virtual int set_async_select(unsigned int socket, unsigned int msg,long event)=0;
	virtual int portableConnect(unsigned int ps,portable_sockaddr_in *si)=0;
	virtual int getLastError()=0;
	virtual int portableShutdown(int s,int how)=0;
	virtual int portableSetsockopt(unsigned int s, int level,int opt,const void *optval,int optlen)=0;
	virtual void uip2ipstr(char* mem, u32_t uip)=0;
};

#endif
