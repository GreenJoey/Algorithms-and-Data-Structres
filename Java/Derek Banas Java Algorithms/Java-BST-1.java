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