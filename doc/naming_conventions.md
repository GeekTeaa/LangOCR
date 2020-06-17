## Notable naming conventions
The program is built very heavily on Qt. I'm seeing this disctinction
that in some places its appropiate to make abstraction layers, and in
some places I want to name according to the object that it
inherits. At this moment I don't think I understand enough to pick
standard, and I fear the best option is mixed. I'm learning towards a
standard of abstraction.

## Terminology used
#### App
Refers to the main application that runs the GUI. The
only *App* that should exist in the program is `LangOcrApp`.

#### Overlay
Indicates a screen sized transparent QWidget.
