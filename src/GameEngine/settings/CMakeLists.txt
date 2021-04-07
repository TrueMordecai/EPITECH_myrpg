set(INCROOT ${PROJECT_SOURCE_DIR}/include/GameEngine)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/GameEngine/settings)

set(SRC
    ${SRC}
    ${INCROOT}/settings.h
    ${SRCROOT}/settings_check.c
    ${SRCROOT}/settings_init_default.c
    ${SRCROOT}/settings_read.c
    ${SRCROOT}/settings_write.c
    PARENT_SCOPE
)
