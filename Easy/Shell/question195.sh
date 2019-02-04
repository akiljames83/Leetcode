# Read from the file file.txt and output the tenth line to stdout.
#!/bin/bash
COUNT=0;
while read line; do
COUNT=$((COUNT+1))
if [[ "${COUNT}" = 10 ]]
then
  echo $line
fi
#echo $line
done < file.txt