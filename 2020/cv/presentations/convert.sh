#!/bin/bash

decktape --chrome-arg=--allow-file-access-from-files \
-s 1024x768 http://127.0.0.1:4000/2020/cv/presentations/week03.html week03.pdf

decktape --chrome-arg=--allow-file-access-from-files \
-s 1024x768 http://127.0.0.1:4000/2020/cv/presentations/week04.html week04.pdf
