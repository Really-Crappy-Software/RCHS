#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
    int charlie;
     FILE *methamphetamine;
     FILE *insertfunny;
    int port = atoi(argv[1]);
        char buffer[1024];
    char response[100000] = "HTTP/1.0 200 OK\r\n"
                  "Server: webserver-c\r\n"
                  "Content-type: text/html\r\n\r\n";

int sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0) {
    printf("socket not created");
    return -1;
} else {
printf("My name is Walter Hartwell White. I live at 308 Negra Arroyo Lane, Albuquerque, New Mexico, 87104\n");
}
struct sockaddr_in http, client;
http.sin_port = htons(port);
http.sin_family = AF_INET;
http.sin_addr.s_addr = inet_addr("127.0.0.1");
int httplen = sizeof(http);
struct sockaddr *addr = (struct sockaddr *)&http;
if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, httplen) < 0) {
    printf("Could not set socket options\n");
    return -1;
}
int mikumikubeam = bind(sockfd, addr, httplen);
if (mikumikubeam < 0) {
    printf("couldn't bind socket\n");
    printf("%d\n", mikumikubeam);
    return -1;
} else {
printf("socket binded\n");
}
if (listen(sockfd, SOMAXCONN) < 0) {
    printf("Cannot listen to incoming connections\n");
    return -1;
} else {
printf("listening\n");
}
while (1) {
int sockfd2 = accept(sockfd, addr, &httplen); // Introducing sockfd2: more socks than ever. coming in a theater near you soon
if (sockfd2 < 0) {
    printf("Can't accept connections\n");
    return -1;
} else {
printf("RCHS: accepting connections since right now\n");
if (read(sockfd2, buffer, 1024) < 0) {
printf("cannot read sockfd2\n");
return -1;
} else {
printf("No longer illiterate\n");
}
char request[1024], file[1024];
sscanf(buffer, "%s %s", request, file);
if (strcmp(request, "GET") == 0) {
    char location[100];
    if (strcmp(file, "/") == 0) {
    methamphetamine = fopen("index.html", "r");
if (methamphetamine == NULL) {
    printf("index.html not found! creating a stock one\n");
    insertfunny = fopen("index.html", "w");
    fprintf(insertfunny, "<html> <body> <center> <h1> Welcome to The Really Crappy HTTP Server </h1> </center> </body> </html");
    fclose(insertfunny);
    methamphetamine = fopen("index.html", "r");
} else {
    struct stat fleszep;
    if (stat("index.html", &fleszep) < 0) {
    printf("couldn't stat index.html\n");
    return -1;
    } else {
    printf("Filesize: %lld\n", fleszep.st_size);
    printf("1\n");
    charlie = fleszep.st_size;
    }
char begacheese[charlie];
fread(begacheese, 1, charlie, methamphetamine);
printf("2\n");
strcat(response, begacheese);
fclose(methamphetamine);
}
    } else {
    memmove(file, file + 1, 1023);
        methamphetamine = fopen(file, "r");
if (methamphetamine == NULL) {
    printf("%s not found! going to 404\n", file);
        insertfunny = fopen("404.html", "w");
    fprintf(insertfunny, "<html> <body> <center> <h1> 404: File Not Found </h1> </center> </body> </html");
    fclose(insertfunny);
    methamphetamine = fopen("404.html", "r");
} else {
    struct stat fleszep;
    if (stat("index.html", &fleszep) < 0) {
    printf("couldn't stat index.html\n");
    return -1;
    } else {
    printf("Filesize: %lld\n", fleszep.st_size);
    printf("1\n");
    charlie = fleszep.st_size;
    }
char begacheese[charlie];
fread(begacheese, 1, charlie, methamphetamine);
printf("2\n");
strcat(response, begacheese);
fclose(methamphetamine);
}
    }
}
if (write(sockfd2, response, strlen(response)) < 0) {
    printf("couldn't send the html\n");
    return -1;
} else {
printf("You are actually using this rubbish?\n");
}
close(sockfd2);
}
}
}
