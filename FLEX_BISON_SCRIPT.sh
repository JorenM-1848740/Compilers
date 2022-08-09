#!/bin/bash
flex -o flex.cpp goLex.l
bison goBison.y -v -o bison.cpp