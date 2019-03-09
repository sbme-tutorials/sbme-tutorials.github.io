---
layout: page
course: "sbe201"
category: "notes"
year: "2019"
title:  "Steps for using Public Key Authentication for accessing your GitHub repositories"
by: "Asem"
---

* TOC
{:toc}


## Generate private key on your machine

Open your terminal and run the `ssh-keygen` app, then press enter for any dialog:

```
$ ssh-keygen
> Generating public/private rsa key pair.
> Enter a file in which to save the key (/home/you/.ssh/id_rsa): [Press enter]
> Enter passphrase (empty for no passphrase): [Press enter]
> Enter same passphrase again: [Press enter]
```

Now you generated a private key.

## Copy your public key that was generated alongside the private key

To copy your public key contents, print the file on the terminal using the following command `more ~/.ssh/id_rsa.pub`, then you should see a long generated text like so:

```
$ more ~/.ssh/id_rsa.pub
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCf4n+BJddGKbJ3h2VK07yCFZ+xf1Nofz0ydWLi2uHE
v0cPEoOpdPDoX50eQfTvqgdT9OWbBCwc99ElRwqvG2WugQhjqcnoUJ7tApigYvooBpfyNal5nXEj2pO/
mbesncqizthWg5xwC5KeRWe6e2GpHRKnGCsolOls3+gI3tInYzNHXyc/f567lN11qIO4E2jdXOfMgocM
TPmADuqZE6G207aO3vos8aYumTcUT2pAtSklzsk2FD2wFo/bitbaDkWMl0t5v/qN7sgJPXWhdGqPfi1L
W1hqvwXGTGaBZvdW1xy7wWxoIm2aAPJwluxS2Gnb9bhHimrlDZzStDqzvfTT asem@asem-pc
```

Using your mouse, select all the text the is shown after the command `more ~/.ssh/id_rsa.pub`

## Add the public key to your GitHub account

Follow the steps illustrated in the following screenshots.

![ssh1](/gallery/add_ssh1.png)


![ssh2](/gallery/add_ssh2.png)


![ssh3](/gallery/add_ssh3.png)


![ssh4](/gallery/add_ssh4.png)


## Use SSH links instead of HTTPS

### Cloning a new repository

If you are going to clone a new repository, just make sure to use the link associated with **SSH**, not ~HTTPS~.

![clone](/gallery/clone_ssh.png)

Make sure the link starts with `git@` instead of `https://`.

### If your repository already cloned using HTTPS

If you have already cloned a repository using `HTTPS` link, retrive the **SSH** link as shown above, then issue the following command in a terminal **placed in your repository**:

```
git remote set-url origin [ssh link]
```

Replace `[ssh link]` with the actual **SSH** link your retrieved.


## Reference

[Connecting to GitHub with SSH](https://help.github.com/en/articles/connecting-to-github-with-ssh)