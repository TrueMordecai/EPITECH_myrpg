set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg)

add_subdirectory(Entities)
add_subdirectory(Map)
add_subdirectory(Fight)

set(SRC
    ${SRC}
    ${INCROOT}/rpg.h
    ${SRCROOT}/rpg_create.c
    ${SRCROOT}/rpg_destroy.c
    ${SRCROOT}/rpg_draw.c
    ${SRCROOT}/rpg_handle_event.c
    ${SRCROOT}/rpg_update.c
    PARENT_SCOPE
)
