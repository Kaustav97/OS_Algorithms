read bsc ta 
ext=`echo "scale=3 ;0.1*$bsc" | bc `
echo `echo "$bsc + $ta + $ext" | bc `

