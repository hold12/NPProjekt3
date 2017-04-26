#!/bin/bash
if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

rm -f /var/www/highest.txt
rm -f /tmp/data.csv
/home/awo/ftpclient/ftpclient
python /home/awo/ftpclient/read_csv.py
#ln -s /home/awo/ftpclient/highest.txt /var/www/
