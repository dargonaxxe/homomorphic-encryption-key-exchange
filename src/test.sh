#!/bin/bash
for i in `seq 1 100`;
do 
	./homomorphic_enc >> test_log.csv
done
