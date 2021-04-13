set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/Shapes)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/Shapes)

add_subdirectory(AABB)

set(SRC
    ${SRC}
    ${INCROOT}/circle_shape.h
    ${INCROOT}/polygon_shape.h
    ${INCROOT}/shape.h
    ${SRCROOT}/pe_init_specific_shapes.c
    ${SRCROOT}/pe_shape_compute_mass_datas.c
    ${SRCROOT}/pe_shape_reset.c
    PARENT_SCOPE
)
