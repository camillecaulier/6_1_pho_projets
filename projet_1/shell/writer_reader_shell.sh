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
    OUTPUT=$((/usr/bin/time -f %e ./executable/writer_reader $i $i 2>&1) | cut -d\) -f2)
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
    OUTPUT=$((/usr/bin/time -f %e ./executable/writer_reader 4 $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader_2.CSV
  done
done

rm -f data/writer_reader_3.CSV
echo "n_thread","time" >> data/writer_reader_3.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/writer_reader 12 $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader_3.CSV
  done
done

rm -f data/writer_reader_4.CSV
echo "n_thread","time" >> data/writer_reader_4.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/writer_reader $i 4 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader_4.CSV
  done
done
rm -f data/writer_reader_5.CSV
echo "n_thread","time" >> data/writer_reader_5.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/writer_reader $i 12 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader_5.CSV
  done
done

rm -f data/writer_reader_mod.CSV
echo "n_thread","time" >> data/writer_reader_mod.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/writer_reader_mod $i $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader_mod.CSV
  done
done


rm -f data/writer_reader_mod_2.CSV
echo "n_thread","time" >> data/writer_reader_mod_2.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/writer_reader_mod 4 $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader_mod_2.CSV
  done
done

rm -f data/writer_reader_mod_3.CSV
echo "n_thread","time" >> data/writer_reader_mod_3.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/writer_reader_mod 12 $i 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader_mod_3.CSV
  done
done

rm -f data/writer_reader_mod_4.CSV
echo "n_thread","time" >> data/writer_reader_mod_4.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/writer_reader_mod $i 4 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader_mod_4.CSV
  done
done
rm -f data/writer_reader_mod_5.CSV
echo "n_thread","time" >> data/writer_reader_mod_5.CSV
for((i=1;i<=NTHREADS;i++))
do
  echo $i "threads"
  for((j=1;j<=NSAMPLE;j++))
  do
    OUTPUT=$((/usr/bin/time -f %e ./executable/writer_reader_mod $i 12 2>&1) | cut -d\) -f2)
    echo $i, $OUTPUT >> data/writer_reader_mod_5.CSV
  done
done
