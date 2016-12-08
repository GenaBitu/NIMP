#!/bin/bash

cppcheck -v -I. --enable=warning,style,performance,portability,information,missingInclude src 2> CppCheckResults.txt
