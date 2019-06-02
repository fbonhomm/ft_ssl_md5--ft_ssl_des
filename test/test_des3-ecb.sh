#!/bin/bash

echo " -------------------- DES3-CBC --------------------"
k="3257823659782567642785682c4695718247568264574"
a="a"
echo " ------ a"
counter=1
while [ $counter -le 10 ]
do
  # encrypt
  echo "$a" | openssl enc -des-ede3 -K $k > c1
  echo "$a" | ../ft_ssl des3-ecb -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # decrypt
  openssl enc -d -des-ede3 -K $k < c2 > c3
  ../ft_ssl des3-ecb -d -k $k < c1 > c4
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




a="a"
b="a"
echo " ------ a2"
counter=1
while [ $counter -le 10 ]
do
  # encrypt
  echo "$a" | openssl enc -des-ede3 -K $k > c1
  echo "$a" | ../ft_ssl des3-ecb -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # decrypt
  openssl enc -d -des-ede3 -K $k < c2 > c3
  ../ft_ssl des3-ecb -d -k $k < c1 > c4
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





a="12gc3c21h1e\\t21\\ne1n2n12vev##12jv"
echo " ------ 12gc3c21h1e\\t21\\ne1n2n12vev##12jv"
counter=1
while [ $counter -le 5 ]
do
  # encrypt
  echo "$a" | openssl enc -des-ede3 -K $k > c1
  echo "$a" | ../ft_ssl des3-ecb -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # decrypt
  openssl enc -d -des-ede3 -K $k < c2 > c3
  ../ft_ssl des3-ecb -d -k $k < c1 > c4
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




a="bjk3245b23jkb5a"
echo " ------ bjk3245b23jkb5a"
counter=1
while [ $counter -le 5 ]
do
  # encrypt
  echo "$a" | openssl enc -des-ede3 -K $k > c1
  echo "$a" | ../ft_ssl des3-ecb -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # decrypt
  openssl enc -d -des-ede3 -K $k < c2 > c3
  ../ft_ssl des3-ecb -d -k $k < c1 > c4
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
openssl enc -des-ede3 -K $k -in ./document.pdf -out c1
../ft_ssl des3-ecb -k $k -i ./document.pdf -o c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
    echo "Pdf"
    echo $ret
    exit
fi

openssl enc -des-ede3 -d -K $k -in c2 -out c3
../ft_ssl des3-ecb -d -k $k -i c1 -o c4
ret=$(diff -u c3 c4)

if [ "$ret" != "" ]
then
    echo "Pdf"
    echo $ret
    exit
fi





# ----------- IMAGE ------------ #
echo " ------ IMAGE"
openssl enc -des-ede3 -K $k -in ./image.png -out c1
../ft_ssl des3-ecb -k $k -i ./image.png -o c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
    echo "Image"
    echo $ret
    exit
fi

openssl enc -des-ede3 -d -K $k -in c2 -out c3
../ft_ssl des3-ecb -d -k $k -i c1 -o c4
ret=$(diff -u c3 c4)

if [ "$ret" != "" ]
then
    echo "Image"
    echo $ret
    exit
fi


rm c1 c2 c3 c4

echo All done
