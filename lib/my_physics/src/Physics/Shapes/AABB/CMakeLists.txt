set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/Shapes)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/Shapes/AABB)

set(SRC
    ${SRC}
    ${INCROOT}/aabb_shape.h
    ${SRCROOT}/pe_aabb_area.c
    ${SRCROOT}/pe_aabb_copy.c
    ${SRCROOT}/pe_aabb_from_shape.c
    ${SRCROOT}/pe_aabb_init.c
    ${SRCROOT}/pe_aabb_is_equal.c
    ${SRCROOT}/pe_aabb_union.c
    PARENT_SCOPE
)
