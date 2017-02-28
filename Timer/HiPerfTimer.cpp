#include "HiPerfTimer.h"
#include <assert.h>
#include <time.h>  
#include <stdio.h>

#define HPTSleepTime  1

HiPerfTimer::HiPerfTimer(){
  QueryPerformanceFrequency(&freq);
}

void HiPerfTimer::Start(){
  QueryPerformanceCounter(&startTime);
}
void HiPerfTimer::Stop(){
  QueryPerformanceCounter(&stopTime);
}
double HiPerfTimer::Duration(){
  return ((double)(stopTime.QuadPart-startTime.QuadPart)/(double)freq.QuadPart);
}

////
SysTime::SysTime(){
 syear  =0;
 smonth =0;
 sday   =0;
 shour  =0;
 sminute=0;
 ssecond=0;

 fyear  =0;
 fmonth =0;
 fday   =0;
 fhour  =0;
 fminute=0;
 fsecond=0;
}
void SysTime::sysTimerStart(){
 SYSTEMTIME   systemTime;
 GetSystemTime(&systemTime);
 syear  =(int)systemTime.wYear;
 smonth =(int)systemTime.wMonth;
 sday   =(int)systemTime.wDay;
 shour  =(int)systemTime.wHour;
 sminute=(int)systemTime.wMinute;
 ssecond=(int)systemTime.wSecond;
}
void SysTime::sysTimerStop(){
 syear  =0;
 smonth =0;
 sday   =0;
 shour  =0;
 sminute=0;
 ssecond=0;

 fyear  =0;
 fmonth =0;
 fday   =0;
 fhour  =0;
 fminute=0;
 fsecond=0;
}
long SysTime::getDuration(char* time){
 SYSTEMTIME   systemTime;
 GetSystemTime(&systemTime);
 fyear  =(int)systemTime.wYear;
 fmonth =(int)systemTime.wMonth;
 fday   =(int)systemTime.wDay;
 fhour  =(int)systemTime.wHour;
 fminute=(int)systemTime.wMinute;
 fsecond=(int)systemTime.wSecond;
 //decide which is the larger one
 if(fhour>=shour){
   if(fsecond<ssecond){
	 fsecond+=60;
     //handle fminute--
	 if(fminute>0)
	   fminute--;
	 else{
	   fminute+=60;
       fhour--;
	 }
   }
   if(fminute<sminute){
	 fminute+=60;
	 fhour--;
   }
   sprintf(time,"%d:%d:%d",(fhour-shour),(fminute-sminute),(fsecond-ssecond));
   return ((fhour-shour)*6000+(fminute-sminute)*60+(fsecond-ssecond));
 }
 else{
   sprintf(time,"%s","error");
   return -1;
 }

}
void getSysTime(char* hms){
 SYSTEMTIME   systemTime;
 GetSystemTime(&systemTime);
 int fhour  =(int)systemTime.wHour;
 int fminute=(int)systemTime.wMinute;
 int fsecond=(int)systemTime.wSecond;
 sprintf(hms,"%d:%d:%d",fhour,fminute,fsecond);
}
void getLocalTime(char* hms){
  char time[20];
  _strtime(hms);
}
////


//inline   unsigned   __int64   GetCycleCount()   
void nsleep(unsigned nanoseconds)
{
    long work=0;
	LARGE_INTEGER freq, now, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&end);
    end.QuadPart += (nanoseconds * freq.QuadPart) / 1000000000ULL;
    do
    {
        work++;
		QueryPerformanceCounter(&now);
	} while (now.QuadPart < end.QuadPart);

}
