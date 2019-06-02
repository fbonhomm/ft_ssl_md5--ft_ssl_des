#!/bin/bash

echo " -------------------- BASE64 --------------------"
echo " ------ a"
a="a"
counter=1
while [ $counter -le 10 ]
do
  # ---------------------- normal ----------------------
  # ---- encrypt ----
  echo "$a" | openssl base64 > c1
  echo "$a" | ../ft_ssl base64 > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---- decrypt ----
  openssl base64 -d < c2 > c3
  ../ft_ssl base64 -d < c1 > c4
  ret=$(diff -u c3 c4)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  a="$a$a"
  counter=$(($counter+1))
done













echo " ------ a2"
a="a"
b="a"
counter=1
while [ $counter -le 80 ]
do
  # ---------------------- normal ----------------------
  # ---- encrypt ----
  echo "$a" | openssl base64 > c1
  echo "$a" | ../ft_ssl base64 > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---- decrypt ----
  openssl base64 -d < c2 > c3
  ../ft_ssl base64 -d < c1 > c4
  ret=$(diff -u c3 c4)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  a="$a$b"
  counter=$(($counter+1))
done










echo " ------ 12gc3c21h1e\\t21\\ne1n2n12vev##12jv"
a="12gc3c21h1e\\t21\\ne1n2n12vev##12jv"
counter=1
while [ $counter -le 5 ]
do
  # encrypt
  echo "$a" | openssl base64 > c1
  echo "$a" | ../ft_ssl base64 > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # decrypt
  openssl base64 -d < c2 > c3
  ../ft_ssl base64 -d < c1 > c4
  ret=$(diff -u c3 c4)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  a="$a$a"
  counter=$(($counter+1))
done










echo " ------ bjk3245b23jkb5a"
a="bjk3245b23jkb5a"
counter=1
while [ $counter -le 5 ]
do
  # encrypt
  echo "$a" | openssl base64 > c1
  echo "$a" | ../ft_ssl base64 > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # decrypt
  openssl base64 -d < c2 > c3
  ../ft_ssl base64 -d < c1 > c4
  ret=$(diff -u c3 c4)

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
openssl base64 -in ./document.pdf -out c1
../ft_ssl base64 -i ./document.pdf -o c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
    echo "pdf"
    echo $ret
    exit
fi

openssl base64 -d -in c2 -out c3
../ft_ssl base64 -d -i c1 -o c4
ret=$(diff -u c3 c4)

if [ "$ret" != "" ]
then
    echo "pdf"
    echo $ret
    exit
fi








# ----------- IMAGE ------------ #
echo " ------ IMAGE"
openssl base64 -in ./image.png -out c1
../ft_ssl base64 -i ./image.png -o c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
    echo "image"
    echo $ret
    exit
fi

openssl base64 -d -in c2 -out c3
../ft_ssl base64 -d -i c1 -o c4
ret=$(diff -u c3 c4)

if [ "$ret" != "" ]
then
    echo "image"
    echo $ret
    exit
fi


rm c1 c2 c3 c4

echo All done
