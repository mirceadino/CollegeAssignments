#!/bin/bash

# 88. b)
# Write a shell script that takes groups  of 3 parameters  (a name of a file a 
# word and a number k).For each groups, print all the lines from the file that 
# contain the word exactly k times.

while [ $# -ne 0 ]; do

	# check if tuple has enough parameters
	echo "\$ Process tuple: $1 | $2 | $3"
	if [ $# -lt 3 ]; then
		echo "\$ Tuple is not complete."
		break
	fi

	# separate tuple and shift the group
	filename=$1
	word=$2
	number=$3

	shift 3

	# check if file exists
	if [ ! -f $filename ]; then
		echo "\$ Filename is invalid."
		continue
	fi

	# check if word is not empty (always true actually)
	if [ -z "$word" ]; then
		echo "\$ Word is empty."
		continue	
	fi

	# check if the number is an integer
	echo "$number" | grep -q "[^0-9]"
	if [ $? -eq 0 ]; then
		echo "\$ Not a number."
		continue		
	fi

	# find matching lines and count them
	nrMatches=0
	for ((i=1; i<=$(cat $filename | wc -l); i++)); do
		line=$(cat "$filename" | head -n "$i" | tail -n 1)
		cnt=$(echo "$line" | grep -o "$word" | wc -l)
		if [ "$cnt" -eq "$number" ]; then
			echo "$line"		
			nrMatches=$(($nrMatches + 1))
		fi
	done

	echo "\$ $nrMatches total number of matches."

done
