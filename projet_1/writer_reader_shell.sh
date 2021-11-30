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
    OUTPUT=$((/usr/bin/time -f %e ./writer_reader $i $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader.CSV
  done
done
rm -f writer_reader