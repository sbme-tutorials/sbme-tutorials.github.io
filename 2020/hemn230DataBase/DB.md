---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: home
category: "coursepage"
course: "hemn230"
year: "2020"
---
# Computer systems(Database) \(SBE306\) - Fall 2020

## Teaching Staff

Instructor: Dr. Ahmed Kandil.

Demonstrators:  Eng. Ayman Anwar.  


## Section Hours

| Section | Day | Time Slot |
|---------|-----|-----------|
|   1     | Thursday | from **11 AM** to **1 PM**  |
|   2     | Thursday | from **4 PM** to **4 PM**  |

## Office Hours

| Day | Time |
|-----|-----------|
| Thursday | from **9 AM** to **11 AM** |
| Thursday | from **2 PM** to **4 PM** |

extra office hours requested via E-Mail to **ayman.m.anwar@eng.cu.edu.eg** (Subject : EXOFH)

## Course Outline

| Week | Content |  Tasks
|------|-----------------|-----|
|   1  | Introduction to full stack development and database management systems | ---- |
|   2  | ER model and basic SQL statements | ---- |
|   3  | SQL Relations and JOINs | ---- |
|   4  | Introduction to python and mysql-connector | ---- |
|   5  | Python Flask Web-MicroFramework | ---- |
|   6  | Flask Templates and style sheets | ---- |

## Required installations

visit [AMPPS](https://www.ampps.com/downloads) and download the latest version according to your distributions.

1. windows 
* for installation please follow regular installation steps (next >> next >> finish)
* please make sure you have internet connection during installation
2. Linux
* please make sure you have internet connection during installation.
type the following command after routing to download directory.
```
cd /download/location
chmod 0755 Ampps-<version>-<arch>.run
sudo ./Ampps-<version>-<arch>.run
```
To run ampps
```
sudo /usr/local/ampps/Ampps
```
## On startup
You should see something like this indicating the server has started properly.
![](images/amppsStart.png)

## common issues for LINUUX installation

if you have a problem installing ampps on linux type the following:

```
cd /usr/local/ampps/apache/lib
sudo mkdir backup
sudo mv ./libapr* ./backup/
sudo apt-get -y install libaprutil1 libaprutil1-dev libapr1 libapr1-dev 
```
then restart your device and run the following every time you want to start it.

```
cd ~
sudo QT_X11_NO_MITSHM=1 /usr/local/ampps/Ampps 
```


## Tutorials

### HEMN230

* Week 1
    * [Slides]({{ site.baseurl }}{% link 2019/Database/presentations/1_week1/index.md %}){:target="_blank"}
    * [Notes]({{ site.baseurl }}{% link 2019/Database/notes/HEMweek1.md %}){:target="_blank"}
* Week 2
    * [Notes]({{ site.baseurl }}{% link 2019/Database/notes/HEMweek2.md %}){:target="_blank"}
* Week 3
    * [Lab-notes]({{ site.baseurl }}{% link 2019/Database/notes/HEMweek3LabNotes.md %}){:target="_blank"}
* Week 4
    * [notes]({{ site.baseurl }}{% link 2019/Database/notes/HEMweek4.md %}){:target="_blank"}
    * [Introduction to python]({{ site.baseurl }}{% link 2019/Database/notes/pythonIntroduction.md %}){:target="_blank"}
    * [python Mysql]({{ site.baseurl }}{% link 2019/Database/notes/pythonMysql.md %}){:target="_blank"}
* Week 5
    * [Lab-notes]({{ site.baseurl }}{% link 2019/Database/notes/HEMweek5LabNotes.md %}){:target="_blank"}
* Week 6
    * [SQL-Revision]({{ site.baseurl }}{% link 2019/Database/notes/HEMweek6.md %}){:target="_blank"}
    * [Flask-Application]({{ site.baseurl }}{% link 2019/Database/notes/SBEweek5.md %}){:target="_blank"}
* Week 7
    * [Flask-Templates-Bootstrap]({{ site.baseurl }}{% link 2019/Database/notes/SBEweek6.md %}){:target="_blank"}
    * [Flask-dynamics]({{ site.baseurl }}{% link 2019/Database/notes/SBEweek7.md %}){:target="_blank"}

