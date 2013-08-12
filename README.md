# FaceRecognitionInterface
Face recognition software

The objective is to make a software like picasa but that can really run on linux and that can handle many files (picasa get stuck when there are too many files, and sometimes it "forgets" tags)


## Features

* manual tagging
* validation
* ignore tags
* automatic face detected
* automatic face recognition
* show tagged tags
* show tagged pictures

## Roadmap

* handle recursive path (folders)
* handle multi-path
* improve recognition
* use clustering ( k-means ? ) to make face tags faster
* make a demo with public pictures


## Install and run

You need to install Qt5.1


* git clone --recursive
* cd facerecognitioninterface
* qmake && make
* mkdir donnees
* cp -R ...your_photos... donnees/photos
* FaceRecognitionInterfaceApp/bin/FaceRecognitionInterface

* file/detect
* tag a few face
* file/recognize
* validate/invalidate the tags
* and again until every face is tagged

* then you can see the tagged photo and cut photo by person
