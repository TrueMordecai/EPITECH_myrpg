set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/Filter)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/Filter)

set(SRC
    ${SRC}
    ${INCROOT}/filter.h
    ${SRCROOT}/pe_filter_init.c
    PARENT_SCOPE
)
