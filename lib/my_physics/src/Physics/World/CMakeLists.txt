set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/World)

set(SRC
    ${SRC}
    ${INCROOT}/world.h
    ${SRCROOT}/pe_world_add.c
    ${SRCROOT}/pe_world_destroy.c
    ${SRCROOT}/pe_world_handle_collisions.c
    ${SRCROOT}/pe_world_init.c
    ${SRCROOT}/pe_world_update.c
    PARENT_SCOPE
)
 