#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include <netinet/in.h>
#define PORT 1234

int main()
{
 
 int server_sock = socket(AF_INET, SOCK_DGRAM, 0);
 
 struct sockaddr_in server_address;

 memset(&server_address, '0', sizeof(server_address));
 printf("Setting up the server..\n");
 fflush(stdout);
 server_address.sin_family = AF_INET;
 server_address.sin_port = htons(PORT);
 server_address.sin_addr.s_addr = htonl(INADDR_ANY);
 
 
 int bind_status = bind(server_sock, (const struct sockaddr *)&server_address, sizeof(server_address));
 printf("Socket binded\n");
 fflush(stdout);
 listen(server_sock, 10);
 
 int client_socket;
 printf("Listening port %d\n", PORT);
 client_socket = accept(server_sock,(struct sockaddr*)NULL, NULL);

 FILE* html_data;
 html_data = fopen("index.html", "r");
 char response_data[3024]; 
 //fgets(response_data, 3024, html_data);
 size_t newLen = fread(response_data, sizeof(char), 3024, html_data);
 response_data[++newLen] = '\0';

 char http_header[1500] = "HTTP/1.1 200 OK\r\n\n";

 strcat(http_header, response_data);

 send(client_socket, &http_header, sizeof(http_header), 0);
 printf("\nData send successfully!");
 close(server_sock);
 printf("Socket closed\n"); 

 return 0;
} 


