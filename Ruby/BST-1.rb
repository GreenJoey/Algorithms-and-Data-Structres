class BinaryTree
    attr_reader :root
    root = nil

    def addNode(key, name)
        newNode = Node.new(key, name)

        if(root == nil)
            @root = newNode
        else
            focus = @root
            parent = nil

            while true
                parent = focus

                if key < focus.key
                    focus = focus.leftChild

                    if focus == nil
                        parent.leftChild = newNode
                        return
                    end
                else
                    focus = focus.rightChild

                    if focus == nil
                        parent.rightChild = newNode
                        return
                    end
                end
            end
        end
    end

    def inOrder(focus)
        if focus != nil
            inOrder(focus.leftChild)
            puts(focus)
            inOrder(focus.rightChild)
        end
    end

    def preOrder(focus)
        if focus != nil
            puts(focus)
            preOrder(focus.leftChild)
            preOrder(focus.rightChild)
        end
    end

    def postOrder(focus)
        if focus != nil
            postOrder(focus.leftChild)
            postOrder(focus.rightChild)
            puts(focus)
        end
    end

    def find(key)
        focus = @root

        while focus.key != key
            if key < focus.key
                focus = focus.leftChild
            else
                focus = focus.rightChild
            end

            if focus == nil
                return nil
            end
        end
        return focus
    end
end


class Node
    attr_accessor :key, :name, :leftChild, :rightChild
    
    def initialize(key, name)
        @key = key
        @name = name
    end

    def to_s()
        return "#{@name} has a key #{@key}"
    end
end


if __FILE__ == $0
    tree = BinaryTree.new()

    tree.addNode(50, "Boss")
    tree.addNode(25, "Vice President")
    tree.addNode(15, "Office Manager")
    tree.addNode(30, "Secretary")
    tree.addNode(75, "Sales Manager")
    tree.addNode(85, "Salesman 1")

    # tree.inOrder(tree.root)
    # tree.preOrder(tree.root)
    tree.postOrder(tree.root)

    puts(tree.find(30))
end
