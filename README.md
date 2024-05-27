# Ash
```
           _     
  __ _ ___| |__  
 / _` / __| '_ \ 
| (_| \__ \ | | |
 \__,_|___/_| |_|
                 
```
An interactive **archive shell**. Built upon (libarchive)[https://github.com/libarchive/libarchive].

## Why?
You don't always have GUI to run File roller or Ark. Furthermore, I want to access my archives and interact with them like in a unix shell.

## Building

Dependencies: `libarchive`, `readline`, `meson` (build-only), `ninja` (build-only)

```sh
$ cd src
$ meson setup b
$ cd b
$ ninja
```

## License
MIT