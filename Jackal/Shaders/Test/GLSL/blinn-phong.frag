// Copyright (c) 2017 Jackal Engine, MIT License.
# version 430

layout (location = 0) in vec3 FragPosition;
layout (location = 1) in vec3 FragNormal;
layout (location = 2) in vec2 FragTexCoord;


layout (location = 0) out vec4 FragColor;


struct PointLight {
  vec3    position;
  vec3    color;
  float   radius;
  int     enabled;
};


struct DirectionalLight {
  vec3  direction;
  vec3  color;
  int   enabled;
};


layout (binding = 0) uniform UBO {
  mat4 model;
  mat4 view;
  mat4 projection;
  vec3 camPosition;
} ubo;





void main() 
{
  // Red color!
  FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}