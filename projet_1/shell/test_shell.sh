#!/bin/bash
NTHREADS=16
NSAMPLE=5
#make philosopher_problem
rm -f data/test_set.CSV
echo "n_thread","time" >> data/test_set.CSV
echo "running test set"
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/test_set $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/test_set.CSV
  done
done

rm -f data/test_test_set.CSV
echo "n_thread","time" >> data/test_test_set.CSV
echo "running test test set"
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/test_test_set_performance $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/test_test_set.CSV
  done
done

rm -f data/posix.CSV
echo "n_thread","time" >> data/posix.CSV
echo "running test test set"
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/posix $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/posix.CSV
  done
done