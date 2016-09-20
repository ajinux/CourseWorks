#include<stdio.h>
#include<float.h>

int n,i,status[10],j;
float s[10],c[10];

void firstfit()
{
    for(j=0;j<n;j++)
   {
       status[j]=-1;
   }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(status[j]==-1 && c[i]<=s[j])
            {
                status[j]=i+1;
                break;
            }
        }
    }
    printf("\nThe status of each space is as follows in first fit:\n");
    for(i=0;i<n;i++)
    {
        if(status[i]!=-1)
        {
            printf("%d space-%d customer\n",i+1,status[i]);
        }

    }
}

void bestfit()
{

    for(i=0;i<n;i++)
    {
        status[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        float best=FLT_MAX;
        int pos=0;
        for(j=0;j<n;j++)
        {
            if(status[j]==-1 && c[i]<=s[j])
            {
                if(s[j]<best)
                {
                    best=s[j];
                    pos=j;
                }
            }
        }
        if(best!=FLT_MAX)
        {
            status[pos]=i+1;
        }
    }

    printf("\nThe status of each space is as follows in best fit:\n");
    for(i=0;i<n;i++)
    {
        if(status[i]!=-1)
        {
            printf("%d space - %d customer\n ",i+1,status[i]);
        }

}
}

void worstfit()
{

    for(i=0;i<n;i++)
    {
        status[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        float worst=FLT_MIN;
        int pos=0;
        for(j=0;j<n;j++)
        {
            if(status[j]==-1 && c[i]<=s[j])
            {
                if(s[j]>worst)
                {
                    worst=s[j];
                    pos=j;
                }
            }
        }
        if(worst!=FLT_MIN)
        {
            status[pos]=i+1;
        }
    }

    printf("\nThe status of each space is as follows in worst fit:\n");
    for(i=0;i<n;i++)
    {
        if(status[i]!=-1)
        {
            printf("%d space - %d customer\n ",i+1,status[i]);
        }
    }
}


main()
{

    printf("enter n\n");
    scanf("%d",&n);

    printf("Enter the space size\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&s[i]);
    }
    printf("Enter the customer requirement size\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&c[i]);
    }

    firstfit();
    bestfit();
    worstfit();
}
