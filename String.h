/*
 * author: Yu-Fang Juan
 * date: Mar 5th, 2017
 * title: Ticking Circus
 * All rights reserved.
 */

#ifndef String_H
#define String_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define IPSTR_LEN  50
#define MACSTR_LEN 50


#include <iostream>
#include <string>
#include <sstream>
using namespace std;


/*
   unsigned int ip_int_cvt(IN char* ipadd)
   convert the input ip address in the str format to be long format.
*/
unsigned int ip_int_cvt(char* ipadd);

/*
   void port_int2carray(OUT char* buf, IN int portint)
   convert the int to be hex format.
*/
void port_int2carray(char* buf,int portint);


/*
   unsigned int port_carray2int(IN int len, IN char* buf)
   convert the port in net byte order to be an int, which is the return value. len means the length of buf required to convert.
*/
unsigned int port_carray2int(int len,char* buf);


/*
   char* trim(OUT char* desc, IN char* src,IN char* seps)
*/
char* trim(char* desc,char* src,char* seps);


/*
   int checkIPAddr(IN char const* ipadd)
   check the input ipadd is in valid ip format or not. 
   0 returned: valid
   -1 returned: invalid

*/
int checkIPAddr(char const* input);


/*
    void parseIPtoIntArray(OUT char* intsaver, IN char* IPArg)
    convert the ip string to the hex format
    e.g.
    192.168.2.1=> intsaver [0]=0xc0, intsaver [1]=a8, intsaver [2]=0x02, intsaver [3]=0x01
*/
void parseIPtoIntArray(char* intsaver,char* IP);

/*
    void parseHexIPtoStr(OUT char* strip,IN char const* hexIP)
    convert the ip in hex format to be in string format
    hexIP [0]=0xc0, hexIP [1]=a8, hexIP [2]=0x02, hexIP [3]=0x01=> 192.168.2.1
*/
void parseHexIPtoStr(char* strip,char const* hexIP);
int checkMask(char* mask);

bool contains(char* str, char* token);
bool isValidPort(int port);
int getSpecialCharCountinSTR(char target,char const* str);
int ascii2Hex(char* buf,int digitnum);
unsigned int strToIntWithBase(int base,char* strStart,char* strFin);
void str2Lower(char* string);
void str2Upper(char* string);
void uint2carray_given_len(unsigned int portint,int numlen,char* buf);

int isAllEnChar(char* allchar,unsigned int len,unsigned int &index);
int isAllMyChar(char spe,char* allchar,unsigned int len,unsigned int &index);
void hex2Ascii(char hint,char* hstr);


wstring widen( const string& str );
string narrow( const wstring& str );

#endif
