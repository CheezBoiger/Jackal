// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLDevice/OpenGLNative.hpp"

#include "Core/Logging/Assertions.hpp"
#include "Core/Logging/Debugging.hpp"

namespace jackal {


GLNativeTextureFormat OpenGLNative::GetNativeTextureFormat(FormatT format)
{
  switch (format) {

    // TODO(): Add in cases for each format type.
  case FORMAT_D16_UNORM:                return { GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, GL_DEPTH_COMPONENT };
  case FORMAT_D32_SFLOAT:               return { GL_DEPTH_COMPONENT, GL_FLOAT, GL_DEPTH_COMPONENT };
  case FORMAT_D16_UNORM_S8_UINT: 
  case FORMAT_D24_UNORM_S8_UINT:        return { GL_DEPTH_STENCIL, GL_UNSIGNED_INT, GL_DEPTH_STENCIL };
  case FORMAT_D32_SFLOAT_S8_UINT:       return { GL_DEPTH_STENCIL, GL_FLOAT, GL_DEPTH_STENCIL };

  case FORMAT_R8G8B8A8_SINT:            return { GL_RGBA, GL_INT, GL_RGBA8 };
  case FORMAT_R8G8B8A8_SRGB:
  case FORMAT_R8G8B8A8_SSCALED:
  case FORMAT_R8G8B8A8_UINT:            return { GL_RGBA, GL_UNSIGNED_INT, GL_RGBA8 };

  case FORMAT_R16G16B16A16_SFLOAT:      return { GL_RGBA, GL_FLOAT, GL_RGBA16F };
  case FORMAT_R16G16B16A16_SSCALED: 
  case FORMAT_R16G16B16A16_USCALED:
  case FORMAT_R16G16B16A16_UNORM:
  case FORMAT_R16G16B16A16_UINT:        return { GL_RGBA, GL_UNSIGNED_INT, GL_RGBA16 };
  case FORMAT_R16G16B16A16_SNORM:
  case FORMAT_R16G16B16A16_SINT:        return { GL_RGBA, GL_INT, GL_RGBA16 };

  case FORMAT_R32G32B32A32_SFLOAT:      return { GL_RGBA, GL_FLOAT, GL_RGBA32F };
  case FORMAT_R32G32B32A32_SINT:        return { GL_RGBA, GL_INT, GL_RGBA };
  case FORMAT_R32G32B32A32_UINT:        return { GL_RGBA, GL_UNSIGNED_INT, GL_RGBA };
 
  case FORMAT_R8G8B8_SRGB:
  case FORMAT_R8G8B8_SNORM:
  case FORMAT_R8G8B8_SSCALED:
  case FORMAT_R8G8B8_SINT:              return { GL_RGB, GL_INT, GL_RGB8 };
  case FORMAT_R8G8B8_UNORM:
  case FORMAT_R8G8B8_UINT:              return { GL_RGB, GL_UNSIGNED_INT, GL_RGB8 };

  default:                              return { GL_RGBA, GL_UNSIGNED_INT, GL_RGBA };
  }
}
} // jackal