# Caesar Encryption
This repo contains the source code of an implementation of the Caesar cipher and decipher algorithms in C, as well as a compilation of it for Windows.

```
usage: <program_name> <cipher|decipher> <key> <string_to_process>
```

Example (Linux - identical in all platforms):
```
$ gcc caesar.c -o caesar
$ ./caesar cipher 1 ABCD
BCDE
$ ./caesar decipher 2 ABCD
YZAB
```