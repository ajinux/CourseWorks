#include <stdio.h>
#include <netdb.h>
int main()
{
	struct servent *t;
	char a[100];

	printf("enter the service name");
	scanf("%s",a);

	t=getservbyname(a,"tcp");

	if(t!=NULL)	
	printf("port number-%d\n",ntohs(t->s_port));
	else
	printf("service name error");
	return 0;
}