#ifndef HiPerfTimerH
#define HiPerfTimerH
#include <Windows.h>
#include <Winnt.h>



class HiPerfTimer{
	public:
	         HiPerfTimer();
	  void   Start();
	  void   Stop();
	  double Duration();
	private:
	  LARGE_INTEGER startTime;
	  LARGE_INTEGER stopTime;
	  LARGE_INTEGER freq;
};
class SysTime{
   private:
	 int syear;
	 int smonth;
	 int sday;
	 int shour;
	 int sminute;
	 int ssecond;

	 int fyear;
	 int fmonth;
	 int fday;
	 int fhour;
	 int fminute;
	 int fsecond;
   public:
	 SysTime();
	 void sysTimerStart();
	 void sysTimerStop();
	 long getDuration(char* time);//return second
};
void getSysTime(char* hms);
void getLocalTime(char* hms);


void nsleep(unsigned nanoseconds);
#endif