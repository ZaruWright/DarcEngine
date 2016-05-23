#!/bin/bash
DIRECTORY=./_build
if [ ! -d "$DIRECTORY" ]; then
	mkdir "$DIRECTORY"
fi

cd "$DIRECTORY"
cmake ../ -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
make
make install
cmake ../ -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
make
make install
cd ..
