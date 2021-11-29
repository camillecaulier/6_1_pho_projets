#!/bin/bash
NTHREADS=16
NSAMPLE=5
make producer_consumer
rm -f producer_consumer.CSV
echo "n_thread","time" >> producer_consumer.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./producer_consumer $i $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> producer_consumer.CSV
  done
done
rm -f producer_consumer