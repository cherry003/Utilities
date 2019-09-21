#ifndef portable_sockaddr_in_H
#define portable_sockaddr_in_H

#include "String.h"
#include "portable_addr_in.h"
typedef unsigned long u32_t;

class portable_sockaddr_in{
/*
protected:

  unsigned short  si_family;
  unsigned short  si_port;
  portable_addr_in*  si_addr;
  unsigned char   si_zero[8]; */

public:
  portable_sockaddr_in(){};
  virtual ~portable_sockaddr_in(){};

  virtual void set_sin_port(unsigned short port)=0;
  virtual void set_ip(char* ip_addrstr)=0;
  virtual void set_sin_family(unsigned short family)=0;
  virtual void uip2ipstr(char* mem, u32_t uip)=0;
 
  virtual unsigned short get_sin_family()=0;
  virtual unsigned long get_long_addr_in()=0;
  virtual void set_long_addr_in(unsigned long v)=0;
  virtual unsigned short get_sin_port()=0;
  virtual void get_ip(char* mem)=0;
  //
};

/*
typedef struct portable_in_addr {
  //union{
	struct { unsigned char s_b1,s_b2,s_b3,s_b4; } S_un_b;
	//unsigned long s_addr;//only for winwock
 // }
}PORTABLE_IN_ADDR;

struct portable_sockaddr_in {
  unsigned short  sin_family;
  unsigned short  sin_port;
  struct portable_in_addr  sin_addr;
  unsigned char   sin_zero[8];
}PORTABLE_SOCKADDR_IN,*PORTABLE_SOCKADDR_IN;

*/
#endif