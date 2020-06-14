# LangOCR
> Quickly screen capture language content for quick dictionary look ups.

This is a prototype for LangOCR, a cross-platform OCR application for
quick dictionary look-ups during active immersion of non-selectable
text.

This program is designed in line with the methodologies of the
MIA. For more information, please check out the [MIA
Website](https://massimmersionapproach.com/).

## Goals and Considerations
At this moment, this application is a prototype. The architecture is
still being developed so the code is in a high level of flux.

This application is intended to supplement active immersion while
reading in the target
language. [Yomi-chan](https://foosoft.net/projects/yomichan/) and
applications like it are fantastic when the text is selectable, but
it's difficult to do the same when the text of the medium cannot be
selected. This is where LangOCR comes in.

LangOCR is a temporary name until I think of something
better...

The goals of LangOCR are to do the following.

* Minimize time the user spends looking up entries in a dictionary
* Minimize time the user spends making N+1 sentence cards for Anki. 
* Log frequency of the words the user comes across.
* Utilize a flexible dictionary interface for cross-language
  translations (e.g. EN to JP and JP to JP Translations).
* Leverage the machine learning engine at the core of this application
  for various future applications.
* Create a low-load intensity architecture that can capture and decode
  text over time. This goal is targeted to capture from games that
  use text as it's main form of communication.
* This application is designed for Windows, Mac, and Linux. That being
  said, my all my machines run Linux. In the temporary, Linux will see
  the most focus as the application takes shape.
* Implement a flexible 'rule set' so the user can control how LangOCR
  operates.

## Installation
Until I have time to test on multiple platforms, I'm going to have to
assume that developers interested on contributing can figure out the
nitty-gritty of getting the packages they need. The following packages
are installed on my system.

* g++ (Arch Linux 9.3.0-1) 9.3.0
* GNU Make 4.3
* QMake version 3.1
* Qt version 5.14.2
* tesseract 4.1.1
* leptonica-1.79.0

## Coding Style
Please follow [Google C++ Coding
Style](https://google.github.io/styleguide/cppguide.html). All PRs
should adhere to Google coding style.

There is an emphasis on readability and modularity. As the project
develops, it is realistic that major aspects of the code base will be
interchanged.

## Contact
You can contact me through my twitter, by github, or by email. Email
will get the quickest responses.

Skylar Scott – 
Twitter:[@GeekTeaa](https://twitter.com/GeekTeaa)
Email: skyenet.inbox@gmail.com

PR and bug reports should be file on GitHub. 

This code is distributed under the GNU license. See ''LICENSE'' for
more information.

## Contributing
If you want to contribute, please and thank you! While the project is
in it's early stages, I ask that you contact me before tackling major
changes so the changes are in line with the architecture goals.

My speciality is in embedded C and networking programming
concepts. Programmers of all backgrounds are welcome, but this project
is missing programmers with a strong foundation in QT and Machine
Learning. 