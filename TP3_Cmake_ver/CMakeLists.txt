# CMakeList.txt: proyecto de CMake para TP3 Cmake ver, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
file(GLOB implementacion "src/*.cpp" "lib/*.cpp")

add_executable (CMakeTarget  
        main.cpp
        ${implementacion}
)

target_include_directories (CMakeTarget PRIVATE
        "include"
        "lib"
        "src"
)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
