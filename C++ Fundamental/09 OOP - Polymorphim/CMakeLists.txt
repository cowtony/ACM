

add_library(dog dog.cpp)

add_executable(poly polymorphim.cpp)
target_link_libraries(poly dog)