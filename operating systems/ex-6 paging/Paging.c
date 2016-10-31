#include<stdio.h>
int main()
{
	int n,i,a[1000],b[1000],fr[100],h[100],s,fifo=0,lfu=0,j,k,flag,flag1,pos,min;
	printf("Enter the no of pages:\n");
	scanf("%d",&n);
	printf("Enter the reference pages:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	printf("Enter the page frame size\n");
	scanf("%d",&s);
	fifo=fifo+s;
	lfu=lfu+s;
	for(i=s;i<n;i++)
	{
		flag=0;
		for(j=0;j<s;j++)
		{
			if(b[i]==b[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			k=0;
			while(k<s-1)
			{
				b[k]=b[k+1];
				k++;
			}
			b[k]=b[i];
			fifo++;
		}
	}
	for(i=0;i<s;i++)
	{
		fr[i]=1;
		h[i]=i+1;
	}
	for(i=s;i<n;i++)
	{
		flag=0;
		for(j=0;j<s;j++)
		{
			if(a[i]==a[j])
			{
				flag=1;
				fr[j]+=1;
				break;
			}
		}
		k=0;
		min=99999;
		pos=0;
		flag1=0;
		if(flag==0)
		{
			//printf("for i=%d\n",i+1);
			while(k<s)//minimum frequency
			{
				if(fr[k]<min)
				{
					min=fr[k];
					pos=k;
				}
				else if(fr[k]==min)
				{
					flag1=1;
					break;
				}
				k++;
			}
			if(flag1==0)//have minimum frequency
			{
				//printf("Hello2");
				a[pos]=a[i];
				//printf("pos=%d",pos);
				fr[pos]=1;
				h[pos]=i;
				lfu++;
			}
			else//two same frequency
			{
				//printf("hello3");
				k=0;
				min=9999;
				while(k<s)//find oldest one
				{
					//printf("h=%d  ",h[k]);
					if(h[k]<min && fr[k]==1)
					{
						min=h[k];
						pos=k;
					}
					k++;
				}
				a[pos]=a[i];
				//printf("pos=%d",pos);
				fr[pos]=1;
				h[pos]=i+1;
				lfu++;
			}
			/*
			for(k=0;k<s;k++)
			{
				printf("%d  ",a[k]);
			}
			printf("\n");
			*/
		}
	}
	printf("Fifo Page Faults=%d\n",fifo);
	printf("Lfu Page Faults=%d\n",lfu-1);
	return 0;

}
