#!/bin/bash
cd ./ai_help
bash keygen.sh
cd ./key
rm file*
cd ..
bash unifier.sh
