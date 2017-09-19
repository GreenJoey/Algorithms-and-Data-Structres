class Node:
    def __init__(self, data, next_node=None):
        self.data = data
        self.next = None


def append(node_list, data):
    if node_list.next:
        append(node_list.next, data)
    else:
        node_list.next = Node(data)


def get_last(node_list, pos):
    head_p = node_list
    end_p = node_list


    for i in range(1, pos+1):
        if end_p == None:
            break
        end_p = end_p.next

    while end_p.next != None:
        head_p = head_p.next
        end_p = end_p.next

    return head_p.next.data


def printer(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print('')


def main():
    l = Node(0)
    for i in range(1, 6):
        append(l, i)

    printer(l)

    print(get_last(l, 2))
    print(get_last(l, 3))



main()
