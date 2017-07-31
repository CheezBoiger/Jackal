// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "OpenGLConfigs.hpp"
#include "RenderDevice/RenderDeviceTypes.hpp"


namespace jackal {


struct GLNativeTextureFormat {
  GLenum format;
  GLenum dataType;
  GLenum internalFormat;
};

class OpenGLNative {
public:
  static GLNativeTextureFormat GetNativeTextureFormat(FormatT format);
};
} // jackal