set(INCROOT ${PROJECT_SOURCE_DIR}/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Functions)

set(SRC
    ${SRC}
    ${INCROOT}/functions.h
    ${SRCROOT}/btns_callbacks.c
    ${SRCROOT}/center_mouse.c
    ${SRCROOT}/create_btn.c
    ${SRCROOT}/get_numbers.c
    ${SRCROOT}/get_rand.c
    ${SRCROOT}/is_in_bounds.c
    ${SRCROOT}/my_strlen_to.c
    ${SRCROOT}/read_file.c
    ${SRCROOT}/trim_str.c
    PARENT_SCOPE
)
