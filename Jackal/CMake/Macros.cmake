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


# macro to set up x11 and xcb libraries.
macro(xcb_and_x11_init Target)
  if (UNIX)
     # Should be unix based operating system.
     find_package(X11 REQUIRED)
     find_package(XCB REQUIRED)

     include_directories(
	${X11_INCLUDE_DIR}
	${XCB_INCLUDE_DIRS}
     )

     target_link_libraries(${Target} ${X11_LIBRARIES} ${XCB_LIBRARIES})
  endif()
endmacro()

# Organize projects to the jackal directory within visual studio.
macro(visual_studio_to_folder Target Folder)
  if (WIN32)
    set_property(TARGET ${Target}
      PROPERTY
      FOLDER ${Folder}
    )
  endif()
endmacro()


# Organize project files in visual studio
# Target is the file glob to organize.
macro(visual_studio_organize_project Target)
if (MSVC)
  foreach(source IN LISTS Target)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
  endforeach()
endif()
endmacro()