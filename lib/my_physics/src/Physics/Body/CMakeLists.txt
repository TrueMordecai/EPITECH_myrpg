set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/Body)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/Body)

set(SRC
    ${SRC}
    ${INCROOT}/body.h
    ${SRCROOT}/pe_body_compute_aabb.c
    ${SRCROOT}/pe_body_compute_mass.c
    ${SRCROOT}/pe_body_destroy.c
    ${SRCROOT}/pe_body_forces.c
    ${SRCROOT}/pe_body_impulse.c
    ${SRCROOT}/pe_body_init.c
    ${SRCROOT}/pe_body_move.c
    ${SRCROOT}/pe_body_rotate.c
    ${SRCROOT}/pe_body_update.c
    PARENT_SCOPE
)
