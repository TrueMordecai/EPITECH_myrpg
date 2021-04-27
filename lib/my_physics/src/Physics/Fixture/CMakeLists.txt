set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/Fixture)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/Fixture)

set(SRC
    ${SRC}
    ${INCROOT}/fixture.h
    ${SRCROOT}/pe_fixture_destroy.c
    ${SRCROOT}/pe_fixture_init.c
    ${SRCROOT}/pe_fixture_mass.c
    PARENT_SCOPE
)
