#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h> 
#include <arpa/inet.h>

int get_ip(char *  , char *);

int main(int argc , char *argv[])
{
  if(argc <2)     
    {
      printf("Please provide a hostname");         
      exit(1);
    }     
    char *hostname = argv[1];     
    char ip[100];     
    get_ip(hostname , ip);     
    printf("%s resolved to %s" , hostname , ip);     
    printf("\n");} 

int get_ip(char * hostname , char* ip) 
{  
   struct hostent *he;     
   struct in_addr **addr_list;     
   int i;     
   if ( (he = gethostbyname( hostname ) ) == NULL)     
   { 
    herror("gethostbyname");         
     return 1;
   }     
   addr_list = (struct in_addr **) he->h_addr_list;

    for(i = 0; addr_list[i] != NULL; i++)
    {   
      strcpy(ip , inet_ntoa(*addr_list[i]) );
      printf("The address is %s \n", ip);
        //return 0;
    }
    return 1;
}