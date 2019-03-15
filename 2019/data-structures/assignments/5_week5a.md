---
layout: page
course: "sbe201"
category: "assignment"
year: "2019"
title:  "Assignment 4 (Groups): Git for Teams and Markdown Resumes"
by: "Asem"
pdf: true
---

## Prerequisites

1. Familiarity with Git basic line commands. Refer to the preprinted git cheat sheet that we have received previously ([PDF version](https://education.github.com/git-cheat-sheet-education.pdf)).
2. Familiarity with Markdown formatting. Refer to the preprinted Markdown fold that we have received previously ([PDF version](https://enterprise.github.com/downloads/en/markdown-cheatsheet.pdf)).

## Warnings

1. <p class="text-danger" markdown="1">Never use the GitHub website to upload your work. This will almost ruin the work of your teammates. You should only rely on the git commands.</p>
1. When you publish your changes, it may happen that one of your teammates has published some updates before you do, so you need to `git pull origin master` first. So never use as a solution: `git push -f origin master` (by adding `-f`) or `git push --force origin master` (by adding `--force` flag). This is guaranteed to ruin and overwrite your teammates work.

#### `git push origin master --force` in practice:

<div class="fb-video" data-href="https://www.facebook.com/nixcraft/videos/1258756887471020/" data-width="500" data-show-text="true"><blockquote cite="https://developers.facebook.com/nixcraft/videos/1258756887471020/" class="fb-xfbml-parse-ignore"><a href="https://developers.facebook.com/nixcraft/videos/1258756887471020/">$ git push --force origin master</a><p>$ git push --force origin master</p>Posted by <a href="https://www.facebook.com/nixcraft/">NixCraft</a> on Tuesday, 15 March 2016</blockquote></div>



[Another practical `git push origin master --force`](https://66.media.tumblr.com/864179eb909776f6208ce1ab8a82c36d/tumblr_o0t4eiOvyQ1v060foo1_500.gif?fbclid=IwAR0X9RShZNjoJ7JC_fCCpHUQOsraMkFnuaZT4ZOwKApYuSP28wU6U2mc1Gk)

## Recommendations

You are expected to often execute git commands that access the remote repository:
    
 1. `git clone url`: which clones the remote repository for the first time.
 2. `git pull origin master`: which merges the updates on the remote repository (almost made by your teammates) into your local repository. 
 3. `git push origin master`: that publishes your local updates to the remote repository.
 
Each of these commands requires providing your username and password. It becomes a cumbersome when you frequently make minor incremental changes. Follow [these simple steps]({{ site.baseurl }}{% link 2019/data-structures/notes/public_key.md %}){:target="_blank"} that guides you towards using public key authentication instead of the username and password.

## Objectives

* Collaborate as a group in a single repository.
* Use the simple Markdown to annotate your document structure.

## Deadline

**Tuesday of 19 March 2019, 11:59 PM (PST time)**

### Assignment in Groups: Resume

#### Creating a Team or Joining an existing team

* Know your team id from [this sheet](https://docs.google.com/spreadsheets/d/1W2bvlF3XUEBwjQ2ArbhgaEqx3ZhwbjIb1bT_OJaZ7cU/edit?usp=sharing).
* Join the assignment page [from here](https://classroom.github.com/g/MhjXa_SX). **skip** this first dialogue.
    * If you are the team leader, create a new team using the label **SBE201-2021 Teamxx** (e.g for team \#1, **SBE201-2021 Team01**).
    * Otherwise, if you are not the team leader, find your team **label** as **SBE201-2021 Teamxx**, where `xx` is the group number in two digits, then join it. If you don't find it then ask your team leader to register your team as described above.
    

#### Start working in your resume

* After cloning your repository of your team, open the folder using *Visual Studio Code*, and work in your Markdown file. 
* The team should write their plain resumes in separate files. You should find **6 files**, choose the one associated with order your name appeared [this sheet](https://docs.google.com/spreadsheets/d/1W2bvlF3XUEBwjQ2ArbhgaEqx3ZhwbjIb1bT_OJaZ7cU/edit?usp=sharing).
* Start drafting a basic resume of yours, you may use [this file](/2019/data-structures/assignments/resumes/asem) as a template.
* You can find extra guidelines in the README.md file of your repository.
* After finishing, add your name in the table in the `README.md` file.
* [A reference for GitHub emojis](https://gist.github.com/rxaviers/7360908)