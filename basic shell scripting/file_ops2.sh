ls ../* -al | grep ^[d,-] |rev | cut -d " " -f 1,2 | rev > data
x= `cat data`

for i in $x ; do
 t=`echo "$i" | cut -d " " -f 1 | cut -d ":" -f 1`
 fl=`echo "$i" | cut -d " " -f 2`
 echo " TIME - $t"
done


fl=$1
if [ -d "${fl}" ] ; then
 echo "folder"
else 
 echo "file"
fi

