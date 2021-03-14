if [ $# -ne 2 ]
then
    echo  usage: script_name dir file 
    exit
else
    if [ ! -d $1 ]
    then
        echo "$1 is not a directory"
        exit

    elif [ ! -f $2 ]
    then 
        echo "$2 is not a regualar file"
        exit
        
    else
        test=$1/$2

        if [ -f $test ]
        then
            echo "file $2 is in directory $1"
        else
            echo "file $2 is not in directory $1"
        fi
    fi
fi