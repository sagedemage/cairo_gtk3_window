#!/bin/sh
clang-tidy --format-style=file ../src/main.c ../src/pch/cairo_gtk3_window-pch.h
