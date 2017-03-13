/*
 * author: Yu-Fang Juan
 * date: Mar 5th, 2017
 * title: Utilities
 * All rights reserved.
 */

#include "String.h"
#include <winsock2.h>

#define smallUnitBit  8
#define largeUnitCount 4
#define MACUnitCount  6
#define stringLength 50

char* trim(char* desc,char* src,char* seps)
{
  assert(desc && src && seps);
  char* token=NULL;
  desc[0]=0; 
  /* Establish string and get the first token: */
  token = strtok(src, seps);
  while( token != NULL )
  {
	/* While there are tokens in "string" */
	strcat(desc,token);
	token = strtok( NULL, seps );
 }
 return desc;
}
int checkMask(char* mask){
  assert(mask);
  char imask[20];
  int isError=0;
  if(!strcmp(mask,"0.0.0.0") || !strcmp(mask,"255.255.255.255")){
    return -1;
  }
  
  parseIPtoIntArray(imask,mask);
  int k=0,j=0;
  int lVal=255;
  for(k=largeUnitCount-1;k >=0;k--){
	if(imask[k]!=0){
	  if(imask[k]>lVal || imask[k]<0){
		isError=1;
	  }
	  break;
	}
  }
  if(isError)
	return -1;
  for(j=0;j<k;j++){
	if(imask[j]!=255){
	  isError=1;
	  break;
	}
  }
  if(isError)
	return -1;
  else
    return 0;
}


int checkIPAddr(char const* ipadd){
 assert(ipadd);
 char* i=(char*)ipadd+strlen((char*)ipadd);
 while(*i!='.'){
   i--;
 }
 if(*ipadd==0 ||
	 inet_addr(ipadd)==-1 ||
	 getSpecialCharCountinSTR('.',ipadd)!=3 ||
	 atoi((i+1))==255){
   return -1;
 }
 else{
   return 0;
 } 

}
unsigned int ip_int_cvt(char* ipadd){
  return inet_addr(ipadd);
}

bool contains(char* charstr, char* token){
 assert(charstr && token);

 str2Lower(charstr);
 str2Lower(token);
 string  str=charstr;
 size_t pos=str.find(token);
 if(pos==string::npos)
   return false;
 else
   return true;
}

void parseIPtoIntArray(char* intsaver,char* IPArg){
  assert(intsaver && IPArg);
  int strsize=strlen(IPArg);
  assert(strsize>=7);
  char IP[IPSTR_LEN];
  strcpy(IP,IPArg);
  char* taillocation[largeUnitCount];
  char* headlocation[largeUnitCount];
  char* head;
  int count=0;
  char* tail;
  char buf[20];
  char* i;
  headlocation[0]=IP;
  for(i=IP;*i!='\0';i++){
	if(*i=='.'){
	  *i='\0';
	 if(count<largeUnitCount-1)
  	    headlocation[count+1]=i+1;
	 taillocation[count]= i;
	 count++;
	}
  }
  taillocation[count]= i;

  count=0;
  for(int k=0;k<largeUnitCount;k++){
      head=headlocation[k];
	  tail =taillocation[k];
	  memcpy(buf,head,tail-head+1);
	  intsaver[count]=(unsigned char)atoi(buf);
	  count++;
   }
}



bool isValidPort(int portnum){
  if(portnum!=0 && portnum>=1 && portnum<=65535){
	 return true;
  }
  else
     return false;
}

int getSpecialCharCountinSTR(char target,const char* str){
  assert(str);
  char* index=(char*)str;
  int count=0;
  while(*index!='\0'){
	if(*index==target){
      count++;
	  index++;
	}
	else{
      index++;
	}
  }
  return count;
}
void parseHexIPtoStr(char* strip,char const* hexIP){
  assert(strip && hexIP);
  unsigned char intsaver[50];
  for(int j=0;j<largeUnitCount;j++){
    intsaver[j]=(unsigned char)hexIP[j];
  }
   sprintf(strip,"%d.%d.%d.%d",intsaver[0],intsaver[1],intsaver[2],intsaver[3]);
}
int ascii2Hex(char* buf,int digitnum){
	  assert(buf);
	  int tempchar=0;
	  for(int p=0;p<digitnum;p++){
		unsigned char c=(unsigned char)buf[p];
		if(c <=70 && c >=65){//A-F   0x41-0x46
		   tempchar+=(c-55)*pow((double)16,(digitnum-p-1));
		}
		else if(c<=102 && c >=97){//a-f  0x61-0x66
		   tempchar+=(c-87)*pow((double)16,(digitnum-p-1));
		}
		//case1: 0   no handling
		else if(c<=57 && c>=48){//number  0-9  0x30-0x39
		  tempchar+=(c-48)*pow((double)16,(digitnum-p-1));
		}
		else{//illegal char in hex str
           strcpy(buf,"error");
		   return 0;
        }
	  }
	  return tempchar;
}
void hex2Ascii(char hint,char* hstr){
	assert(hstr);
	unsigned char uhint=(unsigned char)hint;
	unsigned char charHI=uhint>>4;
	unsigned char charLO=uhint& 0xF;
	unsigned char optimePerChar=2;
    unsigned char isCAPT=0;
    unsigned char j=0;
	char hintchar[2];
	hintchar[0]=charHI;
	hintchar[1]=charLO;
	for(j=0;j<optimePerChar;j++){
	  if(hintchar[j]>=0 && hintchar[j]<=9){
		 hintchar[j]+=48;
	  }
	  else if(hintchar[j]>=10 && hintchar[j]<=15){
		 if(isCAPT){
		   hintchar[j]+=55;
		 }
		 else{
		   hintchar[j]+=87;
		 }
	  }
	  hstr[j]=(char)hintchar[j];
	 }
}
void port_int2carray(char* buf,int portint){
	assert(buf);
	int base=256;
	int tempport=portint;
	buf[1]=fmod(tempport,base);
    buf[0]=tempport/base;
}
unsigned int port_carray2int(int len,char* buf){
	assert(buf);
	unsigned int portint =0;
	for(int n=(len-1);n>=0;n--){
		unsigned char temp=buf[n];
		portint+=temp*pow((double)16,(2*(len-1-n)));
	}
    //with illegal len, portnum: 0 is returned.
	return portint;
}



int isAllEnChar(char* allchar,unsigned int len,unsigned int &index){
  assert(allchar);

  len--;
  index=-1;
  int EnChar=0;
  for(unsigned int i=0;i<len;i++){
	for(int t=65;t<91;t++){
	  if(allchar[i]==(char)t){
		EnChar=1;
        break;
	  }
	  else{

	  }
	}
	for(int k=97;k<123;k++){
	  if(allchar[i]==(char)k){
		EnChar=1;
        break;
	  }
	  else{
	
	  }
	}
	if(allchar[i]==(char)0x0d || allchar[i]==(char)0x0a){
      EnChar=1;
	}
	if(EnChar==0){
      index=i;
	  return 0;
	}
	else{
      EnChar=0;
	}
  }
  return 1;
}
int isAllMyChar(char spe,char* allchar,unsigned int len,unsigned int &index){
  assert(allchar);
  int i=0;
  for(i=0;i<len;i++){
	if(allchar[i]!=spe){
	  index=i;
	  break;
	}
  }
  if(allchar[index]!=spe)
	return 0;
  else
    return 1;
}
void str2Lower(char* str)
{
  assert(str);
  int length = strlen(str);
  for(int i=0;i<length;i++){
	str[i]= tolower(str[i]);
  }
}
void str2Upper(char* str){
  assert(str);
  int length = strlen(str);
  for(int i=0;i<length;i++){
	str[i]= toupper(str[i]);
  }
}
void uint2carray_given_len(unsigned int main,int numlen,char* buf){
	assert(buf);
	int base=0;
	unsigned int temp=main;
	for(int k=(numlen-1);k>0;k--){
      base=pow(256,k);
	  buf[(numlen-1-k)]=temp/base;
	  temp=fmod(temp,base);
	}
	buf[(numlen-1)]=temp;
}






