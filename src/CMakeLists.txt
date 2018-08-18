set(rhsHEAAN_HEADER_FILES Ciphertext.h
                          Common.h
                          Context.h
                          EvaluatorUtils.h
                          Key.h
                          Numb.h
                          Plaintext.h
                          Scheme.h
                          SchemeAlgo.h
                          SecretKey.h
                          StringUtils.h
                          TimeUtils.h)
set(rhsHEAAN_SOURCE_FILES Ciphertext.cpp
                          Context.cpp
                          EvaluatorUtils.cpp
                          Key.cpp
                          Numb.cpp
                          Plaintext.cpp
                          Scheme.cpp
                          SchemeAlgo.cpp
                          SecretKey.cpp
                          StringUtils.cpp
                          TestScheme.cpp
                          TimeUtils.cpp)

add_library(rnsHEAAN SHARED ${rhsHEAAN_HEADER_FILES} ${rhsHEAAN_SOURCE_FILES})

add_executable(Test main.cpp TestScheme.cpp TestScheme.h)
target_link_libraries(Test rnsHEAAN)

install(TARGETS rnsHEAAN LIBRARY DESTINATION lib)

install(FILES ${rhsHEAAN_HEADER_FILES} DESTINATION include/rns_HEAAN)
