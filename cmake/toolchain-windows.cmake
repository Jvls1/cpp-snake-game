set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

set(MINGW_PREFIX /usr/x86_64-w64-mingw32)
include_directories(${MINGW_PREFIX}/include)
link_directories(${MINGW_PREFIX}/lib)

