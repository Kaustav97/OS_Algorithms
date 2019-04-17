x=`cat rec | grep CSE | cut -d ":" -f 5-7 `
echo "$x"
echo "$x" | sed -e 's/:/+/g' | bc

