#!/bin/bash
g++ -DLOCAL -Wall -Wextra -Wno-sign-conversion -Wshadow "$1" -o exc && ./exc
