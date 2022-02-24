#!/bin/bash

make
fuschia='\e[0;35m'
normal='\e[0;m'

function echo_color
{
    echo -ne $fuschia "$*" $normal
}

function tests()
{ 
    echo -e "$1\n$2\n$3\n$4" | ./mysh > temp.txt 2>&1
    echo -e "$1\n$2\n$3\n$4" | tcsh > temp2.txt 2>&1
    diff -I 'SHLVL=' -I '_=' -I 'temp.txt' -I 'temp2.txt' temp.txt temp2.txt -s
}

#basic command
echo_color "ls = ";tests "ls"
echo_color "ls -l = ";tests "cd" "ls -l"
echo_color "/bin/ls = ";tests "/bin/ls"
echo_color "no existant command = ";tests "dzaefgr"
echo_color "no permissions = ";tests "./main.c"
echo_color "segmentation fault = ";tests "./segfault"

#display env
echo_color "env = ";tests "env"

#modif env
echo_color "unsetenv existing variable = ";tests "unsetenv MAIL" "env"
echo_color "unsetenv inexisting variable = ";tests "unsetenv hello" "env"
echo_color "unsetenv no args = ";tests "unsetenv"
echo_color "unsetenv PATH and ls = ";tests "unsetenv PATH" "ls"
echo_color "setenv add = ";tests "setenv hello world" "env"
echo_color "display env with setenv = ";tests "setenv"
echo_color "delete after '=' with setenv = ";tests "setenv MAIL" "env"
echo_color "setenv classic = ";tests "setenv PWD hello" "env"
echo_color "setenv error = ";tests "setenv 4de hello"
echo_color "secund setenv error = ";tests "setenv dze-+de hello"
echo_color "setenv PATH empty & ls = ";tests "setenv PATH" "ls"

#move in env
echo_color "cd at home = ";tests "cd" "env"
echo_color "cd one folder before = ";tests "cd .." "env"
echo_color "cd in lib = ";tests "cd lib" "env"
echo_color "do cd - = ";tests "cd lib" "env" "cd -" "env"
