#!/bin/bash

NTHREADS=16
NSAMPLE=5

make philosopher_problem
rm -f philosopher_problem.CSV

echo "n_thread","time" >> philosopher_problem.CSV


for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./philosopher_problem $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> philosopher_problem.CSV
  done
done
rm -f philosopher_problem