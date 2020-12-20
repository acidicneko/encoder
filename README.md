[![Made in Emacs](https://img.shields.io/badge/Made%20in-emacs-blue.svg)](https://www.gnu.org/software/emacs/)
![Generic badge](https://img.shields.io/badge/Version-1.0.2%20beta-lime.svg)
![Generic badge](https://img.shields.io/badge/Maintained-yes-yellow.svg)


# Encoder
A dumb secret keeper for you! Ho! Ho! Ho!

# Encoder in action
![Settings Window](https://raw.githubusercontent.com/ayush7788/encoder/main/2020-12-19_04_59.png)

Ever forgot your marks in tests you got? Ever realised to note some data given in _key_ - _value_ format? If yes ENCODER is here for help!
And yeah it is dumb as it sounds!

# Usage
The commandline utility to use ENCODER is `enc`

Encoder works something similar to how git works.
First you have to initialise an empty directory with command -
```
enc init
```
When the directory is initialised a ".enc.dat" file is generated in given directory, containing current directory name and some other information.
Then you have to commit a file(eg. contacts) as -
```
enc commit contacts
```
It will generate a file called "contacts" in the directory.
Then to start registering your marks in this file do -
```
enc set contacts
```
It will set default storage file to "contacts"
Then to register data -
```
enc push Abhishek +911009xxx89
```
It will register key "Abhishek" with value "+911009xxx89".

If you ever needed some help -
```
enc help
```
# Installation
Clone this repo - 
```
git clone https://github.com/ayush7788/enc.git
```
Then run the install.sh file as super user.
Usually -
```
sudo sh install.sh
```
And that's it marko is ready to be used!

# To-do list
- [x] Publish source code to GitHub
- [x] Do first beta release
- [x] ~~Make subject deleting system to delete data from record~~
- [x] ~~Make variables deleting system within a file~~
- [x] ~~Do first stable release~~
- [x] Remake Marko with better code and speed
- [x] Introduce new system for data storage
- [x] Publish source code to GitHub
- [ ] Do second beta release
- [ ] Play Minecraft

