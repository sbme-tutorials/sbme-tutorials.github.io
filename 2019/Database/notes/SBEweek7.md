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

This week we will learn more about:
* Request Object

## Request Object

The data from a client’s web page is sent to the server as a global request object. In order to process the request data, it should be imported from the Flask module.

Important attributes of request object are listed below:
* Form − It is a dictionary object containing key and value pairs of form parameters and their values.
* args − parsed contents of query string which is part of URL after question mark (?).
* Cookies − dictionary object holding Cookie names and values.
* files − data pertaining to uploaded file.
* method − current request method.

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
**Check DEMO 2**


## File Uploading 

Handling file upload in Flask is very easy. It needs an HTML form with its enctype attribute set to ‘multipart/form-data’, posting the file to a URL. The URL handler fetches file from request.files[] object and saves it to the desired location.

Each uploaded file is first saved in a temporary location on the server, before it is actually saved to its ultimate location. Name of destination file can be hard-coded or can be obtained from filename property of request.files[file] object. However, it is recommended to obtain a secure version of it using the secure_filename() function.

It is possible to define the path of default upload folder and maximum size of uploaded file in configuration settings of Flask object.

```python
app.config['UPLOAD_FOLDER']  = "/pth to folder" # Defines path for upload folder 
app.config['MAX_CONTENT_LENGTH'] = 5 * 1024 * 1024 # 5 MB  (Specifies maximum size of file yo be uploaded – in bytes )
```
Upload form example:

```html
<html>
   <body>
      <form action = "uploader function" method = "POST" 
         enctype = "multipart/form-data">
         <input type = "file" name = "file" />
         <input type = "submit"/>
      </form>
   </body>
</html>
```

get uploaded file
```python
from werkzeug import secure_filename
app.config['MAX_CONTENT_LENGTH'] = 16 * 1024 * 1024
uploads_dir = os.path.join(app.instance_path, 'uploads')
f.save(os.path.join(uploads_dir, secure_filename(f.filename)))      
```

## Cookies

A cookie is stored on a client’s computer in the form of a text file. Its purpose is to remember and track data pertaining to a client’s usage for better visitor experience and site statistics.

A Request object contains a cookie’s attribute. It is a dictionary object of all the cookie variables and their corresponding values, a client has transmitted. In addition to it, a cookie also stores its expiry time, path and domain name of the site.

In Flask, cookies are set on response object. Use make_response() function to get response object from return value of a view function. After that, use the set_cookie() function of response object to store a cookie.

Reading back a cookie is easy. The get() method of request.cookies attribute is used to read a cookie.

```python
resp = make_response(render_template('readcookie.html'))
resp.set_cookie('userID', user)

## to get cookie
name = request.cookies.get('userID')
```

## Sessions

Unlike a Cookie, Session data is stored on server. Session is the time interval when a client logs into a server and logs out of it. The data, which is needed to be held across this session, is stored in a temporary directory on the server.

A session with each client is assigned a Session ID. The Session data is stored on top of cookies and the server signs them cryptographically. For this encryption, a Flask application needs a defined SECRET_KEY.

Session object is also a dictionary object containing key-value pairs of session variables and associated values.

For example, to set a ‘username’ session variable use the statement −
```python
Session['username'] = 'admin'

# to release a session
session.pop('username', None)
```

## Flask Deployment as external server 

Deployment as external server allow any device in the same network to call it url.

1. Run the server on ip:0.0.0.0

```python
if __name__ == '__main__':
   app.run(host="0.0.0.0")
```

2. Run the server

3. make Hotspot from your PC and connect your phone on it

4. Retrieve your ip address

```
sudo ifconfig
```

you should see the following: take the highlighted IP address 


![](../images/week7ifconfig.png)

5. open your mobile browser and type the retrieved IP address

![](../images/week7mobbrows.png)



**HINT**: When using flask tags { {  , { %, % }, or } } Remove the spaces.



## Demo
All demos will be available in [this](https://github.com/sbme-tutorials/SBE306_2019Demos) repository