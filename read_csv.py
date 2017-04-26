import csv, os, os.path
with open('/home/awo/ftpclient/data.csv', 'rb') as f:
   reader = csv.reader(f)
   csv_list = list(reader)

highest_value = 0

for i in csv_list[1::]:
   itotal = 0
   for j in i[1::]:
        itotal += int(j)

   if itotal > highest_value:
      highest_value = itotal

if os.path.isfile('/home/awo/ftpclient/highest.txt'):
	os.remove('/home/awo/ftpclient/highest.txt')
file = open('/home/awo/ftpclient/highest.txt', 'w')
file.write(str(highest_value))
file.close
print highest_value
