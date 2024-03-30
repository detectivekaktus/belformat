# belformat
Belformat is a simple and convenient tool for styling and formatting output in C. Use a syntax similar to HTML and add originality to your project. Belformat operates around the standard output functions in C from `stdio.h`, as well as ANSI escape codes.

The library is written in the C programming language and does not require additional dependencies to function. You can use this tool as either a statically generated library or as a dynamic library depending on your needs.

The project is open to everyone, and anyone familiar with [CONTRIBUTING.md](https://github.com/Artiom-Astashonak/belformat/blob/master/CONTRIBUTING.md) can suggest their own changes to the repository to make Belformat better and more convenient.

## Examples
If you prefer not to read all the detailed examples of the library usage below, compile a single example file and run it by executing:

```sh
$ make examples
$ ./exam
```
### Formatting
Belformat provides all the standard formatting methods available to ANSI users with a simpler and more understandable syntax.

#### Bold
Use the `<b>` tag (for `b`old) before the start of the text block you want to make bold, and close the tag with `</>` at the end f the block to reset all styles added before it.

`</>` is universal for every single tag, as it appends clear sequence that deletes all styling.
![Bold text](https://github.com/Artiom-Astashonak/belformat/blob/master/img/boldtext.png)

#### Italic
To achieve italic text, use the `<i>` tag (for `i`talic) and close it with `</>` at the very end, resulting in a similar outcome:

![Italic text](https://github.com/Artiom-Astashonak/belformat/blob/master/img/italictext.png)

#### Underlined
Underline text with the `<u>` tag (for `u`nderlined), which like all tags, must be closed with `</>` to remove its effect for all subsequent characters.

![Underlined text](https://github.com/Artiom-Astashonak/belformat/blob/master/img/underlinedtext.png)

#### Strikethrough
To get strikethrough text, use the combination of `<s>` tag (for `s`trikethrough) and `</>` as in previous cases.

![Strikethrough text](https://github.com/Artiom-Astashonak/belformat/blob/master/img/strikethroughtext.png)

#### Dim
Dim color is relative to the current text color and depends on your terminal settings. Use a combination of `<d>` tag (for `d`im) and `</>` to achieve the desired result.

![Dim text](https://github.com/Artiom-Astashonak/belformat/blob/master/img/dimtext.png)

#### Reversed
Reversed color swaps the text color and the background color. Use `<r>` (for `r`eversed) along with `</>`.

![Reversed text](https://github.com/Artiom-Astashonak/belformat/blob/master/img/reversedtext.png)

#### Blinking
This type may not be available for your terminal. Wrap the text in `<l>` (for b`l`inking) and close it with `</>`.

#### Private
You can hide the output values using `<p>` (for `p`rivate) and close it with `</>`.

### Styling
In addition to formatting using standard ANSI, you can also style text using terminal-dependent colors. Available colors are: black, red, green, blue, yellow, magenta, cyan and white.

The general syntax for adding colors works as follows: `<tag_name;foreground_color;background_color>`. For example:
![Colors example](https://github.com/Artiom-Astashonak/belformat/blob/master/img/terminalcolors.png)

To add color exclusively without formatting, use the `<c>` (for `c`olor) tag.

If you wish to have your own colors, you can add them with HEX color notation like so:
![User colors](https://github.com/Artiom-Astashonak/belformat/blob/master/img/usercolors.png)

### Utility
The project also has several utilities for logging output (`bellog()` function), information (`belinfo()` function), warnings (`belwarn()` function), and errors  (`belerror()` function).

![Utility functions](https://github.com/Artiom-Astashonak/belformat/blob/master/img/utilities.png)

## Compilation
Belformat assumes you have a C compiler (either GCC or clang) installed, as well as GNU make for building the library.

To generate a dynamic library, follow the instructions for your operating system below:

### POSIX
```sh
$ make psx_belformat
```

### Windows
```sh
$ make win_belformat
```

Otherwise, generate a static library with the following command:
```sh
$ make static_belformat
```
