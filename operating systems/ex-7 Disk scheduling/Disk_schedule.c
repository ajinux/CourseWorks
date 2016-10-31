#include<stdio.h>
int cap,pos,n,pos1,max,min;
void fcfs(int b[])
{
int p,i,seek=0;
p=pos;
for(i=0;i<n;i++)
{
	seek=seek+sub(b[i],p);
	p=b[i];
}
printf("FCFS seek time:%d ms\n",seek);
}
void sstf(int b[])
{
	int p,i,seek=0,min1=9999,diff,j,flag[1000],p1;
	p=pos;
	for(i=0;i<n;i++)
	{
		flag[i]=0;
	}
	for(i=0;i<n;i++)
	{
		min1=9999;
		for(j=0;j<n;j++)
		{
			diff=sub(b[j],p);
			if(diff<min1 && flag[j]==0)
			{
				min1=diff;
				p1=j;
			}
		}
		seek=seek+min1;
		flag[p1]=1;
		p=b[p1];
	}
	printf("SSTF seek time:%d ms\n",seek);
}
void scan(int b[])
{
	int i,seek=0,p;
	p=pos;
	if(pos1>pos)
	{
		seek=p+max;
	}
	else
	{
		seek=(cap-p)+min;
	}
	printf("SCAN seek time:%d ms\n",seek);
}
void look(int b[])
{
  int i,seek=0,p;
	p=pos;
	if(pos1>pos)
	{
		seek=(p-min)+(max-min);
	}
	else
	{
		seek=(max-p)+(max-min);
	}
	printf("LOOK seek time:%d ms\n",seek);
}
int sub(int x,int y)
{
	if(x>y)
	{
		return x-y;
	}
	else
	{
		return y-x;
	}
}
int main()
{
	int i,a[1000],j,c[1000];
	printf("Enter the cylinder maximum capacity\n");
	scanf("%d",&cap);
	printf("Enter the no of cylinder request\n");
	scanf("%d",&n);
	printf("Enter the cylinder no within capacity to be requested\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(c[j]<c[i])
			{
				int temp;
				temp=c[j];
				c[j]=c[i];
				c[i]=temp;
			}
		}
	}
	max=c[n-1];
	min=c[0];
	printf("Enter the current r/w pointer position\n");
	scanf("%d",&pos);
	printf("Enter the previous r/w pointer position\n");
	scanf("%d",&pos1);

	fcfs(a);
	sstf(a);
	scan(a);
	look(a);
}
