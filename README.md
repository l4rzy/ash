# Ash
```
           _      ____   
  __ _ ___| |__   \ \ \  
 / _` / __| '_ \   \ \ \ 
| (_| \__ \ | | |  / / / 
 \__,_|___/_| |_| /_/_/  
                         
                 
```
An interactive **archive shell**. Built upon [libarchive](https://github.com/libarchive/libarchive).

## Why?
You don't always have a GUI environment to run File Roller or Ark. Furthermore, I want to access my archives and interact with them like in a UNIX shell.

## Building

Dependencies: `libarchive`, `readline`, `meson` (build-only), `ninja` (build-only)

```sh
$ cd src
$ meson setup b
$ cd b
$ ninja
```

## Screenshots
![screenshot1](/assets/s1.png)


## License
MIT