# CS220 - Computer System II Lab 0

**Deadline**:  08/25/2016 by the end of lab

## Introduction
In this lab, you will learn to:

- Develop, compile, and execute a simple C program in command-line environment 
- Use `make` to control builds
- Use `tar` to create archives
- Use `git` to manage your projects and submit your work for grading.

Look for these icons!

| | Meaning |
|:----:|---------|
| :bulb: | Tips and useful information |
| :warning: | Caution! This could cause you problems. |
| :no_entry: | Danger! Don't do this! |

## Getting Started
All students should have card access to room G7 and login information (username and password) to lab machines. If not, please contact TA or Professor for assistance. 
You can use any machines in G7 to complete your lab work, programming assignment, and projects for this class. However, please be mindful of the lab schedule posted outside and avoid using the room when other classes are in session.
If you decide to work from home, you can either try `ssh` from your terminal (if you have Mac or Linux system) or a GUI SSH client. To log into to this lab machine from a terminal, simply type this command:

```shell
ssh username@remote.cs.binghamton.edu
```

... where `username` is your CS LDAP account.

## Writing Hello World

After loging in, open a terminal. 

First, let's set up our `git` credentials. Enter the following two commands in the terminal:

```shell
git config --global user.name "Firstname Lastname"
git config --global user.email "email@binghamton.edu"
```

You should be at your home directory. In this directory, create a new directory for this class:

```shell
mkdir cs220
```

Change your working directory:

```shell
cd cs220
```

Then, clone this repository to get a copy of the source code onto your account. To do this, look at the Github landing page for your fork of this project. You should see a green button that says "Clone or download". Press it and choose "Clone with HTTPS" if you haven't already. You should see something like `https://github.com/bucs220/F17L0.git`. Copy that text then execute the following command in the terminal:
 
```shell
git clone URL
```
... where URL is the copied text ending in ".git".

We will explore git workflows in-depth later in this lab.

## Text Editors

Remote has a variety of text editors available. If you prefer a graphical text editor, you can use `gedit`. If you are more comfortable with command line editors, you can choose `vi`, `emacs`, or `nano`.

:bulb: Useful resources:
- vi: http://heather.cs.ucdavis.edu/~matloff/UnixAndC/Editors/ViIntro.html 
- emacs: https://emacswiki.org
- nano: https://www.nano-editor.org/dist/v2.6/nano.html

Open your favorite text editor and write a simple Hello World program in C. Name your source code file ”hw.c”

```C
#include <stdio .h>

int main() {
  printf (”Hello World!\n”) ; 
  return 0;
}
```

Compile your Hello World program: 

```shell
gcc hw.c −o hw
```

This command invokes a C compiler, `gcc`, and produces an executable file called `hw`. Execute your `hw` program:

```shell
./hw
```

## Make
Make is a build tool that automatically generates executable from multiple source code files. When you invoke make, it will search for a file named `Makefile` in current directory. This Makefile contains rules to build a program.
A basic rule in Makefile has the following form: 

```Make
target: dependencies
	command
```

:warning: Note that `command` is indented using a tab character, not spaces! 

:bulb: Also note that a target can have multiple dependencies (all on one line) and multiple commands (on separate lines, as does the `clean` target below).  

Create a Makefile for your Hello World program. Here is a simple example:

```Make
all: hw 

hw: hw.c
	gcc hw.c −o hw

clean:
	rm −f hw
	rm *~ #*#
```

Make has the following form on the command line:

```shell
make [target]
```

If you do not provide a `target`, make will use the first target listed in the file, which in this case is `all`. Make will compile the program using the command we specify in Makefile. In this case, to compile Hello World program, type:

```shell
make hw
```

You can also provide multiple targets for make. For example:

```make
make clean hw
```

This make command will delete your existing `hw` binary and compile a new one. 

:bulb: To learn more about make and Makefile, here are some useful resources:

- http://www.gnu.org/software/make/manual/make.html
- http://opensourceforu.com/2012/06/gnu-make-in-detail-for-beginners/

## Archives

Sometimes you will find that it is useful to combine a group of files together in an _archive_. One such program is `tar`, which produces an archive nicknamed a _tarball_.

`tar` commands take the following form:

```shell
tar <options> [pathname...]
```

... where the first pathname is the archive itself. Examples:

| command | action |
|---------|--------|
| `tar -cvzf lab0.tar.gz hw.c Makefile` | Create an archive containing `hw.c` and `Makefile` |
| `tar -tvf lab0.tar.gz` | Display the contents of the archive |
| `tar -xvzf lab0.tar.gz .` | Extract the contents of the archive into the current directory |


## Git

:warning: These commands all presume that your current working directory is within the directory tracked by `git`.

In this lab, we will use Github Classroom repositories. You have already [forked](https://help.github.com/articles/fork-a-repo/) this repository when you accepted the emailed link. That makes a copy of the repository, free for you to make changes. Then you cloned your forked repository to get a working copy onto this machine. 

Now that we have made local changes to our working copy, let's [commit](https://git-scm.com/docs/git-commit) those changes to the repository:

```shell
git commit -a -m "My first commit!"
```

The `-a` says that git should add all tracked files with changes to your commit, and the `-m` says the next string contains the commit message.

What about _untracked files_? Run the following commands:

```shell
echo $(whoami)@$(hostname):$(pwd) > information.txt
git status
```

You'll notice that `git` tells us that `information.txt` is an _untracked file_. That means it's not being tracked by the repository. Let's fix that by [adding](https://git-scm.com/docs/git-add) it.

```shell
git add information.txt
git commit -m "Added an informational file"
```

Once we've made the commits for a given coding session, we need to add those to the repository by performing a [push](https://git-scm.com/docs/git-push):

```shell
git push
```

Now, let's say we don't want `information.txt` in the repository anymore. How can we remove it?

```shell
git rm information.txt
git commit -m "Removed an informational file"
git push
```

Lastly, the next time we begin a coding session, we will need to [pull](https://git-scm.com/docs/git-pull) to get an updated working copy.

```shell
git pull
```

That's it! We've completed our work for this lab. Now to submit it.

:bulb: Useful `git` references:
- https://guides.github.com/introduction/flow/
- https://help.github.com
- https://git-scm.com/doc
                              
## Submission

:no_entry: Please read submission instructions carefully. Any deviations from specifications on future labs, assignments or projects will result in point deductions or incomplete grades. 

1. Create a release of your repository:
	1. Click "releases", next to the tag icon.
	2. Click the "Create a new release" button.
	3. Fill in the tag version (i.e. 1.0), the release title (i.e. "First submission!") and add any comments that the grader needs to know about your submission.
	4. Click the "Publish release" button.
	5. On the next page, you will see that your release has a 7-digit hexadecimal number. This is the hash of the release, uniquely identifying the state of the repository that was used to make the release. Copy that.
2. Log onto MyCourses.
	1. Find this assignment.
	2. Make a submission as you normally would for any other class. The difference is that instead of uploading an archive file or source code, all you should do is paste the 7-digit hash into the comments.
	
The MyCourses submission notifies the graders that your repository is ready to be graded. Your grade for the lab, assignment or project will be recorded on MyCourses. **For labs, the TAs can grade your submission on the spot. Simply raise your hand to get our attention.**
