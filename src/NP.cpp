#include "../include/NP.h"

using namespace std;

void NP::Connect(int port, char *adr) {
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	inet_pton(AF_INET, adr, &saddr.sin_addr.s_addr);
	if (connect(sock, (struct sockaddr*)(&saddr), sizeof(saddr)) != 0) {
		cout << "No connection established." << endl;
		exit(1);
	}
	cout << "\nConnected to server on IP " << adr << " and port " << port << "." << endl;
}

void NP::SendMsg(char msg[], int size) {
	if (send(sock, msg, size, 0) == -1) {
		cout << "Could not send message to server." << endl;
		exit(1);
	}
	cout << "Sent to server:\t\t";
	cout << msg;
}

char* NP::RecvMsg() {
	cout << "Received from server:\t";

    buffer[recv(sock, buffer, 1024, 0)] = '\0'; //0 indexing
    cout << buffer;
	return buffer;
}

void NP::SaveFile(char filename[]) {
	ofstream file;
	file.open(filename);
	char buffer[1];
	int bytes(0);
	cout << "/*****FIRST 1 KB OF FILE**********************************************************************/" << endl;
	while (recv(sock, buffer, sizeof(buffer), 0)) {
		if (bytes < 1024)
			cout << buffer[0];
		file << buffer[0];
		bytes++;
	}
	cout << "\n/*********************************************************************************************/" << endl;
	file.close();
}

void NP::CloseCon() {
	close(sock);
	cout << "Closed connection.\n" << endl;
}
