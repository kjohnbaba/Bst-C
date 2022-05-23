# Bst-C
Binary search tree in C
Done as comp arch hw

It will receive commands from standard input, and print resposes to those commands to standard output.

insert n: Adds a value to the tree, if not already present. The new node will always be added as the
child of an existing node, or as the root. No existing node will change or move as as result of
inserting an item. If n was not present, and hence has been inserted, bst will print inserted.
Otherwise, it will print not inserted. The instruction format is an i followed by a decimal
integer n.

search n: Searches the tree for a value n. If n is present, bst will print present. Otherwise, it will
print absent. The instruction format is an s followed by a space and an integer n.

print: Prints the current tree structure

delete n: Removes a value from the tree.If n is not present, print absent. Otherwise, print deleted. The instruction format is a d
followed by a space and an integer n.
