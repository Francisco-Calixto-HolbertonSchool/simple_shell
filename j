#!/bin/bash
#
# run /bin/ls many times, with a lot of spaces everywhere

command="ls"

OLDPATH="$PATH"
PATH=":$PATH"
#$ECHO "env" 

$ECHO "$command" | ./hsh

# put PATH back
PATH="$OLDPATH"

# wait a little bi

# check the result
