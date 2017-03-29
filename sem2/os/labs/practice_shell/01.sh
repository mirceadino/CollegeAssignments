#!/bin/bash

if [ "$1" == "" ] || [ ! -f $1 ]; then
	echo "Parameter not a file."
	exit 1
fi

if [ $(cat $1 | grep -o "\<[^ ]*\>" | wc -l) -lt 3 ]; then
	echo "Not enough words in file."
	exit 2
fi

word1=""
word2=""
word3=""

for word in $(cat $1); do
	if [ "$word1" == "" ]; then
		word1=$word
	elif [ "$word2" == "" ]; then
		word2=$word
	elif [ "$word3" == "" ]; then
		word3=$word
	else
		break
	fi
done

aux="pl1lceha0rdelrer"

filecontent=$(cat "$1")
filecontent=$(echo "$filecontent" | sed "s/\<$word3\>/$aux/")
filecontent=$(echo "$filecontent" | sed "s/\<$word2\>/$word3/")
filecontent=$(echo "$filecontent" | sed "s/\<$word1\>/$word2/")
filecontent=$(echo "$filecontent" | sed "s/\<$aux\>/$word1/")

echo "$filecontent" > $1
