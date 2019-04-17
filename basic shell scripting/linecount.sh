act=$2
fl=$1

case $act in
 "-linecount" ) echo `wc -l $fl` ;;
 "-charcount" ) echo `wc -c $fl` ;;
 "-wordcount" ) echo `wc -w $fl` ;;
 * ) echo "NONE";;
esac

