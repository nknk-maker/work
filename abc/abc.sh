#!/bin/bash
mkdir abc$1
cd abc$1
for i in {a..g}
do
	touch $i.cpp
done
touch sample.txt

