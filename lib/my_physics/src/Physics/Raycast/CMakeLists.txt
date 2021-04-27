set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/Raycast)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/Raycast)

set(SRC
    ${SRC}
    ${INCROOT}/raycast.h
    ${SRCROOT}/pe_raycast_aabb.c
    ${SRCROOT}/pe_raycast_init.c
    PARENT_SCOPE
)
