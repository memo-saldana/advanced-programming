#!/bin/bash

grep -o "hashtag\/[A-Za-z0-9_]\+" $1 | sort -n | uniq -ic > $"onlyHashtags.txt"

cat $"onlyHashtags.txt" | sed "s/hashtag//" |  sed "s/\///g" > $"hashtagsList.txt"

cat hashtagsList.txt