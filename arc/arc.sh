#!/bin/bash
mkdir arc$1
cd arc$1
for i in {a..f}
do
        touch $i.cpp
done
touch sample.txt

