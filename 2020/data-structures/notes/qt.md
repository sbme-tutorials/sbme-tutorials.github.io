---
layout: page
course: "sbe201"
category: "notes"
year: "2020"
title:  "QtCreator for SBE201"
by: "Asem"
---

* TOC
{:toc}


This semester we will rely on the QtCreator as an Integrated Development Environment (IDE).

QtCreator ships with the powerful and rich Qt project that features a large (or maybe the largest) spectrum of C++ libraries.

It is interesting to learn that many famous applications and organizations largely depend on Qt project. See the following lists from Wikipedia to learn about the most famous users of Qt: [3 Qt in use](https://en.wikipedia.org/wiki/Qt_(software)#Qt_in_use)


## Installing QtCreator

### Install Qt prerequisites

In Ubuntu, open your terminal (`Ctrl`+`Alt`+`T`) and copy paste the following command (to paste in the terminal: `Ctrl`+**`Shift`**+`V`), then hit `Enter`:

```bash
sudo apt install build-essential openssl libssl-dev libssl1.0 libgl1-mesa-dev wget
```

<div class="alert alert-primary" markdown="1" role="alert">

#### <i class="fas fa-info-circle"></i> Notes

* `sudo`: stands for _super user do_, and this is required when you make system-wide changes, like installing new libraries for the system. For detailed manual, write in the terminal `man sudo` then `Enter`. Press `Q` to close the manual and return to the terminal.
* `apt`: installation tool that links with large software repositories, so when you write `apt install x`, it will search for a package `x` within a stored database of the the available software in the linked repositories. You can install several packages at once like what we did in the command. Also, for detailed manual, write in the terminal `man apt` then `Enter`. Press `Q` to close the manual and return to the terminal.

</div>


### Download the offline installer

In this page: [Offline Qt Downloads](https://www.qt.io/offline-installers), you will find different download link for each system.

We will download from the following link [Qt 5.14.1 for Linux 64-bit (1.2 GB)](http://download.qt.io/official_releases/qt/5.14/5.14.1/qt-opensource-linux-x64-5.14.1.run) (Right click and _Save link as_). Alternatively, you can download files from the terminal using `wget` application. So, copy the download link and give it to the `wget`:

```bash
wget -c http://download.qt.io/official_releases/qt/5.14/5.14.1/qt-opensource-linux-x64-5.14.1.run
```

<div class="alert alert-primary" markdown="1" role="alert">

#### <i class="fas fa-info-circle"></i> Notes

* This will download `qt-opensource-linux-x64-5.14.1.run` into the terminal working directory. When you first open the terminal, its working directory is your home directory `~`.
* The flag `-c` means we ask `wget` to support continuing download in case the internet connection has broken, so it doesn't download the whole file again. More details can be found in the manual `man wget`.

</div>

### Installation

After downloading `qt-opensource-linux-x64-5.14.1.run`, from the terminal issue the following commands:

```bash
chmod a+x qt-opensource-linux-x64-5.14.1.run
sudo ./qt-opensource-linux-x64-5.14.1.run
```

This will pop up the installation wizard:


<div class="text-center" markdown="1">

Press **Next**:
<br>
<img src="../media/qt1.png" style="width:60%">
<br>

Create an account for the first time, then press **Next**:
<br>
<img src="../media/qt2.png" style="width:60%">
<br>

Tick for your consent to the obligations shown
<br>
<img src="../media/qt3.png" style="width:60%">
<br>

**Next**
<br>
<img src="../media/qt4.png" style="width:60%">
<br>

Specify the location of the installation, then **Next**:
<br>
<img src="../media/qt5.png" style="width:60%">
<br>

Just select the two items highlighted, then **Next**:
<br>
<img src="../media/qt6.png" style="width:60%">
<br>

**Agree** for the listed licenses, then **Next**:
<br>
<img src="../media/qt7.png" style="width:60%">
<br>


Finally proceed with **Install**, and **Finish**.
</div>


### Run your QtCreator

For the first time, open the Ubuntu dash <img src="../media/dash.svg" style="height:1em;width:1em;"> (at the left bottom corner), then look for _Qt_.
Alternatively, run directly from the terminal using:

```bash
/opt/Qt5.14.1/Tools/QtCreator/bin/qtcreator.sh
```

Finally, to add the QtCreator to the menu on the left as a shortcut, right click on the icon, then press _Add to the favourites_.

<div class="text-center" markdown="1">
<br>
<img src="../media/qt8.png" style="width:60%">
<br>
</div>

## Running your first project

<div class="text-center" markdown="1">

Open QtCreator, and from the menu bar press **File**->**New File or Project..**
<br>
<img src="../media/qt9.png" style="width:60%">
<br>


From the dialog menu, select **Application**->**Qt Console Application**->**Choose**
<br>
<img src="../media/qt10.png" style="width:60%">
<br>

Select the location and the name of the project
<br>
<img src="../media/qt10.png" style="width:60%">
<br>

</div>

<div class="alert alert-warning" markdown="1" role="alert">

#### <i class="fas fa-exclamation-triangle"></i> Note

* In general, avoid using spaces in a file or a folder name. Instead, use `-` or `_` to separate words. Alternatively, you may use _PascalCase_ naming convention.

</div>

<div class="text-center" markdown="1">

Use **CMake** as a build system:
<br>
<img src="../media/qt11.png" style="width:60%">
<br>

Now leave this as it is:
<br>
<img src="../media/qt12.png" style="width:60%">
<br>

Leave as it is:
<br>
<img src="../media/qt13.png" style="width:60%">
<br>

Now all is good, click **Finish**:
<br>
<img src="../media/qt14.png" style="width:60%">
<br>

</div>

Finally, you will find the file `main.cpp` opened with the following content there:

```c++
#include <QCoreApplication>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  return a.exec();
}
```


Instead let's use the following code:


```c++
#include <iostream>

int main()
{
  std::cout << "Hello SBE 201!\n";
  return 0;
}
```

Then press on the **Build** icon to compile your code:
<div class="text-center" markdown="1">
<br>
<img src="../media/qt15.png" style="width:60%">
<br>
</div>

