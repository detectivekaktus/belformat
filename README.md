# belformat
***WARNING!* This library is in-progress, which means that everything implemented at the moment can change slightly without any announcements in the future. Use this library at your own risk!**

belformat is an output formatting and styling library in the terminal.

belformat is implemented in the C programming language, and is compatible with all terminals across all the operating systems included Microsoft Windows, macOS and Linux.

## Compilation
The belformat project requires you to have a **C compiler** installed on your machine (either GCC or clang) and **GNU make** build tool.

Depending on your target operating system, you should envolve the following compile commands:

### POSIX
```sh
$ make psx_belformat
```

### Windows
```sh
$ make win_belformat
```

## Functionalities
The belformat library provides styling tags wrapping the standard C output functions. All the styling tags share similar to HTML syntax: to open a new tag add `< >` characters and put a special identifier in the middle of the brackets to get the stylized output. All the characters printed after this tags are going to have a style applied on them.

Here are available identifiers for the tags:
| Name | Description |
| --- | --- |
| b | Boldifies the characters |
| i | Turns italic the characters |
| u | Underlines the characters | 
| s | Strikethroughs the characters |
| d | Makes dim the characters |
| l | Blinks the the characters |
| p | Hides the characters outputted. |
| r | Reverses the color of the characters |
| / | Resets all styling applied before. |
