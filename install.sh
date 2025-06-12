#!/bin/bash

BUILD_DIR=build

rm -r "$BUILD_DIR"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

CMAKE_ARGS=()
for arg in "$@"; do
    CMAKE_ARGS+=("-D$arg")
done

cmake "${CMAKE_ARGS[@]}" ..