# Example.







## Description.



*This is a sketch of the steps to create* `.sublime-snippet`*'s, from* `.sublime-autocompletions` *file.*






### Requirements.


1. `PackageResourceView`. (It can be installed by `ctrl+shift+p`, typing `install`, and then `PackageResourceView`, `Enter`).
2. `LaTeXTools` sublime package. (as above, it can be installed by `ctrl+shift+p`, `install package`, and type `LaTeXTools`).
3. A `c++` compiler.








### Steps to reproduce.


1. Download entire repository folder from [here](https://github.com/ZeraujKcire/Sublime-Text-4-Snippets-to-Replace-Auto-Complete/archive/refs/heads/main.zip), and open Sublime Text.
2. `ctrl+shift+p`, `Enter`.
3. `PRV:Open`, `Enter`.
4. Package names.
   1. `LaTeXTools`, `Enter`, `LaTeX math.sublime-completions`, `Enter`.
   2. `LaTeX.sublime-completions`, `Enter`.
   3. `Beamer.sublime-completions`,`Enter`.

6. `ctrl+f`, `alt+r`, `(?<="trigger":\s\").*(?=\",)`. And paste the result in `1.-TRIGGERS_AND_CONTENTS/triggers.txt`. 

6. `ctrl+f`, `(?<="contents":\s\").*(?=\s?\"\s?\}?,?)`. And paste the result in `1.-TRIGGERS_AND_CONTENTS/contents.txt`. 

10. Run `SNIPPETS_GENERATOR.cpp`.

11. `INSERT THE EXTENSION OF THE FILES :`  `txt`.

12. `INSERT THE ACTION :`  `5`.

13. `SCOPE OF THE SNIPPETS :` `text.tex`.

14. `FILENAME WITH THE TRIGGERS :` `example/1.-TRIGGERS_AND_CONTENTS/triggers`. (all without spaces).

15. `FILENAME WITH THE CONTENTS :` `example/1.-TRIGGERS_AND_CONTENTS/contents`. (all without spaces).

16. `INSERT ACTION :` `6`.

17. Paste the `.sublime-snippet` files into `sublime-text-4/Packages/User` folder.

19. `ctrl+shift+p`, `settings`, `Enter`.

20. Add the following lines to `Preferences.sublime-settings`.

```c++
{
	"tab_completion": false,
	"auto_complete": false // a comma (,) is needed if there are more configuration below.
}
```



And that's it!!! 

Any of this steps can be done with other sublime packages.








### Completions Used in this example.


In the folder `0.-COMPLETIONS_FILES`, are located the files that `LaTeXTools` use for auto-completions, and it were obtained in the step 4.









### Triggers and Contents in this example.


As a guide for how to make a bunch of snippets, in  directory `1.-TRIGGERS_AND_CONTENTS`, are located the files `triggers.txt`, and `contents.txt`, and contains the 3 `.sublime-completions` in order. 










### Snippets generated in this example.


In `2.-SNIPPETS_GENERATED`, are all the `.sublime-snippet`'s that were made by the program.



Here are the firsts snippets that were generated.



| Trigger | Content            |
| ------- | ------------------ |
| a       | \alpha             |
| baa     | \begin{align}...   |
| baan    | \begin{alignat}... |
| bal     | \begin{align*}...  |
| ...     | ...                |








### Back to sublime text default configuration.

1. Delete the files that were created.
2. Restore the file `Preferences.sublime-settings`.
