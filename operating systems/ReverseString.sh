#!/bin/bash

string=$1
len=`expr length $string`
echo $len  
result=""
#ref:http://tldp.org/LDP/abs/html/string-manipulation.html
#reverse a string without using inbuild function
#echo $string | rev
for(( i=$len-1; i>=0; i-- ))
do
  result="$result${string:$i:1}"
done
echo "The reversed string is $result"