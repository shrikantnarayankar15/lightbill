# lightbill

---You'll require mysql-server and libraries for c 'to interact with mysql 'for that download using following command
	$sudo apt-get install mysql-server
	$sudo apt-get install libmysqlclient-dev
---After that create a database with name 'data' execute the following command
	$mysqldump -uroot -p data < data.sql
---it will import the data.sql in your newly created database
1. download all the files
2. run following command 
	$make all
3. after that at client machine run 'client'
4. at server run 'server' 
5. for admin run 'admin'
