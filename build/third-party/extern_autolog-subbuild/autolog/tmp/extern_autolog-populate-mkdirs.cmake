# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/zjl/123/cpp_infer/build/third-party/extern_autolog-src"
  "/home/zjl/123/cpp_infer/build/third-party/extern_autolog-build"
  "/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog"
  "/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/tmp"
  "/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp"
  "/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src"
  "/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
