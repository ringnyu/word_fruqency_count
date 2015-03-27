#!/bin/bash

echo "This is to compile the code count.c"

gcc -c main.c

gcc -o test  main.o libcnt.a

spd-say -p 39 "Building complete"

./test

echo "Execution done"

spd-say -p -48 "File opening"

#gnome-open word_frequency

sleep 2

spd-say -p 0 "removing temporal files"

rm -r word_frequency_program.o test 

cat word_frequency

