#include "../src/belformat.h"

void welcome() {
  belprintf("<b;cyan>Belformat</> is a new way of formatting output in C!\n");
  belprintf("With <b;cyan>Belformat</> you can stylize and color your output\n");
  belprintf("however you want with simple HTML-like syntax! The library wraps\n");
  belprintf("the standard C output functions combined with ANSI escape codes to\n");
  belprintf("provide simplier experience with terminal fomatting!\n\n");
}

void styles() {
  belprintf("Here are the styles you can apply to the outputted characters:\n");
  belprintf("  1. Characters can be <b>bolded</> with the %s tag!\n", "<b>");
  belprintf("  2. Also, you can output <i>italic-style characters</> with %s.\n", "<i>");
  belprintf("  3. If there is something <u>important to underline</>, you can do it with the %s tag!\n", "<u>");
  belprintf("  4. Or if you <s>screwed up</> and want to strike through the text, do it with %s!\n", "<s>");
  belprintf("  5. <d>Unavailable content</> can be dimmed using %s.\n", "<d>");
  belprintf("  6. <l>Blinking text</> is also supported by the <b;cyan>Belformat</> project with the %s tag!\n", "<l>");
  belprintf("  7. <r>Reverse your colors with %s.</>\n", "<r>");
  belprintf("  8. If there is something <p>private</>, just hide it with %s!\n\n", "<p>");
}

void colors() {
  belprintf("Need more creativity? <b;cyan>Belformat</> supports terminal-predefined colors for your output!\n\n");
  belprintf("<c;black>Black</>  <c;red>Red</>  <c;green>Green</>  <c;blue>Blue</>  <c;yellow>Yellow</>  <c;magenta>Magenta</>  <c;cyan>Cyan</>  <c;white>White</>\n");
  belprintf("<r;black>Black</>  <r;red>Red</>  <r;green>Green</>  <r;blue>Blue</>  <r;yellow>Yellow</>  <r;magenta>Magenta</>  <r;cyan>Cyan</>  <r;white>White</>\n\n");
  belprintf("These colors are terminal dependent and can vary on different systems.\n");
  belprintf("So, the <b;cyan>Belformat</> project comes with a better solution that supports HEX-based colors for your output!\n");
  belprintf("<r;#ff0000>   </><r;#ff2200>   <r;#ff4400>   </><r;#ff6600>   </><r;#ff8800>   </><r;#ffaa00>   </><r;#ffcc00>   </><r;#ffee00>   </><r;#eeff00>    </><r;#ccff00>   </><r;#aaff00>   </><r;#88ff00>   </><r;#66ff00>    </><r;#44ff00>    </><r;#22ff00>    </><r;#00ff00>   <r;#00ff22>   </><r;#00ff44>   </><r;#00ff66>   <r;#00ff88>   </><r;#00ffaa>   <r;#00ffcc>   </><r;#00ffee>   </><r;#00eeff>   </><r;#00ccff>   </><r;#00aaff>   </><r;#0088ff>   </><r;#0066ff>   </><r;#0044ff>   </><r;#0022ff>   </><r;#0000ff>   </>\n\n");
}

void logging() {
  belprintf("At the end, <b;cyan>Belformat</> offers you some basic logging functions for your project such as:\n");
  bellog("Logging with precision of hours, minutes and seconds.\n");
  belinfo("Information logging with a simple prefix.\n");
  belwarn("Warnings with formatting!\n");
  belerror("Errors outputted in <b>stderr</> stream.\n");
}

int main(void) {
  welcome();
  styles();
  colors();
  logging();
  return 0;
}
