#!/bin/sh
read pat
read dst
y=`ls *$pat*`
mkdir "$dst"
for x in $y;do
 mv "$x" "$dst/$x"
done

