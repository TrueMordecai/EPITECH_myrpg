set(INCROOT ${PROJECT_SOURCE_DIR}/include/GameEngine)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/GameEngine/settings)

set(SRC
    ${SRC}
    ${INCROOT}/settings.h
    ${SRCROOT}/game_settings_init.c
    ${SRCROOT}/game_settings_save.c
    PARENT_SCOPE
)
