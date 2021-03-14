#!/bin/bash

if [ ! -f "names.txt" ] || [ ! -f "courses.txt" ]	
then
	echo "One or both files do not existing"
	exit 1
fi
    ag=$1
    counter=0
if [ $ag == "-count" ] 
then
	   while read a b
	   do
		   counter=$(($counter+1))
	   done <"names.txt"
	   echo $counter
	   exit 1

   elif [ $ag == "-f" ]
   then
	   stdFound=0 
	   if [ $# -eq 3 ] 
	   then

	   IFS=$'\t'
	   while read name ID
	   do
		   if [ "$2 $3" == $name ] 
		   then
			   stdFound=$((stdFound+1))
			   selected=$ID
			   while read ID course grade
			   do
				   if [ $selected == $ID ] 
				   then
					 if [ -z $grade ]
					 then
						 echo "$course	in progress"
					 else
						 echo "$course	$grade"
					 fi
				 fi
			 done <"courses.txt"
		 fi
	 done <"names.txt"
	 if [ $stdFound -eq 0 ] 
	 then
		 echo "No such student: $2 $3"
		 exit 1
	 fi

 	 elif [ $# -eq 2 ] 
	 then
		stdName=$2
		IFS=$'\t'
		while read name ID 
		do
			if [ "$stdName" == $name ]
			then
				selected=$ID
				stdFound=$((stdFound+1))
				while read ID course grade
				do
					if [ $selected == $ID ]
					then
						if [ -z $grade ]
						then
							echo "$course	in progress"
						else
							echo "$course	$grade"
						fi
					fi
				done <"courses.txt"
			fi
		done <"names.txt"
		if [ $stdFound -eq 0 ] 
		then
			echo "No such student: $stdName"
			exit 1
		fi
	fi	

	elif [ $ag == "-g" ]
	then
		stdFound=0
		if [ $# -eq 3 ]
		then
		IFS=$'\t'
		while read name ID
		do
			if [ "$2 $3" == $name ] 
			then
				selected=$ID
				stdFound=$((stdFound+1))
                            	IFS=$'\t'
                            	while read ID course grade
				do
					if [ ! -z $grade ] && [ $ID == $selected ] 
					then
						echo "$course	$grade"
					fi
				done <"courses.txt"
			fi
		done <"names.txt"
		if [ $stdFound -eq 0 ]
		then
			echo "No such student: $2 $3"
			exit 1
		fi
		elif [ $# -eq 2 ]
		then
			stdName=$2
			IFS=$'\t'
			while read name ID
			do
				if [ "$stdName" == $name ]
				then
					selected=$ID
					stdFound=$(($stdFound+1))
					IFS=$'\t'
					while read ID course grade
					do
						if [ ! -z $grade ] && [ $ID == $selected ]
						then
							echo "$course	$grade"
						fi
					done < "courses.txt"
				fi
			done < "names.txt"
			if [ $stdFound -eq 0 ]
			then
				echo "No such student: $2"
				exit 1
			fi
		fi

	elif [ $ag == "-c" ] 
	then
		courseCount=0
		IFS=$'\t'
		while read ID course grade
		do
			if [ $course == $2 ] 
			then
				courseCount=$((courseCount+1))
			fi
		done <"courses.txt"

		echo "$courseCount"
	elif [ $ag == "-list" ]
	then
		courseGrade=0
		IFS=$'\t'
		while read ID course grade
		do
			if [ ! -z $grade ] && [ $2 == $course ] && [ "$3" == $grade ] 
			then
				courseGrade=$((courseGrade+1))
			fi
		done <"courses.txt"
		
		echo "$courseGrade"
fi