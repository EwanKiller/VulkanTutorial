#!/bin/bash
shaderdir=$(pwd)

mkdir -p $shaderdir/../../../cmake-build-debug/src/HelloTriangle/shaders

targetdir=$shaderdir/../../../cmake-build-debug/src/HelloTriangle/shaders

echo $targetdir

cp vert.spv $targetdir

cp frag.spv $targetdir
