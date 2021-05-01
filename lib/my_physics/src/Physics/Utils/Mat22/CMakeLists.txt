set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/Utils)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/Utils/Mat22)

set(SRC
    ${SRC}
    ${INCROOT}/mat22.h
    ${SRCROOT}/pe_mat22_init.c
    ${SRCROOT}/pe_mat22_rotate.c
    ${SRCROOT}/pe_mat22_transpose.c
    PARENT_SCOPE
)
