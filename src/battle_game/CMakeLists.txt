file(GLOB files *)

foreach(file ${files})
    if (IS_DIRECTORY ${file})
        file(RELATIVE_PATH short_name ${CMAKE_CURRENT_SOURCE_DIR} ${file})
        set(COMPONENT_NAME ${short_name})
        add_subdirectory(${file})
    endif()
endforeach()

add_executable(battle_game battle_game.cpp)
target_link_libraries(battle_game PUBLIC ${LIBRARY_LIST})
target_include_directories(battle_game PUBLIC ${BATTLE_GAME_EXTERNAL_INCLUDE_DIRS} ${BATTLE_GAME_INCLUDE_DIR})
