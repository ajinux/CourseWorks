#include<stdio.h>
#include<string.h>
#define LEN 6 //number of persons

typedef struct person_detail
{
   char name[50];
   float arrival_time;
   float burst_time;
   int priority;
   int process_state; //TRUE(1) if process not terminated and FALSE if process terminated
}persons;
persons person[LEN];

typedef struct gantt_chart
{
    char name[50];
    float start_time;
    float end_time;
    float process_at;
}gantt;

int all_process_not_terminated()
{
    int i;
    for(i=0;i<LEN;i++)
    {
        if(person[i].process_state==1)
            return 1;
    }
    return 0;
}
void fifo_scheduling()
{
    gantt fifo[20];
    float timestamp=0,last_arrivaltime=0;
    int gant_len=0,i;

    while(all_process_not_terminated())
    {
     int flag=0;
     for(i=0;i<LEN;i++)
     {
         if(person[i].process_state==1 && person[i].arrival_time<=last_arrivaltime)
         {
           fifo[gant_len].start_time=timestamp;
           strcpy(fifo[gant_len].name,person[i].name);

           timestamp=timestamp+person[i].burst_time;
           fifo[gant_len].end_time=timestamp;

           last_arrivaltime=person[i].arrival_time;
           fifo[gant_len].process_at=person[i].arrival_time;

           person[i].process_state=0; //set the process is terminated
           gant_len++;
           flag=1;
         }
     }
     if(flag==0)
     {
         last_arrivaltime=last_arrivaltime+0.01;
         timestamp=timestamp+0.01;
     }
    }
    printf("\n----------------------------------NON PREEMPTIVE FIFO SCHEDULING-------------------------\n");
    gantt_calculate(gant_len,fifo);
    set_process();
}

void priority_scheduling()
{
    gantt priority[20];
    float timestamp=0,last_arrivaltime=0;
    int gant_len=0,i,prior=0;

    while(all_process_not_terminated())
    {
     int flag=0;
     for(i=0;i<LEN;i++)
     {
         if(person[i].process_state==1 && person[i].arrival_time<=timestamp)
         {
           flag=1;
           if(person[i].priority==prior)
           {
           strcpy(priority[gant_len].name,person[i].name);
           priority[gant_len].start_time=timestamp;
           timestamp=timestamp+person[i].burst_time;
           priority[gant_len].end_time=timestamp;
           priority[gant_len].process_at=person[i].arrival_time;
           //printf("\nPerson name :%s ,Start Time :%f ,End time :%f ,Arrival time :%f\n",priority[gant_len].name,priority[gant_len].start_time,priority[gant_len].end_time,priority[gant_len].process_at);
           person[i].process_state=0;
           gant_len++;
           }
         }
     }
     if(flag==0)
     {
         //last_arrivaltime=last_arrivaltime+0.01;
         timestamp=timestamp+0.01;
     }
     else
        prior++;
    }
     //printf("\nPriority Timestamp %f  priority %d",timestamp,prior);
    printf("\n----------------------------------NON PREEMPTIVE PRIORITY SCHEDULING--------------------\n");
    gantt_calculate(gant_len,priority);
    set_process();
}

void sjf_scheduling()
{
    gantt sjf[20];
    float timestamp=0,last_arrivaltime=0;
    int gant_len=0,i,btime=0;

    while(all_process_not_terminated())
    {
     int flag=0;
     for(i=0;i<LEN;i++)
     {
         if(person[i].process_state==1 && person[i].arrival_time<=timestamp)
         {
           flag=1;
           if(person[i].burst_time==btime)
           {
           strcpy(sjf[gant_len].name,person[i].name);
           sjf[gant_len].start_time=timestamp;
           timestamp=timestamp+person[i].burst_time;
           sjf[gant_len].end_time=timestamp;
           sjf[gant_len].process_at=person[i].arrival_time;
           //printf("\nPerson name :%s ,Start Time :%f ,End time :%f ,Arrival time :%f\n",sjf[gant_len].name,sjf[gant_len].start_time,priority[gant_len].end_time,priority[gant_len].process_at);
           person[i].process_state=0;
           gant_len++;
           }
         }
     }
     if(flag==0)
         timestamp=timestamp+0.01;
     else
        btime++;
    }
    printf("\n------------------------------------NON PREEMPTIVE SJF SCHEDULING------------------------\n");
    gantt_calculate(gant_len,sjf);
    set_process();


}

void set_process()
{
 int i;
 for(i=0;i<LEN;i++)
 {
     person[i].process_state=1;
 }
}

void gantt_calculate(int gant_len,gantt fifo[])
{
  int i;
  float Average=0;
  for(i=0;i<gant_len;i++)
  {
     float tat;
     tat=fifo[i].end_time-fifo[i].process_at;
     printf("\nTAT for %s :%.1f",fifo[i].name,tat);
     Average=Average+tat;
  }
  printf("\nAverage TAT is %.1f\n",Average/gant_len);
  Average=0;
  for(i=0;i<gant_len;i++)
  {
      float wt;
      wt=fifo[i].start_time-fifo[i].process_at;
      printf("\nWT for %s :%.1f",fifo[i].name,wt);
      Average=Average+wt;
  }
  printf("\nAverage WT is %.1f\n",Average/gant_len);
}
void person_details()
{
   /*------------------PERSON 1-----------------------*/
   strcpy(person[0].name,"Anand");
   person[0].arrival_time=2.02;
   person[0].burst_time=2;
   person[0].priority=2;
   person[0].process_state=1;

   /*------------------PERSON 2-----------------------*/
   strcpy(person[1].name,"Raj");
   person[1].arrival_time=2.04;
   person[1].burst_time=3;
   person[1].priority=2;
   person[1].process_state=1;

   /*------------------PERSON 3-----------------------*/
   strcpy(person[2].name,"Daniel");
   person[2].arrival_time=2.05;
   person[2].burst_time=4;
   person[2].priority=2;
   person[2].process_state=1;

   /*------------------PERSON 4-----------------------*/
   strcpy(person[3].name,"Shan");
   person[3].arrival_time=2.02;
   person[3].burst_time=3;
   person[3].priority=1;
   person[3].process_state=1;

   /*------------------PERSON 5-----------------------*/
   strcpy(person[4].name,"Nickil");
   person[4].arrival_time=2.03;
   person[4].burst_time=2;
   person[4].priority=1;
   person[4].process_state=1;

   /*------------------PERSON 6-----------------------*/
   strcpy(person[5].name,"Nikitha");
   person[5].arrival_time=2.06;
   person[5].burst_time=4;
   person[5].priority=1;
   person[5].process_state=1;
}

void print_details()
{
    int i;
    printf("DETAILS:");
    printf("\n-----------------------------------------------------------------------------------------\n");
    printf("NAME\t\t\t|\tARRIVAL TIME\t|\tBURST TIME\t|\tPRIORITY|");
    printf("\n-----------------------------------------------------------------------------------------");
    for(i=0;i<LEN;i++)
    {
      printf("\n%s\t\t\t|\t%f\t|\t%f\t|\t%d\t|",person[i].name,person[i].arrival_time,person[i].burst_time,person[i].priority);
    }
     printf("\n-----------------------------------------------------------------------------------------\n");
}

void main()
{
   person_details();
   print_details();
   fifo_scheduling();
   priority_scheduling();
   sjf_scheduling();
}
