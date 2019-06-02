
#!/bin/bash

echo " -------------------- MD5 --------------------"
a="a"
echo " ------ a"
counter=1
while [ $counter -le 10 ]
do
  echo "$a" | openssl md5 > c1
  echo "$a" | ../ft_ssl md5 > c2
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

a="a"
b="a"
echo " ------ a2"
counter=1
while [ $counter -le 10 ]
do
  echo "$a" | openssl md5 > c1
  echo "$a" | ../ft_ssl md5 > c2
  ret=$(diff -u c1 c2)

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
  echo "$a" | openssl md5 > c1
  echo "$a" | ../ft_ssl md5 > c2
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
  echo "$a" | openssl md5 > c1
  echo "$a" | ../ft_ssl md5 > c2
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

echo " ------ PDF"
openssl md5 ./document.pdf > c1
../ft_ssl md5 ./document.pdf > c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
    echo "Pdf"
    echo $ret
    exit
fi

echo " ------ IMAGE"
openssl md5 ./image.png > c1
../ft_ssl md5 ./image.png > c2
ret=$(diff -u c1 c2)

if [ "$ret" != "" ]
then
    echo "Image"
    echo $ret
    exit
fi

rm c1 c2
echo All done
