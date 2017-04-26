#ifndef NP_H
#define NP_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <fstream>

using namespace std;
class NP
{
public:
	void Connect(int port, char *adr);
	void SendMsg(char msg[], int size);
	char* RecvMsg();
	void SaveFile(char filename[]);
	void CloseCon();
	int sock;
private:
	struct sockaddr_in saddr;
	char buffer[1024];
};

#endif // NP_H
