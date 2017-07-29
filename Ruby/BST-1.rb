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

    tree.inOrder(tree.root)
end