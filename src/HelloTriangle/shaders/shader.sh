#!/bin/bash
glslc shader.vert -o vert.spv

glslc shader.frag -o frag.spv

shaderdir=$(pwd)

mkdir -p $shaderdir/../../../cmake-build-debug/src/HelloTriangle/shaders

targetdir=$shaderdir/../../../cmake-build-debug/src/HelloTriangle/shaders

echo $targetdir

cp vert.spv $targetdir

cp frag.spv $targetdir
