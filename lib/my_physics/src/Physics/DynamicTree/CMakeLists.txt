add_subdirectory(BinaryTree)
add_subdirectory(TreeNode)

# propagate the changes to SRC from children directories to parent directory.
set(SRC ${SRC} PARENT_SCOPE)
