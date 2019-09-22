# C++ Utilites for Adapters (Windows)

When developing, developers usually need utilities to fast develop.
These utilities are designed for developers to retrieve adapters' information on windows.

## Getting Started

These are modules that could be used in c++ projects on Windows platform.
This project is built and tested on Visual Studio 2019 with precompiled header disabled.

## Steps to Disable Precompiled Header in Visual Studio

Select your project, use the "Project -> Properties" menu and go to the "Configuration Properties -> C/C++ -> Precompiled Headers" section, then change the "Precompiled Header" setting to "Not Using Precompiled Headers" option.

## APIs
in String.h, APIs are provided.
```c++
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




/*
    int checkMask(IN char* mask)
    check the mask string is valid or not.
    0 returned: valid
    -1 returned: invalid
*/
int checkMask(char* mask);




/*
    bool contains(IN char* charstr,IN char* token)
    check the charstr contains the token or not.
    1 returned: charstr contains the token
    0 returned: charstr contains no token
*/
bool contains(char* str, char* token);




/*
    bool isValidPort(IN int portnum)
    check a port number is valid or not.
    1 returned: valid
    0 returned: invalid    
*/
bool isValidPort(int port);




/*
    int getSpecialCharCountinSTR(IN char target,IN const char* str)
    returns the count that the target appears in the str.
*/
int getSpecialCharCountinSTR(char target,char const* str);




/*
    int ascii2Hex(IN char* buf, IN int digitnum)
    e.g.
    char* asc=”ab”;
    int intasc= ascii2Hex(asc,strlen(asc));=>171 is returned
*/
int ascii2Hex(char* buf,int digitnum);




/*
   void str2Lower(IN & OUT char* string)
   convert the string to all lower case form
*/
void str2Lower(char* string);




/*
    void str2Upper(IN & OUT char* string)
    convert the string to all upper case form
*/
void str2Upper(char* string);




/*
    void uint2carray_given_len (IN unsigned int portint,IN int numlen, OUT char* buf)
    convert the portint into buf in hex form.
    eg 
    int test=60000;
    uint2carray_given_len (60000,4,buf);=>buf[0]=0, buf[1]=0, buf[2]=0xea, byf[3]=0x60
*/
void uint2carray_given_len(unsigned int portint,int numlen,char* buf);




/*
     int isAllEnChar(IN char* allchar, IN unsigned int len, IN unsigned int &index)
     1 returned: the buffer’s content is all English chars
     0 returned: the buffer contains non-english chars. 
     used in ringBuffer loopback test
*/
int isAllEnChar(char* allchar,unsigned int len,unsigned int &index);




/*
    int isAllMyChar(IN char spe, IN char* allchar, IN unsigned int len,IN unsigned int &index)
    isAllMyChar is similar with isAllEnChar. The only difference is that here programmer can specify mychar in the spe.
*/
int isAllMyChar(char spe,char* allchar,unsigned int len,unsigned int &index);





/*
    void hex2Ascii(IN char hint, OUT char* hstr)
    convert the hint into hex str format.
    eg 
    long test=0xabcd;
    hstr’s content=>”abcd”
*/
void hex2Ascii(char hint,char* hstr);

```


## License

This project is licensed under the MIT License - see the LICENSE file for details
