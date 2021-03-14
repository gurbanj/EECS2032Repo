#!/bin/bash

contig=true
while true
do 
    read console;
    if [ $console -lt 0 ] 
    then 
        break;
    fi
    integerArray+=($console)
done
for ((i=1; i < ${#integerArray[@]}; i++))
do
    if [ ${integerArray[0]} -ne $((${integerArray[i]}-$i)) ]
    then 
        contig=false
    fi
done   
if [ "$contig" = "true" ] 
then 
    echo "YES"
    exit
else
    echo "NO"
    exit
fi