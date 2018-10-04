#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

int main(int argc, char *argv[]) {
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;

    char sendBuff[1025];
    time_t ticks;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000);

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(listenfd, 10);

    while(1) {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
      
		char str[]=*argv[2], *p = str;
		int r = 0;
		int *arr;
		int size = sizeof(str[]);
		int sumarr = 0;
		for (int i = 0; i < size; i++) {
			while(*p++) if(*p >= '0' && *p <= '9') r = r*10 + *p - '0';
			cin >> arr[i];
			arr[i] << r;
		}
	
		// Сортировка массива пузырьком
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					// меняем элементы местами
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
				ticks << arr[i] << " ";
				sumarr = sumarr + arr[i];
			}
	
	
		ticks << sumarr;
		
        snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks))
        write(connfd, sendBuff, strlen(sendBuff));

        close(connfd);
        sleep(1);
     }
}