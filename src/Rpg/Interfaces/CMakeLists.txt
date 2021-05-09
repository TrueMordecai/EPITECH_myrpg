set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Interfaces)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Interfaces)

set(SRC
    ${SRC}
    ${INCROOT}/inventory.h
    ${SRCROOT}/init_inventory.c
    ${SRCROOT}/inventory_draw_items.c
    ${SRCROOT}/inventory_draw_other.c
    ${SRCROOT}/inventory_handle_events.c
    ${SRCROOT}/inventory_index.c
    ${SRCROOT}/inventory_input.c
    ${SRCROOT}/inventory_open.c
    ${SRCROOT}/inventory_utils.c
    ${SRCROOT}/rpg_create_item.c
    ${SRCROOT}/rpg_create_item_name_gen.c
    ${SRCROOT}/rpg_draw_item_tooltip.c
    PARENT_SCOPE
)
