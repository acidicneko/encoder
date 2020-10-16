#installer script for marko
echo run this script as root if not \in root curretly
echo compiling...
g++ -o marko main.cpp
echo installing...
mv marko /bin/marko
echo marko is ready to be used!
