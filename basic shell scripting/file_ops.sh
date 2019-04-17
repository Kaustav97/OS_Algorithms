lst=`ls`
for x in $lst;do
 if [ -f $x ];then
  y=`cat $x | grep ^ex:`
  z=`cat $x | grep .ex:`
  for ln in $y;do
   echo "${ln/ex:/Example:}"
  done
  for ln in $z;do 
   echo "${z/.ex:/Example:}"
  done
 fi
done
