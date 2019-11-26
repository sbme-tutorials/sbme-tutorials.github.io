---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: page
category: "notes"
course: "sbe306a"
year: "2019"
---
* TOC
{:toc}

# Tutorial 7

This week we will learn 
* using static files

## Static Files

static files such as **.css/.js/.png/.jpeg/...etc** could be used inside Flask Template once placed in static files folder.

Example of a project_directory with static files:

* templates
    * file1.html
    * file2.htm
* static
    * file1.css
    * im1.png
    * im2.png
* server.py 

```html
<img src="/static/im1.png">
```
## Demo
All demos will be available in [this](https://github.com/sbme-tutorials/SBE306_2019Demos) repository