#!/bin/bash
#Implement a UNIX shell program (ld) that will list
#only directories in the directories on the command line.
#A command with no arguments assumes the current directory
for i in $( ls ); do
	echo item: $i
done
