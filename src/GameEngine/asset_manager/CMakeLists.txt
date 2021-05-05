set(INCROOT ${PROJECT_SOURCE_DIR}/include/GameEngine)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/GameEngine/asset_manager)

set(SRC
    ${SRC}
    ${INCROOT}/asset_manager.h
    ${SRCROOT}/asset_manager_drop.c
    ${SRCROOT}/asset_manager.c
    ${SRCROOT}/default_font.h
    ${SRCROOT}/load_textures.c
    PARENT_SCOPE
)
