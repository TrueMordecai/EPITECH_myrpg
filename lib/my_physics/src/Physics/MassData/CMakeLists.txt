set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/MassData)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/MassData)

set(SRC
    ${SRC}
    ${INCROOT}/mass_data.h
    ${SRCROOT}/pe_mass_data.c
    PARENT_SCOPE
)
