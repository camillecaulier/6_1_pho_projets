#!/bin/bash
NTHREADS=16
NSAMPLE=5
make writer_reader
rm -f writer_reader.CSV
echo "n_thread","time" >> writer_reader.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./writer_reader $i $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> writer_reader.CSV
  done
done
rm -f writer_reader