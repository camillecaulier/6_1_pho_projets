#!/bin/bash
NTHREADS=16
NSAMPLE=5
#make producer_consumer
rm -f data/producer_consumer.CSV
echo "n_thread","time" >> data/producer_consumer.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/producer_consumer $i $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/producer_consumer.CSV
  done
done


echo "n_thread","time" >> data/producer_consumer_2.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/producer_consumer 4 $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/producer_consumer_2.CSV
  done
done

echo "n_thread","time" >> data/producer_consumer_3.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/producer_consumer 12 $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/producer_consumer_3.CSV
  done
done


echo "n_thread","time" >> data/producer_consumer_4.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/producer_consumer $i 4 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/producer_consumer_4.CSV
  done
done


echo "n_thread","time" >> data/producer_consumer_5.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/producer_consumer $i 12 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/producer_consumer_5.CSV
  done
done
rm -f producer_consumer