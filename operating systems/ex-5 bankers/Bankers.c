#include<stdio.h>
#include<string.h>
#define R 3
int avail[R];
struct process
{
    char name[20];
    int alloc[R];
    int max[R];
    int need[R];
};
struct process p[10];
int n;
void safeSequenceCompute()
{
    int flag[10]={},sequence[10],avail_cpy[R];
    int count=0;
    int i,j;
    for(i=0;i<R;i++)
        avail_cpy[i]=avail[i];


    for(i=0;count<n;i=(i+1)%n)
    {
        if(flag[i]==2)
            continue;
        else
         {
            for(j=0;j<R;j++)
            {
                if(p[i].need[j]>avail_cpy[j])
                    break;
            }
            if(j==R)
            {
                flag[i]=2;
                sequence[count++]=i;
                for(j=0;j<R;j++)
                {
                    avail_cpy[j]+=p[i].alloc[j];
                }
            }
            else
            {
                if(flag[i]==1)
                    break;
                flag[i]=1;
            }
         }
    }
    if(count==n){
        printf("\nsafe sequence is\n");
        for(i=0;i<n;i++)
            printf("%d ",sequence[i]+1);
    }
    else{
        printf("\nnot safe");
    }

}
int main()
{

    printf("\nenter the number of process :");
    scanf("%d",&n);
    int i,j;
    printf("enter available resource :");
    for(j=0;j<R;j++)
        scanf("%d",&avail[j]);
    printf("\nEnter the details:\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter name of person %d:",i+1);
        scanf("%s",p[i].name);
        printf("\nAllocated resources:");
        for(j=0;j<R;j++)
            scanf("%d",&p[i].alloc[j]);
        printf("\nMax resources:");
        for(j=0;j<R;j++)
            scanf("%d",&p[i].max[j]);
        for(j=0;j<R;j++)
            p[i].need[j]=p[i].max[j]-p[i].alloc[j];

    }
    printf("\nneed matrix is\n");
    for(i=0;i<n;i++){
        for(j=0;j<R;j++)
            printf("%d ",p[i].need[j]);
        printf("\n");
    }
    safeSequenceCompute();
    printf("\nenter the name of additional request :");
    char name[100];
    int temp,flag=0;
    scanf("%s",name);
    for(i=0;i<n;i++){
        if(strcmp(p[i].name,name)==0)
            break;
    }
    printf("\nEnter the resource request :");
    for(j=0;j<R;j++)
        {
            scanf("%d",&temp);
            if(p[i].need[j]>=temp&&avail[j]>=temp)
            {
                p[i].alloc[j]+=temp;
                p[i].need[j]=p[i].max[j]-p[i].alloc[j];
            }
        else
            flag=1;

        }
    if(flag==1)
        printf("\nnot a safe state");
    else
        safeSequenceCompute();
    return 0;
}
