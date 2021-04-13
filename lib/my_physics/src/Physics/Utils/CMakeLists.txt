set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/Utils)

add_subdirectory(Mat22)
add_subdirectory(Vec2)

set(SRC
    ${SRC}
    ${INCROOT}/utils.h
    PARENT_SCOPE
)
