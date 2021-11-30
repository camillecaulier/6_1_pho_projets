#!/bin/bash
NTHREADS=16
NSAMPLE=5

rm -f data/writer_reader.CSV
echo "n_thread","time" >> data/writer_reader.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./writer_reader $i $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader.CSV
  done
done


rm -f data/writer_reader_2.CSV
echo "n_thread","time" >> data/writer_reader_2.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./writer_reader $4 $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader_2.CSV
  done
done


echo "n_thread","time" >> data/producer_consumer_3.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./producer_consumer 12 $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/producer_consumer_3.CSV
  done
done


echo "n_thread","time" >> data/producer_consumer_4.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./producer_consumer $i $4 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/producer_consumer_4.CSV
  done
done


echo "n_thread","time" >> data/producer_consumer_5.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./producer_consumer $i $12 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/producer_consumer_5.CSV
  done
done
rm -f writer_reader