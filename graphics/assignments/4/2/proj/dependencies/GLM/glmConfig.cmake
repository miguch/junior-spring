set(GLM_VERSION "0.9.8")
set(GLM_INCLUDE_DIRS "/Users/mig/Desktop/junior-spring/graphics/assignments/4/proj/dependencies/GLM")

if (NOT CMAKE_VERSION VERSION_LESS "3.0")
    include("${CMAKE_CURRENT_LIST_DIR}/glmTargets.cmake")
endif()
