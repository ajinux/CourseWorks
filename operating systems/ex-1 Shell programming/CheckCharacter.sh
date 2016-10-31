#!/bin/sh
string=$1
char=$2
index=`expr index "$string" $char`
if [ $index -gt 0 ]
then 
  echo "The character '$char' is present in string '$string' at index $index"
else
  echo "The character '$char' is not present in the string '$string'"
fi 
