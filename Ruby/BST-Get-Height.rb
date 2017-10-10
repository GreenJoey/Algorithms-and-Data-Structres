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

    print(@data)

    if @right
      @right.display()
    end
  end

  def height()
    h = 1
    left = right = 0

    if @left == nil && @right == nil
      return 0
    end

    if @left
      left += @left.height()
    end

    if @right
      right += @right.height()
    end

    h += [left, right].max()

    return h
  end
end



tree = Tree.new(3)

for v in [5, 2, 1, 4, 6, 7]
  tree.append(v)
end

tree.display()

puts()
puts(tree.height())
