set(MODULE hal)

add_library(${MODULE})
add_library(${MODULE}::${MODULE} ALIAS ${MODULE})

target_sources(${MODULE}
PRIVATE
    # sources..
)

target_include_directories(${MODULE} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${MODULE}
PUBLIC
PRIVATE
)