#!/bin/bash

if [[ -z $1 ]]; then
  echo "usage: $0 <file>"
  exit 1
fi

g++ -E $1.cpp | sed 's/#\(.*\)//g' > $1.toy
