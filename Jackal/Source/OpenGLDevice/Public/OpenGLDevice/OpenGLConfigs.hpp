// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "opengl/glad/glad.h"


// For anisotropy
#define GL_TEXTURE_MAX_ANISOTROPY_EXT          0x84FE

// Return any errors should there be any.
#define OPENGL_CHECK_ERROR(handler) handler = glGetError()