set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics/DynamicTree)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Physics/DynamicTree/TreeNode)

set(SRC
    ${SRC}
    ${INCROOT}/tree_node.h
    ${SRCROOT}/pe_tree_node_init.c
    PARENT_SCOPE
)
