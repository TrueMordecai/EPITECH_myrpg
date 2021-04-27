set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/Constants)

set(SRC
    ${SRC}
    ${INCROOT}/physics_constants.h
    ${SRCROOT}/pe_constants.c
    PARENT_SCOPE
)
