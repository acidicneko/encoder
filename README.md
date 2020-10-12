# marko
A dumb marks organiser for your academics!

Ever forgot your marks in tests you got? If yes then "Marks Organiser" is here to help!
And yeah it is dumb as it sounds!😁
# Usage
Marko works something similar to how git works.
First you have to initialise an empty directory with command -
```
marko init
```
When the directory is initialised a ".marko_init" file is generated in given directory, containing current directory name and some other information.
Then you have to commit a file(usually name of your exam) as -

> marko commit Finals

It will generate a file called "Finals" in the directory.
Then to start registering your marks in this file do -

> marko set Finals

It will set default storage file to "Finals"

Then to register marks -

> marko push Maths 80

It will register your marks in "Maths" as "80".
Wow how dumb!! Gimme an award for this!!
# Installation
Clone this repo - 

> git clone https://github.com/ayush7788/marko.git
Then run the install.sh file as super user.
Usually -

> sudo sh install.sh
And that's it marko is ready to be used!

# To-do list
- [ ] Publish source code to GitHub
- [ ] Do first release
- [ ] Play Minecraft

