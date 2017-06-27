// Copyright (c) 2017 Jackal Engine, MIT License.
#version 430 
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texcoord;
layout (location = 3) in vec3 basecolor;

layout (location = 0) out vec3 FragPosition;
layout (location = 1) out vec3 FragNormal;
layout (location = 2) out vec2 FragTexCoord;

layout (binding = 0) uniform UBO {
  mat4 model;
  mat4 view;
  mat4 projection;
  vec3 camPosition;
} ubo;


void main() 
{

}