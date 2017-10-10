class Tree
  def initialize(data)
    @data = data
    @left = @right = nil
  end

  def append(data)
    if data > @data
      if @left != nil
        @left.append(data)
      else
        @left = Tree.new(data)
      end
    else
      if @right != nil
        @right.append(data)
      else
        @right = Tree.new(data)
      end
    end
  end

  def display()
    if @left
      @left.display()
    end

    print("#{@data}->")

    if @right
      @right.display()
    end
  end

  def get_leaves()
      leaves = 0
      if @left == nil && @right == nil
          return 1
      end

      if @left
          leaves += @left.get_leaves()
      end

      if @right
          leaves += @right.get_leaves()
      end

      return leaves
  end
end



tree = Tree.new(45)

for v in [39, 78, 79, 80, 54, 55]
  tree.append(v)
end

tree.display()

puts()
puts(tree.get_leaves())
