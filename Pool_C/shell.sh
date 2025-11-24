#!/bin/bash

for i in {01..07}; do
  cd "Day_$i"
  mv "hi" ".hi"
  echo "hello there :)" >>".hi"
  rm "hi"
  cd ".."
done
