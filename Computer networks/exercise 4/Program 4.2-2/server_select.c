#include <stdio.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>

#define MAXLINE 20
#define SERV_PORT 7134
main(int argc,char **argv)
{

 int i,j,maxi,maxfd,listenfd,connfd,sockfd;
 int nread,client[FD_SETSIZE]; // FD_SETSIZE - Maximum number of file descriptor 
 ssize_t n;
 fd_set rset,allset;
 char line[MAXLINE];
 socklen_t clilen;
 struct sockaddr_in cliaddr,servaddr; 

 listenfd=socket(AF_INET,SOCK_STREAM,0); // will retur the socket file descriptor

 bzero(&servaddr,sizeof(servaddr));
 servaddr.sin_family=AF_INET;
 servaddr.sin_port=htons(SERV_PORT);
 bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
 listen(listenfd,1);
 maxfd=listenfd;
 maxi=-1;

 for(i=0;i<FD_SETSIZE;i++)
 client[i]=-1;

 FD_ZERO(&allset);
 FD_SET(listenfd,&allset);
 	
 for(; ;)
 {
 rset=allset;
 nread=select(maxfd+1,&rset,NULL,NULL,NULL);

 if(FD_ISSET(listenfd,&rset))
 {
	 clilen=sizeof(cliaddr);
	 connfd=accept(listenfd,(struct sockaddr*)&cliaddr,&clilen);
	 for(i=0;i<FD_SETSIZE;i++)
	 if(client[i]<0)
	 {
		 client[i]=connfd;
		 break;
	 }
	 if(i==FD_SETSIZE)
	 {
		 printf("too many clients");
		 exit(0);
	 }
	 FD_SET(connfd,&allset);
	 if(connfd>maxfd)
	   maxfd=connfd;
	 if(i>maxi)
	   maxi=i;
	 if(--nread<=0)
	   continue;
  }
	for(i=0;i<=maxi;i++)
	{
		if((sockfd=client[i])<0)
		 continue;
		if(FD_ISSET(sockfd,&rset))
		    {
			    if((n=read(sockfd,line,MAXLINE))==0)
			    {
					close(sockfd);
					FD_CLR(sockfd,&allset);
					client[i]=-1;
				}
				else
				{
					printf("line recieved from the client :%s\n",line);
					for(j=0;line[j]!='\0';j++)
					line[j]=toupper(line[j]);
					write(sockfd,line,MAXLINE);
				}
				if(--nread<=0)
				  break;

			}
	 }
 }
}