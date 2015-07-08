# FourthYearProject
An Intelligent Accompanist System for Classical Music


Michael Lo and Joshua Free's Engineering part four project

### Build Status
Master [![Build Status](https://magnum.travis-ci.com/joshofreeness/FourthYearProject.svg?token=Y4CqoqssvV45tBA9C2v1&branch=master)](https://magnum.travis-ci.com/joshofreeness/FourthYearProject)

Develop [![Build Status](https://magnum.travis-ci.com/joshofreeness/FourthYearProject.svg?token=Y4CqoqssvV45tBA9C2v1&branch=develop)](https://magnum.travis-ci.com/joshofreeness/FourthYearProject)

### Project Description

The proposed project seeks to develop an intelligent accompanist system for classical music.

More about scope investigations, project development and decisions can be found in the [project wiki](https://github.com/joshofreeness/FourthYearProject/wiki)

### Compile Instructions
#### Linux
To build you need to install the package libasound2-dev, and run `make` from the terminal in the folder Project/Builds/Linux.

The output will be a VST plugin (.so on Linux) that can be used in any modern DAW.

#### Windows
To build on Windows, open the project found in Project/Builds/Visual Studio 2013.

The output will be a VST plugin (.dll on Windows) that can be used in any modern DAW.

