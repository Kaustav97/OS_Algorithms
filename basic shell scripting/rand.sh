for x in *q*;do  
 mv "$x" "${x/q__/q_}"
done
echo "Done!"
