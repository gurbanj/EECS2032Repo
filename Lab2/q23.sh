#!/bin/bash

if [[ "$#" -ge 0 ]]
then
    echo "No command line arguments please"
    read b
    for (( c=0; c<=1000; c++))
    do 
        for (( d=0; d<=1000; d++ )) 
        do 
            if[ $(($b*$b)) == $(( ($) )) ]
fi