#!/bin/bash
read -p "Enter a number: " n
is_prime=1
for ((i=2; i*i<=n; i++))
do
  if (( n % i == 0 )); then
    is_prime=0
    break
  fi
done

if (( is_prime && n > 1 )); then
  echo "$n is a Prime Number"
else
  echo "$n is Not a Prime Number"
fi
