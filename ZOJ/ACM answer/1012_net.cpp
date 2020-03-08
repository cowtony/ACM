
#include <iostream> 
#include <vector> 
#include <string> 
#include <utility> 
#include <iterator> 
#include <list> 
#include <algorithm> 

class Job 
{ 
public: 
   int   cpus; 
   int mems; 
    
   int arrive; 
   int deadline; 
    
   int   bonus; 
   int   reward; 
   int punish; 

}; 
inline bool earlier(const Job &a, const Job &b) 
{ 
   if ( a.arrive < b.arrive ) 
      return true; 
   if ( a.arrive == b.arrive ) 
   { 
      if ( a.reward < b.reward ) 
         return true; 
      else 
         return false; 
   } 
   return false; 
} 

vector<int> results; 
list<Job>   jobs_queue; 
vector<Job>   jobs_noenter; 

int    time_life; 

int      sys_cpus; 
int      sys_mems; 

int      income; 
int      current_cpus; 
int      current_mems; 


int count(void); 

int main(void) 
{ 
   int jobs; 
   int i; 
   Job   jtmp;    
    
   while(1) 
   { 
      jobs_noenter.clear(); 
    
      cin >> time_life; 
      if ( time_life == 0) 
         break; 
       
      cin >> sys_cpus >> sys_mems >>   jobs; 
       
      for ( i = 0; i < jobs; i++) 
      { 
         cin >> jtmp.cpus >> jtmp.mems 
            >> jtmp.arrive >> jtmp.deadline 
            >> jtmp.reward >> jtmp.bonus >> jtmp.punish; 
         jobs_noenter.push_back(jtmp); 
      } 
      sort( jobs_noenter.begin(), jobs_noenter.end(),earlier ); 
      /*dump all jobs*/ 
      /* 
      cout << jobs_noenter.size() << endl; 
       
      for ( i = 0; i < jobs_noenter.size(); i++) 
      { 
         cout << jobs_noenter[i].reward << endl; 
      } 
      */ 
      i = count(); 
      results.push_back(i); 
   } 
   for ( i = 0; i < results.size(); i++) 
   { 
      cout <<"Case " << i+1 << ": " << results[i] << endl << endl; 
   } 
} 

int current_time; 

inline int count_get( Job job) 
{ 
   int tmp = job.reward; 

   current_time++; 
    
   if ( current_time > job.deadline ) 
   { 
      tmp -= ( current_time - job.deadline ) * job.punish; 
      current_time--; 
      return tmp; 
   } 
    
   if ( current_time <  job.deadline ) 
   { 
      tmp += (job.deadline - current_time) * job.bonus; 
      current_time--; 
      return tmp; 
   } 
    
   current_time--; 
   return tmp; 
} 

int count(void) 
{ 
   int get; 
   income = 0; 
    
    
    
   list<Job>::iterator iter; 
   //init 
   current_time = 0; 
   current_cpus = sys_cpus; 
   current_mems = sys_mems; 
    
   int   jobindex = jobs_noenter.size() - 1; 
   jobs_queue.clear(); 
   while(1) 
   { 

      if ( (current_time >= time_life) || 
         ( (jobindex < 0) && jobs_queue.empty() ) ) 
         break;   //OK, over! 
       
      //first skip idle() 
      if (    jobindex >= 0 && jobs_queue.empty() 
         && jobs_noenter[jobindex].arrive > current_time 
         && jobs_noenter[jobindex].arrive < time_life ) 
      { 
         current_time = jobs_noenter[jobindex].arrive; 
      } 

      //add all arrive jobs 
      while( jobindex >= 0) 
      { 
         if ( jobs_noenter[jobindex].arrive == current_time ) 
         { 
            jobs_queue.push_back( jobs_noenter[jobindex] ); 
            jobindex--; 
         } 
         else 
            break; 
      } 
    
      //now select jobs can been execute 
      get = 0; 
       
      for(iter = jobs_queue.begin(); iter != jobs_queue.end();) 
      { 
         if ( (*iter).cpus <= current_cpus && (*iter).mems <= current_mems) 
         { 
            current_cpus -= (*iter).cpus; 
            current_mems -= (*iter).mems; 
            get += count_get( (*iter) ); 
             
            iter = jobs_queue.erase(iter); 
             
            if ( current_cpus == 0 && current_mems == 0) 
               break; 
            else 
               continue; 
         } 
         //cout << (*iter).cpus <<" " << (*iter).mems << endl;    
         iter++; 
      } 
       
      income += get; 
      current_cpus = sys_cpus; 
      current_mems = sys_mems; 
      current_time ++; 
   } 
    
   current_time ; 
    
   for(iter = jobs_queue.begin(); iter != jobs_queue.end(); iter++) 
   { 
      if ( (*iter).deadline < current_time ) 
      { 
         income -= ( current_time - (*iter).deadline ) * (*iter).punish; 
      } 
   } 

   return income; 
} 
