#!/bin/bash

read a b c

for (( ;; ))
do
    if [[ "$a" -lt "$b" && "$b" -lt "$c" ]]
    then
        echo $b
        exit
    else 
        echo "NO"
        read a b c
    fi
done
