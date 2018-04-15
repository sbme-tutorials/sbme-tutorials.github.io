---
layout: page
course: "sbe201"
category: "notes"
year: "2018"
title:  "Week 7 - Part1"
by: "Asem"
---

https://www.youtube.com/watch?v=kPRA0W1kECg

### How to download from coursera

#### 1. Coursera Account

#### 2. Install Python

#### 3. Install pip

## Markdown vs. WYGIWYS Editors

### Jekyll

### Remarkjs

### Resumes

### Latex

## Template Structs

Templates.


### Exercism

#### Login with your github account

#### Install the command line tool

[Follow the instructions here](http://exercism.io/clients/cli/linux)

1. Download the command line tool: [(64-bit)](https://github.com/exercism/cli/releases/download/v2.4.1/exercism-linux-64bit.tgz)[(32-bit)](https://github.com/exercism/cli/releases/download/v2.4.1/exercism-linux-32bit.tgz).
2. Extract the downloaded binary file `tar -xzvf exercism-linux-64bit.tgz`
3. Make new folder at your home `~/bin` and move the executable to that folder, using the following commands:

  * `mkdir ~/bin`
  * `mv exercism ~/bin/`
  * `echo 'export PATH=$HOME/bin:$PATH' >> ~/.bashrc`

#### Connect the command line tool to your profile at exercism.io

Go to [this page](http://exercism.io/account/key), and execute the provided command in your terminal.
For example:

```bash
exercism configure --key=SOME_WORDY_KEY
```

#### Start fetching C++ Exercises

By issuing the command `exercism fetch cpp`, you will have a new exercise downloaded at `~/exercism/cpp`.

```bash
$ exercism fetch cpp

Not Submitted:    1 problem
cpp (Hello World) /home/asem/exercism/cpp/hello-world

New:              1 problem
cpp (Hello World) /home/asem/exercism/cpp/hello-world

unchanged: 0, updated: 0, new: 1

```

Go to the exercise folder

```bash
cd ~/exercism/cpp/hello-world
```
