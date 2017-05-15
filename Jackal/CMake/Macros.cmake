# Copyright (c) Jackal Engine, MIT License.

# Simple file appending.
macro(append_gitignore FilePath Arg1)
  file(APPEND ${FilePath} Arg1)
endmacro(append_gitignore)


# Set a macro used to change our c++ requirements to a given standard.
# This can be useful for GCC as it needs to be enabled on these compilers.
macro(set_cxx_standard Target Standard)
  set_property(TARGET ${Target} PROPERTY CXX_STANDARD ${Standard})
  set_property(TARGET ${Target} PROPERTY CXX_STANDARD_REQUIRED ${Standard}) 
endmacro()