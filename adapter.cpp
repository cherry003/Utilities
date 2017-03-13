/*
 * author: Yu-Fang Juan
 * date: Mar 5th, 2017
 * title: Utilities
 * All rights reserved.
 */
#include "adapter.h"

#include <winsock2.h>
#include <iphlpapi.h>
#include <iostream>

typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned long u32_t;
typedef char  s8_t;
typedef short s16_t;
typedef long  s32_t;


domain::domain(){
  memset(domain_name,0,sizeof(domain_name));
  memset(host_name,0,sizeof(host_name));
  memset(dns,0,sizeof(dns));
}
int getDomainInfo(domain* p_dm){
   ULONG ulLen1=4096;
   char pbBuf1[4096];
   
   IP_ADDR_STRING *pIPAddr;
   if(ERROR_SUCCESS==GetNetworkParams((FIXED_INFO*)pbBuf1, &ulLen1))
   {
	 FIXED_INFO* FixedInfo=(FIXED_INFO*)pbBuf1;
	 switch(FixedInfo->NodeType)
     {       
		case     BROADCAST_NODETYPE:
		break;
		case     PEER_TO_PEER_NODETYPE:
		break;
		case     MIXED_NODETYPE:
		break;
		case     HYBRID_NODETYPE:
		break;
		default:
		break;
	 }
	 strcpy(p_dm->domain_name,FixedInfo->DomainName);
	 strcpy(p_dm->host_name,FixedInfo->HostName);
	 parseIPtoIntArray(&(p_dm->dns[0][0]),FixedInfo->DnsServerList.IpAddress.String);
	 pIPAddr=FixedInfo->DnsServerList.Next;
	 parseIPtoIntArray(&(p_dm->dns[1][0]),	pIPAddr->IpAddress.String);
	 return 0;
   }
   else{
	 return -1;
   }

}


/*

    int getAdapterInfo(OUT deque<Adapter> &macdq)
    0 returned: successful
    -1 returned: unsuccessful
*/
int getAdapterInfo(adapter_container &adaq){
   for(size_t i=0;i<adaq.size();i++){
	 delete adaq.at(i);
   }
   adaq.clear();
   ULONG ulLen1=4096;
   char pbBuf1[4096];
   Adapter* curadapter=new Adapter();
   if(ERROR_SUCCESS==GetAdaptersInfo((IP_ADAPTER_INFO*)pbBuf1, &ulLen1))
   {
	  char* macbuf=curadapter->macadd;
	  char* desc=curadapter->desc;
	  char* name=curadapter->name;
      char* mask=curadapter->mask;
	  
	  PIP_ADAPTER_INFO pAdapterInfo,pAdapter=0;
	  pAdapterInfo=(IP_ADAPTER_INFO*)pbBuf1;
	  pAdapter = pAdapterInfo;
	  while(pAdapter){
		 for(unsigned int i=0;i<pAdapterInfo->AddressLength;i++){
		   macbuf[i]=pAdapter->Address[i];
		 }
		 strcpy(desc,pAdapter->Description);
		 strcpy(name,pAdapter->AdapterName);
		 parseIPtoIntArray(mask,pAdapter->IpAddressList.IpMask.String);
		 adaq.push_back(curadapter);
		 pAdapter = pAdapter->Next;
	  }
	  return 0;
   }
   else{
		return -1;
   }    

}



/*
    int getBcastAddPerAdapter(OUT deque<u32_t> &adaq)
    gets all broadcast address from all adapters on the current PC, and saves them into the adaq.
    0 returned: successful
   -1 returned: unsuccessful
*/
int getBcastAddPerAdapter(num_container &bcastq){
   bcastq.clear();
   ULONG ulLen1=4096;
   char pbBuf1[4096];
   if(ERROR_SUCCESS==GetAdaptersInfo((IP_ADAPTER_INFO*)pbBuf1, &ulLen1))
   {
	  char ipaddrcopy[IPSTR_LEN];
	  char maskcopy[IPSTR_LEN];
	  
	  PIP_ADAPTER_INFO pAdapterInfo,pAdapter=0;
	  pAdapterInfo=(IP_ADAPTER_INFO*)pbBuf1;
	  pAdapter = pAdapterInfo;
	  while(pAdapter){
	   IP_ADDR_STRING *ipstr=&(pAdapter->IpAddressList);
	   while(ipstr!=NULL){
		 strcpy(ipaddrcopy,ipstr->IpAddress.String);
		 strcpy(maskcopy,pAdapter->IpAddressList.IpMask.String);
		 
		 if(!strcmp(ipaddrcopy,"0.0.0.0"))
		 {
		 }
		 else
		 {
			u32_t IPaddr=inet_addr(ipaddrcopy);
			u32_t mask=inet_addr(maskcopy);
			u32_t bcastaddr=(IPaddr & mask)| (~mask) ;
			bcastq.push_back(bcastaddr);
		  }
		  ipstr=ipstr->Next;
		}
		pAdapter = pAdapter->Next;
	  }
       return 0;
   }
   else{
        return -1;
   }
}


/*
    int getLocalIPList(OUT deque<u32_t> &ipq)
*/
int getLocalIPList(num_container &ipq){
   ipq.clear();
   ULONG ulLen1=4096;
   char pbBuf1[4096];

   if(ERROR_SUCCESS==GetAdaptersInfo((IP_ADAPTER_INFO*)pbBuf1, &ulLen1))
   {
	  char ipaddrcopy[IPSTR_LEN];
	  //
	  PIP_ADAPTER_INFO pAdapterInfo,pAdapter=0;
	  pAdapterInfo=(IP_ADAPTER_INFO*)pbBuf1;
	  pAdapter = pAdapterInfo;
	  while(pAdapter){
		IP_ADDR_STRING *ipstr=&(pAdapter->IpAddressList);
		while(ipstr!=NULL){
		 strcpy(ipaddrcopy,ipstr->IpAddress.String);
		 //
		 if(!strcmp(ipaddrcopy,"0.0.0.0"))
		 {
		 }
		 else
		 {
           u32_t uipadd= inet_addr(ipaddrcopy);
		   ipq.push_back(uipadd);
		 }
		 ipstr=ipstr->Next;
		}
			pAdapter = pAdapter->Next;
	  }
	  return 0;
   }
   else{
        return -1;
   }
}


