#!/bin/bash
for filename in `find ./src | egrep '\.cc'`; 
do 
  gcov -n -o . ./src/$filename > /dev/null; 
done