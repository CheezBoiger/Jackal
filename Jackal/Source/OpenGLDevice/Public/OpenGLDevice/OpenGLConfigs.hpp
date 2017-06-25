// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "opengl/glad/glad.h"


// Return any errors should there be any.
#define OPENGL_CHECK_ERROR(handler) handler = glGetError()