# Copyright (c) Jackal Engine, MIT License.
macro(append_gitignore FilePath Arg1)
  file(APPEND ${FilePath} Arg1)
endmacro(append_gitignore)