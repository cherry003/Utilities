/*
 * author: Yu-Fang Juan
 * date: Mar 5th, 2017
 * title: Utilities
 * All rights reserved.
 */
#ifndef adapterH
#define adapterH

#include <deque>
#include "String.h"
using namespace std;

typedef deque<int> num_container;
extern char config_new_ip[IPSTR_LEN];


/*
   saves adapter information.
*/
class Adapter{
   public:
	  char desc[500];
	  char name[500];
	  char macadd[6];
	  char mask[4];
};

/*
   saves domain information.
*/
class domain{
	public:
	  domain();
	  char dns[2][4];
	  char domain_name[50];
	  char host_name[50];
};
int getDomainInfo(domain* p_dm);

typedef deque<Adapter*> adapter_container;
extern adapter_container macdq;


/*

    int getAdapterInfo(OUT deque<Adapter> &macdq)
    0 returned: successful
    -1 returned: unsuccessful
*/
int getAdapterInfo(adapter_container &macdq);


/*
    int getBcastAddPerAdapter(OUT deque<u32_t> &adaq)
    gets all broadcast address from all adapters on the current PC, and saves them into the adaq.
    0 returned: successful
   -1 returned: unsuccessful
*/
int getBcastAddPerAdapter(num_container &adaq);


/*
    int getLocalIPList(OUT deque<u32_t> &ipq)
*/
int getLocalIPList(num_container &ipq);
#endif
