# FourthYearProject
An Intelligent Accompanist System for Classical Music


Michael Lo and Joshua Free's Engineering part four project

### Build Status
Master [![Build Status](https://magnum.travis-ci.com/joshofreeness/FourthYearProject.svg?token=Y4CqoqssvV45tBA9C2v1&branch=master)](https://magnum.travis-ci.com/joshofreeness/FourthYearProject)

Develop [![Build Status](https://magnum.travis-ci.com/joshofreeness/FourthYearProject.svg?token=Y4CqoqssvV45tBA9C2v1&branch=develop)](https://magnum.travis-ci.com/joshofreeness/FourthYearProject)

### Project Description
The proposed project seeks to develop an intelligent accompanist system for classical music.

More about scope investigations, project development and decisions made can be found in the [project wiki](https://github.com/joshofreeness/FourthYearProject/wiki)

### Compile Instructions
#### Windows
To build on Windows, open the project found in Project/Builds/Visual Studio 2013.

The output will be a VST plugin (.dll file on Windows). Currently, only Cantabile 1.2 is supported (Download link can be found [here](https://web.archive.org/web/20080109234626/http://www.toptensoftware.com/downloads/Cantabile12LiteSetup.exe), but you are welcome to try it on any other DAW.

#### Linux
To build you need to install the package libasound2-dev, and run `make` from the terminal in the folder Project/Builds/Linux.

The output will be a VST plugin (.so file on Linux).

#### Mac OS
TODO: TALK ABOUT HOW WE CAN'T GET IT TO COMPILE, BUT IN A WAY THAT DOESN'T MAKE US SOUND INCOMPETENT
(particularly how it has never compiled, not even the auto-produced empty Juce project)

### Usage Instructions
#### Windows
If Visual Studio 2013 is not installed, you will need to manually find copies of the following files in C:/Windows/System32: 
 - gpsvc.dll
 - IEShims.dll
 - msvcp120.dll
 - msvcr120.dll
and put them in the same directory as the plugin's .dll file.

Select the plugin in your host DAW, and use the provided MIDI file to supply the beat (or create your own).

Set up a MIDI synthesiser/digital instrument, and route the plugin's output into it.

Start the beat track to begin producing output.
