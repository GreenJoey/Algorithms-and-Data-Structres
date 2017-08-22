import java.util.Scanner;


class BinaryTree {
    Node root;

    public void addNode(int key, String name){
        Node newNode = new Node(key, name);

        if(root == null)
            root = newNode;
        else {
            Node focus = root;
            Node parent;

            while(true) {
                parent = focus;

                if(key < focus.key) {
                    focus = focus.leftChild;

                    if(focus == null) {
                        parent.leftChild = newNode;
                        return;
                    }
                }
                else {
                    focus = focus.rightChild;

                    if(focus == null) {
                        parent.rightChild = newNode;
                        return;
                    }
                }
            }
        }
    }

    public Node getreplac(Node replace) {
        Node replacementParent = replace;
        Node replacement = replace;

        Node focusNode = replace.rightChild;

        while(focusNode != null) {
            replacementParent = replacement;
            replacement = focusNode;

            focusNode = focusNode.leftChild;
        }

        if(replacement != replace.rightChild) {
            replacement.leftChild = replacement.rightChild;
            replacement.rightChild = replacement.rightChild;
        }

        return replacement;
    }

    public void inOrder(Node focus) {
        if(focus != null) {
            this.inOrder(focus.leftChild);
            System.out.println(focus);
            this.inOrder(focus.rightChild);
        }
    }

    public void preOrder(Node focus) {
        if(focus != null) {
            System.out.println(focus);
            this.preOrder(focus.leftChild);
            this.preOrder(focus.rightChild);
        }
    }

    public void postOrder(Node focus) {
        if(focus != null) {
            this.postOrder(focus.leftChild);
            this.postOrder(focus.rightChild);
            System.out.println(focus);
        }
    }

    public Node findNode(int key) {
        Node focus = this.root;

        while(focus.key != key) {
            if(key < focus.key)
                focus = focus.leftChild;
            else
                focus = focus.rightChild;
            
            if(focus == null)
                return null;
        }
        return focus;
    }
    
    public boolean remove(int key) {
        Node focusNode = root;
        Node parent = root;
        
         boolean isItALeft = true;
         
         while(focusNode.key != key) {
             parent = focusNode;
             
             if(key < focusNode.key)
                 focusNode = focusNode.leftChild;
             else {
                isItALeft = false;
                focusNode = focusNode.rightChild;
             }
             
             if(focusNode == null)
                return false;
         }
         
         if(focusNode.leftChild == null && focusNode.rightChild == null) {
            if(focusNode == root)
                root = null;
            else if(isItALeft)
            parent.leftChild = null;
            else
            parent.rightChild = null;
         }
         
         else if(focusNode.rightChild == null) {
            if(focusNode == root)
                root = focusNode.leftChild;
            else if(isItALeft)
                parent.leftChild = focusNode.leftChild;
            else
                parent.rightChild = focusNode.leftChild;
         }
         
         else if(focusNode.leftChild == null) {
            if(focusNode == root)
                root = focusNode.rightChild;
            else if(isItALeft)
                parent.leftChild = focusNode.rightChild;
            else
                parent.rightChild = focusNode.leftChild;
         }
         
         else {
            Node replace = get_replace(focusNode);
            
            if(focusNode == root)
                root = replace;
            else if(isItALeft)
                parent.leftChild = replace;
            else
                parent.rightChild = replace;
            replace.leftChild = focusNode.leftChild;
         }
         
         return true;
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();

        tree.addNode(50, "Boss");
        tree.addNode(25, "Vice President");
        tree.addNode(15, "Office Manager");
        tree.addNode(30, "Secretary");
        tree.addNode(75, "Sales Manager");
        tree.addNode(85, "Salesman 1");

        // tree.inOrder(tree.root);
        // tree.preOrder(tree.root);
        tree.postOrder(tree.root);

        System.out.println(tree.findNode(30));

        System.out.println("Remove 25");
        tree.remove(25);
        tree.postOrder();
    }
}


class Node {
    int key;
    String name;

    Node leftChild;
    Node rightChild;

    Node(int key, String name) {
        this.key = key;
        this.name = name;
    }

    public String toString() {
        return this.name + " has a key " + this.key;
    }
}
