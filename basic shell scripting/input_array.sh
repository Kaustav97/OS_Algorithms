#!/bin/sh
declare -a arr

myfunc() {
 arr1=("${!1}")
 for x in ${arr1[@]};do
  echo $x | tr 'a-z' '0-9'
 done
}

read len
for ((i=0;i<len;i++));do
 read arr[$i]
done

myfunc arr[@]

