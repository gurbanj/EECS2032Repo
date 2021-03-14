#!/bin/bash
x=$1
y=$2
z=$3
w=$4
count = 0
for(( a=1; a<=$x; a++ ))
do
    for(( b=1; b<=$y; b++ ))
    do
        for(( c=1; c<=$z; c++ ))
        do
            for(( d=1; d<=$w; d++ ))
            do
               first=$(($a**3 + $b**3))
               second=$(($c**3 + $d**3))

                if [ $first -eq $second ]; 
                then
                    echo "x= $a, y= $b, z= $c, w= $d"
                    count=1
                fi
            done
        done
    done
done
if [ $count -ne 1 ]
then 
echo "No solution"
fi