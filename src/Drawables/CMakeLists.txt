set(INCROOT ${PROJECT_SOURCE_DIR}/include/Drawables)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Drawables)

set(SRC
    ${SRC}
    ${INCROOT}/drawables_create.h
    ${INCROOT}/drawable.h
    ${INCROOT}/drawables_head.h
    ${SRCROOT}/drawable_create.c
    ${SRCROOT}/drawable_destroy.c
    ${SRCROOT}/drawable_list_fcts_texture.c
    ${SRCROOT}/drawable_list_fcts.c
    PARENT_SCOPE
)
