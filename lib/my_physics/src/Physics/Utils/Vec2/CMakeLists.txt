set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/Utils)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/Utils/Vec2)

set(SRC
    ${SRC}
    ${INCROOT}/utils.h
    ${SRCROOT}/pe_vec2_dot_product.c
    ${SRCROOT}/pe_vec2f.c
    ${SRCROOT}/pe_vec2f_cross_product.c
    ${SRCROOT}/pe_vec2i.c
    ${SRCROOT}/pe_vec2_length.c
    ${SRCROOT}/pe_vec2_length_squared.c
    ${SRCROOT}/pe_vec2_normalize.c
    ${SRCROOT}/pe_vec2_operands.c
    ${SRCROOT}/pe_vec2_operands_simple.c
    ${SRCROOT}/pe_vec2_opposite.c
    ${SRCROOT}/pe_vec2u.c
    PARENT_SCOPE
)
