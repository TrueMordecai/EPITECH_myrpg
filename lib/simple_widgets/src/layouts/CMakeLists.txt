set(INCROOT ${PROJECT_SOURCE_DIR}/include/sw/layouts)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/layouts)

set(SRC
    ${SRC}
    ${INCROOT}/grid.h
    ${INCROOT}/vertical.h
    ${SRCROOT}/grid.c
    ${SRCROOT}/grid2.c
    ${SRCROOT}/vertical.c
    ${SRCROOT}/vertical2.c
    PARENT_SCOPE
)
