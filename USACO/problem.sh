#! /bin/bash
mkdir $1
cd $1
touch $1.cpp
echo "/*
ID: cyrilsh1
TASK: $1
LANG: C++       
*/" >> $1.cpp
echo "#include <iostream>" >> $1.cpp
echo "#include <fstream>" >> $1.cpp
echo "#include <string>" >> $1.cpp
echo "#include <map>" >> $1.cpp
echo "#include <vector>" >> $1.cpp
echo "#include <queue>" >> $1.cpp
echo "#include <stack>" >> $1.cpp
echo "using namespace std;" >> $1.cpp
echo "\nint main() {" >> $1.cpp
echo "    return 0;" >> $1.cpp
echo "}" >> $1.cpp
touch $1.in
touch $1.out