#include <stdio.h>
#include <netdb.h>
int main()
{
	struct servent *t;
	int a;

	printf("enter the port number");
	scanf("%d",&a);

	t=getservbyport(htons(a),NULL);

	printf("service name-%s\n",t->s_name);
	return 0;
}