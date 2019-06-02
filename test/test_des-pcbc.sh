#!/bin/bash

echo " -------------------- DES-PCBC --------------------"
k="133457799bbCDFF1"
v="1F3c973A9BbCDfF1"
s="13a457799bbCDFF1"
a="a"
echo " ------ a"
counter=1
while [ $counter -le 10 ]
do
  # encrypt and decrypt
  echo "$a" > c1
  echo "$a" | ../ft_ssl des-pcbc -e -k $k -v $v | ../ft_ssl des-pcbc -d -k $k -v $v > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option a ----------------------
  echo "$a" > c1
  echo "$a" | ../ft_ssl des-pcbc -a -e -k $k -v $v | ../ft_ssl des-pcbc -a -d -k $k -v $v > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option p ----------------------
  echo "$a" > c1
  echo "$a" | ../ft_ssl des-pcbc -p -a "test" -s $s | ../ft_ssl des-pcbc -d -p -a "test" -s $s > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  a="$a$a"
  counter=$(($counter+1))
done










a="12gc3c21h1e\\t21\\ne1n2n12vev##12jv"
echo " ------ 12gc3c21h1e\\t21\\ne1n2n12vev##12jv"
counter=1
while [ $counter -le 5 ]
do
  # encrypt and decrypt
  echo "$a" > c1
  echo "$a" | ../ft_ssl des-pcbc -e -k $k -v $v | ../ft_ssl des-pcbc -d -k $k -v $v > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option a ----------------------
  echo "$a" > c1
  echo "$a" | ../ft_ssl des-pcbc -a -e -k $k -v $v | ../ft_ssl des-pcbc -a -d -k $k -v $v > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option p ----------------------
  echo "$a" > c1
  echo "$a" | ../ft_ssl des-pcbc -p -a "test" -s $s | ../ft_ssl des-pcbc -d -p -a "test" -s $s > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  a="$a$a"
  counter=$(($counter+1))
done








a="bjk3245b23jkb5a"
echo " ------ bjk3245b23jkb5a"
counter=1
while [ $counter -le 5 ]
do
  # encrypt and decrypt
  echo "$a" > c1
  echo "$a" | ../ft_ssl des-pcbc -e -k $k -v $v | ../ft_ssl des-pcbc -d -k $k -v $v > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option a ----------------------
  echo "$a" > c1
  echo "$a" | ../ft_ssl des-pcbc -a -e -k $k -v $v | ../ft_ssl des-pcbc -a -d -k $k -v $v > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option p ----------------------
  echo "$a" > c1
  echo "$a" | ../ft_ssl des-pcbc -p -a "test" -s $s | ../ft_ssl des-pcbc -d -p -a "test" -s $s > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  a="$a$a"
  counter=$(($counter+1))
done









# ----------- PDF ------------ #
echo " ------ PDF"
../ft_ssl des-pcbc -e -k $k -v $v -i ./document.pdf -o c1
../ft_ssl des-pcbc -d -k $k -v $v -i c1 -o c2
ret=$(diff -u ./document.pdf c2)

if [ "$ret" != "" ]
then
    echo "Pdf"
    echo $ret
    exit
fi









# ----------- IMAGE ------------ #
echo " ------ IMAGE"
../ft_ssl des-pcbc -e -k $k -v $v -i ./image.png -o c1
../ft_ssl des-pcbc -d -k $k -v $v -i c1 -o c2
ret=$(diff -u ./image.png c2)

if [ "$ret" != "" ]
then
    echo "Image"
    echo $ret
    exit
fi


rm c1 c2

echo All done
