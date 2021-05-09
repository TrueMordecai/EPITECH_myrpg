set(INCROOT ${PROJECT_SOURCE_DIR}/include/GameEngine)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/GameEngine/particle_manager)

set(SRC
    ${SRC}
    ${INCROOT}/particle_manager.h
    ${SRCROOT}/particle_manager_create.c
    ${SRCROOT}/particle_manager_destroy.c
    ${SRCROOT}/particle_manager_draw.c
    ${SRCROOT}/particle_manager_spawn.c
    ${SRCROOT}/particle_manager_update.c
    ${SRCROOT}/particle_manager_clear.c
    PARENT_SCOPE
)
