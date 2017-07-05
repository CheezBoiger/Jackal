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


// A Surface material of the mesh to render.
layout (binding = 1) uniform sampler2D Ambient;
layout (binding = 2) uniform sampler2D Diffuse;
layout (binding = 3) uniform sampler2D Specular;


// Material object.
struct Material {
  vec4 ambient;
  vec4 diffuse;
  vec4 Specular;
};

// Material handle.
Material material;


// Blinn Phong implementation of Point Light. Direct Illumination.
vec3 BlinnPhongPointLight(PointLight light, vec3 FragPos, vec3 N, 
  vec3 V, Material material)
{
  vec3 L = light.position - FragPos;
  
  float kD = 0.0;
  float kS = 0.0;
  
  // Lambertian diffuse.
  kD = max(dot(L, N), 0.0);

  // Blinn's implementation of calculating our half vector.
  vec3 H = normalize(L + V);
  
  kS = pow(max(dot(N, H), 0.0) 32.0);
  
  vec3 ambient = vec3(0.1f);
  vec3 diffuse = light.color * kD * vec3(material.diffuse);
  vec3 specular = light.color * kS * vec3(material.specular);

  // Get the distance between light's position and fragment position on screen.
  float distance = length(light.position - FragPos);
  
  // Attenuation of the light
  float attenuation = light.radius / ((distance * distance) + 1.0f);

  // Light shading based on distance of the light and surface.
  ambient *= attenuation;
  diffuse *= attenuation;
  specular *= attenuation;
  
  return (ambient + diffuse + specular);
}


vec3 BlinnPhongDirectionalLight(DirectionalLight light, vec3 FragPos,
  vec3 N, vec3 V, Material material)
{
  return vec3(0.0);
}


void main() 
{
  vec3 ViewDirection = ubo.camPosition - FragPosition;
  
  // Set Mesh material to this object mat.
  material.ambient = texture(Ambient, FragTexCoord).rgb;
  material.diffuse = texture(Diffuse, FragTexCoord).rgb;
  material.Specular = texture(Specular, FragTexCoord).rgb;
  
  // Perform light calculations!
  
  // TODO():
  
  // Red color!
  FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}