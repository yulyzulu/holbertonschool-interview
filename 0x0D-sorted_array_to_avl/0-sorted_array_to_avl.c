#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Create a new binary tree node
 * @parent: Pointer to the parent node
 * @value: The value to insert
 * Return: Pointer to the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->n = value;
	new_node->right = NULL;
	return (new_node);
}

/**
*sort_avl_tree - Build a sort avl tree
*@array: Pointer to array
*@start: Array start
*@end: Array end
*@parent : Pointer to the parent
*Return: AVL tree
*/
avl_t *sort_avl_tree(int *array, size_t start, size_t end, avl_t *parent)
{
	size_t middle;
	avl_t *node;

	middle = (start + end) / 2;
	node = binary_tree_node(parent, array[middle]);

	if (node == NULL)
		return (NULL);

	if (start > end)
		return (NULL);

	if (middle != start)
		node->left = sort_avl_tree(array, start, middle - 1, node);

	if (middle != end)
		node->right = sort_avl_tree(array, middle + 1, end, node);

	return (node);
}


/**
*sorted_array_to_avl - Function that builds an AVL tree from an array
*@array: Pointer to the first element of the array to be converted
*@size: The number of element in the array
*Return: A pointer to the root node of the created AVL tree, or NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (array == NULL || size == 0)
		return (NULL);

	root = sort_avl_tree(array, 0, size - 1, NULL);

	return (root);
}
