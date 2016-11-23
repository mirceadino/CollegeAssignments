#!/bin/bash

report="$1"
echo -n "" > "$report"

for file in `find words*.txt`; do
	for word in `cat test_words.txt`; do
		echo "$word / $file:" >> "$report"
		timeout 60 ./SDA "$file" "$word" | grep -o "\<[0-9]*.[0-9]*s\>" >> "$report"
		if [ $? -eq 124 ]; then
			echo "bla"		
		fi
	done
done
