#!/bin/bash

# 88. a)
# Write a shell script that continuously reads user names from keyboard and
# for each of them outputs it's full name, the number of processes and the 
# current running command.
while [ true ]; do

	# read username
	echo -n "Read username: "
	read username

	# check if line is empty and stop script if so
	if [ "$username" == "" ]; then
		echo "Script stopped."
		break
	fi

	# check if username is valid
	userInfo=$(grep "^$username:" /etc/passwd)
	if [ $? -ne 0 ]; then
		echo "Username is not valid."
		continue
	fi

	# find username, processes and their number
	fullName=$(echo "$userInfo" | cut -d":" -f5 | cut -d"," -f1)
	processes=$(w -h "$username" | awk -f getProcesses.awk)
	nrProcesses=$(ps -ef | wc -l)

	# print information
	echo "Full name is $fullName."
	echo "Number of processes is $nrProcesses."
	echo "Current command is: $processes."

done
