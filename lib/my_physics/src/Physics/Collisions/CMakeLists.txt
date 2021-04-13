set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/Collisions)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/Collisions)

set(SRC
    ${SRC}
    ${INCROOT}/aabb_collides.h
    ${INCROOT}/circle_collides.h
    ${INCROOT}/collisions.h
    ${INCROOT}/manifold.h
    ${SRCROOT}/pe_collide_aabb_aabb.c
    ${SRCROOT}/pe_collide_bodies.c
    ${SRCROOT}/pe_collide_body_from_parent.c
    ${SRCROOT}/pe_collide_circle_circle.c
    ${SRCROOT}/pe_collide_circle_polygone.c
    ${SRCROOT}/pe_collide_get_collide_aabb_id.c
    ${SRCROOT}/pe_collide_polygone_circle.c
    ${SRCROOT}/pe_collide_polygon_polygon.c
    ${SRCROOT}/pe_collide_polygon_polygon_sat.c
    ${SRCROOT}/pe_collide_polygon_polygon_utils.c
    ${SRCROOT}/pe_manifold.c
    ${SRCROOT}/pe_positionnal_correction.c
    ${SRCROOT}/pe_resolve_collision.c
    PARENT_SCOPE
)
