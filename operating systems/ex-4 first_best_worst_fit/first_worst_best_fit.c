#include<stdio.h>
#include<limits.h>
#include<float.h>
int NoL,NoC;
struct Locker
{
    float space;
    int alloStatus;//if allocated 1 else 0
};
struct Customer
{
    float req;
    int lockerno;//initially -1 for all customer
};
struct Locker lockerspace[100];
struct Customer customerReq[100];
void firstFit()
{
    int i,j;
    printf("\n----FIRST FIT-----\n");
    for(i=0;i<NoC;i++)//iterate through all customer requirement
    {
        for(j=0;j<NoL;j++)//iterate through all locker
        {
            if(lockerspace[j].alloStatus==0&&lockerspace[j].space>=customerReq[i].req)//locker not allocated and space >=required
                break;
        }
        if(j<NoL)//it will be true if the above loop exits due to 'break' statement
        {
            lockerspace[j].alloStatus=1;
            customerReq[i].lockerno=j;
        }
    }
    //displaying
    for(i=0;i<NoC;i++)
    {
        if(customerReq[i].lockerno>=0)
        {
            printf("%0.2f - %0.2f\n",customerReq[i].req,lockerspace[customerReq[i].lockerno].space);
            lockerspace[customerReq[i].lockerno].alloStatus=0;//restoring to same state as before the function call
            customerReq[i].lockerno=-1;
        }
        else
            printf("%0.2f - not allocated\n",customerReq[i].req);

    }

}
void bestfit()
{
    int i,j;
    float minValue=FLT_MAX;//for choosing minimum value
    int minIndex=-1;
    printf("\n----BEST FIT-----\n");
    for(i=0;i<NoC;i++)
    {
        for(j=0;j<NoL;j++)
        {
            //locker not alloc and space>=required and minimum value > space
            if(lockerspace[j].alloStatus==0&&lockerspace[j].space>=customerReq[i].req&&minValue>lockerspace[j].space)
            {
                minValue=lockerspace[j].space;//new min value assign
                minIndex=j;
            }
        }
        if(minIndex!=-1)//true if the statement inside if block of above loop is executed
        {
            customerReq[i].lockerno=minIndex;
            lockerspace[minIndex].alloStatus=1;

        }
        minIndex=-1;
        minValue=FLT_MAX;//restoring for next iteration of loop
    }

    //displaying
    for(i=0;i<NoC;i++)
    {
        if(customerReq[i].lockerno>=0)
        {
            printf("%0.2f - %0.2f\n",customerReq[i].req,lockerspace[customerReq[i].lockerno].space);
            lockerspace[customerReq[i].lockerno].alloStatus=0;
            customerReq[i].lockerno=-1;
        }
        else
            printf("%0.2f - not allocated\n",customerReq[i].req);

    }
}

//logic same as above but for maximum value
void worstfit()
{
    int i,j;
    float maxValue=FLT_MIN;//for choosing maximum value
    int maxIndex=-1;
    printf("\n----WORST FIT-----\n");
    for(i=0;i<NoC;i++)
    {
        for(j=0;j<NoL;j++)
        {
            if(lockerspace[j].alloStatus==0&&lockerspace[j].space>=customerReq[i].req&&maxValue<lockerspace[j].space)
            {
                maxValue=lockerspace[j].space;
                maxIndex=j;
            }
        }
        if(maxIndex!=-1)
        {
            customerReq[i].lockerno=maxIndex;
            lockerspace[maxIndex].alloStatus=1;

        }
        maxIndex=-1;
        maxValue=FLT_MIN;
    }

    //displaying
    for(i=0;i<NoC;i++)
    {
        if(customerReq[i].lockerno>=0)
        {
            printf("%0.2f - %0.2f\n",customerReq[i].req,lockerspace[customerReq[i].lockerno].space);
            lockerspace[customerReq[i].lockerno].alloStatus=0;
            customerReq[i].lockerno=-1;
        }
        else
            printf("%0.2f - not allocated\n",customerReq[i].req);

    }

}
void main()
{
    int i;
    printf("enter the number of locker and customer\n");
    scanf("%d%d",&NoL,&NoC);//NoC-number of customer,NoL-number of locker
    printf("enter the locker details\n");
    for(i=0;i<NoL;i++)//inputs locker size
    {
        lockerspace[i].alloStatus=0;
        scanf("%f",&lockerspace[i].space);
    }
    printf("enter the customer details\n");
    for(i=0;i<NoC;i++)//inputs customer requirement
    {
        scanf("%f",&customerReq[i].req);
        customerReq[i].lockerno=-1;
    }
    /*
    NoL=6;
    NoC=6;
    lockerspace[0].alloStatus=0;
    lockerspace[0].space=2;
    lockerspace[1].alloStatus=0;
    lockerspace[1].space=0.5;
    lockerspace[2].alloStatus=0;
    lockerspace[2].space=1;
    lockerspace[3].alloStatus=0;
    lockerspace[3].space=0.75;
    lockerspace[4].alloStatus=0;
    lockerspace[4].space=3;
    lockerspace[5].alloStatus=0;
    lockerspace[5].space=2.5;
    customerReq[0].req=0.25;
    customerReq[0].lockerno=-1;
    customerReq[1].req=1.5;
    customerReq[1].lockerno=-1;
    customerReq[2].req=2;
    customerReq[2].lockerno=-1;
    customerReq[3].req=1;
    customerReq[3].lockerno=-1;
    customerReq[4].req=0.75;
    customerReq[4].lockerno=-1;
    customerReq[5].req=2.75;
    customerReq[5].lockerno=-1;
    */
    firstFit();
    bestfit();
    worstfit();

}
