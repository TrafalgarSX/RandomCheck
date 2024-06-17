
# cmakelists  demo 

cmake_minimum_required(VERSION 3.22)
project(gen_sign_checklist_util)

# set cxx standard 
set(CXX_STANDARD_REQUIRED)
set(CMAKE_CXX_STANDARD 11)

list(APPEND lib_src 
                    # tool
                    ${PROJECT_SOURCE_DIR}/src/cephes.c
                    ${PROJECT_SOURCE_DIR}/src/utilities.c

                    # nist
                    ${PROJECT_SOURCE_DIR}/src/frequency.c # 频率检测

                    ${PROJECT_SOURCE_DIR}/src/blockFrequency.c # 块频率检测

                    ${PROJECT_SOURCE_DIR}/src/overlappingTemplateMatchings.c # 重叠模板匹配

                    ${PROJECT_SOURCE_DIR}/src/runs.c # 连续0/1数

                    ${PROJECT_SOURCE_DIR}/src/longestRunOfOnes.c # 最长连续1数

                    ${PROJECT_SOURCE_DIR}/src/matrix.c # 矩阵秩
                    ${PROJECT_SOURCE_DIR}/src/rank.c

                    ${PROJECT_SOURCE_DIR}/src/cusum.c # 累积和

                    ${PROJECT_SOURCE_DIR}/src/approximateEntropy.c # 近似熵

                    ${PROJECT_SOURCE_DIR}/src/linearComplexity.c # 线性复杂度

                    ${PROJECT_SOURCE_DIR}/src/universal.c  # Maurer

                    ${PROJECT_SOURCE_DIR}/src/dfft.c   # 傅里叶
                    ${PROJECT_SOURCE_DIR}/src/discreteFourierTransform.c

                    # gb/t
                    ${PROJECT_SOURCE_DIR}/src/discreteFourierTransform.c
                    ${PROJECT_SOURCE_DIR}/src/discreteFourierTransform.c
                    ${PROJECT_SOURCE_DIR}/src/discreteFourierTransform.c
                    ${PROJECT_SOURCE_DIR}/src/discreteFourierTransform.c
                   )

list(APPEND exe_src 
                   ${PROJECT_SOURCE_DIR}/src/main.cpp
                   )

list(APPEND include_dir ${PROJECT_SOURCE_DIR}/include
                   )

add_library(${PROJECT_NAME}s STATIC ${lib_src})
target_include_directories(${PROJECT_NAME}s PRIVATE ${include_dir})

add_executable(${PROJECT_NAME} ${exe_src})
target_include_directories(${PROJECT_NAME} PRIVATE ${include_dir})
