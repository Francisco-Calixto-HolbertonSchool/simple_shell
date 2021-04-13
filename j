#!/bin/bash
#
# run /bin/ls many times, with a lot of spaces everywhere

command="pwd"

OLDPATH="$PATH"
PATH=""
#$ECHO "env" 

echo "$command" | ./hsh

# put PATH back
PATH="$OLDPATH"

# wait a little bi

# check the result
