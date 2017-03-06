#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>

extern int h_errno;


int main(int argc,char *argv[])
{
	struct hostent *host,*host2;
	int i;
	char hname[30];

	if(argc==2)
	{	
		host=gethostbyname(argv[1]);
		if(host==NULL)
		{

		switch(h_errno)
		{
			case NO_ADDRESS:
				printf("The requested name is valid but does not have an IP address.\n");
				break;
			case NO_RECOVERY:
				printf("A non-recoverable name server error occurred.\n");
				break;
			case TRY_AGAIN:
				printf("A temporary error occurred on an authoritative name server. Try again later.\n");
				break;
			case HOST_NOT_FOUND:
				printf("The specified host is unknown.\n");
				break;
			default:
				printf("Unknown error.\n");
		}
	}
		while(host->h_addr_list[i]!=NULL)
			{
				printf("Name:	%s\n",host->h_name);			
				printf("Address: %u.%u.%u.%u\n",host->h_addr_list[i][0] & 0x000000FF,host->h_addr_list[i][1] & 0x000000FF,host->h_addr_list[i][2] & 0x000000FF,host->h_addr_list[i][3] & 0x000000FF);
				i++;	
			}
		printf("%s",host->h_name);
	}

	else if(argc==1)
	{		
			
		do
		{
			printf(">");
			scanf("%s",&hname);
			host=gethostbyname(hname);
			if(host==NULL)
			{
				printf("There is some error");
	
			}
			while(host->h_addr_list[i]!=NULL)
			{
				printf("Name:	%s\n",host->h_name);			
				printf("Address: %u.%u.%u.%u\n",host->h_addr_list[i][0] & 0x000000FF,host->h_addr_list[i][1] & 0x000000FF,host->h_addr_list[i][2] & 0x000000FF,host->h_addr_list[i][3] & 0x000000FF);
				i++;	
			}
		}while(hname!="exit");
	}
	else
	{
		printf("Invalid Parameters!!\n");
	}

}