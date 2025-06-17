cmake_minimum_required(VERSION 3.28)
project(FinalProjGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        src/Player.cpp
        src/Player.h
        src/TextureManager.cpp
        src/TextureManager.h
        src/ImageEnum.h
        src/AnimatedSprite.cpp
        src/AnimatedSprite.h
        src/EnemyOverworld.cpp
        src/EnemyOverworld.h
        src/AudioManager.cpp
        src/AudioManager.h
        src/GameState.cpp
        src/GameState.h
        src/KeyControls.cpp
        src/KeyControls.h
        src/SoundEnum.h
        src/FontManager.cpp
        src/FontManager.h
        src/FontEnum.h
        src/Manager.cpp
        src/Manager.h
        src/SoundEffect.cpp
        src/SoundEffect.h
        src/SoundEffectManager.cpp
        src/SoundEffectManager.h
        src/GameStateEnum.h
        src/Screen.cpp
        src/Screen.h
        src/OverWorld.cpp
        src/OverWorld.h
        src/Battle.cpp
        src/Battle.h
        src/EnemyBossBattle.cpp
        src/EnemyBossBattle.h
        src/Pokemon.cpp
        src/Pokemon.h
        src/battleGUI.cpp
        src/battleGUI.h)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio)
