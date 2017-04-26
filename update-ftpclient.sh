#!/bin/bash
rm -rf ftpclient/ master.zip /var/www/highest.txt
wget https://github.com/hold12/NPProjekt3/archive/master.zip --no-check-certificate
unzip master.zip
mv NPProjekt3-master/ ftpclient
cd ftpclient
g++ -o ftpclient main.cpp

echo;: echo "===================================================="; echo;

update-csv