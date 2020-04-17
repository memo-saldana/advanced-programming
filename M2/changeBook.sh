#!/bin/bash

cat "Sherlock.txt" | sed "s/Sherlock/Parfisal/g"	| \
                    sed "s/Godfrey/Dacrum/g" | \
                    sed "s/London/Mexicali/g" | \
                    sed "s/months/14\/10\/20/g" | \
                    sed "s/ago/4\:55/g" > newSherlock.txt