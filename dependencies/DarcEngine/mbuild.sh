#!/bin/bash
DIRECTORY=./_build
if [ ! -d "$DIRECTORY" ]; then
	mkdir "$DIRECTORY"
fi

cd "$DIRECTORY"
cmake ../ -G "Xcode"
xcodebuild -target install
cd ..
