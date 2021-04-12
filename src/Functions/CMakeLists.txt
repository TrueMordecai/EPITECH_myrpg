set(INCROOT ${PROJECT_SOURCE_DIR}/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Functions)

set(SRC
    ${SRC}
    ${INCROOT}/functions.h
    ${SRCROOT}/center_mouse.c
    ${SRCROOT}/get_numbers.c
    ${SRCROOT}/get_rand.c
    ${SRCROOT}/is_in_bounds.c
    PARENT_SCOPE
)
