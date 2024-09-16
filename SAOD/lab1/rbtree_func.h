#pragma once

typedef struct rbtree{
    
};

rbtree *rbtree_add(struct rbtree *root, int key, char *value)
rbtree *rbtree_lookup(struct rbtree *root, int key)
rbtree *rbtree_delete(struct rbtree *root, int key)
rbtree *rbtree_min(struct rbtree *root)
rbtree *rbtree_max(struct rbtree *root)
void rbtree_free(struct rbtree *root)
void rbtree_print_dfs(struct rbtree *root, int level)