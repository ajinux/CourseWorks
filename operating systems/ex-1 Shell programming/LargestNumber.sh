#!/bin/sh
count=$1 #gets value from the terminal argument

if [ $count -lt 2 ]
then
  echo "Numbers should be greater than one"
  exit 1
fi

echo "Enter the numbers:"
temp=$count
while [ $count -gt 0 ]
do
	read num

	#Executes at the first loop
	if [ $temp -eq $count ]
	then
	  temp=$num
	fi

    #assigns largest number to the temp variable
	if [ $num -gt $temp ]
	then
	  temp=$num
	fi  
    
    #decrementing the count
	count=`expr $count - 1`
done

echo "The largest of $1 numbers is $temp"