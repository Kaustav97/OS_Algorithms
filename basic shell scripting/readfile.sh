read fl
l=`wc -l $fl | cut -d " " -f 1`
for((i=1;i<=$l;++i));do
 t=`echo "$i"%2 | bc`
 if (($t % 2 == 1));then
  echo `head -$i data | tail -1`
 fi
done


