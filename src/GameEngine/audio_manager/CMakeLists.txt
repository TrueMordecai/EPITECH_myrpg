set(INCROOT ${PROJECT_SOURCE_DIR}/include/GameEngine)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/GameEngine/audio_manager)

set(SRC
    ${SRC}
    ${INCROOT}/audio_manager.h
    ${SRCROOT}/audio_manager_destroy.c
    ${SRCROOT}/audio_manager_init.c
    ${SRCROOT}/audio_manager_play.c
    ${SRCROOT}/audio_manager_update_volume.c
    ${SRCROOT}/load_audio.c
    PARENT_SCOPE
)
