# SublimeText4, Snippets to Replace Auto-Complete.









## Description.



*This is a repository that contains a temporary solution, to adapt the* `.sublime-completions` *files, of the annoying auto-complete behavior of Sublime Text 4, to similar auto-complete of Sublime Text 3 using snippets.*








## Warning.



- This is a temporary solution for desperate people, who the painful behavior of the auto-complete of Sublime Text 4, doesn't let it work properly. 
- This is a large and simple coded solution, because I have poor skills on python and scripts languages.
- This steps can be undone (by deleting the files we're going to create, and restoring the `Preferences.sublime-settings` file) in case a new version of Sublime Text gets back the function `insert_best_completions`, and that is the point of [this discussion](https://forum.sublimetext.com/t/st3-style-autocomplete-in-st4/57774/32).








## Requirements.



1. Package Resource Viewer (install it with `ctrl+shift+p`, and on `install` prompt, type `PackageResourceViewer`).
2. Some language package `.sublime-completions` that contains auto-complete commands.
3. Have a `c++` compiler.








## Usage.



1. Identify the language(s) that you want to generate the snippets.
2. In Sublime Text type `ctrl+shift+p` (`cmd+shift+p` on mac) to open the command prompt.
3. Type `PackageResourceViewer: Open Resource`, `Enter`.
4. Type the package name (or language name) that contains sublime files to work. (In the example below, I use it on `LaTeXTools` package).
5. Open the `.sublime-completions` file that you are interested in.
6. On the file, type `ctrl+f`, `alt+r` (to able regex on search), and paste this regex pattern: `(?<="trigger":\s\").*(?=\",)`.
7. Type `alt+Enter` to get all the matches, and copy the selected text, on a new file called `triggers.txt`.
8. Repeat steps 6. and 7., but with the regex pattern: `(?<="contents":\s\").*(?=\s?\"\s?\}?,?)`, and copy the selected text in a new file called `contents.txt`. 
9. Download `SNIPPETS_GENERATOR.cpp` from this repo, and put it on the folder that contains both, `triggers.txt`, and `contents.txt`.
10. Open and run `SNIPPETS_GENERATOR.cpp`. (If you're Linux user, you have to uncomment the line `176`, and comment the line `177`).
11. `INSERT THE EXTENSION OF THE FILES :` Type `txt`.
12. `INSERT THE ACTION :` Type `5`.
13. `SCOPE OF THE SNIPPETS : `
    1. Type the language scope that snippets will be applied. [Here](https://gist.github.com/J2TEAM/a54bafb082f90c0f20c9) is a list with the scopes of all languages.
    2. On the example below, the scope we need is `text.tex`.
14. `FILENAME WITH THE TRIGGERS :` Type `triggers`.
15. `FILENAME WITH THE CONTENTS :` Type `contents`.
16. Exit the program.
17. Copy and paste the `.sublime-snippet` files (that the program generated) into `sublime-text-4/Packages/User` folder to use them.
18. Repeat steps 2. to 17. for all languages and packages that you want.
19. In Sublime Text, open the prompt, `ctrl+shift+p`, and type `settings`, `Enter`.
20. Add the following lines to the file that popup's (`Preferences.sublime-settings`) to ignore the auto-completions.

```c++
{
	"tab_completion": false,
	"auto_complete": false // a comma (,) is needed if there are more configuration below.
}
```



And that's it!!! 

With these steps, should be generated `.sublime-snippet` files that will substitute `.sublime-completions`, and auto-completion it's not disturbing anymore.








## Example


1. Download the entire folder of this repository from [here](https://github.com/ZeraujKcire/Sublime-Text-4-Snippets-to-Replace-Auto-Complete/archive/refs/heads/main.zip).
2. Go to [example](https://github.com/ZeraujKcire/Sublime-Text-4-Snippets-to-Replace-Auto-Complete/tree/main/example) folder to see this program applied to LaTeX language.








## Back to sublime text default configuration.



1. Delete the files that were created.
2. Restore the file `Preferences.sublime-settings`.
