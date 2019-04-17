#!/bin/sh
x=`ls * | ls *.txt`
#echo "$x"
y=`echo "$x" | sed -e 's/txt/text/g'`
echo "$y"

