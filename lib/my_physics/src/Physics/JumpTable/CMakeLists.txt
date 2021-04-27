set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/JumpTable)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/JumpTable)

set(SRC
    ${SRC}
    ${INCROOT}/collision_table.h
    ${INCROOT}/jump_tables.h
    ${SRCROOT}/pe_collision_table.c
    PARENT_SCOPE
)
