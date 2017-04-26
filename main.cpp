#include <iostream>
#include "src/NP.cpp"


using namespace std;

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
    client.RecvMsg();


    // bruger sscan til at læse svaret fra FTP serveren
    sscanf(client.RecvMsg(), "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d).\r\n", &a1, &a2, &a3, &a4, &p1, &p2);
    dataPort = (p1 * 256) + p2;


    /*
    * data connection START *******************
    */
    cout << "Data port: " << dataPort << endl;
    cout << "Data addressP: " << addressP << endl;
    data.Connect(dataPort, adressP);
    // The following will fail
//    client.SendMsg("LIST\r\n", 6);

	client.RecvMsg();
	data.RecvMsg();


    client.SendMsg("RETR test.txt\r\n", 15);
	//data.SaveFile("/var/www/html/savedTest.txt");
	data.SaveFile("test.txt");

	client.CloseCon();
    data.CloseCon();
	return 0; // test
}
