#!/bin/sh
#echo "Enter the number:"
#read n
n=$1
a=-1
b=1
i=0
while [ $i -lt $n ]
do
  sum=`expr $a + $b`
  a=$b
  b=$sum
  i=`expr $i + 1`
  echo $i  $sum
done
