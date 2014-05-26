# @Heintze, Darrell R.  6544  GSU
#!/bin/bash
#shell program that will list only directories in the directories
#on the command line.
#A command with no arguments assumes the current directory

if [ "$#" -lt "2" ]; then
ls -d -- ./*/
fi

while [ "$#" -gt "0" ]
do
  ls -d -- $1/*/
  shift
done
