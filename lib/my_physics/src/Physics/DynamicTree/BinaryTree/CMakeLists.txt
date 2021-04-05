set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/DynamicTree)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/DynamicTree/BinaryTree)

set(SRC
    ${SRC}
    ${INCROOT}/binary_tree.h
    ${SRCROOT}/pe_binary_tree_best_sibling.c
    ${SRCROOT}/pe_binary_tree_cost.c
    ${SRCROOT}/pe_binary_tree_debug.c
    ${SRCROOT}/pe_binary_tree_init.c
    ${SRCROOT}/pe_binary_tree_insert_body.c
    ${SRCROOT}/pe_binary_tree_raycast.c
    ${SRCROOT}/pe_binary_tree_reinsert.c
    ${SRCROOT}/pe_binary_tree_remove.c
    ${SRCROOT}/pe_binary_tree_update.c
    PARENT_SCOPE
)
