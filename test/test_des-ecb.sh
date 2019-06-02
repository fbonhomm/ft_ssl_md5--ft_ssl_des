#!/bin/bash

echo " -------------------- DES-ECB --------------------"
k="133457799bbCDFF1"
s="13a457799bbCDFF1"
echo " ------ a"
a="a"
counter=1
while [ $counter -le 10 ]
do
  # ---------------------- normal ----------------------
  # ---- encrypt ----
  echo "$a" | openssl enc -des-ecb -K $k > c1
  echo "$a" | ../ft_ssl des-ecb -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---- decrypt ----
  openssl enc -d -des-ecb -K $k < c2 > c3
  ../ft_ssl des-ecb -d -k $k < c1 > c4
  ret=$(diff -u c3 c4)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option a ----------------------
  echo "$a" | openssl enc -des-ecb -a -K $k > c1
  echo "$a" | ../ft_ssl des-ecb -a -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  openssl enc -des-ecb -a -d -K $k < c2 > c3
  ../ft_ssl des-ecb -a -d -k $k < c1 > c4
  ret=$(diff -u c3 c4)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option p ----------------------
  echo "$a" | openssl enc -des-ecb -pass "pass:test" -S $s  > c1
  echo "$a" | ../ft_ssl des-ecb -p "test" -s $s > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  openssl enc -des-ecb -d -pass "pass:test" < c2 > c3
  ../ft_ssl des-ecb -d -p "test" < c1 > c4
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
  echo "$a" | openssl enc -des-ecb -K $k > c1
  echo "$a" | ../ft_ssl des-ecb -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---- decrypt ----
  openssl enc -d -des-ecb -K $k < c2 > c3
  ../ft_ssl des-ecb -d -k $k < c1 > c4
  ret=$(diff -u c3 c4)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option a ----------------------
  echo "$a" | openssl enc -des-ecb -a -K $k > c1
  echo "$a" | ../ft_ssl des-ecb -a -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  openssl enc -des-ecb -a -d -K $k < c2 > c3
  ../ft_ssl des-ecb -a -d -k $k < c1 > c4
  ret=$(diff -u c3 c4)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option p ----------------------
  echo "$a" | openssl enc -des-ecb -pass "pass:test" -S $s  > c1
  echo "$a" | ../ft_ssl des-ecb -p "test" -s $s > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  openssl enc -des-ecb -d -pass "pass:test" < c2 > c3
  ../ft_ssl des-ecb -d -p "test" < c1 > c4
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
  echo "$a" | openssl enc -des-ecb -K $k > c1
  echo "$a" | ../ft_ssl des-ecb -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # decrypt
  openssl enc -d -des-ecb -K $k < c2 > c3
  ../ft_ssl des-ecb -d -k $k < c1 > c4
  ret=$(diff -u c3 c4)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option a ----------------------
  echo "$a" | openssl enc -des-ecb -a -K $k > c1
  echo "$a" | ../ft_ssl des-ecb -a -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  openssl enc -des-ecb -a -d -K $k < c2 > c3
  ../ft_ssl des-ecb -a -d -k $k < c1 > c4
  ret=$(diff -u c3 c4)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option p ----------------------
  echo "$a" | openssl enc -des-ecb -pass "pass:test" -S $s  > c1
  echo "$a" | ../ft_ssl des-ecb -p "test" -s $s > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  openssl enc -des-ecb -d -pass "pass:test" < c2 > c3
  ../ft_ssl des-ecb -d -p "test" < c1 > c4
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
  echo "$a" | openssl enc -des-ecb -K $k > c1
  echo "$a" | ../ft_ssl des-ecb -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # decrypt
  openssl enc -d -des-ecb -K $k < c2 > c3
  ../ft_ssl des-ecb -d -k $k < c1 > c4
  ret=$(diff -u c3 c4)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option a ----------------------
  echo "$a" | openssl enc -des-ecb -a -K $k > c1
  echo "$a" | ../ft_ssl des-ecb -a -k $k > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  openssl enc -des-ecb -a -d -K $k < c2 > c3
  ../ft_ssl des-ecb -a -d -k $k < c1 > c4
  ret=$(diff -u c3 c4)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  # ---------------------- option p ----------------------
  echo "$a" | openssl enc -des-ecb -pass "pass:test" -S $s  > c1
  echo "$a" | ../ft_ssl des-ecb -p "test" -s $s > c2
  ret=$(diff -u c1 c2)

  if [ "$ret" != "" ]
  then
    echo $a
    echo $ret
    exit
  fi

  openssl enc -des-ecb -d -pass "pass:test" < c2 > c3
  ../ft_ssl des-ecb -d -p "test" < c1 > c4
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
openssl enc -des-ecb -K $k -in ./document.pdf -out c1
../ft_ssl des-ecb -k $k -i ./document.pdf -o c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
    echo "pdf"
    echo $ret
    exit
fi

openssl enc -des-ecb -d -K $k -in c2 -out c3
../ft_ssl des-ecb -d -k $k -i c1 -o c4
ret=$(diff -u c3 c4)

if [ "$ret" != "" ]
then
    echo "pdf"
    echo $ret
    exit
fi

# ---------------------- option a ----------------------
openssl enc -des-ecb -a -K $k -in ./document.pdf -out c1
../ft_ssl des-ecb -a -k $k -i ./document.pdf -o c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
    echo "pdf"
    echo $ret
    exit
fi

openssl enc -des-ecb -a -d -K $k -in c2 -out c3
../ft_ssl des-ecb -a -d -k $k -i c1 -o c4
ret=$(diff -u c3 c4)

if [ "$ret" != "" ]
then
    echo "pdf"
    echo $ret
    exit
fi

# ---------------------- option p ----------------------
echo "$a" | openssl enc -des-ecb -pass "pass:test" -S $s -in ./document.pdf -out c1
echo "$a" | ../ft_ssl des-ecb -p "test" -s $s -i ./document.pdf -o c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
  echo $a
  echo $ret
  exit
fi

openssl enc -des-ecb -d -pass "pass:test" -in c2 -out c3
../ft_ssl des-ecb -d -p "test" -i c1 -o c4
ret=$(diff -u c3 c4)

if [ "$ret" != "" ]
then
  echo $a
  echo $ret
  exit
fi







# ----------- IMAGE ------------ #
echo " ------ IMAGE"
openssl enc -des-ecb -K $k -in ./image.png -out c1
../ft_ssl des-ecb -k $k -i ./image.png -o c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
    echo "image"
    echo $ret
    exit
fi

openssl enc -des-ecb -d -K $k -in c2 -out c3
../ft_ssl des-ecb -d -k $k -i c1 -o c4
ret=$(diff -u c3 c4)

if [ "$ret" != "" ]
then
    echo "image"
    echo $ret
    exit
fi

# ---------------------- option a ----------------------
openssl enc -des-ecb -a -K $k -in ./image.png -out c1
../ft_ssl des-ecb -a -k $k -i ./image.png -o c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
    echo "image"
    echo $ret
    exit
fi

openssl enc -des-ecb -a -d -K $k -in c2 -out c3
../ft_ssl des-ecb -a -d -k $k -i c1 -o c4
ret=$(diff -u c3 c4)

if [ "$ret" != "" ]
then
    echo "image"
    echo $ret
    exit
fi

# ---------------------- option p ----------------------
echo "$a" | openssl enc -des-ecb -pass "pass:test" -S $s -in ./image.png -out c1
echo "$a" | ../ft_ssl des-ecb -p "test" -s $s -i ./image.png -o c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
  echo $a
  echo $ret
  exit
fi

openssl enc -des-ecb -d -pass "pass:test" -in c2 -out c3
../ft_ssl des-ecb -d -p "test" -i c1 -o c4
ret=$(diff -u c3 c4)

if [ "$ret" != "" ]
then
  echo $a
  echo $ret
  exit
fi


rm c1 c2 c3 c4

echo All done
