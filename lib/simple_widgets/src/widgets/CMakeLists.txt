set(INCROOT ${PROJECT_SOURCE_DIR}/include/sw/widgets)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/widgets)

set(SRC
    ${SRC}
    ${INCROOT}/base.h
    ${INCROOT}/button.h
    ${INCROOT}/label.h
    ${SRCROOT}/base.c
    ${SRCROOT}/base2.c
    ${SRCROOT}/button.c
    ${SRCROOT}/button2.c
    ${SRCROOT}/button3.c
    ${SRCROOT}/button4.c
    ${SRCROOT}/label.c
    PARENT_SCOPE
)
