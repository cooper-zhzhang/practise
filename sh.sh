#! /bin/bash
i=0
while [ 100 -ge $i ]
do
let "i += 1"	
time ./solu_sudou_2 < input_1.txt
done
