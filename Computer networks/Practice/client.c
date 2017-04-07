#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>

#define PORT 1234

int main()
{
    
	 int network_sock;
	 network_sock = socket(AF_INET, SOCK_STREAM, 0);
	 char client_msg[255] = "A message from client!";
	 struct sockaddr_in server_address;
	 server_address.sin_family = AF_INET;
	 server_address.sin_port = htons(PORT);
	 server_address.sin_addr.s_addr = INADDR_ANY; //to connect locally(loop-back ip) 
	 
	 int connection_status;
	 printf("A connection is being initiated..\n");
	 connection_status = connect(network_sock,(struct sockaddr*)&server_address, sizeof(server_address));
	 
	 if(connection_status == -1)
	 {
	   printf("There was an error in making remote socket! : \n");
	   printf("\n Error is : %d\n", errno);
	   return 1;
	 }
	 printf("Connected successfully!\n");
	 
	 char server_response[256];
	 send(network_sock, &client_msg, sizeof(client_msg), 0);
	 printf("Client(Send): %s\n", client_msg);
	 recv(network_sock, &server_response, sizeof(server_response), 0);
	 printf("Server(recv): %s\n", server_response);
	 close(network_sock);
	 printf("\nConnection closed\n");
	 return 0;
}
