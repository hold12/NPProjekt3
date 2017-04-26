#include <iostream>
#include "src/NP.cpp"
#include <sstream>
#include <fstream>
#include <string.h> // strlen
#include <string>   // string


using namespace std;

int GetNewPort(string str);

int main()
{
    char adress[] = "10.42.0.3";
    char *adressP = adress;

    int dataPort,a1,a2,a3,a4,p1,p2;

    NP client, data;

    client.Connect(21, adressP);
    client.RecvMsg();

    client.SendMsg("HELLO\r\n", 7);
    client.RecvMsg();

    client.SendMsg("USER anonymous\r\n", 16);
    client.RecvMsg();
    client.SendMsg("PASS 1234\r\n", 11);
    client.RecvMsg();

    // passive mode
    client.SendMsg("PASV\r\n", 6);

    string pasv_message = string(client.RecvMsg());
    cout << "msg received" << endl;
    dataPort = GetNewPort(pasv_message);
    cout << "data port calculated" << endl;

    /*
    * data connection START *******************
    */
    cout << "Data port: " << dataPort << endl;
    cout << "Data addressP: " << adressP << endl;
    data.Connect(dataPort, adressP);

    client.SendMsg("RETR data.csv\r\n", 15);
	
    data.SaveFile("/var/www/data.csv");
	//data.SaveFile("test.txt");

    client.RecvMsg();
    cout << "receive 2" << endl;
    client.RecvMsg();

    cout << "closing client" << endl;

	client.CloseCon();
    cout << "closing data" << endl;
    data.CloseCon();
	return 0; // test
}

int GetNewPort(string str)
{
    stringstream ss(str);
    for (int i = 0; i < 4; i++)
        getline(ss, str, ',');

    int num1, num2;

    ss >> num1;
    ss.ignore(1);
    ss >> num2;

    return num1 * 256 + num2;
}
