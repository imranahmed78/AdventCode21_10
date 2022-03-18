#!/bin/sh

BUILDFOLDER=build

if [ ! -d "$BUILDFOLDER" ]; then
  mkdir "$BUILDFOLDER"
  echo "$BUILDFOLDER folder is created."
else
  echo "$BUILDFOLDER folder already exists"
  echo "make clean"
  cd build make clean
  cd ..
fi

cd build
cmake ..
make
./SubmarineSyntaxScoring

