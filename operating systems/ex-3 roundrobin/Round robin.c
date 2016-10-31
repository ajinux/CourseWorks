#include<stdio.h>
#define LEN 3
int time_slice=3,total_time;
typedef struct process_detail
{
   char name[50];
   float arrival_time;
   float burst_time;
   float temp_extime;
   int inqueue;
   int process_state; //TRUE(1) if process not terminated and FALSE if process terminated
}pro_template;
pro_template process[LEN];

typedef struct gantt_chart
{
    char name[50];
    float start_time;
    float end_time;
    float process_at;
    int process_end;
}gantt;
gantt rrobin[20];

struct node
{
    int process;
    struct node* next;
};
typedef struct node* lqueue;
lqueue front=NULL;
lqueue rear=NULL;

void enqueue(int i)
{
    lqueue temp=malloc(sizeof(struct node));
    temp->process=i;
    temp->next=NULL;
    if(front==NULL && rear==NULL)
    {
     front=rear=temp;
     return;
    }
    rear->next=temp;
    rear=temp;
}

int dequeue()
{
    lqueue temp=front;
    if(front==NULL) //queue is null
    {
    //printf("\nCannot dequeue \n");
    return -1;
    }
    else if(front==rear)
      rear=front=NULL;
    else
      front=front->next;
    int process=temp->process;
    free(temp);
    return process;
}
int all_process_not_terminated()
{
    int i;
    for(i=0;i<LEN;i++)
    {
        if(process[i].process_state==1)
            return 1;
    }
    return 0;
}
int check_arrived_process(int timestamp,int process_no)
{
   while(process[process_no].arrival_time<=timestamp && process_no <LEN)
   {
       enqueue(process_no);
       process_no+=1;
   }
   return process_no;
}
void print_gantchart(int len)
{
    int i;
    printf("\nGantt chart :\n\n\t|");
    for(i=0;i<len;i++)
     printf("%s |",rrobin[i].name);
    printf("\n");
    float atat=0;
    for(i=0;i<len;i++)
    {
        if(rrobin[i].process_end==1)
        {
          float tat=rrobin[i].end_time-rrobin[i].process_at;
          printf("\nTAT for %s :%f",rrobin[i].name,tat);
          atat=atat+tat;
        }
    }
    printf("\nAverage TAT is %f .\n",atat/LEN);
    int j;
    float awt=0;
    for(i=0;i<LEN;i++)
    {
        int temp=0;
        float larrival=0,wt;
        for(j=0;j<len;j++)
        {
            if(strcmp(rrobin[j].name,process[i].name)==0)
            {
              if(temp==0)
              {
                  wt=rrobin[j].start_time-rrobin[j].process_at;
                  larrival=rrobin[j].end_time;
                  temp++;
              }
              else
              {
                 wt=wt+rrobin[j].start_time-larrival;
                 larrival=rrobin[j].end_time;
              }
              if(rrobin[j].process_end==1)
              {
                 printf("\nWT for %s : %f",rrobin[j].name,wt);
                 awt=awt+wt;
                 break;
              }

            }
        }
    }
    printf("\nAverage Waiting Time is %f .\n",awt/LEN);
}
void round_robin()
{
    int timestamp=0,gantt_len=0,process_no=0,proexe=0,count=0,proe_num;
    timestamp=process[process_no].arrival_time;
    enqueue(process_no);
    process_no++;
    while(timestamp<=total_time)
    {
        if(proexe==1 || front!=NULL)
        {
            if(proexe==0)
            {
              proe_num=dequeue();
              rrobin[gantt_len].start_time=timestamp;
              strcpy(rrobin[gantt_len].name,process[proe_num].name);
              proexe=1;
              count=0;
            }
            process[proe_num].temp_extime--;
            timestamp++;
            count++;
            if(process[proe_num].temp_extime==0)
            {
                rrobin[gantt_len].end_time=timestamp;
                rrobin[gantt_len].process_end=1;
                rrobin[gantt_len].process_at=process[proe_num].arrival_time;
                gantt_len++;
                count=0;
                proexe=0;
                process_no=check_arrived_process(timestamp,process_no);
                continue;
            }
            else if(count==time_slice)
            {
                count=0;
                proexe=0;
                process_no=check_arrived_process(timestamp,process_no);
                rrobin[gantt_len].end_time=timestamp;
                rrobin[gantt_len].process_end=0;
                rrobin[gantt_len].process_at=process[proe_num].arrival_time;
                gantt_len++;
                enqueue(proe_num);
            }
            else
            {
                process_no=check_arrived_process(timestamp,process_no);
            }

        }
        else
        {
          timestamp++;
          strcpy(rrobin[gantt_len].name,"Idle");
          rrobin[gantt_len].process_end=0;
          gantt_len++;
          process_no=check_arrived_process(timestamp,process_no);
        }
    }
    print_gantchart(gantt_len);
}
void ask_process_details()
{
    int i=0;
    for(i=0;i<LEN;i++)
    {
      printf("\n\nEnter the details of process %d :\nProcess name:",i+1);
      scanf("%s",process[i].name);
      printf("\nArrival Time:");
      scanf("%f",&process[i].arrival_time);
      printf("\nBurst Time:");
      scanf("%f",&process[i].burst_time);
      process[i].process_state=1;
    }

}
void process_details()
{
       /*------------------process 1-----------------------*/
   strcpy(process[0].name,"p1");
   process[0].burst_time=5;
   process[0].arrival_time=2;
   process[0].process_state=1;

   /*------------------process 2-----------------------*/
   strcpy(process[1].name,"p2");
   process[1].arrival_time=0;
   process[1].burst_time=4;
   process[1].process_state=1;

   /*------------------process 3-----------------------*/
   strcpy(process[2].name,"p3");
   process[2].arrival_time=1;
   process[2].burst_time=6;
   process[2].process_state=1;

}
void sort_arrivaltime()
{
   int i,j;
   for(i=0;i<LEN;i++)
   {
     for(j=i+1;j<LEN;j++)
     {
         if(process[i].arrival_time>process[j].arrival_time)
         {
           pro_template temp;
           temp=process[i];
           process[i]=process[j];
           process[j]=temp;
         }
     }
   }
   for(i=0;i<LEN;i++)
      process[i].temp_extime=process[i].burst_time;
}
void calculate_totlatime()
{
    int i;
    total_time=0;
    for(i=0;i<LEN;i++)
     total_time+=process[i].burst_time;
    printf("\nTotal Time :%d\n",total_time);
}
void print_details()
{
    int i;
    printf("DETAILS:");
    printf("\n------------------------------------------------------------------\n");
    printf("NAME\t\t\t|\tARRIVAL TIME\t|\tBURST TIME|");
     printf("\n------------------------------------------------------------------");
    for(i=0;i<LEN;i++)
    {
      printf("\n%s\t\t\t|\t%f\t|\t%f|",process[i].name,process[i].arrival_time,process[i].burst_time);
    }
    printf("\n------------------------------------------------------------------\n");
}
void main()
{
    process_details();
    //ask_process_details();
    print_details();
    calculate_totlatime();
    sort_arrivaltime();
    round_robin();
}
