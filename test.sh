#!/bin/bash
ARG=$1;
DIED=0
for i in {1..10}
do
	./philo ${ARG} >> output
done

cat output | grep died | wc -l