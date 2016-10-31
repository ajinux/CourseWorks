#!/bin/bash
n=$1
temp=$n
sum=0
digit=0

while [ $temp -gt 0 ]
do
  temp=`expr $temp / 10`
  digit=`expr $digit + 1`
done

while [ $n -gt 0 ]
do
  re=`expr $n % 10`
  n=`expr $n / 10`
  val=$[$re**$digit]
  sum=`expr $sum + $val`
done
if [ $sum == $1 ]
then
  echo "$1 is an armstrong number"
else
  echo "$1 is not an armstrong number"
fi
